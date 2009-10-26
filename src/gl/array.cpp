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

#include "array.h"

int CheckArraySize(lua_State *L, int arg) {
  
  int len = -1;
  
  if (lua_type(L, arg) == LUA_TTABLE) {
    
    len = (int) lua_objlen(L, arg);
  
  } else if (lua_type(L, arg) == LUA_TUSERDATA) {
    
    lua_getmetatable(L, arg);
    
    if (!lua_isnil(L, -1)) {
      
      lua_getfield(L, -1, "__len");
      
      if (!lua_isnil(L, -1)) {
        lua_pushvalue(L, arg); // push self
        lua_call(L, 1, 1);
        len = (int) lua_tointeger(L, -1);
      }
      
      lua_pop(L, 1);
    }
    
    lua_pop(L, 1);
  }
  
  if (len == -1) {
    lua_pushstring(L, "Object is not subscriptable");
    lua_error(L);
  }
  
  return len;
}
