/*

Copyright (C) 2009  Gaetan Guidet

This file is part of luagl.

luagl is free software; you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or (at
your option) any later version.

luagl is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
USA.

*/

#ifndef __luagl_array_h_
#define __luagl_array_h_

#include "common.h"
#include "mem/managedobject.h"

enum {
  COLUMN_MAJOR = 0,
  ROW_MAJOR,
};

extern int CheckArraySize(lua_State *L, int arg);

template <typename U>
class Array1D : public MemoryManagedObject {
  public:

    typedef typename U::T T;
    
    Array1D()
      : mData(0), mSize(0), mOwns(true) {
    }
    
    Array1D(lua_State *L, int arg)
      : mData(0), mSize(0), mOwns(true) {
      fromLUA(L, arg);
    }

    Array1D(T *data, int sz)
      : mData(data), mSize(sz), mOwns(false) {
    }
    
    Array1D(int sz)
      : mSize(sz), mOwns(true) {
      //mData = new T[sz];
      mData = (T*) MemoryManager::Instance().allocate(sz*sizeof(T));
    }
    
    Array1D(const Array1D<U> &rhs)
      : mData(rhs.mData), mSize(rhs.mSize), mOwns(rhs.mOwns) {
      rhs.mOwns = false;
    }
    
    ~Array1D() {
      if (mData && mOwns) {
        //delete[] mData;
        MemoryManager::Instance().deallocate(mData, mSize*sizeof(T));
      }
    }
    
    Array1D<U>& operator=(const Array1D<U> &rhs) {
      if (this != &rhs) {
        if (mData && mOwns) {
          //delete[] mData;
          MemoryManager::Instance().deallocate(mData, mSize*sizeof(T));
        }
        mData = rhs.mData;
        mSize = rhs.mSize;
        mOwns = rhs.mOwns;
        rhs.mOwns = false;
      }
      return *this;
    }
    
    inline operator T* () {
      return mData;
    }
    
    inline operator const T* () const {
      return mData;
    }
    
    inline operator void* () {
      return (void*)mData;
    }
    
    inline operator const void*() const {
      return (const void*)mData;
    }
    
    inline int size() const {
      return mSize;
    }
    
    void toLUA(lua_State *L) {
      if (!mData) {
        lua_pushnil(L);
        return;
      }
      lua_newtable(L);
      for (int i=0; i<mSize; ++i) {
        lua_pushinteger(L, i+1);
        U v(mData[i]);
        v.toLUA(L);
        lua_settable(L, -3);
      }
    }
 
    const T* fromLUA(lua_State *L, int arg) {
      if (mData && mOwns) {
        //delete[] mData;
        MemoryManager::Instance().deallocate(mData, mSize*sizeof(T));
      }
      
      mData = 0;
      mSize = 0;
      mOwns = true;
      
      mSize = CheckArraySize(L, arg);
      
      if (mSize > 0) {
        //mData = new T[mSize];
        mData = (T*) MemoryManager::Instance().allocate(mSize*sizeof(T));
        for (int i=0; i<mSize; ++i) {
          lua_pushinteger(L, i+1);
          lua_gettable(L, arg);
          U v(L, -1);
          mData[i] = T(v);
          lua_pop(L, 1);
        }
      }
      
      return mData;
    }
    
 
  protected:
    T *mData;
    int mSize;
    mutable bool mOwns;
};


template <typename U>
class FlatArray2D : public MemoryManagedObject {
  public:
    
    typedef typename U::T T;
    
    FlatArray2D()
      : mData(0), mRowSize(0), mColSize(0), mOwns(true) {
    }
    
    FlatArray2D(int nr, int nc)
      : mRowSize(nr), mColSize(nc), mOwns(true) {
      //mData = new T[nr * nc];
      mData = (T*) MemoryManager::Instance().allocate(nr*nc*sizeof(T));
    }

    FlatArray2D(T *data, int nr, int nc)
      : mData(data), mRowSize(nr), mColSize(nc), mOwns(false) {
    }
    
    FlatArray2D(lua_State *L, int arg, int luaformat, int dstformat)
      : mData(0), mRowSize(0), mColSize(0), mOwns(true) {
      fromLUA(L, arg, luaformat, dstformat);
    }
    
    FlatArray2D(const FlatArray2D<U> &rhs)
      : mData(rhs.mData), mRowSize(rhs.mRowSize), mColSize(rhs.mColSize),
        mOwns(rhs.mOwns) {
      rhs.mOwns = false;
    }
    
    ~FlatArray2D() {
      if (mData && mOwns) {
        //delete[] mData;
        MemoryManager::Instance().deallocate(mData, mRowSize*mColSize*sizeof(T));
      }
    }
    
    FlatArray2D<U>& operator=(const FlatArray2D<U> &rhs) {
      if (this != &rhs) {
        if (mData && mOwns) {
          //delete[] mData;
          MemoryManager::Instance().deallocate(mData, mRowSize*mColSize*sizeof(T));
        }
        mData = rhs.mData;
        mRowSize = rhs.mRowSize;
        mColSize = rhs.mColSize;
        mOwns = rhs.mOwns;
        rhs.mOwns = false;
      }
      return *this;
    }
    
