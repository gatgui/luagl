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
#include "convert.h"
#include "wrap.h"

static int lua_glBeginQuery(lua_State *L) {
  return WrapFunc2<Enum, Uint >::Call(L, glBeginQuery);
}

static int lua_glBindBuffer(lua_State *L) {
  return WrapFunc2<Enum, Uint >::Call(L, glBindBuffer);
}

static int lua_glBufferData(lua_State *L) {
  return WrapFunc4<Enum, Sizeiptr, ConstPtr, Enum >::Call(L, glBufferData);
}

static int lua_glBufferSubData(lua_State *L) {
  return WrapFunc4<Enum, Intptr, Sizeiptr, ConstPtr >::Call(L, glBufferSubData);
}

static int lua_glDeleteBuffers(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Array1D<Uint> buffers;
  if (buffers.fromLUA(L, 1)) {
    glDeleteBuffers(buffers.size(), buffers);
  }
  return 0;
}

static int lua_glDeleteQueries(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Array1D<Uint> queries;
  if (queries.fromLUA(L, 1)) {
    glDeleteQueries(queries.size(), queries);
  }
  return 0;
}

static int lua_glEndQuery(lua_State *L) {
  return WrapFunc1<Enum >::Call(L, glEndQuery);
}

static int lua_glGenBuffers(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Sizei n(L, 1);
  Array1D<Uint> buffers(n);
  glGenBuffers(n, buffers);
  buffers.toLUA(L);
  return 1;
}

static int lua_glGenQueries(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Sizei n(L, 1);
  Array1D<Uint> queries(n);
  glGenQueries(n, queries);
  queries.toLUA(L);
  return 1;
}

static int lua_glGetBufferParameter(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum target(L, 1);
  Enum pname(L, 2);
  GLint dim = LuaGL::Instance().getParamDim(LuaGL::BufferParameteriv, pname);
  if (dim > 0) {
    Array1D<Int> values(dim);
    glGetBufferParameteriv(target, pname, values);
    if (dim == 1) {
      lua_pushinteger(L, values[0]);
    } else {
      values.toLUA(L);
    }
  }
  if (dim == 0) {
    luaL_error(L, "gl.GetBufferParameter: invalid parameter name");
  }
  return 1;
}

static int lua_glGetBufferPointer(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum target(L, 1);
  Enum pname(L, 2);
  GLvoid *ptr=0;
  glGetBufferPointerv(target, pname, &ptr);
  lua_pushlightuserdata(L, ptr);
  return 1;
}

static int lua_glGetBufferSubData(lua_State *L) {
  return WrapFunc4<Enum, Intptr, Sizeiptr, Ptr >::Call(L, glGetBufferSubData);
}

static int lua_glIsBuffer(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Uint id(L, 1);
  lua_pushboolean(L, (glIsBuffer(id) == GL_TRUE ? 1 : 0));
  return 1;
}

static int lua_glIsQuery(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Uint id(L, 1);
  lua_pushboolean(L, (glIsQuery(id) == GL_TRUE ? 1 : 0));
  return 1;
}

static int lua_glMapBuffer(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum target(L, 1);
  Enum access(L, 2);
  GLvoid *ptr = glMapBuffer(target, access);
  lua_pushlightuserdata(L, ptr);
  return 1;
}

static int lua_glUnmapBuffer(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Enum target(L, 1);
  lua_pushboolean(L, (glUnmapBuffer(target) == GL_TRUE ? 1 : 0));
  return 1;
}

static int lua_glGetQueryObject(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum target(L, 1);
  Enum pname(L, 2);
  GLint dim = LuaGL::Instance().getParamDim(LuaGL::QueryObjectiv, pname);
  if (dim <= 0) {
    dim = LuaGL::Instance().getParamDim(LuaGL::QueryObjectuiv, pname);
    if (dim > 0) {
      Array1D<Uint> values(dim);
      glGetQueryObjectuiv(target, pname, values);
      if (dim == 1) {
        lua_pushinteger(L, values[0]);
      } else {
        values.toLUA(L);
      }
    }
  } else {
    Array1D<Int> values(dim);
    glGetQueryObjectiv(target, pname, values);
    if (dim == 1) {
      lua_pushinteger(L, values[0]);
    } else {
      values.toLUA(L);
    }
  }
  if (dim == 0) {
    luaL_error(L, "gl.GetQueryObject: invalid parameter name");
  }
  return 1;
}

