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

static int lua_glBlendColor(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Clampf, Clampf, Clampf, Clampf, glBlendColor>::Call(L);
#else
  return WrapFunc4<Clampf, Clampf, Clampf, Clampf >::Call(L, glBlendColor);
#endif
}

static int lua_glBlendEquation(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Enum, glBlendEquation>::Call(L);
#else
  return WrapFunc1<Enum >::Call(L, glBlendEquation);
#endif
}

static int lua_glBlendFuncSeparate(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Enum, Enum, Enum, Enum, glBlendFuncSeparate>::Call(L);
#else
  return WrapFunc4<Enum, Enum, Enum, Enum >::Call(L, glBlendFuncSeparate);
#endif
}

static int lua_glFogCoordPointer(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Sizei, ConstPtr, glFogCoordPointer>::Call(L);
#else
  return WrapFunc3<Enum, Sizei, ConstPtr >::Call(L, glFogCoordPointer);
#endif
}

static int lua_glFogCoordd(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Double, glFogCoordd>::Call(L);
#else
  return WrapFunc1<Double >::Call(L, glFogCoordd);
#endif
}
static int lua_glFogCoordf(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Float, glFogCoordf>::Call(L);
#else
  return WrapFunc1<Float >::Call(L, glFogCoordf);
#endif
}

static int lua_glMultiDrawArrays(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Enum, TypedPtr<Int>, TypedPtr<Sizei>, Sizei, glMultiDrawArrays>::Call(L);
#else
  return WrapFunc4<Enum, TypedPtr<Int>, TypedPtr<Sizei>, Sizei >::Call(L, glMultiDrawArrays);
#endif
}

static int lua_glMultiDrawElements(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Enum, Array<Sizei>, Enum, Array<ConstPtr>, Sizei, glMultiDrawElements>::Call(L);
#else
  return WrapFunc5<Enum, Array<Sizei>, Enum, Array<ConstPtr>, Sizei >::Call(L, glMultiDrawElements);
#endif
}

static int lua_glPointParameterf(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Float, glPointParameterf>::Call(L);
#else
  return WrapFunc2<Enum, Float >::Call(L, glPointParameterf);
#endif
}
static int lua_glPointParameterfv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Array<Float>, glPointParameterfv>::Call(L);
#else
  return WrapFunc2<Enum, Array<Float> >::Call(L, glPointParameterfv);
#endif
}
static int lua_glPointParameteri(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Int, glPointParameteri>::Call(L);
#else
  return WrapFunc2<Enum, Int >::Call(L, glPointParameteri);
#endif
}
static int lua_glPointParameteriv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Array<Int>, glPointParameteriv>::Call(L);
#else
  return WrapFunc2<Enum, Array<Int> >::Call(L, glPointParameteriv);
#endif
}

static int lua_glSecondaryColor3b(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Byte, Byte, Byte, glSecondaryColor3b>::Call(L);
#else
  return WrapFunc3<Byte, Byte, Byte >::Call(L, glSecondaryColor3b);
#endif
}
static int lua_glSecondaryColor3bv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Byte>, glSecondaryColor3bv>::Call(L);
#else
  return WrapFunc1<ConstArray<Byte> >::Call(L, glSecondaryColor3bv);
#endif
}
static int lua_glSecondaryColor3d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Double, Double, Double, glSecondaryColor3d>::Call(L);
#else
  return WrapFunc3<Double, Double, Double >::Call(L, glSecondaryColor3d);
#endif
}
static int lua_glSecondaryColor3dv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Double>, glSecondaryColor3dv>::Call(L);
#else
  return WrapFunc1<ConstArray<Double> >::Call(L, glSecondaryColor3dv);
#endif
}
static int lua_glSecondaryColor3f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Float, Float, Float, glSecondaryColor3f>::Call(L);
#else
  return WrapFunc3<Float, Float, Float >::Call(L, glSecondaryColor3f);
#endif
}
static int lua_glSecondaryColor3fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Float>, glSecondaryColor3fv>::Call(L);
#else
  return WrapFunc1<ConstArray<Float> >::Call(L, glSecondaryColor3fv);
