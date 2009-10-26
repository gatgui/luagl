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

static int lua_glAttachShader(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, Uint, glAttachShader>::Call(L);
#else
  return WrapFunc2<Uint, Uint >::Call(L, glAttachShader);
#endif
}

static int lua_glBindAttribLocation(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Uint, Uint, String, glBindAttribLocation>::Call(L);
#else
  return WrapFunc3<Uint, Uint, String >::Call(L, glBindAttribLocation);
#endif
}

static int lua_glBlendEquationSeparate(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Enum, glBlendEquationSeparate>::Call(L);
#else
  return WrapFunc2<Enum, Enum >::Call(L, glBlendEquationSeparate);
#endif
}

static int lua_glCompileShader(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Uint, glCompileShader>::Call(L);
#else
  return WrapFunc1<Uint >::Call(L, glCompileShader);
#endif
}

static int lua_glCreateProgram(lua_State *L) {
  CHECK_ARG_COUNT(L, 0);
  lua_pushinteger(L, glCreateProgram());
  return 1;
}

static int lua_glCreateShader(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Enum type(L, 1);
  lua_pushinteger(L, glCreateShader(type));
  return 1;
}

static int lua_glDeleteProgram(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Uint, glDeleteProgram>::Call(L);
#else
  return WrapFunc1<Uint >::Call(L, glDeleteProgram);
#endif
}

static int lua_glDeleteShader(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Uint, glDeleteShader>::Call(L);
#else
  return WrapFunc1<Uint >::Call(L, glDeleteShader);
#endif
}

static int lua_glDetachShader(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, Uint, glDetachShader>::Call(L);
#else
  return WrapFunc2<Uint, Uint >::Call(L, glDetachShader);
#endif
}

static int lua_glDisableVertexAttribArray(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Uint, glDisableVertexAttribArray>::Call(L);
#else
  return WrapFunc1<Uint >::Call(L, glDisableVertexAttribArray);
#endif
}

static int lua_glDrawBuffers(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Array1D<Enum> buffers(L, 1);
  glDrawBuffers(buffers.size(), buffers);
  return 0;
}

static int lua_glEnableVertexAttribArray(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Uint, glEnableVertexAttribArray>::Call(L);
#else
  return WrapFunc1<Uint >::Call(L, glEnableVertexAttribArray);
#endif
}

static int lua_glGetActiveAttrib(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Uint prg(L, 1);
  Uint idx(L, 2);
  GLint len=0;
  glGetProgramiv(prg, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &len);
  //GLchar *name = new GLchar[len+1];
  Array1D<Char> name(len+1);
  GLint size;
  GLenum type;
  glGetActiveAttrib(prg, idx, len, NULL, &size, &type, name);
  lua_pushinteger(L, size);
  lua_pushinteger(L, type);
  lua_pushstring(L, name);
  //delete[] name;
  return 3;
}

static int lua_glGetActiveUniform(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Uint prg(L, 1);
  Uint idx(L, 2);
  GLint len=0;
  glGetProgramiv(prg, GL_ACTIVE_UNIFORM_MAX_LENGTH, &len);
  //GLchar *name = new GLchar[len+1];
  Array1D<Char> name(len+1);
  GLint size;
  GLenum type;
  glGetActiveUniform(prg, idx, len, NULL, &size, &type, name);
  lua_pushinteger(L, size);
  lua_pushinteger(L, type);
  lua_pushstring(L, name);
  //delete[] name;
  return 3;
}

static int lua_glGetAttachedShaders(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Uint prg(L, 1);
  GLint count=0;
  glGetProgramiv(prg, GL_ATTACHED_SHADERS, &count);
  if (count == 0) {
    lua_newtable(L); // empty table
  } else {
    Array1D<Uint> shaders(count);
    glGetAttachedShaders(prg, count, NULL, shaders);
    shaders.toLUA(L);
  }
  return 1;
}

static int lua_glGetAttribLocation(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Uint prg(L, 1);
  String name(L, 2);
  lua_pushinteger(L, glGetAttribLocation(prg, name));
  return 1;
}

static int lua_glGetProgramInfoLog(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Uint prg(L, 1);
  GLint len=0;
  glGetProgramiv(prg, GL_INFO_LOG_LENGTH, &len);
  //GLchar *log = new GLchar[len+1];
  Array1D<Char> log(len+1);
  glGetProgramInfoLog(prg, len, NULL, log);
  lua_pushstring(L, log);
  //delete[] log;
  return 1;
}

static int lua_glGetProgram(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Uint prg(L, 1);
  Enum pname(L, 2);
  GLint dim = LuaGL::Instance().getParamDim(LuaGL::Programiv, pname);
  if (dim > 0) {
    Array1D<Int> param(dim);
    glGetProgramiv(prg, pname, param);
    if (dim == 1) {
      lua_pushinteger(L, param[0]);
    } else {
      param.toLUA(L);
    }
  }
  if (dim == 0) {
    luaL_error(L, "gl.GetProgram: invalid parameter name");
  }
  return 1;
}

static int lua_glGetShaderInfoLog(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Uint shader(L, 1);
  GLint len=0;
  glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
  //GLchar *log = new GLchar[len+1];
  Array1D<Char> log(len+1);
  glGetShaderInfoLog(shader, len, NULL, log);
  lua_pushstring(L, log);
  //delete[] log;
  return 1;
}

