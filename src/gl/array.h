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

extern int CheckArraySize(lua_State *L, int arg);

template <typename U>
class Array1D {
  
  public:

    typedef typename U::T T;
    
    Array1D()
      : mData(0), mSize(0), mOwns(true)
    {
    }

    Array1D(T *data, int sz)
      : mData(data), mSize(sz), mOwns(false) {
    }
    
    Array1D(int sz)
      : mSize(sz), mOwns(true) {
      mData = new T[sz];
    }
    
    Array1D(const Array1D<U> &rhs)
      : mData(rhs.mData), mSize(rhs.mSize), mOwns(rhs.mOwns) {
      rhs.mOwns = false;
    }
    
    ~Array1D() {
      if (mData && mOwns) {
        delete[] mData;
      }
    }
    
    Array1D<U>& operator=(const Array1D<U> &rhs) {
      if (this != &rhs) {
        if (mData && mOwns) {
          delete[] mData;
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
 
    bool fromLUA(lua_State *L, int arg) {
      int sz = CheckArraySize(L, arg);
      
      if (mData) {
        if (mSize != sz) {
          char tmp[256];
          sprintf(tmp, "Array size mismatch: expected %d, got %d", mSize, sz);
          lua_pushstring(L, tmp);
          lua_error(L);
          return false;
        }
      } else {
        mData = new T[sz];
        mSize = sz;
        mOwns = true;
      }
      
      if (mSize > 0) {
        mData = new T[mSize];
        for (int i=0; i<mSize; ++i) {
          lua_pushinteger(L, i+1);
          lua_gettable(L, arg);
          U v(L, -1);
          mData[i] = T(v);
          lua_pop(L, 1);
        }
      }
      
      return true;
    }
    
 
  protected:
    T *mData;
    int mSize;
    mutable bool mOwns;
};

#endif