#endif
}
static int lua_glSecondaryColor3i(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Int, Int, glSecondaryColor3i>::Call(L);
#else
  return WrapFunc3<Int, Int, Int >::Call(L, glSecondaryColor3i);
#endif
}
static int lua_glSecondaryColor3iv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Int>, glSecondaryColor3iv>::Call(L);
#else
  return WrapFunc1<ConstArray<Int> >::Call(L, glSecondaryColor3iv);
#endif
}
static int lua_glSecondaryColor3s(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Short, Short, Short, glSecondaryColor3s>::Call(L);
#else
  return WrapFunc3<Short, Short, Short >::Call(L, glSecondaryColor3s);
#endif
}
static int lua_glSecondaryColor3sv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Short>, glSecondaryColor3sv>::Call(L);
#else
  return WrapFunc1<ConstArray<Short> >::Call(L, glSecondaryColor3sv);
#endif
}
static int lua_glSecondaryColor3ub(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Ubyte, Ubyte, Ubyte, glSecondaryColor3ub>::Call(L);
#else
  return WrapFunc3<Ubyte, Ubyte, Ubyte >::Call(L, glSecondaryColor3ub);
#endif
}
static int lua_glSecondaryColor3ubv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Ubyte>, glSecondaryColor3ubv>::Call(L);
#else
  return WrapFunc1<ConstArray<Ubyte> >::Call(L, glSecondaryColor3ubv);
#endif
}
static int lua_glSecondaryColor3ui(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Uint, Uint, Uint, glSecondaryColor3ui>::Call(L);
#else
  return WrapFunc3<Uint, Uint, Uint >::Call(L, glSecondaryColor3ui);
#endif
}
static int lua_glSecondaryColor3uiv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Uint>, glSecondaryColor3uiv>::Call(L);
#else
  return WrapFunc1<ConstArray<Uint> >::Call(L, glSecondaryColor3uiv);
#endif
}
static int lua_glSecondaryColor3us(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Ushort, Ushort, Ushort, glSecondaryColor3us>::Call(L);
#else
  return WrapFunc3<Ushort, Ushort, Ushort >::Call(L, glSecondaryColor3us);
#endif
}
static int lua_glSecondaryColor3usv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Ushort>, glSecondaryColor3usv>::Call(L);
#else
  return WrapFunc1<ConstArray<Ushort> >::Call(L, glSecondaryColor3usv);
#endif
}

static int lua_glSecondaryColorPointer(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Enum, Sizei, Ptr, glSecondaryColorPointer>::Call(L);
#else
  return WrapFunc4<Int, Enum, Sizei, Ptr >::Call(L, glSecondaryColorPointer);
#endif
}

static int lua_glWindowPos2d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Double, Double, glWindowPos2d>::Call(L);
#else
  return WrapFunc2<Double, Double >::Call(L, glWindowPos2d);
#endif
}
static int lua_glWindowPos2dv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Double>, glWindowPos2dv>::Call(L);
#else
  return WrapFunc1<ConstArray<Double> >::Call(L, glWindowPos2dv);
#endif
}
static int lua_glWindowPos2f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Float, Float, glWindowPos2f>::Call(L);
#else
  return WrapFunc2<Float, Float >::Call(L, glWindowPos2f);
#endif
}
static int lua_glWindowPos2fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Float>, glWindowPos2fv>::Call(L);
#else
  return WrapFunc1<ConstArray<Float> >::Call(L, glWindowPos2fv);
#endif
}
static int lua_glWindowPos2i(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Int, Int, glWindowPos2i>::Call(L);
#else
  return WrapFunc2<Int, Int >::Call(L, glWindowPos2i);
#endif
}
static int lua_glWindowPos2iv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Int>, glWindowPos2iv>::Call(L);
#else
  return WrapFunc1<ConstArray<Int> >::Call(L, glWindowPos2iv);
#endif
}
static int lua_glWindowPos2s(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Short, Short, glWindowPos2s>::Call(L);
#else
  return WrapFunc2<Short, Short >::Call(L, glWindowPos2s);
#endif
}
static int lua_glWindowPos2sv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Short>, glWindowPos2sv>::Call(L);
#else
  return WrapFunc1<ConstArray<Short> >::Call(L, glWindowPos2sv);
#endif
}
static int lua_glWindowPos3d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Double, Double, Double, glWindowPos3d>::Call(L);
#else
  return WrapFunc3<Double, Double, Double >::Call(L, glWindowPos3d);
