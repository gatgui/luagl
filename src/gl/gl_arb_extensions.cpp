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

// GL_ARB_color_buffer_float

static int lua_glClampColorARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Enum, glClampColorARB>::Call(L);
#else
  return WrapFunc2<Enum, Enum >::Call(L, glClampColorARB);
#endif
}

// GL_ARB_draw_buffers

static int lua_glDrawBuffersARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Array1D<Enum> buffers(L, 1);
  glDrawBuffersARB(buffers.size(), buffers);
  return 0;
}

// GL_ARB_matrix_palette

static int lua_glCurrentPaletteMatrixARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Int, glCurrentPaletteMatrixARB>::Call(L);
#else
  return WrapFunc1<Int >::Call(L, glCurrentPaletteMatrixARB);
#endif
}
static int lua_glMatrixIndexPointerARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Enum, Sizei, Ptr, glMatrixIndexPointerARB>::Call(L);
#else
  return WrapFunc4<Int, Enum, Sizei, Ptr >::Call(L, glMatrixIndexPointerARB);
#endif
}
static int lua_glMatrixIndexubvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Int, Array<Ubyte>, glMatrixIndexubvARB>::Call(L);
#else
  return WrapFunc2<Int, Array<Ubyte> >::Call(L, glMatrixIndexubvARB);
#endif
}
static int lua_glMatrixIndexusvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Int, Array<Ushort>, glMatrixIndexusvARB>::Call(L);
#else
  return WrapFunc2<Int, Array<Ushort> >::Call(L, glMatrixIndexusvARB);
#endif
}
static int lua_glMatrixIndexuivARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Int, Array<Uint>, glMatrixIndexuivARB>::Call(L);
#else
  return WrapFunc2<Int, Array<Uint> >::Call(L, glMatrixIndexuivARB);
#endif
}

// GL_ARB_multisample

static int lua_glSampleCoverageARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Clampf, Boolean, glSampleCoverageARB>::Call(L);
#else
  return WrapFunc2<Clampf, Boolean >::Call(L, glSampleCoverageARB);
#endif
}

// GL_ARB_multitexture

static int lua_glActiveTextureARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Enum, glActiveTextureARB>::Call(L);
#else
  return WrapFunc1<Enum >::Call(L, glActiveTextureARB);
#endif
}

static int lua_glClientActiveTextureARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Enum, glClientActiveTextureARB>::Call(L);
#else
  return WrapFunc1<Enum >::Call(L, glClientActiveTextureARB);
#endif
}

static int lua_glMultiTexCoord1dARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Double, glMultiTexCoord1dARB>::Call(L);
#else
  return WrapFunc2<Enum, Double >::Call(L, glMultiTexCoord1dARB);
#endif
}
static int lua_glMultiTexCoord1fARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Float, glMultiTexCoord1fARB>::Call(L);
#else
  return WrapFunc2<Enum, Float >::Call(L, glMultiTexCoord1fARB);
#endif
}
static int lua_glMultiTexCoord1sARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Short, glMultiTexCoord1sARB>::Call(L);
#else
  return WrapFunc2<Enum, Short >::Call(L, glMultiTexCoord1sARB);
#endif
}
static int lua_glMultiTexCoord1iARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Int, glMultiTexCoord1iARB>::Call(L);
#else
  return WrapFunc2<Enum, Int >::Call(L, glMultiTexCoord1iARB);
#endif
}

static int lua_glMultiTexCoord2dARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Double, Double, glMultiTexCoord2dARB>::Call(L);
#else
  return WrapFunc3<Enum, Double, Double >::Call(L, glMultiTexCoord2dARB);
#endif
}
static int lua_glMultiTexCoord2fARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Float, Float, glMultiTexCoord2fARB>::Call(L);
#else
  return WrapFunc3<Enum, Float, Float >::Call(L, glMultiTexCoord2fARB);
#endif
}
static int lua_glMultiTexCoord2sARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Short, Short, glMultiTexCoord2sARB>::Call(L);
#else
  return WrapFunc3<Enum, Short, Short >::Call(L, glMultiTexCoord2sARB);
#endif
}
static int lua_glMultiTexCoord2iARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Int, Int, glMultiTexCoord2iARB>::Call(L);
#else
  return WrapFunc3<Enum, Int, Int >::Call(L, glMultiTexCoord2iARB);
#endif
}
static int lua_glMultiTexCoord2dvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, ConstArray<Double>, glMultiTexCoord2dvARB>::Call(L);
#else
  return WrapFunc2<Enum, ConstArray<Double> >::Call(L, glMultiTexCoord2dvARB);
#endif
}
static int lua_glMultiTexCoord2fvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, ConstArray<Float>, glMultiTexCoord2fvARB>::Call(L);
#else
  return WrapFunc2<Enum, ConstArray<Float> >::Call(L, glMultiTexCoord2fvARB);
#endif
}
static int lua_glMultiTexCoord2svARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, ConstArray<Short>, glMultiTexCoord2svARB>::Call(L);
#else
  return WrapFunc2<Enum, ConstArray<Short> >::Call(L, glMultiTexCoord2svARB);
#endif
}
static int lua_glMultiTexCoord2ivARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, ConstArray<Int>, glMultiTexCoord2ivARB>::Call(L);
#else
  return WrapFunc2<Enum, ConstArray<Int> >::Call(L, glMultiTexCoord2ivARB);
#endif
}

static int lua_glMultiTexCoord3dARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Enum, Double, Double, Double, glMultiTexCoord3dARB>::Call(L);
#else
  return WrapFunc4<Enum, Double, Double, Double >::Call(L, glMultiTexCoord3dARB);
#endif
}
static int lua_glMultiTexCoord3fARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Enum, Float, Float, Float, glMultiTexCoord3fARB>::Call(L);
#else
  return WrapFunc4<Enum, Float, Float, Float >::Call(L, glMultiTexCoord3fARB);
#endif
}
static int lua_glMultiTexCoord3sARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Enum, Short, Short, Short, glMultiTexCoord3sARB>::Call(L);
#else
  return WrapFunc4<Enum, Short, Short, Short >::Call(L, glMultiTexCoord3sARB);
#endif
}
static int lua_glMultiTexCoord3iARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Enum, Int, Int, Int, glMultiTexCoord3iARB>::Call(L);
#else
  return WrapFunc4<Enum, Int, Int, Int >::Call(L, glMultiTexCoord3iARB);
#endif
}
static int lua_glMultiTexCoord3dvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, ConstArray<Double>, glMultiTexCoord3dvARB>::Call(L);
#else
  return WrapFunc2<Enum, ConstArray<Double> >::Call(L, glMultiTexCoord3dvARB);
#endif
}
static int lua_glMultiTexCoord3fvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, ConstArray<Float>, glMultiTexCoord3fvARB>::Call(L);
#else
  return WrapFunc2<Enum, ConstArray<Float> >::Call(L, glMultiTexCoord3fvARB);
#endif
}
static int lua_glMultiTexCoord3svARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, ConstArray<Short>, glMultiTexCoord3svARB>::Call(L);
#else
  return WrapFunc2<Enum, ConstArray<Short> >::Call(L, glMultiTexCoord3svARB);
#endif
}
static int lua_glMultiTexCoord3ivARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, ConstArray<Int>, glMultiTexCoord3ivARB>::Call(L);
#else
  return WrapFunc2<Enum, ConstArray<Int> >::Call(L, glMultiTexCoord3ivARB);
#endif
}

static int lua_glMultiTexCoord4dARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Enum, Double, Double, Double, Double, glMultiTexCoord4dARB>::Call(L);
#else
  return WrapFunc5<Enum, Double, Double, Double, Double >::Call(L, glMultiTexCoord4dARB);
#endif
}
static int lua_glMultiTexCoord4fARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Enum, Float, Float, Float, Float, glMultiTexCoord4fARB>::Call(L);
#else
  return WrapFunc5<Enum, Float, Float, Float, Float >::Call(L, glMultiTexCoord4fARB);
#endif
}
static int lua_glMultiTexCoord4sARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Enum, Short, Short, Short, Short, glMultiTexCoord4sARB>::Call(L);
#else
  return WrapFunc5<Enum, Short, Short, Short, Short >::Call(L, glMultiTexCoord4sARB);
#endif
}
static int lua_glMultiTexCoord4iARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Enum, Int, Int, Int, Int, glMultiTexCoord4iARB>::Call(L);
#else
  return WrapFunc5<Enum, Int, Int, Int, Int >::Call(L, glMultiTexCoord4iARB);
#endif
}
static int lua_glMultiTexCoord4dvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, ConstArray<Double>, glMultiTexCoord4dvARB>::Call(L);
#else
  return WrapFunc2<Enum, ConstArray<Double> >::Call(L, glMultiTexCoord4dvARB);
#endif
}
static int lua_glMultiTexCoord4fvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, ConstArray<Float>, glMultiTexCoord4fvARB>::Call(L);
#else
  return WrapFunc2<Enum, ConstArray<Float> >::Call(L, glMultiTexCoord4fvARB);
#endif
}
static int lua_glMultiTexCoord4svARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, ConstArray<Short>, glMultiTexCoord4svARB>::Call(L);
#else
  return WrapFunc2<Enum, ConstArray<Short> >::Call(L, glMultiTexCoord4svARB);
#endif
}
static int lua_glMultiTexCoord4ivARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, ConstArray<Int>, glMultiTexCoord4ivARB>::Call(L);
#else
  return WrapFunc2<Enum, ConstArray<Int> >::Call(L, glMultiTexCoord4ivARB);
#endif
}

// GL_ARB_occlusion_query

static int lua_glBeginQueryARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Uint, glBeginQueryARB>::Call(L);
#else
  return WrapFunc2<Enum, Uint >::Call(L, glBeginQueryARB);
#endif
}
static int lua_glDeleteQueriesARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Array1D<Uint> ids(L, 1);
  glDeleteQueriesARB(ids.size(), ids);
  return 0;
}
static int lua_glEndQueryARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Enum, glEndQueryARB>::Call(L);
#else
  return WrapFunc1<Enum >::Call(L, glEndQueryARB);
#endif
}
static int lua_glGenQueriesARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Sizei n(L, 1);
  Array1D<Uint> ids(n);
  glGenQueriesARB(n, ids);
  ids.toLUA(L);
  return 1;
}
static int lua_glGetQueryObjectARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Uint id(L, 1);
  Enum pname(L, 2);
  switch (pname) {
    case GL_QUERY_RESULT_ARB: {
      GLuint value;
      glGetQueryObjectuivARB(id, pname, &value);
      lua_pushinteger(L, value);
      break;
    }
    case GL_QUERY_RESULT_AVAILABLE_ARB: {
      GLint value;
      glGetQueryObjectivARB(id, pname, &value);
      lua_pushinteger(L, value);
      break;
    }
    default:
      luaL_error(L, "gl.GetQueryObjectARB: invalid parameter name");
  }
  return 1;
}
static int lua_glGetQueryARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum target(L, 1);
  Enum pname(L, 2);
  GLint value;
  switch (pname) {
    case GL_CURRENT_QUERY_ARB:
    case GL_QUERY_COUNTER_BITS_ARB:
      glGetQueryivARB(target, pname, &value);
      lua_pushinteger(L, value);
      break;
    default:
      luaL_error(L, "gl.GetQueryARB: invalid parameter name");
  }
  return 1;
}
static int lua_glIsQueryARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Uint id(L, 1);
  lua_pushboolean(L, (glIsQueryARB(id) == GL_TRUE ? 1 : 0));
  return 1;
}

// GL_ARB_point_parameters

static int lua_glPointParameterfARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Float, glPointParameterfARB>::Call(L);
#else
  return WrapFunc2<Enum, Float >::Call(L, glPointParameterfARB);
#endif
}
static int lua_glPointParameterfvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Array<Float>, glPointParameterfvARB>::Call(L);
#else
  return WrapFunc2<Enum, Array<Float> >::Call(L, glPointParameterfvARB);
#endif
}

// GL_ARB_shader_objects

static int lua_glAttachObjectARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Handle, Handle, glAttachObjectARB>::Call(L);
#else
  return WrapFunc2<Handle, Handle >::Call(L, glAttachObjectARB);
#endif
}
static int lua_glCompileShaderARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Handle, glCompileShaderARB>::Call(L);
#else
  return WrapFunc1<Handle >::Call(L, glCompileShaderARB);
#endif
}
static int lua_glCreateProgramObjectARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 0);
  GLhandleARB handle = glCreateProgramObjectARB();
  lua_pushinteger(L, handle);
  return 1;
}
static int lua_glCreateShaderObjectARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Enum type(L, 1);
  GLhandleARB handle = glCreateShaderObjectARB(type);
  lua_pushinteger(L, handle);
  return 1;
}
static int lua_glDeleteObjectARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Handle, glDeleteObjectARB>::Call(L);
#else
  return WrapFunc1<Handle >::Call(L, glDeleteObjectARB);
#endif
}
static int lua_glDetachObjectARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Handle, Handle, glDetachObjectARB>::Call(L);
#else
  return WrapFunc2<Handle, Handle >::Call(L, glDetachObjectARB);
#endif
}
static int lua_glUseProgramObjectARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Handle, glUseProgramObjectARB>::Call(L);
#else
  return WrapFunc1<Handle >::Call(L, glUseProgramObjectARB);
#endif
}
static int lua_glValidateProgramARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Handle, glValidateProgramARB>::Call(L);
#else
  return WrapFunc1<Handle >::Call(L, glValidateProgramARB);
#endif
}
static int lua_glLinkProgramARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Handle, glLinkProgramARB>::Call(L);
#else
  return WrapFunc1<Handle >::Call(L, glLinkProgramARB);
#endif
}
static int lua_glUniform1fARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Int, Float, glUniform1fARB>::Call(L);
#else
  return WrapFunc2<Int, Float >::Call(L, glUniform1fARB);
#endif
}
static int lua_glUniform1iARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Int, Int, glUniform1iARB>::Call(L);
#else
  return WrapFunc2<Int, Int >::Call(L, glUniform1iARB);
#endif
}
static int lua_glUniform2fARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Float, Float, glUniform2fARB>::Call(L);
#else
  return WrapFunc3<Int, Float, Float >::Call(L, glUniform2fARB);
#endif
}
static int lua_glUniform2iARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Int, Int, glUniform2iARB>::Call(L);
#else
  return WrapFunc3<Int, Int, Int >::Call(L, glUniform2iARB);
#endif
}
static int lua_glUniform3fARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Float, Float, Float, glUniform3fARB>::Call(L);
#else
  return WrapFunc4<Int, Float, Float, Float >::Call(L, glUniform3fARB);
#endif
}
static int lua_glUniform3iARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Int, Int, Int, glUniform3iARB>::Call(L);
#else
  return WrapFunc4<Int, Int, Int, Int >::Call(L, glUniform3iARB);
#endif
}
static int lua_glUniform4fARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Int, Float, Float, Float, Float, glUniform4fARB>::Call(L);
#else
  return WrapFunc5<Int, Float, Float, Float, Float >::Call(L, glUniform4fARB);
#endif
}
static int lua_glUniform4iARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Int, Int, Int, Int, Int, glUniform4iARB>::Call(L);
#else
  return WrapFunc5<Int, Int, Int, Int, Int >::Call(L, glUniform4iARB);
#endif
}
static int lua_glUniform1fvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Sizei, ConstArray<Float>, glUniform1fvARB>::Call(L);
#else
  return WrapFunc3<Int, Sizei, ConstArray<Float> >::Call(L, glUniform1fvARB);
#endif
}
static int lua_glUniform1ivARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Sizei, ConstArray<Int>, glUniform1ivARB>::Call(L);
#else
  return WrapFunc3<Int, Sizei, ConstArray<Int> >::Call(L, glUniform1ivARB);
#endif
}
static int lua_glUniform2fvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Sizei, ConstArray<Float>, glUniform2fvARB>::Call(L);
#else
  return WrapFunc3<Int, Sizei, ConstArray<Float> >::Call(L, glUniform2fvARB);
#endif
}
static int lua_glUniform2ivARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Sizei, ConstArray<Int>, glUniform2ivARB>::Call(L);
#else
  return WrapFunc3<Int, Sizei, ConstArray<Int> >::Call(L, glUniform2ivARB);
#endif
}
static int lua_glUniform3fvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Sizei, ConstArray<Float>, glUniform3fvARB>::Call(L);
#else
  return WrapFunc3<Int, Sizei, ConstArray<Float> >::Call(L, glUniform3fvARB);
#endif
}
static int lua_glUniform3ivARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Sizei, ConstArray<Int>, glUniform3ivARB>::Call(L);
#else
  return WrapFunc3<Int, Sizei, ConstArray<Int> >::Call(L, glUniform3ivARB);
#endif
}
static int lua_glUniform4fvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Sizei, ConstArray<Float>, glUniform4fvARB>::Call(L);
#else
  return WrapFunc3<Int, Sizei, ConstArray<Float> >::Call(L, glUniform4fvARB);
#endif
}
static int lua_glUniform4ivARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Sizei, ConstArray<Int>, glUniform4ivARB>::Call(L);
#else
  return WrapFunc3<Int, Sizei, ConstArray<Int> >::Call(L, glUniform4ivARB);
