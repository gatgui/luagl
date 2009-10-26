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

#include "raw.h"
#include <iostream>

#define CHECK_ARG_COUNT(L, n) \
  if (lua_gettop(L) != n) {\
    lua_pushfstring(L, "%d arguments expected (including self when it applies)", n);\
    lua_error(L);\
  }

Structure::Structure()
  : mName("-"), mOffset(0), mCount(0), mFinalized(false) {
}

Structure::Structure(const std::string &n)
  : mName(n), mOffset(0), mCount(0), mFinalized(false) {
}

Structure::Structure(const Structure &rhs)
  : mName(rhs.mName), mOffset(rhs.mOffset),
    mCount(rhs.mCount), mSubs(rhs.mSubs),
    mFinalized(rhs.mFinalized) {
}

Structure::~Structure() {
}

Structure& Structure::operator=(const Structure &rhs) {
  if (this != &rhs) {
    mName = rhs.mName;
    mOffset = rhs.mOffset;
    mCount = rhs.mCount;
    mSubs = rhs.mSubs;
    mFinalized = rhs.mFinalized;
  }
  return *this;
}

bool Structure::operator==(const Structure &rhs) const {
  if (this != &rhs) {
    if (mName != rhs.mName) {
      return false;
    }
    if (mOffset != rhs.mOffset) {
      return false;
    }
    if (mCount != rhs.mCount) {
      return false;
    }
    if (mSubs.size() != rhs.mSubs.size()) {
      return false;
    }
    for (size_t i=0; i<mSubs.size(); ++i) {
      if (mSubs[i] != rhs.mSubs[i]) {
        return false;
      }
    }
  }
  return true;
}

Structure&
Structure::addField(const std::string &name) throw (std::runtime_error) {
  if (mFinalized) {
    throw std::runtime_error("Structure:add: description is finalized");
  }
  Structure sub(name);
  mSubs.push_back(sub);
  return mSubs.back();
}

size_t Structure::getFieldIndex(const std::string &name) const {
  for (size_t i=0; i<mSubs.size(); ++i) {
    if (mSubs[i].getName() == name) {
      return i;
    }
  }
  return InvalidIndex;
}

const Structure&
Structure::getField(size_t idx) const throw(std::runtime_error) {
  if (idx >= mSubs.size()) {
    throw std::runtime_error("Structure::getField: Invalid index");
  }
  return mSubs[idx];
}

const Structure&
Structure::getField(const std::string &name) const throw(std::runtime_error) {
  size_t idx = getFieldIndex(name);
  if (idx == InvalidIndex) {
    throw std::runtime_error("Structure::getField: Invalid name");
  }
  return mSubs[idx];
}

Structure&
Structure::getField(size_t idx) throw(std::runtime_error) {
  if (idx >= mSubs.size()) {
    throw std::runtime_error("Structure::getField: Invalid index");
  }
  return mSubs[idx];
}

Structure&
Structure::getField(const std::string &name) throw(std::runtime_error) {
  size_t idx = getFieldIndex(name);
  if (idx == InvalidIndex) {
    throw std::runtime_error("Structure::getField: Invalid name");
  }
  return mSubs[idx];
}

void Structure::resolve(size_t &off) {
  mOffset = off;
  mCount = 0;
  for (size_t i=0; i<mSubs.size(); ++i) {
    mSubs[i].resolve(off);
    mCount += mSubs[i].getFieldCount();
  }
  if (mCount == 0) {
    mCount = 1;
    ++off;
  }
}

std::string Structure::toString() const {
  std::ostringstream oss;
  if (isTerminal()) {
    oss << mName;
  } else {
    oss << "{ " << mName << ": ";
    for (size_t i=0; i<mSubs.size(); ++i) {
      oss << mSubs[i].toString() << " ";
    }
    oss << "}";
  }
  return oss.str();
}

// ---

class LuaStructure {
  public:
    
    Structure *structure;
    bool owns;
  
    LuaStructure()
      : structure(0), owns(true) {
      void *ptr = (void*)(((unsigned char*)this) + sizeof(LuaStructure));
      structure = new (ptr) Structure();
    }

    LuaStructure(Structure *s)
      : structure(s), owns(false) {
    }
    
    ~LuaStructure() {
      if (structure && owns) {
        structure->~Structure();
      }
    }

    inline static size_t AllocSize() {
      return (sizeof(LuaStructure) + sizeof(Structure));
    }

    inline static const char* RegistryKey() {
      return "__luaraw_structure";
    }
};

static int structure_new_nocheck(lua_State *L) {
  void *ud = lua_newuserdata(L, LuaStructure::AllocSize());
  new (ud) LuaStructure();
  lua_getfield(L, LUA_REGISTRYINDEX, LuaStructure::RegistryKey());
  lua_setmetatable(L, -2);
  return 1;
}

static int structure_new(lua_State *L) {
  CHECK_ARG_COUNT(L, 0);
  void *ud = lua_newuserdata(L, LuaStructure::AllocSize());
  new (ud) LuaStructure();
  lua_getfield(L, LUA_REGISTRYINDEX, LuaStructure::RegistryKey());
  lua_setmetatable(L, -2);
  return 1;
}

// this one is not called from LUA directly
static int structure_wrap(lua_State *L, Structure *d) {
  void *ud = lua_newuserdata(L, sizeof(LuaStructure));
  new (ud) LuaStructure(d);
  lua_getfield(L, LUA_REGISTRYINDEX, LuaStructure::RegistryKey());
  lua_setmetatable(L, -2);
  return 1;
}

static int structure_del(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  void *ud = lua_touserdata(L, 1);
  ((LuaStructure*)ud)->~LuaStructure();
  lua_pop(L, 1);
  return 0;
}