#endif
}
static int lua_glWindowPos3dv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Double>, glWindowPos3dv>::Call(L);
#else
  return WrapFunc1<ConstArray<Double> >::Call(L, glWindowPos3dv);
#endif
}
static int lua_glWindowPos3f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Float, Float, Float, glWindowPos3f>::Call(L);
#else
  return WrapFunc3<Float, Float, Float >::Call(L, glWindowPos3f);
#endif
}
static int lua_glWindowPos3fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Float>, glWindowPos3fv>::Call(L);
#else
  return WrapFunc1<ConstArray<Float> >::Call(L, glWindowPos3fv);
#endif
}
static int lua_glWindowPos3i(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Int, Int, glWindowPos3i>::Call(L);
#else
  return WrapFunc3<Int, Int, Int >::Call(L, glWindowPos3i);
#endif
}
static int lua_glWindowPos3iv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Int>, glWindowPos3iv>::Call(L);
#else
  return WrapFunc1<ConstArray<Int> >::Call(L, glWindowPos3iv);
#endif
}
static int lua_glWindowPos3s(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Short, Short, Short, glWindowPos3s>::Call(L);
#else
  return WrapFunc3<Short, Short, Short >::Call(L, glWindowPos3s);
#endif
}
static int lua_glWindowPos3sv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Short>, glWindowPos3sv>::Call(L);
#else
  return WrapFunc1<ConstArray<Short> >::Call(L, glWindowPos3sv);
#endif
}

