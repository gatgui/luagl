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

static int lua_glGetError(lua_State *L) {
  CHECK_ARG_COUNT(L, 0);
  Enum r(glGetError());
  r.toLUA(L);
  return 1;
}

static int lua_glEnable(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Enum, glEnable>::Call(L);
#else
  return WrapFunc1<Enum>::Call(L, glEnable);
#endif
}

static int lua_glDisable(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Enum, glDisable>::Call(L);
#else
  return WrapFunc1<Enum>::Call(L, glDisable);
#endif
}

static int lua_glIsEnabled(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Enum e(L, 1);
  lua_pushboolean(L, (glIsEnabled(e) == GL_TRUE ? 1 : 0));
  return 1;
}

static int lua_glBegin(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Enum, glBegin>::Call(L);
#else
  return WrapFunc1<Enum>::Call(L, glBegin);
#endif
}

static int lua_glEnd(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc0<glEnd>::Call(L);
#else
  return WrapFunc0::Call(L, glEnd);
#endif
}

static int lua_glEdgeFlag(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Boolean, glEdgeFlag>::Call(L);
#else
  return WrapFunc1<Boolean>::Call(L, glEdgeFlag);
#endif
}

static int lua_glVertex2s(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Short, Short, glVertex2s>::Call(L);
#else
  return WrapFunc2<Short, Short>::Call(L, glVertex2s);
#endif
}
static int lua_glVertex2i(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Int, Int, glVertex2i>::Call(L);
#else
  return WrapFunc2<Int, Int>::Call(L, glVertex2i);
#endif
}
static int lua_glVertex2f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Float, Float, glVertex2f>::Call(L);
#else
  return WrapFunc2<Float, Float>::Call(L, glVertex2f);
#endif
}
static int lua_glVertex2d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Double, Double, glVertex2d>::Call(L);
#else
  return WrapFunc2<Double, Double>::Call(L, glVertex2d);
#endif
}
static int lua_glVertex3s(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Short, Short, Short, glVertex3s>::Call(L);
#else
  return WrapFunc3<Short, Short, Short>::Call(L, glVertex3s);
#endif
}
static int lua_glVertex3i(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Int, Int, glVertex3i>::Call(L);
#else
  return WrapFunc3<Int, Int, Int>::Call(L, glVertex3i);
#endif
}
static int lua_glVertex3f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Float, Float, Float, glVertex3f>::Call(L);
#else
  return WrapFunc3<Float, Float, Float>::Call(L, glVertex3f);
#endif
}
static int lua_glVertex3d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Double, Double, Double, glVertex3d>::Call(L);
#else
  return WrapFunc3<Double, Double, Double>::Call(L, glVertex3d);
#endif
}
static int lua_glVertex4s(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Short, Short, Short, Short, glVertex4s>::Call(L);
#else
  return WrapFunc4<Short, Short, Short, Short>::Call(L, glVertex4s);
#endif
}
static int lua_glVertex4i(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Int, Int, Int, glVertex4i>::Call(L);
#else
  return WrapFunc4<Int, Int, Int, Int>::Call(L, glVertex4i);
#endif
}
static int lua_glVertex4f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Float, Float, Float, Float, glVertex4f>::Call(L);
#else
  return WrapFunc4<Float, Float, Float, Float>::Call(L, glVertex4f);
#endif
}
static int lua_glVertex4d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Double, Double, Double, Double, glVertex4d>::Call(L);
#else
  return WrapFunc4<Double, Double, Double, Double>::Call(L, glVertex4d);
#endif
}
static int lua_glVertex2sv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Short>, glVertex2sv>::Call(L);
#else
  return WrapFunc1<ConstArray<Short> >::Call(L, glVertex2sv);
#endif
}
static int lua_glVertex2iv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Int>, glVertex2iv>::Call(L);
#else
  return WrapFunc1<ConstArray<Int> >::Call(L, glVertex2iv);
#endif
}
static int lua_glVertex2fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Float>, glVertex2fv>::Call(L);
#else
  return WrapFunc1<ConstArray<Float> >::Call(L, glVertex2fv);
#endif
}
static int lua_glVertex2dv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Double>, glVertex2dv>::Call(L);
#else
  return WrapFunc1<ConstArray<Double> >::Call(L, glVertex2dv);
#endif
}
static int lua_glVertex3sv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Short>, glVertex3sv>::Call(L);
#else
  return WrapFunc1<ConstArray<Short> >::Call(L, glVertex3sv);
#endif
}
static int lua_glVertex3iv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Int>, glVertex3iv>::Call(L);
#else
  return WrapFunc1<ConstArray<Int> >::Call(L, glVertex3iv);
#endif
}
static int lua_glVertex3fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Float>, glVertex3fv>::Call(L);
#else
  return WrapFunc1<ConstArray<Float> >::Call(L, glVertex3fv);
#endif
}
static int lua_glVertex3dv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Double>, glVertex3dv>::Call(L);
#else
  return WrapFunc1<ConstArray<Double> >::Call(L, glVertex3dv);
#endif
}
static int lua_glVertex4sv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Short>, glVertex4sv>::Call(L);
#else
  return WrapFunc1<ConstArray<Short> >::Call(L, glVertex4sv);
#endif
}
static int lua_glVertex4iv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Int>, glVertex4iv>::Call(L);
#else
  return WrapFunc1<ConstArray<Int> >::Call(L, glVertex4iv);
#endif
}
static int lua_glVertex4fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Float>, glVertex4fv>::Call(L);
#else
  return WrapFunc1<ConstArray<Float> >::Call(L, glVertex4fv);
#endif
}
static int lua_glVertex4dv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Double>, glVertex4dv>::Call(L);
#else
  return WrapFunc1<ConstArray<Double> >::Call(L, glVertex4dv);
#endif
}

static int lua_glTexCoord1s(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Short, glTexCoord1s>::Call(L);
#else
  return WrapFunc1<Short>::Call(L, glTexCoord1s);
#endif
}
static int lua_glTexCoord1i(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Int, glTexCoord1i>::Call(L);
#else
  return WrapFunc1<Int>::Call(L, glTexCoord1i);
#endif
}
static int lua_glTexCoord1f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Float, glTexCoord1f>::Call(L);
#else
  return WrapFunc1<Float>::Call(L, glTexCoord1f);
#endif
}
static int lua_glTexCoord1d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Double, glTexCoord1d>::Call(L);
#else
  return WrapFunc1<Double>::Call(L, glTexCoord1d);
#endif
}
// no v variant for glTexCoord1
static int lua_glTexCoord2s(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Short, Short, glTexCoord2s>::Call(L);
#else
  return WrapFunc2<Short, Short>::Call(L, glTexCoord2s);
#endif
}
static int lua_glTexCoord2i(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Int, Int, glTexCoord2i>::Call(L);
#else
  return WrapFunc2<Int, Int>::Call(L, glTexCoord2i);
#endif
}
static int lua_glTexCoord2f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Float, Float, glTexCoord2f>::Call(L);
#else
  return WrapFunc2<Float, Float>::Call(L, glTexCoord2f);
#endif
}
static int lua_glTexCoord2d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Double, Double, glTexCoord2d>::Call(L);
#else
  return WrapFunc2<Double, Double>::Call(L, glTexCoord2d);
#endif
}
static int lua_glTexCoord2sv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Short>, glTexCoord2sv>::Call(L);
#else
  return WrapFunc1<ConstArray<Short> >::Call(L, glTexCoord2sv);
#endif
}
static int lua_glTexCoord2iv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Int>, glTexCoord2iv>::Call(L);
#else
  return WrapFunc1<ConstArray<Int> >::Call(L, glTexCoord2iv);
#endif
}
static int lua_glTexCoord2fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Float>, glTexCoord2fv>::Call(L);
#else
  return WrapFunc1<ConstArray<Float> >::Call(L, glTexCoord2fv);
#endif
}
static int lua_glTexCoord2dv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Double>, glTexCoord2dv>::Call(L);
#else
  return WrapFunc1<ConstArray<Double> >::Call(L, glTexCoord2dv);
#endif
}
static int lua_glTexCoord3s(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Short, Short, Short, glTexCoord3s>::Call(L);
#else
  return WrapFunc3<Short, Short, Short>::Call(L, glTexCoord3s);
#endif
}
static int lua_glTexCoord3i(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Int, Int, glTexCoord3i>::Call(L);
#else
  return WrapFunc3<Int, Int, Int>::Call(L, glTexCoord3i);
#endif
}
static int lua_glTexCoord3f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Float, Float, Float, glTexCoord3f>::Call(L);
#else
  return WrapFunc3<Float, Float, Float>::Call(L, glTexCoord3f);
#endif
}
static int lua_glTexCoord3d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Double, Double, Double, glTexCoord3d>::Call(L);
#else
  return WrapFunc3<Double, Double, Double>::Call(L, glTexCoord3d);
#endif
}
static int lua_glTexCoord3sv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Short>, glTexCoord3sv>::Call(L);
#else
  return WrapFunc1<ConstArray<Short> >::Call(L, glTexCoord3sv);
#endif
}
static int lua_glTexCoord3iv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Int>, glTexCoord3iv>::Call(L);
#else
  return WrapFunc1<ConstArray<Int> >::Call(L, glTexCoord3iv);
#endif
}
static int lua_glTexCoord3fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Float>, glTexCoord3fv>::Call(L);
#else
  return WrapFunc1<ConstArray<Float> >::Call(L, glTexCoord3fv);
#endif
}
static int lua_glTexCoord3dv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Double>, glTexCoord3dv>::Call(L);
#else
  return WrapFunc1<ConstArray<Double> >::Call(L, glTexCoord3dv);
#endif
}
static int lua_glTexCoord4s(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Short, Short, Short, Short, glTexCoord4s>::Call(L);
#else
  return WrapFunc4<Short, Short, Short, Short>::Call(L, glTexCoord4s);
#endif
}
static int lua_glTexCoord4i(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Int, Int, Int, glTexCoord4i>::Call(L);
#else
  return WrapFunc4<Int, Int, Int, Int>::Call(L, glTexCoord4i);
#endif
}
static int lua_glTexCoord4f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Float, Float, Float, Float, glTexCoord4f>::Call(L);
#else
  return WrapFunc4<Float, Float, Float, Float>::Call(L, glTexCoord4f);
#endif
}
static int lua_glTexCoord4d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Double, Double, Double, Double, glTexCoord4d>::Call(L);
#else
  return WrapFunc4<Double, Double, Double, Double>::Call(L, glTexCoord4d);
#endif
}
static int lua_glTexCoord4sv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Short>, glTexCoord4sv>::Call(L);
#else
  return WrapFunc1<ConstArray<Short> >::Call(L, glTexCoord4sv);
#endif
}
static int lua_glTexCoord4iv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Int>, glTexCoord4iv>::Call(L);
#else
  return WrapFunc1<ConstArray<Int> >::Call(L, glTexCoord4iv);
#endif
}
static int lua_glTexCoord4fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Float>, glTexCoord4fv>::Call(L);
#else
  return WrapFunc1<ConstArray<Float> >::Call(L, glTexCoord4fv);
#endif
}
static int lua_glTexCoord4dv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Double>, glTexCoord4dv>::Call(L);
#else
  return WrapFunc1<ConstArray<Double> >::Call(L, glTexCoord4dv);
#endif
}

static int lua_glNormal3b(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Byte, Byte, Byte, glNormal3b>::Call(L);
#else
  return WrapFunc3<Byte, Byte, Byte>::Call(L, glNormal3b);
#endif
}
static int lua_glNormal3s(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Short, Short, Short, glNormal3s>::Call(L);
#else
  return WrapFunc3<Short, Short, Short>::Call(L, glNormal3s);
#endif
}
static int lua_glNormal3i(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Int, Int, glNormal3i>::Call(L);
#else
  return WrapFunc3<Int, Int, Int>::Call(L, glNormal3i);
#endif
}
static int lua_glNormal3f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Float, Float, Float, glNormal3f>::Call(L);
#else
  return WrapFunc3<Float, Float, Float>::Call(L, glNormal3f);
#endif
}
static int lua_glNormal3d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Double, Double, Double, glNormal3d>::Call(L);
#else
  return WrapFunc3<Double, Double, Double>::Call(L, glNormal3d);
#endif
}
static int lua_glNormal3bv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Byte>, glNormal3bv>::Call(L);
#else
  return WrapFunc1<ConstArray<Byte> >::Call(L, glNormal3bv);
#endif
}
static int lua_glNormal3sv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Short>, glNormal3sv>::Call(L);
#else
  return WrapFunc1<ConstArray<Short> >::Call(L, glNormal3sv);
#endif
}
static int lua_glNormal3iv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Int>, glNormal3iv>::Call(L);
#else
  return WrapFunc1<ConstArray<Int> >::Call(L, glNormal3iv);
#endif
}
static int lua_glNormal3fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Float>, glNormal3fv>::Call(L);
#else
  return WrapFunc1<ConstArray<Float> >::Call(L, glNormal3fv);
#endif
}
static int lua_glNormal3dv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Double>, glNormal3dv>::Call(L);
#else
  return WrapFunc1<ConstArray<Double> >::Call(L, glNormal3dv);
#endif
}

static int lua_glColor3b(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Byte, Byte, Byte, glColor3b>::Call(L);
#else
  return WrapFunc3<Byte, Byte, Byte>::Call(L, glColor3b);
#endif
}
static int lua_glColor3ub(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Ubyte, Ubyte, Ubyte, glColor3ub>::Call(L);
#else
  return WrapFunc3<Ubyte, Ubyte, Ubyte>::Call(L, glColor3ub);
#endif
}
static int lua_glColor3s(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Short, Short, Short, glColor3s>::Call(L);
#else
  return WrapFunc3<Short, Short, Short>::Call(L, glColor3s);
#endif
}
static int lua_glColor3us(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Ushort, Ushort, Ushort, glColor3us>::Call(L);
#else
  return WrapFunc3<Ushort, Ushort, Ushort>::Call(L, glColor3us);
#endif
}
static int lua_glColor3i(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Int, Int, glColor3i>::Call(L);
#else
  return WrapFunc3<Int, Int, Int>::Call(L, glColor3i);
#endif
}
static int lua_glColor3ui(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Uint, Uint, Uint, glColor3ui>::Call(L);
#else
  return WrapFunc3<Uint, Uint, Uint>::Call(L, glColor3ui);
#endif
}
static int lua_glColor3f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Float, Float, Float, glColor3f>::Call(L);
#else
  return WrapFunc3<Float, Float, Float>::Call(L, glColor3f);
#endif
}
static int lua_glColor3d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Double, Double, Double, glColor3d>::Call(L);
#else
  return WrapFunc3<Double, Double, Double>::Call(L, glColor3d);
#endif
}
static int lua_glColor3bv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Byte>, glColor3bv>::Call(L);
#else
  return WrapFunc1<ConstArray<Byte> >::Call(L, glColor3bv);
#endif
}
static int lua_glColor3ubv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Ubyte>, glColor3ubv>::Call(L);
#else
  return WrapFunc1<ConstArray<Ubyte> >::Call(L, glColor3ubv);
#endif
}
static int lua_glColor3sv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Short>, glColor3sv>::Call(L);
#else
  return WrapFunc1<ConstArray<Short> >::Call(L, glColor3sv);
#endif
}
static int lua_glColor3usv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Ushort>, glColor3usv>::Call(L);
#else
  return WrapFunc1<ConstArray<Ushort> >::Call(L, glColor3usv);
#endif
}
static int lua_glColor3iv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Int>, glColor3iv>::Call(L);
#else
  return WrapFunc1<ConstArray<Int> >::Call(L, glColor3iv);
#endif
}
static int lua_glColor3uiv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Uint>, glColor3uiv>::Call(L);
#else
  return WrapFunc1<ConstArray<Uint> >::Call(L, glColor3uiv);
#endif
}
static int lua_glColor3fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Float>, glColor3fv>::Call(L);
#else
  return WrapFunc1<ConstArray<Float> >::Call(L, glColor3fv);
#endif
}
static int lua_glColor3dv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Double>, glColor3dv>::Call(L);
#else
  return WrapFunc1<ConstArray<Double> >::Call(L, glColor3dv);
#endif
}
static int lua_glColor4b(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Byte, Byte, Byte, Byte, glColor4b>::Call(L);
#else
  return WrapFunc4<Byte, Byte, Byte, Byte>::Call(L, glColor4b);
#endif
}
static int lua_glColor4ub(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Ubyte, Ubyte, Ubyte, Ubyte, glColor4ub>::Call(L);
#else
  return WrapFunc4<Ubyte, Ubyte, Ubyte, Ubyte>::Call(L, glColor4ub);
#endif
}
static int lua_glColor4s(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Short, Short, Short, Short, glColor4s>::Call(L);
#else
  return WrapFunc4<Short, Short, Short, Short>::Call(L, glColor4s);
#endif
}
static int lua_glColor4us(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Ushort, Ushort, Ushort, Ushort, glColor4us>::Call(L);
#else
  return WrapFunc4<Ushort, Ushort, Ushort, Ushort>::Call(L, glColor4us);
#endif
}
static int lua_glColor4i(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Int, Int, Int, glColor4i>::Call(L);
#else
  return WrapFunc4<Int, Int, Int, Int>::Call(L, glColor4i);
#endif
}
static int lua_glColor4ui(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Uint, Uint, Uint, Uint, glColor4ui>::Call(L);
#else
  return WrapFunc4<Uint, Uint, Uint, Uint>::Call(L, glColor4ui);
#endif
}
static int lua_glColor4f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Float, Float, Float, Float, glColor4f>::Call(L);
#else
  return WrapFunc4<Float, Float, Float, Float>::Call(L, glColor4f);
#endif
}
static int lua_glColor4d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Double, Double, Double, Double, glColor4d>::Call(L);
#else
  return WrapFunc4<Double, Double, Double, Double>::Call(L, glColor4d);
#endif
}
static int lua_glColor4bv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Byte>, glColor4bv>::Call(L);
#else
  return WrapFunc1<ConstArray<Byte> >::Call(L, glColor4bv);
#endif
}
static int lua_glColor4ubv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Ubyte>, glColor4ubv>::Call(L);
#else
  return WrapFunc1<ConstArray<Ubyte> >::Call(L, glColor4ubv);
#endif
}
static int lua_glColor4sv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Short>, glColor4sv>::Call(L);
#else
  return WrapFunc1<ConstArray<Short> >::Call(L, glColor4sv);
#endif
}
static int lua_glColor4usv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Ushort>, glColor4usv>::Call(L);
#else
  return WrapFunc1<ConstArray<Ushort> >::Call(L, glColor4usv);
#endif
}
static int lua_glColor4iv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Int>, glColor4iv>::Call(L);
#else
  return WrapFunc1<ConstArray<Int> >::Call(L, glColor4iv);
#endif
}
static int lua_glColor4uiv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Uint>, glColor4uiv>::Call(L);
#else
  return WrapFunc1<ConstArray<Uint> >::Call(L, glColor4uiv);
#endif
}
static int lua_glColor4fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Float>, glColor4fv>::Call(L);
#else
  return WrapFunc1<ConstArray<Float> >::Call(L, glColor4fv);
#endif
}
static int lua_glColor4dv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Double>, glColor4dv>::Call(L);
#else
  return WrapFunc1<ConstArray<Double> >::Call(L, glColor4dv);
#endif
}

// no v variant, always 1 arg
static int lua_glIndexs(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Short, glIndexs>::Call(L);
#else
  return WrapFunc1<Short>::Call(L, glIndexs);
#endif
}
static int lua_glIndexi(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Int, glIndexi>::Call(L);
#else
  return WrapFunc1<Int>::Call(L, glIndexi);
#endif
}
static int lua_glIndexf(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Float, glIndexf>::Call(L);
#else
  return WrapFunc1<Float>::Call(L, glIndexf);
#endif
}
static int lua_glIndexd(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Double, glIndexd>::Call(L);
#else
  return WrapFunc1<Double>::Call(L, glIndexd);
#endif
}
static int lua_glIndexub(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Ubyte, glIndexub>::Call(L);
#else
  return WrapFunc1<Ubyte>::Call(L, glIndexub);
#endif
}

static int lua_glVertexPointer(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Enum, Sizei, ConstPtr, glVertexPointer>::Call(L);
#else
  return WrapFunc4<Int, Enum, Sizei, ConstPtr>::Call(L, glVertexPointer);
#endif
}

static int lua_glTexCoordPointer(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Enum, Sizei, ConstPtr, glTexCoordPointer>::Call(L);
#else
  return WrapFunc4<Int, Enum, Sizei, ConstPtr>::Call(L, glTexCoordPointer);
#endif
}

static int lua_glNormalPointer(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Sizei, ConstPtr, glNormalPointer>::Call(L);
#else
  return WrapFunc3<Enum, Sizei, ConstPtr>::Call(L, glNormalPointer);
#endif
}

static int lua_glColorPointer(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Enum, Sizei, ConstPtr, glColorPointer>::Call(L);
#else
  return WrapFunc4<Int, Enum, Sizei, ConstPtr>::Call(L, glColorPointer);
#endif
}

static int lua_glIndexPointer(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Sizei, ConstPtr, glIndexPointer>::Call(L);
#else
  return WrapFunc3<Enum, Sizei, ConstPtr>::Call(L, glIndexPointer);
#endif
}

static int lua_glEdgeFlagPointer(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Sizei, ConstPtr, glEdgeFlagPointer>::Call(L);
#else
  return WrapFunc2<Sizei, ConstPtr>::Call(L, glEdgeFlagPointer);
#endif
}

static int lua_glEnableClientState(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Enum, glEnableClientState>::Call(L);
#else
  return WrapFunc1<Enum>::Call(L, glEnableClientState);
#endif
}

static int lua_glDisableClientState(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Enum, glDisableClientState>::Call(L);
#else
  return WrapFunc1<Enum>::Call(L, glDisableClientState);
#endif
}

static int lua_glArrayElement(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Int, glArrayElement>::Call(L);
#else
  return WrapFunc1<Int>::Call(L, glArrayElement);
#endif
}

static int lua_glDrawArrays(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Int, Sizei, glDrawArrays>::Call(L);
#else
  return WrapFunc3<Enum, Int, Sizei>::Call(L, glDrawArrays);
#endif
}

static int lua_glDrawElements(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Enum, Sizei, Enum, ConstPtr, glDrawElements>::Call(L);
#else
  return WrapFunc4<Enum, Sizei, Enum, ConstPtr>::Call(L, glDrawElements);
#endif
}