static Structure* structure_check(lua_State *L, int narg, bool up=false) {
  int idx = (up ? lua_upvalueindex(narg) : narg);
  // could be a subclass
  void *p = lua_touserdata(L, idx);
  if (!p) {
    luaL_typerror(L, narg, "raw.Structure");
  }
  lua_getfield(L, LUA_REGISTRYINDEX, LuaStructure::RegistryKey());
  if (!lua_getmetatable(L, idx) || !lua_rawequal(L, -1, -2)) {
    luaL_typerror(L, narg, "raw.Structure");
  }
  lua_pop(L, 2);
  return ((LuaStructure*) p)->structure;
}

static int structure_offset(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Structure *s = structure_check(L, 1);
  lua_pushinteger(L, s->getOffset());
  return 1;
}

static int structure_count(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Structure *s = structure_check(L, 1);
  lua_pushinteger(L, s->getFieldCount());
  return 1;
}

static int structure_equal(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Structure *s0 = structure_check(L, 1);
  Structure *s1 = structure_check(L, 2);
  if (*s0 == *s1) {
    lua_pushboolean(L, 1);
  } else {
    lua_pushboolean(L, 0);
  }
  return 1;
}

static int structure_terminal(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Structure *s = structure_check(L, 1);
  lua_pushboolean(L, s->isTerminal() ? 1 : 0);
  return 1;
}

static int structure_finalized(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Structure *s = structure_check(L, 1);
  lua_pushboolean(L, s->isFinalized() ? 1 : 0);
  return 1;
}

static int structure_name(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Structure *s = structure_check(L, 1);
  lua_pushstring(L, s->getName().c_str());
  return 1;
}

static int structure_fieldindex(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Structure *s = structure_check(L, 1);
  const char *fn = lua_tostring(L, 2);
  size_t idx = s->getFieldIndex(fn);
  if (idx == Structure::InvalidIndex) {
    lua_pushinteger(L, -1);
  } else {
    lua_pushinteger(L, idx);
  }
  return 1;
}

static int structure_addfield(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Structure *s = structure_check(L, 1);
  const char *fn = lua_tostring(L, 2);
  try {
    Structure &r = s->addField(fn);
    structure_wrap(L, &r);
  } catch (std::runtime_error &) {
    lua_pushstring(L, "raw.Structure: cannot add to finalized description");
    lua_error(L);
  }
  return 1;
}

static int structure_hasfield(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Structure *s = structure_check(L, 1);
  const char *fn = lua_tostring(L, 2);
  lua_pushboolean(L, s->hasField(fn) ? 1 : 0);
  return 1;
}

static int structure_finalize(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Structure *s = structure_check(L, 1);
  s->finalize();
  return 0;
}

static int structure_getfield(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Structure *s = structure_check(L, 1);
  try {
    Structure *r = 0;
    if (lua_isnumber(L, 2)) {
      // start with 1
      size_t idx = lua_tointeger(L, 2);
      if (idx == 0) {
        lua_pushstring(L, "raw.Structure.field: invalid index");
        lua_error(L);
      }
      idx -= 1;
      r = &(s->getField(idx));
    } else {
      const char *fn = lua_tostring(L, 2);
      r = &(s->getField(fn));
    }
    structure_wrap(L, r);
  } catch (std::runtime_error &) {
    lua_pushstring(L, "raw.Structure.field: Invalid name");
    lua_error(L);
  }
  return 1;
}

static int structure_tostring(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Structure *s = structure_check(L, 1);
  std::string str = s->toString();
  lua_pushstring(L, str.c_str());
  return 1;
}

static void raw_addfields(lua_State *L, int arg, Structure *s) {
  if (lua_istable(L, arg)) {
    // hum ...
    // if size == 2 && string + table -> subentry
    size_t len = lua_objlen(L, arg);
    if (len > 0) {
      // first entry MUST be a string
      lua_pushinteger(L, 1);
      lua_gettable(L, arg);
      if (!lua_isstring(L, -1)) {
        lua_pushstring(L, "raw.MakeStructure: invalid structure specification");
        lua_error(L);
      }
      // still first entry on top
      std::string fn = lua_tostring(L, -1);
      lua_pop(L, 1);
      Structure *ss = &(s->addField(fn));
      // sub structure ?
      if (len == 2) {
        lua_pushinteger(L, 2);
        lua_gettable(L, arg);
        if (lua_istable(L, -1)) {
          raw_addfields(L, lua_gettop(L), ss);
          lua_pop(L, 1);
        } else if (lua_isstring(L, -1)) {
          //s->addField(fn); already added
          s->addField(lua_tostring(L, -1));
          lua_pop(L, 1);
        } else {
          lua_pushstring(L, "raw.MakeStructure: invalid structure specification");
          lua_error(L);
        }
      } else {
        for (size_t i=2; i<=len; ++i) {
          lua_pushinteger(L, i);
          lua_gettable(L, arg);
          if (!lua_isstring(L, -1)) {
            lua_pushstring(L, "raw.MakeStructure: invalid structure specification");
            lua_error(L);
          }
          const char *fn = lua_tostring(L, -1);
          s->addField(fn);
          lua_pop(L, 1);
        }
      }
    }
    // else -> all strings -> add all top s
  } else {
    if (lua_isstring(L, arg)) {
      const char *fn = lua_tostring(L, arg);
      s->addField(fn);
    } else {
      lua_pushstring(L, "raw.MakeStructure: invalid structure specification");
      lua_error(L);
    }
  }
}

static int raw_makestructure(lua_State *L) {
  int narg = lua_gettop(L);
  
  structure_new_nocheck(L);
  
  Structure *s = structure_check(L, lua_gettop(L));
  for (int i=1; i<=narg; ++i) {
    raw_addfields(L, i, s);
  }
  s->finalize();
  return 1;
}

// ---

static const char* RegistryKeys[DT_MAX] = {
  "__luaraw_byte_buffer",
  "__luaraw_short_buffer",
  "__luaraw_int_buffer",
  "__luaraw_long_buffer",
  "__luaraw_ubyte_buffer",
  "__luaraw_ushort_buffer",
  "__luaraw_uint_buffer",
  "__luaraw_ulong_buffer",
  "__luaraw_float_buffer",
  "__luaraw_double_buffer"
};