#endif
}
static int lua_glUniformMatrix2fvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float>, glUniformMatrix2fvARB>::Call(L);
#else
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(L, glUniformMatrix2fvARB);
#endif
}
static int lua_glUniformMatrix3fvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float>, glUniformMatrix3fvARB>::Call(L);
#else
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(L, glUniformMatrix3fvARB);
#endif
}
static int lua_glUniformMatrix4fvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float>, glUniformMatrix4fvARB>::Call(L);
#else
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(L, glUniformMatrix4fvARB);
#endif
}
static int lua_glGetHandleARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Enum pname(L, 1);
  GLhandleARB handle = glGetHandleARB(pname);
  lua_pushinteger(L, handle);
  return 1;
}
static int lua_glGetUniformLocationARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Handle prog(L, 1);
  String name(L, 2);
  GLint loc = glGetUniformLocationARB(prog, name);
  lua_pushinteger(L, loc);
  return 1;
}
static int lua_glShaderSourceARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Handle obj(L, 1);
  Array1D<String> string(L, 2);
  glShaderSourceARB(obj, string.size(), string, 0);
  return 0;
}
static int lua_glGetUniformARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Handle prog(L, 1);
  Int loc(L, 2);
  GLchar dummy;
  GLint count;
  GLenum type;
  glGetActiveUniformARB(prog, loc, 0, 0, &count, &type, &dummy);
  bool integer = false;
  int dim = 0;
  switch (type) {
    case GL_INT:
    case GL_BOOL_ARB:
    case GL_SAMPLER_1D_ARB:
    case GL_SAMPLER_2D_ARB:
    case GL_SAMPLER_3D_ARB:
    case GL_SAMPLER_CUBE_ARB:
    case GL_SAMPLER_1D_SHADOW_ARB:
    case GL_SAMPLER_2D_SHADOW_ARB:
    case GL_SAMPLER_2D_RECT_ARB:
    case GL_SAMPLER_2D_RECT_SHADOW_ARB:
      integer = true;
      dim = 1;
      break;
    case GL_INT_VEC2_ARB:
    case GL_BOOL_VEC2_ARB:
      integer = true;
      dim = 2;
      break;
    case GL_INT_VEC3_ARB:
    case GL_BOOL_VEC3_ARB:
      integer = true;
      dim = 3;
      break;
    case GL_INT_VEC4_ARB:
    case GL_BOOL_VEC4_ARB:
      integer = true;
      dim = 4;
      break;
    case GL_FLOAT:
      dim = 1;
      break;
    case GL_FLOAT_VEC2_ARB:
      dim = 2;
      break;
    case GL_FLOAT_VEC3_ARB:
      dim = 3;
      break;
    case GL_FLOAT_VEC4_ARB:
    case GL_FLOAT_MAT2_ARB:
      dim = 4;
      break;
    case GL_FLOAT_MAT3_ARB:
      dim = 9;
      break;
    case GL_FLOAT_MAT4_ARB:
      dim = 16;
      break;
    default:
      luaL_error(L, "gl.GetUniformARB: unsupported uniform type");
  }
  if (integer) {
    Array1D<Int> values(dim);
    glGetUniformivARB(prog, loc, values);
    if (dim == 1) {
      lua_pushinteger(L, values[0]);
    } else {
      values.toLUA(L);
    }
  } else {
    Array1D<Float> values(dim);
    glGetUniformfvARB(prog, loc, values);
    if (dim == 1) {
      lua_pushnumber(L, values[0]);
    } else {
      values.toLUA(L);
    }
  }
  return 1;
}
static int lua_glGetActiveUniformARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Handle obj(L, 1);
  Uint idx(L, 2);
  GLint len;
  GLint size;
  GLenum type;  
  glGetObjectParameterivARB(obj, GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB, &len);
  Array1D<Char> name(len+1);
  glGetActiveUniformARB(obj, idx, len, 0, &size, &type, name);
  lua_pushinteger(L, size);
  lua_pushinteger(L, type);
  lua_pushstring(L, name);
  return 3;
}
static int lua_glGetAttachedObjectsARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Handle obj(L, 1);
  GLint len=0;
  glGetObjectParameterivARB(obj, GL_OBJECT_ATTACHED_OBJECTS_ARB, &len);
  if (len == 0) {
    lua_newtable(L);
  } else {
    Array1D<Handle> handles(len);
    glGetAttachedObjectsARB(obj, len, 0, handles);
    handles.toLUA(L);
  }
  return 1;
}
static int lua_glGetObjectParameterARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Handle obj(L, 1);
  Enum pname(L, 2);
  int dim=0;
  bool integer=false;
  switch (pname) {
    case GL_OBJECT_TYPE_ARB:
    case GL_OBJECT_SUBTYPE_ARB:
    case GL_OBJECT_DELETE_STATUS_ARB:
    case GL_OBJECT_COMPILE_STATUS_ARB:
    case GL_OBJECT_LINK_STATUS_ARB:
    case GL_OBJECT_VALIDATE_STATUS_ARB:
    case GL_OBJECT_INFO_LOG_LENGTH_ARB:
    case GL_OBJECT_SHADER_SOURCE_LENGTH_ARB:
    case GL_OBJECT_ATTACHED_OBJECTS_ARB:
    case GL_OBJECT_ACTIVE_UNIFORMS_ARB:
    case GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB:
    case GL_OBJECT_ACTIVE_ATTRIBUTES_ARB: // ARB_vertex_shader
    case GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB: // ARB_vertex_shader
      integer = true;
      dim = 1;
      break;
    default:
      luaL_error(L, "gl.GetObjectParameterARB: invalid parameter name");
  }
  if (integer) {
    Array1D<Int> values(dim);
    glGetObjectParameterivARB(obj, pname, values);
    if (dim == 1) {
      lua_pushinteger(L, values[0]);
    } else {
      values.toLUA(L);
    }
  } else {
    Array1D<Float> values(dim);
    glGetObjectParameterfvARB(obj, pname, values);
    if (dim == 1) {
      lua_pushnumber(L, values[0]);
    } else {
      values.toLUA(L);
    }
  }
  return 1;
}
static int lua_glGetInfoLogARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Handle obj(L, 1);
  GLint len=0;
  glGetObjectParameterivARB(obj, GL_OBJECT_INFO_LOG_LENGTH_ARB, &len);
  Array1D<Char> log(len+1);
  glGetInfoLogARB(obj, len, 0, log);
  lua_pushstring(L, log); 
  return 1;
}
static int lua_glGetShaderSourceARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Handle obj(L, 1);
  GLint len=0;
  glGetObjectParameterivARB(obj, GL_OBJECT_SHADER_SOURCE_LENGTH_ARB, &len);
  Array1D<Char> src(len+1);
  glGetShaderSourceARB(obj, len, 0, src);
  lua_pushstring(L, src);
  return 1;
}

// GL_ARB_texture_compression

static int lua_glCompressedTexImage1DARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc7<Enum, Int, Enum, Sizei, Int, Sizei, ConstPtr, glCompressedTexImage1D>::Call(L);
#else
  return WrapFunc7<Enum, Int, Enum, Sizei, Int, Sizei, ConstPtr >::Call(L, glCompressedTexImage1D);
#endif
}
static int lua_glCompressedTexImage2DARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc8<Enum, Int, Enum, Sizei, Sizei, Int, Sizei, ConstPtr, glCompressedTexImage2D>::Call(L);
#else
  return WrapFunc8<Enum, Int, Enum, Sizei, Sizei, Int, Sizei, ConstPtr >::Call(L, glCompressedTexImage2D);
#endif
}
static int lua_glCompressedTexImage3DARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc9<Enum, Int, Enum, Sizei, Sizei, Sizei, Int, Sizei, ConstPtr, glCompressedTexImage3D>::Call(L);
#else
  return WrapFunc9<Enum, Int, Enum, Sizei, Sizei, Sizei, Int, Sizei, ConstPtr >::Call(L, glCompressedTexImage3D);
#endif
}
static int lua_glCompressedTexSubImage1DARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc7<Enum, Int, Int, Sizei, Enum, Sizei, ConstPtr, glCompressedTexSubImage1D>::Call(L);
#else
  return WrapFunc7<Enum, Int, Int, Sizei, Enum, Sizei, ConstPtr >::Call(L, glCompressedTexSubImage1D);
#endif
}
static int lua_glCompressedTexSubImage2DARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc9<Enum, Int, Int, Int, Sizei, Sizei, Enum, Sizei, ConstPtr, glCompressedTexSubImage2D>::Call(L);
#else
  return WrapFunc9<Enum, Int, Int, Int, Sizei, Sizei, Enum, Sizei, ConstPtr >::Call(L, glCompressedTexSubImage2D);
#endif
}
static int lua_glCompressedTexSubImage3DARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc11<Enum, Int, Int, Int, Int, Sizei, Sizei, Sizei, Enum, Sizei, ConstPtr, glCompressedTexSubImage3D>::Call(L);
#else
  return WrapFunc11<Enum, Int, Int, Int, Int, Sizei, Sizei, Sizei, Enum, Sizei, ConstPtr >::Call(L, glCompressedTexSubImage3D);
#endif
}
static int lua_glGetCompressedTexImageARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Int, Ptr, glGetCompressedTexImageARB>::Call(L);
#else
  return WrapFunc3<Enum, Int, Ptr >::Call(L, glGetCompressedTexImageARB);
#endif
}

// GL_ARB_transpose_matrix

static int lua_glLoadTransposeMatrixdARB(lua_State *L) {
  // WrapFunc1<CheckSize<Array<Double>, 16>, glLoadTransposeMatrixdARB>::Call(L);
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Array<Double>, glLoadTransposeMatrixdARB>::Call(L);
#else
  return WrapFunc1<Array<Double> >::Call(L, glLoadTransposeMatrixdARB);
#endif
}
static int lua_glLoadTransposeMatrixfARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Array<Float>, glLoadTransposeMatrixfARB>::Call(L);
#else
  return WrapFunc1<Array<Float> >::Call(L, glLoadTransposeMatrixfARB);
#endif
}
static int lua_glMultTransposeMatrixdARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Array<Double>, glMultTransposeMatrixdARB>::Call(L);
#else
  return WrapFunc1<Array<Double> >::Call(L, glMultTransposeMatrixdARB);
#endif
}
static int lua_glMultTransposeMatrixfARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Array<Float>, glMultTransposeMatrixfARB>::Call(L);
#else
  return WrapFunc1<Array<Float> >::Call(L, glMultTransposeMatrixfARB);
#endif
}

// GL_ARB_vertex_weight

static int lua_glVertexBlendARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Int, glVertexBlendARB>::Call(L);
#else
  return WrapFunc1<Int >::Call(L, glVertexBlendARB);
#endif
}
static int lua_glWeightPointerARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Enum, Sizei, Ptr, glWeightPointerARB>::Call(L);
#else
  return WrapFunc4<Int, Enum, Sizei, Ptr >::Call(L, glWeightPointerARB);
#endif
}
static int lua_glWeightbvARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Array1D<Byte> weights(L, 1);
  glWeightbvARB(weights.size(), weights);
  return 0;
}
static int lua_glWeightdvARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Array1D<Double> weights(L, 1);
  glWeightdvARB(weights.size(), weights);
  return 0;
}
static int lua_glWeightfvARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Array1D<Float> weights(L, 1);
  glWeightfvARB(weights.size(), weights);
  return 0;
}
static int lua_glWeightivARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Array1D<Int> weights(L, 1);
  glWeightivARB(weights.size(), weights);
  return 0;
}
static int lua_glWeightsvARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Array1D<Short> weights(L, 1);
  glWeightsvARB(weights.size(), weights);
  return 0;
}
static int lua_glWeightubvARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Array1D<Ubyte> weights(L, 1);
  glWeightubvARB(weights.size(), weights);
  return 0;
}
static int lua_glWeightuivARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Array1D<Uint> weights(L, 1);
  glWeightuivARB(weights.size(), weights);
  return 0;
}
static int lua_glWeightusvARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Array1D<Ushort> weights(L, 1);
  glWeightusvARB(weights.size(), weights);
  return 0;
}

// GL_ARB_vertex_buffer_object

static int lua_glBindBufferARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Uint, glBindBufferARB>::Call(L);
#else
  return WrapFunc2<Enum, Uint >::Call(L, glBindBufferARB);
#endif
}
static int lua_glBufferDataARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Enum, Sizeiptr, ConstPtr, Enum, glBufferDataARB>::Call(L);
#else
  return WrapFunc4<Enum, Sizeiptr, ConstPtr, Enum >::Call(L, glBufferDataARB);
#endif
}
static int lua_glBufferSubDataARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Enum, Intptr, Sizeiptr, ConstPtr, glBufferSubDataARB>::Call(L);
#else
  return WrapFunc4<Enum, Intptr, Sizeiptr, ConstPtr >::Call(L, glBufferSubDataARB);
#endif
}
static int lua_glDeleteBuffersARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Array1D<Uint> buffers(L, 1);
  glDeleteBuffersARB(buffers.size(), buffers);
  return 0;
}
static int lua_glGenBuffersARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Sizei n(L, 1);
  Array1D<Uint> buffers(n);
  glGenBuffersARB(n, buffers);
  buffers.toLUA(L);
  return 1;
}
static int lua_glIsBufferARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Uint buffer(L, 1);
  lua_pushboolean(L, (glIsBufferARB(buffer) == GL_TRUE ? 1 : 0));
  return 1;
}
static int lua_glMapBufferARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum target(L, 1);
  Enum access(L, 2);
  lua_pushlightuserdata(L, glMapBufferARB(target, access));
  return 1;
}
static int lua_glUnmapBufferARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Enum target(L, 1);
  lua_pushboolean(L, (glUnmapBufferARB(target) == GL_TRUE ? 1 : 0));
  return 1;
}
static int lua_glGetBufferPointerARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum target(L, 1);
  Enum pname(L, 2);
  GLvoid *ptr;
  glGetBufferPointervARB(target, pname, &ptr);
  lua_pushlightuserdata(L, ptr);
  return 1;
}
static int lua_glGetBufferSubDataARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Enum, Intptr, Sizeiptr, Ptr, glGetBufferSubDataARB>::Call(L);
#else
  return WrapFunc4<Enum, Intptr, Sizeiptr, Ptr >::Call(L, glGetBufferSubDataARB);
#endif
}
static int lua_glGetBufferParameterARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum target(L, 1);
  Enum pname(L, 2);
  int dim = 0;
  switch (pname) {
    case GL_BUFFER_SIZE_ARB:
    case GL_BUFFER_USAGE_ARB:
    case GL_BUFFER_ACCESS_ARB:
    case GL_BUFFER_MAPPED_ARB:
      dim = 1;
      break;
    default:
      luaL_error(L, "gl.GetBufferParameter: invalid parameter name");
  }
  Array1D<Int> values(dim);
  glGetBufferParameterivARB(target, pname, values);
  if (dim == 1) {
    lua_pushinteger(L, values[0]);
  } else {
    values.toLUA(L);
  }
  return 1;
}

// GL_ARB_vertex_program

static int lua_glBindProgramARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Uint, glBindProgramARB>::Call(L);
#else
  return WrapFunc2<Enum, Uint >::Call(L, glBindProgramARB);
#endif
}
static int lua_glDeleteProgramsARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Array1D<Uint> progs(L, 1);
  glDeleteProgramsARB(progs.size(), progs);
  return 0;
}
static int lua_glDisableVertexAttribArrayARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Uint, glDisableVertexAttribArrayARB>::Call(L);
#else
  return WrapFunc1<Uint >::Call(L, glDisableVertexAttribArrayARB);
#endif
}
static int lua_glEnableVertexAttribArrayARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Uint, glEnableVertexAttribArrayARB>::Call(L);
#else
  return WrapFunc1<Uint >::Call(L, glEnableVertexAttribArrayARB);
#endif
}
static int lua_glGenProgramsARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Sizei n(L, 1);
  Array1D<Uint> progs(n);
  glGenProgramsARB(n, progs);
  progs.toLUA(L);
  return 1;
}
static int lua_glGetProgramEnvParameterARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum target(L, 1);
  Uint index(L, 2);
  Array1D<Double> values(4);
  glGetProgramEnvParameterdvARB(target, index, values);
  values.toLUA(L);
  return 1;
}
static int lua_glGetProgramLocalParameterARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum target(L, 1);
  Uint index(L, 2);
  Array1D<Double> values(4);
  glGetProgramLocalParameterdvARB(target, index, values);
  values.toLUA(L);
  return 1;
}
static int lua_glGetProgramARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum target(L, 1);
  Enum pname(L, 2);
  int dim = 0;
  switch (pname) {
    case GL_PROGRAM_BINDING_ARB:
    case GL_PROGRAM_LENGTH_ARB:
    case GL_PROGRAM_FORMAT_ARB:
    case GL_PROGRAM_INSTRUCTIONS_ARB:
    case GL_PROGRAM_TEMPORARIES_ARB:
    case GL_PROGRAM_PARAMETERS_ARB:
    case GL_PROGRAM_ATTRIBS_ARB:
    case GL_PROGRAM_ADDRESS_REGISTERS_ARB:
    case GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB:
    case GL_PROGRAM_NATIVE_TEMPORARIES_ARB:
    case GL_PROGRAM_NATIVE_PARAMETERS_ARB:
    case GL_PROGRAM_NATIVE_ATTRIBS_ARB:
    case GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB:
    case GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB:
    case GL_MAX_PROGRAM_ENV_PARAMETERS_ARB:
    case GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB:
    case GL_MAX_PROGRAM_INSTRUCTIONS_ARB:
    case GL_MAX_PROGRAM_TEMPORARIES_ARB:
    case GL_MAX_PROGRAM_PARAMETERS_ARB:
    case GL_MAX_PROGRAM_ATTRIBS_ARB:
    case GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB:
    case GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB:
    case GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB:
    case GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB:
    case GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB:
    case GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB:
    case GL_PROGRAM_ALU_INSTRUCTIONS_ARB: // ARB_fragment_program
    case GL_PROGRAM_TEX_INSTRUCTIONS_ARB: // "
    case GL_PROGRAM_TEX_INDIRECTIONS_ARB: // "
    case GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB: // "
    case GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB: // "
    case GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB: // "
    case GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB: // "
    case GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB: // "
    case GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB: // "
    case GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB: // "
    case GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB: // "
    case GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB: // "
      dim = 1;
      break;
    default:
      luaL_error(L, "gl.GetProgramARB: invalid parameter name");
  }
  Array1D<Int> values(dim);
  glGetProgramivARB(target, pname, values);
  if (dim == 1) {
    lua_pushinteger(L, values[0]);
  } else {
    values.toLUA(L);
  }
  return 0;
}
static int lua_glGetProgramStringARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum target(L, 1);
  Enum pname(L, 2);
  GLint len;
  glGetProgramiv(target, GL_PROGRAM_LENGTH_ARB, &len);
  Array1D<Char> str(len+1);
  glGetProgramStringARB(target, pname, str);
  lua_pushstring(L, str);
  return 1;
}
static int lua_glIsProgramARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Uint program(L, 1);
  lua_pushboolean(L, (glIsProgramARB(program) == GL_TRUE ? 1 : 0));
  return 1;
}
static int lua_glProgramEnvParameter4dARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc6<Enum, Uint, Double, Double, Double, Double, glProgramEnvParameter4dARB>::Call(L);
#else
  return WrapFunc6<Enum, Uint, Double, Double, Double, Double >::Call(L, glProgramEnvParameter4dARB);
