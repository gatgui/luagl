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
  return WrapFunc4<Clampf, Clampf, Clampf, Clampf >::Call(L, glBlendColor);
}

static int lua_glBlendEquation(lua_State *L) {
  return WrapFunc1<Enum >::Call(L, glBlendEquation);
}

static int lua_glBlendFuncSeparate(lua_State *L) {
  return WrapFunc4<Enum, Enum, Enum, Enum >::Call(L, glBlendFuncSeparate);
}

static int lua_glFogCoordPointer(lua_State *L) {
  return WrapFunc3<Enum, Sizei, ConstPtr >::Call(L, glFogCoordPointer);
}

static int lua_glFogCoordd(lua_State *L) {
  return WrapFunc1<Double >::Call(L, glFogCoordd);
}
static int lua_glFogCoordf(lua_State *L) {
  return WrapFunc1<Float >::Call(L, glFogCoordf);
}

static int lua_glMultiDrawArrays(lua_State *L) {
  return WrapFunc4<Enum, TypedPtr<Int>, TypedPtr<Sizei>, Sizei >::Call(L, glMultiDrawArrays);
}

static int lua_glMultiDrawElements(lua_State *L) {
  return WrapFunc5<Enum, Array<Sizei>, Enum, Array<ConstPtr>, Sizei >::Call(L, glMultiDrawElements);
}

static int lua_glPointParameterf(lua_State *L) {
  return WrapFunc2<Enum, Float >::Call(L, glPointParameterf);
}
static int lua_glPointParameterfv(lua_State *L) {
  return WrapFunc2<Enum, Array<Float> >::Call(L, glPointParameterfv);
}
static int lua_glPointParameteri(lua_State *L) {
  return WrapFunc2<Enum, Int >::Call(L, glPointParameteri);
}
static int lua_glPointParameteriv(lua_State *L) {
  return WrapFunc2<Enum, Array<Int> >::Call(L, glPointParameteriv);
}

static int lua_glSecondaryColor3b(lua_State *L) {
  return WrapFunc3<Byte, Byte, Byte >::Call(L, glSecondaryColor3b);
}
static int lua_glSecondaryColor3bv(lua_State *L) {
  return WrapFunc1<ConstArrayN<Byte, 3> >::Call(L, glSecondaryColor3bv);
}
static int lua_glSecondaryColor3d(lua_State *L) {
  return WrapFunc3<Double, Double, Double >::Call(L, glSecondaryColor3d);
}
static int lua_glSecondaryColor3dv(lua_State *L) {
  return WrapFunc1<ConstArrayN<Double, 3> >::Call(L, glSecondaryColor3dv);
}
static int lua_glSecondaryColor3f(lua_State *L) {
  return WrapFunc3<Float, Float, Float >::Call(L, glSecondaryColor3f);
}
static int lua_glSecondaryColor3fv(lua_State *L) {
  return WrapFunc1<ConstArrayN<Float, 3> >::Call(L, glSecondaryColor3fv);
}
static int lua_glSecondaryColor3i(lua_State *L) {
  return WrapFunc3<Int, Int, Int >::Call(L, glSecondaryColor3i);
}
static int lua_glSecondaryColor3iv(lua_State *L) {
  return WrapFunc1<ConstArrayN<Int, 3> >::Call(L, glSecondaryColor3iv);
}
static int lua_glSecondaryColor3s(lua_State *L) {
  return WrapFunc3<Short, Short, Short >::Call(L, glSecondaryColor3s);
}
static int lua_glSecondaryColor3sv(lua_State *L) {
  return WrapFunc1<ConstArrayN<Short, 3> >::Call(L, glSecondaryColor3sv);
}
static int lua_glSecondaryColor3ub(lua_State *L) {
  return WrapFunc3<Ubyte, Ubyte, Ubyte >::Call(L, glSecondaryColor3ub);
}
static int lua_glSecondaryColor3ubv(lua_State *L) {
  return WrapFunc1<ConstArrayN<Ubyte, 3> >::Call(L, glSecondaryColor3ubv);
}
static int lua_glSecondaryColor3ui(lua_State *L) {
  return WrapFunc3<Uint, Uint, Uint >::Call(L, glSecondaryColor3ui);
}
static int lua_glSecondaryColor3uiv(lua_State *L) {
  return WrapFunc1<ConstArrayN<Uint, 3> >::Call(L, glSecondaryColor3uiv);
}
static int lua_glSecondaryColor3us(lua_State *L) {
  return WrapFunc3<Ushort, Ushort, Ushort >::Call(L, glSecondaryColor3us);
}
static int lua_glSecondaryColor3usv(lua_State *L) {
  return WrapFunc1<ConstArrayN<Ushort, 3> >::Call(L, glSecondaryColor3usv);
}

static int lua_glSecondaryColorPointer(lua_State *L) {
  return WrapFunc4<Int, Enum, Sizei, Ptr >::Call(L, glSecondaryColorPointer);
}

static int lua_glWindowPos2d(lua_State *L) {
  return WrapFunc2<Double, Double >::Call(L, glWindowPos2d);
}
static int lua_glWindowPos2dv(lua_State *L) {
  return WrapFunc1<ConstArrayN<Double, 2> >::Call(L, glWindowPos2dv);
}
static int lua_glWindowPos2f(lua_State *L) {
  return WrapFunc2<Float, Float >::Call(L, glWindowPos2f);
}
static int lua_glWindowPos2fv(lua_State *L) {
  return WrapFunc1<ConstArrayN<Float, 2> >::Call(L, glWindowPos2fv);
}
static int lua_glWindowPos2i(lua_State *L) {
  return WrapFunc2<Int, Int >::Call(L, glWindowPos2i);
}
static int lua_glWindowPos2iv(lua_State *L) {
  return WrapFunc1<ConstArrayN<Int, 2> >::Call(L, glWindowPos2iv);
}
static int lua_glWindowPos2s(lua_State *L) {
  return WrapFunc2<Short, Short >::Call(L, glWindowPos2s);
}
static int lua_glWindowPos2sv(lua_State *L) {
  return WrapFunc1<ConstArrayN<Short, 2> >::Call(L, glWindowPos2sv);
}
static int lua_glWindowPos3d(lua_State *L) {
  return WrapFunc3<Double, Double, Double >::Call(L, glWindowPos3d);
}
static int lua_glWindowPos3dv(lua_State *L) {
  return WrapFunc1<ConstArrayN<Double, 3> >::Call(L, glWindowPos3dv);
}
static int lua_glWindowPos3f(lua_State *L) {
  return WrapFunc3<Float, Float, Float >::Call(L, glWindowPos3f);
}
static int lua_glWindowPos3fv(lua_State *L) {
  return WrapFunc1<ConstArrayN<Float, 3> >::Call(L, glWindowPos3fv);
}
static int lua_glWindowPos3i(lua_State *L) {
  return WrapFunc3<Int, Int, Int >::Call(L, glWindowPos3i);
}
static int lua_glWindowPos3iv(lua_State *L) {
  return WrapFunc1<ConstArrayN<Int, 3> >::Call(L, glWindowPos3iv);
}
static int lua_glWindowPos3s(lua_State *L) {
  return WrapFunc3<Short, Short, Short >::Call(L, glWindowPos3s);
}
static int lua_glWindowPos3sv(lua_State *L) {
  return WrapFunc1<ConstArrayN<Short, 3> >::Call(L, glWindowPos3sv);
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