static int lua_glGetShaderSource(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Uint shader(L, 1);
  GLint len=0;
  glGetShaderiv(shader, GL_SHADER_SOURCE_LENGTH, &len);
  //GLchar *src = new GLchar[len+1];
  Array1D<Char> src(len+1);
  glGetShaderSource(shader, len, NULL, src);
  lua_pushstring(L, src);
  //delete[] src;
  return 1;
}

static int lua_glGetShader(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Uint prg(L, 1);
  Enum pname(L, 2);
  GLint dim = LuaGL::Instance().getParamDim(LuaGL::Shaderiv, pname);
  if (dim > 0) {
    Array1D<Int> param(dim);
    glGetShaderiv(prg, pname, param);
    if (dim == 1) {
      lua_pushinteger(L, param[0]);
    } else {
      param.toLUA(L);
    }
  }
  if (dim == 0) {
    luaL_error(L, "gl.GetShader: invalid parameter name");
  }
  return 1;
}

static int lua_glGetUniformLocation(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Int prg(L, 1);
  String name(L, 2);
  lua_pushinteger(L, glGetUniformLocation(prg, name));
  return 1;
}

static int lua_glIsProgram(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Uint prg(L, 1);
  lua_pushboolean(L, (glIsProgram(prg) == GL_TRUE ? 1 : 0));
  return 1;
}

static int lua_glIsShader(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Uint shader(L, 1);
  lua_pushboolean(L, (glIsShader(shader) == GL_TRUE ? 1 : 0));
  return 1;
}

static int lua_glLinkProgram(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Uint, glLinkProgram>::Call(L);
#else
  return WrapFunc1<Uint >::Call(L, glLinkProgram);
#endif
}

static int lua_glGetUniform(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Uint prg(L, 1);
  Int loc(L, 2);
  GLint size;
  GLenum type;
  GLchar dummy;
  glGetActiveUniform(prg, loc, 0, 0, &size, &type, &dummy);
  bool integer = false;
  int dim = 0;
  switch (type) {
    case GL_FLOAT:
      dim = 1;
      break;
    case GL_FLOAT_VEC2:
      dim = 2;
      break;
    case GL_FLOAT_VEC3:
      dim = 3;
      break;
    case GL_FLOAT_VEC4:
    case GL_FLOAT_MAT2:
      dim = 4;
      break;
    case GL_FLOAT_MAT3:
      dim = 9;
      break;
    case GL_FLOAT_MAT4:
      dim = 16;
      break;
    // Those are in fact OpenGL 2.1 additions
    case GL_FLOAT_MAT2x3:
    case GL_FLOAT_MAT3x2:
      dim = 6;
      break;
    case GL_FLOAT_MAT2x4:
    case GL_FLOAT_MAT4x2:
      dim = 8;
      break;
    case GL_FLOAT_MAT3x4:
    case GL_FLOAT_MAT4x3:
      dim = 12;
      break;
    case GL_INT:
    case GL_BOOL:
    case GL_SAMPLER_1D:
    case GL_SAMPLER_2D:
    case GL_SAMPLER_3D:
    case GL_SAMPLER_CUBE:
    case GL_SAMPLER_1D_SHADOW:
    case GL_SAMPLER_2D_SHADOW:
      integer = true;
      dim = 1;
      break;
    case GL_INT_VEC2:
    case GL_BOOL_VEC2:
      integer = true;
      dim = 2;
      break;
    case GL_INT_VEC3:
    case GL_BOOL_VEC3:
      integer = true;
      dim = 3;
      break;
    case GL_INT_VEC4:
    case GL_BOOL_VEC4:
      integer = true;
      dim = 4;
    default:
      break;
  }
  if (dim == 0) {
    luaL_error(L, "gl.GetUniform: invalid type");
  }
  if (integer) {
    GLint values[4];
    glGetUniformiv(prg, loc, values);
    if (dim == 1) {
      lua_pushinteger(L, values[0]);
    } else {
      Array1D<Int>(values, dim).toLUA(L);
    }
  } else {
    GLfloat values[16];
    glGetUniformfv(prg, loc, values);
    if (dim == 1) {
      lua_pushnumber(L, values[0]);
    } else {
      Array1D<Float>(values, dim).toLUA(L);
    }
  }
  return 1;
}

static int lua_glGetVertexAttribPointer(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Uint prg(L, 1);
  Enum param(L, 2);
  GLvoid *ptr=0;
  glGetVertexAttribPointerv(prg, param, &ptr);
  lua_pushlightuserdata(L, ptr);
  return 1;
}

static int lua_glGetVertexAttrib(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Uint attrib(L, 1);
  Enum pname(L, 2);
  switch (pname) {
    case GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING:
    case GL_VERTEX_ATTRIB_ARRAY_ENABLED:
    case GL_VERTEX_ATTRIB_ARRAY_SIZE:
    case GL_VERTEX_ATTRIB_ARRAY_STRIDE:
    case GL_VERTEX_ATTRIB_ARRAY_TYPE:
    case GL_VERTEX_ATTRIB_ARRAY_NORMALIZED: {
      GLint value;
      glGetVertexAttribiv(attrib, pname, &value);
      lua_pushinteger(L, value);
      break;
    }
    case GL_CURRENT_VERTEX_ATTRIB: {
      Array1D<Float> values(4);
      glGetVertexAttribfv(attrib, pname, values);
      values.toLUA(L);
      break;
    }
    default:
      luaL_error(L, "gl.GetVertexAttrib: invalid parameter name");
  }
  return 1;
}