#endif
}
static int lua_glProgramEnvParameter4dvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Uint, ConstArray<Double>, glProgramEnvParameter4dvARB>::Call(L);
#else
  return WrapFunc3<Enum, Uint, ConstArray<Double> >::Call(L, glProgramEnvParameter4dvARB);
#endif
}
static int lua_glProgramEnvParameter4fARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc6<Enum, Uint, Float, Float, Float, Float, glProgramEnvParameter4fARB>::Call(L);
#else
  return WrapFunc6<Enum, Uint, Float, Float, Float, Float >::Call(L, glProgramEnvParameter4fARB);
#endif
}
static int lua_glProgramEnvParameter4fvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Uint, ConstArray<Float>, glProgramEnvParameter4fvARB>::Call(L);
#else
  return WrapFunc3<Enum, Uint, ConstArray<Float> >::Call(L, glProgramEnvParameter4fvARB);
#endif
}
static int lua_glProgramLocalParameter4dARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc6<Enum, Uint, Double, Double, Double, Double, glProgramLocalParameter4dARB>::Call(L);
#else
  return WrapFunc6<Enum, Uint, Double, Double, Double, Double >::Call(L, glProgramLocalParameter4dARB);
#endif
}
static int lua_glProgramLocalParameter4dvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Uint, ConstArray<Double>, glProgramLocalParameter4dvARB>::Call(L);
#else
  return WrapFunc3<Enum, Uint, ConstArray<Double> >::Call(L, glProgramLocalParameter4dvARB);
#endif
}
static int lua_glProgramLocalParameter4fARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc6<Enum, Uint, Float, Float, Float, Float, glProgramLocalParameter4fARB>::Call(L);
#else
  return WrapFunc6<Enum, Uint, Float, Float, Float, Float >::Call(L, glProgramLocalParameter4fARB);
#endif
}
static int lua_glProgramLocalParameter4fvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Uint, ConstArray<Float>, glProgramLocalParameter4fvARB>::Call(L);
#else
  return WrapFunc3<Enum, Uint, ConstArray<Float> >::Call(L, glProgramLocalParameter4fvARB);
#endif
}
static int lua_glProgramStringARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 3);
  Enum target(L, 1);
  Enum format(L, 2);
  String string(L, 3);
  GLsizei len = (GLsizei) strlen(string);
  glProgramStringARB(target, format, len, string);
  return 0;
}
static int lua_glVertexAttrib1dARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, Double, glVertexAttrib1dARB>::Call(L);
#else
  return WrapFunc2<Uint, Double >::Call(L, glVertexAttrib1dARB);
#endif
}
static int lua_glVertexAttrib2dARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Uint, Double, Double, glVertexAttrib2dARB>::Call(L);
#else
  return WrapFunc3<Uint, Double, Double >::Call(L, glVertexAttrib2dARB);
#endif
}
static int lua_glVertexAttrib2dvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Double>, glVertexAttrib2dvARB>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Double> >::Call(L, glVertexAttrib2dvARB);
#endif
}
static int lua_glVertexAttrib3dARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Uint, Double, Double, Double, glVertexAttrib3dARB>::Call(L);
#else
  return WrapFunc4<Uint, Double, Double, Double >::Call(L, glVertexAttrib3dARB);
#endif
}
static int lua_glVertexAttrib3dvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Double>, glVertexAttrib3dvARB>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Double> >::Call(L, glVertexAttrib3dvARB);
#endif
}
static int lua_glVertexAttrib4dARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Uint, Double, Double, Double, Double, glVertexAttrib4dARB>::Call(L);
#else
  return WrapFunc5<Uint, Double, Double, Double, Double >::Call(L, glVertexAttrib4dARB);
#endif
}
static int lua_glVertexAttrib4dvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Double>, glVertexAttrib4dvARB>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Double> >::Call(L, glVertexAttrib4dvARB);
#endif
}
static int lua_glVertexAttrib1fARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, Float, glVertexAttrib1fARB>::Call(L);
#else
  return WrapFunc2<Uint, Float >::Call(L, glVertexAttrib1fARB);
#endif
}
static int lua_glVertexAttrib2fARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Uint, Float, Float, glVertexAttrib2fARB>::Call(L);
#else
  return WrapFunc3<Uint, Float, Float >::Call(L, glVertexAttrib2fARB);
#endif
}
static int lua_glVertexAttrib2fvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Float>, glVertexAttrib2fvARB>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Float> >::Call(L, glVertexAttrib2fvARB);
#endif
}
static int lua_glVertexAttrib3fARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Uint, Float, Float, Float, glVertexAttrib3fARB>::Call(L);
#else
  return WrapFunc4<Uint, Float, Float, Float >::Call(L, glVertexAttrib3fARB);
#endif
}
static int lua_glVertexAttrib3fvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Float>, glVertexAttrib3fvARB>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Float> >::Call(L, glVertexAttrib3fvARB);
#endif
}
static int lua_glVertexAttrib4fARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Uint, Float, Float, Float, Float, glVertexAttrib4fARB>::Call(L);
#else
  return WrapFunc5<Uint, Float, Float, Float, Float >::Call(L, glVertexAttrib4fARB);
#endif
}
static int lua_glVertexAttrib4fvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Float>, glVertexAttrib4fvARB>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Float> >::Call(L, glVertexAttrib4fvARB);
#endif
}
static int lua_glVertexAttrib1sARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, Short, glVertexAttrib1sARB>::Call(L);
#else
  return WrapFunc2<Uint, Short >::Call(L, glVertexAttrib1sARB);
#endif
}
static int lua_glVertexAttrib2sARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Uint, Short, Short, glVertexAttrib2sARB>::Call(L);
#else
  return WrapFunc3<Uint, Short, Short >::Call(L, glVertexAttrib2sARB);
#endif
}
static int lua_glVertexAttrib2svARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Short>, glVertexAttrib2svARB>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Short> >::Call(L, glVertexAttrib2svARB);
#endif
}
static int lua_glVertexAttrib3sARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Uint, Short, Short, Short, glVertexAttrib3sARB>::Call(L);
#else
  return WrapFunc4<Uint, Short, Short, Short >::Call(L, glVertexAttrib3sARB);
#endif
}
static int lua_glVertexAttrib3svARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Short>, glVertexAttrib3svARB>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Short> >::Call(L, glVertexAttrib3svARB);
#endif
}
static int lua_glVertexAttrib4sARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Uint, Short, Short, Short, Short, glVertexAttrib4sARB>::Call(L);
#else
  return WrapFunc5<Uint, Short, Short, Short, Short >::Call(L, glVertexAttrib4sARB);
#endif
}
static int lua_glVertexAttrib4svARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Short>, glVertexAttrib4svARB>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Short> >::Call(L, glVertexAttrib4svARB);
#endif
}
static int lua_glVertexAttrib4NbvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Byte>, glVertexAttrib4NbvARB>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Byte> >::Call(L, glVertexAttrib4NbvARB);
#endif
}
static int lua_glVertexAttrib4NivARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Int>, glVertexAttrib4NivARB>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Int> >::Call(L, glVertexAttrib4NivARB);
#endif
}
static int lua_glVertexAttrib4NsvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Short>, glVertexAttrib4NsvARB>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Short> >::Call(L, glVertexAttrib4NsvARB);
#endif
}
static int lua_glVertexAttrib4NubvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Ubyte>, glVertexAttrib4NubvARB>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Ubyte> >::Call(L, glVertexAttrib4NubvARB);
#endif
}
static int lua_glVertexAttrib4NuivARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Uint>, glVertexAttrib4NuivARB>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Uint> >::Call(L, glVertexAttrib4NuivARB);
#endif
}
static int lua_glVertexAttrib4NusvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Ushort>, glVertexAttrib4NusvARB>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Ushort> >::Call(L, glVertexAttrib4NusvARB);
#endif
}
static int lua_glVertexAttrib4bvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Byte>, glVertexAttrib4bvARB>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Byte> >::Call(L, glVertexAttrib4bvARB);
#endif
}
static int lua_glVertexAttrib4ivARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Int>, glVertexAttrib4ivARB>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Int> >::Call(L, glVertexAttrib4ivARB);
#endif
}
static int lua_glVertexAttrib4ubvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Ubyte>, glVertexAttrib4ubvARB>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Ubyte> >::Call(L, glVertexAttrib4ubvARB);
#endif
}
static int lua_glVertexAttrib4uivARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Uint>, glVertexAttrib4uivARB>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Uint> >::Call(L, glVertexAttrib4uivARB);
#endif
}
static int lua_glVertexAttrib4usvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Ushort>, glVertexAttrib4usvARB>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Ushort> >::Call(L, glVertexAttrib4usvARB);
#endif
}
static int lua_glVertexAttrib4NubARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Uint, Ubyte, Ubyte, Ubyte, Ubyte, glVertexAttrib4NubARB>::Call(L);
#else
  return WrapFunc5<Uint, Ubyte, Ubyte, Ubyte, Ubyte >::Call(L, glVertexAttrib4NubARB);
#endif
}
static int lua_glVertexAttribPointerARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc6<Uint, Int, Enum, Boolean, Sizei, ConstPtr, glVertexAttribPointerARB>::Call(L);
#else
  return WrapFunc6<Uint, Int, Enum, Boolean, Sizei, ConstPtr >::Call(L, glVertexAttribPointerARB);
#endif
}
static int lua_glGetVertexAttribPointerARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Uint index(L, 1);
  Enum pname(L, 2);
  GLvoid *ptr;
  glGetVertexAttribPointervARB(index, pname, &ptr);
  lua_pushlightuserdata(L, ptr);
  return 1;
}
static int lua_glGetVertexAttribARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Uint index(L, 1);
  Enum pname(L, 2);
  int dim = 0;
  bool integer = false;
  switch (pname) {
    case GL_CURRENT_VERTEX_ATTRIB_ARB:
      dim = 4;
      break;
    case GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB:
    case GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB:
    case GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB:
    case GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB:
    case GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB:
    case GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB: // requires: ARB_vertex_buffer_object
      integer = true;
      dim = 1;
      break;
    default:
      luaL_error(L, "gl.GetVertexAttribARB: invalid parameter name");
  }
  if (integer) {
    Array1D<Int> values;
    glGetVertexAttribivARB(index, pname, values);
    if (dim == 1) {
      lua_pushinteger(L, values[0]);
    } else {
      values.toLUA(L);
    }
  } else {
    Array1D<Double> values;
    glGetVertexAttribdvARB(index, pname, values);
    if (dim == 1) {
      lua_pushnumber(L, values[0]);
    } else {
      values.toLUA(L);
    }
  }
  return 1;
}

// GL_ARB_vertex_shader

static int lua_glBindAttribLocationARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Handle, Uint, String, glBindAttribLocationARB>::Call(L);
#else
  return WrapFunc3<Handle, Uint, String >::Call(L, glBindAttribLocationARB);
#endif
}
static int lua_glGetActiveAttribARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Handle obj(L, 1);
  Uint index(L, 2);
  GLint len=0;
  glGetObjectParameterivARB(obj, GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB, &len);
  GLint size;
  GLenum type;
  Array1D<Char> name(len+1);
  glGetActiveAttribARB(obj, index, len, 0, &size, &type, name);
  lua_pushinteger(L, size);
  lua_pushinteger(L, type);
  lua_pushstring(L, name);
  return 3;
}
static int lua_glGetAttribLocationARB(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Handle obj(L, 1);
  String name(L, 2);
  lua_pushinteger(L, glGetAttribLocationARB(obj, name));
  return 1;
}

// GL_ARB_window_pos

static int lua_glWindowPos2dARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Double, Double, glWindowPos2dARB>::Call(L);
#else
  return WrapFunc2<Double, Double >::Call(L, glWindowPos2dARB);
#endif
}
static int lua_glWindowPos2dvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Double>, glWindowPos2dvARB>::Call(L);
#else
  return WrapFunc1<ConstArray<Double> >::Call(L, glWindowPos2dvARB);
#endif
}
static int lua_glWindowPos3dARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Double, Double, Double, glWindowPos3dARB>::Call(L);
#else
  return WrapFunc3<Double, Double, Double >::Call(L, glWindowPos3dARB);
#endif
}
static int lua_glWindowPos3dvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Double>, glWindowPos3dvARB>::Call(L);
#else
  return WrapFunc1<ConstArray<Double> >::Call(L, glWindowPos3dvARB);
#endif
}
static int lua_glWindowPos2fARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Float, Float, glWindowPos2fARB>::Call(L);
#else
  return WrapFunc2<Float, Float >::Call(L, glWindowPos2fARB);
#endif
}
static int lua_glWindowPos2fvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Float>, glWindowPos2fvARB>::Call(L);
#else
  return WrapFunc1<ConstArray<Float> >::Call(L, glWindowPos2fvARB);
#endif
}
static int lua_glWindowPos3fARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Float, Float, Float, glWindowPos3fARB>::Call(L);
#else
  return WrapFunc3<Float, Float, Float >::Call(L, glWindowPos3fARB);
#endif
}
static int lua_glWindowPos3fvARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Float>, glWindowPos3fvARB>::Call(L);
#else
  return WrapFunc1<ConstArray<Float> >::Call(L, glWindowPos3fvARB);
#endif
}
static int lua_glWindowPos2iARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Int, Int, glWindowPos2iARB>::Call(L);
#else
  return WrapFunc2<Int, Int >::Call(L, glWindowPos2iARB);
#endif
}
static int lua_glWindowPos2ivARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Int>, glWindowPos2ivARB>::Call(L);
#else
  return WrapFunc1<ConstArray<Int> >::Call(L, glWindowPos2ivARB);
#endif
}
static int lua_glWindowPos3iARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Int, Int, glWindowPos3iARB>::Call(L);
#else
  return WrapFunc3<Int, Int, Int >::Call(L, glWindowPos3iARB);
#endif
}
static int lua_glWindowPos3ivARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Int>, glWindowPos3ivARB>::Call(L);
#else
  return WrapFunc1<ConstArray<Int> >::Call(L, glWindowPos3ivARB);
#endif
}
static int lua_glWindowPos2sARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Short, Short, glWindowPos2sARB>::Call(L);
#else
  return WrapFunc2<Short, Short >::Call(L, glWindowPos2sARB);
#endif
}
static int lua_glWindowPos2svARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Short>, glWindowPos2svARB>::Call(L);
#else
  return WrapFunc1<ConstArray<Short> >::Call(L, glWindowPos2svARB);
#endif
}
static int lua_glWindowPos3sARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Short, Short, Short, glWindowPos3sARB>::Call(L);
#else
  return WrapFunc3<Short, Short, Short >::Call(L, glWindowPos3sARB);
#endif
}
static int lua_glWindowPos3svARB(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Short>, glWindowPos3svARB>::Call(L);
#else
  return WrapFunc1<ConstArray<Short> >::Call(L, glWindowPos3svARB);
#endif
}

// GL_ARB_imaging

static int lua_glColorSubTable(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc6<Enum, Sizei, Sizei, Enum, Enum, ConstPtr, glColorSubTable>::Call(L);
#else
  return WrapFunc6<Enum, Sizei, Sizei, Enum, Enum, ConstPtr >::Call(L, glColorSubTable);
#endif
}
static int lua_glColorTable(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc6<Enum, Enum, Sizei, Enum, Enum, ConstPtr, glColorTable>::Call(L);
#else
  return WrapFunc6<Enum, Enum, Sizei, Enum, Enum, ConstPtr >::Call(L, glColorTable);
#endif
}
static int lua_glColorTableParameterfv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, ConstArray<Float>, glColorTableParameterfv>::Call(L);
#else
  return WrapFunc3<Enum, Enum, ConstArray<Float> >::Call(L, glColorTableParameterfv);
#endif
}
static int lua_glColorTableParameteriv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, ConstArray<Int>, glColorTableParameteriv>::Call(L);
#else
  return WrapFunc3<Enum, Enum, ConstArray<Int> >::Call(L, glColorTableParameteriv);
#endif
}
static int lua_glConvolutionFilter1D(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc6<Enum, Enum, Sizei, Enum, Enum, ConstPtr, glConvolutionFilter1D>::Call(L);
#else
  return WrapFunc6<Enum, Enum, Sizei, Enum, Enum, ConstPtr >::Call(L, glConvolutionFilter1D);
#endif
}
static int lua_glConvolutionFilter2D(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc7<Enum, Enum, Sizei, Sizei, Enum, Enum, ConstPtr, glConvolutionFilter2D>::Call(L);
#else
  return WrapFunc7<Enum, Enum, Sizei, Sizei, Enum, Enum, ConstPtr >::Call(L, glConvolutionFilter2D);
#endif
}
static int lua_glConvolutionParameterf(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, Float, glConvolutionParameterf>::Call(L);
#else
  return WrapFunc3<Enum, Enum, Float >::Call(L, glConvolutionParameterf);
#endif
}
static int lua_glConvolutionParameterfv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, ConstArray<Float>, glConvolutionParameterfv>::Call(L);
#else
  return WrapFunc3<Enum, Enum, ConstArray<Float> >::Call(L, glConvolutionParameterfv);
#endif
}
static int lua_glConvolutionParameteri(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, Int, glConvolutionParameteri>::Call(L);
#else
  return WrapFunc3<Enum, Enum, Int >::Call(L, glConvolutionParameteri);
#endif
}
static int lua_glConvolutionParameteriv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, ConstArray<Int>, glConvolutionParameteriv>::Call(L);
#else
  return WrapFunc3<Enum, Enum, ConstArray<Int> >::Call(L, glConvolutionParameteriv);