static const char* ClassNames[DT_MAX] = {
  "ByteBuffer",
  "ShortBuffer",
  "IntBuffer",
  "LongBuffer",
  "UbyteBuffer",
  "UshortBuffer",
  "UintBuffer",
  "UlongBuffer",
  "FloatBuffer",
  "DoubleBuffer"
};

template <DataType DT>
class LuaBuffer {
  public:
    Buffer<DT> *buffer;
    bool owns;

    LuaBuffer()
      : buffer(0), owns(true) {
      void *ptr = (void*)(((unsigned char*)this) + sizeof(LuaBuffer<DT>));
      buffer = new (ptr) Buffer<DT>();
    }
  
    LuaBuffer(size_t n)
      : buffer(0), owns(true) {
      void *ptr = (void*)(((unsigned char*)this) + sizeof(LuaBuffer<DT>));
      buffer = new (ptr) Buffer<DT>(n);
    }
    
    LuaBuffer(Buffer<DT> *b)
      : buffer(b), owns(false) {
    }
    
    ~LuaBuffer() {
      if (buffer && owns) {
        buffer->~Buffer<DT>();
      }
    }

    inline static size_t AllocSize() {
      return (sizeof(LuaBuffer<DT>) + sizeof(Buffer<DT>));
    }

    inline static const char* RegistryKey() {
      return RegistryKeys[DT];
    }

    inline static const char* ClassName() {
      return ClassNames[DT];
    }
};

template <DataType DT>
static int buffer_new(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  size_t sz = lua_tointeger(L, 1);
  void *ud = lua_newuserdata(L, LuaBuffer<DT>::AllocSize());
  new (ud) LuaBuffer<DT>(sz);
  lua_getfield(L, LUA_REGISTRYINDEX, LuaBuffer<DT>::RegistryKey());
  lua_setmetatable(L, -2);
  return 1;
}

template <DataType DT>
static int buffer_new2(lua_State *L) {
  void *ud = lua_newuserdata(L, LuaBuffer<DT>::AllocSize());
  new (ud) LuaBuffer<DT>();
  lua_getfield(L, LUA_REGISTRYINDEX, LuaBuffer<DT>::RegistryKey());
  lua_setmetatable(L, -2);
  return 1;
}

template <DataType DT>
static int buffer_del(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  LuaBuffer<DT> *lb = (LuaBuffer<DT>*) lua_touserdata(L, 1);
  lb->~LuaBuffer<DT>();
  lua_pop(L, 1);
  return 0;
}

template <DataType DT>
static Buffer<DT>* buffer_check(lua_State *L, int arg, bool up=false) {
  int idx = (up ? lua_upvalueindex(arg) : arg);
  void *p = lua_touserdata(L, idx);
  if (!p) {
    luaL_typerror(L, arg, "raw.Buffer");
  }
  lua_getfield(L, LUA_REGISTRYINDEX, LuaBuffer<DT>::RegistryKey());
  if (!lua_getmetatable(L, idx) || !lua_rawequal(L, -1, -2)) {
    luaL_typerror(L, arg, "raw.Buffer");
  }
  lua_pop(L, 2);
  return ((LuaBuffer<DT>*) p)->buffer;
}

template <DataType DT>
static int buffer_elementcount(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Buffer<DT> *b = buffer_check<DT>(L, 1);
  lua_pushinteger(L, b->getElementCount());
  return 1;
}

template <DataType DT>
static int buffer_elementsize(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Buffer<DT> *b = buffer_check<DT>(L, 1);
  lua_pushinteger(L, b->getElementSize());
  return 1;
}

template <DataType DT>
static int buffer_type(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Buffer<DT> *b = buffer_check<DT>(L, 1);
  lua_pushinteger(L, b->getType());
  return 1;
}

template <DataType DT>
static int buffer_index(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Buffer<DT> *b = buffer_check<DT>(L, 1);
  if (lua_isnumber(L, 2)) {
    size_t i = lua_tointeger(L, 2);
    if (i < 1 || i > (b->getElementCount())) {
      lua_pushstring(L, "raw.Buffer.__index: invalid index");
      lua_error(L);
    }
    TypeConvert<DT>::ToLUA(L, (*b)[i-1]);
    return 1;
  }
  lua_getmetatable(L, 1);
  lua_pushvalue(L, 2);
  lua_gettable(L, -2);
  return 1;
}

template <DataType DT>
static int buffer_newindex(lua_State *L) {
  CHECK_ARG_COUNT(L, 3);
  Buffer<DT> *b = buffer_check<DT>(L, 1);
  if (lua_isnumber(L, 3) && lua_isnumber(L, 2)) {
    size_t i = lua_tointeger(L, 2);
    if (i < 1 || i > (b->getElementCount())) {
      lua_pushstring(L, "raw.Buffer.__newindex: invalid index");
      lua_error(L);
    }
    (*b)[i-1] = TypeConvert<DT>::FromLUA(L, 3);
    return 0;
  }
  lua_pushstring(L, "raw.Buffer: not modifiable");
  lua_error(L);
  return 0;
}

template <DataType DT>
static int buffer_rawptr(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Buffer<DT> *b = buffer_check<DT>(L, 1);
  typename Enum2Type<DT>::T *ptr = *b;
  lua_pushlightuserdata(L, (void*)ptr);
  return 1;
}

template <DataType DT>
static int buffer_offset(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Buffer<DT> *b = buffer_check<DT>(L, 1);
  size_t off = lua_tointeger(L, 2);
  Buffer<DT> ob = b->offset(off);
  buffer_new2<DT>(L);
  Buffer<DT> *r = buffer_check<DT>(L, lua_gettop(L));
  *r = ob;
  return 1;
}

template <DataType DT>
static int buffer_tostring(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  return 1;
}