static int lua_glInterleavedArrays(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Sizei, ConstPtr, glInterleavedArrays>::Call(L);
#else
  return WrapFunc3<Enum, Sizei, ConstPtr>::Call(L, glInterleavedArrays);
#endif
}

static int lua_glRects(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Short, Short, Short, Short, glRects>::Call(L);
#else
  return WrapFunc4<Short, Short, Short, Short>::Call(L, glRects);
#endif
}
static int lua_glRecti(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Int, Int, Int, glRecti>::Call(L);
#else
  return WrapFunc4<Int, Int, Int, Int>::Call(L, glRecti);
#endif
}
static int lua_glRectf(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Float, Float, Float, Float, glRectf>::Call(L);
#else
  return WrapFunc4<Float, Float, Float, Float>::Call(L, glRectf);
#endif
}
static int lua_glRectd(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Double, Double, Double, Double, glRectd>::Call(L);
#else
  return WrapFunc4<Double, Double, Double, Double>::Call(L, glRectd);
#endif
}
static int lua_glRectsv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<ConstArray<Short>, ConstArray<Short>, glRectsv>::Call(L);
#else
  return WrapFunc2<ConstArray<Short>, ConstArray<Short> >::Call(L, glRectsv);
#endif
}
static int lua_glRectiv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<ConstArray<Int>, ConstArray<Int>, glRectiv>::Call(L);
#else
  return WrapFunc2<ConstArray<Int>, ConstArray<Int> >::Call(L, glRectiv);
#endif
}
static int lua_glRectfv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<ConstArray<Float>, ConstArray<Float>, glRectfv>::Call(L);
#else
  return WrapFunc2<ConstArray<Float>, ConstArray<Float> >::Call(L, glRectfv);
#endif
}
static int lua_glRectdv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<ConstArray<Double>, ConstArray<Double>, glRectdv>::Call(L);
#else
  return WrapFunc2<ConstArray<Double>, ConstArray<Double> >::Call(L, glRectdv);
#endif
}

static int lua_glDepthRange(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Clampd, Clampd, glDepthRange>::Call(L);
#else
  return WrapFunc2<Clampd, Clampd>::Call(L, glDepthRange);
#endif
}

static int lua_glViewport(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Int, Sizei, Sizei, glViewport>::Call(L);
#else
  return WrapFunc4<Int, Int, Sizei, Sizei>::Call(L, glViewport);
#endif
}

static int lua_glMatrixMode(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Enum, glMatrixMode>::Call(L);
#else
  return WrapFunc1<Enum>::Call(L, glMatrixMode);
#endif
}

static int lua_glLoadMatrixf(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Array1D<Float> m(L, 1);
  if (m.size() != 16) {
    lua_pushstring(L, "gl.LoadMatrixf: Invalid matrix data");
    lua_error(L);
  }
  glLoadMatrixf(m);
  return 0;
}
static int lua_glLoadMatrixd(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Array1D<Double> m(L, 1);
  if (m.size() != 16) {
    lua_pushstring(L, "gl.LoadMatrixd: Invalid matrix data");
    lua_error(L);
  }
  glLoadMatrixd(m);
  return 0;
}

static int lua_glMultMatrixf(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Array1D<Float> m(L, 1);
  if (m.size() != 16) {
    lua_pushstring(L, "gl.MultMatrixf: Invalid matrix data");
    lua_error(L);
  }
  glMultMatrixf(m);
  return 0;
}
static int lua_glMultMatrixd(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Array1D<Double> m(L, 1);
  if (m.size() != 16) {
    lua_pushstring(L, "gl.MultMatrixd: Invalid matrix data");
    lua_error(L);
  }
  glMultMatrixd(m);
  return 0;
}

static int lua_glLoadIdentity(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc0<glLoadIdentity>::Call(L);
#else
  return WrapFunc0::Call(L, glLoadIdentity);
#endif
}

static int lua_glRotatef(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Float, Float, Float, Float, glRotatef>::Call(L);
#else
  return WrapFunc4<Float, Float, Float, Float>::Call(L, glRotatef);
#endif
}
static int lua_glRotated(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Double, Double, Double, Double, glRotated>::Call(L);
#else
  return WrapFunc4<Double, Double, Double, Double>::Call(L, glRotated);
#endif
}

static int lua_glTranslatef(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Float, Float, Float, glTranslatef>::Call(L);
#else
  return WrapFunc3<Float, Float, Float>::Call(L, glTranslatef);
#endif
}
static int lua_glTranslated(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Double, Double, Double, glTranslated>::Call(L);
#else
  return WrapFunc3<Double, Double, Double>::Call(L, glTranslated);
#endif
}

static int lua_glScalef(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Float, Float, Float, glScalef>::Call(L);
#else
  return WrapFunc3<Float, Float, Float>::Call(L, glScalef);
#endif
}
static int lua_glScaled(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Double, Double, Double, glScaled>::Call(L);
#else
  return WrapFunc3<Double, Double, Double>::Call(L, glScaled);
#endif
}

static int lua_glFrustum(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc6<Double, Double, Double, Double, Double, Double, glFrustum>::Call(L);
#else
  return WrapFunc6<Double, Double, Double, Double, Double, Double>::Call(L, glFrustum);
#endif
}

static int lua_glOrtho(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc6<Double, Double, Double, Double, Double, Double, glOrtho>::Call(L);
#else
  return WrapFunc6<Double, Double, Double, Double, Double, Double>::Call(L, glOrtho);
#endif
}

static int lua_glPushMatrix(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc0<glPushMatrix>::Call(L);
#else
  return WrapFunc0::Call(L, glPushMatrix);
#endif
}

static int lua_glPopMatrix(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc0<glPopMatrix>::Call(L);
#else
  return WrapFunc0::Call(L, glPopMatrix);
#endif
}

static int lua_glTexGeni(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, Int, glTexGeni>::Call(L);
#else
  return WrapFunc3<Enum, Enum, Int>::Call(L, glTexGeni);
#endif
}
static int lua_glTexGenf(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, Float, glTexGenf>::Call(L);
#else
  return WrapFunc3<Enum, Enum, Float>::Call(L, glTexGenf);
#endif
}
static int lua_glTexGend(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, Double, glTexGend>::Call(L);
#else
  return WrapFunc3<Enum, Enum, Double>::Call(L, glTexGend);
#endif
}
static int lua_glTexGeniv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, ConstArray<Int>, glTexGeniv>::Call(L);
#else
  return WrapFunc3<Enum, Enum, ConstArray<Int> >::Call(L, glTexGeniv);
#endif
}
static int lua_glTexGenfv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, ConstArray<Float>, glTexGenfv>::Call(L);
#else
  return WrapFunc3<Enum, Enum, ConstArray<Float> >::Call(L, glTexGenfv);
#endif
}
static int lua_glTexGendv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, ConstArray<Double>, glTexGendv>::Call(L);
#else
  return WrapFunc3<Enum, Enum, ConstArray<Double> >::Call(L, glTexGendv);
#endif
}

static int lua_glClipPlane(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, ConstArray<Double>, glClipPlane>::Call(L);
#else
  return WrapFunc2<Enum, ConstArray<Double> >::Call(L, glClipPlane);
#endif
}

static int lua_glRasterPos2s(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Short, Short, glRasterPos2s>::Call(L);
#else
  return WrapFunc2<Short, Short>::Call(L, glRasterPos2s);
#endif
}
static int lua_glRasterPos2i(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Int, Int, glRasterPos2i>::Call(L);
#else
  return WrapFunc2<Int, Int>::Call(L, glRasterPos2i);
#endif
}
static int lua_glRasterPos2f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Float, Float, glRasterPos2f>::Call(L);
#else
  return WrapFunc2<Float, Float>::Call(L, glRasterPos2f);
#endif
}
static int lua_glRasterPos2d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Double, Double, glRasterPos2d>::Call(L);
#else
  return WrapFunc2<Double, Double>::Call(L, glRasterPos2d);
#endif
}
static int lua_glRasterPos2sv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Short>, glRasterPos2sv>::Call(L);
#else
  return WrapFunc1<ConstArray<Short> >::Call(L, glRasterPos2sv);
#endif
}
static int lua_glRasterPos2iv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Int>, glRasterPos2iv>::Call(L);
#else
  return WrapFunc1<ConstArray<Int> >::Call(L, glRasterPos2iv);
#endif
}
static int lua_glRasterPos2fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Float>, glRasterPos2fv>::Call(L);
#else
  return WrapFunc1<ConstArray<Float> >::Call(L, glRasterPos2fv);
#endif
}
static int lua_glRasterPos2dv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Double>, glRasterPos2dv>::Call(L);
#else
  return WrapFunc1<ConstArray<Double> >::Call(L, glRasterPos2dv);
#endif
}
static int lua_glRasterPos3s(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Short, Short, Short, glRasterPos3s>::Call(L);
#else
  return WrapFunc3<Short, Short, Short>::Call(L, glRasterPos3s);
#endif
}
static int lua_glRasterPos3i(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Int, Int, glRasterPos3i>::Call(L);
#else
  return WrapFunc3<Int, Int, Int>::Call(L, glRasterPos3i);
#endif
}
static int lua_glRasterPos3f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Float, Float, Float, glRasterPos3f>::Call(L);
#else
  return WrapFunc3<Float, Float, Float>::Call(L, glRasterPos3f);
#endif
}
static int lua_glRasterPos3d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Double, Double, Double, glRasterPos3d>::Call(L);
#else
  return WrapFunc3<Double, Double, Double>::Call(L, glRasterPos3d);
#endif
}
static int lua_glRasterPos3sv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Short>, glRasterPos3sv>::Call(L);
#else
  return WrapFunc1<ConstArray<Short> >::Call(L, glRasterPos3sv);
#endif
}
static int lua_glRasterPos3iv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Int>, glRasterPos3iv>::Call(L);
#else
  return WrapFunc1<ConstArray<Int> >::Call(L, glRasterPos3iv);
#endif
}
static int lua_glRasterPos3fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Float>, glRasterPos3fv>::Call(L);
#else
  return WrapFunc1<ConstArray<Float> >::Call(L, glRasterPos3fv);
#endif
}
static int lua_glRasterPos3dv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Double>, glRasterPos3dv>::Call(L);
#else
  return WrapFunc1<ConstArray<Double> >::Call(L, glRasterPos3dv);
#endif
}
static int lua_glRasterPos4s(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Short, Short, Short, Short, glRasterPos4s>::Call(L);
#else
  return WrapFunc4<Short, Short, Short, Short>::Call(L, glRasterPos4s);
#endif
}
static int lua_glRasterPos4i(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Int, Int, Int, glRasterPos4i>::Call(L);
#else
  return WrapFunc4<Int, Int, Int, Int>::Call(L, glRasterPos4i);
#endif
}
static int lua_glRasterPos4f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Float, Float, Float, Float, glRasterPos4f>::Call(L);
#else
  return WrapFunc4<Float, Float, Float, Float>::Call(L, glRasterPos4f);
#endif
}
static int lua_glRasterPos4d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Double, Double, Double, Double, glRasterPos4d>::Call(L);
#else
  return WrapFunc4<Double, Double, Double, Double>::Call(L, glRasterPos4d);
#endif
}
static int lua_glRasterPos4sv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Short>, glRasterPos4sv>::Call(L);
#else
  return WrapFunc1<ConstArray<Short> >::Call(L, glRasterPos4sv);
#endif
}
static int lua_glRasterPos4iv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Int>, glRasterPos4iv>::Call(L);
#else
  return WrapFunc1<ConstArray<Int> >::Call(L, glRasterPos4iv);
#endif
}
static int lua_glRasterPos4fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Float>, glRasterPos4fv>::Call(L);
#else
  return WrapFunc1<ConstArray<Float> >::Call(L, glRasterPos4fv);
#endif
}
static int lua_glRasterPos4dv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Double>, glRasterPos4dv>::Call(L);
#else
  return WrapFunc1<ConstArray<Double> >::Call(L, glRasterPos4dv);
#endif
}

static int lua_glFrontFace(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Enum, glFrontFace>::Call(L);
#else
  return WrapFunc1<Enum>::Call(L, glFrontFace);
#endif
}

static int lua_glMateriali(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, Int, glMateriali>::Call(L);
#else
  return WrapFunc3<Enum, Enum, Int>::Call(L, glMateriali);
#endif
}
static int lua_glMaterialf(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, Float, glMaterialf>::Call(L);
#else
  return WrapFunc3<Enum, Enum, Float>::Call(L, glMaterialf);
#endif
}
static int lua_glMaterialiv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, ConstArray<Int>, glMaterialiv>::Call(L);
#else
  return WrapFunc3<Enum, Enum, ConstArray<Int> >::Call(L, glMaterialiv);
#endif
}
static int lua_glMaterialfv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, ConstArray<Float>, glMaterialfv>::Call(L);
#else
  return WrapFunc3<Enum, Enum, ConstArray<Float> >::Call(L, glMaterialfv);
#endif
}

static int lua_glLighti(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, Int, glLighti>::Call(L);
#else
  return WrapFunc3<Enum, Enum, Int>::Call(L, glLighti);
#endif
}
static int lua_glLightf(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, Float, glLightf>::Call(L);
#else
  return WrapFunc3<Enum, Enum, Float>::Call(L, glLightf);
#endif
}
static int lua_glLightiv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, ConstArray<Int>, glLightiv>::Call(L);
#else
  return WrapFunc3<Enum, Enum, ConstArray<Int> >::Call(L, glLightiv);
#endif
}
static int lua_glLightfv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, ConstArray<Float>, glLightfv>::Call(L);
#else
  return WrapFunc3<Enum, Enum, ConstArray<Float> >::Call(L, glLightfv);
#endif
}

static int lua_glLightModeli(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Int, glLightModeli>::Call(L);
#else
  return WrapFunc2<Enum, Int>::Call(L, glLightModeli);
#endif
}
static int lua_glLightModelf(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Float, glLightModelf>::Call(L);
#else
  return WrapFunc2<Enum, Float>::Call(L, glLightModelf);
#endif
}
static int lua_glLightModeliv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, ConstArray<Int>, glLightModeliv>::Call(L);
#else
  return WrapFunc2<Enum, ConstArray<Int> >::Call(L, glLightModeliv);
#endif
}
static int lua_glLightModelfv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, ConstArray<Float>, glLightModelfv>::Call(L);
#else
  return WrapFunc2<Enum, ConstArray<Float> >::Call(L, glLightModelfv);
#endif
}

static int lua_glColorMaterial(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Enum, glColorMaterial>::Call(L);
#else
  return WrapFunc2<Enum, Enum>::Call(L, glColorMaterial);
#endif
}

static int lua_glShadeModel(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Enum, glShadeModel>::Call(L);
#else
  return WrapFunc1<Enum>::Call(L, glShadeModel);
#endif
}

static int lua_glPointSize(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Float, glPointSize>::Call(L);
#else
  return WrapFunc1<Float>::Call(L, glPointSize);
#endif
}

static int lua_glLineWidth(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Float, glLineWidth>::Call(L);
#else
  return WrapFunc1<Float>::Call(L, glLineWidth);
#endif
}

static int lua_glLineStipple(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Int, Ushort, glLineStipple>::Call(L);
#else
  return WrapFunc2<Int, Ushort>::Call(L, glLineStipple);
#endif
}

static int lua_glCullFace(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Enum, glCullFace>::Call(L);
#else
  return WrapFunc1<Enum>::Call(L, glCullFace);
#endif
}

static int lua_glPolygonStipple(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstTypedPtr<Ubyte>, glPolygonStipple>::Call(L);
#else
  return WrapFunc1<ConstTypedPtr<Ubyte> >::Call(L, glPolygonStipple);
#endif
}

static int lua_glPolygonMode(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Enum, glPolygonMode>::Call(L);
#else
  return WrapFunc2<Enum, Enum>::Call(L, glPolygonMode);
#endif
}

static int lua_glPolygonOffset(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Float, Float, glPolygonOffset>::Call(L);
#else
  return WrapFunc2<Float, Float>::Call(L, glPolygonOffset);
#endif
}

static int lua_glPixelStorei(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Int, glPixelStorei>::Call(L);
#else
  return WrapFunc2<Enum, Int>::Call(L, glPixelStorei);
#endif
}
static int lua_glPixelStoref(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Float, glPixelStoref>::Call(L);
#else
  return WrapFunc2<Enum, Float>::Call(L, glPixelStoref);
#endif
}

static int lua_glPixelTransferi(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Int, glPixelTransferi>::Call(L);
#else
  return WrapFunc2<Enum, Int>::Call(L, glPixelTransferi);
#endif
}
static int lua_glPixelTransferf(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Float, glPixelTransferf>::Call(L);
#else
  return WrapFunc2<Enum, Float>::Call(L, glPixelTransferf);
#endif
}

static int lua_glPixelMapusv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Sizei, ConstTypedPtr<Ushort>, glPixelMapusv>::Call(L);
#else
  return WrapFunc3<Enum, Sizei, ConstTypedPtr<Ushort> >::Call(L, glPixelMapusv);
#endif
}
static int lua_glPixelMapuiv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Sizei, ConstTypedPtr<Uint>, glPixelMapuiv>::Call(L);
#else
  return WrapFunc3<Enum, Sizei, ConstTypedPtr<Uint> >::Call(L, glPixelMapuiv);
#endif
}
static int lua_glPixelMapfv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Sizei, ConstTypedPtr<Float>, glPixelMapfv>::Call(L);
#else
  return WrapFunc3<Enum, Sizei, ConstTypedPtr<Float> >::Call(L, glPixelMapfv);
#endif
}

static int lua_glDrawPixels(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Sizei, Sizei, Enum, Enum, ConstPtr, glDrawPixels>::Call(L);
#else
  return WrapFunc5<Sizei, Sizei, Enum, Enum, ConstPtr>::Call(L, glDrawPixels);
#endif
}

static int lua_glPixelZoom(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Float, Float, glPixelZoom>::Call(L);
#else
  return WrapFunc2<Float, Float>::Call(L, glPixelZoom);
#endif
}

static int lua_glBitmap(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc7<Sizei, Sizei, Float, Float, Float, Float,
                   ConstTypedPtr<Ubyte>, glBitmap>::Call(L);
#else
  return WrapFunc7<Sizei, Sizei, Float, Float, Float, Float,
                   ConstTypedPtr<Ubyte> >::Call(L, glBitmap);
#endif
}

static int lua_glTexImage1D(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc8<Enum, Int, Int, Sizei, Int,
                   Enum, Enum, ConstPtr, glTexImage1D>::Call(L);
#else
  return WrapFunc8<Enum, Int, Int, Sizei, Int,
                   Enum, Enum, ConstPtr>::Call(L, glTexImage1D);
#endif
}

static int lua_glTexImage2D(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc9<Enum, Int, Int, Sizei, Sizei, Int,
                   Enum, Enum, ConstPtr, glTexImage2D>::Call(L);
#else
  return WrapFunc9<Enum, Int, Int, Sizei, Sizei, Int,
                   Enum, Enum, ConstPtr>::Call(L, glTexImage2D);
#endif
}

static int lua_glCopyTexImage1D(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc7<Enum, Int, Enum, Int, Int, Sizei,
                   Int, glCopyTexImage1D>::Call(L);
#else
  return WrapFunc7<Enum, Int, Enum, Int, Int, Sizei,
                   Int>::Call(L, glCopyTexImage1D);
#endif
}

static int lua_glCopyTexImage2D(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc8<Enum, Int, Enum, Int, Int, Sizei,
                   Sizei, Int, glCopyTexImage2D>::Call(L);
#else
  return WrapFunc8<Enum, Int, Enum, Int, Int, Sizei,
                   Sizei, Int>::Call(L, glCopyTexImage2D);
#endif
}

static int lua_glTexSubImage1D(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc7<Enum, Int, Int, Sizei, Enum, Enum, ConstPtr,
                   glTexSubImage1D>::Call(L);
#else
  return WrapFunc7<Enum, Int, Int, Sizei, Enum, Enum, ConstPtr>::Call(L, glTexSubImage1D);
#endif
}

static int lua_glTexSubImage2D(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc9<Enum, Int, Int, Int, Sizei, Sizei, Enum,
                   Enum, ConstPtr, glTexSubImage2D>::Call(L);
#else
  return WrapFunc9<Enum, Int, Int, Int, Sizei, Sizei, Enum,
                   Enum, ConstPtr>::Call(L, glTexSubImage2D);
#endif
}

static int lua_glCopyTexSubImage1D(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc6<Enum, Int, Int, Int, Int, Sizei,
                   glCopyTexSubImage1D>::Call(L);
#else
  return WrapFunc6<Enum, Int, Int, Int, Int, Sizei>::Call(L, glCopyTexSubImage1D);
#endif    
}

static int lua_glCopyTexSubImage2D(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc8<Enum, Int, Int, Int, Int, Int, Sizei, Sizei,
                   glCopyTexSubImage2D>::Call(L);
#else
  return WrapFunc8<Enum, Int, Int, Int, Int, Int, Sizei, Sizei>::Call(L, glCopyTexSubImage2D);
#endif
}

static int lua_glTexParameteri(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, Int, glTexParameteri>::Call(L);
#else
  return WrapFunc3<Enum, Enum, Int>::Call(L, glTexParameteri);
#endif
}
static int lua_glTexParameterf(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, Float, glTexParameterf>::Call(L);
#else
  return WrapFunc3<Enum, Enum, Float>::Call(L, glTexParameterf);
#endif
}
static int lua_glTexParameteriv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, ConstArray<Int>, glTexParameteriv>::Call(L);
#else
  return WrapFunc3<Enum, Enum, ConstArray<Int> >::Call(L, glTexParameteriv);
#endif
}
static int lua_glTexParameterfv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, ConstArray<Float>, glTexParameterfv>::Call(L);
#else
  return WrapFunc3<Enum, Enum, ConstArray<Float> >::Call(L, glTexParameterfv);
#endif
}

static int lua_glBindTexture(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Uint, glBindTexture>::Call(L);
#else
  return WrapFunc2<Enum, Uint>::Call(L, glBindTexture);
#endif
}

static int lua_glGenTextures(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Sizei n(L, 1);
  Array1D<Uint> textures(n);
  glGenTextures(n, textures);
  textures.toLUA(L);
  return 1;
}

static int lua_glDeleteTextures(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Array1D<Uint> textures(L, 1);
  glDeleteTextures(textures.size(), textures);
  return 0;
}