#endif
}
static int lua_glCopyColorSubTable(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Enum, Sizei, Int, Int, Sizei, glCopyColorSubTable>::Call(L);
#else
  return WrapFunc5<Enum, Sizei, Int, Int, Sizei >::Call(L, glCopyColorSubTable);
#endif
}
static int lua_glCopyColorTable(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Enum, Enum, Int, Int, Sizei, glCopyColorTable>::Call(L);
#else
  return WrapFunc5<Enum, Enum, Int, Int, Sizei >::Call(L, glCopyColorTable);
#endif
}
static int lua_glCopyConvolutionFilter1D(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Enum, Enum, Int, Int, Sizei, glCopyConvolutionFilter1D>::Call(L);
#else
  return WrapFunc5<Enum, Enum, Int, Int, Sizei >::Call(L, glCopyConvolutionFilter1D);
#endif
}
static int lua_glCopyConvolutionFilter2D(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc6<Enum, Enum, Int, Int, Sizei, Sizei, glCopyConvolutionFilter2D>::Call(L);
#else
  return WrapFunc6<Enum, Enum, Int, Int, Sizei, Sizei >::Call(L, glCopyConvolutionFilter2D);
#endif
}
static int lua_glGetColorTable(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Enum, Enum, Enum, Ptr, glGetColorTable>::Call(L);
#else
  return WrapFunc4<Enum, Enum, Enum, Ptr >::Call(L, glGetColorTable);
#endif
}
static int lua_glGetColorTableParameter(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum target(L, 1);
  Enum pname(L, 2);
  bool integer = false;
  int dim = 0;
  switch (pname) {
    case GL_COLOR_TABLE_FORMAT:
    case GL_COLOR_TABLE_WIDTH:
    case GL_COLOR_TABLE_RED_SIZE:
    case GL_COLOR_TABLE_GREEN_SIZE:
    case GL_COLOR_TABLE_BLUE_SIZE:
    case GL_COLOR_TABLE_ALPHA_SIZE:
    case GL_COLOR_TABLE_LUMINANCE_SIZE:
    case GL_COLOR_TABLE_INTENSITY_SIZE:
      integer = true;
      dim = 1;
      break;
    case GL_COLOR_TABLE_SCALE:
    case GL_COLOR_TABLE_BIAS:
      dim = 4;
      break;
    default:
      break;
  }
  if (dim == 0) {
    luaL_error(L, "gl.GetColorTableParameter: invalid parameter name");
  }
  if (integer) {
    Array1D<Int> values(dim);
    glGetColorTableParameteriv(target, pname, values);
    if (dim == 1) {
      lua_pushinteger(L, values[0]);
    } else {
      values.toLUA(L);
    }
  } else {
    Array1D<Float> values(dim);
    glGetColorTableParameterfv(target, pname, values);
    if (dim == 1) {
      lua_pushnumber(L, values[0]);
    } else {
      values.toLUA(L);
    }
  }
  return 1;
}
static int lua_glGetConvolutionFilter(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Enum, Enum, Enum, Ptr, glGetConvolutionFilter>::Call(L);
#else
  return WrapFunc4<Enum, Enum, Enum, Ptr >::Call(L, glGetConvolutionFilter);
#endif
}
static int lua_glGetConvolutionParameter(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum target(L, 1);
  Enum pname(L, 2);
  bool integer = false;
  int dim = 0;
  switch (pname) {
    case GL_CONVOLUTION_BORDER_MODE:
    case GL_CONVOLUTION_FORMAT:
    case GL_CONVOLUTION_WIDTH:
    case GL_CONVOLUTION_HEIGHT:
    case GL_MAX_CONVOLUTION_WIDTH:
    case GL_MAX_CONVOLUTION_HEIGHT:
      integer = true;
      dim = 1;
      break;
    case GL_CONVOLUTION_BORDER_COLOR:
    case GL_CONVOLUTION_FILTER_SCALE:
    case GL_CONVOLUTION_FILTER_BIAS:
      dim = 4;
      break;
    default:
      break;
  }
  if (dim == 0) {
    luaL_error(L, "gl.GetConvolutionParameter: invalid parameter name");
  }
  if (integer) {
    Array1D<Int> values(dim);
    glGetConvolutionParameteriv(target, pname, values);
    if (dim == 1) {
      lua_pushinteger(L, values[0]);
    } else {
      values.toLUA(L);
    }
  } else {
    Array1D<Float> values(dim);
    glGetConvolutionParameterfv(target, pname, values);
    if (dim == 1) {
      lua_pushnumber(L, values[0]);
    } else {
      values.toLUA(L);
    }
  }
  return 1;
}
static int lua_glGetHistogram(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Enum, Boolean, Enum, Enum, Ptr, glGetHistogram>::Call(L);
#else
  return WrapFunc5<Enum, Boolean, Enum, Enum, Ptr >::Call(L, glGetHistogram);
#endif
}
static int lua_glGetHistogramParameter(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum target(L, 1);
  Enum pname(L, 2);
  bool integer = false;
  int dim = 0;
  switch (pname) {
    case GL_HISTOGRAM_WIDTH:
    case GL_HISTOGRAM_FORMAT:
    case GL_HISTOGRAM_RED_SIZE:
    case GL_HISTOGRAM_GREEN_SIZE:
    case GL_HISTOGRAM_BLUE_SIZE:
    case GL_HISTOGRAM_ALPHA_SIZE:
    case GL_HISTOGRAM_LUMINANCE_SIZE:
    case GL_HISTOGRAM_SINK:
      integer = true;
      dim = 1;
      break;
    default:
      break;
  }
  if (dim == 0) {
    luaL_error(L, "gl.GetHistogramParameter: invalid parameter name");
  }
  if (integer) {
    Array1D<Int> values(dim);
    glGetHistogramParameteriv(target, pname, values);
    if (dim == 1) {
      lua_pushinteger(L, values[0]);
    } else {
      values.toLUA(L);
    }
  } else {
    Array1D<Float> values(dim);
    glGetHistogramParameterfv(target, pname, values);
    if (dim == 1) {
      lua_pushnumber(L, values[0]);
    } else {
      values.toLUA(L);
    }
  }
  return 1;
}
static int lua_glGetMinmax(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Enum, Boolean, Enum, Enum, Ptr, glGetMinmax>::Call(L);
#else
  return WrapFunc5<Enum, Boolean, Enum, Enum, Ptr >::Call(L, glGetMinmax);
#endif
}
static int lua_glGetMinmaxParameter(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum target(L, 1);
  Enum pname(L, 2);
  bool integer = false;
  int dim = 0;
  switch (pname) {
    case GL_MINMAX_FORMAT:
    case GL_MINMAX_SINK:
      integer = true;
      dim = 1;
      break;
    default:
      break;
  }
  if (dim == 0) {
    luaL_error(L, "gl.GetMinmaxParameter: invalid parameter name");
  }
  if (integer) {
    Array1D<Int> values(dim);
    glGetMinmaxParameteriv(target, pname, values);
    if (dim == 1) {
      lua_pushinteger(L, values[0]);
    } else {
      values.toLUA(L);
    }
  } else {
    Array1D<Float> values(dim);
    glGetMinmaxParameterfv(target, pname, values);
    if (dim == 1) {
      lua_pushnumber(L, values[0]);
    } else {
      values.toLUA(L);
    }
  }
  return 1;
}
static int lua_glGetSeparableFilter(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc6<Enum, Enum, Enum, Ptr, Ptr, Ptr, glGetSeparableFilter>::Call(L);
#else
  return WrapFunc6<Enum, Enum, Enum, Ptr, Ptr, Ptr >::Call(L, glGetSeparableFilter);
#endif
}
static int lua_glHistogram(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Enum, Sizei, Enum, Boolean, glHistogram>::Call(L);
#else
  return WrapFunc4<Enum, Sizei, Enum, Boolean >::Call(L, glHistogram);
#endif
}
static int lua_glMinmax(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, Boolean, glMinmax>::Call(L);
#else
  return WrapFunc3<Enum, Enum, Boolean >::Call(L, glMinmax);
#endif
}
static int lua_glResetHistogram(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Enum, glResetHistogram>::Call(L);
#else
  return WrapFunc1<Enum >::Call(L, glResetHistogram);
#endif
}
static int lua_glResetMinmax(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Enum, glResetMinmax>::Call(L);
#else
  return WrapFunc1<Enum >::Call(L, glResetMinmax);
#endif
}
static int lua_glSeparableFilter2D(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc8<Enum, Enum, Sizei, Sizei, Enum, Enum, ConstPtr, ConstPtr, glSeparableFilter2D>::Call(L);
#else
  return WrapFunc8<Enum, Enum, Sizei, Sizei, Enum, Enum, ConstPtr, ConstPtr >::Call(L, glSeparableFilter2D);
#endif
}

// Register constants and functions to LUA

