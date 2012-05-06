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

#ifndef __raw_h_
#define __raw_h_

#include <lua.hpp>
#ifdef _WIN32
# pragma warning(disable: 4290)
#endif
#include <string>
#include <vector>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <iostream>

enum DataType {
  DT_INVALID = -1,
  DT_BYTE,
  DT_SHORT,
  DT_INT,
  DT_LONG,
  DT_UBYTE,
  DT_USHORT,
  DT_UINT,
  DT_ULONG,
  DT_FLOAT,
  DT_DOUBLE,
  DT_MAX
};

struct Invalid {
};

template <DataType DT>
struct Enum2Type {
  typedef Invalid T;
};

template <typename T>
struct Type2Enum {
  enum {
    E = DT_INVALID
  };
};

template <DataType DT>
struct TypeSize {
  enum {
    Size = sizeof(typename Enum2Type<DT>::T)
  };
};

template <DataType DT>
struct TypeConvert {
  typedef typename Enum2Type<DT>::T T;
  inline static int ToLUA(lua_State *L, T) {
    lua_pushstring(L, "Could not convert type to LUA");
    lua_error(L);
    return 0;
  }
  inline static T FromLUA(lua_State *L, int) {
    lua_pushstring(L, "Coult not convert type from LUA");
    lua_error(L);
    return T(0);
  }
};

template <> struct Enum2Type<DT_BYTE> {typedef char T;};
template <> struct Enum2Type<DT_SHORT> {typedef short T;};
template <> struct Enum2Type<DT_INT> {typedef int T;};
template <> struct Enum2Type<DT_LONG> {typedef long T;};
template <> struct Enum2Type<DT_UBYTE> {typedef unsigned char T;};
template <> struct Enum2Type<DT_USHORT> {typedef unsigned short T;};
template <> struct Enum2Type<DT_UINT> {typedef unsigned int T;};
template <> struct Enum2Type<DT_ULONG> {typedef unsigned long T;};
template <> struct Enum2Type<DT_FLOAT> {typedef float T;};
template <> struct Enum2Type<DT_DOUBLE> {typedef double T;};

template <> struct Type2Enum<char> {enum {E = DT_BYTE};};
template <> struct Type2Enum<short> {enum {E = DT_SHORT};};
template <> struct Type2Enum<int> {enum {E = DT_INT};};
template <> struct Type2Enum<long> {enum {E = DT_LONG};};
template <> struct Type2Enum<unsigned char> {enum {E = DT_UBYTE};};
template <> struct Type2Enum<unsigned short> {enum {E = DT_USHORT};};
template <> struct Type2Enum<unsigned int> {enum {E = DT_UINT};};
template <> struct Type2Enum<unsigned long> {enum {E = DT_ULONG};};
template <> struct Type2Enum<float> {enum {E = DT_FLOAT};};
template <> struct Type2Enum<double> {enum {E = DT_DOUBLE};};