static int lua_glAreTexturesResident(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Array1D<Uint> textures(L, 1);
  Array1D<Boolean> residences(textures.size());
  glAreTexturesResident(textures.size(), textures, residences);
  residences.toLUA(L);
  return 1;
}

static int lua_glPrioritizeTextures(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Array1D<Uint> textures(L, 1);
  Array1D<Clampf> priorities(L, 2);
  if (priorities.size() != textures.size()) {
    luaL_error(L, "gl.PrioritizeTextures: arrays length mismatch");
  }
  glPrioritizeTextures(textures.size(), textures, priorities);
  return 0;
}

static int lua_glTexEnvi(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, Int, glTexEnvi>::Call(L);
#else
  return WrapFunc3<Enum, Enum, Int>::Call(L, glTexEnvi);
#endif
}
static int lua_glTexEnvf(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, Float, glTexEnvf>::Call(L);
#else
  return WrapFunc3<Enum, Enum, Float>::Call(L, glTexEnvf);
#endif
}
static int lua_glTexEnviv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, ConstArray<Int>, glTexEnviv>::Call(L);
#else
  return WrapFunc3<Enum, Enum, ConstArray<Int> >::Call(L, glTexEnviv);
#endif
}
static int lua_glTexEnvfv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, ConstArray<Float>, glTexEnvfv>::Call(L);
#else
  return WrapFunc3<Enum, Enum, ConstArray<Float> >::Call(L, glTexEnvfv);
#endif
}

static int lua_glFogi(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Int, glFogi>::Call(L);
#else
  return WrapFunc2<Enum, Int>::Call(L, glFogi);
#endif
}
static int lua_glFogf(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Float, glFogf>::Call(L);
#else
  return WrapFunc2<Enum, Float>::Call(L, glFogf);
#endif
}
static int lua_glFogiv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, ConstArray<Int>, glFogiv>::Call(L);
#else
  return WrapFunc2<Enum, ConstArray<Int> >::Call(L, glFogiv);
#endif
}
static int lua_glFogfv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, ConstArray<Float>, glFogfv>::Call(L);
#else
  return WrapFunc2<Enum, ConstArray<Float> >::Call(L, glFogfv);
#endif
}

static int lua_glScissor(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Int, Int, Sizei, Sizei, glScissor>::Call(L);
#else
  return WrapFunc4<Int, Int, Sizei, Sizei>::Call(L, glScissor);
#endif
}

static int lua_glAlphaFunc(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Clampf, glAlphaFunc>::Call(L);
#else
  return WrapFunc2<Enum, Clampf>::Call(L, glAlphaFunc);
#endif
}

static int lua_glStencilFunc(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Int, Uint, glStencilFunc>::Call(L);
#else
  return WrapFunc3<Enum, Int, Uint>::Call(L, glStencilFunc);
#endif
}

static int lua_glStencilOp(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Enum, Enum, glStencilOp>::Call(L);
#else
  return WrapFunc3<Enum, Enum, Enum>::Call(L, glStencilOp);
#endif
}

static int lua_glDepthFunc(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Enum, glDepthFunc>::Call(L);
#else
  return WrapFunc1<Enum>::Call(L, glDepthFunc);
#endif
}

static int lua_glBlendFunc(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Enum, glBlendFunc>::Call(L);
#else
  return WrapFunc2<Enum, Enum>::Call(L, glBlendFunc);
#endif
}

static int lua_glLogicOp(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Enum, glLogicOp>::Call(L);
#else
  return WrapFunc1<Enum>::Call(L, glLogicOp);
#endif
}

static int lua_glDrawBuffer(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Enum, glDrawBuffer>::Call(L);
#else
  return WrapFunc1<Enum>::Call(L, glDrawBuffer);
#endif
}

static int lua_glIndexMask(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Uint, glIndexMask>::Call(L);
#else
  return WrapFunc1<Uint>::Call(L, glIndexMask);
#endif
}

static int lua_glColorMask(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Boolean, Boolean, Boolean, Boolean, glColorMask>::Call(L);
#else
  return WrapFunc4<Boolean, Boolean, Boolean, Boolean>::Call(L, glColorMask);
#endif
}

static int lua_glDepthMask(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Boolean, glDepthMask>::Call(L);
#else
  return WrapFunc1<Boolean>::Call(L, glDepthMask);
#endif
}

static int lua_glStencilMask(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Uint, glStencilMask>::Call(L);
#else
  return WrapFunc1<Uint>::Call(L, glStencilMask);
#endif
}

static int lua_glClear(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Bitfield, glClear>::Call(L);
#else
  return WrapFunc1<Bitfield>::Call(L, glClear);
#endif
}

static int lua_glClearColor(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Clampf, Clampf, Clampf, Clampf, glClearColor>::Call(L);
#else
  return WrapFunc4<Clampf, Clampf, Clampf, Clampf>::Call(L, glClearColor);
#endif
}

static int lua_glClearIndex(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Float, glClearIndex>::Call(L);
#else
  return WrapFunc1<Float>::Call(L, glClearIndex);
#endif
}

static int lua_glClearDepth(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Clampd, glClearDepth>::Call(L);
#else
  return WrapFunc1<Clampd>::Call(L, glClearDepth);
#endif
}

static int lua_glClearStencil(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Int, glClearStencil>::Call(L);
#else
  return WrapFunc1<Int>::Call(L, glClearStencil);
#endif
}

static int lua_glClearAccum(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc4<Float, Float, Float, Float, glClearAccum>::Call(L);
#else
  return WrapFunc4<Float, Float, Float, Float>::Call(L, glClearAccum);
#endif
}

static int lua_glAccum(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Float, glAccum>::Call(L);
#else
  return WrapFunc2<Enum, Float>::Call(L, glAccum);
#endif
}

static int lua_glReadPixels(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc7<Int, Int, Sizei, Sizei, Enum, Enum, Ptr, glReadPixels>::Call(L);
#else
  return WrapFunc7<Int, Int, Sizei, Sizei, Enum, Enum, Ptr>::Call(L, glReadPixels);
#endif
}

static int lua_glReadBuffer(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Enum, glReadBuffer>::Call(L);
#else
  return WrapFunc1<Enum>::Call(L, glReadBuffer);
#endif
}

static int lua_glCopyPixels(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Int, Int, Sizei, Sizei, Enum, glCopyPixels>::Call(L);
#else
  return WrapFunc5<Int, Int, Sizei, Sizei, Enum>::Call(L, glCopyPixels);
#endif
}

static int lua_glMap1f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc6<Enum, Float, Float, Int, Int, ConstTypedPtr<Float>, glMap1f>::Call(L);
#else
  return WrapFunc6<Enum, Float, Float, Int, Int, ConstTypedPtr<Float> >::Call(L, glMap1f);
#endif
}
static int lua_glMap1d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc6<Enum, Double, Double, Int, Int, ConstTypedPtr<Double>, glMap1d>::Call(L); 
#else
  return WrapFunc6<Enum, Double, Double, Int, Int, ConstTypedPtr<Double> >::Call(L, glMap1d);
#endif
}

static int lua_glMap2f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc10<Enum, Float, Float, Int, Int, Float, Float, Int, Int, ConstTypedPtr<Float>, glMap2f>::Call(L);
#else
  return WrapFunc10<Enum, Float, Float, Int, Int, Float, Float, Int, Int, ConstTypedPtr<Float> >::Call(L, glMap2f);
#endif
}
static int lua_glMap2d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc10<Enum, Double, Double, Int, Int, Double, Double, Int, Int, ConstTypedPtr<Double>, glMap2d>::Call(L);
#else
  return WrapFunc10<Enum, Double, Double, Int, Int, Double, Double, Int, Int, ConstTypedPtr<Double> >::Call(L, glMap2d);
#endif
}

static int lua_glEvalCoord1f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Float, glEvalCoord1f>::Call(L);
#else
  return WrapFunc1<Float>::Call(L, glEvalCoord1f);
#endif
}
static int lua_glEvalCoord1d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Double, glEvalCoord1d>::Call(L);
#else
  return WrapFunc1<Double>::Call(L, glEvalCoord1d);
#endif
}
static int lua_glEvalCoord2f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Float, Float, glEvalCoord2f>::Call(L);
#else
  return WrapFunc2<Float, Float>::Call(L, glEvalCoord2f);
#endif
}
static int lua_glEvalCoord2d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Double, Double, glEvalCoord2d>::Call(L);
#else
  return WrapFunc2<Double, Double>::Call(L, glEvalCoord2d);
#endif
}
static int lua_glEvalCoord2fv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Float>, glEvalCoord2fv>::Call(L);
#else
  return WrapFunc1<ConstArray<Float> >::Call(L, glEvalCoord2fv);
#endif
}
static int lua_glEvalCoord2dv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<ConstArray<Double>, glEvalCoord2dv>::Call(L);
#else
  return WrapFunc1<ConstArray<Double> >::Call(L, glEvalCoord2dv);
#endif
}

static int lua_glMapGrid1f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Float, Float, glMapGrid1f>::Call(L);
#else
  return WrapFunc3<Int, Float, Float>::Call(L, glMapGrid1f);
#endif
}
static int lua_glMapGrid1d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Int, Double, Double, glMapGrid1d>::Call(L);
#else
  return WrapFunc3<Int, Double, Double>::Call(L, glMapGrid1d);
#endif
}
static int lua_glMapGrid2f(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc6<Int, Float, Float, Int, Float, Float, glMapGrid2f>::Call(L);
#else
  return WrapFunc6<Int, Float, Float, Int, Float, Float>::Call(L, glMapGrid2f);
#endif
}
static int lua_glMapGrid2d(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc6<Int, Double, Double, Int, Double, Double, glMapGrid2d>::Call(L);
#else
  return WrapFunc6<Int, Double, Double, Int, Double, Double>::Call(L, glMapGrid2d);
#endif
}

static int lua_glEvalMesh1(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Enum, Int, Int, glEvalMesh1>::Call(L);
#else
  return WrapFunc3<Enum, Int, Int>::Call(L, glEvalMesh1);
#endif
}
static int lua_glEvalMesh2(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Enum, Int, Int, Int, Int, glEvalMesh2>::Call(L);
#else
  return WrapFunc5<Enum, Int, Int, Int, Int>::Call(L, glEvalMesh2);
#endif
}

static int lua_glEvalPoint1(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Int, glEvalPoint1>::Call(L);
#else
  return WrapFunc1<Int>::Call(L, glEvalPoint1);
#endif
}
static int lua_glEvalPoint2(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Int, Int, glEvalPoint2>::Call(L);
#else
  return WrapFunc2<Int, Int>::Call(L, glEvalPoint2);
#endif
}

static int lua_glInitNames(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc0<glInitNames>::Call(L);
#else
  return WrapFunc0::Call(L, glInitNames);
#endif
}

static int lua_glPopName(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc0<glPopName>::Call(L);
#else
  return WrapFunc0::Call(L, glPopName);
#endif
}

static int lua_glPushName(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Uint, glPushName>::Call(L);
#else
  return WrapFunc1<Uint>::Call(L, glPushName);
#endif
}

static int lua_glLoadName(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Uint, glLoadName>::Call(L);
#else
  return WrapFunc1<Uint>::Call(L, glLoadName);
#endif
}

static int lua_glRenderMode(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Enum mode(L, 1);
  GLint r = glRenderMode(mode);
  lua_pushinteger(L, r);
  return 1;
}

static int lua_glSelectBuffer(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Sizei, TypedPtr<Uint>, glSelectBuffer>::Call(L);
#else
  return WrapFunc2<Sizei, TypedPtr<Uint> >::Call(L, glSelectBuffer);
#endif
}

static int lua_glFeedbackBuffer(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Sizei, Enum, TypedPtr<Float>, glFeedbackBuffer>::Call(L);
#else
  return WrapFunc3<Sizei, Enum, TypedPtr<Float> >::Call(L, glFeedbackBuffer);
#endif
}

static int lua_glPassThrough(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Float, glPassThrough>::Call(L);
#else
  return WrapFunc1<Float>::Call(L, glPassThrough);
#endif
}

static int lua_glNewList(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, Enum, glNewList>::Call(L);
#else
  return WrapFunc2<Uint, Enum>::Call(L, glNewList);
#endif
}

static int lua_glEndList(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc0<glEndList>::Call(L);
#else
  return WrapFunc0::Call(L, glEndList);
#endif
}

static int lua_glCallList(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Uint, glCallList>::Call(L);
#else
  return WrapFunc1<Uint>::Call(L, glCallList);
#endif
}

static int lua_glCallLists(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc3<Sizei, Enum, ConstPtr, glCallLists>::Call(L);
#else
  return WrapFunc3<Sizei, Enum, ConstPtr>::Call(L, glCallLists);
#endif
}

static int lua_glListBase(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Uint, glListBase>::Call(L);
#else
  return WrapFunc1<Uint>::Call(L, glListBase);
#endif
}

static int lua_glGenLists(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Sizei s(L, 1);
  lua_pushinteger(L, glGenLists(s));
  return 1;
}

static int lua_glIsList(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Uint list(L, 1);
  lua_pushboolean(L, (glIsList(list) == GL_TRUE ? 1 : 0));
  return 1;
}

static int lua_glDeleteLists(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Uint, Sizei, glDeleteLists>::Call(L);
#else
  return WrapFunc2<Uint, Sizei>::Call(L, glDeleteLists);
#endif
}

static int lua_glFlush(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc0<glFlush>::Call(L);
#else
  return WrapFunc0::Call(L, glFlush);
#endif
}

static int lua_glFinish(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc0<glFinish>::Call(L);
#else
  return WrapFunc0::Call(L, glFinish);
#endif
}

static int lua_glHint(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, Enum, glHint>::Call(L);
#else
  return WrapFunc2<Enum, Enum>::Call(L, glHint);
#endif
}

static int lua_glIsTexture(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Uint tex(L, 1);
  lua_pushboolean(L, (glIsTexture(tex) == GL_TRUE ? 1 : 0));
  return 1;
}

static int lua_glGetString(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Enum name(L, 1);
  const GLubyte *s = glGetString(name);
  lua_pushstring(L, (const char*)s);
  return 1;
}

static int lua_glPushAttrib(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Bitfield, glPushAttrib>::Call(L);
#else
  return WrapFunc1<Bitfield>::Call(L, glPushAttrib);
#endif
}

static int lua_glPushClientAttrib(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<Bitfield, glPushClientAttrib>::Call(L);
#else
  return WrapFunc1<Bitfield>::Call(L, glPushClientAttrib);
#endif
}

static int lua_glPopAttrib(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc0<glPopAttrib>::Call(L);
#else
  return WrapFunc0::Call(L, glPopAttrib);
#endif
}

static int lua_glPopClientAttrib(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc0<glPopClientAttrib>::Call(L);
#else
  return WrapFunc0::Call(L, glPopClientAttrib);
#endif
}

static int lua_glGet(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Enum param(L, 1);
  GLint dim=0;
  LuaGL &gl = LuaGL::Instance();
  dim = gl.getParamDim(LuaGL::Booleanv, param);
  if (dim <= 0) {
    dim = gl.getParamDim(LuaGL::Integerv, param);
    if (dim <= 0) {
      dim = gl.getParamDim(LuaGL::Floatv, param);
      if (dim <= 0) {
        dim = gl.getParamDim(LuaGL::Doublev, param);
        if (dim > 0) {
          Array1D<Double> values(dim);
          glGetDoublev(param, values);
          if (dim == 1) {
            lua_pushnumber(L, values[0]);
          } else {
            values.toLUA(L);
          }
        }
      } else {
        Array1D<Float> values(dim);
        glGetFloatv(param, values);
        if (dim == 1) {
          lua_pushnumber(L, values[0]);
        } else {
          values.toLUA(L);
        }
      }
    } else {
      Array1D<Int> values(dim);
      glGetIntegerv(param, values);
      if (dim == 1) {
        lua_pushinteger(L, values[0]);
      } else {
        values.toLUA(L);
      }
    }
  } else {
    Array1D<Boolean> values(dim);
    glGetBooleanv(param, values);
    if (dim == 1) {
      lua_pushboolean(L, (values[0] == GL_TRUE ? 1 : 0));
    } else {
      values.toLUA(L);
    }
  }
  if (dim == 0) {
    luaL_error(L, "gl.Get: Invalid parameter name");
  }
  return 1;
}
/*
static int lua_glGetBooleanv(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Enum param(L, 1);
  GLboolean values[4];
  GLint nval = 0;
  switch (param) {
  case GL_COLOR_WRITEMASK:
    nval = 4;
    break;
  case GL_CURRENT_RASTER_POSITION_VALID:
  case GL_EDGE_FLAG:
  case GL_LIGHT_MODEL_LOCAL_VIEWER:
  case GL_LIGHT_MODEL_TWO_SIDE:
  case GL_DEPTH_WRITEMASK:
  case GL_UNPACK_SWAP_BYTES:
  case GL_UNPACK_LSB_FIRST:
  case GL_PACK_SWAP_BYTES:
  case GL_PACK_LSB_FIRST:
  case GL_MAP_COLOR:
  case GL_MAP_STENCIL:
  case GL_RGBA_MODE:
  case GL_INDEX_MODE:
  case GL_DOUBLEBUFFER:
  case GL_STEREO:
    nval = 1;
    break;
  default:
    break;
  }
  if (nval == 0) {
    luaL_error(L, "gl.GetBooleanv: invalid parameter name");
  }
  glGetBooleanv(param, values);
  if (nval == 1) {
    lua_pushboolean(L, (values[0] == GL_TRUE ? 1 : 0));
  } else {
    Array1D<Boolean>(values, nval).toLUA(L);
  }
  return 1;
}
static int lua_glGetIntegerv(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Enum param(L, 1);
  GLint values[4];
  GLint nval = 0;
  switch (param) {
  case GL_CURRENT_COLOR:
  case GL_CURRENT_RASTER_COLOR:
  case GL_VIEWPORT:
  case GL_SCISSOR_BOX:
    nval = 4;
    break;
  case GL_MAX_VIEWPORT_DIMS:
    nval = 2;
    break;
  case GL_CURRENT_INDEX:
  case GL_CURRENT_RASTER_INDEX:
  case GL_VERTEX_ARRAY_SIZE:
  case GL_VERTEX_ARRAY_TYPE:
  case GL_VERTEX_ARRAY_STRIDE:
  case GL_NORMAL_ARRAY_TYPE:
  case GL_NORMAL_ARRAY_STRIDE:
  case GL_COLOR_ARRAY_SIZE:
  case GL_COLOR_ARRAY_TYPE:
  case GL_COLOR_ARRAY_STRIDE:
  case GL_INDEX_ARRAY_TYPE:
  case GL_INDEX_ARRAY_STRIDE:
  case GL_TEXTURE_COORD_ARRAY_SIZE:
  case GL_TEXTURE_COORD_ARRAY_TYPE:
  case GL_TEXTURE_COORD_ARRAY_STRIDE:
  case GL_EDGE_FLAG_ARRAY_STRIDE:
  case GL_MODELVIEW_STACK_DEPTH:
  case GL_PROJECTION_STACK_DEPTH:
  case GL_TEXTURE_STACK_DEPTH:
  case GL_MATRIX_MODE:
  case GL_FOG_INDEX: // not in spec
  case GL_FOG_MODE:
  case GL_SHADE_MODEL:
  case GL_COLOR_MATERIAL_PARAMETER:
  case GL_COLOR_MATERIAL_FACE:
  case GL_LINE_STIPPLE_PATTERN:
  case GL_LINE_STIPPLE_REPEAT:
  case GL_CULL_FACE_MODE:
  case GL_FRONT_FACE:
  case GL_POLYGON_MODE:
  case GL_TEXTURE_BINDING_1D:
  case GL_TEXTURE_BINDING_2D:
  case GL_ALPHA_TEST_FUNC:
  case GL_ALPHA_TEST_REF:
  case GL_STENCIL_FUNC:
  case GL_STENCIL_VALUE_MASK:
  case GL_STENCIL_REF:
  case GL_STENCIL_FAIL:
  case GL_STENCIL_PASS_DEPTH_FAIL:
  case GL_STENCIL_PASS_DEPTH_PASS:
  case GL_DEPTH_FUNC:
  case GL_BLEND_SRC:
  case GL_BLEND_DST:
  case GL_LOGIC_OP_MODE:
  case GL_DRAW_BUFFER:
  case GL_INDEX_WRITEMASK:
  case GL_STENCIL_WRITEMASK:
  case GL_DEPTH_CLEAR_VALUE:
  case GL_STENCIL_CLEAR_VALUE:
  case GL_UNPACK_ROW_LENGTH:
  case GL_UNPACK_SKIP_ROWS:
  case GL_UNPACK_SKIP_PIXELS:
  case GL_UNPACK_ALIGNMENT:
  case GL_PACK_ROW_LENGTH:
  case GL_PACK_SKIP_ROWS:
  case GL_PACK_SKIP_PIXELS:
  case GL_PACK_ALIGNMENT:
  case GL_INDEX_SHIFT:
  case GL_INDEX_OFFSET:
  case GL_PIXEL_MAP_A_TO_A_SIZE:
  case GL_PIXEL_MAP_B_TO_B_SIZE:
  case GL_PIXEL_MAP_G_TO_G_SIZE:
  case GL_PIXEL_MAP_I_TO_A_SIZE:
  case GL_PIXEL_MAP_I_TO_B_SIZE:
  case GL_PIXEL_MAP_I_TO_G_SIZE:
  case GL_PIXEL_MAP_I_TO_I_SIZE:
  case GL_PIXEL_MAP_I_TO_R_SIZE:
  case GL_PIXEL_MAP_R_TO_R_SIZE:
  case GL_PIXEL_MAP_S_TO_S_SIZE:
  case GL_READ_BUFFER:
  case GL_PERSPECTIVE_CORRECTION_HINT:
  case GL_POINT_SMOOTH_HINT:
  case GL_LINE_SMOOTH_HINT:
  case GL_FOG_HINT:
  case GL_MAX_LIGHTS:
  case GL_MAX_CLIP_PLANES:
  case GL_MAX_MODELVIEW_STACK_DEPTH:
  case GL_MAX_PROJECTION_STACK_DEPTH:
  case GL_MAX_TEXTURE_STACK_DEPTH:
  case GL_SUBPIXEL_BITS:
  case GL_MAX_TEXTURE_SIZE:
  case GL_MAX_PIXEL_MAP_TABLE:
  case GL_MAX_NAME_STACK_DEPTH:
  case GL_MAX_LIST_NESTING:
  case GL_MAX_EVAL_ORDER:
  case GL_MAX_ATTRIB_STACK_DEPTH:
  case GL_MAX_CLIENT_ATTRIB_STACK_DEPTH:
  case GL_AUX_BUFFERS:
  case GL_RED_BITS:
  case GL_GREEN_BITS:
  case GL_BLUE_BITS:
  case GL_ALPHA_BITS:
  case GL_INDEX_BITS:
  case GL_DEPTH_BITS:
  case GL_STENCIL_BITS:
  case GL_ACCUM_RED_BITS:
  case GL_ACCUM_GREEN_BITS:
  case GL_ACCUM_BLUE_BITS:
  case GL_ACCUM_ALPHA_BITS:
  case GL_LIST_BASE:
  case GL_LIST_INDEX:
  case GL_LIST_MODE:
  case GL_ATTRIB_STACK_DEPTH:
  case GL_CLIENT_ATTRIB_STACK_DEPTH:
  case GL_NAME_STACK_DEPTH:
  case GL_RENDER_MODE:
  case GL_SELECTION_BUFFER_SIZE:
  case GL_FEEDBACK_BUFFER_SIZE:
  case GL_FEEDBACK_BUFFER_TYPE:
    nval = 1;
    break;
  default:
    break;
  }
  if (nval == 0) {
    extern int lua_glGetIntegerv_1_2(lua_State*, GLenum);
    if (lua_glGetIntegerv_1_2(L, param) != 0) {
      return 1;
    }
    luaL_error(L, "gl.GetIntegerv: invalid parameter name");
  }
  glGetIntegerv(param, values);
  if (nval == 1) {
    lua_pushinteger(L, values[0]);
  } else {
    Array1D<Int>(values, nval).toLUA(L);
  }
  return 1;
}
static int lua_glGetFloatv(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Enum param(L, 1);
  GLfloat values[16];
  GLint nval = 0;
  switch (param) {
  case GL_MODELVIEW_MATRIX:
  case GL_PROJECTION_MATRIX:
  case GL_TEXTURE_MATRIX:
    nval = 16;
    break;
  case GL_CURRENT_COLOR:
  case GL_CURRENT_TEXTURE_COORDS:
  case GL_CURRENT_RASTER_POSITION:
  case GL_CURRENT_RASTER_COLOR:
  case GL_CURRENT_RASTER_TEXTURE_COORDS:
  case GL_FOG_COLOR:
  case GL_LIGHT_MODEL_AMBIENT:
  case GL_COLOR_CLEAR_VALUE:
  case GL_ACCUM_CLEAR_VALUE:
  case GL_MAP2_GRID_DOMAIN:
    nval = 4;
    break;
  case GL_CURRENT_NORMAL:
    nval = 3;
    break;
  case GL_DEPTH_RANGE:
  case GL_MAP1_GRID_DOMAIN:
  case GL_MAP2_GRID_SEGMENTS:
  case GL_POINT_SIZE_RANGE:
  case GL_LINE_WIDTH_RANGE:
    nval = 2;
    break;
  case GL_CURRENT_INDEX:
  case GL_CURRENT_RASTER_DISTANCE:
  case GL_CURRENT_RASTER_INDEX:
  case GL_FOG_INDEX:
  case GL_FOG_DENSITY:
  case GL_FOG_START:
  case GL_FOG_END:
  case GL_POINT_SIZE:
  case GL_LINE_WIDTH:
  case GL_POLYGON_OFFSET_FACTOR:
  case GL_POLYGON_OFFSET_UNITS:
  case GL_INDEX_CLEAR_VALUE:
  case GL_RED_SCALE:
  case GL_GREEN_SCALE:
  case GL_BLUE_SCALE:
  case GL_ALPHA_SCALE:
  case GL_DEPTH_SCALE:
  case GL_RED_BIAS:
  case GL_GREEN_BIAS:
  case GL_BLUE_BIAS:
  case GL_ALPHA_BIAS:
  case GL_DEPTH_BIAS:
  case GL_ZOOM_X:
  case GL_ZOOM_Y:
  case GL_MAP1_GRID_SEGMENTS:
  case GL_POINT_SIZE_GRANULARITY:
  case GL_LINE_WIDTH_GRANULARITY:
    nval = 1;
    break;
  default:
    break;
  }
  if (nval == 0) {
    luaL_error(L, "gl.GetFloatv: invalid parameter name");
  }
  glGetFloatv(param, values);
  if (nval == 1) {
    lua_pushnumber(L, values[0]);
  } else if (nval == 16) {
    FlatArray2D<Float>(values, 4, 4).toLUA(L, COLUMN_MAJOR, ROW_MAJOR);
  } else {
    Array1D<Float>(values, nval).toLUA(L);
  }
  return 1;
}
static int lua_glGetDoublev(lua_State *L) {
  // just like float
  return lua_glGetFloatv(L);
}
*/
static int lua_glGetClipPlane(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Enum plane(L, 1);
  GLdouble eq[4];
  glGetClipPlane(plane, eq);
  Array1D<Double>(eq, 4).toLUA(L);
  return 1;
}

