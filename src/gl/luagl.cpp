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

#include "luagl.h"

LuaGL* LuaGL::msInstance = 0;
GLenum LuaGL::ENUM_ERROR = (GLenum)-2;

extern void Register_GL_1_1_Constants(LuaGL::ConstantMap&);
extern void Register_GL_1_2_Constants(LuaGL::ConstantMap&);
extern void Register_GL_1_3_Constants(LuaGL::ConstantMap&);
extern void Register_GL_1_4_Constants(LuaGL::ConstantMap&);
extern void Register_GL_1_5_Constants(LuaGL::ConstantMap&);
extern void Register_GL_2_0_Constants(LuaGL::ConstantMap&);
extern void Register_GL_2_1_Constants(LuaGL::ConstantMap&);
extern void Register_GL_ARB_Constants(LuaGL::ConstantMap&);

extern void Register_GL_1_1_Functions(lua_State*, int);
extern void Register_GL_1_2_Functions(lua_State*, int);
extern void Register_GL_1_3_Functions(lua_State*, int);
extern void Register_GL_1_4_Functions(lua_State*, int);
extern void Register_GL_1_5_Functions(lua_State*, int);
extern void Register_GL_2_0_Functions(lua_State*, int);
extern void Register_GL_2_1_Functions(lua_State*, int);
extern void Register_GL_ARB_Functions(lua_State*, int);

LuaGL& LuaGL::Instance() {
  assert(msInstance != 0);
  return *msInstance;
}

LuaGL::LuaGL()
  : mVersion(1.1) {
  assert(msInstance == 0);
  msInstance = this;
  //initConstants();
  //initFunctions();
  //initExtensions();
}

LuaGL::~LuaGL() {
  msInstance = 0;
}

GLenum LuaGL::getConstant(const std::string &name) {
  std::map<std::string, GLenum>::iterator it = mConstants.find(name);
  if (it == mConstants.end()) {
    return ENUM_ERROR;
  } else {
    return it->second;
  }
}

void LuaGL::initConstants() {
  Register_GL_1_1_Constants(mConstants);
  Register_GL_1_2_Constants(mConstants);
  Register_GL_1_3_Constants(mConstants);
  Register_GL_1_4_Constants(mConstants);
  Register_GL_1_5_Constants(mConstants);
  Register_GL_2_0_Constants(mConstants);
  Register_GL_2_1_Constants(mConstants);
  Register_GL_ARB_Constants(mConstants);
}

//void LuaGL::initFunctions(lua_State *L, int module) {
//  Register_GL_1_1_Functions(L, module);
//}

// ---

static int luagl_gc(lua_State *L) {
  void *ud = lua_touserdata(L, 1);
  LuaGL *gl = (LuaGL*)ud;
  gl->~LuaGL();
  lua_pop(L, 1);
  return 0;
}

static int luagl_index(lua_State *L) {
  
  const char *key = lua_tostring(L, 2);
  
  LuaGL &gl = LuaGL::Instance();
  
  GLenum e = gl.getConstant(key);
  
  if (e == LuaGL::ENUM_ERROR) {
    
    if (!strcmp(key, "version")) {
      lua_pop(L, 2);
      lua_pushnumber(L, gl.getVersion());

    } else {
      lua_pushstring(L, "Invalid entry");
      lua_error(L);
    }
  } else {
    lua_pop(L, 2);
    lua_pushinteger(L, lua_Integer(e));
  }

  return 1;
}

static int luagl_newindex(lua_State *L) {
  lua_pushstring(L, "No assignable values in GL module");
  lua_error(L);
  return 0;
}

static int luagl_initialize(lua_State *L) {
  glewInit();
  
  lua_getfield(L, LUA_GLOBALSINDEX, "gl");
  lua_getmetatable(L, -1);
  int module = lua_gettop(L);

  LuaGL::Instance().initConstants();
  
  Register_GL_1_1_Functions(L, module);
  Register_GL_1_2_Functions(L, module);
  Register_GL_1_3_Functions(L, module);  
  Register_GL_1_4_Functions(L, module);
  Register_GL_1_5_Functions(L, module);
  Register_GL_2_0_Functions(L, module);
  Register_GL_2_1_Functions(L, module);
  Register_GL_ARB_Functions(L, module);

  return 0;
}

static int luagl_cleanup(lua_State *) {
  return 0;
}

EXPORT int luaopen_luagl_gl(lua_State *L) {
  
  void *ud = lua_newuserdata(L, sizeof(LuaGL));
  new (ud) LuaGL();
  int module = lua_gettop(L);
  
  lua_newtable(L);
  int metatable = lua_gettop(L);
  
  lua_pushvalue(L, metatable);
  lua_setfield(L, metatable, "__index");
  
  lua_pushcfunction(L, &luagl_newindex);
  lua_setfield(L, metatable, "__newindex");
  
  lua_pushcfunction(L, &luagl_gc);
  lua_setfield(L, metatable, "__gc");
  
  lua_pushcfunction(L, &luagl_initialize);
  lua_setfield(L, metatable, "Init");

  lua_pushcfunction(L, &luagl_cleanup);
  lua_setfield(L, metatable, "Cleanup");
  
  lua_pushvalue(L, metatable);
  lua_setfield(L, metatable, "__metatable");
  
  lua_newtable(L);
  int metametatable = lua_gettop(L);
  lua_pushcfunction(L, &luagl_index);
  lua_setfield(L, metametatable, "__index");
  lua_setmetatable(L, metatable);
  
  lua_pushvalue(L, metatable);
  lua_setmetatable(L, module);
  
  lua_pushvalue(L, module);
  lua_setfield(L, LUA_GLOBALSINDEX, "gl");

  lua_pushlightuserdata(L, LuaGL::RegistryKey());
  lua_pushvalue(L, metatable);
  lua_settable(L, LUA_REGISTRYINDEX);

  lua_pop(L, 1);

  return 1;
}