template <> struct TypeConvert<DT_BYTE> {
  inline static int ToLUA(lua_State *L, char val) {
    lua_pushinteger(L, lua_Integer(val));
    return 1;
  }
  inline static char FromLUA(lua_State *L, int arg) {
    lua_Integer i = lua_tointeger(L, arg);
    return ((char)i);
  }
};
template <> struct TypeConvert<DT_SHORT> {
  inline static int ToLUA(lua_State *L, short val) {
    lua_pushinteger(L, lua_Integer(val));
    return 1;
  }
  inline static short FromLUA(lua_State *L, int arg) {
    lua_Integer i = lua_tointeger(L, arg);
    return ((short)i);
  }
};
template <> struct TypeConvert<DT_INT> {
  inline static int ToLUA(lua_State *L, int val) {
    lua_pushinteger(L, lua_Integer(val));
    return 1;
  }
  inline static unsigned int FromLUA(lua_State *L, int arg) {
    lua_Integer i = lua_tointeger(L, arg);
    return ((int)i);
  }
};
template <> struct TypeConvert<DT_LONG> {
  inline static int ToLUA(lua_State *L, long val) {
    lua_pushinteger(L, lua_Integer(val));
    return 1;
  }
  inline static unsigned int FromLUA(lua_State *L, int arg) {
    lua_Integer i = lua_tointeger(L, arg);
    return ((long)i);
  }
};
template <> struct TypeConvert<DT_UBYTE> {
  inline static int ToLUA(lua_State *L, unsigned char val) {
    lua_pushinteger(L, lua_Integer(val));
    return 1;
  }
  inline static char FromLUA(lua_State *L, int arg) {
    lua_Integer i = lua_tointeger(L, arg);
    return ((unsigned char)i);
  }
};
template <> struct TypeConvert<DT_USHORT> {
  inline static int ToLUA(lua_State *L, unsigned short val) {
    lua_pushinteger(L, lua_Integer(val));
    return 1;
  }
  inline static short FromLUA(lua_State *L, int arg) {
    lua_Integer i = lua_tointeger(L, arg);
    return ((unsigned short)i);
  }
};
template <> struct TypeConvert<DT_UINT> {
  inline static int ToLUA(lua_State *L, unsigned int val) {
    lua_pushinteger(L, lua_Integer(val));
    return 1;
  }
  inline static unsigned int FromLUA(lua_State *L, int arg) {
    lua_Integer i = lua_tointeger(L, arg);
    return ((unsigned int)i);
  }
};
template <> struct TypeConvert<DT_ULONG> {
  inline static int ToLUA(lua_State *L, unsigned long val) {
    lua_pushinteger(L, lua_Integer(val));
    return 1;
  }
  inline static unsigned int FromLUA(lua_State *L, int arg) {
    lua_Integer i = lua_tointeger(L, arg);
    return ((unsigned long)i);
  }
};
template <> struct TypeConvert<DT_FLOAT> {
  inline static int ToLUA(lua_State *L, float val) {
    lua_pushnumber(L, lua_Number(val));
    return 1;
  }
  inline static float FromLUA(lua_State *L, int arg) {
    lua_Number n = lua_tonumber(L, arg);
    return ((float)n);
  }
};
template <> struct TypeConvert<DT_DOUBLE> {
  inline static int ToLUA(lua_State *L, double val) {
    lua_pushnumber(L, val);
    return 1;
  }
  inline static double FromLUA(lua_State *L, int arg) {
    lua_Number n = lua_tonumber(L, arg);
    return n;
  }
};

/*
todo:
  field buffer as pointers ?
*/
    
//template <DataType DT> class StructuredBuffer;

class Structure {
  public:
    
    typedef std::vector<Structure> Array;
    typedef std::vector<Structure*> PtrArray;    

    static const size_t InvalidIndex = size_t(-1);
    
  public:

    template <DataType DT> friend class StructuredBuffer;
    
    Structure();
    Structure(const std::string &n);
    Structure(const Structure &rhs);
    ~Structure();
    
    Structure& operator=(const Structure &rhs);
    bool operator==(const Structure &rhs) const;
    
    inline bool operator!=(const Structure &rhs) const {
      return !operator==(rhs);
    }
    
    inline size_t getOffset() const {
      return mOffset;
    }
    
    inline size_t getFieldCount() const {
      return mCount;
    }
    
    inline bool isTerminal() const {
      return (mSubs.size() == 0);
    }
    
    inline bool isFinalized() const {
      return mFinalized;
    }
    
    inline const std::string& getName() const {
      return mName;
    }
    
    Structure& addField(const std::string &name) throw (std::runtime_error);

    size_t getFieldIndex(const std::string &name) const;
    
    inline bool hasField(const std::string &name) const {
      return (getFieldIndex(name) != InvalidIndex);
    }
    
    const Structure& getField(size_t idx) const throw(std::runtime_error);
    Structure& getField(size_t idx) throw(std::runtime_error);
       
    const Structure& getField(const std::string &name) const throw(std::runtime_error);
    Structure& getField(const std::string &name) throw(std::runtime_error);

    inline void finalize() {
      if (!mFinalized) {
        resolve();
        mFinalized = true;
      }
    }
  
    inline void resolve() {
      size_t tmp = 0;
      resolve(tmp);
    }

    std::string toString() const;
    
    template <typename T>
    std::string toString(const T *values) const {
      std::ostringstream oss;
      if (!isTerminal()) {
        oss << "{";
        for (size_t i=0; i<mSubs.size(); ++i) {
          oss << mSubs[i].getName() << ": "
              << mSubs[i].toString(values);
          if (i != (mSubs.size()-1)) {
            oss << ", ";
          }
        }
        oss << "}";
      } else {
        oss << values[mOffset];
      }
      return oss.str();
    }
    
  protected:
    