static int lua_glGetLight(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum light(L, 1);
  Enum param(L, 2);
  GLint dim=0;
  LuaGL &gl = LuaGL::Instance();  
  dim = gl.getParamDim(LuaGL::Lightiv, param);
  if (dim <= 0) {
    dim = gl.getParamDim(LuaGL::Lightfv, param);
    if (dim > 0) {
      Array1D<Float> values(dim);
      glGetLightfv(light, param, values);
      if (dim == 1) {
        lua_pushnumber(L, values[0]);
      } else {
        values.toLUA(L);
      }
    }
  } else {
    Array1D<Int> values(dim);
    glGetLightiv(light, param, values);
    if (dim == 1) {
      lua_pushinteger(L, values[0]);
    } else {
      values.toLUA(L);
    }
  }
  if (dim == 0) {
    luaL_error(L, "gl.GetLight: invalid parameter");
  }
  return 1;
}
/*
static int lua_glGetLightiv(lua_State *L) {
  luaL_error(L, "gl.GetLightiv: Unsupported parameter name");
  return 0;
}
static int lua_glGetLightfv(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum light(L, 1);
  Enum param(L, 2);
  GLfloat values[4];
  GLint nval = 0;
  switch (param) {
  case GL_AMBIENT:
  case GL_DIFFUSE:
  case GL_SPECULAR:
  case GL_POSITION:
    nval = 4;
    break;
  case GL_SPOT_DIRECTION:
    nval = 3;
    break;
  case GL_SPOT_CUTOFF:
  case GL_CONSTANT_ATTENUATION:
  case GL_LINEAR_ATTENUATION:
  case GL_QUADRATIC_ATTENUATION:
    nval = 1;
  default:
    break;
  }
  if (nval == 0) {
    luaL_error(L, "gl.GetLightfv: Unsupported parameter name");
  }
  glGetLightfv(light, param, values);
  if (nval == 1) {
    lua_pushnumber(L, values[0]);
  } else {
    Array1D<Float>(values, nval).toLUA(L);
  }
  return 1;
}
*/

static int lua_glGetMaterial(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum face(L, 1);
  Enum param(L, 2);
  GLint dim=0;
  LuaGL &gl = LuaGL::Instance();  
  dim = gl.getParamDim(LuaGL::Materialiv, param);
  if (dim <= 0) {
    dim = gl.getParamDim(LuaGL::Materialfv, param);
    if (dim > 0) {
      Array1D<Float> values(dim);
      glGetMaterialfv(face, param, values);
      if (dim == 1) {
        lua_pushnumber(L, values[0]);
      } else {
        values.toLUA(L);
      }
    }
  } else {
    Array1D<Int> values(dim);
    glGetMaterialiv(face, param, values);
    if (dim == 1) {
      lua_pushinteger(L, values[0]);
    } else {
      values.toLUA(L);
    }
  }
  if (dim == 0) {
    luaL_error(L, "gl.GetMaterial: invalid parameter");
  }
  return 1;
}
/*
static int lua_glGetMaterialiv(lua_State *L) {
  luaL_error(L, "gl.GetMaterialiv: Unsupported parameter name");
  return 0;
}
static int lua_glGetMaterialfv(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum face(L, 1);
  Enum param(L, 2);
  GLfloat values[4];
  GLint nval = 0;
  switch (param) {
  case GL_AMBIENT:
  case GL_DIFFUSE:
  case GL_SPECULAR:
  case GL_EMISSION:
    nval = 4;
    break;
  case GL_COLOR_INDEXES:
    nval = 3;
    break;
  case GL_SHININESS:
    nval = 1;
  default:
    break;
  }
  if (nval == 0) {
    luaL_error(L, "gl.Materialfv: invalid parameter name");
  }
  glGetMaterialfv(face, param, values);
  if (nval == 1) {
    lua_pushnumber(L, values[0]);
  } else {
    Array1D<Float>(values, nval).toLUA(L);
  }
  return 1;
}
*/

static int lua_glGetTexEnv(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum target(L, 1);
  Enum param(L, 2);
  GLint dim=0;
  LuaGL &gl = LuaGL::Instance();  
  dim = gl.getParamDim(LuaGL::TexEnviv, param);
  if (dim <= 0) {
    dim = gl.getParamDim(LuaGL::TexEnvfv, param);
    if (dim > 0) {
      Array1D<Float> values(dim);
      glGetTexEnvfv(target, param, values);
      if (dim == 1) {
        lua_pushnumber(L, values[0]);
      } else {
        values.toLUA(L);
      }
    }
  } else {
    Array1D<Int> values(dim);
    glGetTexEnviv(target, param, values);
    if (dim == 1) {
      lua_pushinteger(L, values[0]);
    } else {
      values.toLUA(L);
    }
  }
  if (dim == 0) {
    luaL_error(L, "gl.GetTexEnv: invalid parameter");
  }
  return 1;
}
/*
static int lua_glGetTexEnviv(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum target(L, 1);
  Enum param(L, 2);
  GLint values[4];
  GLint nval = 0;
  switch (param) {
  case GL_TEXTURE_ENV_MODE:
    nval = 1;
  default:
    break;
  }
  if (nval == 0) {
    luaL_error(L, "gl.GetTexEnviv: Invalid parameter name");
  }
  glGetTexEnviv(target, param, values);
  if (nval == 1) {
    lua_pushinteger(L, values[0]);
  } else {
    Array1D<Int>(values, nval).toLUA(L);
  }
  return 1;
}
static int lua_glGetTexEnvfv(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum target(L, 1);
  Enum param(L, 2);
  GLfloat values[4];
  GLint nval = 0;
  switch (param) {
  case GL_TEXTURE_ENV_COLOR:
    nval = 4;
  default:
    break;
  }
  if (nval == 0) {
    luaL_error(L, "gl.GetTexEnvfv: invalid parameter name");
  }
  glGetTexEnvfv(target, param, values);
  if (nval == 1) {
    lua_pushnumber(L, values[0]);
  } else {
    Array1D<Float>(values, nval).toLUA(L);
  }
  return 0;
}
*/

static int lua_glGetTexGen(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum coord(L, 1);
  Enum param(L, 2);
  GLint dim=0;
  LuaGL &gl = LuaGL::Instance();  
  dim = gl.getParamDim(LuaGL::TexGeniv, param);
  if (dim <= 0) {
    dim = gl.getParamDim(LuaGL::TexGenfv, param);
    if (dim <= 0) {
      dim = gl.getParamDim(LuaGL::TexGendv, param);
      if (dim > 0) {
        Array1D<Double> values(dim);
        glGetTexGendv(coord, param, values);
        if (dim == 1) {
          lua_pushnumber(L, values[0]);
        } else {
          values.toLUA(L);
        }
      }
    } else {
      Array1D<Float> values(dim);
      glGetTexGenfv(coord, param, values);
      if (dim == 1) {
        lua_pushnumber(L, values[0]);
      } else {
        values.toLUA(L);
      }
    }
  } else {
    Array1D<Int> values(dim);
    glGetTexGeniv(coord, param, values);
    if (dim == 1) {
      lua_pushinteger(L, values[0]);
    } else {
      values.toLUA(L);
    }
  }
  if (dim == 0) {
    luaL_error(L, "gl.GetTexGen: invalid parameter");
  }
  return 1;
}
/*
static int lua_glGetTexGeniv(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum coord(L, 1);
  Enum param(L, 2);
  GLint values[4];
  GLint nval = 0;
  switch (param) {
  case GL_TEXTURE_GEN_MODE:
    nval = 1;
  default:
    break;
  }
  if (nval == 0) {
    luaL_error(L, "gl.GetTexGeniv: invalid parameter name");
  }
  glGetTexEnviv(coord, param, values);
  if (nval == 1) {
    lua_pushinteger(L, values[0]);
  } else {
    Array1D<Int>(values, nval).toLUA(L);
  }
  return 1;
}
static int lua_glGetTexGenfv(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum coord(L, 1);
  Enum param(L, 2);
  GLfloat values[4];
  GLint nval = 0;
  switch (param) {
  case GL_OBJECT_PLANE:
  case GL_EYE_PLANE:
    nval = 4;
  default:
    break;
  }
  if (nval == 0) {
    luaL_error(L, "gl.GetTexGenfv: invalid parameter name");
  }
  glGetTexEnvfv(coord, param, values);
  if (nval == 1) {
    lua_pushnumber(L, values[0]);
  } else {
    Array1D<Float>(values, nval).toLUA(L);
  }
  return 1;
}
static int lua_glGetTexGendv(lua_State *L) {
  return lua_glGetTexGenfv(L);
}
*/

static int lua_glGetTexParameter(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum target(L, 1);
  Enum param(L, 2);
  GLint dim=0;
  LuaGL &gl = LuaGL::Instance();  
  dim = gl.getParamDim(LuaGL::TexParameteriv, param);
  if (dim <= 0) {
    dim = gl.getParamDim(LuaGL::TexParameterfv, param);
    if (dim > 0) {
      Array1D<Float> values(dim);
      glGetTexParameterfv(target, param, values);
      if (dim == 1) {
        lua_pushnumber(L, values[0]);
      } else {
        values.toLUA(L);
      }
    }
  } else {
    Array1D<Int> values(dim);
    glGetTexParameteriv(target, param, values);
    if (dim == 1) {
      lua_pushinteger(L, values[0]);
    } else {
      values.toLUA(L);
    }
  }
  if (dim == 0) {
    luaL_error(L, "gl.GetTexParameter: invalid parameter");
  }
  return 1;
}
/*
static int lua_glGetTexParameteriv(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum target(L, 1);
  Enum param(L, 2);
  GLint values[4];
  GLint nval = 0;
  switch (param) {
  case GL_TEXTURE_MIN_FILTER:
  case GL_TEXTURE_MAG_FILTER:
  case GL_TEXTURE_WRAP_S:
  case GL_TEXTURE_WRAP_T:
  case GL_TEXTURE_RESIDENT:
  default:
    break;
  }
  if (nval == 0) {
    extern int lua_glGetTexParameteriv_1_2(lua_State*,GLenum,GLenum);
    if (lua_glGetTexParameteriv_1_2(L, target, param) != 0) {
      return 1;
    }
    luaL_error(L, "gl.GetTexParameteriv: invalid parameter name");
  }
  glGetTexParameteriv(target, param, values);
  if (nval == 1) {
    lua_pushinteger(L, values[0]);
  } else {
    Array1D<Int>(values, nval).toLUA(L);
  }
  return 1;
}
static int lua_glGetTexParameterfv(lua_State *L) {
  CHECK_ARG_COUNT(L, 2);
  Enum target(L, 1);
  Enum param(L, 2);
  GLfloat values[4];
  GLint nval = 0;
  switch (param) {
  case GL_TEXTURE_PRIORITY:
    nval = 1;
    break;
  case GL_TEXTURE_BORDER_COLOR:
    nval = 4;
  default:
    break;
  }
  if (nval == 0) {
    luaL_error(L, "gl.GetTexParameterfv: invalid parameter name");
  }
  glGetTexParameterfv(target, param, values);
  if (nval == 1) {
    lua_pushnumber(L, values[0]);
  } else {
    Array1D<Float>(values, nval).toLUA(L);
  }
  return 1;
}
*/

static int lua_glGetTexLevelParameter(lua_State *L) {
  CHECK_ARG_COUNT(L, 3);
  Enum target(L, 1);
  Int level(L, 2);
  Enum param(L, 3);
  GLint dim=0;
  LuaGL &gl = LuaGL::Instance();  
  dim = gl.getParamDim(LuaGL::TexLevelParameteriv, param);
  if (dim <= 0) {
    dim = gl.getParamDim(LuaGL::TexLevelParameterfv, param);
    if (dim > 0) {
      Array1D<Float> values(dim);
      glGetTexLevelParameterfv(target, level, param, values);
      if (dim == 1) {
        lua_pushnumber(L, values[0]);
      } else {
        values.toLUA(L);
      }
    }
  } else {
    Array1D<Int> values(dim);
    glGetTexLevelParameteriv(target, level, param, values);
    if (dim == 1) {
      lua_pushinteger(L, values[0]);
    } else {
      values.toLUA(L);
    }
  }
  if (dim == 0) {
    luaL_error(L, "gl.GetTexLevelParameter: invalid parameter");
  }
  return 1;
}


/*
static int lua_glGetTexLevelParameteriv(lua_State *L) {
  CHECK_ARG_COUNT(L, 3);
  Enum target(L, 1);
  Int level(L, 2);
  Enum param(L, 3);
  GLint values[4];
  GLint nval = 0;
  switch (param) {
  case GL_TEXTURE_WIDTH:
  case GL_TEXTURE_HEIGHT:
  case GL_TEXTURE_BORDER:
  case GL_TEXTURE_INTERNAL_FORMAT:
  case GL_TEXTURE_RED_SIZE:
  case GL_TEXTURE_GREEN_SIZE:
  case GL_TEXTURE_BLUE_SIZE:
  case GL_TEXTURE_ALPHA_SIZE:
  case GL_TEXTURE_LUMINANCE_SIZE:
  case GL_TEXTURE_INTENSITY_SIZE:
    nval = 1;
  default:
    break;
  }
  if (nval == 0) {
    extern int lua_glGetTexLevelParameteriv_1_2(lua_State*,GLenum,GLint,GLenum);
    if (lua_glGetTexLevelParameteriv_1_2(L, target, level, param) != 0) {
      return 1;
    }
    luaL_error(L, "gl.GetTexLevelParameteriv: invalid parameter name");
  }
  glGetTexLevelParameteriv(target, level, param, values);
  if (nval == 1) {
    lua_pushinteger(L, values[0]);
  } else {
    Array1D<Int>(values, nval).toLUA(L);
  }
  return 1;
}
static int lua_glGetTexLevelParameterfv(lua_State *L) {
  luaL_error(L, "gl.GetTexLevelParameterfv: Unsupported parameter name");
  return 0;
}
*/

static int lua_glGetPixelMapuiv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, TypedPtr<Uint>, glGetPixelMapuiv>::Call(L);
#else
  return WrapFunc2<Enum, TypedPtr<Uint> >::Call(L, glGetPixelMapuiv);
#endif
}
static int lua_glGetPixelMapusv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, TypedPtr<Ushort>, glGetPixelMapusv>::Call(L);
#else
  return WrapFunc2<Enum, TypedPtr<Ushort> >::Call(L, glGetPixelMapusv);
#endif
}
static int lua_glGetPixelMapfv(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc2<Enum, TypedPtr<Float>, glGetPixelMapfv>::Call(L);
#else
  return WrapFunc2<Enum, TypedPtr<Float> >::Call(L, glGetPixelMapfv);
#endif
}