static int lua_glShaderSource(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Uint shader(L, 1);
  Array1D<String> strings(L, 2);
  glShaderSource(shader, strings.size(), strings, 0);
  return 0;
}

static int lua_glStencilFuncSeparate(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Enum, Enum, Int, Uint, glStencilFuncSeparate>::Call(L);
#else
  return WrapFunc4<Enum, Enum, Int, Uint >::Call(L, glStencilFuncSeparate);
#endif
}

static int lua_glStencilMaskSeparate(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Uint, glStencilMaskSeparate>::Call(L);
#else
  return WrapFunc2<Enum, Uint >::Call(L, glStencilMaskSeparate);
#endif
}

static int lua_glStencilOpSeparate(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Enum, Enum, Enum, Enum, glStencilOpSeparate>::Call(L);
#else
  return WrapFunc4<Enum, Enum, Enum, Enum >::Call(L, glStencilOpSeparate);
#endif
}

static int lua_glUniform1f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Int, Float, glUniform1f>::Call(L);
#else
  return WrapFunc2<Int, Float >::Call(L, glUniform1f);
#endif
}
static int lua_glUniform2f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Float, Float, glUniform2f>::Call(L);
#else
  return WrapFunc3<Int, Float, Float >::Call(L, glUniform2f);
#endif
}
static int lua_glUniform3f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Float, Float, Float, glUniform3f>::Call(L);
#else
  return WrapFunc4<Int, Float, Float, Float >::Call(L, glUniform3f);
#endif
}
static int lua_glUniform4f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Int, Float, Float, Float, Float, glUniform4f>::Call(L);
#else
  return WrapFunc5<Int, Float, Float, Float, Float >::Call(L, glUniform4f);
#endif
}
static int lua_glUniform1i(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Int, Int, glUniform1i>::Call(L);
#else
  return WrapFunc2<Int, Int >::Call(L, glUniform1i);
#endif
}
static int lua_glUniform2i(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Int, Int, glUniform2i>::Call(L);
#else
  return WrapFunc3<Int, Int, Int >::Call(L, glUniform2i);
#endif
}
static int lua_glUniform3i(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Int, Int, Int, glUniform3i>::Call(L);
#else
  return WrapFunc4<Int, Int, Int, Int >::Call(L, glUniform3i);
#endif
}
static int lua_glUniform4i(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Int, Int, Int, Int, Int, glUniform4i>::Call(L);
#else
  return WrapFunc5<Int, Int, Int, Int, Int >::Call(L, glUniform4i);
#endif
}
static int lua_glUniform1iv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Sizei, ConstArray<Int>, glUniform1iv>::Call(L);
#else
  return WrapFunc3<Int, Sizei, ConstArray<Int> >::Call(L, glUniform1iv);
#endif
}
static int lua_glUniform2iv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Sizei, ConstArray<Int>, glUniform2iv>::Call(L);
#else
  return WrapFunc3<Int, Sizei, ConstArray<Int> >::Call(L, glUniform2iv);
#endif
}
static int lua_glUniform3iv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Sizei, ConstArray<Int>, glUniform3iv>::Call(L);
#else
  return WrapFunc3<Int, Sizei, ConstArray<Int> >::Call(L, glUniform3iv);
#endif
}
static int lua_glUniform4iv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Sizei, ConstArray<Int>, glUniform4iv>::Call(L);
#else
  return WrapFunc3<Int, Sizei, ConstArray<Int> >::Call(L, glUniform4iv);
#endif
}
static int lua_glUniform1fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Sizei, ConstArray<Float>, glUniform1fv>::Call(L);
#else
  return WrapFunc3<Int, Sizei, ConstArray<Float> >::Call(L, glUniform1fv);
#endif
}
static int lua_glUniform2fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Sizei, ConstArray<Float>, glUniform2fv>::Call(L);
#else
  return WrapFunc3<Int, Sizei, ConstArray<Float> >::Call(L, glUniform2fv);
#endif
}
static int lua_glUniform3fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Sizei, ConstArray<Float>, glUniform3fv>::Call(L);
#else
  return WrapFunc3<Int, Sizei, ConstArray<Float> >::Call(L, glUniform3fv);
#endif
}
static int lua_glUniform4fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Sizei, ConstArray<Float>, glUniform4fv>::Call(L);
#else
  return WrapFunc3<Int, Sizei, ConstArray<Float> >::Call(L, glUniform4fv);
#endif
}

static int lua_glUniformMatrix2fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float>, glUniformMatrix2fv>::Call(L);
#else
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(L, glUniformMatrix2fv);
#endif
}
static int lua_glUniformMatrix3fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float>, glUniformMatrix3fv>::Call(L);
#else
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(L, glUniformMatrix3fv);
#endif
}
static int lua_glUniformMatrix4fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float>, glUniformMatrix4fv>::Call(L);
#else
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(L, glUniformMatrix4fv);
#endif
}

static int lua_glUseProgram(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Uint, glUseProgram>::Call(L);
#else
  return WrapFunc1<Uint >::Call(L, glUseProgram);
#endif
}