// also add rawptr function in lua -> lightuserdata
// so can use from other modules through lua function call

template <DataType DT>
static void register_buffer(lua_State *L, int module) {

  lua_newtable(L);
  int klass = lua_gettop(L);

  lua_pushcfunction(L, buffer_new<DT>);
  lua_setfield(L, klass, "new");
  lua_pushcfunction(L, buffer_del<DT>);
  lua_setfield(L, klass, "__gc");
  lua_pushcfunction(L, buffer_index<DT>);
  lua_setfield(L, klass, "__index");
  lua_pushcfunction(L, buffer_newindex<DT>);
  lua_setfield(L, klass, "__newindex");
  lua_pushcfunction(L, buffer_tostring<DT>);
  lua_setfield(L, klass, "__tostring");
  lua_pushcfunction(L, buffer_elementcount<DT>);
  lua_setfield(L, klass, "__len");
  lua_pushcfunction(L, buffer_type<DT>);
  lua_setfield(L, klass, "type");
  lua_pushcfunction(L, buffer_elementsize<DT>);
  lua_setfield(L, klass, "element_size");
  lua_pushcfunction(L, buffer_elementcount<DT>);
  lua_setfield(L, klass, "element_count");
  lua_pushcfunction(L, buffer_rawptr<DT>);
  lua_setfield(L, klass, "raw_ptr");
  lua_pushcfunction(L, buffer_offset<DT>);
  lua_setfield(L, klass, "offset");

  lua_pushvalue(L, klass);
  lua_setfield(L, LUA_REGISTRYINDEX, LuaBuffer<DT>::RegistryKey());

  lua_setfield(L, module, LuaBuffer<DT>::ClassName());
}


// ---

static const char* SRegistryKeys[DT_MAX] = {
  "__luaraw_struct_byte_buffer",
  "__luaraw_struct_short_buffer",
  "__luaraw_struct_int_buffer",
  "__luaraw_struct_long_buffer",
  "__luaraw_struct_ubyte_buffer",
  "__luaraw_struct_ushort_buffer",
  "__luaraw_struct_uint_buffer",
  "__luaraw_struct_ulong_buffer",
  "__luaraw_struct_float_buffer",
  "__luaraw_struct_double_buffer"
};

static const char* SClassNames[DT_MAX] = {
  "StructuredByteBuffer",
  "StructuredShortBuffer",
  "StructuredIntBuffer",
  "StructuredLongBuffer",
  "StructuredUbyteBuffer",
  "StructuredUshortBuffer",
  "StructuredUintBuffer",
  "StructuredUlongBuffer",
  "StructuredFloatBuffer",
  "StructuredDoubleBuffer"
};

template <DataType DT>
class LuaStructuredBuffer {
  public:

    typedef typename Enum2Type<DT>::T T;

    StructuredBuffer<DT> *buffer;
    bool owns;

    LuaStructuredBuffer()
      : buffer(0), owns(true) {
      void *ptr = (void*)(((unsigned char*)this) + sizeof(LuaStructuredBuffer<DT>));
      buffer = new (ptr) StructuredBuffer<DT>();
    }
  
    LuaStructuredBuffer(Structure *d, size_t n)
      : buffer(0), owns(true) {
      void *ptr = (void*)(((unsigned char*)this) + sizeof(LuaStructuredBuffer<DT>));
      buffer = new (ptr) StructuredBuffer<DT>(*d, n);
    }

    LuaStructuredBuffer(const Structure &s, T *data, size_t n, size_t es)
      : buffer(0), owns(true) {
      void *ptr = (void*)(((unsigned char*)this) + sizeof(LuaStructuredBuffer<DT>));
      buffer = new (ptr) StructuredBuffer<DT>(s, data, n, es);
    }
    
    LuaStructuredBuffer(StructuredBuffer<DT> *b)
      : buffer(b), owns(false) {
    }
    
    ~LuaStructuredBuffer() {
      if (buffer && owns) {
        //delete buffer;
        buffer->~StructuredBuffer<DT>();
      }
    }

    inline static size_t AllocSize() {
      return (sizeof(LuaStructuredBuffer<DT>) + sizeof(StructuredBuffer<DT>));
    }

    inline static const char* RegistryKey() {
      return SRegistryKeys[DT];
    }

    inline static const char* ClassName() {
      return SClassNames[DT];
    }
};

template <DataType DT>
static int struct_buffer_new(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  void *ud = lua_newuserdata(L, LuaStructuredBuffer<DT>::AllocSize());
  Structure *d = structure_check(L, 1);
  size_t n = lua_tointeger(L, 2);
  new (ud) LuaStructuredBuffer<DT>(d, n);
  lua_getfield(L, LUA_REGISTRYINDEX, LuaStructuredBuffer<DT>::RegistryKey());
  lua_setmetatable(L, -2);
  return 1;
}

// not called from lua directly -> no check
template <DataType DT>
static int struct_buffer_new2(lua_State *L) {
  void *ud = lua_newuserdata(L, LuaStructuredBuffer<DT>::AllocSize());
  new (ud) LuaStructuredBuffer<DT>();
  lua_getfield(L, LUA_REGISTRYINDEX, LuaStructuredBuffer<DT>::RegistryKey());
  lua_setmetatable(L, -2);
  return 1;   
}

template <DataType DT>
static int struct_buffer_del(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  void *ud = lua_touserdata(L, 1);
  ((LuaStructuredBuffer<DT>*)ud)->~LuaStructuredBuffer<DT>();
  lua_pop(L, 1);
  return 0;
}

template <DataType DT>
static StructuredBuffer<DT>* struct_buffer_check(lua_State *L, int narg, bool up=false) {
  int idx = (up ? lua_upvalueindex(narg) : narg);
  void *p = lua_touserdata(L, idx);
  if (!p) {
    luaL_typerror(L, narg, "raw.StructuredBuffer");
  }
  lua_getfield(L, LUA_REGISTRYINDEX, LuaStructuredBuffer<DT>::RegistryKey());
  if (!lua_getmetatable(L, idx) || !lua_rawequal(L, -1, -2)) {
    luaL_typerror(L, narg, "raw.StructuredBuffer");
  }
  lua_pop(L, 2);
  return ((LuaStructuredBuffer<DT>*) p)->buffer;
}