static int lua_glGetMapiv(lua_State *L) {
  int narg = lua_gettop(L);
  if (narg < 2) {
    luaL_error(L, "gl.GetMapiv: requires at least two arguments");
  }
  Enum target(L, 1);
  Enum query(L, 2);
  GLint dim = 0;
  switch (target) {
    case GL_MAP1_COLOR_4:
    case GL_MAP1_INDEX:
    case GL_MAP1_NORMAL:
    case GL_MAP1_TEXTURE_COORD_1:
    case GL_MAP1_TEXTURE_COORD_2:
    case GL_MAP1_TEXTURE_COORD_3:
    case GL_MAP1_TEXTURE_COORD_4:
    case GL_MAP1_VERTEX_3:
    case GL_MAP1_VERTEX_4:
      dim = 1;
      break;
    case GL_MAP2_COLOR_4:
    case GL_MAP2_INDEX:
    case GL_MAP2_NORMAL:
    case GL_MAP2_TEXTURE_COORD_1:
    case GL_MAP2_TEXTURE_COORD_2:
    case GL_MAP2_TEXTURE_COORD_3:
    case GL_MAP2_TEXTURE_COORD_4:
    case GL_MAP2_VERTEX_3:
    case GL_MAP2_VERTEX_4:
      dim = 2;
    default:
      break;
  }
  if (dim == 0) {
    luaL_error(L, "gl.GetMapiv: invalid target");
  }
  switch (query) {
    case GL_COEFF: {
      if (narg != 3) {
        luaL_error(L, "gl.GetMapiv: invalid argument count");
      }
      TypedPtr<Int> values(L, 3);
      glGetMapiv(target, query, values);
      break;
    }
    case GL_ORDER: {
      if (narg != 2) {
        luaL_error(L, "gl.GetMapiv: invalid argument count");
      }
      GLint values[4];
      glGetMapiv(target, query, values);
      Array1D<Int>(values, dim).toLUA(L);
      break;
    }
    case GL_DOMAIN: {
      if (narg != 2) {
        luaL_error(L, "gl.GetMapiv: invalid argument count");
      }
      GLint values[4];
      glGetMapiv(target, query, values);
      Array1D<Int>(values, dim*2).toLUA(L);
      break;
    }
    default:
      luaL_error(L, "gl.GetMapiv: invalid query");
  }
  return 1;
}
static int lua_glGetMapfv(lua_State *L) {
  int narg = lua_gettop(L);
  if (narg < 2) {
    luaL_error(L, "gl.GetMapfv: requires at least two arguments");
  }
  Enum target(L, 1);
  Enum query(L, 2);
  GLint dim = 0;
  switch (target) {
    case GL_MAP1_COLOR_4:
    case GL_MAP1_INDEX:
    case GL_MAP1_NORMAL:
    case GL_MAP1_TEXTURE_COORD_1:
    case GL_MAP1_TEXTURE_COORD_2:
    case GL_MAP1_TEXTURE_COORD_3:
    case GL_MAP1_TEXTURE_COORD_4:
    case GL_MAP1_VERTEX_3:
    case GL_MAP1_VERTEX_4:
      dim = 1;
      break;
    case GL_MAP2_COLOR_4:
    case GL_MAP2_INDEX:
    case GL_MAP2_NORMAL:
    case GL_MAP2_TEXTURE_COORD_1:
    case GL_MAP2_TEXTURE_COORD_2:
    case GL_MAP2_TEXTURE_COORD_3:
    case GL_MAP2_TEXTURE_COORD_4:
    case GL_MAP2_VERTEX_3:
    case GL_MAP2_VERTEX_4:
      dim = 2;
    default:
      break;
  }
  if (dim == 0) {
    luaL_error(L, "gl.GetMapfv: invalid target");
  }
  switch (query) {
    case GL_COEFF: {
      if (narg != 3) {
        luaL_error(L, "gl.GetMapfv: invalid argument count");
      }
      TypedPtr<Float> values(L, 3);
      glGetMapfv(target, query, values);
      break;
    }
    case GL_ORDER: {
      if (narg != 2) {
        luaL_error(L, "gl.GetMapfv: invalid argument count");
      }
      GLfloat values[4];
      glGetMapfv(target, query, values);
      Array1D<Float>(values, dim).toLUA(L);
      break;
    }
    case GL_DOMAIN: {
      if (narg != 2) {
        luaL_error(L, "gl.GetMapfv: invalid argument count");
      }
      GLfloat values[4];
      glGetMapfv(target, query, values);
      Array1D<Float>(values, dim*2).toLUA(L);
      break;
    }
    default:
      luaL_error(L, "gl.GetMapfv: invalid query");
  }
  return 1;
}
static int lua_glGetMapdv(lua_State *L) {
  int narg = lua_gettop(L);
  if (narg < 2) {
    luaL_error(L, "gl.GetMapdv: requires at least two arguments");
  }
  Enum target(L, 1);
  Enum query(L, 2);
  GLint dim = 0;
  switch (target) {
    case GL_MAP1_COLOR_4:
    case GL_MAP1_INDEX:
    case GL_MAP1_NORMAL:
    case GL_MAP1_TEXTURE_COORD_1:
    case GL_MAP1_TEXTURE_COORD_2:
    case GL_MAP1_TEXTURE_COORD_3:
    case GL_MAP1_TEXTURE_COORD_4:
    case GL_MAP1_VERTEX_3:
    case GL_MAP1_VERTEX_4:
      dim = 1;
      break;
    case GL_MAP2_COLOR_4:
    case GL_MAP2_INDEX:
    case GL_MAP2_NORMAL:
    case GL_MAP2_TEXTURE_COORD_1:
    case GL_MAP2_TEXTURE_COORD_2:
    case GL_MAP2_TEXTURE_COORD_3:
    case GL_MAP2_TEXTURE_COORD_4:
    case GL_MAP2_VERTEX_3:
    case GL_MAP2_VERTEX_4:
      dim = 2;
    default:
      break;
  }
  if (dim == 0) {
    luaL_error(L, "gl.GetMapdv: invalid target");
  }
  switch (query) {
    case GL_COEFF: {
      if (narg != 3) {
        luaL_error(L, "gl.GetMapdv: invalid argument count");
      }
      TypedPtr<Double> values(L, 3);
      glGetMapdv(target, query, values);
      break;
    }
    case GL_ORDER: {
      if (narg != 2) {
        luaL_error(L, "gl.GetMapdv: invalid argument count");
      }
      GLdouble values[4];
      glGetMapdv(target, query, values);
      Array1D<Double>(values, dim).toLUA(L);
      break;
    }
    case GL_DOMAIN: {
      if (narg != 2) {
        luaL_error(L, "gl.GetMapdv: invalid argument count");
      }
      GLdouble values[4];
      glGetMapdv(target, query, values);
      Array1D<Double>(values, dim*2).toLUA(L);
      break;
    }
    default:
      luaL_error(L, "gl.GetMapdv: invalid query");
  }
  return 1;
}

static int lua_glGetTexImage(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc5<Enum, Int, Enum, Enum, Ptr, glGetTexImage>::Call(L);
#else
  return WrapFunc5<Enum, Int, Enum, Enum, Ptr>::Call(L, glGetTexImage);
#endif
}

static int lua_glGetPolygonStipple(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
  return WrapFunc1<TypedPtr<Ubyte>, glGetPolygonStipple>::Call(L);
#else
  return WrapFunc1<TypedPtr<Ubyte> >::Call(L, glGetPolygonStipple);
#endif
}

//static int lua_glGetPointerv(lua_State *L) {
static int lua_glGetPointer(lua_State *L) {
  CHECK_ARG_COUNT(L, 1);
  Enum param(L, 1);
  GLvoid *ptr;
  glGetPointerv(param, &ptr);
  lua_pushlightuserdata(L, ptr);
  return 1;
}



// ---