static int lua_glValidateProgram(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Uint, glValidateProgram>::Call(L);
#else
  return WrapFunc1<Uint >::Call(L, glValidateProgram);
#endif
}

static int lua_glVertexAttrib1d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, Double, glVertexAttrib1d>::Call(L);
#else
  return WrapFunc2<Uint, Double >::Call(L, glVertexAttrib1d);
#endif
}
static int lua_glVertexAttrib1f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, Float, glVertexAttrib1f>::Call(L);
#else
  return WrapFunc2<Uint, Float >::Call(L, glVertexAttrib1f);
#endif
}
static int lua_glVertexAttrib1s(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, Short, glVertexAttrib1s>::Call(L);
#else
  return WrapFunc2<Uint, Short >::Call(L, glVertexAttrib1s);
#endif
}

static int lua_glVertexAttrib2d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Uint, Double, Double, glVertexAttrib2d>::Call(L);
#else
  return WrapFunc3<Uint, Double, Double >::Call(L, glVertexAttrib2d);
#endif
}
static int lua_glVertexAttrib2f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Uint, Float, Float, glVertexAttrib2f>::Call(L);
#else
  return WrapFunc3<Uint, Float, Float >::Call(L, glVertexAttrib2f);
#endif
}
static int lua_glVertexAttrib2s(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Uint, Short, Short, glVertexAttrib2s>::Call(L);
#else
  return WrapFunc3<Uint, Short, Short >::Call(L, glVertexAttrib2s);
#endif
}
static int lua_glVertexAttrib2dv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Double>, glVertexAttrib2dv>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Double> >::Call(L, glVertexAttrib2dv);
#endif
}
static int lua_glVertexAttrib2fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Float>, glVertexAttrib2fv>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Float> >::Call(L, glVertexAttrib2fv);
#endif
}
static int lua_glVertexAttrib2sv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Short>, glVertexAttrib2sv>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Short> >::Call(L, glVertexAttrib2sv);
#endif
}

static int lua_glVertexAttrib3d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Uint, Double, Double, Double, glVertexAttrib3d>::Call(L);
#else
  return WrapFunc4<Uint, Double, Double, Double >::Call(L, glVertexAttrib3d);
#endif
}
static int lua_glVertexAttrib3f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Uint, Float, Float, Float, glVertexAttrib3f>::Call(L);
#else
  return WrapFunc4<Uint, Float, Float, Float >::Call(L, glVertexAttrib3f);
#endif
}
static int lua_glVertexAttrib3s(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Uint, Short, Short, Short, glVertexAttrib3s>::Call(L);
#else
  return WrapFunc4<Uint, Short, Short, Short >::Call(L, glVertexAttrib3s);
#endif
}
static int lua_glVertexAttrib3dv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Double>, glVertexAttrib3dv>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Double> >::Call(L, glVertexAttrib3dv);
#endif
}
static int lua_glVertexAttrib3fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Float>, glVertexAttrib3fv>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Float> >::Call(L, glVertexAttrib3fv);
#endif
}
static int lua_glVertexAttrib3sv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Short>, glVertexAttrib3sv>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Short> >::Call(L, glVertexAttrib3sv);
#endif
}

static int lua_glVertexAttrib4d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Uint, Double, Double, Double, Double, glVertexAttrib4d>::Call(L);
#else
  return WrapFunc5<Uint, Double, Double, Double, Double >::Call(L, glVertexAttrib4d);
#endif
}
static int lua_glVertexAttrib4f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Uint, Float, Float, Float, Float, glVertexAttrib4f>::Call(L);
#else
  return WrapFunc5<Uint, Float, Float, Float, Float >::Call(L, glVertexAttrib4f);
#endif
}
static int lua_glVertexAttrib4s(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Uint, Short, Short, Short, Short, glVertexAttrib4s>::Call(L);
#else
  return WrapFunc5<Uint, Short, Short, Short, Short >::Call(L, glVertexAttrib4s);
#endif
}
static int lua_glVertexAttrib4Nub(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Uint, Ubyte, Ubyte, Ubyte, Ubyte, glVertexAttrib4Nub>::Call(L);
#else
  return WrapFunc5<Uint, Ubyte, Ubyte, Ubyte, Ubyte >::Call(L, glVertexAttrib4Nub);
#endif
}
static int lua_glVertexAttrib4Nbv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Byte>, glVertexAttrib4Nbv>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Byte> >::Call(L, glVertexAttrib4Nbv);
#endif
}
static int lua_glVertexAttrib4Niv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Int>, glVertexAttrib4Niv>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Int> >::Call(L, glVertexAttrib4Niv);
#endif
}
static int lua_glVertexAttrib4Nsv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Short>, glVertexAttrib4Nsv>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Short> >::Call(L, glVertexAttrib4Nsv);
#endif
}
static int lua_glVertexAttrib4Nubv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Ubyte>, glVertexAttrib4Nubv>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Ubyte> >::Call(L, glVertexAttrib4Nubv);
#endif
}
static int lua_glVertexAttrib4Nuiv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Uint>, glVertexAttrib4Nuiv>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Uint> >::Call(L, glVertexAttrib4Nuiv);
#endif
}
static int lua_glVertexAttrib4Nusv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Ushort>, glVertexAttrib4Nusv>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Ushort> >::Call(L, glVertexAttrib4Nusv);
#endif
}
static int lua_glVertexAttrib4bv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Byte>, glVertexAttrib4bv>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Byte> >::Call(L, glVertexAttrib4bv);
#endif
}
static int lua_glVertexAttrib4ubv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Ubyte>, glVertexAttrib4ubv>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Ubyte> >::Call(L, glVertexAttrib4ubv);
#endif
}
static int lua_glVertexAttrib4sv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Short>, glVertexAttrib4sv>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Short> >::Call(L, glVertexAttrib4sv);
#endif
}
static int lua_glVertexAttrib4usv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Ushort>, glVertexAttrib4usv>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Ushort> >::Call(L, glVertexAttrib4usv);
#endif
}
static int lua_glVertexAttrib4iv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Int>, glVertexAttrib4iv>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Int> >::Call(L, glVertexAttrib4iv);
#endif
}
static int lua_glVertexAttrib4uiv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Uint>, glVertexAttrib4uiv>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Uint> >::Call(L, glVertexAttrib4uiv);
#endif
}
static int lua_glVertexAttrib4fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Float>, glVertexAttrib4fv>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Float> >::Call(L, glVertexAttrib4fv);
#endif
}
static int lua_glVertexAttrib4dv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, ConstArray<Double>, glVertexAttrib4dv>::Call(L);
#else
  return WrapFunc2<Uint, ConstArray<Double> >::Call(L, glVertexAttrib4dv);