void Register_GL_1_4_Constants(LuaGL::ConstantMap &constants) {
  if (GLEW_VERSION_1_4) {
    constants["BLEND_DST_RGB"] = GL_BLEND_DST_RGB;
    constants["BLEND_SRC_RGB"] = GL_BLEND_SRC_RGB;
    constants["BLEND_DST_ALPHA"] = GL_BLEND_DST_ALPHA;
    constants["BLEND_SRC_ALPHA"] = GL_BLEND_SRC_ALPHA;
    constants["POINT_SIZE_MIN"] = GL_POINT_SIZE_MIN;
    constants["POINT_SIZE_MAX"] = GL_POINT_SIZE_MAX;
    constants["POINT_FADE_THRESHOLD_SIZE"] = GL_POINT_FADE_THRESHOLD_SIZE;
    constants["POINT_DISTANCE_ATTENUATION"] = GL_POINT_DISTANCE_ATTENUATION;
    constants["GENERATE_MIPMAP"] = GL_GENERATE_MIPMAP;
    constants["GENERATE_MIPMAP_HINT"] = GL_GENERATE_MIPMAP_HINT;
    constants["DEPTH_COMPONENT16"] = GL_DEPTH_COMPONENT16;
    constants["DEPTH_COMPONENT24"] = GL_DEPTH_COMPONENT24;
    constants["DEPTH_COMPONENT32"] = GL_DEPTH_COMPONENT32;
    constants["MIRRORED_REPEAT"] = GL_MIRRORED_REPEAT;
    constants["FOG_COORDINATE_SOURCE"] = GL_FOG_COORDINATE_SOURCE;
    constants["FOG_COORDINATE"] = GL_FOG_COORDINATE;
    constants["FRAGMENT_DEPTH"] = GL_FRAGMENT_DEPTH;
    constants["CURRENT_FOG_COORDINATE"] = GL_CURRENT_FOG_COORDINATE;
    constants["FOG_COORDINATE_ARRAY_TYPE"] = GL_FOG_COORDINATE_ARRAY_TYPE;
    constants["FOG_COORDINATE_ARRAY_STRIDE"] = GL_FOG_COORDINATE_ARRAY_STRIDE;
    constants["FOG_COORDINATE_ARRAY_POINTER"] = GL_FOG_COORDINATE_ARRAY_POINTER;
    constants["FOG_COORDINATE_ARRAY"] = GL_FOG_COORDINATE_ARRAY;
    constants["COLOR_SUM"] = GL_COLOR_SUM;
    constants["CURRENT_SECONDARY_COLOR"] = GL_CURRENT_SECONDARY_COLOR;
    constants["SECONDARY_COLOR_ARRAY_SIZE"] = GL_SECONDARY_COLOR_ARRAY_SIZE;
    constants["SECONDARY_COLOR_ARRAY_TYPE"] = GL_SECONDARY_COLOR_ARRAY_TYPE;
    constants["SECONDARY_COLOR_ARRAY_STRIDE"] = GL_SECONDARY_COLOR_ARRAY_STRIDE;
    constants["SECONDARY_COLOR_ARRAY_POINTER"] = GL_SECONDARY_COLOR_ARRAY_POINTER;
    constants["SECONDARY_COLOR_ARRAY"] = GL_SECONDARY_COLOR_ARRAY;
    constants["MAX_TEXTURE_LOD_BIAS"] = GL_MAX_TEXTURE_LOD_BIAS;
    constants["TEXTURE_FILTER_CONTROL"] = GL_TEXTURE_FILTER_CONTROL;
    constants["TEXTURE_LOD_BIAS"] = GL_TEXTURE_LOD_BIAS;
    constants["INCR_WRAP"] = GL_INCR_WRAP;
    constants["DECR_WRAP"] = GL_DECR_WRAP;
    constants["TEXTURE_DEPTH_SIZE"] = GL_TEXTURE_DEPTH_SIZE;
    constants["DEPTH_TEXTURE_MODE"] = GL_DEPTH_TEXTURE_MODE;
    constants["TEXTURE_COMPARE_MODE"] = GL_TEXTURE_COMPARE_MODE;
    constants["TEXTURE_COMPARE_FUNC"] = GL_TEXTURE_COMPARE_FUNC;
    constants["COMPARE_R_TO_TEXTURE"] = GL_COMPARE_R_TO_TEXTURE;
    
    LuaGL &gl = LuaGL::Instance();
    // GL_SGIS_generate_mipmap
    gl.addParamDim(LuaGL::TexParameteriv, GL_GENERATE_MIPMAP, 1);
    gl.addParamDim(LuaGL::Integerv, GL_GENERATE_MIPMAP_HINT, 1);
    // GL_NV_blend_square
    gl.addParamDim(LuaGL::Integerv, GL_BLEND_SRC, 1);
    gl.addParamDim(LuaGL::Integerv, GL_BLEND_DST, 1);
    // GL_ARB_depth_texture
    gl.addParamDim(LuaGL::TexLevelParameteriv, GL_TEXTURE_DEPTH_SIZE, 1);
    gl.addParamDim(LuaGL::TexParameteriv, GL_DEPTH_TEXTURE_MODE, 1);
    // GL_ARB_shadow
    gl.addParamDim(LuaGL::TexParameteriv, GL_TEXTURE_COMPARE_MODE, 1);
    gl.addParamDim(LuaGL::TexParameteriv, GL_TEXTURE_COMPARE_FUNC, 1);
    // GL_EXT_fog_coord
    gl.addParamDim(LuaGL::Floatv, GL_CURRENT_FOG_COORDINATE, 1);
    gl.addParamDim(LuaGL::Integerv, GL_FOG_COORDINATE_ARRAY_TYPE, 1);
    gl.addParamDim(LuaGL::Integerv, GL_FOG_COORDINATE_ARRAY_STRIDE, 1);
    gl.addParamDim(LuaGL::Integerv, GL_FOG_COORDINATE_SOURCE, 1);
    // GL_EXT_multi_draw_arrays
    // x
    // GL_ARB_point_parameters
    gl.addParamDim(LuaGL::Floatv, GL_POINT_SIZE_MIN, 1);
    gl.addParamDim(LuaGL::Floatv, GL_POINT_SIZE_MAX, 1);
    gl.addParamDim(LuaGL::Floatv, GL_POINT_FADE_THRESHOLD_SIZE, 1);
    gl.addParamDim(LuaGL::Floatv, GL_POINT_DISTANCE_ATTENUATION, 3);
    // GL_EXT_secondary_color
    gl.addParamDim(LuaGL::Floatv, GL_CURRENT_SECONDARY_COLOR, 4);
    gl.addParamDim(LuaGL::Integerv, GL_SECONDARY_COLOR_ARRAY_SIZE, 1);
    gl.addParamDim(LuaGL::Integerv, GL_SECONDARY_COLOR_ARRAY_TYPE, 1);
    gl.addParamDim(LuaGL::Integerv, GL_SECONDARY_COLOR_ARRAY_STRIDE, 1);
    // GL_EXT_blend_func_separate
    gl.addParamDim(LuaGL::Integerv, GL_BLEND_SRC_RGB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_BLEND_DST_RGB, 1);
    gl.addParamDim(LuaGL::Integerv, GL_BLEND_SRC_ALPHA, 1);
    gl.addParamDim(LuaGL::Integerv, GL_BLEND_DST_ALPHA, 1);
    // GL_EXT_stencil_wrap
    // x
    // GL_ARB_texture_env_crossbar
    // x
    // GL_EXT_texture_lod_bias
    gl.addParamDim(LuaGL::TexEnvfv, GL_TEXTURE_LOD_BIAS, 1);
    gl.addParamDim(LuaGL::Floatv, GL_MAX_TEXTURE_LOD_BIAS, 1);
    // GL_ARB_texture_mirrored_repeat
    // x
    // GL_ARB_window_pos
    // x
  }
}