    void resolve(size_t &off);
      
  protected:
    
    std::string mName;
    size_t mOffset;
    size_t mCount;
    Array mSubs;
    bool mFinalized;
};

// ---

template <DataType DT>
class Buffer {
  public:
    
    typedef typename Enum2Type<DT>::T T;

    Buffer();
    Buffer(size_t n);
    Buffer(T *foreign, size_t n);
    Buffer(const Buffer &rhs);
    ~Buffer();

    Buffer& operator=(const Buffer &rhs);
    
    inline DataType getType() const {
      return DT;
    }

    inline size_t getElementSize() const {
      return TypeSize<DT>::Size;
    }

    inline size_t getElementCount() const {
      return mSize;
    }

    inline size_t getElementStride() const {
      return 1;
    }

    inline operator T* () {
      return mData;
    }

    inline operator const T* () const {
      return mData;
    }
    
    inline Buffer<DT> offset(size_t n) {
      return Buffer<DT>(mData+n, mSize-n);
    }

  protected:

    T *mData;
    size_t mSize;
    mutable bool mOwns;
};


template <DataType DT>
Buffer<DT>::Buffer()
  : mData(0), mSize(0), mOwns(true) {
}

template <DataType DT>
Buffer<DT>::Buffer(size_t n)
  : mData(0), mSize(n), mOwns(true) {
  mData = new T[n];
  for (size_t i=0; i<n; ++i) {
    mData[i] = T(0);
  }
}

template <DataType DT>
Buffer<DT>::Buffer(T *foreign, size_t n)
  : mData(foreign), mSize(n), mOwns(false) {
}

template <DataType DT>
Buffer<DT>::Buffer(const Buffer &rhs)
  : mData(rhs.mData), mSize(rhs.mSize), mOwns(rhs.mOwns) {
  rhs.mOwns = false;
}

template <DataType DT>
Buffer<DT>::~Buffer() {
  if (mData && mOwns) {
#ifdef _DEBUG
    std::cout << "Free buffer" << std::endl;
#endif
    delete[] mData;
  }
}

template <DataType DT>
Buffer<DT>& Buffer<DT>::operator=(const Buffer<DT> &rhs) {
  if (this != &rhs) {
    if (mData && mOwns) {
#ifdef _DEBUG
      std::cout << "Free buffer" << std::endl;
#endif
      delete[] mData;
    }
    mData = rhs.mData;
    mSize = rhs.mSize;
    mOwns = rhs.mOwns;
    rhs.mOwns = false;
  }
  return *this;
}

// ---

template <DataType DT>
class StructuredBuffer {
  public:
    
    typedef typename Enum2Type<DT>::T T;
    
    StructuredBuffer();
    StructuredBuffer(const Structure &d, size_t n);
    StructuredBuffer(const Structure &d, T *foreign, size_t n, size_t es);
    StructuredBuffer(const StructuredBuffer &rhs);
    ~StructuredBuffer();
    
    StructuredBuffer& operator=(const StructuredBuffer &rhs);
    
    inline DataType getType() const {
      return DT;
    }

    // use this one at your own risk [hint: single element buffer iterator]
    inline void next() {
      // mData += mElementStride;
      if (mIsIter) {
        mData += mIterStride;
      }
    }
    
    inline const Structure& getStructure() const {
      return mStructure;
    }
    
    inline size_t getFieldOffset(const std::string &str) const throw(std::runtime_error) {
      return mStructure.getField(str).getOffset();
    }
    
    inline size_t getFieldCount() const {
      return mStructure.getFieldCount();
    }

    inline size_t getElementStride() const {
      return mElementStride;
    }
    
    inline size_t getElementSize() const {
      return (getElementStride() * TypeSize<DT>::Size);
    }
    
    inline size_t getElementOffset(size_t idx) const {
      return (getElementStride() * idx);
    }
    
    inline operator T* () {
      return mData;
    }
    
    inline operator const T* () const {
      return mData;
    }
    
    inline T* getRawField(const std::string &str) throw(std::runtime_error) {
      return (mData + getFieldOffset(str));
    }
    
    inline const T* getRawField(const std::string &str) const throw(std::runtime_error) {
      return (mData + getFieldOffset(str));
    }
    
    inline size_t getElementCount() const {
      return mSize;
    }
    
    StructuredBuffer getFieldBuffer(const std::string &name) throw(std::runtime_error);
    