template <DataType DT>
static int struct_buffer_type(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  StructuredBuffer<DT> *b = struct_buffer_check<DT>(L, 1);
  lua_pushinteger(L, b->getType());
  return 1;
}

template <DataType DT>
static int struct_buffer_structure(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  StructuredBuffer<DT> *b = struct_buffer_check<DT>(L, 1);
  const Structure &d = b->getStructure();
  structure_wrap(L, (Structure*)&d);
  return 1;
}

template <DataType DT>
static int struct_buffer_fieldcount(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  StructuredBuffer<DT> *b = struct_buffer_check<DT>(L, 1);
  lua_pushinteger(L, b->getFieldCount());
  return 1;
}

template <DataType DT>
static int struct_buffer_elementstride(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  StructuredBuffer<DT> *b = struct_buffer_check<DT>(L, 1);
  lua_pushinteger(L, b->getElementStride());
  return 1;
}

template <DataType DT>
static int struct_buffer_elementsize(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  StructuredBuffer<DT> *b = struct_buffer_check<DT>(L, 1);
  lua_pushinteger(L, b->getElementSize());
  return 1;
}

template <DataType DT>
static int struct_buffer_elementcount(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  StructuredBuffer<DT> *b = struct_buffer_check<DT>(L, 1);
  lua_pushinteger(L, b->getElementCount());
  return 1;
}

template <DataType DT>
static int struct_buffer_len(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  StructuredBuffer<DT> *b = struct_buffer_check<DT>(L, 1);
  lua_pushinteger(L, b->getElementCount()*b->getElementStride());
  return 1;
}

template <DataType DT>
static int struct_buffer_fieldoffset(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  StructuredBuffer<DT> *b = struct_buffer_check<DT>(L, 1);
  const char *name = lua_tostring(L, 2);
  try {
    lua_pushinteger(L, b->getFieldOffset(name));
  } catch (std::runtime_error &) {
    lua_pushstring(L, "invalid name");
    lua_error(L);
  }
  return 1;
}

template <DataType DT>
static int struct_buffer_elementoffset(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  StructuredBuffer<DT> *b = struct_buffer_check<DT>(L, 1);
  size_t idx = lua_tointeger(L, 2);
  if (idx == 0) {
    lua_pushstring(L, "raw.StructuredBuffer.element_offset: invalid index");
    lua_error(L);
  }
  lua_pushinteger(L, b->getElementOffset(idx-1));
  return 1;
}

template <DataType DT>
static int struct_buffer_fieldbuffer(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  StructuredBuffer<DT> *b = struct_buffer_check<DT>(L, 1);
  const char *name = lua_tostring(L, 2);
  try {
    StructuredBuffer<DT> fb = b->getFieldBuffer(name);
    struct_buffer_new2<DT>(L);
    StructuredBuffer<DT> *r = struct_buffer_check<DT>(L, lua_gettop(L));
    *r = fb;
  } catch (std::runtime_error &) {
    lua_pushstring(L, "raw.StructuredBuffer.field_buffer: Invalid field");
    lua_error(L);
  }
  return 1;
}

template <DataType DT>
static int struct_buffer_element(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  StructuredBuffer<DT> *b = struct_buffer_check<DT>(L, 1);
  size_t idx = lua_tointeger(L, 2);
  try {
    StructuredBuffer<DT> fb = b->getElement(idx-1);
    struct_buffer_new2<DT>(L);
    StructuredBuffer<DT> *r = struct_buffer_check<DT>(L, lua_gettop(L));
    *r = fb;
  } catch (std::runtime_error &) {
    lua_pushstring(L, "raw.StructuredBuffer.element: invalid index");
    lua_error(L);
  }
  return 1;
}

template <DataType DT>
static int struct_buffer_index(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  
  StructuredBuffer<DT> *sb = struct_buffer_check<DT>(L, 1);
  
  if (lua_isnumber(L, 2)) {
    size_t n = lua_tointeger(L, 2);
    if (n < 1 || n > (sb->getElementCount() * sb->getElementStride())) {
      lua_pushstring(L, "raw.StructuredBuffer.__index: invalid index");
      lua_error(L);
    }
    // hum beware !
    // element count == 3
    // element stride == 6
    // buffer[1:2:3] -> 0, 1, 2
    // buffer[4:5:6] -> skip 3, 4, 5, return 6, 7, 8 ???
    TypeConvert<DT>::ToLUA(L, (*sb)[n-1]);
    return 1;
    
  } else if (lua_isstring(L, 2)) {
    const Structure &s = sb->getStructure();
    const char *field = lua_tostring(L, 2);
    if (s.hasField(field)) {
      const Structure &fs = s.getField(field);
      if (fs.isTerminal()) {
        TypeConvert<DT>::ToLUA(L, (*sb)[fs.getOffset()]);
        
      } else {
        struct_buffer_new2<DT>(L);
        StructuredBuffer<DT> *r = struct_buffer_check<DT>(L, lua_gettop(L));
        *r = sb->getFieldBuffer(field);
      }
      return 1;
    }
  }
  lua_getmetatable(L, 1);
  lua_pushvalue(L, 2);
  lua_gettable(L, -2);
  return 1;
}