#endif
}

static int lua_glVertexAttribPointer(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc6<Uint, Int, Enum, Boolean, Sizei, ConstPtr, glVertexAttribPointer>::Call(L);
#else
  return WrapFunc6<Uint, Int, Enum, Boolean, Sizei, ConstPtr >::Call(L, glVertexAttribPointer);
#endif
}


void Register_GL_2_0_Constants(LuaGL::ConstantMap &constants) {
  if (GLEW_VERSION_2_0) {
    constants["BLEND_EQUATION_RGB"] = GL_BLEND_EQUATION_RGB;
    constants["VERTEX_ATTRIB_ARRAY_ENABLED"] = GL_VERTEX_ATTRIB_ARRAY_ENABLED;
    constants["VERTEX_ATTRIB_ARRAY_SIZE"] = GL_VERTEX_ATTRIB_ARRAY_SIZE;
    constants["VERTEX_ATTRIB_ARRAY_STRIDE"] = GL_VERTEX_ATTRIB_ARRAY_STRIDE;
    constants["VERTEX_ATTRIB_ARRAY_TYPE"] = GL_VERTEX_ATTRIB_ARRAY_TYPE;
    constants["CURRENT_VERTEX_ATTRIB"] = GL_CURRENT_VERTEX_ATTRIB;
    constants["VERTEX_PROGRAM_POINT_SIZE"] = GL_VERTEX_PROGRAM_POINT_SIZE;
    constants["VERTEX_PROGRAM_TWO_SIDE"] = GL_VERTEX_PROGRAM_TWO_SIDE;
    constants["VERTEX_ATTRIB_ARRAY_POINTER"] = GL_VERTEX_ATTRIB_ARRAY_POINTER;
    constants["STENCIL_BACK_FUNC"] = GL_STENCIL_BACK_FUNC;
    constants["STENCIL_BACK_FAIL"] = GL_STENCIL_BACK_FAIL;
    constants["STENCIL_BACK_PASS_DEPTH_FAIL"] = GL_STENCIL_BACK_PASS_DEPTH_FAIL;
    constants["STENCIL_BACK_PASS_DEPTH_PASS"] = GL_STENCIL_BACK_PASS_DEPTH_PASS;
    constants["MAX_DRAW_BUFFERS"] = GL_MAX_DRAW_BUFFERS;
    constants["DRAW_BUFFER0"] = GL_DRAW_BUFFER0;
    constants["DRAW_BUFFER1"] = GL_DRAW_BUFFER1;
    constants["DRAW_BUFFER2"] = GL_DRAW_BUFFER2;
    constants["DRAW_BUFFER3"] = GL_DRAW_BUFFER3;
    constants["DRAW_BUFFER4"] = GL_DRAW_BUFFER4;
    constants["DRAW_BUFFER5"] = GL_DRAW_BUFFER5;
    constants["DRAW_BUFFER6"] = GL_DRAW_BUFFER6;
    constants["DRAW_BUFFER7"] = GL_DRAW_BUFFER7;
    constants["DRAW_BUFFER8"] = GL_DRAW_BUFFER8;
    constants["DRAW_BUFFER9"] = GL_DRAW_BUFFER9;
    constants["DRAW_BUFFER10"] = GL_DRAW_BUFFER10;
    constants["DRAW_BUFFER11"] = GL_DRAW_BUFFER11;
    constants["DRAW_BUFFER12"] = GL_DRAW_BUFFER12;
    constants["DRAW_BUFFER13"] = GL_DRAW_BUFFER13;
    constants["DRAW_BUFFER14"] = GL_DRAW_BUFFER14;
    constants["DRAW_BUFFER15"] = GL_DRAW_BUFFER15;
    constants["BLEND_EQUATION_ALPHA"] = GL_BLEND_EQUATION_ALPHA;
    constants["POINT_SPRITE"] = GL_POINT_SPRITE;
    constants["COORD_REPLACE"] = GL_COORD_REPLACE;
    constants["MAX_VERTEX_ATTRIBS"] = GL_MAX_VERTEX_ATTRIBS;
    constants["VERTEX_ATTRIB_ARRAY_NORMALIZED"] = GL_VERTEX_ATTRIB_ARRAY_NORMALIZED;
    constants["MAX_TEXTURE_COORDS"] = GL_MAX_TEXTURE_COORDS;
    constants["MAX_TEXTURE_IMAGE_UNITS"] = GL_MAX_TEXTURE_IMAGE_UNITS;
    constants["FRAGMENT_SHADER"] = GL_FRAGMENT_SHADER;
    constants["VERTEX_SHADER"] = GL_VERTEX_SHADER;
    constants["MAX_FRAGMENT_UNIFORM_COMPONENTS"] = GL_MAX_FRAGMENT_UNIFORM_COMPONENTS;
    constants["MAX_VERTEX_UNIFORM_COMPONENTS"] = GL_MAX_VERTEX_UNIFORM_COMPONENTS;
    constants["MAX_VARYING_FLOATS"] = GL_MAX_VARYING_FLOATS;
    constants["MAX_VERTEX_TEXTURE_IMAGE_UNITS"] = GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS;
    constants["MAX_COMBINED_TEXTURE_IMAGE_UNITS"] = GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS;
    constants["SHADER_TYPE"] = GL_SHADER_TYPE;
    constants["FLOAT_VEC2"] = GL_FLOAT_VEC2;
    constants["FLOAT_VEC3"] = GL_FLOAT_VEC3;
    constants["FLOAT_VEC4"] = GL_FLOAT_VEC4;
    constants["INT_VEC2"] = GL_INT_VEC2;
    constants["INT_VEC3"] = GL_INT_VEC3;
    constants["INT_VEC4"] = GL_INT_VEC4;
    constants["BOOL"] = GL_BOOL;
    constants["BOOL_VEC2"] = GL_BOOL_VEC2;
    constants["BOOL_VEC3"] = GL_BOOL_VEC3;
    constants["BOOL_VEC4"] = GL_BOOL_VEC4;
    constants["FLOAT_MAT2"] = GL_FLOAT_MAT2;
    constants["FLOAT_MAT3"] = GL_FLOAT_MAT3;
    constants["FLOAT_MAT4"] = GL_FLOAT_MAT4;
    constants["SAMPLER_1D"] = GL_SAMPLER_1D;
    constants["SAMPLER_2D"] = GL_SAMPLER_2D;
    constants["SAMPLER_3D"] = GL_SAMPLER_3D;
    constants["SAMPLER_CUBE"] = GL_SAMPLER_CUBE;
    constants["SAMPLER_1D_SHADOW"] = GL_SAMPLER_1D_SHADOW;
    constants["SAMPLER_2D_SHADOW"] = GL_SAMPLER_2D_SHADOW;
    constants["DELETE_STATUS"] = GL_DELETE_STATUS;
    constants["COMPILE_STATUS"] = GL_COMPILE_STATUS;
    constants["LINK_STATUS"] = GL_LINK_STATUS;
    constants["VALIDATE_STATUS"] = GL_VALIDATE_STATUS;
    constants["INFO_LOG_LENGTH"] = GL_INFO_LOG_LENGTH;
    constants["ATTACHED_SHADERS"] = GL_ATTACHED_SHADERS;
    constants["ACTIVE_UNIFORMS"] = GL_ACTIVE_UNIFORMS;
    constants["ACTIVE_UNIFORM_MAX_LENGTH"] = GL_ACTIVE_UNIFORM_MAX_LENGTH;
    constants["SHADER_SOURCE_LENGTH"] = GL_SHADER_SOURCE_LENGTH;
    constants["ACTIVE_ATTRIBUTES"] = GL_ACTIVE_ATTRIBUTES;
    constants["ACTIVE_ATTRIBUTE_MAX_LENGTH"] = GL_ACTIVE_ATTRIBUTE_MAX_LENGTH;
    constants["FRAGMENT_SHADER_DERIVATIVE_HINT"] = GL_FRAGMENT_SHADER_DERIVATIVE_HINT;
    constants["SHADING_LANGUAGE_VERSION"] = GL_SHADING_LANGUAGE_VERSION;
    constants["CURRENT_PROGRAM"] = GL_CURRENT_PROGRAM;
    constants["POINT_SPRITE_COORD_ORIGIN"] = GL_POINT_SPRITE_COORD_ORIGIN;
    constants["LOWER_LEFT"] = GL_LOWER_LEFT;
    constants["UPPER_LEFT"] = GL_UPPER_LEFT;
    constants["STENCIL_BACK_REF"] = GL_STENCIL_BACK_REF;
    constants["STENCIL_BACK_VALUE_MASK"] = GL_STENCIL_BACK_VALUE_MASK;
    constants["STENCIL_BACK_WRITEMASK"] = GL_STENCIL_BACK_WRITEMASK;
    
    LuaGL &gl = LuaGL::Instance();
    // GL_ARB_shader_objects
    // x
    // GL_ARB_vertex_shader
    gl.addParamDim(LuaGL::Integerv, GL_MAX_VERTEX_ATTRIBS, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_VERTEX_UNIFORM_COMPONENTS, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_VARYING_FLOATS, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_TEXTURE_IMAGE_UNITS, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_TEXTURE_COORDS, 1);
    // GL_ARB_fragment_shader
    gl.addParamDim(LuaGL::Integerv, GL_FRAGMENT_SHADER_DERIVATIVE_HINT, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_FRAGMENT_UNIFORM_COMPONENTS, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_TEXTURE_IMAGE_UNITS, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_TEXTURE_COORDS, 1);
    // GL_ARB_shading_language_100
    // x
    // GL_ARB_draw_buffers
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER0, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER1, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER2, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER3, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER4, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER5, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER6, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER7, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER8, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER9, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER10, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER11, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER12, 1);
    gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER15, 1);
    gl.addParamDim(LuaGL::Integerv, GL_MAX_DRAW_BUFFERS, 1);
    // GL_ARB_texture_non_power_of_two
    // x
    // GL_ARB_point_sprite [depends on GL_ARB_point_parameter]
    gl.addParamDim(LuaGL::TexEnviv, GL_COORD_REPLACE, 1);
    gl.addParamDim(LuaGL::Integerv, GL_POINT_SPRITE_COORD_ORIGIN, 1);
    // GL_EXT_blend_equation_separate
    gl.addParamDim(LuaGL::Integerv, GL_BLEND_EQUATION_RGB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_BLEND_EQUATION_ALPHA, 1);
    // GL_ATI_separate_stencil, GL_EXT_stencil_two_side
    gl.addParamDim(LuaGL::Integerv, GL_STENCIL_BACK_FUNC, 1);
    gl.addParamDim(LuaGL::Integerv, GL_STENCIL_BACK_FAIL, 1);
    gl.addParamDim(LuaGL::Integerv, GL_STENCIL_BACK_PASS_DEPTH_FAIL, 1);
    gl.addParamDim(LuaGL::Integerv, GL_STENCIL_BACK_PASS_DEPTH_PASS, 1);
    gl.addParamDim(LuaGL::Integerv, GL_STENCIL_BACK_VALUE_MASK, 1);
    gl.addParamDim(LuaGL::Integerv, GL_STENCIL_BACK_REF, 1);
    gl.addParamDim(LuaGL::Integerv, GL_STENCIL_BACK_WRITEMASK, 1);
    // Other
    gl.addParamDim(LuaGL::Integerv, GL_CURRENT_PROGRAM, 1);
    gl.addParamDim(LuaGL::Shaderiv, GL_SHADER_TYPE, 1);
    gl.addParamDim(LuaGL::Shaderiv, GL_DELETE_STATUS, 1);
    gl.addParamDim(LuaGL::Shaderiv, GL_COMPILE_STATUS, 1);
    gl.addParamDim(LuaGL::Shaderiv, GL_INFO_LOG_LENGTH, 1);
    gl.addParamDim(LuaGL::Shaderiv, GL_SHADER_SOURCE_LENGTH, 1);
    gl.addParamDim(LuaGL::Programiv, GL_DELETE_STATUS, 1);
    gl.addParamDim(LuaGL::Programiv, GL_LINK_STATUS, 1);
    gl.addParamDim(LuaGL::Programiv, GL_VALIDATE_STATUS, 1);
    gl.addParamDim(LuaGL::Programiv, GL_ATTACHED_SHADERS, 1);
    gl.addParamDim(LuaGL::Programiv, GL_INFO_LOG_LENGTH, 1);
    gl.addParamDim(LuaGL::Programiv, GL_ACTIVE_UNIFORMS, 1);
    gl.addParamDim(LuaGL::Programiv, GL_ACTIVE_UNIFORM_MAX_LENGTH, 1);
    gl.addParamDim(LuaGL::Programiv, GL_ACTIVE_ATTRIBUTES, 1);
    gl.addParamDim(LuaGL::Programiv, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, 1);
  }
}