    StructuredBuffer getElement(size_t idx) throw(std::runtime_error);
    
    std::string toString() const;
    
    inline bool asIterator() {
      if (!mOwns) {
        mIsIter = true;
        mIterStride = mElementStride;
        // override mElementStride as it is used to compute element size
        mElementStride = getFieldCount();
        return true;
      } else {
        return false;
      }
    }
    
  protected:
    
    Structure mStructure;
    T *mData;
    size_t mSize;
    mutable bool mOwns;
    size_t mElementStride;
    bool mIsIter;
    size_t mIterStride;
};

template <DataType DT>
StructuredBuffer<DT>::StructuredBuffer()
  : mData(0), mSize(0), mOwns(true), mElementStride(0), mIsIter(false), mIterStride(0) {
} 

template <DataType DT>
StructuredBuffer<DT>::StructuredBuffer(const Structure &s, size_t n)
  : mStructure(s), mSize(n), mOwns(true), mIsIter(false), mIterStride(0) {
  mElementStride = s.getFieldCount();
  mData = new T[n * getFieldCount()];
  for (size_t i=0; i<n; ++i) {
    mData[i] = T(0);
  }
}

template <DataType DT>
StructuredBuffer<DT>::StructuredBuffer(const Structure &s, T *foreign,
                                       size_t n, size_t es)
  : mStructure(s), mData(foreign), mSize(n), mOwns(false), mElementStride(es),
    mIsIter(false), mIterStride(0) {
}

template <DataType DT>
StructuredBuffer<DT>::StructuredBuffer(const StructuredBuffer<DT> &rhs)
  : mStructure(rhs.mStructure), mData(rhs.mData),
    mSize(rhs.mSize), mOwns(rhs.mOwns), mElementStride(rhs.mElementStride),
    mIsIter(rhs.mIsIter), mIterStride(rhs.mIterStride) {
  if (mIsIter) {
    // do not steal ownership
    mOwns = false;
  } else {
    rhs.mOwns = false;
  }
}

template <DataType DT>
StructuredBuffer<DT>::~StructuredBuffer() {
  if (mData && mOwns) {
#ifdef _DEBUG
    std::cout << "Free structured buffer" << std::endl;
#endif
    delete[] mData;
  }
}

template <DataType DT>
StructuredBuffer<DT>& StructuredBuffer<DT>::operator=(const StructuredBuffer<DT> &rhs) {
  if (this != &rhs) {
    if (mData && mOwns) {
#ifdef _DEBUG
      std::cout << "Free structured buffer" << std::endl;
#endif
      delete[] mData;
    }
    mStructure = rhs.mStructure;
    mData = rhs.mData;
    mSize = rhs.mSize;
    mElementStride = rhs.mElementStride;
    mOwns = rhs.mOwns;
    mIsIter = rhs.mIsIter;
    rhs.mOwns = false;
  }
  return *this;
}

template <DataType DT>
StructuredBuffer<DT> StructuredBuffer<DT>::getFieldBuffer(const std::string &name) throw(std::runtime_error) {
  Structure s = mStructure.getField(name);
  T *data = mData + s.getOffset();
  // reset offsets, so that start from 0 [offset is included in data ptr]
  // what this means is that we really need to copy the structure
  s.resolve();
  //return StructuredBuffer(s, data, mSize, getElementStride());
  if (mIsIter) {
    StructuredBuffer tmp(s, data, mSize, mIterStride);
    tmp.asIterator();
    return tmp;
  } else {
    return StructuredBuffer(s, data, mSize, getElementStride());
  }
}

template <DataType DT>
StructuredBuffer<DT> StructuredBuffer<DT>::getElement(size_t idx) throw(std::runtime_error) {
  if (idx >= mSize) {
    throw std::runtime_error("StructuredBuffer::element: Invalid index");
  }
  T *ptr = mData + idx * getElementStride();
  return StructuredBuffer(mStructure, ptr, 1, getElementStride());
}

template <DataType DT>
std::string StructuredBuffer<DT>::toString() const {
  std::ostringstream oss;
  oss << "{";
  for (size_t i=0; i<mSize; ++i) {
    size_t off = i * getElementStride();
    oss << mStructure.toString(mData+off);
    if (i != mSize-1) {
      oss << std::endl;
    }
  }
  oss << "}";
  return oss.str();
}

#endif
