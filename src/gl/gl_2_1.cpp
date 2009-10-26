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

static int lua_glUniformMatrix2x3fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float>, glUniformMatrix2x3fv>::Call(L);
#else
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(L, glUniformMatrix2x3fv);
#endif
}
static int lua_glUniformMatrix2x4fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float>, glUniformMatrix2x4fv>::Call(L);
#else
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(L, glUniformMatrix2x4fv);
#endif
}
static int lua_glUniformMatrix3x2fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float>, glUniformMatrix3x2fv>::Call(L);
#else
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(L, glUniformMatrix3x2fv);
#endif
}
static int lua_glUniformMatrix3x4fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float>, glUniformMatrix3x4fv>::Call(L);
#else
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(L, glUniformMatrix3x4fv);
#endif
}
static int lua_glUniformMatrix4x2fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float>, glUniformMatrix4x2fv>::Call(L);
#else
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(L, glUniformMatrix4x2fv);
#endif
}
static int lua_glUniformMatrix4x3fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float>, glUniformMatrix4x3fv>::Call(L);
#else
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(L, glUniformMatrix4x3fv);
#endif
}

void Register_GL_2_1_Constants(LuaGL::ConstantMap &constants) {
  if (GLEW_VERSION_2_1) {
    constants["CURRENT_RASTER_SECONDARY_COLOR"] = GL_CURRENT_RASTER_SECONDARY_COLOR;
    constants["PIXEL_PACK_BUFFER"] = GL_PIXEL_PACK_BUFFER;
    constants["PIXEL_UNPACK_BUFFER"] = GL_PIXEL_UNPACK_BUFFER;
    constants["PIXEL_PACK_BUFFER_BINDING"] = GL_PIXEL_PACK_BUFFER_BINDING;
    constants["PIXEL_UNPACK_BUFFER_BINDING"] = GL_PIXEL_UNPACK_BUFFER_BINDING;
    constants["FLOAT_MAT2x3"] = GL_FLOAT_MAT2x3;
    constants["FLOAT_MAT2x4"] = GL_FLOAT_MAT2x4;
    constants["FLOAT_MAT3x2"] = GL_FLOAT_MAT3x2;
    constants["FLOAT_MAT3x4"] = GL_FLOAT_MAT3x4;
    constants["FLOAT_MAT4x2"] = GL_FLOAT_MAT4x2;
    constants["FLOAT_MAT4x3"] = GL_FLOAT_MAT4x3;
    constants["SRGB"] = GL_SRGB;
    constants["SRGB8"] = GL_SRGB8;
    constants["SRGB_ALPHA"] = GL_SRGB_ALPHA;
    constants["SRGB8_ALPHA8"] = GL_SRGB8_ALPHA8;
    constants["SLUMINANCE_ALPHA"] = GL_SLUMINANCE_ALPHA;
    constants["SLUMINANCE8_ALPHA8"] = GL_SLUMINANCE8_ALPHA8;
    constants["SLUMINANCE"] = GL_SLUMINANCE;
    constants["SLUMINANCE8"] = GL_SLUMINANCE8;
    constants["COMPRESSED_SRGB"] = GL_COMPRESSED_SRGB;
    constants["COMPRESSED_SRGB_ALPHA"] = GL_COMPRESSED_SRGB_ALPHA;
    constants["COMPRESSED_SLUMINANCE"] = GL_COMPRESSED_SLUMINANCE;
    constants["COMPRESSED_SLUMINANCE_ALPHA"] = GL_COMPRESSED_SLUMINANCE_ALPHA;
    
    LuaGL &gl = LuaGL::Instance();
    // GL_ARB_pixel_buffer_object
    gl.addParamDim(LuaGL::Integerv, GL_PIXEL_PACK_BUFFER_BINDING, 1);
    gl.addParamDim(LuaGL::Integerv, GL_PIXEL_UNPACK_BUFFER_BINDING, 1);
    // GL_EXT_texture_sRGB
    // x
    // Other
    gl.addParamDim(LuaGL::Floatv, GL_CURRENT_RASTER_SECONDARY_COLOR, 4);
  }
}

void Register_GL_2_1_Functions(lua_State *L, int module) {
  if (GLEW_VERSION_2_1) {
#ifdef _DEBUG
    std::cout << "Supports OpenGL 2.1" << std::endl;
#endif
    LuaGL::Instance().setVersion(2.1);
    REGISTER_GL_FUNC(L, module, UniformMatrix2x3fv);
    REGISTER_GL_FUNC(L, module, UniformMatrix2x4fv);
    REGISTER_GL_FUNC(L, module, UniformMatrix3x2fv);
    REGISTER_GL_FUNC(L, module, UniformMatrix3x4fv);
    REGISTER_GL_FUNC(L, module, UniformMatrix4x2fv);
    REGISTER_GL_FUNC(L, module, UniformMatrix4x3fv);
  }
}