void Register_GL_1_1_Constants(LuaGL::ConstantMap &constants) {
  constants["NO_ERROR"] = GL_NO_ERROR;
  constants["INVALID_ENUM"] = GL_INVALID_ENUM;
  constants["INVALID_VALUE"] = GL_INVALID_VALUE;
  constants["INVALID_OPERATION"] = GL_INVALID_OPERATION;
  constants["STACK_OVERFLOW"] = GL_STACK_OVERFLOW;
  constants["STACK_UNDERFLOW"] = GL_STACK_UNDERFLOW;
  constants["OUT_OF_MEMORY"] = GL_OUT_OF_MEMORY;
  constants["POINTS"] = GL_POINTS;
  constants["LINES"] = GL_LINES;
  constants["LINE_LOOP"] = GL_LINE_LOOP;
  constants["LINE_STRIP"] = GL_LINE_STRIP;
  constants["TRIANGLES"] = GL_TRIANGLES;
  constants["TRIANGLE_STRIP"] = GL_TRIANGLE_STRIP;
  constants["TRIANGLE_FAN"] = GL_TRIANGLE_FAN;
  constants["QUADS"] = GL_QUADS;
  constants["QUAD_STRIP"] = GL_QUAD_STRIP;
  constants["POLYGON"] = GL_POLYGON;
  constants["TRUE"] = GL_TRUE;
  constants["FALSE"] = GL_FALSE;
  constants["BYTE"] = GL_BYTE;
  constants["UNSIGNED_BYTE"] = GL_UNSIGNED_BYTE;
  constants["SHORT"] = GL_SHORT;
  constants["UNSIGNED_SHORT"] = GL_UNSIGNED_SHORT;
  constants["INT"] = GL_INT;
  constants["UNSIGNED_INT"] = GL_UNSIGNED_INT;
  constants["FLOAT"] = GL_FLOAT;
  constants["DOUBLE"] = GL_DOUBLE;
  constants["VERTEX_ARRAY"] = GL_VERTEX_ARRAY;
  constants["NORMAL_ARRAY"] = GL_NORMAL_ARRAY;
  constants["COLOR_ARRAY"] = GL_COLOR_ARRAY;
  constants["INDEX_ARRAY"] = GL_INDEX_ARRAY;
  constants["TEXTURE_COORD_ARRAY"] = GL_TEXTURE_COORD_ARRAY;
  constants["EDGE_FLAG_ARRAY"] = GL_EDGE_FLAG_ARRAY;
  constants["V2F"] = GL_V2F;
  constants["V3F"] = GL_V3F;
  constants["C4UB_V2F"] = GL_C4UB_V2F;
  constants["C4UB_V3F"] = GL_C4UB_V3F;
  constants["C3F_V3F"] = GL_C3F_V3F;
  constants["N3F_V3F"] = GL_N3F_V3F;
  constants["C4F_N3F_V3F"] = GL_C4F_N3F_V3F;
  constants["T2F_V3F"] = GL_T2F_V3F;
  constants["T4F_V4F"] = GL_T4F_V4F;
  constants["T2F_C4UB_V3F"] = GL_T2F_C4UB_V3F;
  constants["T2F_C3F_V3F"] = GL_T2F_C3F_V3F;
  constants["T2F_N3F_V3F"] = GL_T2F_N3F_V3F;
  constants["T2F_C4F_N3F_V3F"] = GL_T2F_C4F_N3F_V3F;
  constants["T4F_C4F_N3F_V4F"] = GL_T4F_C4F_N3F_V4F;
  constants["MODELVIEW"] = GL_MODELVIEW;
  constants["PROJECTION"] = GL_PROJECTION;
  constants["TEXTURE"] = GL_TEXTURE;
  constants["NORMALIZE"] = GL_NORMALIZE;
  constants["TEXTURE_GEN_MODE"] = GL_TEXTURE_GEN_MODE;
  constants["OBJECT_PLANE"] = GL_OBJECT_PLANE;
  constants["EYE_PLANE"] = GL_EYE_PLANE;
  constants["EYE_LINEAR"] = GL_EYE_LINEAR;
  constants["OBJECT_LINEAR"] = GL_OBJECT_LINEAR;
  constants["SPHERE_MAP"] = GL_SPHERE_MAP;
  constants["TEXTURE_GEN_S"] = GL_TEXTURE_GEN_S;
  constants["TEXTURE_GEN_T"] = GL_TEXTURE_GEN_T;
  constants["TEXTURE_GEN_R"] = GL_TEXTURE_GEN_R;
  constants["TEXTURE_GEN_Q"] = GL_TEXTURE_GEN_Q;
  constants["CLIP_PLANE0"] = GL_CLIP_PLANE0;
  constants["CLIP_PLANE1"] = GL_CLIP_PLANE1;
  constants["CLIP_PLANE2"] = GL_CLIP_PLANE2;
  constants["CLIP_PLANE3"] = GL_CLIP_PLANE3;
  constants["CLIP_PLANE4"] = GL_CLIP_PLANE4;
  constants["CLIP_PLANE5"] = GL_CLIP_PLANE5;
  constants["LIGHTING"] = GL_LIGHTING;
  constants["LIGHT0"] = GL_LIGHT0;
  constants["LIGHT1"] = GL_LIGHT1;
  constants["LIGHT2"] = GL_LIGHT2;
  constants["LIGHT3"] = GL_LIGHT3;
  constants["LIGHT4"] = GL_LIGHT4;
  constants["LIGHT5"] = GL_LIGHT5;
  constants["LIGHT6"] = GL_LIGHT6;
  constants["LIGHT7"] = GL_LIGHT7;
  constants["FRONT"] = GL_FRONT;
  constants["BACK"] = GL_BACK;
  constants["FRONT_AND_BACK"] = GL_FRONT_AND_BACK;
  constants["COLOR_MATERIAL"] = GL_COLOR_MATERIAL;
  constants["AMBIENT"] = GL_AMBIENT;
  constants["DIFFUSE"] = GL_DIFFUSE;
  constants["AMBIENT_AND_DIFFUSE"] = GL_AMBIENT_AND_DIFFUSE;
  constants["SPECULAR"] = GL_SPECULAR;
  constants["EMISSION"] = GL_EMISSION;
  constants["SHININESS"] = GL_SHININESS;
  constants["COLOR_INDEXES"] = GL_COLOR_INDEXES;
  constants["POSITION"] = GL_POSITION;
  constants["SPOT_DIRECTION"] = GL_SPOT_DIRECTION;
  constants["SPOT_EXPONENT"] = GL_SPOT_EXPONENT;
  constants["SPOT_CUTOFF"] = GL_SPOT_CUTOFF;
  constants["CONSTANT_ATTENUATION"] = GL_CONSTANT_ATTENUATION;
  constants["LINEAR_ATTENUATION"] = GL_LINEAR_ATTENUATION;
  constants["QUADRATIC_ATTENUATION"] = GL_QUADRATIC_ATTENUATION;
  constants["LIGHT_MODEL_LOCAL_VIEWER"] = GL_LIGHT_MODEL_LOCAL_VIEWER;
  constants["LIGHT_MODEL_TWO_SIDE"] = GL_LIGHT_MODEL_TWO_SIDE;
  constants["LIGHT_MODEL_AMBIENT"] = GL_LIGHT_MODEL_AMBIENT;
  constants["FLAT"] = GL_FLAT;
  constants["SMOOTH"] = GL_SMOOTH;
  constants["CW"] = GL_CW;
  constants["CCW"] = GL_CCW;
  constants["POINT_SMOOTH"] = GL_POINT_SMOOTH;
  constants["LINE_SMOOTH"] = GL_LINE_SMOOTH;
  constants["LINE_STIPPLE"] = GL_LINE_STIPPLE;
  constants["POLYGON_SMOOTH"] = GL_POLYGON_SMOOTH;
  constants["POLYGON_STIPPLE"] = GL_POLYGON_STIPPLE;
  constants["POLYGON_OFFSET_POINT"] = GL_POLYGON_OFFSET_POINT;
  constants["POLYGON_OFFSET_LINE"] = GL_POLYGON_OFFSET_LINE;
  constants["POLYGON_OFFSET_FILL"] = GL_POLYGON_OFFSET_FILL;
  constants["POINT"] = GL_POINT;
  constants["LINE"] = GL_LINE;
  constants["FILL"] = GL_FILL;
  constants["UNPACK_SWAP_BYTES"] = GL_UNPACK_SWAP_BYTES;
  constants["UNPACK_LSB_FIRST"] = GL_UNPACK_LSB_FIRST;
  constants["UNPACK_ROW_LENGTH"] = GL_UNPACK_ROW_LENGTH;
  constants["UNPACK_SKIP_ROWS"] = GL_UNPACK_SKIP_ROWS;
  constants["UNPACK_SKIP_PIXELS"] = GL_UNPACK_SKIP_PIXELS;
  constants["UNPACK_ALIGNMENT"] = GL_UNPACK_ALIGNMENT;
  constants["MAP_COLOR"] = GL_MAP_COLOR;
  constants["MAP_STENCIL"] = GL_MAP_STENCIL;
  constants["INDEX_SHIFT"] = GL_INDEX_SHIFT;
  constants["INDEX_OFFSET"] = GL_INDEX_OFFSET;
  constants["RED_SCALE"] = GL_RED_SCALE;
  constants["RED_BIAS"] = GL_RED_BIAS;
  constants["GREEN_SCALE"] = GL_GREEN_SCALE;
  constants["GREEN_BIAS"] = GL_GREEN_BIAS;
  constants["BLUE_SCALE"] = GL_BLUE_SCALE;
  constants["BLUE_BIAS"] = GL_BLUE_BIAS;
  constants["ALPHA_SCALE"] = GL_ALPHA_SCALE;
  constants["ALPHA_BIAS"] = GL_ALPHA_BIAS;
  constants["DEPTH_SCALE"] = GL_DEPTH_SCALE;
  constants["DEPTH_BIAS"] = GL_DEPTH_BIAS;
  constants["PIXEL_MAP_I_TO_I"] = GL_PIXEL_MAP_I_TO_I;
  constants["PIXEL_MAP_S_TO_S"] = GL_PIXEL_MAP_S_TO_S;
  constants["PIXEL_MAP_I_TO_R"] = GL_PIXEL_MAP_I_TO_R;
  constants["PIXEL_MAP_I_TO_G"] = GL_PIXEL_MAP_I_TO_G;
  constants["PIXEL_MAP_I_TO_B"] = GL_PIXEL_MAP_I_TO_B;
  constants["PIXEL_MAP_I_TO_A"] = GL_PIXEL_MAP_I_TO_A;
  constants["PIXEL_MAP_R_TO_R"] = GL_PIXEL_MAP_R_TO_R;
  constants["PIXEL_MAP_G_TO_G"] = GL_PIXEL_MAP_G_TO_G;
  constants["PIXEL_MAP_B_TO_B"] = GL_PIXEL_MAP_B_TO_B;
  constants["PIXEL_MAP_A_TO_A"] = GL_PIXEL_MAP_A_TO_A;
  constants["COLOR_INDEX"] = GL_COLOR_INDEX;
  constants["STENCIL_INDEX"] = GL_STENCIL_INDEX;
  constants["DEPTH_COMPONENT"] = GL_DEPTH_COMPONENT;
  constants["RED"] = GL_RED;
  constants["GREEN"] = GL_GREEN;
  constants["BLUE"] = GL_BLUE;
  constants["ALPHA"] = GL_ALPHA;
  constants["RGB"] = GL_RGB;
  constants["RGBA"] = GL_RGBA;
  constants["LUMINANCE"] = GL_LUMINANCE;
  constants["LUMINANCE_ALPHA"] = GL_LUMINANCE_ALPHA;
  constants["BITMAP"] = GL_BITMAP;
  constants["TEXTURE_2D"] = GL_TEXTURE_2D;
  constants["PROXY_TEXTURE_2D"] = GL_PROXY_TEXTURE_2D;
  constants["ACCUM"] = GL_ACCUM;
  constants["LOAD"] = GL_LOAD;
  constants["RETURN"] = GL_RETURN;
  constants["MULT"] = GL_MULT;
  constants["ADD"] = GL_ADD;
  constants["NEVER"] = GL_NEVER;
  constants["LESS"] = GL_LESS;
  constants["EQUAL"] = GL_EQUAL;
  constants["LEQUAL"] = GL_LEQUAL;
  constants["GREATER"] = GL_GREATER;
  constants["NOTEQUAL"] = GL_NOTEQUAL;
  constants["GEQUAL"] = GL_GEQUAL;
  constants["ALWAYS"] = GL_ALWAYS;
  constants["CURRENT_BIT"] = GL_CURRENT_BIT;
  constants["POINT_BIT"] = GL_POINT_BIT;
  constants["LINE_BIT"] = GL_LINE_BIT;
  constants["POLYGON_BIT"] = GL_POLYGON_BIT;
  constants["POLYGON_STIPPLE_BIT"] = GL_POLYGON_STIPPLE_BIT;
  constants["PIXEL_MODE_BIT"] = GL_PIXEL_MODE_BIT;
  constants["LIGHTING_BIT"] = GL_LIGHTING_BIT;
  constants["FOG_BIT"] = GL_FOG_BIT;
  constants["DEPTH_BUFFER_BIT"] = GL_DEPTH_BUFFER_BIT;
  constants["ACCUM_BUFFER_BIT"] = GL_ACCUM_BUFFER_BIT;
  constants["STENCIL_BUFFER_BIT"] = GL_STENCIL_BUFFER_BIT;
  constants["VIEWPORT_BIT"] = GL_VIEWPORT_BIT;
  constants["TRANSFORM_BIT"] = GL_TRANSFORM_BIT;
  constants["ENABLE_BIT"] = GL_ENABLE_BIT;
  constants["COLOR_BUFFER_BIT"] = GL_COLOR_BUFFER_BIT;
  constants["HINT_BIT"] = GL_HINT_BIT;
  constants["EVAL_BIT"] = GL_EVAL_BIT;
  constants["LIST_BIT"] = GL_LIST_BIT;
  constants["TEXTURE_BIT"] = GL_TEXTURE_BIT;
  constants["SCISSOR_BIT"] = GL_SCISSOR_BIT;
  constants["ALL_ATTRIB_BITS"] = GL_ALL_ATTRIB_BITS;
  constants["ZERO"] = GL_ZERO;
  constants["ONE"] = GL_ONE;
  constants["SRC_COLOR"] = GL_SRC_COLOR;
  constants["ONE_MINUS_SRC_COLOR"] = GL_ONE_MINUS_SRC_COLOR;
  constants["SRC_ALPHA"] = GL_SRC_ALPHA;
  constants["ONE_MINUS_SRC_ALPHA"] = GL_ONE_MINUS_SRC_ALPHA;
  constants["DST_ALPHA"] = GL_DST_ALPHA;
  constants["ONE_MINUS_DST_ALPHA"] = GL_ONE_MINUS_DST_ALPHA;
  constants["DST_COLOR"] = GL_DST_COLOR;
  constants["ONE_MINUS_DST_COLOR"] = GL_ONE_MINUS_DST_COLOR;
  constants["SRC_ALPHA_SATURATE"] = GL_SRC_ALPHA_SATURATE;
  constants["NONE"] = GL_NONE;
  constants["FRONT_LEFT"] = GL_FRONT_LEFT;
  constants["FRONT_RIGHT"] = GL_FRONT_RIGHT;
  constants["BACK_LEFT"] = GL_BACK_LEFT;
  constants["BACK_RIGHT"] = GL_BACK_RIGHT;
  constants["LEFT"] = GL_LEFT;
  constants["RIGHT"] = GL_RIGHT;
  constants["AUX0"] = GL_AUX0;
  constants["AUX1"] = GL_AUX1;
  constants["AUX2"] = GL_AUX2;
  constants["AUX3"] = GL_AUX3;
  constants["_2D"] = GL_2D;
  constants["_3D"] = GL_3D;
  constants["_3D_COLOR"] = GL_3D_COLOR;
  constants["_3D_COLOR_TEXTURE"] = GL_3D_COLOR_TEXTURE;
  constants["_4D_COLOR_TEXTURE"] = GL_4D_COLOR_TEXTURE;
  constants["PASS_THROUGH_TOKEN"] = GL_PASS_THROUGH_TOKEN;
  constants["POINT_TOKEN"] = GL_POINT_TOKEN;
  constants["LINE_TOKEN"] = GL_LINE_TOKEN;
  constants["POLYGON_TOKEN"] = GL_POLYGON_TOKEN;
  constants["BITMAP_TOKEN"] = GL_BITMAP_TOKEN;
  constants["DRAW_PIXEL_TOKEN"] = GL_DRAW_PIXEL_TOKEN;
  constants["COPY_PIXEL_TOKEN"] = GL_COPY_PIXEL_TOKEN;
  constants["LINE_RESET_TOKEN"] = GL_LINE_RESET_TOKEN;
  constants["EXP"] = GL_EXP;
  constants["EXP2"] = GL_EXP2;
  constants["COEFF"] = GL_COEFF;
  constants["ORDER"] = GL_ORDER;
  constants["DOMAIN"] = GL_DOMAIN;
  constants["CURRENT_COLOR"] = GL_CURRENT_COLOR;
  constants["CURRENT_INDEX"] = GL_CURRENT_INDEX;
  constants["CURRENT_NORMAL"] = GL_CURRENT_NORMAL;
  constants["CURRENT_TEXTURE_COORDS"] = GL_CURRENT_TEXTURE_COORDS;
  constants["CURRENT_RASTER_COLOR"] = GL_CURRENT_RASTER_COLOR;
  constants["CURRENT_RASTER_INDEX"] = GL_CURRENT_RASTER_INDEX;
  constants["CURRENT_RASTER_TEXTURE_COORDS"] = GL_CURRENT_RASTER_TEXTURE_COORDS;
  constants["CURRENT_RASTER_POSITION"] = GL_CURRENT_RASTER_POSITION;
  constants["CURRENT_RASTER_POSITION_VALID"] = GL_CURRENT_RASTER_POSITION_VALID;
  constants["CURRENT_RASTER_DISTANCE"] = GL_CURRENT_RASTER_DISTANCE;
  constants["POINT_SIZE"] = GL_POINT_SIZE;
  constants["POINT_SIZE_RANGE"] = GL_POINT_SIZE_RANGE;
  constants["POINT_SIZE_GRANULARITY"] = GL_POINT_SIZE_GRANULARITY;
  constants["LINE_WIDTH"] = GL_LINE_WIDTH;
  constants["LINE_WIDTH_RANGE"] = GL_LINE_WIDTH_RANGE;
  constants["LINE_WIDTH_GRANULARITY"] = GL_LINE_WIDTH_GRANULARITY;
  constants["LINE_STIPPLE_PATTERN"] = GL_LINE_STIPPLE_PATTERN;
  constants["LINE_STIPPLE_REPEAT"] = GL_LINE_STIPPLE_REPEAT;
  constants["LIST_MODE"] = GL_LIST_MODE;
  constants["MAX_LIST_NESTING"] = GL_MAX_LIST_NESTING;
  constants["LIST_BASE"] = GL_LIST_BASE;
  constants["LIST_INDEX"] = GL_LIST_INDEX;
  constants["POLYGON_MODE"] = GL_POLYGON_MODE;
  constants["EDGE_FLAG"] = GL_EDGE_FLAG;
  constants["CULL_FACE"] = GL_CULL_FACE;
  constants["CULL_FACE_MODE"] = GL_CULL_FACE_MODE;
  constants["FRONT_FACE"] = GL_FRONT_FACE;
  constants["SHADE_MODEL"] = GL_SHADE_MODEL;
  constants["COLOR_MATERIAL_FACE"] = GL_COLOR_MATERIAL_FACE;
  constants["COLOR_MATERIAL_PARAMETER"] = GL_COLOR_MATERIAL_PARAMETER;
  constants["FOG"] = GL_FOG;
  constants["FOG_INDEX"] = GL_FOG_INDEX;
  constants["FOG_DENSITY"] = GL_FOG_DENSITY;
  constants["FOG_START"] = GL_FOG_START;
  constants["FOG_END"] = GL_FOG_END;
  constants["FOG_MODE"] = GL_FOG_MODE;
  constants["FOG_COLOR"] = GL_FOG_COLOR;
  constants["DEPTH_RANGE"] = GL_DEPTH_RANGE;
  constants["DEPTH_TEST"] = GL_DEPTH_TEST;
  constants["DEPTH_WRITEMASK"] = GL_DEPTH_WRITEMASK;
  constants["DEPTH_CLEAR_VALUE"] = GL_DEPTH_CLEAR_VALUE;
  constants["DEPTH_FUNC"] = GL_DEPTH_FUNC;
  constants["ACCUM_CLEAR_VALUE"] = GL_ACCUM_CLEAR_VALUE;
  constants["STENCIL_TEST"] = GL_STENCIL_TEST;
  constants["STENCIL_CLEAR_VALUE"] = GL_STENCIL_CLEAR_VALUE;
  constants["STENCIL_FUNC"] = GL_STENCIL_FUNC;
  constants["STENCIL_VALUE_MASK"] = GL_STENCIL_VALUE_MASK;
  constants["STENCIL_FAIL"] = GL_STENCIL_FAIL;
  constants["STENCIL_PASS_DEPTH_FAIL"] = GL_STENCIL_PASS_DEPTH_FAIL;
  constants["STENCIL_PASS_DEPTH_PASS"] = GL_STENCIL_PASS_DEPTH_PASS;
  constants["STENCIL_REF"] = GL_STENCIL_REF;
  constants["STENCIL_WRITEMASK"] = GL_STENCIL_WRITEMASK;
  constants["MATRIX_MODE"] = GL_MATRIX_MODE;
  constants["VIEWPORT"] = GL_VIEWPORT;
  constants["MODELVIEW_STACK_DEPTH"] = GL_MODELVIEW_STACK_DEPTH;
  constants["PROJECTION_STACK_DEPTH"] = GL_PROJECTION_STACK_DEPTH;
  constants["TEXTURE_STACK_DEPTH"] = GL_TEXTURE_STACK_DEPTH;
  constants["MODELVIEW_MATRIX"] = GL_MODELVIEW_MATRIX;
  constants["PROJECTION_MATRIX"] = GL_PROJECTION_MATRIX;
  constants["TEXTURE_MATRIX"] = GL_TEXTURE_MATRIX;
  constants["ATTRIB_STACK_DEPTH"] = GL_ATTRIB_STACK_DEPTH;
  constants["CLIENT_ATTRIB_STACK_DEPTH"] = GL_CLIENT_ATTRIB_STACK_DEPTH;
  constants["ALPHA_TEST"] = GL_ALPHA_TEST;
  constants["ALPHA_TEST_FUNC"] = GL_ALPHA_TEST_FUNC;
  constants["ALPHA_TEST_REF"] = GL_ALPHA_TEST_REF;
  constants["DITHER"] = GL_DITHER;
  constants["BLEND_DST"] = GL_BLEND_DST;
  constants["BLEND_SRC"] = GL_BLEND_SRC;
  constants["BLEND"] = GL_BLEND;
  constants["LOGIC_OP_MODE"] = GL_LOGIC_OP_MODE;
  constants["INDEX_LOGIC_OP"] = GL_INDEX_LOGIC_OP;
  constants["COLOR_LOGIC_OP"] = GL_COLOR_LOGIC_OP;
  constants["AUX_BUFFERS"] = GL_AUX_BUFFERS;
  constants["DRAW_BUFFER"] = GL_DRAW_BUFFER;
  constants["READ_BUFFER"] = GL_READ_BUFFER;
  constants["SCISSOR_BOX"] = GL_SCISSOR_BOX;
  constants["SCISSOR_TEST"] = GL_SCISSOR_TEST;
  constants["INDEX_CLEAR_VALUE"] = GL_INDEX_CLEAR_VALUE;
  constants["INDEX_WRITEMASK"] = GL_INDEX_WRITEMASK;
  constants["COLOR_CLEAR_VALUE"] = GL_COLOR_CLEAR_VALUE;
  constants["COLOR_WRITEMASK"] = GL_COLOR_WRITEMASK;
  constants["INDEX_MODE"] = GL_INDEX_MODE;
  constants["RGBA_MODE"] = GL_RGBA_MODE;
  constants["DOUBLEBUFFER"] = GL_DOUBLEBUFFER;
  constants["STEREO"] = GL_STEREO;
  constants["RENDER_MODE"] = GL_RENDER_MODE;
  constants["PERSPECTIVE_CORRECTION_HINT"] = GL_PERSPECTIVE_CORRECTION_HINT;
  constants["POINT_SMOOTH_HINT"] = GL_POINT_SMOOTH_HINT;
  constants["LINE_SMOOTH_HINT"] = GL_LINE_SMOOTH_HINT;
  constants["POLYGON_SMOOTH_HINT"] = GL_POLYGON_SMOOTH_HINT;
  constants["FOG_HINT"] = GL_FOG_HINT;
  constants["PIXEL_MAP_I_TO_I_SIZE"] = GL_PIXEL_MAP_I_TO_I_SIZE;
  constants["PIXEL_MAP_S_TO_S_SIZE"] = GL_PIXEL_MAP_S_TO_S_SIZE;
  constants["PIXEL_MAP_I_TO_R_SIZE"] = GL_PIXEL_MAP_I_TO_R_SIZE;
  constants["PIXEL_MAP_I_TO_G_SIZE"] = GL_PIXEL_MAP_I_TO_G_SIZE;
  constants["PIXEL_MAP_I_TO_B_SIZE"] = GL_PIXEL_MAP_I_TO_B_SIZE;
  constants["PIXEL_MAP_I_TO_A_SIZE"] = GL_PIXEL_MAP_I_TO_A_SIZE;
  constants["PIXEL_MAP_R_TO_R_SIZE"] = GL_PIXEL_MAP_R_TO_R_SIZE;
  constants["PIXEL_MAP_G_TO_G_SIZE"] = GL_PIXEL_MAP_G_TO_G_SIZE;
  constants["PIXEL_MAP_B_TO_B_SIZE"] = GL_PIXEL_MAP_B_TO_B_SIZE;
  constants["PIXEL_MAP_A_TO_A_SIZE"] = GL_PIXEL_MAP_A_TO_A_SIZE;
  constants["PACK_SWAP_BYTES"] = GL_PACK_SWAP_BYTES;
  constants["PACK_LSB_FIRST"] = GL_PACK_LSB_FIRST;
  constants["PACK_ROW_LENGTH"] = GL_PACK_ROW_LENGTH;
  constants["PACK_SKIP_ROWS"] = GL_PACK_SKIP_ROWS;
  constants["PACK_SKIP_PIXELS"] = GL_PACK_SKIP_PIXELS;
  constants["PACK_ALIGNMENT"] = GL_PACK_ALIGNMENT;
  constants["ZOOM_X"] = GL_ZOOM_X;
  constants["ZOOM_Y"] = GL_ZOOM_Y;
  constants["MAX_EVAL_ORDER"] = GL_MAX_EVAL_ORDER;
  constants["MAX_LIGHTS"] = GL_MAX_LIGHTS;
  constants["MAX_CLIP_PLANES"] = GL_MAX_CLIP_PLANES;
  constants["MAX_TEXTURE_SIZE"] = GL_MAX_TEXTURE_SIZE;
  constants["MAX_PIXEL_MAP_TABLE"] = GL_MAX_PIXEL_MAP_TABLE;
  constants["MAX_ATTRIB_STACK_DEPTH"] = GL_MAX_ATTRIB_STACK_DEPTH;
  constants["MAX_MODELVIEW_STACK_DEPTH"] = GL_MAX_MODELVIEW_STACK_DEPTH;
  constants["MAX_NAME_STACK_DEPTH"] = GL_MAX_NAME_STACK_DEPTH;
  constants["MAX_PROJECTION_STACK_DEPTH"] = GL_MAX_PROJECTION_STACK_DEPTH;
  constants["MAX_TEXTURE_STACK_DEPTH"] = GL_MAX_TEXTURE_STACK_DEPTH;
  constants["MAX_VIEWPORT_DIMS"] = GL_MAX_VIEWPORT_DIMS;
  constants["MAX_CLIENT_ATTRIB_STACK_DEPTH"] = GL_MAX_CLIENT_ATTRIB_STACK_DEPTH;
  constants["SUBPIXEL_BITS"] = GL_SUBPIXEL_BITS;
  constants["INDEX_BITS"] = GL_INDEX_BITS;
  constants["RED_BITS"] = GL_RED_BITS;
  constants["GREEN_BITS"] = GL_GREEN_BITS;
  constants["BLUE_BITS"] = GL_BLUE_BITS;
  constants["ALPHA_BITS"] = GL_ALPHA_BITS;
  constants["DEPTH_BITS"] = GL_DEPTH_BITS;
  constants["STENCIL_BITS"] = GL_STENCIL_BITS;
  constants["ACCUM_RED_BITS"] = GL_ACCUM_RED_BITS;
  constants["ACCUM_GREEN_BITS"] = GL_ACCUM_GREEN_BITS;
  constants["ACCUM_BLUE_BITS"] = GL_ACCUM_BLUE_BITS;
  constants["ACCUM_ALPHA_BITS"] = GL_ACCUM_ALPHA_BITS;
  constants["NAME_STACK_DEPTH"] = GL_NAME_STACK_DEPTH;
  constants["AUTO_NORMAL"] = GL_AUTO_NORMAL;
  constants["MAP1_COLOR_4"] = GL_MAP1_COLOR_4;
  constants["MAP1_INDEX"] = GL_MAP1_INDEX;
  constants["MAP1_NORMAL"] = GL_MAP1_NORMAL;
  constants["MAP1_TEXTURE_COORD_1"] = GL_MAP1_TEXTURE_COORD_1;
  constants["MAP1_TEXTURE_COORD_2"] = GL_MAP1_TEXTURE_COORD_2;
  constants["MAP1_TEXTURE_COORD_3"] = GL_MAP1_TEXTURE_COORD_3;
  constants["MAP1_TEXTURE_COORD_4"] = GL_MAP1_TEXTURE_COORD_4;
  constants["MAP1_VERTEX_3"] = GL_MAP1_VERTEX_3;
  constants["MAP1_VERTEX_4"] = GL_MAP1_VERTEX_4;
  constants["MAP2_COLOR_4"] = GL_MAP2_COLOR_4;
  constants["MAP2_INDEX"] = GL_MAP2_INDEX;
  constants["MAP2_NORMAL"] = GL_MAP2_NORMAL;
  constants["MAP2_TEXTURE_COORD_1"] = GL_MAP2_TEXTURE_COORD_1;
  constants["MAP2_TEXTURE_COORD_2"] = GL_MAP2_TEXTURE_COORD_2;
  constants["MAP2_TEXTURE_COORD_3"] = GL_MAP2_TEXTURE_COORD_3;
  constants["MAP2_TEXTURE_COORD_4"] = GL_MAP2_TEXTURE_COORD_4;
  constants["MAP2_VERTEX_3"] = GL_MAP2_VERTEX_3;
  constants["MAP2_VERTEX_4"] = GL_MAP2_VERTEX_4;
  constants["MAP1_GRID_DOMAIN"] = GL_MAP1_GRID_DOMAIN;
  constants["MAP1_GRID_SEGMENTS"] = GL_MAP1_GRID_SEGMENTS;
  constants["MAP2_GRID_DOMAIN"] = GL_MAP2_GRID_DOMAIN;
  constants["MAP2_GRID_SEGMENTS"] = GL_MAP2_GRID_SEGMENTS;
  constants["TEXTURE_1D"] = GL_TEXTURE_1D;
  constants["FEEDBACK_BUFFER_POINTER"] = GL_FEEDBACK_BUFFER_POINTER;
  constants["FEEDBACK_BUFFER_SIZE"] = GL_FEEDBACK_BUFFER_SIZE;
  constants["FEEDBACK_BUFFER_TYPE"] = GL_FEEDBACK_BUFFER_TYPE;
  constants["SELECTION_BUFFER_POINTER"] = GL_SELECTION_BUFFER_POINTER;
  constants["SELECTION_BUFFER_SIZE"] = GL_SELECTION_BUFFER_SIZE;
  constants["TEXTURE_WIDTH"] = GL_TEXTURE_WIDTH;
  constants["TEXTURE_HEIGHT"] = GL_TEXTURE_HEIGHT;
  constants["TEXTURE_INTERNAL_FORMAT"] = GL_TEXTURE_INTERNAL_FORMAT;
  constants["TEXTURE_BORDER_COLOR"] = GL_TEXTURE_BORDER_COLOR;
  constants["TEXTURE_BORDER"] = GL_TEXTURE_BORDER;
  constants["DONT_CARE"] = GL_DONT_CARE;
  constants["FASTEST"] = GL_FASTEST;
  constants["NICEST"] = GL_NICEST;
  constants["COMPILE"] = GL_COMPILE;
  constants["COMPILE_AND_EXECUTE"] = GL_COMPILE_AND_EXECUTE;
  constants["CLEAR"] = GL_CLEAR;
  constants["AND"] = GL_AND;
  constants["AND_REVERSE"] = GL_AND_REVERSE;
  constants["COPY"] = GL_COPY;
  constants["AND_INVERTED"] = GL_AND_INVERTED;
  constants["NOOP"] = GL_NOOP;
  constants["XOR"] = GL_XOR;
  constants["OR"] = GL_OR;
  constants["NOR"] = GL_NOR;
  constants["EQUIV"] = GL_EQUIV;
  constants["INVERT"] = GL_INVERT;
  constants["OR_REVERSE"] = GL_OR_REVERSE;
  constants["COPY_INVERTED"] = GL_COPY_INVERTED;
  constants["OR_INVERTED"] = GL_OR_INVERTED;
  constants["NAND"] = GL_NAND;
  constants["SET"] = GL_SET;
  constants["COLOR"] = GL_COLOR;
  constants["DEPTH"] = GL_DEPTH;
  constants["STENCIL"] = GL_STENCIL;
  constants["RENDER"] = GL_RENDER;
  constants["FEEDBACK"] = GL_FEEDBACK;
  constants["SELECT"] = GL_SELECT;
  constants["KEEP"] = GL_KEEP;
  constants["REPLACE"] = GL_REPLACE;
  constants["INCR"] = GL_INCR;
  constants["DECR"] = GL_DECR;
  constants["VENDOR"] = GL_VENDOR;
  constants["RENDERER"] = GL_RENDERER;
  constants["VERSION"] = GL_VERSION;
  constants["EXTENSIONS"] = GL_EXTENSIONS;
  constants["S"] = GL_S;
  constants["T"] = GL_T;
  constants["R"] = GL_R;
  constants["Q"] = GL_Q;
  constants["MODULATE"] = GL_MODULATE;
  constants["DECAL"] = GL_DECAL;
  constants["TEXTURE_ENV_MODE"] = GL_TEXTURE_ENV_MODE;
  constants["TEXTURE_ENV_COLOR"] = GL_TEXTURE_ENV_COLOR;
  constants["TEXTURE_ENV"] = GL_TEXTURE_ENV;
  constants["NEAREST"] = GL_NEAREST;
  constants["LINEAR"] = GL_LINEAR;
  constants["NEAREST_MIPMAP_NEAREST"] = GL_NEAREST_MIPMAP_NEAREST;
  constants["LINEAR_MIPMAP_NEAREST"] = GL_LINEAR_MIPMAP_NEAREST;
  constants["NEAREST_MIPMAP_LINEAR"] = GL_NEAREST_MIPMAP_LINEAR;
  constants["LINEAR_MIPMAP_LINEAR"] = GL_LINEAR_MIPMAP_LINEAR;
  constants["TEXTURE_MAG_FILTER"] = GL_TEXTURE_MAG_FILTER;
  constants["TEXTURE_MIN_FILTER"] = GL_TEXTURE_MIN_FILTER;
  constants["TEXTURE_WRAP_S"] = GL_TEXTURE_WRAP_S;
  constants["TEXTURE_WRAP_T"] = GL_TEXTURE_WRAP_T;
  constants["CLAMP"] = GL_CLAMP;
  constants["REPEAT"] = GL_REPEAT;
  constants["CLIENT_PIXEL_STORE_BIT"] = GL_CLIENT_PIXEL_STORE_BIT;
  constants["CLIENT_VERTEX_ARRAY_BIT"] = GL_CLIENT_VERTEX_ARRAY_BIT;
  constants["CLIENT_ALL_ATTRIB_BITS"] = GL_CLIENT_ALL_ATTRIB_BITS;
  constants["POLYGON_OFFSET_FACTOR"] = GL_POLYGON_OFFSET_FACTOR;
  constants["POLYGON_OFFSET_UNITS"] = GL_POLYGON_OFFSET_UNITS;
  constants["ALPHA4"] = GL_ALPHA4;
  constants["ALPHA8"] = GL_ALPHA8;
  constants["ALPHA12"] = GL_ALPHA12;
  constants["ALPHA16"] = GL_ALPHA16;
  constants["LUMINANCE4"] = GL_LUMINANCE4;
  constants["LUMINANCE8"] = GL_LUMINANCE8;
  constants["LUMINANCE12"] = GL_LUMINANCE12;
  constants["LUMINANCE16"] = GL_LUMINANCE16;
  constants["LUMINANCE4_ALPHA4"] = GL_LUMINANCE4_ALPHA4;
  constants["LUMINANCE6_ALPHA2"] = GL_LUMINANCE6_ALPHA2;
  constants["LUMINANCE8_ALPHA8"] = GL_LUMINANCE8_ALPHA8;
  constants["LUMINANCE12_ALPHA4"] = GL_LUMINANCE12_ALPHA4;
  constants["LUMINANCE12_ALPHA12"] = GL_LUMINANCE12_ALPHA12;
  constants["LUMINANCE16_ALPHA16"] = GL_LUMINANCE16_ALPHA16;
  constants["INTENSITY"] = GL_INTENSITY;
  constants["INTENSITY4"] = GL_INTENSITY4;
  constants["INTENSITY8"] = GL_INTENSITY8;
  constants["INTENSITY12"] = GL_INTENSITY12;
  constants["INTENSITY16"] = GL_INTENSITY16;
  constants["R3_G3_B2"] = GL_R3_G3_B2;
  constants["RGB4"] = GL_RGB4;
  constants["RGB5"] = GL_RGB5;
  constants["RGB8"] = GL_RGB8;
  constants["RGB10"] = GL_RGB10;
  constants["RGB12"] = GL_RGB12;
  constants["RGB16"] = GL_RGB16;
  constants["RGBA2"] = GL_RGBA2;
  constants["RGBA4"] = GL_RGBA4;
  constants["RGB5_A1"] = GL_RGB5_A1;
  constants["RGBA8"] = GL_RGBA8;
  constants["RGB10_A2"] = GL_RGB10_A2;
  constants["RGBA12"] = GL_RGBA12;
  constants["RGBA16"] = GL_RGBA16;
  constants["TEXTURE_RED_SIZE"] = GL_TEXTURE_RED_SIZE;
  constants["TEXTURE_GREEN_SIZE"] = GL_TEXTURE_GREEN_SIZE;
  constants["TEXTURE_BLUE_SIZE"] = GL_TEXTURE_BLUE_SIZE;
  constants["TEXTURE_ALPHA_SIZE"] = GL_TEXTURE_ALPHA_SIZE;
  constants["TEXTURE_LUMINANCE_SIZE"] = GL_TEXTURE_LUMINANCE_SIZE;
  constants["TEXTURE_INTENSITY_SIZE"] = GL_TEXTURE_INTENSITY_SIZE;
  constants["PROXY_TEXTURE_1D"] = GL_PROXY_TEXTURE_1D;
  constants["TEXTURE_PRIORITY"] = GL_TEXTURE_PRIORITY;
  constants["TEXTURE_RESIDENT"] = GL_TEXTURE_RESIDENT;
  constants["TEXTURE_BINDING_1D"] = GL_TEXTURE_BINDING_1D;
  constants["TEXTURE_BINDING_2D"] = GL_TEXTURE_BINDING_2D;
  constants["VERTEX_ARRAY_SIZE"] = GL_VERTEX_ARRAY_SIZE;
  constants["VERTEX_ARRAY_TYPE"] = GL_VERTEX_ARRAY_TYPE;
  constants["VERTEX_ARRAY_STRIDE"] = GL_VERTEX_ARRAY_STRIDE;
  constants["NORMAL_ARRAY_TYPE"] = GL_NORMAL_ARRAY_TYPE;
  constants["NORMAL_ARRAY_STRIDE"] = GL_NORMAL_ARRAY_STRIDE;
  constants["COLOR_ARRAY_SIZE"] = GL_COLOR_ARRAY_SIZE;
  constants["COLOR_ARRAY_TYPE"] = GL_COLOR_ARRAY_TYPE;
  constants["COLOR_ARRAY_STRIDE"] = GL_COLOR_ARRAY_STRIDE;
  constants["INDEX_ARRAY_TYPE"] = GL_INDEX_ARRAY_TYPE;
  constants["INDEX_ARRAY_STRIDE"] = GL_INDEX_ARRAY_STRIDE;
  constants["TEXTURE_COORD_ARRAY_SIZE"] = GL_TEXTURE_COORD_ARRAY_SIZE;
  constants["TEXTURE_COORD_ARRAY_TYPE"] = GL_TEXTURE_COORD_ARRAY_TYPE;
  constants["TEXTURE_COORD_ARRAY_STRIDE"] = GL_TEXTURE_COORD_ARRAY_STRIDE;
  constants["EDGE_FLAG_ARRAY_STRIDE"] = GL_EDGE_FLAG_ARRAY_STRIDE;
  constants["VERTEX_ARRAY_POINTER"] = GL_VERTEX_ARRAY_POINTER;
  constants["NORMAL_ARRAY_POINTER"] = GL_NORMAL_ARRAY_POINTER;
  constants["COLOR_ARRAY_POINTER"] = GL_COLOR_ARRAY_POINTER;
  constants["INDEX_ARRAY_POINTER"] = GL_INDEX_ARRAY_POINTER;
  constants["TEXTURE_COORD_ARRAY_POINTER"] = GL_TEXTURE_COORD_ARRAY_POINTER;
  constants["EDGE_FLAG_ARRAY_POINTER"] = GL_EDGE_FLAG_ARRAY_POINTER;
  constants["LOGIC_OP"] = GL_LOGIC_OP;
  constants["TEXTURE_COMPONENTS"] = GL_TEXTURE_COMPONENTS;

  //constants["COLOR_INDEX1_EXT"] = GL_COLOR_INDEX1_EXT;
  //constants["COLOR_INDEX2_EXT"] = GL_COLOR_INDEX2_EXT;
  //constants["COLOR_INDEX4_EXT"] = GL_COLOR_INDEX4_EXT;
  //constants["COLOR_INDEX8_EXT"] = GL_COLOR_INDEX8_EXT;
  //constants["COLOR_INDEX12_EXT"] = GL_COLOR_INDEX12_EXT;
  //constants["COLOR_INDEX16_EXT"] = GL_COLOR_INDEX16_EXT;
  //constants["_2_BYTES"] = GL_2_BYTES;
  //constants["_3_BYTES"] = GL_3_BYTES;
  //constants["_4_BYTES"] = GL_4_BYTES;

  LuaGL &gl = LuaGL::Instance();

  gl.addParamDim(LuaGL::Booleanv, GL_COLOR_WRITEMASK, 4);
  gl.addParamDim(LuaGL::Booleanv, GL_CURRENT_RASTER_POSITION_VALID, 1);
  gl.addParamDim(LuaGL::Booleanv, GL_EDGE_FLAG, 1);
  gl.addParamDim(LuaGL::Booleanv, GL_LIGHT_MODEL_LOCAL_VIEWER, 1);
  gl.addParamDim(LuaGL::Booleanv, GL_LIGHT_MODEL_TWO_SIDE, 1);
  gl.addParamDim(LuaGL::Booleanv, GL_DEPTH_WRITEMASK, 1);
  gl.addParamDim(LuaGL::Booleanv, GL_UNPACK_SWAP_BYTES, 1);
  gl.addParamDim(LuaGL::Booleanv, GL_UNPACK_LSB_FIRST, 1);
  gl.addParamDim(LuaGL::Booleanv, GL_PACK_SWAP_BYTES, 1);
  gl.addParamDim(LuaGL::Booleanv, GL_PACK_LSB_FIRST, 1);
  gl.addParamDim(LuaGL::Booleanv, GL_MAP_COLOR, 1);
  gl.addParamDim(LuaGL::Booleanv, GL_MAP_STENCIL, 1);
  gl.addParamDim(LuaGL::Booleanv, GL_RGBA_MODE, 1);
  gl.addParamDim(LuaGL::Booleanv, GL_INDEX_MODE, 1);
  gl.addParamDim(LuaGL::Booleanv, GL_DOUBLEBUFFER, 1);
  gl.addParamDim(LuaGL::Booleanv, GL_STEREO, 1);
  gl.addParamDim(LuaGL::Integerv, GL_CURRENT_COLOR, 4);
  gl.addParamDim(LuaGL::Integerv, GL_CURRENT_RASTER_COLOR, 4);
  gl.addParamDim(LuaGL::Integerv, GL_VIEWPORT, 4);
  gl.addParamDim(LuaGL::Integerv, GL_SCISSOR_BOX, 4);
  gl.addParamDim(LuaGL::Integerv, GL_MAX_VIEWPORT_DIMS, 2);
  gl.addParamDim(LuaGL::Integerv, GL_CURRENT_INDEX, 1);
  gl.addParamDim(LuaGL::Integerv, GL_CURRENT_RASTER_INDEX, 1);
  gl.addParamDim(LuaGL::Integerv, GL_VERTEX_ARRAY_SIZE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_VERTEX_ARRAY_TYPE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_VERTEX_ARRAY_STRIDE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_NORMAL_ARRAY_TYPE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_NORMAL_ARRAY_STRIDE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_COLOR_ARRAY_SIZE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_COLOR_ARRAY_TYPE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_COLOR_ARRAY_STRIDE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_INDEX_ARRAY_TYPE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_INDEX_ARRAY_STRIDE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_TEXTURE_COORD_ARRAY_SIZE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_TEXTURE_COORD_ARRAY_TYPE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_TEXTURE_COORD_ARRAY_STRIDE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_EDGE_FLAG_ARRAY_STRIDE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_MODELVIEW_STACK_DEPTH, 1);
  gl.addParamDim(LuaGL::Integerv, GL_PROJECTION_STACK_DEPTH, 1);
  gl.addParamDim(LuaGL::Integerv, GL_TEXTURE_STACK_DEPTH, 1);
  gl.addParamDim(LuaGL::Integerv, GL_MATRIX_MODE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_FOG_MODE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_SHADE_MODEL, 1);
  gl.addParamDim(LuaGL::Integerv, GL_COLOR_MATERIAL_PARAMETER, 1);
  gl.addParamDim(LuaGL::Integerv, GL_COLOR_MATERIAL_FACE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_LINE_STIPPLE_PATTERN, 1);
  gl.addParamDim(LuaGL::Integerv, GL_LINE_STIPPLE_REPEAT, 1);
  gl.addParamDim(LuaGL::Integerv, GL_CULL_FACE_MODE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_FRONT_FACE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_POLYGON_MODE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_TEXTURE_BINDING_1D, 1);
  gl.addParamDim(LuaGL::Integerv, GL_TEXTURE_BINDING_2D, 1);
  gl.addParamDim(LuaGL::Integerv, GL_ALPHA_TEST_FUNC, 1);
  gl.addParamDim(LuaGL::Integerv, GL_ALPHA_TEST_REF, 1);
  gl.addParamDim(LuaGL::Integerv, GL_STENCIL_FUNC, 1);
  gl.addParamDim(LuaGL::Integerv, GL_STENCIL_VALUE_MASK, 1);
  gl.addParamDim(LuaGL::Integerv, GL_STENCIL_REF, 1);
  gl.addParamDim(LuaGL::Integerv, GL_STENCIL_FAIL, 1);
  gl.addParamDim(LuaGL::Integerv, GL_STENCIL_PASS_DEPTH_FAIL, 1);
  gl.addParamDim(LuaGL::Integerv, GL_STENCIL_PASS_DEPTH_PASS, 1);
  gl.addParamDim(LuaGL::Integerv, GL_DEPTH_FUNC, 1);
  gl.addParamDim(LuaGL::Integerv, GL_BLEND_SRC, 1);
  gl.addParamDim(LuaGL::Integerv, GL_BLEND_DST, 1);
  gl.addParamDim(LuaGL::Integerv, GL_LOGIC_OP_MODE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_DRAW_BUFFER, 1);
  gl.addParamDim(LuaGL::Integerv, GL_INDEX_WRITEMASK, 1);
  gl.addParamDim(LuaGL::Integerv, GL_STENCIL_WRITEMASK, 1);
  gl.addParamDim(LuaGL::Integerv, GL_DEPTH_CLEAR_VALUE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_STENCIL_CLEAR_VALUE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_UNPACK_ROW_LENGTH, 1);
  gl.addParamDim(LuaGL::Integerv, GL_UNPACK_SKIP_ROWS, 1);
  gl.addParamDim(LuaGL::Integerv, GL_UNPACK_SKIP_PIXELS, 1);
  gl.addParamDim(LuaGL::Integerv, GL_UNPACK_ALIGNMENT, 1);
  gl.addParamDim(LuaGL::Integerv, GL_PACK_ROW_LENGTH, 1);
  gl.addParamDim(LuaGL::Integerv, GL_PACK_SKIP_ROWS, 1);
  gl.addParamDim(LuaGL::Integerv, GL_PACK_SKIP_PIXELS, 1);
  gl.addParamDim(LuaGL::Integerv, GL_PACK_ALIGNMENT, 1);
  gl.addParamDim(LuaGL::Integerv, GL_INDEX_SHIFT, 1);
  gl.addParamDim(LuaGL::Integerv, GL_INDEX_OFFSET, 1);
  gl.addParamDim(LuaGL::Integerv, GL_PIXEL_MAP_A_TO_A_SIZE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_PIXEL_MAP_B_TO_B_SIZE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_PIXEL_MAP_G_TO_G_SIZE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_PIXEL_MAP_I_TO_A_SIZE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_PIXEL_MAP_I_TO_B_SIZE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_PIXEL_MAP_I_TO_G_SIZE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_PIXEL_MAP_I_TO_I_SIZE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_PIXEL_MAP_I_TO_R_SIZE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_PIXEL_MAP_R_TO_R_SIZE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_PIXEL_MAP_S_TO_S_SIZE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_READ_BUFFER, 1);
  gl.addParamDim(LuaGL::Integerv, GL_PERSPECTIVE_CORRECTION_HINT, 1);
  gl.addParamDim(LuaGL::Integerv, GL_POINT_SMOOTH_HINT, 1);
  gl.addParamDim(LuaGL::Integerv, GL_LINE_SMOOTH_HINT, 1);
  gl.addParamDim(LuaGL::Integerv, GL_FOG_HINT, 1);
  gl.addParamDim(LuaGL::Integerv, GL_MAX_LIGHTS, 1);
  gl.addParamDim(LuaGL::Integerv, GL_MAX_CLIP_PLANES, 1);
  gl.addParamDim(LuaGL::Integerv, GL_MAX_MODELVIEW_STACK_DEPTH, 1);
  gl.addParamDim(LuaGL::Integerv, GL_MAX_PROJECTION_STACK_DEPTH, 1);
  gl.addParamDim(LuaGL::Integerv, GL_MAX_TEXTURE_STACK_DEPTH, 1);
  gl.addParamDim(LuaGL::Integerv, GL_SUBPIXEL_BITS, 1);
  gl.addParamDim(LuaGL::Integerv, GL_MAX_TEXTURE_SIZE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_MAX_PIXEL_MAP_TABLE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_MAX_NAME_STACK_DEPTH, 1);
  gl.addParamDim(LuaGL::Integerv, GL_MAX_LIST_NESTING, 1);
  gl.addParamDim(LuaGL::Integerv, GL_MAX_EVAL_ORDER, 1);
  gl.addParamDim(LuaGL::Integerv, GL_MAX_ATTRIB_STACK_DEPTH, 1);
  gl.addParamDim(LuaGL::Integerv, GL_MAX_CLIENT_ATTRIB_STACK_DEPTH, 1);
  gl.addParamDim(LuaGL::Integerv, GL_AUX_BUFFERS, 1);
  gl.addParamDim(LuaGL::Integerv, GL_RED_BITS, 1);
  gl.addParamDim(LuaGL::Integerv, GL_GREEN_BITS, 1);
  gl.addParamDim(LuaGL::Integerv, GL_BLUE_BITS, 1);
  gl.addParamDim(LuaGL::Integerv, GL_ALPHA_BITS, 1);
  gl.addParamDim(LuaGL::Integerv, GL_INDEX_BITS, 1);
  gl.addParamDim(LuaGL::Integerv, GL_DEPTH_BITS, 1);
  gl.addParamDim(LuaGL::Integerv, GL_STENCIL_BITS, 1);
  gl.addParamDim(LuaGL::Integerv, GL_ACCUM_RED_BITS, 1);
  gl.addParamDim(LuaGL::Integerv, GL_ACCUM_GREEN_BITS, 1);
  gl.addParamDim(LuaGL::Integerv, GL_ACCUM_BLUE_BITS, 1);
  gl.addParamDim(LuaGL::Integerv, GL_ACCUM_ALPHA_BITS, 1);
  gl.addParamDim(LuaGL::Integerv, GL_LIST_BASE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_LIST_INDEX, 1);
  gl.addParamDim(LuaGL::Integerv, GL_LIST_MODE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_ATTRIB_STACK_DEPTH, 1);
  gl.addParamDim(LuaGL::Integerv, GL_CLIENT_ATTRIB_STACK_DEPTH, 1);
  gl.addParamDim(LuaGL::Integerv, GL_NAME_STACK_DEPTH, 1);
  gl.addParamDim(LuaGL::Integerv, GL_RENDER_MODE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_SELECTION_BUFFER_SIZE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_FEEDBACK_BUFFER_SIZE, 1);
  gl.addParamDim(LuaGL::Integerv, GL_FEEDBACK_BUFFER_TYPE, 1);
  gl.addParamDim(LuaGL::Floatv, GL_MODELVIEW_MATRIX, 16);
  gl.addParamDim(LuaGL::Floatv, GL_PROJECTION_MATRIX, 16);
  gl.addParamDim(LuaGL::Floatv, GL_TEXTURE_MATRIX, 16);
  gl.addParamDim(LuaGL::Floatv, GL_CURRENT_COLOR, 4);
  gl.addParamDim(LuaGL::Floatv, GL_CURRENT_TEXTURE_COORDS, 4);
  gl.addParamDim(LuaGL::Floatv, GL_CURRENT_RASTER_POSITION, 4);
  gl.addParamDim(LuaGL::Floatv, GL_CURRENT_RASTER_COLOR, 4);
  gl.addParamDim(LuaGL::Floatv, GL_CURRENT_RASTER_TEXTURE_COORDS, 4);
  gl.addParamDim(LuaGL::Floatv, GL_FOG_COLOR, 4);
  gl.addParamDim(LuaGL::Floatv, GL_LIGHT_MODEL_AMBIENT, 4);
  gl.addParamDim(LuaGL::Floatv, GL_COLOR_CLEAR_VALUE, 4);
  gl.addParamDim(LuaGL::Floatv, GL_ACCUM_CLEAR_VALUE, 4);
  gl.addParamDim(LuaGL::Floatv, GL_MAP2_GRID_DOMAIN, 4);
  gl.addParamDim(LuaGL::Floatv, GL_CURRENT_NORMAL, 3);
  gl.addParamDim(LuaGL::Floatv, GL_DEPTH_RANGE, 2);
  gl.addParamDim(LuaGL::Floatv, GL_MAP1_GRID_DOMAIN, 2);
  gl.addParamDim(LuaGL::Floatv, GL_MAP2_GRID_SEGMENTS, 2);
  gl.addParamDim(LuaGL::Floatv, GL_POINT_SIZE_RANGE, 2);
  gl.addParamDim(LuaGL::Floatv, GL_LINE_WIDTH_RANGE, 2);
  gl.addParamDim(LuaGL::Floatv, GL_CURRENT_INDEX, 1);
  gl.addParamDim(LuaGL::Floatv, GL_CURRENT_RASTER_DISTANCE, 1);
  gl.addParamDim(LuaGL::Floatv, GL_CURRENT_RASTER_INDEX, 1);
  gl.addParamDim(LuaGL::Floatv, GL_FOG_INDEX, 1);
  gl.addParamDim(LuaGL::Floatv, GL_FOG_DENSITY, 1);
  gl.addParamDim(LuaGL::Floatv, GL_FOG_START, 1);
  gl.addParamDim(LuaGL::Floatv, GL_FOG_END, 1);
  gl.addParamDim(LuaGL::Floatv, GL_POINT_SIZE, 1);
  gl.addParamDim(LuaGL::Floatv, GL_LINE_WIDTH, 1);
  gl.addParamDim(LuaGL::Floatv, GL_POLYGON_OFFSET_FACTOR, 1);
  gl.addParamDim(LuaGL::Floatv, GL_POLYGON_OFFSET_UNITS, 1);
  gl.addParamDim(LuaGL::Floatv, GL_INDEX_CLEAR_VALUE, 1);
  gl.addParamDim(LuaGL::Floatv, GL_RED_SCALE, 1);
  gl.addParamDim(LuaGL::Floatv, GL_GREEN_SCALE, 1);
  gl.addParamDim(LuaGL::Floatv, GL_BLUE_SCALE, 1);
  gl.addParamDim(LuaGL::Floatv, GL_ALPHA_SCALE, 1);
  gl.addParamDim(LuaGL::Floatv, GL_DEPTH_SCALE, 1);
  gl.addParamDim(LuaGL::Floatv, GL_RED_BIAS, 1);
  gl.addParamDim(LuaGL::Floatv, GL_GREEN_BIAS, 1);
  gl.addParamDim(LuaGL::Floatv, GL_BLUE_BIAS, 1);
  gl.addParamDim(LuaGL::Floatv, GL_ALPHA_BIAS, 1);
  gl.addParamDim(LuaGL::Floatv, GL_DEPTH_BIAS, 1);
  gl.addParamDim(LuaGL::Floatv, GL_ZOOM_X, 1);
  gl.addParamDim(LuaGL::Floatv, GL_ZOOM_Y, 1);
  gl.addParamDim(LuaGL::Floatv, GL_MAP1_GRID_SEGMENTS, 1);
  gl.addParamDim(LuaGL::Floatv, GL_POINT_SIZE_GRANULARITY, 1);
  gl.addParamDim(LuaGL::Floatv, GL_LINE_WIDTH_GRANULARITY, 1);
  gl.addParamDim(LuaGL::Lightfv, GL_AMBIENT, 4);
  gl.addParamDim(LuaGL::Lightfv, GL_DIFFUSE, 4);
  gl.addParamDim(LuaGL::Lightfv, GL_SPECULAR, 4);
  gl.addParamDim(LuaGL::Lightfv, GL_POSITION, 4);
  gl.addParamDim(LuaGL::Lightfv, GL_SPOT_DIRECTION, 3);
  gl.addParamDim(LuaGL::Lightfv, GL_SPOT_CUTOFF, 1);
  gl.addParamDim(LuaGL::Lightfv, GL_CONSTANT_ATTENUATION, 1);
  gl.addParamDim(LuaGL::Lightfv, GL_LINEAR_ATTENUATION, 1);
  gl.addParamDim(LuaGL::Lightfv, GL_QUADRATIC_ATTENUATION, 1);
  gl.addParamDim(LuaGL::Materialfv, GL_AMBIENT, 4);
  gl.addParamDim(LuaGL::Materialfv, GL_DIFFUSE, 4);
  gl.addParamDim(LuaGL::Materialfv, GL_SPECULAR, 4);
  gl.addParamDim(LuaGL::Materialfv, GL_EMISSION, 4);
  gl.addParamDim(LuaGL::Materialfv, GL_COLOR_INDEXES, 3);
  gl.addParamDim(LuaGL::Materialfv, GL_SHININESS, 1);
  gl.addParamDim(LuaGL::TexEnviv, GL_TEXTURE_ENV_MODE, 1);
  gl.addParamDim(LuaGL::TexEnvfv, GL_TEXTURE_ENV_COLOR, 4);
  gl.addParamDim(LuaGL::TexGeniv, GL_TEXTURE_GEN_MODE, 1);
  gl.addParamDim(LuaGL::TexGenfv, GL_OBJECT_PLANE, 4);
  gl.addParamDim(LuaGL::TexGenfv, GL_EYE_PLANE, 4);
  gl.addParamDim(LuaGL::TexParameteriv, GL_TEXTURE_MIN_FILTER, 1);
  gl.addParamDim(LuaGL::TexParameteriv, GL_TEXTURE_MAG_FILTER, 1);
  gl.addParamDim(LuaGL::TexParameteriv, GL_TEXTURE_WRAP_S, 1);
  gl.addParamDim(LuaGL::TexParameteriv, GL_TEXTURE_WRAP_T, 1);
  gl.addParamDim(LuaGL::TexParameteriv, GL_TEXTURE_RESIDENT, 1);
  gl.addParamDim(LuaGL::TexParameterfv, GL_TEXTURE_PRIORITY, 1);
  gl.addParamDim(LuaGL::TexParameterfv, GL_TEXTURE_BORDER_COLOR, 4);
  gl.addParamDim(LuaGL::TexLevelParameteriv, GL_TEXTURE_WIDTH, 1);
  gl.addParamDim(LuaGL::TexLevelParameteriv, GL_TEXTURE_HEIGHT, 1);
  gl.addParamDim(LuaGL::TexLevelParameteriv, GL_TEXTURE_BORDER, 1);
  gl.addParamDim(LuaGL::TexLevelParameteriv, GL_TEXTURE_INTERNAL_FORMAT, 1);
  gl.addParamDim(LuaGL::TexLevelParameteriv, GL_TEXTURE_RED_SIZE, 1);
  gl.addParamDim(LuaGL::TexLevelParameteriv, GL_TEXTURE_GREEN_SIZE, 1);
  gl.addParamDim(LuaGL::TexLevelParameteriv, GL_TEXTURE_BLUE_SIZE, 1);
  gl.addParamDim(LuaGL::TexLevelParameteriv, GL_TEXTURE_ALPHA_SIZE, 1);
  gl.addParamDim(LuaGL::TexLevelParameteriv, GL_TEXTURE_LUMINANCE_SIZE, 1);
  gl.addParamDim(LuaGL::TexLevelParameteriv, GL_TEXTURE_INTENSITY_SIZE, 1);
}