static int lua_glGetQuery(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum target(L, 1);
  Enum pname(L, 2);
  GLint dim = LuaGL::Instance().getParamDim(LuaGL::Queryiv, pname);
  if (dim > 0) {
    Array1D<Int> values(dim);
    glGetQueryiv(target, pname, values);
    if (dim == 1) {
      lua_pushinteger(L, values[0]);
    } else {
      values.toLUA(L);
    }
  }
  if (dim == 0) {
    luaL_error(L, "gl.GetQuery: invalid parameter name");
  }
  return 1;
}

void Register_GL_1_5_Constants(LuaGL::ConstantMap &constants) {
  if (GLEW_VERSION_1_5) {
    constants["FOG_COORD_SRC"] = GL_FOG_COORD_SRC;
    constants["FOG_COORD"] = GL_FOG_COORD;
    constants["FOG_COORD_ARRAY"] = GL_FOG_COORD_ARRAY;
    constants["SRC0_RGB"] = GL_SRC0_RGB;
    constants["FOG_COORD_ARRAY_POINTER"] = GL_FOG_COORD_ARRAY_POINTER;
    constants["FOG_COORD_ARRAY_TYPE"] = GL_FOG_COORD_ARRAY_TYPE;
    constants["SRC1_ALPHA"] = GL_SRC1_ALPHA;
    constants["CURRENT_FOG_COORD"] = GL_CURRENT_FOG_COORD;
    constants["FOG_COORD_ARRAY_STRIDE"] = GL_FOG_COORD_ARRAY_STRIDE;
    constants["SRC0_ALPHA"] = GL_SRC0_ALPHA;
    constants["SRC1_RGB"] = GL_SRC1_RGB;
    constants["FOG_COORD_ARRAY_BUFFER_BINDING"] = GL_FOG_COORD_ARRAY_BUFFER_BINDING;
    constants["SRC2_ALPHA"] = GL_SRC2_ALPHA;
    constants["SRC2_RGB"] = GL_SRC2_RGB;
    constants["BUFFER_SIZE"] = GL_BUFFER_SIZE;
    constants["BUFFER_USAGE"] = GL_BUFFER_USAGE;
    constants["QUERY_COUNTER_BITS"] = GL_QUERY_COUNTER_BITS;
    constants["CURRENT_QUERY"] = GL_CURRENT_QUERY;
    constants["QUERY_RESULT"] = GL_QUERY_RESULT;
    constants["QUERY_RESULT_AVAILABLE"] = GL_QUERY_RESULT_AVAILABLE;
    constants["ARRAY_BUFFER"] = GL_ARRAY_BUFFER;
    constants["ELEMENT_ARRAY_BUFFER"] = GL_ELEMENT_ARRAY_BUFFER;
    constants["ARRAY_BUFFER_BINDING"] = GL_ARRAY_BUFFER_BINDING;
    constants["ELEMENT_ARRAY_BUFFER_BINDING"] = GL_ELEMENT_ARRAY_BUFFER_BINDING;
    constants["VERTEX_ARRAY_BUFFER_BINDING"] = GL_VERTEX_ARRAY_BUFFER_BINDING;
    constants["NORMAL_ARRAY_BUFFER_BINDING"] = GL_NORMAL_ARRAY_BUFFER_BINDING;
    constants["COLOR_ARRAY_BUFFER_BINDING"] = GL_COLOR_ARRAY_BUFFER_BINDING;
    constants["INDEX_ARRAY_BUFFER_BINDING"] = GL_INDEX_ARRAY_BUFFER_BINDING;
    constants["TEXTURE_COORD_ARRAY_BUFFER_BINDING"] = GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING;
    constants["EDGE_FLAG_ARRAY_BUFFER_BINDING"] = GL_EDGE_FLAG_ARRAY_BUFFER_BINDING;
    constants["SECONDARY_COLOR_ARRAY_BUFFER_BINDING"] = GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING;
    constants["FOG_COORDINATE_ARRAY_BUFFER_BINDING"] = GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING;
    constants["WEIGHT_ARRAY_BUFFER_BINDING"] = GL_WEIGHT_ARRAY_BUFFER_BINDING;
    constants["VERTEX_ATTRIB_ARRAY_BUFFER_BINDING"] = GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING;
    constants["READ_ONLY"] = GL_READ_ONLY;
    constants["WRITE_ONLY"] = GL_WRITE_ONLY;
    constants["READ_WRITE"] = GL_READ_WRITE;
    constants["BUFFER_ACCESS"] = GL_BUFFER_ACCESS;
    constants["BUFFER_MAPPED"] = GL_BUFFER_MAPPED;
    constants["BUFFER_MAP_POINTER"] = GL_BUFFER_MAP_POINTER;
    constants["STREAM_DRAW"] = GL_STREAM_DRAW;
    constants["STREAM_READ"] = GL_STREAM_READ;
    constants["STREAM_COPY"] = GL_STREAM_COPY;
    constants["STATIC_DRAW"] = GL_STATIC_DRAW;
    constants["STATIC_READ"] = GL_STATIC_READ;
    constants["STATIC_COPY"] = GL_STATIC_COPY;
    constants["DYNAMIC_DRAW"] = GL_DYNAMIC_DRAW;
    constants["DYNAMIC_READ"] = GL_DYNAMIC_READ;
    constants["DYNAMIC_COPY"] = GL_DYNAMIC_COPY;
    constants["SAMPLES_PASSED"] = GL_SAMPLES_PASSED;
    
    LuaGL &gl = LuaGL::Instance();
    // GL_ARB_vertex_buffer_object
    gl.addParamDim(LuaGL::Integerv, GL_ARRAY_BUFFER_BINDING, 1);
    gl.addParamDim(LuaGL::Integerv, GL_VERTEX_ARRAY_BUFFER_BINDING, 1);
    gl.addParamDim(LuaGL::Integerv, GL_NORMAL_ARRAY_BUFFER_BINDING, 1);
    gl.addParamDim(LuaGL::Integerv, GL_COLOR_ARRAY_BUFFER_BINDING, 1);
    gl.addParamDim(LuaGL::Integerv, GL_INDEX_ARRAY_BUFFER_BINDING, 1);
    gl.addParamDim(LuaGL::Integerv, GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING, 1);
    gl.addParamDim(LuaGL::Integerv, GL_EDGE_FLAG_ARRAY_BUFFER_BINDING, 1);
    gl.addParamDim(LuaGL::Integerv, GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING, 1);
    gl.addParamDim(LuaGL::Integerv, GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING, 1);
    gl.addParamDim(LuaGL::Integerv, GL_WEIGHT_ARRAY_BUFFER_BINDING, 1);
    gl.addParamDim(LuaGL::Integerv, GL_ELEMENT_ARRAY_BUFFER_BINDING, 1);
    gl.addParamDim(LuaGL::BufferParameteriv, GL_BUFFER_SIZE, 1);
    gl.addParamDim(LuaGL::BufferParameteriv, GL_BUFFER_USAGE, 1);
    gl.addParamDim(LuaGL::BufferParameteriv, GL_BUFFER_ACCESS, 1);
    gl.addParamDim(LuaGL::BufferParameteriv, GL_BUFFER_MAPPED, 1);
    // GL_ARB_occlusion_query
    gl.addParamDim(LuaGL::Queryiv, GL_CURRENT_QUERY, 1);
    gl.addParamDim(LuaGL::Queryiv, GL_QUERY_COUNTER_BITS, 1);
    gl.addParamDim(LuaGL::QueryObjectuiv, GL_QUERY_RESULT, 1);
    gl.addParamDim(LuaGL::QueryObjectiv, GL_QUERY_RESULT_AVAILABLE, 1);
    // GL_EXT_shadow_funcs
    gl.addParamDim(LuaGL::TexParameteriv, GL_TEXTURE_COMPARE_FUNC, 1);
  }
}