void Register_GL_1_4_Functions(lua_State *L, int module) {
  if (GLEW_VERSION_1_4) {
#ifdef _DEBUG
    std::cout << "Supports OpenGL 1.4" << std::endl;
#endif
    LuaGL::Instance().setVersion(1.4);
    REGISTER_GL_FUNC(L, module, BlendColor);
    REGISTER_GL_FUNC(L, module, BlendEquation);
    REGISTER_GL_FUNC(L, module, BlendFuncSeparate);
    REGISTER_GL_FUNC(L, module, FogCoordPointer);
    REGISTER_GL_FUNC(L, module, FogCoordd);
    REGISTER_GL_FUNC(L, module, FogCoordf);
    REGISTER_GL_FUNC(L, module, MultiDrawArrays);
    REGISTER_GL_FUNC(L, module, MultiDrawElements);
    REGISTER_GL_FUNC(L, module, PointParameterf);
    REGISTER_GL_FUNC(L, module, PointParameterfv);
    REGISTER_GL_FUNC(L, module, PointParameteri);
    REGISTER_GL_FUNC(L, module, PointParameteriv);
    REGISTER_GL_FUNC(L, module, SecondaryColor3d);
    REGISTER_GL_FUNC(L, module, SecondaryColor3f);
    REGISTER_GL_FUNC(L, module, SecondaryColor3b);
    REGISTER_GL_FUNC(L, module, SecondaryColor3s);
    REGISTER_GL_FUNC(L, module, SecondaryColor3i);
    REGISTER_GL_FUNC(L, module, SecondaryColor3ub);
    REGISTER_GL_FUNC(L, module, SecondaryColor3us);
    REGISTER_GL_FUNC(L, module, SecondaryColor3ui);
    REGISTER_GL_FUNC(L, module, SecondaryColor3dv);
    REGISTER_GL_FUNC(L, module, SecondaryColor3fv);
    REGISTER_GL_FUNC(L, module, SecondaryColor3bv);
    REGISTER_GL_FUNC(L, module, SecondaryColor3sv);
    REGISTER_GL_FUNC(L, module, SecondaryColor3iv);
    REGISTER_GL_FUNC(L, module, SecondaryColor3ubv);
    REGISTER_GL_FUNC(L, module, SecondaryColor3usv);
    REGISTER_GL_FUNC(L, module, SecondaryColor3uiv);
    REGISTER_GL_FUNC(L, module, SecondaryColorPointer);
    REGISTER_GL_FUNC(L, module, WindowPos2d);
    REGISTER_GL_FUNC(L, module, WindowPos2f);
    REGISTER_GL_FUNC(L, module, WindowPos2i);
    REGISTER_GL_FUNC(L, module, WindowPos2s);
    REGISTER_GL_FUNC(L, module, WindowPos2dv);
    REGISTER_GL_FUNC(L, module, WindowPos2fv);
    REGISTER_GL_FUNC(L, module, WindowPos2iv);
    REGISTER_GL_FUNC(L, module, WindowPos2sv);
    REGISTER_GL_FUNC(L, module, WindowPos3d);
    REGISTER_GL_FUNC(L, module, WindowPos3f);
    REGISTER_GL_FUNC(L, module, WindowPos3i);
    REGISTER_GL_FUNC(L, module, WindowPos3s);
    REGISTER_GL_FUNC(L, module, WindowPos3dv);
    REGISTER_GL_FUNC(L, module, WindowPos3fv);
    REGISTER_GL_FUNC(L, module, WindowPos3iv);
    REGISTER_GL_FUNC(L, module, WindowPos3sv);
  }
  
}


