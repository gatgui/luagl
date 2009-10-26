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

#include <lua.hpp>

#ifdef _WIN32
# define EXPORT extern "C" __declspec(dllexport)
#else
# define EXPORT extern "C"
#endif

int lua_bitor(lua_State *L) {
  int narg = lua_gettop(L);
  if (narg < 1) {
    lua_pushstring(L, "bitop.btor need at least two arguments");
    lua_error(L);
  }
  unsigned long r = (unsigned long) lua_tointeger(L, 1);
  for (int i=1; i<narg; ++i) {
    r = r | ((unsigned long) lua_tointeger(L, i+1));
  }
  lua_pushnumber(L, r);
  return 1;
}

int lua_bitand(lua_State *L) {
  int narg = lua_gettop(L);
  if (narg < 1) {
    lua_pushstring(L, "bitop.band need at least two arguments");
    lua_error(L);
  }
  unsigned long r = (unsigned long) lua_tointeger(L, 1);
  for (int i=1; i<narg; ++i) {
    r = r & ((unsigned long) lua_tointeger(L, i+1));
  }
  lua_pushnumber(L, r);
  return 1;
}

int lua_bitxor(lua_State *L) {
  int narg = lua_gettop(L);
  if (narg != 2) {
    lua_pushstring(L, "bitop.bxor requires two arguments");
    lua_error(L);
  }
  unsigned long r = ((unsigned long) lua_tointeger(L, 1)) ^ ((unsigned long) lua_tointeger(L, 2));
  lua_pushnumber(L, r);
  return 1;
}

int lua_bitnot(lua_State *L) {
  int narg = lua_gettop(L);
  if (narg != 1) {
    lua_pushstring(L, "bitop.bnot takes a single argument");
    lua_error(L);
  }
  unsigned long r = ~((unsigned long) lua_tointeger(L, 1));
  lua_pushnumber(L, r);
  return 1;
}

int lua_bitrshift(lua_State *L) {
  int narg = lua_gettop(L);
  if (narg != 2) {
    lua_pushstring(L, "bitop.brshift takes two arguments");
    lua_error(L);
  }
  unsigned long r = ((unsigned long) lua_tointeger(L, 1)) >> ((unsigned long) lua_tointeger(L, 2));
  lua_pushnumber(L, r);
  return 1;
}

int lua_bitlshift(lua_State *L) {
  int narg = lua_gettop(L);
  if (narg != 2) {
    lua_pushstring(L, "bitop.blshift takes two arguments");
    lua_error(L);
  }
  unsigned long r = ((unsigned long) lua_tointeger(L, 1)) << ((unsigned long) lua_tointeger(L, 2));
  lua_pushnumber(L, r);
  return 1;
}


EXPORT int luaopen_luabitop(lua_State *L) {
  lua_newtable(L);
  lua_pushcfunction(L, &lua_bitor);
  lua_setfield(L, -2, "Or");
  lua_pushcfunction(L, &lua_bitand);
  lua_setfield(L, -2, "And");
  lua_pushcfunction(L, &lua_bitxor);
  lua_setfield(L, -2, "Xor");
  lua_pushcfunction(L, &lua_bitnot);
  lua_setfield(L, -2, "Not");
  lua_pushcfunction(L, &lua_bitrshift);
  lua_setfield(L, -2, "Rshift");
  lua_pushcfunction(L, &lua_bitlshift);
  lua_setfield(L, -2, "Lshift");
  lua_pushvalue(L, -1); // duplicate table on top
  lua_setfield(L, LUA_GLOBALSINDEX, "bitop");
  return 1;
}
