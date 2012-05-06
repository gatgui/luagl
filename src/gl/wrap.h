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

#ifndef __wrap_h_
#define __wrap_h_

#include "convert.h"

struct WrapFunc0 {
  static inline int Call(lua_State *L, void (CALLBACK *func)()) {
    CHECK_ARG_COUNT(L, 0);
    func();
    return 0;
  }
};
template <typename A>
struct WrapFunc1 {
  static inline int Call(lua_State *L, void (CALLBACK *func)(typename A::T)) {
    CHECK_ARG_COUNT(L, 1);
    A arg0(L, 1);
    func(arg0);
    return 0;
  }
};
template <typename A, typename B>
struct WrapFunc2 {
  static inline int Call(lua_State *L, void (CALLBACK *func)(typename A::T, typename B::T)) {
    CHECK_ARG_COUNT(L, 2);
    A arg0(L, 1);
    B arg1(L, 2);
    func(arg0, arg1);
    return 0;
  }
};
template <typename A, typename B, typename C>
struct WrapFunc3 {
  static inline int Call(lua_State *L, void (CALLBACK *func)(typename A::T, typename B::T, typename C::T)) {
    CHECK_ARG_COUNT(L, 3);
    A arg0(L, 1);
    B arg1(L, 2);
    C arg2(L, 3);
    func(arg0, arg1, arg2);
    return 0;
  }
};
template <typename A, typename B, typename C, typename D>
struct WrapFunc4 {
  static inline int Call(lua_State *L, void (CALLBACK *func)(typename A::T, typename B::T, typename C::T,
                                                             typename D::T)) {
    CHECK_ARG_COUNT(L, 4);
    A arg0(L, 1);
    B arg1(L, 2);
    C arg2(L, 3);
    D arg3(L, 4);
    func(arg0, arg1, arg2, arg3);
    return 0;
  }
};
template <typename A, typename B, typename C, typename D, typename E>
struct WrapFunc5 {
  static inline int Call(lua_State *L, void (CALLBACK *func)(typename A::T, typename B::T, typename C::T,
                                                             typename D::T, typename E::T)) {
    CHECK_ARG_COUNT(L, 5);
    A arg0(L, 1);
    B arg1(L, 2);
    C arg2(L, 3);
    D arg3(L, 4);
    E arg4(L, 5);
    func(arg0, arg1, arg2, arg3, arg4);
    return 0;
  }
};
template <typename A, typename B, typename C, typename D, typename E,
          typename F>
struct WrapFunc6 {
  static inline int Call(lua_State *L, void (CALLBACK *func)(typename A::T, typename B::T, typename C::T,
                                                             typename D::T, typename E::T, typename F::T)) {
    CHECK_ARG_COUNT(L, 6);
    A arg0(L, 1);
    B arg1(L, 2);
    C arg2(L, 3);
    D arg3(L, 4);
    E arg4(L, 5);
    F arg5(L, 6);
    func(arg0, arg1, arg2, arg3, arg4, arg5);
    return 0;
  }
};
template <typename A, typename B, typename C, typename D, typename E,
          typename F, typename G>
struct WrapFunc7 {
  static inline int Call(lua_State *L, void (CALLBACK *func)(typename A::T, typename B::T, typename C::T,
                                                             typename D::T, typename E::T, typename F::T,
                                                             typename G::T)) {
    CHECK_ARG_COUNT(L, 7);
    A arg0(L, 1);
    B arg1(L, 2);
    C arg2(L, 3);
    D arg3(L, 4);
    E arg4(L, 5);
    F arg5(L, 6);
    G arg6(L, 7);
    func(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
    return 0;
  }
};
template <typename A, typename B, typename C, typename D, typename E,
          typename F, typename G, typename H>
struct WrapFunc8 {
  static inline int Call(lua_State *L, void (CALLBACK *func)(typename A::T, typename B::T, typename C::T,
                                                             typename D::T, typename E::T, typename F::T,
                                                             typename G::T, typename H::T)) {
    CHECK_ARG_COUNT(L, 8);
    A arg0(L, 1);
    B arg1(L, 2);
    C arg2(L, 3);
    D arg3(L, 4);
    E arg4(L, 5);
    F arg5(L, 6);
    G arg6(L, 7);
    H arg7(L, 8);
    func(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    return 0;
  }
};
template <typename A, typename B, typename C, typename D, typename E,
          typename F, typename G, typename H, typename I>
struct WrapFunc9 {
  static inline int Call(lua_State *L, void (CALLBACK *func)(typename A::T, typename B::T, typename C::T,
                                                             typename D::T, typename E::T, typename F::T,
                                                             typename G::T, typename H::T, typename I::T)) {
    CHECK_ARG_COUNT(L, 9);
    A arg0(L, 1);
    B arg1(L, 2);
    C arg2(L, 3);
    D arg3(L, 4);
    E arg4(L, 5);
    F arg5(L, 6);
    G arg6(L, 7);
    H arg7(L, 8);
    I arg8(L, 9);
    func(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    return 0;
  }
};
template <typename A, typename B, typename C, typename D, typename E,
          typename F, typename G, typename H, typename I, typename J>
struct WrapFunc10 {
  static inline int Call(lua_State *L, void (CALLBACK *func)(typename A::T, typename B::T, typename C::T,
                                                             typename D::T, typename E::T, typename F::T,
                                                             typename G::T, typename H::T, typename I::T,
                                                             typename J::T)) {
    CHECK_ARG_COUNT(L, 10);
    A arg0(L, 1);
    B arg1(L, 2);
    C arg2(L, 3);
    D arg3(L, 4);
    E arg4(L, 5);
    F arg5(L, 6);
    G arg6(L, 7);
    H arg7(L, 8);
    I arg8(L, 9);
    J arg9(L, 10);
    func(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    return 0;
  }
};
template <typename A, typename B, typename C, typename D, typename E,
          typename F, typename G, typename H, typename I, typename J,
          typename K>
struct WrapFunc11 {
  static inline int Call(lua_State *L, void (CALLBACK *func)(typename A::T, typename B::T, typename C::T,
                                                             typename D::T, typename E::T, typename F::T,
                                                             typename G::T, typename H::T, typename I::T,
                                                             typename J::T, typename K::T)) {
    CHECK_ARG_COUNT(L, 11);
    A arg0(L, 1);
    B arg1(L, 2);
    C arg2(L, 3);
    D arg3(L, 4);
    E arg4(L, 5);
    F arg5(L, 6);
    G arg6(L, 7);
    H arg7(L, 8);
    I arg8(L, 9);
    J arg9(L, 10);
    K arg10(L, 11);
    func(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
    return 0;
  }
};

#endif