void Register_GL_2_0_Functions(lua_State *L, int module) {
  if (GLEW_VERSION_2_0) {
#ifdef _DEBUG
    std::cout << "Supports OpenGL 2.0" << std::endl;
#endif
    LuaGL::Instance().setVersion(2.0);
    REGISTER_GL_FUNC(L, module, AttachShader);
    REGISTER_GL_FUNC(L, module, CreateShader);
    REGISTER_GL_FUNC(L, module, CreateProgram);
    REGISTER_GL_FUNC(L, module, DetachShader);
    REGISTER_GL_FUNC(L, module, DeleteShader);
    REGISTER_GL_FUNC(L, module, DeleteProgram);
    REGISTER_GL_FUNC(L, module, BindAttribLocation);
    REGISTER_GL_FUNC(L, module, BlendEquationSeparate);
    REGISTER_GL_FUNC(L, module, CompileShader);
    REGISTER_GL_FUNC(L, module, DisableVertexAttribArray);
    REGISTER_GL_FUNC(L, module, DrawBuffers);
    REGISTER_GL_FUNC(L, module, EnableVertexAttribArray);
    REGISTER_GL_FUNC(L, module, GetActiveAttrib);
    REGISTER_GL_FUNC(L, module, GetActiveUniform);
    REGISTER_GL_FUNC(L, module, GetAttachedShaders);
    REGISTER_GL_FUNC(L, module, GetAttribLocation);
    REGISTER_GL_FUNC(L, module, GetProgramInfoLog);
    REGISTER_GL_FUNC(L, module, GetProgram);
    REGISTER_GL_FUNC(L, module, GetShaderInfoLog);
    REGISTER_GL_FUNC(L, module, GetShaderSource);
    REGISTER_GL_FUNC(L, module, GetShader);
    REGISTER_GL_FUNC(L, module, GetUniformLocation);
    REGISTER_GL_FUNC(L, module, IsProgram);
    REGISTER_GL_FUNC(L, module, IsShader);
    REGISTER_GL_FUNC(L, module, LinkProgram);
    REGISTER_GL_FUNC(L, module, GetUniform);
    REGISTER_GL_FUNC(L, module, GetVertexAttribPointer);
    REGISTER_GL_FUNC(L, module, GetVertexAttrib);
    REGISTER_GL_FUNC(L, module, ShaderSource);
    REGISTER_GL_FUNC(L, module, StencilFuncSeparate);
    REGISTER_GL_FUNC(L, module, StencilMaskSeparate);
    REGISTER_GL_FUNC(L, module, StencilOpSeparate);
    REGISTER_GL_FUNC(L, module, Uniform1f);
    REGISTER_GL_FUNC(L, module, Uniform2f);
    REGISTER_GL_FUNC(L, module, Uniform3f);
    REGISTER_GL_FUNC(L, module, Uniform4f);
    REGISTER_GL_FUNC(L, module, Uniform1i);
    REGISTER_GL_FUNC(L, module, Uniform2i);
    REGISTER_GL_FUNC(L, module, Uniform3i);
    REGISTER_GL_FUNC(L, module, Uniform4i);
    REGISTER_GL_FUNC(L, module, Uniform1iv);
    REGISTER_GL_FUNC(L, module, Uniform2iv);
    REGISTER_GL_FUNC(L, module, Uniform3iv);
    REGISTER_GL_FUNC(L, module, Uniform4iv);
    REGISTER_GL_FUNC(L, module, Uniform1fv);
    REGISTER_GL_FUNC(L, module, Uniform2fv);
    REGISTER_GL_FUNC(L, module, Uniform3fv);
    REGISTER_GL_FUNC(L, module, Uniform4fv);
    REGISTER_GL_FUNC(L, module, UniformMatrix2fv);
    REGISTER_GL_FUNC(L, module, UniformMatrix3fv);
    REGISTER_GL_FUNC(L, module, UniformMatrix4fv);
    REGISTER_GL_FUNC(L, module, UseProgram);
    REGISTER_GL_FUNC(L, module, ValidateProgram);
    REGISTER_GL_FUNC(L, module, VertexAttrib1f);
    REGISTER_GL_FUNC(L, module, VertexAttrib1d);
    REGISTER_GL_FUNC(L, module, VertexAttrib1s);
    REGISTER_GL_FUNC(L, module, VertexAttrib2f);
    REGISTER_GL_FUNC(L, module, VertexAttrib2d);
    REGISTER_GL_FUNC(L, module, VertexAttrib2s);
    REGISTER_GL_FUNC(L, module, VertexAttrib3f);
    REGISTER_GL_FUNC(L, module, VertexAttrib3d);
    REGISTER_GL_FUNC(L, module, VertexAttrib3s);
    REGISTER_GL_FUNC(L, module, VertexAttrib2fv);
    REGISTER_GL_FUNC(L, module, VertexAttrib2dv);
    REGISTER_GL_FUNC(L, module, VertexAttrib2sv);
    REGISTER_GL_FUNC(L, module, VertexAttrib3fv);
    REGISTER_GL_FUNC(L, module, VertexAttrib3dv);
    REGISTER_GL_FUNC(L, module, VertexAttrib3sv);
    REGISTER_GL_FUNC(L, module, VertexAttrib4f);
    REGISTER_GL_FUNC(L, module, VertexAttrib4d);
    REGISTER_GL_FUNC(L, module, VertexAttrib4s);
    REGISTER_GL_FUNC(L, module, VertexAttrib4Nub);
    REGISTER_GL_FUNC(L, module, VertexAttrib4Nbv);
    REGISTER_GL_FUNC(L, module, VertexAttrib4Niv);
    REGISTER_GL_FUNC(L, module, VertexAttrib4Nsv);
    REGISTER_GL_FUNC(L, module, VertexAttrib4Nubv);
    REGISTER_GL_FUNC(L, module, VertexAttrib4Nuiv);
    REGISTER_GL_FUNC(L, module, VertexAttrib4Nusv);
    REGISTER_GL_FUNC(L, module, VertexAttrib4bv);
    REGISTER_GL_FUNC(L, module, VertexAttrib4ubv);
    REGISTER_GL_FUNC(L, module, VertexAttrib4sv);
    REGISTER_GL_FUNC(L, module, VertexAttrib4usv);
    REGISTER_GL_FUNC(L, module, VertexAttrib4iv);
    REGISTER_GL_FUNC(L, module, VertexAttrib4uiv);
    REGISTER_GL_FUNC(L, module, VertexAttrib4fv);
    REGISTER_GL_FUNC(L, module, VertexAttrib4dv);
    REGISTER_GL_FUNC(L, module, VertexAttribPointer);
  }
}