template <DataType DT>
static int struct_buffer_newindex(lua_State *L) {
  
  CHECK_ARG_COUNT(L, 3);
  
  StructuredBuffer<DT> *sb = struct_buffer_check<DT>(L, 1);
  
  if (lua_isnumber(L, 3)) {
    if (lua_isnumber(L, 2)) {
      size_t n = lua_tointeger(L, 2);
      if (n < 1 || n > (sb->getElementCount() * sb->getElementStride())) {
        lua_pushstring(L, "raw.StructuredBuffer.__newindex: invalid index");
        lua_error(L);
      }
      (*sb)[n-1] = TypeConvert<DT>::FromLUA(L, 3);
      return 0;
      
    } else if (lua_isstring(L, 2)) {
      
      const Structure &s = sb->getStructure();
      const char *field = lua_tostring(L, 2);
      
      if (s.hasField(field)) {
        const Structure &fs = s.getField(field);
        if (fs.isTerminal()) {
          (*sb)[fs.getOffset()] = TypeConvert<DT>::FromLUA(L, 3);
          return 0;
        }
      }
    }
  }
  
  lua_pushstring(L, "raw.StructuredBuffer.__newindex: not modifiable");
  lua_error(L);
  
  return 0;
}

template <DataType DT>
static int struct_buffer_rawptr(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  StructuredBuffer<DT> *b = struct_buffer_check<DT>(L, 1);
  typename Enum2Type<DT>::T *ptr = *b;
  lua_pushlightuserdata(L, (void*)ptr);
  return 1;
}

template <DataType DT>
static int struct_buffer_tostring(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  StructuredBuffer<DT> *sb = struct_buffer_check<DT>(L, 1);
  std::string s = sb->toString();
  lua_pushstring(L, s.c_str());
  return 1;
}

// there's a little trick here to avoid repeated allocation of
// a separated StructuredBuffer user data

template <DataType DT>
static int struct_buffer_iterator(lua_State *L) {
  StructuredBuffer<DT> *e = struct_buffer_check<DT>(L, 1, true);
  size_t n = lua_tointeger(L, lua_upvalueindex(2));
  size_t i = lua_tointeger(L, lua_upvalueindex(3));
  if (i < n) {
    e->next();
    lua_pushinteger(L, i+1);
    lua_replace(L, lua_upvalueindex(3));
    lua_pushvalue(L, lua_upvalueindex(1));
  } else {
    lua_pushnil(L);
  }
  return 1;
}

template <DataType DT>
static int struct_buffer_elements(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  StructuredBuffer<DT> *sb = struct_buffer_check<DT>(L, 1);
  
  typename Enum2Type<DT>::T *data = *sb;
  const Structure &structure = sb->getStructure();
  size_t stride = sb->getElementStride();

  void *ud = lua_newuserdata(L, LuaStructuredBuffer<DT>::AllocSize());
  // "-stride" a we pre-increment and use the same buffer for each element
  // if we post increment, by the time the buffer is used in lua, it points to next element
  new (ud) LuaStructuredBuffer<DT>(structure, data-stride, 1, stride);
  lua_getfield(L, LUA_REGISTRYINDEX, LuaStructuredBuffer<DT>::RegistryKey());
  lua_setmetatable(L, -2);
  
  lua_pushinteger(L, sb->getElementCount());
  
  lua_pushinteger(L, 0);

  lua_pushcclosure(L, struct_buffer_iterator<DT>, 3);

  return 1;
};

template <DataType DT>
static void register_struct_buffer(lua_State *L, int module) {

  lua_newtable(L);
  int klass = lua_gettop(L);

  lua_pushcfunction(L, struct_buffer_new<DT>);
  lua_setfield(L, klass, "new");
  lua_pushcfunction(L, struct_buffer_del<DT>);
  lua_setfield(L, klass, "__gc");
  lua_pushcfunction(L, struct_buffer_index<DT>);
  lua_setfield(L, klass, "__index");
  lua_pushcfunction(L, struct_buffer_newindex<DT>);
  lua_setfield(L, klass, "__newindex");
  lua_pushcfunction(L, struct_buffer_tostring<DT>);
  lua_setfield(L, klass, "__tostring");
  lua_pushcfunction(L, struct_buffer_type<DT>);
  lua_setfield(L, klass, "type");
  lua_pushcfunction(L, struct_buffer_len<DT>);
  lua_setfield(L, klass, "__len");
  lua_pushcfunction(L, struct_buffer_structure<DT>);
  lua_setfield(L, klass, "structure");
  lua_pushcfunction(L, struct_buffer_fieldcount<DT>);
  lua_setfield(L, klass, "field_count");
  lua_pushcfunction(L, struct_buffer_elementstride<DT>);
  lua_setfield(L, klass, "element_stride");
  lua_pushcfunction(L, struct_buffer_elementsize<DT>);
  lua_setfield(L, klass, "element_size");
  lua_pushcfunction(L, struct_buffer_elementcount<DT>);
  lua_setfield(L, klass, "element_count");
  lua_pushcfunction(L, struct_buffer_elementoffset<DT>);
  lua_setfield(L, klass, "element_offset");
  lua_pushcfunction(L, struct_buffer_fieldoffset<DT>);
  lua_setfield(L, klass, "field_offset");
  lua_pushcfunction(L, struct_buffer_fieldbuffer<DT>);
  lua_setfield(L, klass, "field_buffer");
  lua_pushcfunction(L, struct_buffer_element<DT>);
  lua_setfield(L, klass, "element");
  lua_pushcfunction(L, struct_buffer_elements<DT>);
  lua_setfield(L, klass, "elements");
  lua_pushcfunction(L, struct_buffer_rawptr<DT>);
  lua_setfield(L, klass, "raw_ptr");

  lua_pushvalue(L, klass);
  lua_setfield(L, LUA_REGISTRYINDEX, LuaStructuredBuffer<DT>::RegistryKey());

  lua_setfield(L, module, LuaStructuredBuffer<DT>::ClassName());
}

// ---

