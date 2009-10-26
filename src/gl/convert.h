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

#ifndef __convert_h_
#define __convert_h_

#include "common.h"
#include "array.h"

// use
// luaL_checkstring, luaL_checkint, luaL_checkinteger, luaL_checklong,
// luaL_checknumber, luaL_checkudata

template <typename Ctype, typename LUAtype,
          LUAtype (*from)(lua_State*, int),
          void (*to)(lua_State*, LUAtype)>
struct TypeWrapper {
  typedef Ctype T;
  inline TypeWrapper() {}
  inline TypeWrapper(T v) : value(v) {}
  inline TypeWrapper(lua_State *L, int arg) {fromLUA(L, arg);}
  inline ~TypeWrapper() {}
  inline void fromLUA(lua_State *L, int arg) {
    value = (T)(from(L, arg));
  }
  inline void toLUA(lua_State *L) {
    to(L, (LUAtype)value);
  }
  inline operator T () const {
    return value;
  }
  T value;
};


typedef TypeWrapper<GLbitfield, lua_Integer, lua_tointeger, lua_pushinteger> Bitfield;
//typedef TypeWrapper<GLboolean, lua_Integer, lua_tointeger, lua_pushinteger> Boolean;
typedef TypeWrapper<GLenum, lua_Integer, lua_tointeger, lua_pushinteger> Enum;
typedef TypeWrapper<GLsizei, lua_Integer, lua_tointeger, lua_pushinteger> Sizei;
typedef TypeWrapper<GLbyte, lua_Integer, lua_tointeger, lua_pushinteger> Byte;
typedef TypeWrapper<GLubyte, lua_Integer, lua_tointeger, lua_pushinteger> Ubyte;
typedef TypeWrapper<GLshort, lua_Integer, lua_tointeger, lua_pushinteger> Short;
typedef TypeWrapper<GLushort, lua_Integer, lua_tointeger, lua_pushinteger> Ushort;
typedef TypeWrapper<GLint, lua_Integer, lua_tointeger, lua_pushinteger> Int;
typedef TypeWrapper<GLuint, lua_Integer, lua_tointeger, lua_pushinteger> Uint;
typedef TypeWrapper<GLfloat, lua_Number, lua_tonumber, lua_pushnumber> Float;
typedef TypeWrapper<GLclampf, lua_Number, lua_tonumber, lua_pushnumber> Clampf;
typedef TypeWrapper<GLdouble, lua_Number, lua_tonumber, lua_pushnumber> Double;
typedef TypeWrapper<GLclampd, lua_Number, lua_tonumber, lua_pushnumber> Clampd;
typedef TypeWrapper<void*, void*, lua_touserdata, lua_pushlightuserdata> Ptr;
typedef TypeWrapper<const void*, void*, lua_touserdata, lua_pushlightuserdata> ConstPtr;
typedef TypeWrapper<int, lua_Integer, lua_tointeger, lua_pushinteger> CInt;
typedef TypeWrapper<long, lua_Integer, lua_tointeger, lua_pushinteger> CLong;
typedef TypeWrapper<unsigned int, lua_Integer, lua_tointeger, lua_pushinteger> CUint;
typedef TypeWrapper<unsigned long, lua_Integer, lua_tointeger, lua_pushinteger> CUlong;
// For some reasons... this fails
//typedef TypeWrapper<const char*, const char*, lua_tostring, lua_pushstring> String;
typedef TypeWrapper<GLsizeiptr, lua_Integer, lua_tointeger, lua_pushinteger> Sizeiptr;
typedef TypeWrapper<GLintptr, lua_Integer, lua_tointeger, lua_pushinteger> Intptr;
typedef TypeWrapper<GLchar, lua_Integer, lua_tointeger, lua_pushinteger> Char;
typedef TypeWrapper<GLhandleARB, lua_Integer, lua_tointeger, lua_pushinteger> Handle;

struct Boolean {
  typedef GLboolean T;
  inline Boolean() {}
  inline Boolean(T v) : value(v) {}
  inline Boolean(lua_State *L, int arg) {fromLUA(L, arg);}
  inline ~Boolean() {}
  inline void fromLUA(lua_State *L, int arg) {
    value = (lua_toboolean(L, arg) == 1 ? GL_TRUE : GL_FALSE);
  }
  inline void toLUA(lua_State *L) {
    lua_toboolean(L, (value == GL_TRUE ? 1 : 0));
  }
  inline operator T () const {
    return value;
  }
  GLboolean value;
};

struct String {
  typedef const char* T;
  inline String() {}
  inline String(T v) : value(v) {}
  inline String(lua_State *L, int arg) {fromLUA(L, arg);}
  inline ~String() {}
  inline void fromLUA(lua_State *L, int arg) {
    value = lua_tostring(L, arg);
  }
  inline void toLUA(lua_State *L) {
    lua_pushstring(L, value);
  }
  inline operator T () const {
    return value;
  }
  const char* value;
};

template <typename U>
struct TypedPtr {
  typedef typename U::T* T;
  inline TypedPtr() {}
  inline TypedPtr(T v) : value(v) {}
  inline TypedPtr(lua_State *L, int arg) {fromLUA(L, arg);}
  inline ~TypedPtr() {}
  inline void fromLUA(lua_State *L, int arg) {
    value = (T)(lua_touserdata(L, arg));
  }
  inline void toLUA(lua_State *L) {
    lua_pushlightuserdata(L, (void*)value);
  }
  inline operator T () const {
    return value;
  }
  T value;
};

template <typename U>
struct ConstTypedPtr {
  typedef const typename U::T* T;
  inline ConstTypedPtr() {}
  inline ConstTypedPtr(T v) : value(v) {}
  inline ConstTypedPtr(lua_State *L, int arg) {fromLUA(L, arg);}
  inline ~ConstTypedPtr() {}
  inline void fromLUA(lua_State *L, int arg) {
    value = (T)(lua_touserdata(L, arg));
  }
  inline void toLUA(lua_State *L) {
    lua_pushlightuserdata(L, (void*)value);
  }
  inline operator T () const {
    return value;
  }
  T value;
};

template <typename U>
struct Array {
  typedef typename U::T* T;
  inline Array() {}
  inline Array(lua_State *L, int arg) {fromLUA(L, arg);}
  inline ~Array() {}
  inline void fromLUA(lua_State *L, int arg) {
    value.fromLUA(L, arg);
  }
  inline void toLUA(lua_State *L) {
    value.toLUA(L);
  }
  inline operator T () {
    return value;
  }
  Array1D<U> value;
};

template <typename U>
struct ConstArray {
  typedef const typename U::T* T;
  inline ConstArray() {}
  inline ConstArray(lua_State *L, int arg) {fromLUA(L, arg);}
  inline ~ConstArray() {}
  inline void fromLUA(lua_State *L, int arg) {
    value.fromLUA(L, arg);
  }
  inline void toLUA(lua_State *L) {
    value.toLUA(L);
  }
  inline operator T () const {
    return value;
  }
  Array1D<U> value;
};

#endif