void Register_GL_ARB_Constants(LuaGL::ConstantMap &constants) {
  LuaGL &gl = LuaGL::Instance();

  if (GLEW_ARB_color_buffer_float) {
#ifdef _DEBUG
    std::cout << "Supports ARB color buffer float" << std::endl;
#endif
    constants["ARB_color_buffer_float"] = 1;
    constants["RGBA_FLOAT_MODE_ARB"] = GL_RGBA_FLOAT_MODE_ARB;
    constants["CLAMP_VERTEX_COLOR_ARB"] = GL_CLAMP_VERTEX_COLOR_ARB;
    constants["CLAMP_FRAGMENT_COLOR_ARB"] = GL_CLAMP_FRAGMENT_COLOR_ARB;
    constants["CLAMP_READ_COLOR_ARB"] = GL_CLAMP_READ_COLOR_ARB;
    constants["FIXED_ONLY_ARB"] = GL_FIXED_ONLY_ARB;
    gl.addParamDim(LuaGL::Integerv, GL_CLAMP_VERTEX_COLOR_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_CLAMP_FRAGMENT_COLOR_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_CLAMP_READ_COLOR_ARB, 1);
    gl.addParamDim(LuaGL::Booleanv, GL_RGBA_FLOAT_MODE_ARB, 1);
  } else {
    constants["ARB_color_buffer_float"] = 0;
  }

  if (GLEW_ARB_depth_texture) {
#ifdef _DEBUG
    std::cout << "Supports ARB depth texture" << std::endl;
#endif
    constants["ARB_depth_texture"] = 1;
    constants["DEPTH_COMPONENT16_ARB"] = GL_DEPTH_COMPONENT16_ARB;
    constants["DEPTH_COMPONENT24_ARB"] = GL_DEPTH_COMPONENT24_ARB;
    constants["DEPTH_COMPONENT32_ARB"] = GL_DEPTH_COMPONENT32_ARB;
    constants["TEXTURE_DEPTH_SIZE_ARB"] = GL_TEXTURE_DEPTH_SIZE_ARB;
    constants["DEPTH_TEXTURE_MODE_ARB"] = GL_DEPTH_TEXTURE_MODE_ARB;
    gl.addParamDim(LuaGL::TexLevelParameteriv, GL_TEXTURE_DEPTH_SIZE_ARB, 1);
    gl.addParamDim(LuaGL::TexParameteriv, GL_DEPTH_TEXTURE_MODE_ARB, 1);
  } else {
    constants["ARB_depth_texture"] = 0;
  }

  if (GLEW_ARB_draw_buffers) {
#ifdef _DEBUG
    std::cout << "Supports ARB draw buffers" << std::endl;
#endif
    constants["ARB_draw_buffers"] = 1;
    constants["MAX_DRAW_BUFFERS_ARB"] = GL_MAX_DRAW_BUFFERS_ARB;
    constants["DRAW_BUFFER0_ARB"] = GL_DRAW_BUFFER0_ARB;
    constants["DRAW_BUFFER1_ARB"] = GL_DRAW_BUFFER1_ARB;
    constants["DRAW_BUFFER2_ARB"] = GL_DRAW_BUFFER2_ARB;
    constants["DRAW_BUFFER3_ARB"] = GL_DRAW_BUFFER3_ARB;
    constants["DRAW_BUFFER4_ARB"] = GL_DRAW_BUFFER4_ARB;
    constants["DRAW_BUFFER5_ARB"] = GL_DRAW_BUFFER5_ARB;
    constants["DRAW_BUFFER6_ARB"] = GL_DRAW_BUFFER6_ARB;
    constants["DRAW_BUFFER7_ARB"] = GL_DRAW_BUFFER7_ARB;
    constants["DRAW_BUFFER8_ARB"] = GL_DRAW_BUFFER8_ARB;
    constants["DRAW_BUFFER9_ARB"] = GL_DRAW_BUFFER9_ARB;
    constants["DRAW_BUFFER10_ARB"] = GL_DRAW_BUFFER10_ARB;
    constants["DRAW_BUFFER11_ARB"] = GL_DRAW_BUFFER11_ARB;
    constants["DRAW_BUFFER12_ARB"] = GL_DRAW_BUFFER12_ARB;
    constants["DRAW_BUFFER13_ARB"] = GL_DRAW_BUFFER13_ARB;
    constants["DRAW_BUFFER14_ARB"] = GL_DRAW_BUFFER14_ARB;
    constants["DRAW_BUFFER15_ARB"] = GL_DRAW_BUFFER15_ARB;
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER0_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER1_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER2_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER3_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER4_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER5_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER6_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER7_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER8_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER9_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER10_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER11_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER12_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER13_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER14_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER15_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_DRAW_BUFFERS_ARB, 1);
  } else {
    constants["ARB_draw_buffers"] = 0;
  }

  if (GLEW_ARB_fragment_program) {
#ifdef _DEBUG
    std::cout << "Supports ARB fragment program" << std::endl;
#endif
    constants["ARB_fragment_program"] = 1;
    constants["FRAGMENT_PROGRAM_ARB"] = GL_FRAGMENT_PROGRAM_ARB;
    constants["PROGRAM_ALU_INSTRUCTIONS_ARB"] = GL_PROGRAM_ALU_INSTRUCTIONS_ARB;
    constants["PROGRAM_TEX_INSTRUCTIONS_ARB"] = GL_PROGRAM_TEX_INSTRUCTIONS_ARB;
    constants["PROGRAM_TEX_INDIRECTIONS_ARB"] = GL_PROGRAM_TEX_INDIRECTIONS_ARB;
    constants["PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB"] = GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB;
    constants["PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB"] = GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB;
    constants["PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB"] = GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB;
    constants["MAX_PROGRAM_ALU_INSTRUCTIONS_ARB"] = GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB;
    constants["MAX_PROGRAM_TEX_INSTRUCTIONS_ARB"] = GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB;
    constants["MAX_PROGRAM_TEX_INDIRECTIONS_ARB"] = GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB;
    constants["MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB"] = GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB;
    constants["MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB"] = GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB;
    constants["MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB"] = GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB;
    constants["MAX_TEXTURE_COORDS_ARB"] = GL_MAX_TEXTURE_COORDS_ARB;
    constants["MAX_TEXTURE_IMAGE_UNITS_ARB"] = GL_MAX_TEXTURE_IMAGE_UNITS_ARB;
    gl.addParamDim(LuaGL::Integerv, GL_MAX_TEXTURE_COORDS_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_TEXTURE_IMAGE_UNITS_ARB, 1);
  } else {
    constants["ARB_fragment_program"] = 0;
  }

  if (GLEW_ARB_fragment_program_shadow) {
#ifdef _DEBUG
    std::cout << "Supports ARB fragment program shadow" << std::endl;
#endif
    constants["ARB_fragment_program_shadow"] = 1;
  } else {
    constants["ARB_fragment_program_shadow"] = 0;
  }

  if (GLEW_ARB_fragment_shader) {
#ifdef _DEBUG
    std::cout << "Supports ARB fragment shader" << std::endl;
#endif
    constants["ARB_fragment_shader"] = 1;
    constants["FRAGMENT_SHADER_ARB"] = GL_FRAGMENT_SHADER_ARB;
    constants["MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB"] = GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB;
    constants["FRAGMENT_SHADER_DERIVATIVE_HINT_ARB"] = GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB;
    gl.addParamDim(LuaGL::Integerv, GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB, 1);
  } else {
    constants["ARB_fragment_shader"] = 0;
  }

  if (GLEW_ARB_half_float_pixel) {
#ifdef _DEBUG
    std::cout << "Supports ARB half float pixel" << std::endl;
#endif
    constants["ARB_half_float_pixel"] = 1;
    constants["HALF_FLOAT_ARB"] = GL_HALF_FLOAT_ARB;
  } else {
    constants["ARB_half_float_pixel"] = 0;
  }

  if (GLEW_ARB_matrix_palette) {
#ifdef _DEBUG
    std::cout << "Supports ARB matrix palette" << std::endl;
#endif
    constants["ARB_matrix_palette"] = 1;
    constants["MATRIX_PALETTE_ARB"] = GL_MATRIX_PALETTE_ARB;
    constants["MAX_MATRIX_PALETTE_STACK_DEPTH_ARB"] = GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB;
    constants["MAX_PALETTE_MATRICES_ARB"] = GL_MAX_PALETTE_MATRICES_ARB;
    constants["CURRENT_PALETTE_MATRIX_ARB"] = GL_CURRENT_PALETTE_MATRIX_ARB;
    constants["MATRIX_INDEX_ARRAY_ARB"] = GL_MATRIX_INDEX_ARRAY_ARB;
    constants["CURRENT_MATRIX_INDEX_ARB"] = GL_CURRENT_MATRIX_INDEX_ARB;
    constants["MATRIX_INDEX_ARRAY_SIZE_ARB"] = GL_MATRIX_INDEX_ARRAY_SIZE_ARB;
    constants["MATRIX_INDEX_ARRAY_TYPE_ARB"] = GL_MATRIX_INDEX_ARRAY_TYPE_ARB;
    constants["MATRIX_INDEX_ARRAY_STRIDE_ARB"] = GL_MATRIX_INDEX_ARRAY_STRIDE_ARB;
    constants["MATRIX_INDEX_ARRAY_POINTER_ARB"] = GL_MATRIX_INDEX_ARRAY_POINTER_ARB;
    gl.addParamDim(LuaGL::Integerv, GL_CURRENT_MATRIX_INDEX_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MATRIX_INDEX_ARRAY_SIZE_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MATRIX_INDEX_ARRAY_TYPE_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MATRIX_INDEX_ARRAY_STRIDE_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_CURRENT_PALETTE_MATRIX_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_PALETTE_MATRICES_ARB, 1);
    gl.addParamDim(LuaGL::Floatv, GL_MATRIX_PALETTE_ARB, 16);
  } else {
    constants["ARB_matrix_palette"] = 0;
  }

  if (GLEW_ARB_multisample) {
#ifdef _DEBUG
    std::cout << "Supports ARB multisample" << std::endl;
#endif
    constants["ARB_multisample"] = 1;
    constants["MULTISAMPLE_ARB"] = GL_MULTISAMPLE_ARB;
    constants["SAMPLE_ALPHA_TO_COVERAGE_ARB"] = GL_SAMPLE_ALPHA_TO_COVERAGE_ARB;
    constants["SAMPLE_ALPHA_TO_ONE_ARB"] = GL_SAMPLE_ALPHA_TO_ONE_ARB;
    constants["SAMPLE_COVERAGE_ARB"] = GL_SAMPLE_COVERAGE_ARB;
    constants["SAMPLE_BUFFERS_ARB"] = GL_SAMPLE_BUFFERS_ARB;
    constants["SAMPLES_ARB"] = GL_SAMPLES_ARB;
    constants["SAMPLE_COVERAGE_VALUE_ARB"] = GL_SAMPLE_COVERAGE_VALUE_ARB;
    constants["SAMPLE_COVERAGE_INVERT_ARB"] = GL_SAMPLE_COVERAGE_INVERT_ARB;
    constants["MULTISAMPLE_BIT_ARB"] = GL_MULTISAMPLE_BIT_ARB;
    gl.addParamDim(LuaGL::Floatv, GL_SAMPLE_COVERAGE_VALUE_ARB, 1);
    gl.addParamDim(LuaGL::Booleanv, GL_SAMPLE_COVERAGE_INVERT_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_SAMPLE_BUFFERS_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_SAMPLES_ARB, 1);
  } else {
    constants["ARB_multisample"] = 0;
  }

  if (GLEW_ARB_multitexture) {
#ifdef _DEBUG
    std::cout << "Supports ARB multitexture" << std::endl;
#endif
    constants["ARB_multitexture"] = 1;
    constants["TEXTURE0_ARB"] = GL_TEXTURE0_ARB;
    constants["TEXTURE1_ARB"] = GL_TEXTURE1_ARB;
    constants["TEXTURE2_ARB"] = GL_TEXTURE2_ARB;
    constants["TEXTURE3_ARB"] = GL_TEXTURE3_ARB;
    constants["TEXTURE4_ARB"] = GL_TEXTURE4_ARB;
    constants["TEXTURE5_ARB"] = GL_TEXTURE5_ARB;
    constants["TEXTURE6_ARB"] = GL_TEXTURE6_ARB;
    constants["TEXTURE7_ARB"] = GL_TEXTURE7_ARB;
    constants["TEXTURE8_ARB"] = GL_TEXTURE8_ARB;
    constants["TEXTURE9_ARB"] = GL_TEXTURE9_ARB;
    constants["TEXTURE10_ARB"] = GL_TEXTURE10_ARB;
    constants["TEXTURE11_ARB"] = GL_TEXTURE11_ARB;
    constants["TEXTURE12_ARB"] = GL_TEXTURE12_ARB;
    constants["TEXTURE13_ARB"] = GL_TEXTURE13_ARB;
    constants["TEXTURE14_ARB"] = GL_TEXTURE14_ARB;
    constants["TEXTURE15_ARB"] = GL_TEXTURE15_ARB;
    constants["TEXTURE16_ARB"] = GL_TEXTURE16_ARB;
    constants["TEXTURE17_ARB"] = GL_TEXTURE17_ARB;
    constants["TEXTURE18_ARB"] = GL_TEXTURE18_ARB;
    constants["TEXTURE19_ARB"] = GL_TEXTURE19_ARB;
    constants["TEXTURE20_ARB"] = GL_TEXTURE20_ARB;
    constants["TEXTURE21_ARB"] = GL_TEXTURE21_ARB;
    constants["TEXTURE22_ARB"] = GL_TEXTURE22_ARB;
    constants["TEXTURE23_ARB"] = GL_TEXTURE23_ARB;
    constants["TEXTURE24_ARB"] = GL_TEXTURE24_ARB;
    constants["TEXTURE25_ARB"] = GL_TEXTURE25_ARB;
    constants["TEXTURE26_ARB"] = GL_TEXTURE26_ARB;
    constants["TEXTURE27_ARB"] = GL_TEXTURE27_ARB;
    constants["TEXTURE28_ARB"] = GL_TEXTURE28_ARB;
    constants["TEXTURE29_ARB"] = GL_TEXTURE29_ARB;
    constants["TEXTURE30_ARB"] = GL_TEXTURE30_ARB;
    constants["TEXTURE31_ARB"] = GL_TEXTURE31_ARB;
    constants["ACTIVE_TEXTURE_ARB"] = GL_ACTIVE_TEXTURE_ARB;
    constants["CLIENT_ACTIVE_TEXTURE_ARB"] = GL_CLIENT_ACTIVE_TEXTURE_ARB;
    constants["MAX_TEXTURE_UNITS_ARB"] = GL_MAX_TEXTURE_UNITS_ARB;
    gl.addParamDim(LuaGL::Integerv, GL_MAX_TEXTURE_UNITS_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_ACTIVE_TEXTURE_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_CLIENT_ACTIVE_TEXTURE_ARB, 1);
  } else {
    constants["ARB_multitexture"] = 0;
  }

  if (GLEW_ARB_occlusion_query) {
#ifdef _DEBUG
    std::cout << "Supports ARB occlusion query" << std::endl;
#endif
    constants["ARB_occlusion_query"] = 1;
    constants["QUERY_COUNTER_BITS_ARB"] = GL_QUERY_COUNTER_BITS_ARB;
    constants["CURRENT_QUERY_ARB"] = GL_CURRENT_QUERY_ARB;
    constants["QUERY_RESULT_ARB"] = GL_QUERY_RESULT_ARB;
    constants["QUERY_RESULT_AVAILABLE_ARB"] = GL_QUERY_RESULT_AVAILABLE_ARB;
    constants["SAMPLES_PASSED_ARB"] = GL_SAMPLES_PASSED_ARB;
  } else {
    constants["ARB_occlusion_query"] = 0;
  }

  if (GLEW_ARB_pixel_buffer_object) {
#ifdef _DEBUG
    std::cout << "Supports ARB pixel buffer object" << std::endl;
#endif
    constants["ARB_pixel_buffer_object"] = 1;
    constants["PIXEL_PACK_BUFFER_ARB"] = GL_PIXEL_PACK_BUFFER_ARB;
    constants["PIXEL_UNPACK_BUFFER_ARB"] = GL_PIXEL_UNPACK_BUFFER_ARB;
    constants["PIXEL_PACK_BUFFER_BINDING_ARB"] = GL_PIXEL_PACK_BUFFER_BINDING_ARB;
    constants["PIXEL_UNPACK_BUFFER_BINDING_ARB"] = GL_PIXEL_UNPACK_BUFFER_BINDING_ARB;
    gl.addParamDim(LuaGL::Integerv, GL_PIXEL_PACK_BUFFER_BINDING_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_PIXEL_UNPACK_BUFFER_BINDING_ARB, 1);
  } else {
    constants["ARB_pixel_buffer_object"] = 0;
  }

  if (GLEW_ARB_point_parameters) {
#ifdef _DEBUG
    std::cout << "Supports ARB point parameters" << std::endl;
#endif
    constants["ARB_point_parameters"] = 1;
    constants["POINT_SIZE_MIN_ARB"] = GL_POINT_SIZE_MIN_ARB;
    constants["POINT_SIZE_MAX_ARB"] = GL_POINT_SIZE_MAX_ARB;
    constants["POINT_FADE_THRESHOLD_SIZE_ARB"] = GL_POINT_FADE_THRESHOLD_SIZE_ARB;
    constants["POINT_DISTANCE_ATTENUATION_ARB"] = GL_POINT_DISTANCE_ATTENUATION_ARB;
    gl.addParamDim(LuaGL::Floatv, GL_POINT_SIZE_MIN_ARB, 1);
    gl.addParamDim(LuaGL::Floatv, GL_POINT_SIZE_MAX_ARB, 1);
    gl.addParamDim(LuaGL::Floatv, GL_POINT_FADE_THRESHOLD_SIZE_ARB, 1);
    gl.addParamDim(LuaGL::Floatv, GL_POINT_DISTANCE_ATTENUATION_ARB, 3);
  } else {
    constants["ARB_point_parameters"] = 0;
  }

  if (GLEW_ARB_point_sprite) {
#ifdef _DEBUG
    std::cout << "Supports ARB point sprite" << std::endl;
#endif
    constants["ARB_point_sprite"] = 1;
    constants["POINT_SPRITE_ARB"] = GL_POINT_SPRITE_ARB;
    constants["COORD_REPLACE_ARB"] = GL_COORD_REPLACE_ARB;
    gl.addParamDim(LuaGL::TexEnviv, GL_COORD_REPLACE_ARB, 1);
  } else {
    constants["ARB_point_sprite"] = 0;
  }

  if (GLEW_ARB_shader_objects) {
#ifdef _DEBUG
    std::cout << "Supports ARB shader objects" << std::endl;
#endif
    constants["ARB_shader_objects"] = 1;
    constants["PROGRAM_OBJECT_ARB"] = GL_PROGRAM_OBJECT_ARB;
    constants["SHADER_OBJECT_ARB"] = GL_SHADER_OBJECT_ARB;
    constants["OBJECT_TYPE_ARB"] = GL_OBJECT_TYPE_ARB;
    constants["OBJECT_SUBTYPE_ARB"] = GL_OBJECT_SUBTYPE_ARB;
    constants["FLOAT_VEC2_ARB"] = GL_FLOAT_VEC2_ARB;
    constants["FLOAT_VEC3_ARB"] = GL_FLOAT_VEC3_ARB;
    constants["FLOAT_VEC4_ARB"] = GL_FLOAT_VEC4_ARB;
    constants["INT_VEC2_ARB"] = GL_INT_VEC2_ARB;
    constants["INT_VEC3_ARB"] = GL_INT_VEC3_ARB;
    constants["INT_VEC4_ARB"] = GL_INT_VEC4_ARB;
    constants["BOOL_ARB"] = GL_BOOL_ARB;
    constants["BOOL_VEC2_ARB"] = GL_BOOL_VEC2_ARB;
    constants["BOOL_VEC3_ARB"] = GL_BOOL_VEC3_ARB;
    constants["BOOL_VEC4_ARB"] = GL_BOOL_VEC4_ARB;
    constants["FLOAT_MAT2_ARB"] = GL_FLOAT_MAT2_ARB;
    constants["FLOAT_MAT3_ARB"] = GL_FLOAT_MAT3_ARB;
    constants["FLOAT_MAT4_ARB"] = GL_FLOAT_MAT4_ARB;
    constants["SAMPLER_1D_ARB"] = GL_SAMPLER_1D_ARB;
    constants["SAMPLER_2D_ARB"] = GL_SAMPLER_2D_ARB;
    constants["SAMPLER_3D_ARB"] = GL_SAMPLER_3D_ARB;
    constants["SAMPLER_CUBE_ARB"] = GL_SAMPLER_CUBE_ARB;
    constants["SAMPLER_1D_SHADOW_ARB"] = GL_SAMPLER_1D_SHADOW_ARB;
    constants["SAMPLER_2D_SHADOW_ARB"] = GL_SAMPLER_2D_SHADOW_ARB;
    constants["SAMPLER_2D_RECT_ARB"] = GL_SAMPLER_2D_RECT_ARB;
    constants["SAMPLER_2D_RECT_SHADOW_ARB"] = GL_SAMPLER_2D_RECT_SHADOW_ARB;
    constants["OBJECT_DELETE_STATUS_ARB"] = GL_OBJECT_DELETE_STATUS_ARB;
    constants["OBJECT_COMPILE_STATUS_ARB"] = GL_OBJECT_COMPILE_STATUS_ARB;
    constants["OBJECT_LINK_STATUS_ARB"] = GL_OBJECT_LINK_STATUS_ARB;
    constants["OBJECT_VALIDATE_STATUS_ARB"] = GL_OBJECT_VALIDATE_STATUS_ARB;
    constants["OBJECT_INFO_LOG_LENGTH_ARB"] = GL_OBJECT_INFO_LOG_LENGTH_ARB;
    constants["OBJECT_ATTACHED_OBJECTS_ARB"] = GL_OBJECT_ATTACHED_OBJECTS_ARB;
    constants["OBJECT_ACTIVE_UNIFORMS_ARB"] = GL_OBJECT_ACTIVE_UNIFORMS_ARB;
    constants["OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB"] = GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB;
    constants["OBJECT_SHADER_SOURCE_LENGTH_ARB"] = GL_OBJECT_SHADER_SOURCE_LENGTH_ARB;
  } else {
    constants["ARB_shader_objects"] = 0;
  }

  if (GLEW_ARB_shading_language_100) {
#ifdef _DEBUG
    std::cout << "Supports ARB shading language 100" << std::endl;
#endif
    constants["ARB_shading_language_100"] = 1;
    constants["SHADING_LANGUAGE_VERSION_ARB"] = GL_SHADING_LANGUAGE_VERSION_ARB;
  } else {
    constants["ARB_shading_language_100"] = 1;
  }

  if (GLEW_ARB_shadow) {
#ifdef _DEBUG
    std::cout << "Supports ARB shadow" << std::endl;
#endif
    constants["ARB_shadow"] = 0;
    constants["TEXTURE_COMPARE_MODE_ARB"] = GL_TEXTURE_COMPARE_MODE_ARB;
    constants["TEXTURE_COMPARE_FUNC_ARB"] = GL_TEXTURE_COMPARE_FUNC_ARB;
    constants["COMPARE_R_TO_TEXTURE_ARB"] = GL_COMPARE_R_TO_TEXTURE_ARB;
    gl.addParamDim(LuaGL::TexParameteriv, GL_TEXTURE_COMPARE_MODE_ARB, 1);
    gl.addParamDim(LuaGL::TexParameteriv, GL_TEXTURE_COMPARE_FUNC_ARB, 1);
  } else {
    constants["ARB_shadow"] = 0;
  }

  if (GLEW_ARB_shadow_ambient) {
#ifdef _DEBUG
    std::cout << "Supports ARB shadow ambient" << std::endl;
#endif
    constants["ARB_shadow_ambient"] = 1;
    constants["TEXTURE_COMPARE_FAIL_VALUE_ARB"] = GL_TEXTURE_COMPARE_FAIL_VALUE_ARB;
    gl.addParamDim(LuaGL::TexParameterfv, GL_TEXTURE_COMPARE_FAIL_VALUE_ARB, 1);
  } else {
    constants["ARB_shadow_ambient"] = 0;
  }

  if (GLEW_ARB_texture_border_clamp) {
#ifdef _DEBUG
    std::cout << "Supports ARB texture border clamp" << std::endl;
#endif
    constants["ARB_texture_border_clamp"] = 1;
    constants["CLAMP_TO_BORDER_ARB"] = GL_CLAMP_TO_BORDER_ARB;
  } else {
    constants["ARB_texture_border_clamp"] = 0;
  }

  if (GLEW_ARB_texture_compression) {
#ifdef _DEBUG
    std::cout << "Supports ARB texture compression" << std::endl;
#endif
    constants["ARB_texture_compression"] = 1;
    constants["COMPRESSED_ALPHA_ARB"] = GL_COMPRESSED_ALPHA_ARB;
    constants["COMPRESSED_LUMINANCE_ARB"] = GL_COMPRESSED_LUMINANCE_ARB;
    constants["COMPRESSED_LUMINANCE_ALPHA_ARB"] = GL_COMPRESSED_LUMINANCE_ALPHA_ARB;
    constants["COMPRESSED_INTENSITY_ARB"] = GL_COMPRESSED_INTENSITY_ARB;
    constants["COMPRESSED_RGB_ARB"] = GL_COMPRESSED_RGB_ARB;
    constants["COMPRESSED_RGBA_ARB"] = GL_COMPRESSED_RGBA_ARB;
    constants["TEXTURE_COMPRESSION_HINT_ARB"] = GL_TEXTURE_COMPRESSION_HINT_ARB;
    constants["TEXTURE_COMPRESSED_IMAGE_SIZE_ARB"] = GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB;
    constants["TEXTURE_COMPRESSED_ARB"] = GL_TEXTURE_COMPRESSED_ARB;
    constants["NUM_COMPRESSED_TEXTURE_FORMATS_ARB"] = GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB;
    constants["COMPRESSED_TEXTURE_FORMATS_ARB"] = GL_COMPRESSED_TEXTURE_FORMATS_ARB;
    gl.addParamDim(LuaGL::TexLevelParameteriv, GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB, 1);
    gl.addParamDim(LuaGL::TexLevelParameteriv, GL_TEXTURE_COMPRESSED_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_TEXTURE_COMPRESSION_HINT_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB, 1);
    gl.addDependentParamDim(LuaGL::Integerv, GL_COMPRESSED_TEXTURE_FORMATS_ARB, GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB);
  } else {
    constants["ARB_texture_compression"] = 0;
  }

  if (GLEW_ARB_texture_cube_map) {
#ifdef _DEBUG
    std::cout << "Supports ARB texture cube map" << std::endl;
#endif
    constants["ARB_texture_cube_map"] = 1;
    constants["NORMAL_MAP_ARB"] = GL_NORMAL_MAP_ARB;
    constants["REFLECTION_MAP_ARB"] = GL_REFLECTION_MAP_ARB;
    constants["TEXTURE_CUBE_MAP_ARB"] = GL_TEXTURE_CUBE_MAP_ARB;
    constants["TEXTURE_BINDING_CUBE_MAP_ARB"] = GL_TEXTURE_BINDING_CUBE_MAP_ARB;
    constants["TEXTURE_CUBE_MAP_POSITIVE_X_ARB"] = GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB;
    constants["TEXTURE_CUBE_MAP_NEGATIVE_X_ARB"] = GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB;
    constants["TEXTURE_CUBE_MAP_POSITIVE_Y_ARB"] = GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB;
    constants["TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB"] = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB;
    constants["TEXTURE_CUBE_MAP_POSITIVE_Z_ARB"] = GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB;
    constants["TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB"] = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB;
    constants["PROXY_TEXTURE_CUBE_MAP_ARB"] = GL_PROXY_TEXTURE_CUBE_MAP_ARB;
    constants["MAX_CUBE_MAP_TEXTURE_SIZE_ARB"] = GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB;
    gl.addParamDim(LuaGL::Integerv, GL_TEXTURE_BINDING_CUBE_MAP_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB, 1);
  } else {
    constants["ARB_texture_cube_map"] = 0;
  }

  if (GLEW_ARB_texture_env_add) {
#ifdef _DEBUG
    std::cout << "Supports ARB texture env add" << std::endl;
#endif
    constants["ARB_texture_env_add"] = 1;
  } else {
    constants["ARB_texture_env_add"] = 0;
  }

  if (GLEW_ARB_texture_env_combine) {
#ifdef _DEBUG
    std::cout << "Supports ARB texture env combine" << std::endl;
#endif
    constants["ARB_texture_env_combine"] = 1;
    constants["SUBTRACT_ARB"] = GL_SUBTRACT_ARB;
    constants["COMBINE_ARB"] = GL_COMBINE_ARB;
    constants["COMBINE_RGB_ARB"] = GL_COMBINE_RGB_ARB;
    constants["COMBINE_ALPHA_ARB"] = GL_COMBINE_ALPHA_ARB;
    constants["RGB_SCALE_ARB"] = GL_RGB_SCALE_ARB;
    constants["ADD_SIGNED_ARB"] = GL_ADD_SIGNED_ARB;
    constants["INTERPOLATE_ARB"] = GL_INTERPOLATE_ARB;
    constants["CONSTANT_ARB"] = GL_CONSTANT_ARB;
    constants["PRIMARY_COLOR_ARB"] = GL_PRIMARY_COLOR_ARB;
    constants["PREVIOUS_ARB"] = GL_PREVIOUS_ARB;
    constants["SOURCE0_RGB_ARB"] = GL_SOURCE0_RGB_ARB;
    constants["SOURCE1_RGB_ARB"] = GL_SOURCE1_RGB_ARB;
    constants["SOURCE2_RGB_ARB"] = GL_SOURCE2_RGB_ARB;
    constants["SOURCE0_ALPHA_ARB"] = GL_SOURCE0_ALPHA_ARB;
    constants["SOURCE1_ALPHA_ARB"] = GL_SOURCE1_ALPHA_ARB;
    constants["SOURCE2_ALPHA_ARB"] = GL_SOURCE2_ALPHA_ARB;
    constants["OPERAND0_RGB_ARB"] = GL_OPERAND0_RGB_ARB;
    constants["OPERAND1_RGB_ARB"] = GL_OPERAND1_RGB_ARB;
    constants["OPERAND2_RGB_ARB"] = GL_OPERAND2_RGB_ARB;
    constants["OPERAND0_ALPHA_ARB"] = GL_OPERAND0_ALPHA_ARB;
    constants["OPERAND1_ALPHA_ARB"] = GL_OPERAND1_ALPHA_ARB;
    constants["OPERAND2_ALPHA_ARB"] = GL_OPERAND2_ALPHA_ARB;
    gl.addParamDim(LuaGL::TexEnviv, GL_COMBINE_RGB_ARB, 1);
    gl.addParamDim(LuaGL::TexEnviv, GL_COMBINE_ALPHA_ARB, 1);
    gl.addParamDim(LuaGL::TexEnviv, GL_SOURCE0_RGB_ARB, 1);
    gl.addParamDim(LuaGL::TexEnviv, GL_SOURCE1_RGB_ARB, 1);
    gl.addParamDim(LuaGL::TexEnviv, GL_SOURCE2_RGB_ARB, 1);
    gl.addParamDim(LuaGL::TexEnviv, GL_SOURCE0_ALPHA_ARB, 1);
    gl.addParamDim(LuaGL::TexEnviv, GL_SOURCE1_ALPHA_ARB, 1);
    gl.addParamDim(LuaGL::TexEnviv, GL_SOURCE2_ALPHA_ARB, 1);
    gl.addParamDim(LuaGL::TexEnviv, GL_OPERAND0_RGB_ARB, 1);
    gl.addParamDim(LuaGL::TexEnviv, GL_OPERAND1_RGB_ARB, 1);
    gl.addParamDim(LuaGL::TexEnviv, GL_OPERAND2_RGB_ARB, 1);
    gl.addParamDim(LuaGL::TexEnviv, GL_OPERAND0_ALPHA_ARB, 1);
    gl.addParamDim(LuaGL::TexEnviv, GL_OPERAND1_ALPHA_ARB, 1);
    gl.addParamDim(LuaGL::TexEnviv, GL_OPERAND2_ALPHA_ARB, 1);
    gl.addParamDim(LuaGL::TexEnvfv, GL_RGB_SCALE_ARB, 1);
    gl.addParamDim(LuaGL::TexEnvfv, GL_ALPHA_SCALE, 1);
  } else {
    constants["ARB_texture_env_combine"] = 0;
  }

  if (GLEW_ARB_texture_env_crossbar) {
#ifdef _DEBUG
    std::cout << "Supports ARB texture env crossbar" << std::endl;
#endif
    constants["ARB_texture_env_crossbar"] = 1;
  } else {
    constants["ARB_texture_env_crossbar"] = 0;
  }

  if (GLEW_ARB_texture_env_dot3) {
#ifdef _DEBUG
    std::cout << "Supports ARB texture env dot3" << std::endl;
#endif
    constants["ARB_texture_env_dot3"] = 1;
    constants["DOT3_RGB_ARB"] = GL_DOT3_RGB_ARB;
    constants["DOT3_RGBA_ARB"] = GL_DOT3_RGBA_ARB;
  } else {
    constants["ARB_texture_env_dot3"] = 0;
  }

  if (GLEW_ARB_texture_float) {
#ifdef _DEBUG
    std::cout << "Supports ARB texture float" << std::endl;
#endif
    constants["ARB_texture_float"] = 1;
    constants["RGBA32F_ARB"] = GL_RGBA32F_ARB;
    constants["RGB32F_ARB"] = GL_RGB32F_ARB;
    constants["ALPHA32F_ARB"] = GL_ALPHA32F_ARB;
    constants["INTENSITY32F_ARB"] = GL_INTENSITY32F_ARB;
    constants["LUMINANCE32F_ARB"] = GL_LUMINANCE32F_ARB;
    constants["LUMINANCE_ALPHA32F_ARB"] = GL_LUMINANCE_ALPHA32F_ARB;
    constants["RGBA16F_ARB"] = GL_RGBA16F_ARB;
    constants["RGB16F_ARB"] = GL_RGB16F_ARB;
    constants["ALPHA16F_ARB"] = GL_ALPHA16F_ARB;
    constants["INTENSITY16F_ARB"] = GL_INTENSITY16F_ARB;
    constants["LUMINANCE16F_ARB"] = GL_LUMINANCE16F_ARB;
    constants["LUMINANCE_ALPHA16F_ARB"] = GL_LUMINANCE_ALPHA16F_ARB;
    constants["TEXTURE_RED_TYPE_ARB"] = GL_TEXTURE_RED_TYPE_ARB;
    constants["TEXTURE_GREEN_TYPE_ARB"] = GL_TEXTURE_GREEN_TYPE_ARB;
    constants["TEXTURE_BLUE_TYPE_ARB"] = GL_TEXTURE_BLUE_TYPE_ARB;
    constants["TEXTURE_ALPHA_TYPE_ARB"] = GL_TEXTURE_ALPHA_TYPE_ARB;
    constants["TEXTURE_LUMINANCE_TYPE_ARB"] = GL_TEXTURE_LUMINANCE_TYPE_ARB;
    constants["TEXTURE_INTENSITY_TYPE_ARB"] = GL_TEXTURE_INTENSITY_TYPE_ARB;
    constants["TEXTURE_DEPTH_TYPE_ARB"] = GL_TEXTURE_DEPTH_TYPE_ARB;
    constants["UNSIGNED_NORMALIZED_ARB"] = GL_UNSIGNED_NORMALIZED_ARB;
    gl.addParamDim(LuaGL::TexLevelParameteriv, GL_TEXTURE_RED_TYPE_ARB, 1);
    gl.addParamDim(LuaGL::TexLevelParameteriv, GL_TEXTURE_GREEN_TYPE_ARB, 1);
    gl.addParamDim(LuaGL::TexLevelParameteriv, GL_TEXTURE_BLUE_TYPE_ARB, 1);
    gl.addParamDim(LuaGL::TexLevelParameteriv, GL_TEXTURE_ALPHA_TYPE_ARB, 1);
    gl.addParamDim(LuaGL::TexLevelParameteriv, GL_TEXTURE_LUMINANCE_TYPE_ARB, 1);
    gl.addParamDim(LuaGL::TexLevelParameteriv, GL_TEXTURE_INTENSITY_TYPE_ARB, 1);
    gl.addParamDim(LuaGL::TexLevelParameteriv, GL_TEXTURE_DEPTH_TYPE_ARB, 1);
  } else {
    constants["ARB_texture_float"] = 0;
  }

  if (GLEW_ARB_texture_mirrored_repeat) {
#ifdef _DEBUG
    std::cout << "Supports ARB texture mirrored repeat" << std::endl;
#endif
    constants["ARB_texture_mirrored_repeat"] = 1;
    constants["MIRRORED_REPEAT_ARB"] = GL_MIRRORED_REPEAT_ARB;
  } else {
    constants["ARB_texture_mirrored_repeat"] = 0;
  }

  if (GLEW_ARB_texture_non_power_of_two) {
#ifdef _DEBUG
    std::cout << "Supports ARB texture npot" << std::endl;
#endif
    constants["ARB_texture_non_power_of_two"] = 1;
  } else {
    constants["ARB_texture_non_power_of_two"] = 0;
  }

  if (GLEW_ARB_texture_rectangle) {
#ifdef _DEBUG
    std::cout << "Supports ARB texture rectangle" << std::endl;
#endif
    constants["ARB_texture_rectangle"] = 1;
    constants["TEXTURE_RECTANGLE_ARB"] = GL_TEXTURE_RECTANGLE_ARB;
    constants["TEXTURE_BINDING_RECTANGLE_ARB"] = GL_TEXTURE_BINDING_RECTANGLE_ARB;
    constants["PROXY_TEXTURE_RECTANGLE_ARB"] = GL_PROXY_TEXTURE_RECTANGLE_ARB;
    constants["MAX_RECTANGLE_TEXTURE_SIZE_ARB"] = GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB;
    constants["SAMPLER_2D_RECT_ARB"] = GL_SAMPLER_2D_RECT_ARB;
    constants["SAMPLER_2D_RECT_SHADOW_ARB"] = GL_SAMPLER_2D_RECT_SHADOW_ARB;
    gl.addParamDim(LuaGL::Integerv, GL_TEXTURE_BINDING_RECTANGLE_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB, 1);
  } else {
    constants["ARB_texture_rectangle"] = 0;
  }

  if (GLEW_ARB_transpose_matrix) {
#ifdef _DEBUG
    std::cout << "Supports ARB transpose matrix" << std::endl;
#endif
    constants["ARB_transpose_matrix"] = 1;
    constants["TRANSPOSE_MODELVIEW_MATRIX_ARB"] = GL_TRANSPOSE_MODELVIEW_MATRIX_ARB;
    constants["TRANSPOSE_PROJECTION_MATRIX_ARB"] = GL_TRANSPOSE_PROJECTION_MATRIX_ARB;
    constants["TRANSPOSE_TEXTURE_MATRIX_ARB"] = GL_TRANSPOSE_TEXTURE_MATRIX_ARB;
    constants["TRANSPOSE_COLOR_MATRIX_ARB"] = GL_TRANSPOSE_COLOR_MATRIX_ARB;
  } else {
    constants["ARB_transpose_matrix"] = 0;
  }

  if (GLEW_ARB_vertex_blend) {
#ifdef _DEBUG
    std::cout << "Supports ARB vertex blend" << std::endl;
#endif
    constants["ARB_vertex_blend"] = 1;
    constants["MAX_VERTEX_UNITS_ARB"] = GL_MAX_VERTEX_UNITS_ARB;
    constants["ACTIVE_VERTEX_UNITS_ARB"] = GL_ACTIVE_VERTEX_UNITS_ARB;
    constants["WEIGHT_SUM_UNITY_ARB"] = GL_WEIGHT_SUM_UNITY_ARB;
    constants["VERTEX_BLEND_ARB"] = GL_VERTEX_BLEND_ARB;
    constants["CURRENT_WEIGHT_ARB"] = GL_CURRENT_WEIGHT_ARB;
    constants["WEIGHT_ARRAY_TYPE_ARB"] = GL_WEIGHT_ARRAY_TYPE_ARB;
    constants["WEIGHT_ARRAY_STRIDE_ARB"] = GL_WEIGHT_ARRAY_STRIDE_ARB;
    constants["WEIGHT_ARRAY_SIZE_ARB"] = GL_WEIGHT_ARRAY_SIZE_ARB;
    constants["WEIGHT_ARRAY_POINTER_ARB"] = GL_WEIGHT_ARRAY_POINTER_ARB;
    constants["WEIGHT_ARRAY_ARB"] = GL_WEIGHT_ARRAY_ARB;
    constants["MODELVIEW0_ARB"] = GL_MODELVIEW0_ARB;
    constants["MODELVIEW1_ARB"] = GL_MODELVIEW1_ARB;
    constants["MODELVIEW2_ARB"] = GL_MODELVIEW2_ARB;
    constants["MODELVIEW3_ARB"] = GL_MODELVIEW3_ARB;
    constants["MODELVIEW4_ARB"] = GL_MODELVIEW4_ARB;
    constants["MODELVIEW5_ARB"] = GL_MODELVIEW5_ARB;
    constants["MODELVIEW6_ARB"] = GL_MODELVIEW6_ARB;
    constants["MODELVIEW7_ARB"] = GL_MODELVIEW7_ARB;
    constants["MODELVIEW8_ARB"] = GL_MODELVIEW8_ARB;
    constants["MODELVIEW9_ARB"] = GL_MODELVIEW9_ARB;
    constants["MODELVIEW10_ARB"] = GL_MODELVIEW10_ARB;
    constants["MODELVIEW11_ARB"] = GL_MODELVIEW11_ARB;
    constants["MODELVIEW12_ARB"] = GL_MODELVIEW12_ARB;
    constants["MODELVIEW13_ARB"] = GL_MODELVIEW13_ARB;
    constants["MODELVIEW14_ARB"] = GL_MODELVIEW14_ARB;
    constants["MODELVIEW15_ARB"] = GL_MODELVIEW15_ARB;
    constants["MODELVIEW16_ARB"] = GL_MODELVIEW16_ARB;
    constants["MODELVIEW17_ARB"] = GL_MODELVIEW17_ARB;
    constants["MODELVIEW18_ARB"] = GL_MODELVIEW18_ARB;
    constants["MODELVIEW19_ARB"] = GL_MODELVIEW19_ARB;
    constants["MODELVIEW20_ARB"] = GL_MODELVIEW20_ARB;
    constants["MODELVIEW21_ARB"] = GL_MODELVIEW21_ARB;
    constants["MODELVIEW22_ARB"] = GL_MODELVIEW22_ARB;
    constants["MODELVIEW23_ARB"] = GL_MODELVIEW23_ARB;
    constants["MODELVIEW24_ARB"] = GL_MODELVIEW24_ARB;
    constants["MODELVIEW25_ARB"] = GL_MODELVIEW25_ARB;
    constants["MODELVIEW26_ARB"] = GL_MODELVIEW26_ARB;
    constants["MODELVIEW27_ARB"] = GL_MODELVIEW27_ARB;
    constants["MODELVIEW28_ARB"] = GL_MODELVIEW28_ARB;
    constants["MODELVIEW29_ARB"] = GL_MODELVIEW29_ARB;
    constants["MODELVIEW30_ARB"] = GL_MODELVIEW30_ARB;
    constants["MODELVIEW31_ARB"] = GL_MODELVIEW31_ARB;
    gl.addParamDim(LuaGL::Integerv, GL_WEIGHT_ARRAY_TYPE_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_WEIGHT_ARRAY_SIZE_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_WEIGHT_ARRAY_STRIDE_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_ACTIVE_VERTEX_UNITS_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_VERTEX_UNITS_ARB, 1);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW0_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW1_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW2_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW3_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW4_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW5_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW6_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW7_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW8_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW9_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW10_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW11_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW12_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW13_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW14_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW15_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW16_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW17_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW18_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW19_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW20_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW21_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW22_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW23_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW24_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW25_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW26_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW27_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW28_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW29_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW30_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW31_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_CURRENT_WEIGHT_ARB, 1);
  } else {
    constants["ARB_vertex_blend"] = 0;
  }

  if (GLEW_ARB_vertex_buffer_object) {
#ifdef _DEBUG
    std::cout << "Supports ARB vertex buffer object" << std::endl;
#endif
    constants["ARB_vertex_buffer_object"] = 1;
    constants["BUFFER_SIZE_ARB"] = GL_BUFFER_SIZE_ARB;
    constants["BUFFER_USAGE_ARB"] = GL_BUFFER_USAGE_ARB;
    constants["ARRAY_BUFFER_ARB"] = GL_ARRAY_BUFFER_ARB;
    constants["ELEMENT_ARRAY_BUFFER_ARB"] = GL_ELEMENT_ARRAY_BUFFER_ARB;
    constants["ARRAY_BUFFER_BINDING_ARB"] = GL_ARRAY_BUFFER_BINDING_ARB;
    constants["ELEMENT_ARRAY_BUFFER_BINDING_ARB"] = GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB;
    constants["VERTEX_ARRAY_BUFFER_BINDING_ARB"] = GL_VERTEX_ARRAY_BUFFER_BINDING_ARB;
    constants["NORMAL_ARRAY_BUFFER_BINDING_ARB"] = GL_NORMAL_ARRAY_BUFFER_BINDING_ARB;
    constants["COLOR_ARRAY_BUFFER_BINDING_ARB"] = GL_COLOR_ARRAY_BUFFER_BINDING_ARB;
    constants["INDEX_ARRAY_BUFFER_BINDING_ARB"] = GL_INDEX_ARRAY_BUFFER_BINDING_ARB;
    constants["TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB"] = GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB;
    constants["EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB"] = GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB;
    constants["SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB"] = GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB;
    constants["FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB"] = GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB;
    constants["WEIGHT_ARRAY_BUFFER_BINDING_ARB"] = GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB;
    constants["VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB"] = GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB;
    constants["READ_ONLY_ARB"] = GL_READ_ONLY_ARB;
    constants["WRITE_ONLY_ARB"] = GL_WRITE_ONLY_ARB;
    constants["READ_WRITE_ARB"] = GL_READ_WRITE_ARB;
    constants["BUFFER_ACCESS_ARB"] = GL_BUFFER_ACCESS_ARB;
    constants["BUFFER_MAPPED_ARB"] = GL_BUFFER_MAPPED_ARB;
    constants["BUFFER_MAP_POINTER_ARB"] = GL_BUFFER_MAP_POINTER_ARB;
    constants["STREAM_DRAW_ARB"] = GL_STREAM_DRAW_ARB;
    constants["STREAM_READ_ARB"] = GL_STREAM_READ_ARB;
    constants["STREAM_COPY_ARB"] = GL_STREAM_COPY_ARB;
    constants["STATIC_DRAW_ARB"] = GL_STATIC_DRAW_ARB;
    constants["STATIC_READ_ARB"] = GL_STATIC_READ_ARB;
    constants["STATIC_COPY_ARB"] = GL_STATIC_COPY_ARB;
    constants["DYNAMIC_DRAW_ARB"] = GL_DYNAMIC_DRAW_ARB;
    constants["DYNAMIC_READ_ARB"] = GL_DYNAMIC_READ_ARB;
    constants["DYNAMIC_COPY_ARB"] = GL_DYNAMIC_COPY_ARB;
    gl.addParamDim(LuaGL::Integerv, GL_ARRAY_BUFFER_BINDING_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_VERTEX_ARRAY_BUFFER_BINDING_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_NORMAL_ARRAY_BUFFER_BINDING_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_COLOR_ARRAY_BUFFER_BINDING_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_INDEX_ARRAY_BUFFER_BINDING_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB, 1);
    // VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB    16+ x Z+  GetVertexAttribivARB     0
  } else {
    constants["ARB_vertex_buffer_object"] = 0;
  }

  if (GLEW_ARB_vertex_program) {
#ifdef _DEBUG
    std::cout << "Supports ARB vertex program" << std::endl;
#endif
    constants["ARB_vertex_program"] = 1;
    constants["COLOR_SUM_ARB"] = GL_COLOR_SUM_ARB;
    constants["VERTEX_PROGRAM_ARB"] = GL_VERTEX_PROGRAM_ARB;
    constants["VERTEX_ATTRIB_ARRAY_ENABLED_ARB"] = GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB;
    constants["VERTEX_ATTRIB_ARRAY_SIZE_ARB"] = GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB;
    constants["VERTEX_ATTRIB_ARRAY_STRIDE_ARB"] = GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB;
    constants["VERTEX_ATTRIB_ARRAY_TYPE_ARB"] = GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB;
    constants["CURRENT_VERTEX_ATTRIB_ARB"] = GL_CURRENT_VERTEX_ATTRIB_ARB;
    constants["PROGRAM_LENGTH_ARB"] = GL_PROGRAM_LENGTH_ARB;
    constants["PROGRAM_STRING_ARB"] = GL_PROGRAM_STRING_ARB;
    constants["MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB"] = GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB;
    constants["MAX_PROGRAM_MATRICES_ARB"] = GL_MAX_PROGRAM_MATRICES_ARB;
    constants["CURRENT_MATRIX_STACK_DEPTH_ARB"] = GL_CURRENT_MATRIX_STACK_DEPTH_ARB;
    constants["CURRENT_MATRIX_ARB"] = GL_CURRENT_MATRIX_ARB;
    constants["VERTEX_PROGRAM_POINT_SIZE_ARB"] = GL_VERTEX_PROGRAM_POINT_SIZE_ARB;
    constants["VERTEX_PROGRAM_TWO_SIDE_ARB"] = GL_VERTEX_PROGRAM_TWO_SIDE_ARB;
    constants["VERTEX_ATTRIB_ARRAY_POINTER_ARB"] = GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB;
    constants["PROGRAM_ERROR_POSITION_ARB"] = GL_PROGRAM_ERROR_POSITION_ARB;
    constants["PROGRAM_BINDING_ARB"] = GL_PROGRAM_BINDING_ARB;
    constants["MAX_VERTEX_ATTRIBS_ARB"] = GL_MAX_VERTEX_ATTRIBS_ARB;
    constants["VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB"] = GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB;
    constants["PROGRAM_ERROR_STRING_ARB"] = GL_PROGRAM_ERROR_STRING_ARB;
    constants["PROGRAM_FORMAT_ASCII_ARB"] = GL_PROGRAM_FORMAT_ASCII_ARB;
    constants["PROGRAM_FORMAT_ARB"] = GL_PROGRAM_FORMAT_ARB;
    constants["PROGRAM_INSTRUCTIONS_ARB"] = GL_PROGRAM_INSTRUCTIONS_ARB;
    constants["MAX_PROGRAM_INSTRUCTIONS_ARB"] = GL_MAX_PROGRAM_INSTRUCTIONS_ARB;
    constants["PROGRAM_NATIVE_INSTRUCTIONS_ARB"] = GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB;
    constants["MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB"] = GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB;
    constants["PROGRAM_TEMPORARIES_ARB"] = GL_PROGRAM_TEMPORARIES_ARB;
    constants["MAX_PROGRAM_TEMPORARIES_ARB"] = GL_MAX_PROGRAM_TEMPORARIES_ARB;
    constants["PROGRAM_NATIVE_TEMPORARIES_ARB"] = GL_PROGRAM_NATIVE_TEMPORARIES_ARB;
    constants["MAX_PROGRAM_NATIVE_TEMPORARIES_ARB"] = GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB;
    constants["PROGRAM_PARAMETERS_ARB"] = GL_PROGRAM_PARAMETERS_ARB;
    constants["MAX_PROGRAM_PARAMETERS_ARB"] = GL_MAX_PROGRAM_PARAMETERS_ARB;
    constants["PROGRAM_NATIVE_PARAMETERS_ARB"] = GL_PROGRAM_NATIVE_PARAMETERS_ARB;
    constants["MAX_PROGRAM_NATIVE_PARAMETERS_ARB"] = GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB;
    constants["PROGRAM_ATTRIBS_ARB"] = GL_PROGRAM_ATTRIBS_ARB;
    constants["MAX_PROGRAM_ATTRIBS_ARB"] = GL_MAX_PROGRAM_ATTRIBS_ARB;
    constants["PROGRAM_NATIVE_ATTRIBS_ARB"] = GL_PROGRAM_NATIVE_ATTRIBS_ARB;
    constants["MAX_PROGRAM_NATIVE_ATTRIBS_ARB"] = GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB;
    constants["PROGRAM_ADDRESS_REGISTERS_ARB"] = GL_PROGRAM_ADDRESS_REGISTERS_ARB;
    constants["MAX_PROGRAM_ADDRESS_REGISTERS_ARB"] = GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB;
    constants["PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB"] = GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB;
    constants["MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB"] = GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB;
    constants["MAX_PROGRAM_LOCAL_PARAMETERS_ARB"] = GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB;
    constants["MAX_PROGRAM_ENV_PARAMETERS_ARB"] = GL_MAX_PROGRAM_ENV_PARAMETERS_ARB;
    constants["PROGRAM_UNDER_NATIVE_LIMITS_ARB"] = GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB;
    constants["TRANSPOSE_CURRENT_MATRIX_ARB"] = GL_TRANSPOSE_CURRENT_MATRIX_ARB;
    constants["MATRIX0_ARB"] = GL_MATRIX0_ARB;
    constants["MATRIX1_ARB"] = GL_MATRIX1_ARB;
    constants["MATRIX2_ARB"] = GL_MATRIX2_ARB;
    constants["MATRIX3_ARB"] = GL_MATRIX3_ARB;
    constants["MATRIX4_ARB"] = GL_MATRIX4_ARB;
    constants["MATRIX5_ARB"] = GL_MATRIX5_ARB;
    constants["MATRIX6_ARB"] = GL_MATRIX6_ARB;
    constants["MATRIX7_ARB"] = GL_MATRIX7_ARB;
    constants["MATRIX8_ARB"] = GL_MATRIX8_ARB;
    constants["MATRIX9_ARB"] = GL_MATRIX9_ARB;
    constants["MATRIX10_ARB"] = GL_MATRIX10_ARB;
    constants["MATRIX11_ARB"] = GL_MATRIX11_ARB;
    constants["MATRIX12_ARB"] = GL_MATRIX12_ARB;
    constants["MATRIX13_ARB"] = GL_MATRIX13_ARB;
    constants["MATRIX14_ARB"] = GL_MATRIX14_ARB;
    constants["MATRIX15_ARB"] = GL_MATRIX15_ARB;
    constants["MATRIX16_ARB"] = GL_MATRIX16_ARB;
    constants["MATRIX17_ARB"] = GL_MATRIX17_ARB;
    constants["MATRIX18_ARB"] = GL_MATRIX18_ARB;
    constants["MATRIX19_ARB"] = GL_MATRIX19_ARB;
    constants["MATRIX20_ARB"] = GL_MATRIX20_ARB;
    constants["MATRIX21_ARB"] = GL_MATRIX21_ARB;
    constants["MATRIX22_ARB"] = GL_MATRIX22_ARB;
    constants["MATRIX23_ARB"] = GL_MATRIX23_ARB;
    constants["MATRIX24_ARB"] = GL_MATRIX24_ARB;
    constants["MATRIX25_ARB"] = GL_MATRIX25_ARB;
    constants["MATRIX26_ARB"] = GL_MATRIX26_ARB;
    constants["MATRIX27_ARB"] = GL_MATRIX27_ARB;
    constants["MATRIX28_ARB"] = GL_MATRIX28_ARB;
    constants["MATRIX29_ARB"] = GL_MATRIX29_ARB;
    constants["MATRIX30_ARB"] = GL_MATRIX30_ARB;
    constants["MATRIX31_ARB"] = GL_MATRIX31_ARB;
    gl.addParamDim(LuaGL::Integerv, GL_PROGRAM_ERROR_POSITION_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_PROGRAM_MATRICES_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_CURRENT_MATRIX_STACK_DEPTH_ARB, 1);
    gl.addParamDim(LuaGL::Floatv, GL_CURRENT_MATRIX_ARB, 16);
    gl.addParamDim(LuaGL::Floatv, GL_TRANSPOSE_CURRENT_MATRIX_ARB, 16);
  } else {
    constants["ARB_vertex_program"] = 0;
  }

  if (GLEW_ARB_vertex_shader) {
#ifdef _DEBUG
    std::cout << "Supports ARB vertex shader" << std::endl;
#endif
    constants["ARB_vertex_shader"] = 1;
    constants["VERTEX_SHADER_ARB"] = GL_VERTEX_SHADER_ARB;
    constants["MAX_VERTEX_UNIFORM_COMPONENTS_ARB"] = GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB;
    constants["MAX_VARYING_FLOATS_ARB"] = GL_MAX_VARYING_FLOATS_ARB;
    constants["MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB"] = GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB;
    constants["MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB"] = GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB;
    constants["OBJECT_ACTIVE_ATTRIBUTES_ARB"] = GL_OBJECT_ACTIVE_ATTRIBUTES_ARB;
    constants["OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB"] = GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB;
    gl.addParamDim(LuaGL::Integerv, GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_VARYING_FLOATS_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB, 1);
  } else {
    constants["ARB_vertex_shader"] = 0;
  }

  if (GLEW_ARB_window_pos) {
#ifdef _DEBUG
    std::cout << "Supports ARB window pos" << std::endl;
#endif
    constants["ARB_window_pos"] = 1;
  } else {
    constants["ARB_window_pos"] = 0;
  }

  if (GLEW_ARB_imaging) {
#ifdef _DEBUG
    std::cout << "Supports ARB imaging" << std::endl;
#endif
    constants["ARB_imaging"] = 1;
    constants["CONSTANT_COLOR"] = GL_CONSTANT_COLOR;
    constants["ONE_MINUS_CONSTANT_COLOR"] = GL_ONE_MINUS_CONSTANT_COLOR;
    constants["CONSTANT_ALPHA"] = GL_CONSTANT_ALPHA;
    constants["ONE_MINUS_CONSTANT_ALPHA"] = GL_ONE_MINUS_CONSTANT_ALPHA;
    constants["BLEND_COLOR"] = GL_BLEND_COLOR;
    constants["FUNC_ADD"] = GL_FUNC_ADD;
    constants["MIN"] = GL_MIN;
    constants["MAX"] = GL_MAX;
    constants["BLEND_EQUATION"] = GL_BLEND_EQUATION;
    constants["FUNC_SUBTRACT"] = GL_FUNC_SUBTRACT;
    constants["FUNC_REVERSE_SUBTRACT"] = GL_FUNC_REVERSE_SUBTRACT;
    constants["CONVOLUTION_1D"] = GL_CONVOLUTION_1D;
    constants["CONVOLUTION_2D"] = GL_CONVOLUTION_2D;
    constants["SEPARABLE_2D"] = GL_SEPARABLE_2D;
    constants["CONVOLUTION_BORDER_MODE"] = GL_CONVOLUTION_BORDER_MODE;
    constants["CONVOLUTION_FILTER_SCALE"] = GL_CONVOLUTION_FILTER_SCALE;
    constants["CONVOLUTION_FILTER_BIAS"] = GL_CONVOLUTION_FILTER_BIAS;
    constants["REDUCE"] = GL_REDUCE;
    constants["CONVOLUTION_FORMAT"] = GL_CONVOLUTION_FORMAT;
    constants["CONVOLUTION_WIDTH"] = GL_CONVOLUTION_WIDTH;
    constants["CONVOLUTION_HEIGHT"] = GL_CONVOLUTION_HEIGHT;
    constants["MAX_CONVOLUTION_WIDTH"] = GL_MAX_CONVOLUTION_WIDTH;
    constants["MAX_CONVOLUTION_HEIGHT"] = GL_MAX_CONVOLUTION_HEIGHT;
    constants["POST_CONVOLUTION_RED_SCALE"] = GL_POST_CONVOLUTION_RED_SCALE;
    constants["POST_CONVOLUTION_GREEN_SCALE"] = GL_POST_CONVOLUTION_GREEN_SCALE;
    constants["POST_CONVOLUTION_BLUE_SCALE"] = GL_POST_CONVOLUTION_BLUE_SCALE;
    constants["POST_CONVOLUTION_ALPHA_SCALE"] = GL_POST_CONVOLUTION_ALPHA_SCALE;
    constants["POST_CONVOLUTION_RED_BIAS"] = GL_POST_CONVOLUTION_RED_BIAS;
    constants["POST_CONVOLUTION_GREEN_BIAS"] = GL_POST_CONVOLUTION_GREEN_BIAS;
    constants["POST_CONVOLUTION_BLUE_BIAS"] = GL_POST_CONVOLUTION_BLUE_BIAS;
    constants["POST_CONVOLUTION_ALPHA_BIAS"] = GL_POST_CONVOLUTION_ALPHA_BIAS;
    constants["HISTOGRAM"] = GL_HISTOGRAM;
    constants["PROXY_HISTOGRAM"] = GL_PROXY_HISTOGRAM;
    constants["HISTOGRAM_WIDTH"] = GL_HISTOGRAM_WIDTH;
    constants["HISTOGRAM_FORMAT"] = GL_HISTOGRAM_FORMAT;
    constants["HISTOGRAM_RED_SIZE"] = GL_HISTOGRAM_RED_SIZE;
    constants["HISTOGRAM_GREEN_SIZE"] = GL_HISTOGRAM_GREEN_SIZE;
    constants["HISTOGRAM_BLUE_SIZE"] = GL_HISTOGRAM_BLUE_SIZE;
    constants["HISTOGRAM_ALPHA_SIZE"] = GL_HISTOGRAM_ALPHA_SIZE;
    constants["HISTOGRAM_LUMINANCE_SIZE"] = GL_HISTOGRAM_LUMINANCE_SIZE;
    constants["HISTOGRAM_SINK"] = GL_HISTOGRAM_SINK;
    constants["MINMAX"] = GL_MINMAX;
    constants["MINMAX_FORMAT"] = GL_MINMAX_FORMAT;
    constants["MINMAX_SINK"] = GL_MINMAX_SINK;
    constants["TABLE_TOO_LARGE"] = GL_TABLE_TOO_LARGE;
    constants["COLOR_MATRIX"] = GL_COLOR_MATRIX;
    constants["COLOR_MATRIX_STACK_DEPTH"] = GL_COLOR_MATRIX_STACK_DEPTH;
    constants["MAX_COLOR_MATRIX_STACK_DEPTH"] = GL_MAX_COLOR_MATRIX_STACK_DEPTH;
    constants["POST_COLOR_MATRIX_RED_SCALE"] = GL_POST_COLOR_MATRIX_RED_SCALE;
    constants["POST_COLOR_MATRIX_GREEN_SCALE"] = GL_POST_COLOR_MATRIX_GREEN_SCALE;
    constants["POST_COLOR_MATRIX_BLUE_SCALE"] = GL_POST_COLOR_MATRIX_BLUE_SCALE;
    constants["POST_COLOR_MATRIX_ALPHA_SCALE"] = GL_POST_COLOR_MATRIX_ALPHA_SCALE;
    constants["POST_COLOR_MATRIX_RED_BIAS"] = GL_POST_COLOR_MATRIX_RED_BIAS;
    constants["POST_COLOR_MATRIX_GREEN_BIAS"] = GL_POST_COLOR_MATRIX_GREEN_BIAS;
    constants["POST_COLOR_MATRIX_BLUE_BIAS"] = GL_POST_COLOR_MATRIX_BLUE_BIAS;
    constants["POST_COLOR_MATRIX_ALPHA_BIAS"] = GL_POST_COLOR_MATRIX_ALPHA_BIAS;
    constants["COLOR_TABLE"] = GL_COLOR_TABLE;
    constants["POST_CONVOLUTION_COLOR_TABLE"] = GL_POST_CONVOLUTION_COLOR_TABLE;
    constants["POST_COLOR_MATRIX_COLOR_TABLE"] = GL_POST_COLOR_MATRIX_COLOR_TABLE;
    constants["PROXY_COLOR_TABLE"] = GL_PROXY_COLOR_TABLE;
    constants["PROXY_POST_CONVOLUTION_COLOR_TABLE"] = GL_PROXY_POST_CONVOLUTION_COLOR_TABLE;
    constants["PROXY_POST_COLOR_MATRIX_COLOR_TABLE"] = GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE;
    constants["COLOR_TABLE_SCALE"] = GL_COLOR_TABLE_SCALE;
    constants["COLOR_TABLE_BIAS"] = GL_COLOR_TABLE_BIAS;
    constants["COLOR_TABLE_FORMAT"] = GL_COLOR_TABLE_FORMAT;
    constants["COLOR_TABLE_WIDTH"] = GL_COLOR_TABLE_WIDTH;
    constants["COLOR_TABLE_RED_SIZE"] = GL_COLOR_TABLE_RED_SIZE;
    constants["COLOR_TABLE_GREEN_SIZE"] = GL_COLOR_TABLE_GREEN_SIZE;
    constants["COLOR_TABLE_BLUE_SIZE"] = GL_COLOR_TABLE_BLUE_SIZE;
    constants["COLOR_TABLE_ALPHA_SIZE"] = GL_COLOR_TABLE_ALPHA_SIZE;
    constants["COLOR_TABLE_LUMINANCE_SIZE"] = GL_COLOR_TABLE_LUMINANCE_SIZE;
    constants["COLOR_TABLE_INTENSITY_SIZE"] = GL_COLOR_TABLE_INTENSITY_SIZE;
    constants["IGNORE_BORDER"] = GL_IGNORE_BORDER;
    constants["CONSTANT_BORDER"] = GL_CONSTANT_BORDER;
    constants["WRAP_BORDER"] = GL_WRAP_BORDER;
    constants["REPLICATE_BORDER"] = GL_REPLICATE_BORDER;
    constants["CONVOLUTION_BORDER_COLOR"] = GL_CONVOLUTION_BORDER_COLOR;
    gl.addParamDim(LuaGL::Integerv, GL_COLOR_MATRIX_STACK_DEPTH, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_COLOR_MATRIX_STACK_DEPTH, 1);
    gl.addParamDim(LuaGL::Floatv, GL_COLOR_MATRIX, 16);
    gl.addParamDim(LuaGL::Floatv, GL_POST_CONVOLUTION_RED_SCALE, 1);
    gl.addParamDim(LuaGL::Floatv, GL_POST_CONVOLUTION_GREEN_SCALE, 1);
    gl.addParamDim(LuaGL::Floatv, GL_POST_CONVOLUTION_BLUE_SCALE, 1);
    gl.addParamDim(LuaGL::Floatv, GL_POST_CONVOLUTION_ALPHA_SCALE, 1);
    gl.addParamDim(LuaGL::Floatv, GL_POST_CONVOLUTION_RED_BIAS, 1);
    gl.addParamDim(LuaGL::Floatv, GL_POST_CONVOLUTION_GREEN_BIAS, 1);
    gl.addParamDim(LuaGL::Floatv, GL_POST_CONVOLUTION_BLUE_BIAS, 1);
    gl.addParamDim(LuaGL::Floatv, GL_POST_CONVOLUTION_ALPHA_BIAS, 1);
    gl.addParamDim(LuaGL::Floatv, GL_POST_COLOR_MATRIX_RED_SCALE, 1);
    gl.addParamDim(LuaGL::Floatv, GL_POST_COLOR_MATRIX_GREEN_SCALE, 1);
    gl.addParamDim(LuaGL::Floatv, GL_POST_COLOR_MATRIX_BLUE_SCALE, 1);
    gl.addParamDim(LuaGL::Floatv, GL_POST_COLOR_MATRIX_ALPHA_SCALE, 1);
    gl.addParamDim(LuaGL::Floatv, GL_POST_COLOR_MATRIX_RED_BIAS, 1);
    gl.addParamDim(LuaGL::Floatv, GL_POST_COLOR_MATRIX_GREEN_BIAS, 1);
    gl.addParamDim(LuaGL::Floatv, GL_POST_COLOR_MATRIX_BLUE_BIAS, 1);
    gl.addParamDim(LuaGL::Floatv, GL_POST_COLOR_MATRIX_ALPHA_BIAS, 1);
  } else {
    constants["ARB_imaging"] = 0;
  }
}