static int module_index(lua_State *L) {
  std::string key = lua_tostring(L, 2);
  if (key == "Byte") {
    lua_pushinteger(L, DT_BYTE);
    return 1;
  } else if (key == "Short") {
    lua_pushinteger(L, DT_SHORT);
    return 1;
  } else if (key == "Int") {
    lua_pushinteger(L, DT_INT);
    return 1;
  } else if (key == "Long") {
    lua_pushinteger(L, DT_LONG);
    return 1;
  } else if (key == "Ubyte") {
    lua_pushinteger(L, DT_UBYTE);
    return 1;
  } else if (key == "Ushort") {
    lua_pushinteger(L, DT_USHORT);
    return 1;
  } else if (key == "Uint") {
    lua_pushinteger(L, DT_UINT);
    return 1;
  } else if (key == "Ulong") {
    lua_pushinteger(L, DT_ULONG);
    return 1;
  } else if (key == "Float") {
    lua_pushinteger(L, DT_FLOAT);
    return 1;
  } else if (key == "Double") {
    lua_pushinteger(L, DT_DOUBLE);
    return 1;
  } else {
    lua_pushstring(L, "invalid constant");
    lua_error(L);
  }
  return 0;
}

static int module_newindex(lua_State *L) {
  lua_pushstring(L, "raw module is read only");
  lua_error(L);
  return 0;
}

static int module_newstructbuffer(lua_State *L) {
  CHECK_ARG_COUNT(L, 3);
  
  size_t in_type = lua_tointeger(L, 1);
  Structure *fmt = structure_check(L, 2);
  size_t n = lua_tointeger(L, 3);
  
  void *ud = 0;
  const char *key = 0;
  
  switch (in_type) {
  case DT_UBYTE:
    key = LuaStructuredBuffer<DT_UBYTE>::RegistryKey();
    ud = lua_newuserdata(L, LuaStructuredBuffer<DT_UBYTE>::AllocSize());
    new (ud) LuaStructuredBuffer<DT_UBYTE>(fmt, n);
    break;
  case DT_USHORT:
    key = LuaStructuredBuffer<DT_USHORT>::RegistryKey();
    ud = lua_newuserdata(L, LuaStructuredBuffer<DT_SHORT>::AllocSize());
    new (ud) LuaStructuredBuffer<DT_USHORT>(fmt, n);
    break;
  case DT_UINT:
    key = LuaStructuredBuffer<DT_UINT>::RegistryKey();
    ud = lua_newuserdata(L, LuaStructuredBuffer<DT_UINT>::AllocSize());
    new (ud) LuaStructuredBuffer<DT_UINT>(fmt, n);
    break;
  case DT_ULONG:
    key = LuaStructuredBuffer<DT_ULONG>::RegistryKey();
    ud = lua_newuserdata(L, LuaStructuredBuffer<DT_ULONG>::AllocSize());
    new (ud) LuaStructuredBuffer<DT_ULONG>(fmt, n);
    break;
  case DT_BYTE:
    key = LuaStructuredBuffer<DT_BYTE>::RegistryKey();
    ud = lua_newuserdata(L, LuaStructuredBuffer<DT_BYTE>::AllocSize());
    new (ud) LuaStructuredBuffer<DT_BYTE>(fmt, n);
    break;
  case DT_SHORT:
    key = LuaStructuredBuffer<DT_SHORT>::RegistryKey();
    ud = lua_newuserdata(L, LuaStructuredBuffer<DT_SHORT>::AllocSize());
    new (ud) LuaStructuredBuffer<DT_SHORT>(fmt, n);
    break;
  case DT_INT:
    key = LuaStructuredBuffer<DT_INT>::RegistryKey();
    ud = lua_newuserdata(L, LuaStructuredBuffer<DT_INT>::AllocSize());
    new (ud) LuaStructuredBuffer<DT_INT>(fmt, n);
    break;
  case DT_LONG:
    key = LuaStructuredBuffer<DT_LONG>::RegistryKey();
    ud = lua_newuserdata(L, LuaStructuredBuffer<DT_LONG>::AllocSize());
    new (ud) LuaStructuredBuffer<DT_LONG>(fmt, n);
    break;
  case DT_FLOAT:
    key = LuaStructuredBuffer<DT_FLOAT>::RegistryKey();
    ud = lua_newuserdata(L, LuaStructuredBuffer<DT_FLOAT>::AllocSize());
    new (ud) LuaStructuredBuffer<DT_FLOAT>(fmt, n);
    break;
  case DT_DOUBLE:
    key = LuaStructuredBuffer<DT_DOUBLE>::RegistryKey();
    ud = lua_newuserdata(L, LuaStructuredBuffer<DT_DOUBLE>::AllocSize());
    new (ud) LuaStructuredBuffer<DT_DOUBLE>(fmt, n);
    break;
  default:
    luaL_argerror(L, 1, "Invalid type");
  }
  
  lua_getfield(L, LUA_REGISTRYINDEX, key);
  lua_setmetatable(L, -2);
  
  return 1;
}