void Register_GL_1_5_Functions(lua_State *L, int module) {
  if (GLEW_VERSION_1_5) {
#ifdef _DEBUG
    std::cout << "Supports OpenGL 1.5" << std::endl;
#endif
    LuaGL::Instance().setVersion(1.5);
    REGISTER_GL_FUNC(L, module, BeginQuery);
    REGISTER_GL_FUNC(L, module, BindBuffer);
    REGISTER_GL_FUNC(L, module, BufferData);
    REGISTER_GL_FUNC(L, module, BufferSubData);
    REGISTER_GL_FUNC(L, module, DeleteBuffers);
    REGISTER_GL_FUNC(L, module, DeleteQueries);
    REGISTER_GL_FUNC(L, module, EndQuery);
    REGISTER_GL_FUNC(L, module, GenBuffers);
    REGISTER_GL_FUNC(L, module, GenQueries);
    REGISTER_GL_FUNC(L, module, GetBufferParameter);
    REGISTER_GL_FUNC(L, module, GetBufferPointer);
    REGISTER_GL_FUNC(L, module, GetBufferSubData);
    REGISTER_GL_FUNC(L, module, IsBuffer);
    REGISTER_GL_FUNC(L, module, IsQuery);
    REGISTER_GL_FUNC(L, module, MapBuffer);
    REGISTER_GL_FUNC(L, module, UnmapBuffer);
    REGISTER_GL_FUNC(L, module, GetQueryObject);
    REGISTER_GL_FUNC(L, module, GetQuery);
  }
}

