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

#ifndef __common_h_
#define __common_h_

#ifdef _WIN32
# define WIN32_LEAN_AND_MEAN
# include <windows.h>
# pragma warning(disable: 4702)
# define EXPORT extern "C" __declspec(dllexport)
#else
# define EXPORT extern "C"
# define CALLBACK
#endif

#include <GL/glew.h>
#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <string>
#include <map>

#include <lua.hpp>

#include "mem/manager.h"

#define CHECK_ARG_COUNT(L, n) \
  if (lua_gettop(L) != n) {\
    lua_pushfstring(L, "%d arguments expected (including self when it applies)", n);\
    lua_error(L);\
  }

#endif