void Register_GL_ARB_Functions(lua_State *L, int module) {
  //REGISTER_GL_FUNC(L, module, 
  if (GLEW_ARB_color_buffer_float) {
    REGISTER_GL_FUNC(L, module, ClampColorARB);
  }
  if (GLEW_ARB_draw_buffers) {
    REGISTER_GL_FUNC(L, module, DrawBuffersARB);
  }
  if (GLEW_ARB_matrix_palette) {
    REGISTER_GL_FUNC(L, module, CurrentPaletteMatrixARB);
    REGISTER_GL_FUNC(L, module, MatrixIndexPointerARB);
    REGISTER_GL_FUNC(L, module, MatrixIndexubvARB);
    REGISTER_GL_FUNC(L, module, MatrixIndexusvARB);
    REGISTER_GL_FUNC(L, module, MatrixIndexuivARB);
  }
  if (GLEW_ARB_multisample) {
    REGISTER_GL_FUNC(L, module, SampleCoverageARB);
  }
  if (GLEW_ARB_multitexture) {
    REGISTER_GL_FUNC(L, module, ActiveTextureARB);
    REGISTER_GL_FUNC(L, module, ClientActiveTextureARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord1dARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord1fARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord1sARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord1iARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord2dARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord2fARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord2sARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord2iARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord3dARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord3fARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord3sARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord3iARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord4dARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord4fARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord4sARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord4iARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord2dvARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord2fvARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord2svARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord2ivARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord3dvARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord3fvARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord3svARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord3ivARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord4dvARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord4fvARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord4svARB);
    REGISTER_GL_FUNC(L, module, MultiTexCoord4ivARB);
  }
  if (GLEW_ARB_occlusion_query) {
    REGISTER_GL_FUNC(L, module, BeginQueryARB);
    REGISTER_GL_FUNC(L, module, GenQueriesARB);
    REGISTER_GL_FUNC(L, module, EndQueryARB);
    REGISTER_GL_FUNC(L, module, DeleteQueriesARB);
    REGISTER_GL_FUNC(L, module, GetQueryObjectARB);
    REGISTER_GL_FUNC(L, module, GetQueryARB);
    REGISTER_GL_FUNC(L, module, IsQueryARB);
  }
  if (GLEW_ARB_point_parameters) {
    REGISTER_GL_FUNC(L, module, PointParameterfARB);
    REGISTER_GL_FUNC(L, module, PointParameterfvARB); 
  }
  if (GLEW_ARB_shader_objects) {
    REGISTER_GL_FUNC(L, module, AttachObjectARB);
    REGISTER_GL_FUNC(L, module, CompileShaderARB);
    REGISTER_GL_FUNC(L, module, CreateProgramObjectARB);
    REGISTER_GL_FUNC(L, module, CreateShaderObjectARB);
    REGISTER_GL_FUNC(L, module, DeleteObjectARB);
    REGISTER_GL_FUNC(L, module, DetachObjectARB);
    REGISTER_GL_FUNC(L, module, UseProgramObjectARB);
    REGISTER_GL_FUNC(L, module, ValidateProgramARB);
    REGISTER_GL_FUNC(L, module, LinkProgramARB);
    REGISTER_GL_FUNC(L, module, Uniform1fARB);
    REGISTER_GL_FUNC(L, module, Uniform2fARB);
    REGISTER_GL_FUNC(L, module, Uniform3fARB);
    REGISTER_GL_FUNC(L, module, Uniform4fARB);
    REGISTER_GL_FUNC(L, module, Uniform1fvARB);
    REGISTER_GL_FUNC(L, module, Uniform2fvARB);
    REGISTER_GL_FUNC(L, module, Uniform3fvARB);
    REGISTER_GL_FUNC(L, module, Uniform4fvARB);
    REGISTER_GL_FUNC(L, module, Uniform1iARB);
    REGISTER_GL_FUNC(L, module, Uniform2iARB);
    REGISTER_GL_FUNC(L, module, Uniform3iARB);
    REGISTER_GL_FUNC(L, module, Uniform4iARB);
    REGISTER_GL_FUNC(L, module, Uniform1ivARB);
    REGISTER_GL_FUNC(L, module, Uniform2ivARB);
    REGISTER_GL_FUNC(L, module, Uniform3ivARB);
    REGISTER_GL_FUNC(L, module, Uniform4ivARB);
    REGISTER_GL_FUNC(L, module, GetActiveUniformARB);
    REGISTER_GL_FUNC(L, module, GetShaderSourceARB);
    REGISTER_GL_FUNC(L, module, GetHandleARB);
    REGISTER_GL_FUNC(L, module, GetUniformLocationARB);
    REGISTER_GL_FUNC(L, module, ShaderSourceARB);
    REGISTER_GL_FUNC(L, module, GetAttachedObjectsARB);
    REGISTER_GL_FUNC(L, module, GetObjectParameterARB);
    REGISTER_GL_FUNC(L, module, GetInfoLogARB);
    REGISTER_GL_FUNC(L, module, UniformMatrix2fvARB);
    REGISTER_GL_FUNC(L, module, UniformMatrix3fvARB);
    REGISTER_GL_FUNC(L, module, UniformMatrix4fvARB);
    REGISTER_GL_FUNC(L, module, GetUniformARB);
  }
  if (GLEW_ARB_texture_compression) {
    REGISTER_GL_FUNC(L, module, CompressedTexImage1DARB);
    REGISTER_GL_FUNC(L, module, CompressedTexImage2DARB);
    REGISTER_GL_FUNC(L, module, CompressedTexImage3DARB);
    REGISTER_GL_FUNC(L, module, CompressedTexSubImage1DARB);
    REGISTER_GL_FUNC(L, module, CompressedTexSubImage2DARB);
    REGISTER_GL_FUNC(L, module, CompressedTexSubImage3DARB);
    REGISTER_GL_FUNC(L, module, GetCompressedTexImageARB);
  }
  if (GLEW_ARB_transpose_matrix) {
    REGISTER_GL_FUNC(L, module, LoadTransposeMatrixdARB);
    REGISTER_GL_FUNC(L, module, LoadTransposeMatrixfARB);
    REGISTER_GL_FUNC(L, module, MultTransposeMatrixdARB);
    REGISTER_GL_FUNC(L, module, MultTransposeMatrixfARB);
  }
  if (GLEW_ARB_vertex_blend) {
    REGISTER_GL_FUNC(L, module, VertexBlendARB);
    REGISTER_GL_FUNC(L, module, WeightPointerARB);
    REGISTER_GL_FUNC(L, module, WeightdvARB);
    REGISTER_GL_FUNC(L, module, WeightfvARB);
    REGISTER_GL_FUNC(L, module, WeightivARB);
    REGISTER_GL_FUNC(L, module, WeightsvARB);
    REGISTER_GL_FUNC(L, module, WeightbvARB);
    REGISTER_GL_FUNC(L, module, WeightuivARB);
    REGISTER_GL_FUNC(L, module, WeightusvARB);
    REGISTER_GL_FUNC(L, module, WeightubvARB);
  }
  if (GLEW_ARB_vertex_buffer_object) {
    REGISTER_GL_FUNC(L, module, BindBufferARB);
    REGISTER_GL_FUNC(L, module, BufferDataARB);
    REGISTER_GL_FUNC(L, module, BufferSubDataARB);
    REGISTER_GL_FUNC(L, module, DeleteBuffersARB);
    REGISTER_GL_FUNC(L, module, GenBuffersARB);
    REGISTER_GL_FUNC(L, module, IsBufferARB);
    REGISTER_GL_FUNC(L, module, MapBufferARB);
    REGISTER_GL_FUNC(L, module, UnmapBufferARB);
    REGISTER_GL_FUNC(L, module, GetBufferPointerARB);
    REGISTER_GL_FUNC(L, module, GetBufferSubDataARB);
    REGISTER_GL_FUNC(L, module, GetBufferParameterARB);
  }
  if (GLEW_ARB_vertex_program) {
    REGISTER_GL_FUNC(L, module, GetVertexAttribARB);
    REGISTER_GL_FUNC(L, module, GetVertexAttribPointerARB);
    REGISTER_GL_FUNC(L, module, VertexAttribPointerARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib1dARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib1fARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib1sARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib2dARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib2fARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib2sARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib3dARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib3fARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib3sARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib4dARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib4fARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib4sARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib2dvARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib2fvARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib2svARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib3dvARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib3fvARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib3svARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib4dvARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib4fvARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib4svARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib4NbvARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib4NsvARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib4NivARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib4NubvARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib4NusvARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib4NuivARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib4bvARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib4ivARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib4ubvARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib4usvARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib4uivARB);
    REGISTER_GL_FUNC(L, module, BindProgramARB);
    REGISTER_GL_FUNC(L, module, DeleteProgramsARB);
    REGISTER_GL_FUNC(L, module, DisableVertexAttribArrayARB);
    REGISTER_GL_FUNC(L, module, EnableVertexAttribArrayARB);
    REGISTER_GL_FUNC(L, module, GenProgramsARB);
    REGISTER_GL_FUNC(L, module, GetProgramEnvParameterARB);
    REGISTER_GL_FUNC(L, module, GetProgramLocalParameterARB);
    REGISTER_GL_FUNC(L, module, GetProgramARB);
    REGISTER_GL_FUNC(L, module, GetProgramStringARB);
    REGISTER_GL_FUNC(L, module, IsProgramARB);
    REGISTER_GL_FUNC(L, module, ProgramEnvParameter4fvARB);
    REGISTER_GL_FUNC(L, module, ProgramEnvParameter4fARB);
    REGISTER_GL_FUNC(L, module, ProgramEnvParameter4dvARB);
    REGISTER_GL_FUNC(L, module, ProgramEnvParameter4dARB);
    REGISTER_GL_FUNC(L, module, ProgramLocalParameter4fvARB);
    REGISTER_GL_FUNC(L, module, ProgramLocalParameter4fARB);
    REGISTER_GL_FUNC(L, module, ProgramLocalParameter4dvARB);
    REGISTER_GL_FUNC(L, module, ProgramLocalParameter4dARB);
    REGISTER_GL_FUNC(L, module, ProgramStringARB);
    REGISTER_GL_FUNC(L, module, VertexAttrib4NubARB);
  }
  if (GLEW_ARB_vertex_shader) {
    REGISTER_GL_FUNC(L, module, BindAttribLocationARB);
    REGISTER_GL_FUNC(L, module, GetActiveAttribARB);
    REGISTER_GL_FUNC(L, module, GetAttribLocationARB);
  }
  if (GLEW_ARB_window_pos) {
    REGISTER_GL_FUNC(L, module, WindowPos2dARB);
    REGISTER_GL_FUNC(L, module, WindowPos2fARB);
    REGISTER_GL_FUNC(L, module, WindowPos2iARB);
    REGISTER_GL_FUNC(L, module, WindowPos2sARB);
    REGISTER_GL_FUNC(L, module, WindowPos3dARB);
    REGISTER_GL_FUNC(L, module, WindowPos3fARB);
    REGISTER_GL_FUNC(L, module, WindowPos3iARB);
    REGISTER_GL_FUNC(L, module, WindowPos3sARB);
    REGISTER_GL_FUNC(L, module, WindowPos2dvARB);
    REGISTER_GL_FUNC(L, module, WindowPos2fvARB);
    REGISTER_GL_FUNC(L, module, WindowPos2ivARB);
    REGISTER_GL_FUNC(L, module, WindowPos2svARB);
    REGISTER_GL_FUNC(L, module, WindowPos3dvARB);
    REGISTER_GL_FUNC(L, module, WindowPos3fvARB);
    REGISTER_GL_FUNC(L, module, WindowPos3ivARB);
    REGISTER_GL_FUNC(L, module, WindowPos3svARB);
  }
  if (GLEW_ARB_imaging) {
    REGISTER_GL_FUNC(L, module, ColorSubTable);
    REGISTER_GL_FUNC(L, module, ColorTable);
    REGISTER_GL_FUNC(L, module, ColorTableParameterfv);
    REGISTER_GL_FUNC(L, module, ColorTableParameteriv);
    REGISTER_GL_FUNC(L, module, ConvolutionFilter1D);
    REGISTER_GL_FUNC(L, module, ConvolutionFilter2D);
    REGISTER_GL_FUNC(L, module, ConvolutionParameterf);
    REGISTER_GL_FUNC(L, module, ConvolutionParameterfv);
    REGISTER_GL_FUNC(L, module, ConvolutionParameteri);
    REGISTER_GL_FUNC(L, module, ConvolutionParameteriv);
    REGISTER_GL_FUNC(L, module, CopyColorSubTable);
    REGISTER_GL_FUNC(L, module, CopyColorTable);
    REGISTER_GL_FUNC(L, module, CopyConvolutionFilter1D);
    REGISTER_GL_FUNC(L, module, CopyConvolutionFilter2D);
    REGISTER_GL_FUNC(L, module, GetColorTable);
    REGISTER_GL_FUNC(L, module, GetColorTableParameter);
    REGISTER_GL_FUNC(L, module, GetConvolutionFilter);
    REGISTER_GL_FUNC(L, module, GetConvolutionParameter);
    REGISTER_GL_FUNC(L, module, GetHistogram);
    REGISTER_GL_FUNC(L, module, GetHistogramParameter);
    REGISTER_GL_FUNC(L, module, GetMinmax);
    REGISTER_GL_FUNC(L, module, GetMinmaxParameter);
    REGISTER_GL_FUNC(L, module, GetSeparableFilter);
    REGISTER_GL_FUNC(L, module, Histogram);
    REGISTER_GL_FUNC(L, module, Minmax);
    REGISTER_GL_FUNC(L, module, ResetHistogram);
    REGISTER_GL_FUNC(L, module, ResetMinmax);
    REGISTER_GL_FUNC(L, module, SeparableFilter2D);
  }
}