static int module_newbuffer(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  
  size_t in_type = lua_tointeger(L, 1);
  size_t n = lua_tointeger(L, 2);
  
  void *ud = 0;
  const char *key = 0;
  
  switch (in_type) {
  case DT_UBYTE:
    key = LuaBuffer<DT_UBYTE>::RegistryKey();
    ud = lua_newuserdata(L, LuaBuffer<DT_UBYTE>::AllocSize());
    new (ud) LuaBuffer<DT_UBYTE>(n);
    break;
  case DT_USHORT:
    key = LuaBuffer<DT_USHORT>::RegistryKey();
    ud = lua_newuserdata(L, LuaBuffer<DT_SHORT>::AllocSize());
    new (ud) LuaBuffer<DT_USHORT>(n);
    break;
  case DT_UINT:
    key = LuaBuffer<DT_UINT>::RegistryKey();
    ud = lua_newuserdata(L, LuaBuffer<DT_UINT>::AllocSize());
    new (ud) LuaBuffer<DT_UINT>(n);
    break;
  case DT_ULONG:
    key = LuaBuffer<DT_ULONG>::RegistryKey();
    ud = lua_newuserdata(L, LuaBuffer<DT_ULONG>::AllocSize());
    new (ud) LuaBuffer<DT_ULONG>(n);
    break;
  case DT_BYTE:
    key = LuaBuffer<DT_BYTE>::RegistryKey();
    ud = lua_newuserdata(L, LuaBuffer<DT_BYTE>::AllocSize());
    new (ud) LuaBuffer<DT_BYTE>(n);
    break;
  case DT_SHORT:
    key = LuaBuffer<DT_SHORT>::RegistryKey();
    ud = lua_newuserdata(L, LuaBuffer<DT_SHORT>::AllocSize());
    new (ud) LuaBuffer<DT_SHORT>(n);
    break;
  case DT_INT:
    key = LuaBuffer<DT_INT>::RegistryKey();
    ud = lua_newuserdata(L, LuaBuffer<DT_INT>::AllocSize());
    new (ud) LuaBuffer<DT_INT>(n);
    break;
  case DT_LONG:
    key = LuaBuffer<DT_LONG>::RegistryKey();
    ud = lua_newuserdata(L, LuaBuffer<DT_LONG>::AllocSize());
    new (ud) LuaBuffer<DT_LONG>(n);
    break;
  case DT_FLOAT:
    key = LuaBuffer<DT_FLOAT>::RegistryKey();
    ud = lua_newuserdata(L, LuaBuffer<DT_FLOAT>::AllocSize());
    new (ud) LuaBuffer<DT_FLOAT>(n);
    break;
  case DT_DOUBLE:
    key = LuaBuffer<DT_DOUBLE>::RegistryKey();
    ud = lua_newuserdata(L, LuaBuffer<DT_DOUBLE>::AllocSize());
    new (ud) LuaBuffer<DT_DOUBLE>(n);
    break;
  default:
    luaL_argerror(L, 1, "Invalid type");
  }
  
  lua_getfield(L, LUA_REGISTRYINDEX, key);
  lua_setmetatable(L, -2);
  
  return 1;
}

// ---

#ifdef _WIN32
extern "C" __declspec(dllexport)
#else
extern "C"
#endif
int luaopen_luaraw(lua_State *L) {
  
  int module, klass;

  lua_newtable(L);
  module = lua_gettop(L);
  
  lua_newtable(L);
  klass = lua_gettop(L);
  lua_pushvalue(L, klass);
  lua_setfield(L, klass, "__index");
  lua_pushcfunction(L, structure_del);
  lua_setfield(L, klass, "__gc");
  lua_pushcfunction(L, structure_equal);
  lua_setfield(L, klass, "__eq");
  lua_pushcfunction(L, structure_tostring);
  lua_setfield(L, klass, "__tostring");
  lua_pushcfunction(L, structure_new);
  lua_setfield(L, klass, "new");
  lua_pushcfunction(L, structure_offset);
  lua_setfield(L, klass, "offset");
  lua_pushcfunction(L, structure_fieldindex);
  lua_setfield(L, klass, "field_index");
  lua_pushcfunction(L, structure_name);
  lua_setfield(L, klass, "name");
  lua_pushcfunction(L, structure_hasfield);
  lua_setfield(L, klass, "has_field");
  lua_pushcfunction(L, structure_addfield);
  lua_setfield(L, klass, "add_field");
  lua_pushcfunction(L, structure_getfield);
  lua_setfield(L, klass, "field");
  lua_pushcfunction(L, structure_count);
  lua_setfield(L, klass, "field_count");
  lua_pushcfunction(L, structure_terminal);
  lua_setfield(L, klass, "is_terminal");
  lua_pushcfunction(L, structure_finalized);
  lua_setfield(L, klass, "is_finalized");
  lua_pushcfunction(L, structure_finalize);
  lua_setfield(L, klass, "finalize");
  lua_pushvalue(L, klass);
  lua_setfield(L, LUA_REGISTRYINDEX, LuaStructure::RegistryKey());
  lua_setfield(L, module, "Structure");
  
  lua_pushcfunction(L, raw_makestructure);
  lua_setfield(L, module, "MakeStructure");
  
  register_struct_buffer<DT_BYTE>(L, module);
  register_struct_buffer<DT_SHORT>(L, module);
  register_struct_buffer<DT_INT>(L, module);
  register_struct_buffer<DT_LONG>(L, module);
  register_struct_buffer<DT_UBYTE>(L, module);
  register_struct_buffer<DT_USHORT>(L, module);
  register_struct_buffer<DT_UINT>(L, module);
  register_struct_buffer<DT_ULONG>(L, module);
  register_struct_buffer<DT_FLOAT>(L, module);
  register_struct_buffer<DT_DOUBLE>(L, module);
  
  register_buffer<DT_BYTE>(L, module);
  register_buffer<DT_SHORT>(L, module);
  register_buffer<DT_INT>(L, module);
  register_buffer<DT_LONG>(L, module);
  register_buffer<DT_UBYTE>(L, module);
  register_buffer<DT_USHORT>(L, module);
  register_buffer<DT_UINT>(L, module);
  register_buffer<DT_ULONG>(L, module);
  register_buffer<DT_FLOAT>(L, module);
  register_buffer<DT_DOUBLE>(L, module);
  
  lua_newtable(L);
  lua_pushcfunction(L, module_newstructbuffer);
  lua_setfield(L, -2, "new");
  lua_setfield(L, module, "StructuredBuffer");
  
  lua_newtable(L);
  lua_pushcfunction(L, module_newbuffer);
  lua_setfield(L, -2, "new");
  lua_setfield(L, module, "Buffer");

  // add constants and restrict access
  lua_newtable(L);
  lua_pushcfunction(L, module_index);
  lua_setfield(L, -2, "__index");
  lua_pushcfunction(L, module_newindex);
  lua_setfield(L, -2, "__newindex");
  lua_pushvalue(L, -1);
  lua_setmetatable(L, module);

  lua_pushvalue(L, module);
  lua_setfield(L, LUA_GLOBALSINDEX, "raw");
  
  return 1;
}