    inline operator T* () {
      return mData;
    }
    
    inline operator const T* () const {
      return mData;
    }
    
    inline operator void* () {
      return (void*)mData;
    }
    
    inline operator const void*() const {
      return (const void*)mData;
    }
    
    inline int numRows() const {
      return mRowSize;
    }
    
    inline int numColumns() const {
      return mColSize;
    }

    inline int size() const {
      return (mRowSize * mColSize);
    }
    
    void toLUA(lua_State *L, int srcformat, int luaformat) {
      
      if (!mData) {
        lua_pushnil(L);
        return;
      }
      
      int mRowStride, mColStride;
        
      if (srcformat == COLUMN_MAJOR) {
        mRowStride = 1;
        mColStride = mColSize;
      } else {
        mColStride = 1;
        mRowStride = mRowSize;
      }
      
      lua_newtable(L);
      
      if (luaformat == ROW_MAJOR) {
        // first array contains row arrays
        for (int r=0; r<mRowSize; ++r) {
          int idx = r * mRowStride;
          lua_pushinteger(L, r+1);
          lua_newtable(L);
          for (int c=0; c<mColSize; ++c, idx+=mColStride) {
            lua_pushinteger(L, c+1);
            U v(mData[idx]);
            v.toLUA(L);
            lua_settable(L, -3);
          }
          lua_settable(L, -3);
        }
        
      } else {
        // first array contains col arrays
        for (int c=0; c<mColSize; ++c) {
          int idx = c * mColStride;
          lua_pushinteger(L, c+1);
          lua_newtable(L);
          for (int r=0; r<mRowSize; ++r, idx+=mRowStride) {
            lua_pushinteger(L, r+1);
            U v(mData[idx]);
            v.toLUA(L);
            lua_settable(L, -3);
          }
          lua_settable(L, -3);
        }
      }
    }
    
    const T* fromLUA(lua_State *L, int arg, int luaformat, int dstformat) {
      if (mData && mOwns) {
        //delete[] mData;
        MemoryManager::Instance().deallocate(mData, mRowSize*mColSize*sizeof(T));
      }
      
      mRowSize = 0;
      mColSize = 0;
      mOwns = true;
      
      if (luaformat == ROW_MAJOR) {
        mRowSize = CheckArraySize(L, arg);
        int cs = -1;
        for (int i=0; i<mRowSize; ++i) {
          lua_pushinteger(L, i+1);
          lua_gettable(L, arg);
          if (cs == -1) {
            cs = CheckArraySize(L, -1);
          } else if (cs != CheckArraySize(L, -1)) {
            lua_pushstring(L, "All columns must have the same dimension");
            lua_error(L);
          }
          lua_pop(L, 1);
        }
        mColSize = cs;
        
      } else {
        mColSize = CheckArraySize(L, arg);
        int rs = -1;
        for (int i=0; i<mColSize; ++i) {
          lua_pushinteger(L, i+1);
          lua_gettable(L, arg);
          if (rs == -1) {
            rs = CheckArraySize(L, -1);
          } else if (rs != CheckArraySize(L, -1)) {
            lua_pushstring(L, "All rows must have the same dimension");
            lua_error(L);
          }
          lua_pop(L, 1);
        }
        mRowSize = rs;
      }
      
      if (mRowSize > 0 && mColSize > 0) {
        
        int mRowStride, mColStride;
        
        if (dstformat == COLUMN_MAJOR) {
          mRowStride = 1;
          mColStride = mColSize;
        } else {
          mColStride = 1;
          mRowStride = mRowSize;
        }
        
        //mData = new T[mRowSize * mColSize];
        mData = (T*) MemoryManager::Instance().allocate(mRowSize*mColSize*sizeof(T));        

        if (luaformat == COLUMN_MAJOR) {
          for (int c=0; c<mColSize; ++c) {
            int idx = c * mColStride;
            lua_pushinteger(L, c+1);
            lua_gettable(L, arg);
            for (int r=0; r<mRowSize; ++r, idx+=mRowStride) {
              lua_pushinteger(L, r+1);
              lua_gettable(L, -2);
              U v(L, -1);
              mData[idx] = T(v);
              lua_pop(L, 1);
            }
            lua_pop(L, 1);
          }
          
        } else {
          for (int r=0; r<mRowSize; ++r) {
            int idx = r * mRowStride;
            lua_pushinteger(L, r+1);
            lua_gettable(L, arg);
            for (int c=0; c<mColSize; ++c, idx+=mColStride) {
              lua_pushinteger(L, c+1);
              lua_gettable(L, -2);
              U v(L, -1);
              mData[idx] = T(v);
              lua_pop(L, 1);
            }
            lua_pop(L, 1);
          }
        }
      }
      
      return mData;
    }
    
  protected:
    
    T *mData;
    int mRowSize;
    int mColSize;
    mutable bool mOwns;
    
};


#endif