void Register_GL_1_1_Functions(lua_State *L, int module) {
  LuaGL::Instance().setVersion(1.1);

  REGISTER_GL_FUNC(L, module, GetError);
  REGISTER_GL_FUNC(L, module, Begin);
  REGISTER_GL_FUNC(L, module, End);
  REGISTER_GL_FUNC(L, module, EdgeFlag);
  REGISTER_GL_FUNC(L, module, Vertex2s);
  REGISTER_GL_FUNC(L, module, Vertex2i);
  REGISTER_GL_FUNC(L, module, Vertex2f);
  REGISTER_GL_FUNC(L, module, Vertex2d);
  REGISTER_GL_FUNC(L, module, Vertex3s);
  REGISTER_GL_FUNC(L, module, Vertex3i);
  REGISTER_GL_FUNC(L, module, Vertex3f);
  REGISTER_GL_FUNC(L, module, Vertex3d);
  REGISTER_GL_FUNC(L, module, Vertex4s);
  REGISTER_GL_FUNC(L, module, Vertex4i);
  REGISTER_GL_FUNC(L, module, Vertex4f);
  REGISTER_GL_FUNC(L, module, Vertex4d);
  REGISTER_GL_FUNC(L, module, Vertex2sv);
  REGISTER_GL_FUNC(L, module, Vertex2iv);
  REGISTER_GL_FUNC(L, module, Vertex2fv);
  REGISTER_GL_FUNC(L, module, Vertex2dv);
  REGISTER_GL_FUNC(L, module, Vertex3sv);
  REGISTER_GL_FUNC(L, module, Vertex3iv);
  REGISTER_GL_FUNC(L, module, Vertex3fv);
  REGISTER_GL_FUNC(L, module, Vertex3dv);
  REGISTER_GL_FUNC(L, module, Vertex4sv);
  REGISTER_GL_FUNC(L, module, Vertex4iv);
  REGISTER_GL_FUNC(L, module, Vertex4fv);
  REGISTER_GL_FUNC(L, module, Vertex4dv);
  REGISTER_GL_FUNC(L, module, TexCoord1s);
  REGISTER_GL_FUNC(L, module, TexCoord1i);
  REGISTER_GL_FUNC(L, module, TexCoord1f);
  REGISTER_GL_FUNC(L, module, TexCoord1d);
  REGISTER_GL_FUNC(L, module, TexCoord2s);
  REGISTER_GL_FUNC(L, module, TexCoord2i);
  REGISTER_GL_FUNC(L, module, TexCoord2f);
  REGISTER_GL_FUNC(L, module, TexCoord2d);
  REGISTER_GL_FUNC(L, module, TexCoord3s);
  REGISTER_GL_FUNC(L, module, TexCoord3i);
  REGISTER_GL_FUNC(L, module, TexCoord3f);
  REGISTER_GL_FUNC(L, module, TexCoord3d);
  REGISTER_GL_FUNC(L, module, TexCoord4s);
  REGISTER_GL_FUNC(L, module, TexCoord4i);
  REGISTER_GL_FUNC(L, module, TexCoord4f);
  REGISTER_GL_FUNC(L, module, TexCoord4d);
  REGISTER_GL_FUNC(L, module, TexCoord2sv);
  REGISTER_GL_FUNC(L, module, TexCoord2iv);
  REGISTER_GL_FUNC(L, module, TexCoord2fv);
  REGISTER_GL_FUNC(L, module, TexCoord2dv);
  REGISTER_GL_FUNC(L, module, TexCoord3sv);
  REGISTER_GL_FUNC(L, module, TexCoord3iv);
  REGISTER_GL_FUNC(L, module, TexCoord3fv);
  REGISTER_GL_FUNC(L, module, TexCoord3dv);
  REGISTER_GL_FUNC(L, module, TexCoord4sv);
  REGISTER_GL_FUNC(L, module, TexCoord4iv);
  REGISTER_GL_FUNC(L, module, TexCoord4fv);
  REGISTER_GL_FUNC(L, module, TexCoord4dv);
  REGISTER_GL_FUNC(L, module, Normal3b);
  REGISTER_GL_FUNC(L, module, Normal3s);
  REGISTER_GL_FUNC(L, module, Normal3i);
  REGISTER_GL_FUNC(L, module, Normal3f);
  REGISTER_GL_FUNC(L, module, Normal3d);
  REGISTER_GL_FUNC(L, module, Normal3bv);
  REGISTER_GL_FUNC(L, module, Normal3sv);
  REGISTER_GL_FUNC(L, module, Normal3iv);
  REGISTER_GL_FUNC(L, module, Normal3fv);
  REGISTER_GL_FUNC(L, module, Normal3dv);
  REGISTER_GL_FUNC(L, module, Color3b);
  REGISTER_GL_FUNC(L, module, Color3ub);
  REGISTER_GL_FUNC(L, module, Color3s);
  REGISTER_GL_FUNC(L, module, Color3us);
  REGISTER_GL_FUNC(L, module, Color3i);
  REGISTER_GL_FUNC(L, module, Color3ui);
  REGISTER_GL_FUNC(L, module, Color3f);
  REGISTER_GL_FUNC(L, module, Color3d);
  REGISTER_GL_FUNC(L, module, Color4b);
  REGISTER_GL_FUNC(L, module, Color4ub);
  REGISTER_GL_FUNC(L, module, Color4s);
  REGISTER_GL_FUNC(L, module, Color4us);
  REGISTER_GL_FUNC(L, module, Color4i);
  REGISTER_GL_FUNC(L, module, Color4ui);
  REGISTER_GL_FUNC(L, module, Color4f);
  REGISTER_GL_FUNC(L, module, Color4d);
  REGISTER_GL_FUNC(L, module, Color3bv);
  REGISTER_GL_FUNC(L, module, Color3ubv);
  REGISTER_GL_FUNC(L, module, Color3sv);
  REGISTER_GL_FUNC(L, module, Color3usv);
  REGISTER_GL_FUNC(L, module, Color3iv);
  REGISTER_GL_FUNC(L, module, Color3uiv);
  REGISTER_GL_FUNC(L, module, Color3fv);
  REGISTER_GL_FUNC(L, module, Color3dv);
  REGISTER_GL_FUNC(L, module, Color4bv);
  REGISTER_GL_FUNC(L, module, Color4ubv);
  REGISTER_GL_FUNC(L, module, Color4sv);
  REGISTER_GL_FUNC(L, module, Color4usv);
  REGISTER_GL_FUNC(L, module, Color4iv);
  REGISTER_GL_FUNC(L, module, Color4uiv);
  REGISTER_GL_FUNC(L, module, Color4fv);
  REGISTER_GL_FUNC(L, module, Color4dv);
  REGISTER_GL_FUNC(L, module, Indexub);
  REGISTER_GL_FUNC(L, module, Indexs);
  REGISTER_GL_FUNC(L, module, Indexi);
  REGISTER_GL_FUNC(L, module, Indexf);
  REGISTER_GL_FUNC(L, module, Indexd);
  REGISTER_GL_FUNC(L, module, VertexPointer);
  REGISTER_GL_FUNC(L, module, TexCoordPointer);
  REGISTER_GL_FUNC(L, module, NormalPointer);
  REGISTER_GL_FUNC(L, module, ColorPointer);
  REGISTER_GL_FUNC(L, module, IndexPointer);
  REGISTER_GL_FUNC(L, module, EdgeFlagPointer);
  REGISTER_GL_FUNC(L, module, EnableClientState);
  REGISTER_GL_FUNC(L, module, DisableClientState);
  REGISTER_GL_FUNC(L, module, ArrayElement);
  REGISTER_GL_FUNC(L, module, DrawArrays);
  REGISTER_GL_FUNC(L, module, DrawElements);
  REGISTER_GL_FUNC(L, module, InterleavedArrays);
  REGISTER_GL_FUNC(L, module, DepthRange);
  REGISTER_GL_FUNC(L, module, MatrixMode);
  REGISTER_GL_FUNC(L, module, Ortho);
  REGISTER_GL_FUNC(L, module, Frustum);
  REGISTER_GL_FUNC(L, module, Viewport);
  REGISTER_GL_FUNC(L, module, PushMatrix);
  REGISTER_GL_FUNC(L, module, PopMatrix);
  REGISTER_GL_FUNC(L, module, LoadIdentity);
  REGISTER_GL_FUNC(L, module, LoadMatrixf);
  REGISTER_GL_FUNC(L, module, LoadMatrixd);
  REGISTER_GL_FUNC(L, module, MultMatrixf);
  REGISTER_GL_FUNC(L, module, MultMatrixd);
  REGISTER_GL_FUNC(L, module, Rotatef);
  REGISTER_GL_FUNC(L, module, Scalef);
  REGISTER_GL_FUNC(L, module, Translatef);
  REGISTER_GL_FUNC(L, module, Rotated);
  REGISTER_GL_FUNC(L, module, Scaled);
  REGISTER_GL_FUNC(L, module, Translated);
  REGISTER_GL_FUNC(L, module, Rects);
  REGISTER_GL_FUNC(L, module, Recti);
  REGISTER_GL_FUNC(L, module, Rectf);
  REGISTER_GL_FUNC(L, module, Rectd);
  REGISTER_GL_FUNC(L, module, Rectsv);
  REGISTER_GL_FUNC(L, module, Rectiv);
  REGISTER_GL_FUNC(L, module, Rectfv);
  REGISTER_GL_FUNC(L, module, Rectdv);
  REGISTER_GL_FUNC(L, module, Disable);
  REGISTER_GL_FUNC(L, module, Enable);
  REGISTER_GL_FUNC(L, module, IsEnabled);
  REGISTER_GL_FUNC(L, module, TexGeni);
  REGISTER_GL_FUNC(L, module, TexGenf);
  REGISTER_GL_FUNC(L, module, TexGend);
  REGISTER_GL_FUNC(L, module, TexGeniv);
  REGISTER_GL_FUNC(L, module, TexGenfv);
  REGISTER_GL_FUNC(L, module, TexGendv);
  REGISTER_GL_FUNC(L, module, ClipPlane);
  REGISTER_GL_FUNC(L, module, RasterPos2s);
  REGISTER_GL_FUNC(L, module, RasterPos2i);
  REGISTER_GL_FUNC(L, module, RasterPos2f);
  REGISTER_GL_FUNC(L, module, RasterPos2d);
  REGISTER_GL_FUNC(L, module, RasterPos3s);
  REGISTER_GL_FUNC(L, module, RasterPos3i);
  REGISTER_GL_FUNC(L, module, RasterPos3f);
  REGISTER_GL_FUNC(L, module, RasterPos3d);
  REGISTER_GL_FUNC(L, module, RasterPos4s);
  REGISTER_GL_FUNC(L, module, RasterPos4i);
  REGISTER_GL_FUNC(L, module, RasterPos4f);
  REGISTER_GL_FUNC(L, module, RasterPos4d);
  REGISTER_GL_FUNC(L, module, RasterPos2sv);
  REGISTER_GL_FUNC(L, module, RasterPos2iv);
  REGISTER_GL_FUNC(L, module, RasterPos2fv);
  REGISTER_GL_FUNC(L, module, RasterPos2dv);
  REGISTER_GL_FUNC(L, module, RasterPos3sv);
  REGISTER_GL_FUNC(L, module, RasterPos3iv);
  REGISTER_GL_FUNC(L, module, RasterPos3fv);
  REGISTER_GL_FUNC(L, module, RasterPos3dv);
  REGISTER_GL_FUNC(L, module, RasterPos4sv);
  REGISTER_GL_FUNC(L, module, RasterPos4iv);
  REGISTER_GL_FUNC(L, module, RasterPos4fv);
  REGISTER_GL_FUNC(L, module, RasterPos4dv);
  REGISTER_GL_FUNC(L, module, Materiali);
  REGISTER_GL_FUNC(L, module, Materialf);
  REGISTER_GL_FUNC(L, module, Materialiv);
  REGISTER_GL_FUNC(L, module, Materialfv);
  REGISTER_GL_FUNC(L, module, Lighti);
  REGISTER_GL_FUNC(L, module, Lightf);
  REGISTER_GL_FUNC(L, module, Lightiv);
  REGISTER_GL_FUNC(L, module, Lightfv);
  REGISTER_GL_FUNC(L, module, LightModeli);
  REGISTER_GL_FUNC(L, module, LightModelf);
  REGISTER_GL_FUNC(L, module, LightModeliv);
  REGISTER_GL_FUNC(L, module, LightModelfv);
  REGISTER_GL_FUNC(L, module, ColorMaterial);
  REGISTER_GL_FUNC(L, module, ShadeModel);
  REGISTER_GL_FUNC(L, module, FrontFace);
  REGISTER_GL_FUNC(L, module, PointSize);
  REGISTER_GL_FUNC(L, module, LineWidth);
  REGISTER_GL_FUNC(L, module, LineStipple);
  REGISTER_GL_FUNC(L, module, CullFace);
  REGISTER_GL_FUNC(L, module, PolygonStipple);
  REGISTER_GL_FUNC(L, module, PolygonMode);
  REGISTER_GL_FUNC(L, module, PolygonOffset);
  REGISTER_GL_FUNC(L, module, PixelStorei);
  REGISTER_GL_FUNC(L, module, PixelStoref);
  REGISTER_GL_FUNC(L, module, PixelTransferi);
  REGISTER_GL_FUNC(L, module, PixelTransferf);
  REGISTER_GL_FUNC(L, module, PixelMapusv);
  REGISTER_GL_FUNC(L, module, PixelMapuiv);
  REGISTER_GL_FUNC(L, module, PixelMapfv);
  REGISTER_GL_FUNC(L, module, DrawPixels);
  REGISTER_GL_FUNC(L, module, PixelZoom);
  REGISTER_GL_FUNC(L, module, Bitmap);
  REGISTER_GL_FUNC(L, module, TexImage1D);
  REGISTER_GL_FUNC(L, module, TexImage2D);
  REGISTER_GL_FUNC(L, module, CopyTexImage1D);
  REGISTER_GL_FUNC(L, module, CopyTexImage2D);
  REGISTER_GL_FUNC(L, module, TexSubImage1D);
  REGISTER_GL_FUNC(L, module, TexSubImage2D);
  REGISTER_GL_FUNC(L, module, CopyTexSubImage1D);
  REGISTER_GL_FUNC(L, module, CopyTexSubImage2D);
  REGISTER_GL_FUNC(L, module, TexParameteri);
  REGISTER_GL_FUNC(L, module, TexParameterf);
  REGISTER_GL_FUNC(L, module, TexParameteriv);
  REGISTER_GL_FUNC(L, module, TexParameterfv);
  REGISTER_GL_FUNC(L, module, BindTexture);
  REGISTER_GL_FUNC(L, module, GenTextures);
  REGISTER_GL_FUNC(L, module, DeleteTextures);
  REGISTER_GL_FUNC(L, module, AreTexturesResident);
  REGISTER_GL_FUNC(L, module, PrioritizeTextures);
  REGISTER_GL_FUNC(L, module, TexEnvi);
  REGISTER_GL_FUNC(L, module, TexEnvf);
  REGISTER_GL_FUNC(L, module, TexEnviv);
  REGISTER_GL_FUNC(L, module, TexEnvfv);
  REGISTER_GL_FUNC(L, module, Fogi);
  REGISTER_GL_FUNC(L, module, Fogf);
  REGISTER_GL_FUNC(L, module, Fogiv);
  REGISTER_GL_FUNC(L, module, Fogfv);
  REGISTER_GL_FUNC(L, module, Scissor);
  REGISTER_GL_FUNC(L, module, AlphaFunc);
  REGISTER_GL_FUNC(L, module, StencilFunc);
  REGISTER_GL_FUNC(L, module, StencilOp);
  REGISTER_GL_FUNC(L, module, DepthFunc);
  REGISTER_GL_FUNC(L, module, BlendFunc);
  REGISTER_GL_FUNC(L, module, LogicOp);
  REGISTER_GL_FUNC(L, module, DrawBuffer);
  REGISTER_GL_FUNC(L, module, IndexMask);
  REGISTER_GL_FUNC(L, module, ColorMask);
  REGISTER_GL_FUNC(L, module, DepthMask);
  REGISTER_GL_FUNC(L, module, StencilMask);
  REGISTER_GL_FUNC(L, module, Clear);
  REGISTER_GL_FUNC(L, module, ClearColor);
  REGISTER_GL_FUNC(L, module, ClearIndex);
  REGISTER_GL_FUNC(L, module, ClearDepth);
  REGISTER_GL_FUNC(L, module, ClearStencil);
  REGISTER_GL_FUNC(L, module, ClearAccum);
  REGISTER_GL_FUNC(L, module, Accum);
  REGISTER_GL_FUNC(L, module, ReadPixels);
  REGISTER_GL_FUNC(L, module, ReadBuffer);
  REGISTER_GL_FUNC(L, module, CopyPixels);
  REGISTER_GL_FUNC(L, module, Map1f);
  REGISTER_GL_FUNC(L, module, Map1d);
  REGISTER_GL_FUNC(L, module, Map2f);
  REGISTER_GL_FUNC(L, module, Map2d);
  REGISTER_GL_FUNC(L, module, EvalCoord1f);
  REGISTER_GL_FUNC(L, module, EvalCoord1d);
  REGISTER_GL_FUNC(L, module, EvalCoord2f);
  REGISTER_GL_FUNC(L, module, EvalCoord2d);
  REGISTER_GL_FUNC(L, module, EvalCoord2fv);
  REGISTER_GL_FUNC(L, module, EvalCoord2dv);
  REGISTER_GL_FUNC(L, module, MapGrid1f);
  REGISTER_GL_FUNC(L, module, MapGrid1d);
  REGISTER_GL_FUNC(L, module, MapGrid2f);
  REGISTER_GL_FUNC(L, module, MapGrid2d);
  REGISTER_GL_FUNC(L, module, EvalMesh1);
  REGISTER_GL_FUNC(L, module, EvalMesh2);
  REGISTER_GL_FUNC(L, module, EvalPoint1);
  REGISTER_GL_FUNC(L, module, EvalPoint2);
  REGISTER_GL_FUNC(L, module, InitNames);
  REGISTER_GL_FUNC(L, module, PopName);
  REGISTER_GL_FUNC(L, module, PushName);
  REGISTER_GL_FUNC(L, module, LoadName);
  REGISTER_GL_FUNC(L, module, RenderMode);
  REGISTER_GL_FUNC(L, module, SelectBuffer);
  REGISTER_GL_FUNC(L, module, FeedbackBuffer);
  REGISTER_GL_FUNC(L, module, PassThrough);
  REGISTER_GL_FUNC(L, module, NewList);
  REGISTER_GL_FUNC(L, module, EndList);
  REGISTER_GL_FUNC(L, module, CallList);
  REGISTER_GL_FUNC(L, module, CallLists);
  REGISTER_GL_FUNC(L, module, ListBase);
  REGISTER_GL_FUNC(L, module, GenLists);
  REGISTER_GL_FUNC(L, module, IsList);
  REGISTER_GL_FUNC(L, module, DeleteLists);
  REGISTER_GL_FUNC(L, module, Flush);
  REGISTER_GL_FUNC(L, module, Finish);
  REGISTER_GL_FUNC(L, module, Hint);
  REGISTER_GL_FUNC(L, module, IsTexture);
  REGISTER_GL_FUNC(L, module, GetString);
  REGISTER_GL_FUNC(L, module, PushAttrib);
  REGISTER_GL_FUNC(L, module, PushClientAttrib);
  REGISTER_GL_FUNC(L, module, PopAttrib);
  REGISTER_GL_FUNC(L, module, PopClientAttrib);
  //REGISTER_GL_FUNC(L, module, GetBooleanv);
  //REGISTER_GL_FUNC(L, module, GetIntegerv);
  //REGISTER_GL_FUNC(L, module, GetFloatv);
  //REGISTER_GL_FUNC(L, module, GetDoublev);
  REGISTER_GL_FUNC(L, module, Get);
  REGISTER_GL_FUNC(L, module, GetClipPlane);
  //REGISTER_GL_FUNC(L, module, GetLightiv);
  //REGISTER_GL_FUNC(L, module, GetLightfv);
  REGISTER_GL_FUNC(L, module, GetLight);
  //REGISTER_GL_FUNC(L, module, GetMaterialiv);
  //REGISTER_GL_FUNC(L, module, GetMaterialfv);
  REGISTER_GL_FUNC(L, module, GetMaterial);
  //REGISTER_GL_FUNC(L, module, GetTexEnviv);
  //REGISTER_GL_FUNC(L, module, GetTexEnvfv);
  REGISTER_GL_FUNC(L, module, GetTexEnv);
  //REGISTER_GL_FUNC(L, module, GetTexGeniv);
  //REGISTER_GL_FUNC(L, module, GetTexGenfv);
  //REGISTER_GL_FUNC(L, module, GetTexGendv);
  REGISTER_GL_FUNC(L, module, GetTexGen);
  //REGISTER_GL_FUNC(L, module, GetTexParameteriv);
  //REGISTER_GL_FUNC(L, module, GetTexParameterfv);
  REGISTER_GL_FUNC(L, module, GetTexParameter);
  //REGISTER_GL_FUNC(L, module, GetTexLevelParameteriv);
  //REGISTER_GL_FUNC(L, module, GetTexLevelParameterfv);
  REGISTER_GL_FUNC(L, module, GetTexLevelParameter);

  REGISTER_GL_FUNC(L, module, GetPixelMapuiv);
  REGISTER_GL_FUNC(L, module, GetPixelMapusv);
  REGISTER_GL_FUNC(L, module, GetPixelMapfv);

  REGISTER_GL_FUNC(L, module, GetMapiv);
  REGISTER_GL_FUNC(L, module, GetMapfv);
  REGISTER_GL_FUNC(L, module, GetMapdv);
  //REGISTER_GL_FUNC(L, module, GetMap);

  REGISTER_GL_FUNC(L, module, GetTexImage);
  REGISTER_GL_FUNC(L, module, GetPolygonStipple);
  //REGISTER_GL_FUNC(L, module, GetPointerv);
  REGISTER_GL_FUNC(L, module, GetPointer);
}

