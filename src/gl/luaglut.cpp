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

#include "common.h"
#include "convert.h"
#include "wrap.h"

#ifdef __APPLE__
# include <GLUT/glut.h>
#else
# include <GL/glut.h>
#endif


#define MENU_MAX_ENTRY 100


class LuaGLUT {
  
  protected:
    
    struct WindowCallbacks {
      std::string Display;
      std::string Reshape;
      std::string Keyboard;
      std::string Mouse;
      std::string Motion;
      std::string PassiveMotion;
      std::string Entry;
      std::string Visibility;
      std::string Special;
      std::string SpaceballMotion;
      std::string SpaceballRotate;
      std::string SpaceballButton;
      std::string ButtonBox;
      std::string Dials;
      std::string TabletMotion;
      std::string TabletButton;
      std::string OverlayDisplay;
      std::string Status;
      std::string KeyboardUp;
      std::string SpecialUp;
      std::string Joystick;
    };
  
  public:

    static int REG_KEY;
    static unsigned int INTEGER_ERROR;
    static GLenum ENUM_ERROR;
    static void* PTR_ERROR;
    static LuaGLUT * msInstance;

  public:

    LuaGLUT(lua_State *L) {
      assert(msInstance == 0);
      msInstance = this;
      initDefines();
      mState = L;
    }

    ~LuaGLUT() {
      msInstance = 0;
      mState = 0;
    }
    
    unsigned int getInteger(const std::string &name) {
      std::map<std::string, unsigned int>::iterator it = mIConstants.find(name);
      if (it == mIConstants.end()) {
        return INTEGER_ERROR;
      } else {
        return it->second;
      }
    }

    GLenum getEnum(const std::string &name) {
      std::map<std::string, GLenum>::iterator it = mEConstants.find(name);
      if (it == mEConstants.end()) {
        return ENUM_ERROR;
      } else {
        return it->second;
      }
    }

    void* getPtr(const std::string &name) {
      std::map<std::string, void*>::iterator it = mPConstants.find(name);
      if (it == mPConstants.end()) {
        return PTR_ERROR;
      } else {
        return it->second;
      }
    }
    
    inline lua_State* state() const {
      return mState;
    }
    
    void addTimerCallback(int tid, const char *name) {
      mTimerCallbacks[tid] = std::string(name);
    }
    
    const char* findTimerCallback(int tid) {
      std::map<int, std::string>::iterator it = mTimerCallbacks.find(tid);
      if (it != mTimerCallbacks.end()) {
        return it->second.c_str();
      } else {
        return 0;
      }
    }
    
    void addMenuCallback(int mid, const char *name) {
      mMenuCallbacks[mid] = std::string(name);
    }
    
    void removeMenuCallback(int mid) {
      std::map<int, std::string>::iterator it = mMenuCallbacks.find(mid);
      if (it != mMenuCallbacks.end()) {
        mMenuCallbacks.erase(it);
      }
    }
    
    const char* findMenuCallback(int mid) {
      std::map<int, std::string>::iterator it = mMenuCallbacks.find(mid);
      if (it != mMenuCallbacks.end()) {
        return it->second.c_str();
      } else {
        return 0;
      }
    }
    
    WindowCallbacks& getWindowCallbacks(int wid) {
      std::map<int, WindowCallbacks>::iterator it = mWinCallbacks.find(wid);
      if (it == mWinCallbacks.end()) {
        mWinCallbacks[wid] = WindowCallbacks();
      }
      return mWinCallbacks[wid];
    }
    
    WindowCallbacks* findWindowCallbacks(int wid) {
      std::map<int, WindowCallbacks>::iterator it = mWinCallbacks.find(wid);
      if (it != mWinCallbacks.end()) {
        return &(it->second);
      } else {
        return 0;
      }
    }
    
#define FIND_WINDOW_CALLBACK(name)\
    const char* findWindow##name##Callback(int wid) {\
      WindowCallbacks *wc = findWindowCallbacks(wid);\
      if (wc != 0) {\
        if (wc->name.length() > 0) {\
          return wc->name.c_str();\
        }\
      }\
      return 0;\
    }
  
    FIND_WINDOW_CALLBACK(Display);
    FIND_WINDOW_CALLBACK(Reshape);
    FIND_WINDOW_CALLBACK(Keyboard);
    FIND_WINDOW_CALLBACK(Mouse);
    FIND_WINDOW_CALLBACK(Motion);
    FIND_WINDOW_CALLBACK(PassiveMotion);
    FIND_WINDOW_CALLBACK(Entry);
    FIND_WINDOW_CALLBACK(Visibility);
    FIND_WINDOW_CALLBACK(Special);
    FIND_WINDOW_CALLBACK(SpaceballMotion);
    FIND_WINDOW_CALLBACK(SpaceballRotate);
    FIND_WINDOW_CALLBACK(SpaceballButton);
    FIND_WINDOW_CALLBACK(ButtonBox);
    FIND_WINDOW_CALLBACK(Dials);
    FIND_WINDOW_CALLBACK(TabletMotion);
    FIND_WINDOW_CALLBACK(TabletButton);
    FIND_WINDOW_CALLBACK(OverlayDisplay);
    FIND_WINDOW_CALLBACK(Status);
    FIND_WINDOW_CALLBACK(KeyboardUp);
    FIND_WINDOW_CALLBACK(SpecialUp);
    FIND_WINDOW_CALLBACK(Joystick);
    
#undef FIND_WINDOW_CALLBACK
    
    
  public:
    
    // Proxy callbacks
    
    inline static LuaGLUT& Instance() {
      assert(msInstance != 0);
      return *msInstance;
    }
    
    static void lua_glutMenuCallback(int idx) {
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      const char *fname = lg.findMenuCallback(idx / MENU_MAX_ENTRY);
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushinteger(L, idx % MENU_MAX_ENTRY);
        lua_call(L, 1, 0);
        lua_pop(L, 2);
      }
    }
  
    static void lua_glutDisplayCallback(void) {
      int id = glutGetWindow();
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      const char *fname = lg.findWindowDisplayCallback(id);
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_call(L, 0, 0);
        lua_pop(L, 2);
      }
    }

    static void lua_glutReshapeCallback(int w, int h) {
      int id = glutGetWindow();
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      const char *fname = lg.findWindowReshapeCallback(id);
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushinteger(L, w);
        lua_pushinteger(L, h);
        lua_call(L, 2, 0);
        lua_pop(L, 2);
      }
    }

    static void lua_glutKeyboardCallback(unsigned char c, int x, int y) {
      int id = glutGetWindow();
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      const char *fname = lg.findWindowKeyboardCallback(id);
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushinteger(L, c);
        lua_pushinteger(L, x);
        lua_pushinteger(L, y);
        lua_call(L, 3, 0);
        lua_pop(L, 2);
      }
    }

    static void lua_glutMouseCallback(int b, int s, int x, int y) {
      int id = glutGetWindow();
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      const char *fname = lg.findWindowMouseCallback(id);
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushinteger(L, b);
        lua_pushinteger(L, s);
        lua_pushinteger(L, x);
        lua_pushinteger(L, y);
        lua_call(L, 4, 0);
        lua_pop(L, 2);
      }
    }

    static void lua_glutMotionCallback(int x, int y) {
      int id = glutGetWindow();
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      const char *fname = lg.findWindowMotionCallback(id);
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushinteger(L, x);
        lua_pushinteger(L, y);
        lua_call(L, 2, 0);
        lua_pop(L, 2);
      }
    }
    
    static void lua_glutPassiveMotionCallback(int x, int y) {
      int id = glutGetWindow();
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      const char *fname = lg.findWindowPassiveMotionCallback(id);
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushinteger(L, x);
        lua_pushinteger(L, y);
        lua_call(L, 2, 0);
        lua_pop(L, 2);
      }
    }

    static void lua_glutEntryCallback(int s) {
      int id = glutGetWindow();
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      const char *fname = lg.findWindowEntryCallback(id);
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushinteger(L, s);
        lua_call(L, 1, 0);
        lua_pop(L, 2);
      }
    }

    static void lua_glutVisibilityCallback(int s) {
      int id = glutGetWindow();
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      const char *fname = lg.findWindowVisibilityCallback(id);
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushinteger(L, s);
        lua_call(L, 1, 0);
        lua_pop(L, 2);
      }
    }

    static void lua_glutSpecialCallback(int key, int x, int y) {
      int id = glutGetWindow();
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      const char *fname = lg.findWindowSpecialCallback(id);
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushinteger(L, key);
        lua_pushinteger(L, x);
        lua_pushinteger(L, y);
        lua_call(L, 3, 0);
        lua_pop(L, 2);
      }
    }

    static void lua_glutSpaceballMotionCallback(int x, int y, int z) {
      int id = glutGetWindow();
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      const char *fname = lg.findWindowSpaceballMotionCallback(id);
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushinteger(L, x);
        lua_pushinteger(L, y);
        lua_pushinteger(L, z);
        lua_call(L, 3, 0);
        lua_pop(L, 2);
      }
    }

    static void lua_glutSpaceballRotateCallback(int x, int y, int z) {
      int id = glutGetWindow();
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      const char *fname = lg.findWindowSpaceballRotateCallback(id);
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushinteger(L, x);
        lua_pushinteger(L, y);
        lua_pushinteger(L, z);
        lua_call(L, 3, 0);
        lua_pop(L, 2);
      }
    }

    static void lua_glutSpaceballButtonCallback(int b, int s) {
      int id = glutGetWindow();
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      const char *fname = lg.findWindowSpaceballButtonCallback(id);
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushinteger(L, b);
        lua_pushinteger(L, s);
        lua_call(L, 2, 0);
        lua_pop(L, 2);
      }
    }
    
    static void lua_glutButtonBoxCallback(int b, int s) {
      int id = glutGetWindow();
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      const char *fname = lg.findWindowButtonBoxCallback(id);
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushinteger(L, b);
        lua_pushinteger(L, s);
        lua_call(L, 2, 0);
        lua_pop(L, 2);
      }
    }
    
    static void lua_glutDialsCallback(int dial, int value) {
      int id = glutGetWindow();
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      const char *fname = lg.findWindowDialsCallback(id);
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushinteger(L, dial);
        lua_pushinteger(L, value);
        lua_call(L, 2, 0);
        lua_pop(L, 2);
      }
    }
    
    static void lua_glutTabletMotionCallback(int x, int y) {
      int id = glutGetWindow();
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      const char *fname = lg.findWindowTabletMotionCallback(id);
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushinteger(L, x);
        lua_pushinteger(L, y);
        lua_call(L, 2, 0);
        lua_pop(L, 2);
      }
    }
    
    static void lua_glutTabletButtonCallback(int button, int state, int x, int y) {
      int id = glutGetWindow();
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      const char *fname = lg.findWindowTabletButtonCallback(id);
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushinteger(L, button);
        lua_pushinteger(L, state);
        lua_pushinteger(L, x);
        lua_pushinteger(L, y);
        lua_call(L, 4, 0);
        lua_pop(L, 2);
      }
    }
    
    static void lua_glutOverlayDisplayCallback(void) {
      int id = glutGetWindow();
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      const char *fname = lg.findWindowOverlayDisplayCallback(id);
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_call(L, 0, 0);
        lua_pop(L, 2);
      }
    }
    
    static void lua_glutWindowStatusCallback(int status) {
      int id = glutGetWindow();
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      const char *fname = lg.findWindowStatusCallback(id);
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushinteger(L, status);
        lua_call(L, 1, 0);
        lua_pop(L, 2);
      }
    }
    
    static void lua_glutKeyboardUpCallback(unsigned char key, int x, int y) {
      int id = glutGetWindow();
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      const char *fname = lg.findWindowKeyboardUpCallback(id);
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushinteger(L, key);
        lua_pushinteger(L, x);
        lua_pushinteger(L, y);
        lua_call(L, 3, 0);
        lua_pop(L, 2);
      }
    }
    
    static void lua_glutSpecialUpCallback(int key, int x, int y) {
      int id = glutGetWindow();
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      const char *fname = lg.findWindowSpecialUpCallback(id);
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushinteger(L, key);
        lua_pushinteger(L, x);
        lua_pushinteger(L, y);
        lua_call(L, 3, 0);
        lua_pop(L, 2);
      }
    }
    
    static void lua_glutJoystickCallback(unsigned int mask, int x, int y, int z) {
      int id = glutGetWindow();
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      const char *fname = lg.findWindowJoystickCallback(id);
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushinteger(L, mask);
        lua_pushinteger(L, x);
        lua_pushinteger(L, y);
        lua_pushinteger(L, z);
        lua_call(L, 4, 0);
        lua_pop(L, 2);
      }
    }

    static void lua_glutIdleCallback(void) {
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      lua_getfield(L, LUA_GLOBALSINDEX, "glut");
      lua_getmetatable(L, -1);
      lua_getfield(L, -1, "__glut_idle");
      lua_call(L, 0, 0);
      lua_pop(L, 2);
    }

    static void lua_glutMenuStatusCallback(int status, int x, int y) {
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      lua_getfield(L, LUA_GLOBALSINDEX, "glut");
      lua_getmetatable(L, -1);
      lua_getfield(L, -1, "__glut_menustatus");
      lua_pushinteger(L, status);
      lua_pushinteger(L, x);
      lua_pushinteger(L, y);
      lua_call(L, 3, 0);
      lua_pop(L, 2);
    }
    
    static void lua_glutTimerCallback(int value) {
      LuaGLUT &lg = Instance();
      lua_State *L = lg.state();
      const char *fname = lg.findTimerCallback(value);
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushinteger(L, value);
        lua_call(L, 1, 0);
        lua_pop(L, 2);
      }
    }
    
  public:

    static int lua__gc(lua_State *L) {
      void *ud = lua_touserdata(L, 1);
      LuaGLUT *glut = (LuaGLUT*)ud;
      glut->~LuaGLUT();
      lua_pop(L, 1);
      return 0;
    }
    
    static int lua__index(lua_State *L) {
      
      const char *key = lua_tostring(L, 2);
      
      LuaGLUT &glut = Instance();
      
      unsigned int i = glut.getInteger(key);
      
      if (i == INTEGER_ERROR) {
        
        GLenum e = glut.getEnum(key);

        if (e == ENUM_ERROR) {
          
          void *p = glut.getPtr(key);

          if (p == PTR_ERROR) {
            lua_pushstring(L, "Invalid entry");
            lua_error(L);

          } else {
            lua_pop(L, 2);
            lua_pushlightuserdata(L, p);
          }

        } else {
          lua_pop(L, 2);
          lua_pushinteger(L, lua_Integer(e));
        }

      } else {
        lua_pop(L, 2);
        lua_pushinteger(L, lua_Integer(i));
      }

      return 1;
    }
    
    static int lua__newindex(lua_State *L) {
      lua_pushstring(L, "No assignable values in GL module");
      lua_error(L);
      return 0;
    }

    // GLUT functions
    
    static int lua_glutInit(lua_State *L) {
      CHECK_ARG_COUNT(L, 0);
      static char *argv[] = {"luaglut", 0};
      static int argc = 1;
      glutInit(&argc, argv);
      return 0;
    }

    static int lua_glutInitDisplayMode(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<CUint, glutInitDisplayMode>::Call(L);
#else
      return WrapFunc1<CUint >::Call(L, glutInitDisplayMode);
#endif
    }

    static int lua_glutInitDisplayString(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<String, glutInitDisplayString>::Call(L);
#else
      return WrapFunc1<String >::Call(L, glutInitDisplayString);
#endif
    }

    static int lua_glutInitWindowPosition(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc2<CInt, CInt, glutInitWindowPosition>::Call(L);
#else
      return WrapFunc2<CInt, CInt >::Call(L, glutInitWindowPosition);
#endif
    }

    static int lua_glutInitWindowSize(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc2<CInt, CInt, glutInitWindowSize>::Call(L);
#else
      return WrapFunc2<CInt, CInt >::Call(L, glutInitWindowSize);
#endif
    }

    static int lua_glutMainLoop(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutMainLoop>::Call(L);
#else
      return WrapFunc0::Call(L, glutMainLoop);
#endif
    }

    static int lua_glutCreateWindow(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      String title(L, 1);
      int w = glutCreateWindow(title);
      lua_pushinteger(L, w);
      return 1;
    }

    static int lua_glutCreateSubWindow(lua_State *L) {
      CHECK_ARG_COUNT(L, 5);
      CInt id(L, 1);
      CInt x(L, 2);
      CInt y(L, 3);
      CInt w(L, 4);
      CInt h(L, 5);
      int sid = glutCreateSubWindow(id, x, y, w, h);
      lua_pushinteger(L, sid);
      return 1;
    }

    static int lua_glutDestroyWindow(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<CInt, glutDestroyWindow>::Call(L);
#else
      return WrapFunc1<CInt >::Call(L, glutDestroyWindow);
#endif
    }

    static int lua_glutPostRedisplay(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutPostRedisplay>::Call(L);
#else
      return WrapFunc0::Call(L, glutPostRedisplay);
#endif
    }

    static int lua_glutPostWindowRedisplay(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<CInt, glutPostWindowRedisplay>::Call(L);
#else
      return WrapFunc1<CInt >::Call(L, glutPostWindowRedisplay);
#endif
    }

    static int lua_glutSwapBuffers(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutSwapBuffers>::Call(L);
#else
      return WrapFunc0::Call(L, glutSwapBuffers);
#endif
    }

    static int lua_glutGetWindow(lua_State *L) {
      CHECK_ARG_COUNT(L, 0);
      int id = glutGetWindow();
      lua_pushinteger(L, id);
      return 1;
    }

    static int lua_glutSetWindow(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<CInt, glutSetWindow>::Call(L);
#else
      return WrapFunc1<CInt >::Call(L, glutSetWindow);
#endif
    }

    static int lua_glutSetWindowTitle(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<String, glutSetWindowTitle>::Call(L);
#else
      return WrapFunc1<String >::Call(L, glutSetWindowTitle);
#endif
    }

    static int lua_glutSetIconTitle(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<String, glutSetIconTitle>::Call(L);
#else
      return WrapFunc1<String >::Call(L, glutSetIconTitle);
#endif
    }

    static int lua_glutPositionWindow(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc2<CInt, CInt, glutPositionWindow>::Call(L);
#else
      return WrapFunc2<CInt, CInt >::Call(L, glutPositionWindow);
#endif
    }

    static int lua_glutReshapeWindow(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc2<CInt, CInt, glutReshapeWindow>::Call(L);
#else
      return WrapFunc2<CInt, CInt >::Call(L, glutReshapeWindow);
#endif
    }

    static int lua_glutPopWindow(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutPopWindow>::Call(L);
#else
      return WrapFunc0::Call(L, glutPopWindow);
#endif
    }

    static int lua_glutPushWindow(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutPushWindow>::Call(L);
#else
      return WrapFunc0::Call(L, glutPushWindow);
#endif
    }

    static int lua_glutIconifyWindow(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutIconifyWindow>::Call(L);
#else
      return WrapFunc0::Call(L, glutIconifyWindow);
#endif
    }
    
    static int lua_glutShowWindow(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutShowWindow>::Call(L);
#else
      return WrapFunc0::Call(L, glutShowWindow);
#endif
    }
    
    static int lua_glutHideWindow(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutHideWindow>::Call(L);
#else
      return WrapFunc0::Call(L, glutHideWindow);
#endif
    }
    
    static int lua_glutFullScreen(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutFullScreen>::Call(L);
#else
      return WrapFunc0::Call(L, glutFullScreen);
#endif
    }
    
    static int lua_glutSetCursor(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<CInt, glutSetCursor>::Call(L);
#else
      return WrapFunc1<CInt >::Call(L, glutSetCursor);
#endif
    }
    
    static int lua_glutWarpPointer(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc2<CInt, CInt, glutWarpPointer>::Call(L);
#else
      return WrapFunc2<CInt, CInt >::Call(L, glutWarpPointer);
#endif
    }
    
    static int lua_glutEstablishOverlay(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutEstablishOverlay>::Call(L);
#else
      return WrapFunc0::Call(L, glutEstablishOverlay);
#endif
    }
    
    static int lua_glutRemoveOverlay(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutRemoveOverlay>::Call(L);
#else
      return WrapFunc0::Call(L, glutRemoveOverlay);
#endif
    }
    
    static int lua_glutUseLayer(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<Enum, glutUseLayer>::Call(L);
#else
      return WrapFunc1<Enum >::Call(L, glutUseLayer);
#endif
    }
    
    static int lua_glutPostOverlayRedisplay(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutPostOverlayRedisplay>::Call(L);
#else
      return WrapFunc0::Call(L, glutPostOverlayRedisplay);
#endif
    }
    
    static int lua_glutPostWindowOverlayRedisplay(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<CInt, glutPostWindowOverlayRedisplay>::Call(L);
#else
      return WrapFunc1<CInt >::Call(L, glutPostWindowOverlayRedisplay);
#endif
    }
    
    static int lua_glutShowOverlay(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutShowOverlay>::Call(L);
#else
      return WrapFunc0::Call(L, glutShowOverlay);
#endif
    }
    
    static int lua_glutHideOverlay(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutHideOverlay>::Call(L);
#else
      return WrapFunc0::Call(L, glutHideOverlay);
#endif
    }

    static int lua_glutCreateMenu(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      static char fname[64];
      int m = glutCreateMenu(&LuaGLUT::lua_glutMenuCallback);
      sprintf(fname, "__glut_menu%d", m);
      Instance().addMenuCallback(m, fname);
      lua_getfield(L, LUA_GLOBALSINDEX, "glut");
      lua_getmetatable(L, -1);
      lua_pushvalue(L, 1);
      lua_setfield(L, -2, fname);
      lua_pushinteger(L, m);
      return 1;
    }
    
    static int lua_glutDestroyMenu(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      static char fname[64];
      CInt m(L, 1);      
      sprintf(fname, "__glut_menu%d", (int)m);
      Instance().removeMenuCallback(m);
      lua_getfield(L, LUA_GLOBALSINDEX, "glut");
      lua_getmetatable(L, -1);
      lua_pushnil(L);
      lua_setfield(L, -2, fname);
      glutDestroyMenu(m);
      return 0;
    }
    
    static int lua_glutGetMenu(lua_State *L) {
      int m = glutGetMenu();
      lua_pushinteger(L, m);
      return 1;
    }
    
    static int lua_glutSetMenu(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<CInt, glutSetMenu>::Call(L);
#else
      return WrapFunc1<CInt >::Call(L, glutSetMenu);
#endif
    }
    
    static int lua_glutAddMenuEntry(lua_State *L) {
      CHECK_ARG_COUNT(L, 2);
      int menuoffset = glutGetMenu() * MENU_MAX_ENTRY;
      String label(L, 1);
      CInt val(L, 2);
      glutAddMenuEntry(label, menuoffset+val);
      return 0;
    }
    
    static int lua_glutAddSubMenu(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc2<String, CInt, glutAddSubMenu>::Call(L);
#else
      return WrapFunc2<String, CInt >::Call(L, glutAddSubMenu);
#endif
    }
    
    static int lua_glutChangeToMenuEntry(lua_State *L) {
      CHECK_ARG_COUNT(L, 3);
      int menuoffset = glutGetMenu() * MENU_MAX_ENTRY;
      CInt item(L, 1);
      String label(L, 2);
      Int value(L, 3);
      glutChangeToMenuEntry(item, label, menuoffset+value);
      return 0;
    }
    
    static int lua_glutChangeToSubMenu(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc3<CInt, String, CInt, glutChangeToSubMenu>::Call(L);
#else
      return WrapFunc3<CInt, String, CInt >::Call(L, glutChangeToSubMenu);
#endif
    }
    
    static int lua_glutRemoveMenuItem(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<CInt, glutRemoveMenuItem>::Call(L);
#else
      return WrapFunc1<CInt >::Call(L, glutRemoveMenuItem);
#endif
    }
    
    static int lua_glutAttachMenu(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<CInt, glutAttachMenu>::Call(L);
#else
      return WrapFunc1<CInt >::Call(L, glutAttachMenu);
#endif
    }
    
    static int lua_glutDetachMenu(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<CInt, glutDetachMenu>::Call(L);
#else
      return WrapFunc1<CInt >::Call(L, glutDetachMenu);
#endif
    }
    
    static int lua_glutDisplayFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      static char fname[64];
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      sprintf(fname, "__glut_wdisplay%d", wid);
      if (lua_isnil(L, 1)) {
        lua_pushstring(L, "GLUT windows MUST have a display callback");
        lua_error(L);
      } else {
        wc.Display = std::string(fname);
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1); // set callback on metatable whose __newindex is not overridden
        lua_pushvalue(L, 1);
        lua_setfield(L, -2, fname);
        glutDisplayFunc(lua_glutDisplayCallback);
      }
      
      return 0;
    }
    
    static int lua_glutReshapeFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      static char fname[64];
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      sprintf(fname, "__glut_wreshape%d", wid);
      if (lua_isnil(L, 1)) {
        wc.Reshape = "";
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushnil(L);
        lua_setfield(L, -2, fname);
        glutReshapeFunc(0);
      } else {
        wc.Reshape = std::string(fname);
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushvalue(L, 1);
        lua_setfield(L, -2, fname);
        glutReshapeFunc(lua_glutReshapeCallback);
      }
      return 0;
    }
    
    static int lua_glutKeyboardFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      static char fname[64];
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      sprintf(fname, "__glut_wkeyb%d", wid);
      if (lua_isnil(L, 1)) {
        wc.Keyboard = "";
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushnil(L);
        lua_setfield(L, -2, fname);
        glutKeyboardFunc(0);
      } else {
        wc.Keyboard = std::string(fname);
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushvalue(L, 1);
        lua_setfield(L, -2, fname);
        glutKeyboardFunc(lua_glutKeyboardCallback);
      }
      return 0;
    }
    
    static int lua_glutKeyboardUpFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      static char fname[64];
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      sprintf(fname, "__glut_wkeybup%d", wid);
      if (lua_isnil(L, 1)) {
        wc.KeyboardUp = "";
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushnil(L);
        lua_setfield(L, -2, fname);
        glutKeyboardUpFunc(0);
      } else {
        wc.KeyboardUp = std::string(fname);
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushvalue(L, 1);
        lua_setfield(L, -2, fname);
        glutKeyboardUpFunc(lua_glutKeyboardUpCallback);
      }
      return 0;
    }
    
    static int lua_glutMouseFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      static char fname[64];
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      sprintf(fname, "__glut_wmouse%d", wid);
      if (lua_isnil(L, 1)) {
        wc.Mouse = "";
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushnil(L);
        lua_setfield(L, -2, fname);
        glutMouseFunc(0);
      } else {
        wc.Mouse = std::string(fname);
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushvalue(L, 1);
        lua_setfield(L, -2, fname);
        glutMouseFunc(lua_glutMouseCallback);
      }
      return 0;
    }
    
    static int lua_glutMotionFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      static char fname[64];
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      sprintf(fname, "__glut_wmotion%d", wid);
      if (lua_isnil(L, 1)) {
        wc.Motion = "";
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushnil(L);
        lua_setfield(L, -2, fname);
        glutMotionFunc(0);
      } else {
        wc.Motion = std::string(fname);
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushvalue(L, 1);
        lua_setfield(L, -2, fname);
        glutMotionFunc(lua_glutMotionCallback);
      }
      return 0;
    }
    
    static int lua_glutPassiveMotionFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      static char fname[64];
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      sprintf(fname, "__glut_wpmotion%d", wid);
      if (lua_isnil(L, 1)) {
        wc.PassiveMotion = "";
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushnil(L);
        lua_setfield(L, -2, fname);
        glutPassiveMotionFunc(0);
      } else {
        wc.PassiveMotion = std::string(fname);
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushvalue(L, 1);
        lua_setfield(L, -2, fname);
        glutPassiveMotionFunc(lua_glutPassiveMotionCallback);
      }
      return 0;
    }
    
    static int lua_glutEntryFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      static char fname[64];
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      sprintf(fname, "__glut_wentry%d", wid);
      if (lua_isnil(L, 1)) {
        wc.Entry = "";
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushnil(L);
        lua_setfield(L, -2, fname);
        glutEntryFunc(0);
      } else {
        wc.Entry = std::string(fname);
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushvalue(L, 1);
        lua_setfield(L, -2, fname);
        glutEntryFunc(lua_glutEntryCallback);
      }
      return 0;
    }
    
    static int lua_glutSpecialFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      static char fname[64];
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      sprintf(fname, "__glut_wspec%d", wid);
      if (lua_isnil(L, 1)) {
        wc.Special = "";
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushnil(L);
        lua_setfield(L, -2, fname);
        glutSpecialFunc(0);
      } else {
        wc.Special = std::string(fname);
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushvalue(L, 1);
        lua_setfield(L, -2, fname);
        glutSpecialFunc(lua_glutSpecialCallback);
      }
      return 0;
    }
    
    static int lua_glutSpecialUpFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      static char fname[64];
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      sprintf(fname, "__glut_wspecup%d", wid);
      if (lua_isnil(L, 1)) {
        wc.SpecialUp = "";
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushnil(L);
        lua_setfield(L, -2, fname);
        glutSpecialUpFunc(0);
      } else {
        wc.SpecialUp = std::string(fname);
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushvalue(L, 1);
        lua_setfield(L, -2, fname);
        glutSpecialUpFunc(lua_glutSpecialUpCallback);
      }
      return 0;
    }
    
    static int lua_glutVisibilityFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      static char fname[64];
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      sprintf(fname, "__glut_wvis%d", wid);
      if (lua_isnil(L, 1)) {
        wc.Visibility = "";
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushnil(L);
        lua_setfield(L, -2, fname);
        glutVisibilityFunc(0);
      } else {
        wc.Visibility = std::string(fname);
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushvalue(L, 1);
        lua_setfield(L, -2, fname);
        glutVisibilityFunc(lua_glutVisibilityCallback);
      }
      return 0;
    }
    
    static int lua_glutSpaceballMotionFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      static char fname[64];
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      sprintf(fname, "__glut_wsbm%d", wid);
      if (lua_isnil(L, 1)) {
        wc.SpaceballMotion = "";
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushnil(L);
        lua_setfield(L, -2, fname);
        glutSpaceballMotionFunc(0);
      } else {
        wc.SpaceballMotion = std::string(fname);
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushvalue(L, 1);
        lua_setfield(L, -2, fname);
        glutSpaceballMotionFunc(lua_glutSpaceballMotionCallback);
      }
      return 0;
    }
    
    static int lua_glutSpaceballRotateFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      static char fname[64];
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      sprintf(fname, "__glut_wsbr%d", wid);
      if (lua_isnil(L, 1)) {
        wc.SpaceballRotate = "";
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushnil(L);
        lua_setfield(L, -2, fname);
        glutSpaceballRotateFunc(0);
      } else {
        wc.SpaceballRotate = std::string(fname);
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushvalue(L, 1);
        lua_setfield(L, -2, fname);
        glutSpaceballRotateFunc(lua_glutSpaceballRotateCallback);
      }
      return 0;
    }
    
    static int lua_glutSpaceballButtonFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      static char fname[64];
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      sprintf(fname, "__glut_wsbb%d", wid);
      if (lua_isnil(L, 1)) {
        wc.SpaceballMotion = "";
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushnil(L);
        lua_setfield(L, -2, fname);
        glutSpaceballButtonFunc(0);
      } else {
        wc.SpaceballMotion = std::string(fname);
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushvalue(L, 1);
        lua_setfield(L, -2, fname);
        glutSpaceballButtonFunc(lua_glutSpaceballButtonCallback);
      }
      return 0;
    }
    
    static int lua_glutButtonBoxFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      static char fname[64];
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      sprintf(fname, "__glut_wbb%d", wid);
      if (lua_isnil(L, 1)) {
        wc.ButtonBox = "";
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushnil(L);
        lua_setfield(L, -2, fname);
        glutButtonBoxFunc(0);
      } else {
        wc.ButtonBox = std::string(fname);
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushvalue(L, 1);
        lua_setfield(L, -2, fname);
        glutButtonBoxFunc(lua_glutButtonBoxCallback);
      }
      return 0;
    }
    
    static int lua_glutDialsFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      static char fname[64];
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      sprintf(fname, "__glut_wdials%d", wid);
      if (lua_isnil(L, 1)) {
        wc.Dials = "";
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushnil(L);
        lua_setfield(L, -2, fname);
        glutDialsFunc(0);
      } else {
        wc.Dials = std::string(fname);
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushvalue(L, 1);
        lua_setfield(L, -2, fname);
        glutDialsFunc(lua_glutDialsCallback);
      }
      return 0;
    }
    
    static int lua_glutTabletMotionFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      static char fname[64];
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      sprintf(fname, "__glut_wtabm%d", wid);
      if (lua_isnil(L, 1)) {
        wc.TabletMotion = "";
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushnil(L);
        lua_setfield(L, -2, fname);
        glutTabletMotionFunc(0);
      } else {
        wc.TabletMotion = std::string(fname);
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushvalue(L, 1);
        lua_setfield(L, -2, fname);
        glutTabletMotionFunc(lua_glutTabletMotionCallback);
      }
      return 0;
    }
    
    static int lua_glutTabletButtonFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      static char fname[64];
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      sprintf(fname, "__glut_wtabb%d", wid);
      if (lua_isnil(L, 1)) {
        wc.TabletButton = "";
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushnil(L);
        lua_setfield(L, -2, fname);
        glutTabletButtonFunc(0);
      } else {
        wc.TabletButton = std::string(fname);
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushvalue(L, 1);
        lua_setfield(L, -2, fname);
        glutTabletButtonFunc(lua_glutTabletButtonCallback);
      }
      return 0;
    }
    
    static int lua_glutOverlayDisplayFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      static char fname[64];
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      sprintf(fname, "__glut_woverd%d", wid);
      if (lua_isnil(L, 1)) {
        wc.OverlayDisplay = "";
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushnil(L);
        lua_setfield(L, -2, fname);
        glutOverlayDisplayFunc(0);
      } else {
        wc.OverlayDisplay = std::string(fname);
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushvalue(L, 1);
        lua_setfield(L, -2, fname);
        glutOverlayDisplayFunc(lua_glutOverlayDisplayCallback);
      }
      return 0;
    }
    
    static int lua_glutWindowStatusFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      static char fname[64];
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      sprintf(fname, "__glut_wstat%d", wid);
      if (lua_isnil(L, 1)) {
        wc.Status = "";
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushnil(L);
        lua_setfield(L, -2, fname);
        glutWindowStatusFunc(0);
      } else {
        wc.Status = std::string(fname);
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushvalue(L, 1);
        lua_setfield(L, -2, fname);
        glutWindowStatusFunc(lua_glutWindowStatusCallback);
      }
      return 0;
    }
    
    static int lua_glutJoystickFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      static char fname[64];
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      sprintf(fname, "__glut_wjoy%d", wid);
      if (lua_isnil(L, 1)) {
        wc.Joystick = "";
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushnil(L);
        lua_setfield(L, -2, fname);
        glutJoystickFunc(0, 0);
      } else {
        wc.Joystick = std::string(fname);
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushvalue(L, 1);
        lua_setfield(L, -2, fname);
        glutJoystickFunc(lua_glutJoystickCallback, (int) lua_tointeger(L, 2));
      }
      return 0;
    }
    
    static int lua_glutIdleFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      if (lua_isnil(L, 1)) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushnil(L);
        lua_setfield(L, -2, "__glut_idle");
        glutIdleFunc(0);
      } else {
        lua_getfield(L, LUA_GLOBALSINDEX, "glut");
        lua_getmetatable(L, -1);
        lua_pushvalue(L, 1);
        lua_setfield(L, -2, "__glut_idle");
        glutIdleFunc(lua_glutIdleCallback);
      }
      
      return 0;
    }
    
    static int lua_glutTimerFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 3);
      static char fname[64];
      if (lua_isnil(L, 2)) {
        lua_pushstring(L, "nil value passed to glut.TimerFunc");
        lua_error(L);
      }
      CUint msec(L, 1);
      CInt value(L, 3);
      //unsigned int msec = (unsigned int) lua_tointeger(L, 1);
      //int value = (int) lua_tointeger(L, 3);
      sprintf(fname, "__glut_timer%d", (int)value);
      Instance().addTimerCallback(value, fname);
      lua_getfield(L, LUA_GLOBALSINDEX, "glut");
      lua_getmetatable(L, -1);
      lua_pushvalue(L, 2);
      lua_setfield(L, -2, fname);
      glutTimerFunc(msec, lua_glutTimerCallback, value);
      return 0;
    }
    
    static int lua_glutMenuStatusFunc(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      lua_getfield(L, LUA_GLOBALSINDEX, "glut");
      lua_getmetatable(L, -1);
      if (lua_isnil(L, 1)) {
        lua_pushnil(L);
        lua_setfield(L, -2, "__glut_menustatus");
        glutMenuStatusFunc(0);
      } else {
        lua_pushvalue(L, 1);
        lua_setfield(L, -2, "__glut_menustatus");
        glutMenuStatusFunc(lua_glutMenuStatusCallback);
      }
      return 0;
    }
  
    static int lua_glutSetColor(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc4<CInt, Float, Float, Float, glutSetColor>::Call(L);
#else
      return WrapFunc4<CInt, Float, Float, Float >::Call(L, glutSetColor);
#endif
    }
    
    static int lua_glutGetColor(lua_State *L) {
      CHECK_ARG_COUNT(L, 2);
      CInt ndx(L, 1);
      CInt comp(L, 2);
      GLfloat r = glutGetColor(ndx, comp);
      lua_pushnumber(L, r);
      return 1;
    }
    
    static int lua_glutCopyColormap(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<CInt, glutCopyColormap>::Call(L);
#else
      return WrapFunc1<CInt >::Call(L, glutCopyColormap);
#endif
    }
    
    static int lua_glutGet(lua_State *L) {
      int r = glutGet((GLenum) lua_tointeger(L, 1));
      lua_pushinteger(L, r);
      return 1;
    }
    
    static int lua_glutDeviceGet(lua_State *L) {
      int r = glutDeviceGet((GLenum) lua_tointeger(L, 1));
      lua_pushinteger(L, r);
      return 1;
    }
    
    static int lua_glutExtensionSupported(lua_State *L) {
      int r = glutExtensionSupported(lua_tostring(L, 1));
      lua_pushinteger(L, r);
      return 1;
    }
    
    static int lua_glutGetModifiers(lua_State *L) {
      int r = glutGetModifiers();
      lua_pushinteger(L, r);
      return 1;
    }
    
    static int lua_glutLayerGet(lua_State *L) {
      int r = glutLayerGet((GLenum) lua_tointeger(L, 1));
      lua_pushinteger(L, r);
      return 1;
    }
    
    static int lua_glutBitmapCharacter(lua_State *L) {
      void *font = lua_touserdata(L, 1);
      int character = (int) lua_tointeger(L, 2);
      glutBitmapCharacter(font, character);
      return 0;
    }
    
    static int lua_glutBitmapWidth(lua_State *L) {
      void *font = lua_touserdata(L, 1);
      int character = (int) lua_tointeger(L, 2);
      int r = glutBitmapWidth(font, character);
      lua_pushinteger(L, r);
      return 1;
    }
    
    static int lua_glutStrokeCharacter(lua_State *L) {
      void *font = lua_touserdata(L, 1);
      int character = (int) lua_tointeger(L, 2);
      glutStrokeCharacter(font, character);
      return 0;
    }
    
    static int lua_glutStrokeWidth(lua_State *L) {
      CHECK_ARG_COUNT(L, 2);
      void *font = lua_touserdata(L, 1);
      int character = (int) lua_tointeger(L, 2);
      int r = glutStrokeWidth(font, character);
      lua_pushinteger(L, r);
      return 1;
    }
    
    static int lua_glutBitmapLength(lua_State *L) {
      CHECK_ARG_COUNT(L, 2);
      void *font = lua_touserdata(L, 1);
      const char *str = lua_tostring(L, 2);
      int r = glutBitmapLength(font, (const unsigned char*)str);
      lua_pushinteger(L, r);
      return 1;
    }
    
    static int lua_glutStrokeLength(lua_State *L) {
      CHECK_ARG_COUNT(L, 2);
      void *font = lua_touserdata(L, 1);
      const char *str = lua_tostring(L, 2);
      int r = glutStrokeLength(font, (const unsigned char*)str);
      lua_pushinteger(L, r);
      return 1;
    }

    static int lua_glutWireSphere(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc3<Double, Int, Int, glutWireSphere>::Call(L);
#else
      return WrapFunc3<Double, Int, Int >::Call(L, glutWireSphere);
#endif
    }
    
    static int lua_glutSolidSphere(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc3<Double, Int, Int, glutSolidSphere>::Call(L);
#else
      return WrapFunc3<Double, Int, Int >::Call(L, glutSolidSphere);
#endif
    }
    
    static int lua_glutWireCone(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc4<Double, Double, Int, Int, glutWireCone>::Call(L);
#else
      return WrapFunc4<Double, Double, Int, Int >::Call(L, glutWireCone);
#endif
    }
    
    static int lua_glutSolidCone(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc4<Double, Double, Int, Int, glutSolidCone>::Call(L);
#else
      return WrapFunc4<Double, Double, Int, Int >::Call(L, glutSolidCone);
#endif
    }
    
    static int lua_glutWireCube(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<Double, glutWireCube>::Call(L);
#else
      return WrapFunc1<Double >::Call(L, glutWireCube);
#endif
    }
    
    static int lua_glutSolidCube(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<Double, glutSolidCube>::Call(L);
#else
      return WrapFunc1<Double >::Call(L, glutSolidCube);
#endif
    }
    
    static int lua_glutWireTorus(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc4<Double, Double, Int, Int, glutWireTorus>::Call(L);
#else
      return WrapFunc4<Double, Double, Int, Int >::Call(L, glutWireTorus);
#endif
    }
    
    static int lua_glutSolidTorus(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc4<Double, Double, Int, Int, glutSolidTorus>::Call(L);
#else
      return WrapFunc4<Double, Double, Int, Int >::Call(L, glutSolidTorus);
#endif
    }
    
    static int lua_glutWireDodecahedron(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutWireDodecahedron>::Call(L);
#else
      return WrapFunc0::Call(L, glutWireDodecahedron);
#endif
    }
    
    static int lua_glutSolidDodecahedron(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutSolidDodecahedron>::Call(L);
#else
      return WrapFunc0::Call(L, glutSolidDodecahedron);
#endif
    }
    
    static int lua_glutWireTeapot(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<Double, glutWireTeapot>::Call(L);
#else
      return WrapFunc1<Double >::Call(L, glutWireTeapot);
#endif
    }
    
    static int lua_glutSolidTeapot(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<Double, glutSolidTeapot>::Call(L);
#else
      return WrapFunc1<Double >::Call(L, glutSolidTeapot);
#endif
    }
    
    static int lua_glutWireOctahedron(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutWireOctahedron>::Call(L);
#else
      return WrapFunc0::Call(L, glutWireOctahedron);
#endif
    }
    
    static int lua_glutSolidOctahedron(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutSolidOctahedron>::Call(L);
#else
      return WrapFunc0::Call(L, glutSolidOctahedron);
#endif
    }
    
    static int lua_glutWireTetrahedron(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutWireTetrahedron>::Call(L);
#else
      return WrapFunc0::Call(L, glutWireTetrahedron);
#endif
    }
    
    static int lua_glutSolidTetrahedron(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutSolidTetrahedron>::Call(L);
#else
      return WrapFunc0::Call(L, glutSolidTetrahedron);
#endif
    }
    
    static int lua_glutWireIcosahedron(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutWireIcosahedron>::Call(L);
#else
      return WrapFunc0::Call(L, glutWireIcosahedron);
#endif
    }
    
    static int lua_glutSolidIcosahedron(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutSolidIcosahedron>::Call(L);
#else
      return WrapFunc0::Call(L, glutSolidIcosahedron);
#endif
    }
    
    static int lua_glutVideoResizeGet(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      Enum param(L, 1);
      int r = glutVideoResizeGet(param);
      lua_pushinteger(L, r);
      return 1;
    }
    
    static int lua_glutSetupVideoResizing(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutSetupVideoResizing>::Call(L);
#else
      return WrapFunc0::Call(L, glutSetupVideoResizing);
#endif
    }
    
    static int lua_glutStopVideoResizing(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutStopVideoResizing>::Call(L);
#else
      return WrapFunc0::Call(L, glutStopVideoResizing);
#endif
    }
    
    static int lua_glutVideoResize(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc4<CInt, CInt, CInt, CInt, glutVideoResize>::Call(L);
#else
      return WrapFunc4<CInt, CInt, CInt, CInt >::Call(L, glutVideoResize);
#endif
    }
    
    static int lua_glutVideoPan(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc4<CInt, CInt, CInt, CInt, glutVideoPan>::Call(L);
#else
      return WrapFunc4<CInt, CInt, CInt, CInt >::Call(L, glutVideoPan);
#endif
    }
    
    static int lua_glutReportErrors(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutReportErrors>::Call(L);
#else
      return WrapFunc0::Call(L, glutReportErrors);
#endif
    }

    static int lua_glutIgnoreKeyRepeat(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<CInt, glutIgnoreKeyRepeat>::Call(L);
#else
      return WrapFunc1<CInt >::Call(L, glutIgnoreKeyRepeat);
#endif
    }
    
    static int lua_glutSetKeyRepeat(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<CInt, glutSetKeyRepeat>::Call(L);
#else
      return WrapFunc1<CInt >::Call(L, glutSetKeyRepeat);
#endif
    }
    
    static int lua_glutForceJoystickFunc(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutForceJoystickFunc>::Call(L);
#else
      return WrapFunc0::Call(L, glutForceJoystickFunc);
#endif
    }

    static int lua_glutGameModeString(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<String, glutGameModeString>::Call(L);
#else
      return WrapFunc1<String >::Call(L, glutGameModeString);
#endif
    }
    
    static int lua_glutEnterGameMode(lua_State *L) {
      CHECK_ARG_COUNT(L, 0);
      int i = glutEnterGameMode();
      lua_pushinteger(L, i);
      return 1;
    }
    
    static int lua_glutLeaveGameMode(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc0<glutLeaveGameMode>::Call(L);
#else
      return WrapFunc0::Call(L, glutLeaveGameMode);
#endif
    }
    
    static int lua_glutGameModeGet(lua_State *L) {
      CHECK_ARG_COUNT(L, 0);
      int i = glutGameModeGet((GLenum) lua_tointeger(L, 1));
      lua_pushinteger(L, i);
      return 1;
    }
    

    void fillFunctions(lua_State *L, int table) {

#define GLUT_FUNCTION(name) \
      lua_pushcfunction(L, &LuaGLUT::lua_glut##name);\
      lua_setfield(L, table, #name)

      GLUT_FUNCTION(Init);
      GLUT_FUNCTION(InitDisplayMode);
      GLUT_FUNCTION(InitDisplayString);
      GLUT_FUNCTION(InitWindowPosition);
      GLUT_FUNCTION(InitWindowSize);
      GLUT_FUNCTION(MainLoop);
      GLUT_FUNCTION(CreateWindow);
      GLUT_FUNCTION(CreateSubWindow);
      GLUT_FUNCTION(DestroyWindow);
      GLUT_FUNCTION(PostRedisplay);
      GLUT_FUNCTION(PostWindowRedisplay);
      GLUT_FUNCTION(SwapBuffers);
      GLUT_FUNCTION(GetWindow);
      GLUT_FUNCTION(SetWindow);
      GLUT_FUNCTION(SetWindowTitle);
      GLUT_FUNCTION(SetIconTitle);
      GLUT_FUNCTION(PositionWindow);
      GLUT_FUNCTION(ReshapeWindow);
      GLUT_FUNCTION(PopWindow);
      GLUT_FUNCTION(PushWindow);
      GLUT_FUNCTION(IconifyWindow);
      GLUT_FUNCTION(ShowWindow);
      GLUT_FUNCTION(HideWindow);
      GLUT_FUNCTION(FullScreen);
      GLUT_FUNCTION(SetCursor);
      GLUT_FUNCTION(WarpPointer);
      GLUT_FUNCTION(EstablishOverlay);
      GLUT_FUNCTION(RemoveOverlay);
      GLUT_FUNCTION(UseLayer);
      GLUT_FUNCTION(PostOverlayRedisplay);
      GLUT_FUNCTION(PostWindowOverlayRedisplay);
      GLUT_FUNCTION(ShowOverlay);
      GLUT_FUNCTION(HideOverlay);
      GLUT_FUNCTION(CreateMenu);
      GLUT_FUNCTION(DestroyMenu);
      GLUT_FUNCTION(GetMenu);
      GLUT_FUNCTION(SetMenu);
      GLUT_FUNCTION(AddMenuEntry);
      GLUT_FUNCTION(AddSubMenu);
      GLUT_FUNCTION(ChangeToMenuEntry);
      GLUT_FUNCTION(ChangeToSubMenu);
      GLUT_FUNCTION(RemoveMenuItem);
      GLUT_FUNCTION(AttachMenu);
      GLUT_FUNCTION(DetachMenu);
      GLUT_FUNCTION(DisplayFunc);
      GLUT_FUNCTION(ReshapeFunc);
      GLUT_FUNCTION(KeyboardFunc);
      GLUT_FUNCTION(MouseFunc);
      GLUT_FUNCTION(MotionFunc);
      GLUT_FUNCTION(PassiveMotionFunc);
      GLUT_FUNCTION(EntryFunc);
      GLUT_FUNCTION(VisibilityFunc);
      GLUT_FUNCTION(SpecialFunc);
      GLUT_FUNCTION(SpaceballMotionFunc);
      GLUT_FUNCTION(SpaceballRotateFunc);
      GLUT_FUNCTION(SpaceballButtonFunc);
      GLUT_FUNCTION(ButtonBoxFunc);
      GLUT_FUNCTION(DialsFunc);
      GLUT_FUNCTION(TabletMotionFunc);
      GLUT_FUNCTION(TabletButtonFunc);
      GLUT_FUNCTION(OverlayDisplayFunc);
      GLUT_FUNCTION(WindowStatusFunc);
      GLUT_FUNCTION(KeyboardUpFunc);
      GLUT_FUNCTION(SpecialUpFunc);
      GLUT_FUNCTION(JoystickFunc);
      GLUT_FUNCTION(IdleFunc);
      GLUT_FUNCTION(TimerFunc);
      GLUT_FUNCTION(MenuStatusFunc);
      GLUT_FUNCTION(SetColor);
      GLUT_FUNCTION(GetColor);
      GLUT_FUNCTION(CopyColormap);
      GLUT_FUNCTION(Get);
      GLUT_FUNCTION(DeviceGet);
      GLUT_FUNCTION(ExtensionSupported);
      GLUT_FUNCTION(GetModifiers);
      GLUT_FUNCTION(LayerGet);
      GLUT_FUNCTION(BitmapCharacter);
      GLUT_FUNCTION(BitmapWidth);
      GLUT_FUNCTION(BitmapLength);
      GLUT_FUNCTION(StrokeCharacter);
      GLUT_FUNCTION(StrokeWidth);
      GLUT_FUNCTION(StrokeLength);
      GLUT_FUNCTION(WireSphere);
      GLUT_FUNCTION(SolidSphere);
      GLUT_FUNCTION(WireCone);
      GLUT_FUNCTION(SolidCone);
      GLUT_FUNCTION(WireCube);
      GLUT_FUNCTION(SolidCube);
      GLUT_FUNCTION(WireTorus);
      GLUT_FUNCTION(SolidTorus);
      GLUT_FUNCTION(WireDodecahedron);
      GLUT_FUNCTION(SolidDodecahedron);
      GLUT_FUNCTION(WireTeapot);
      GLUT_FUNCTION(SolidTeapot);
      GLUT_FUNCTION(WireOctahedron);
      GLUT_FUNCTION(SolidOctahedron);
      GLUT_FUNCTION(WireTetrahedron);
      GLUT_FUNCTION(SolidTetrahedron);
      GLUT_FUNCTION(WireIcosahedron);
      GLUT_FUNCTION(SolidIcosahedron);
      GLUT_FUNCTION(VideoResizeGet);
      GLUT_FUNCTION(SetupVideoResizing);
      GLUT_FUNCTION(StopVideoResizing);
      GLUT_FUNCTION(VideoResize);
      GLUT_FUNCTION(VideoPan);
      GLUT_FUNCTION(ReportErrors);
      GLUT_FUNCTION(GameModeString);
      GLUT_FUNCTION(EnterGameMode);
      GLUT_FUNCTION(LeaveGameMode);
      GLUT_FUNCTION(GameModeGet);
      
#undef GLUT_FUNCTION
    }

  protected:

    void initDefines() {

      // use GLUT_API_VERSION 3
      
      mIConstants["RGB"] = GLUT_RGB;
      mIConstants["RGBA"] = GLUT_RGBA;
      mIConstants["INDEX"] = GLUT_INDEX;
      mIConstants["SINGLE"] = GLUT_SINGLE;
      mIConstants["DOUBLE"] = GLUT_DOUBLE;
      mIConstants["ACCUM"] = GLUT_ACCUM;
      mIConstants["ALPHA"] = GLUT_ALPHA;
      mIConstants["DEPTH"] = GLUT_DEPTH;
      mIConstants["STENCIL"] = GLUT_STENCIL;
      mIConstants["MULTISAMPLE"] = GLUT_MULTISAMPLE;
      mIConstants["STEREO"] = GLUT_STEREO;
      mIConstants["LUMINANCE"] = GLUT_LUMINANCE;
      mIConstants["LEFT_BUTTON"] = GLUT_LEFT_BUTTON;
      mIConstants["MIDDLE_BUTTON"] = GLUT_MIDDLE_BUTTON;
      mIConstants["RIGHT_BUTTON"] = GLUT_RIGHT_BUTTON;
      mIConstants["DOWN"] = GLUT_DOWN;
      mIConstants["UP"] = GLUT_UP;
      mIConstants["KEY_F1"] = GLUT_KEY_F1;
      mIConstants["KEY_F2"] = GLUT_KEY_F2;
      mIConstants["KEY_F3"] = GLUT_KEY_F3;
      mIConstants["KEY_F4"] = GLUT_KEY_F4;
      mIConstants["KEY_F5"] = GLUT_KEY_F5;
      mIConstants["KEY_F6"] = GLUT_KEY_F6;
      mIConstants["KEY_F7"] = GLUT_KEY_F7;
      mIConstants["KEY_F8"] = GLUT_KEY_F8;
      mIConstants["KEY_F9"] = GLUT_KEY_F9;
      mIConstants["KEY_F10"] = GLUT_KEY_F10;
      mIConstants["KEY_F11"] = GLUT_KEY_F11;
      mIConstants["KEY_F12"] = GLUT_KEY_F12;
      mIConstants["KEY_LEFT"] = GLUT_KEY_LEFT;
      mIConstants["KEY_UP"] = GLUT_KEY_UP;
      mIConstants["KEY_RIGHT"] = GLUT_KEY_RIGHT;
      mIConstants["KEY_DOWN"] = GLUT_KEY_DOWN;
      mIConstants["KEY_PAGE_UP"] = GLUT_KEY_PAGE_UP;
      mIConstants["KEY_PAGE_DOWN"] = GLUT_KEY_PAGE_DOWN;
      mIConstants["KEY_HOME"] = GLUT_KEY_HOME;
      mIConstants["KEY_END"] = GLUT_KEY_END;
      mIConstants["KEY_INSERT"] = GLUT_KEY_INSERT;
      mIConstants["LEFT"] = GLUT_LEFT;
      mIConstants["ENTERED"] = GLUT_ENTERED;
      mIConstants["MENU_NOT_IN_USE"] = GLUT_MENU_NOT_IN_USE;
      mIConstants["MENU_IN_USE"] = GLUT_MENU_IN_USE;
      mIConstants["NOT_VISIBLE"] = GLUT_NOT_VISIBLE;
      mIConstants["VISIBLE"] = GLUT_VISIBLE;
      mIConstants["HIDDEN"] = GLUT_HIDDEN;
      mIConstants["FULLY_RETAINED"] = GLUT_FULLY_RETAINED;
      mIConstants["PARTIALLY_RETAINED"] = GLUT_PARTIALLY_RETAINED;
      mIConstants["FULLY_COVERED"] = GLUT_FULLY_COVERED;
      mIConstants["RED"] = GLUT_RED;
      mIConstants["GREEN"] = GLUT_GREEN;
      mIConstants["BLUE"] = GLUT_BLUE;
      
      mPConstants["STROKE_ROMAN"] = GLUT_STROKE_ROMAN;
      mPConstants["STROKE_MONO_ROMAN"] = GLUT_STROKE_MONO_ROMAN;
      mPConstants["BITMAP_9_BY_15"] = GLUT_BITMAP_9_BY_15;
      mPConstants["BITMAP_8_BY_13"] = GLUT_BITMAP_8_BY_13;
      mPConstants["BITMAP_TIMES_ROMAN_10"] = GLUT_BITMAP_TIMES_ROMAN_10;
      mPConstants["BITMAP_TIMES_ROMAN_24"] = GLUT_BITMAP_TIMES_ROMAN_24;
      mPConstants["BITMAP_HELVETICA_10"] = GLUT_BITMAP_HELVETICA_10;
      mPConstants["BITMAP_HELVETICA_12"] = GLUT_BITMAP_HELVETICA_12;
      mPConstants["BITMAP_HELVETICA_18"] = GLUT_BITMAP_HELVETICA_18;
      
      mEConstants["WINDOW_X"] = GLUT_WINDOW_X;
      mEConstants["WINDOW_Y"] = GLUT_WINDOW_Y;
      mEConstants["WINDOW_WIDTH"] = GLUT_WINDOW_WIDTH;
      mEConstants["WINDOW_HEIGHT"] = GLUT_WINDOW_HEIGHT;
      mEConstants["WINDOW_BUFFER_SIZE"] = GLUT_WINDOW_BUFFER_SIZE;
      mEConstants["WINDOW_STENCIL_SIZE"] = GLUT_WINDOW_STENCIL_SIZE;
      mEConstants["WINDOW_DEPTH_SIZE"] = GLUT_WINDOW_DEPTH_SIZE;
      mEConstants["WINDOW_RED_SIZE"] = GLUT_WINDOW_RED_SIZE;
      mEConstants["WINDOW_GREEN_SIZE"] = GLUT_WINDOW_GREEN_SIZE;
      mEConstants["WINDOW_BLUE_SIZE"] = GLUT_WINDOW_BLUE_SIZE;
      mEConstants["WINDOW_ALPHA_SIZE"] = GLUT_WINDOW_ALPHA_SIZE;
      mEConstants["WINDOW_ACCUM_RED_SIZE"] = GLUT_WINDOW_ACCUM_RED_SIZE;
      mEConstants["WINDOW_ACCUM_GREEN_SIZE"] = GLUT_WINDOW_ACCUM_GREEN_SIZE;
      mEConstants["WINDOW_ACCUM_BLUE_SIZE"] = GLUT_WINDOW_ACCUM_BLUE_SIZE;
      mEConstants["WINDOW_ACCUM_ALPHA_SIZE"] = GLUT_WINDOW_ACCUM_ALPHA_SIZE;
      mEConstants["WINDOW_DOUBLEBUFFER"] = GLUT_WINDOW_DOUBLEBUFFER;
      mEConstants["WINDOW_RGBA"] = GLUT_WINDOW_RGBA;
      mEConstants["WINDOW_PARENT"] = GLUT_WINDOW_PARENT;
      mEConstants["WINDOW_NUM_CHILDREN"] = GLUT_WINDOW_NUM_CHILDREN;
      mEConstants["WINDOW_COLORMAP_SIZE"] = GLUT_WINDOW_COLORMAP_SIZE;      
      mEConstants["WINDOW_NUM_SAMPLES"] = GLUT_WINDOW_NUM_SAMPLES;
      mEConstants["WINDOW_STEREO"] = GLUT_WINDOW_STEREO;
      mEConstants["WINDOW_CURSOR"] = GLUT_WINDOW_CURSOR;
      mEConstants["SCREEN_WIDTH"] = GLUT_SCREEN_WIDTH;
      mEConstants["SCREEN_HEIGHT"] = GLUT_SCREEN_HEIGHT;
      mEConstants["SCREEN_WIDTH_MM"] = GLUT_SCREEN_WIDTH_MM;
      mEConstants["SCREEN_HEIGHT_MM"] = GLUT_SCREEN_HEIGHT_MM;
      mEConstants["MENU_NUM_ITEMS"] = GLUT_MENU_NUM_ITEMS;
      mEConstants["DISPLAY_MODE_POSSIBLE"] = GLUT_DISPLAY_MODE_POSSIBLE;
      mEConstants["INIT_WINDOW_X"] = GLUT_INIT_WINDOW_X;
      mEConstants["INIT_WINDOW_Y"] = GLUT_INIT_WINDOW_Y;
      mEConstants["INIT_WINDOW_WIDTH"] = GLUT_INIT_WINDOW_WIDTH;
      mEConstants["INIT_WINDOW_HEIGHT"] = GLUT_INIT_WINDOW_HEIGHT;
      mEConstants["INIT_DISPLAY_MODE"] = GLUT_INIT_DISPLAY_MODE;
      mEConstants["ELAPSED_TIME"] = GLUT_ELAPSED_TIME;
      mEConstants["WINDOW_FORMAT_ID"] = GLUT_WINDOW_FORMAT_ID;
      mEConstants["HAS_KEYBOARD"] = GLUT_HAS_KEYBOARD;
      mEConstants["HAS_MOUSE"] = GLUT_HAS_MOUSE;
      mEConstants["HAS_SPACEBALL"] = GLUT_HAS_SPACEBALL;
      mEConstants["HAS_DIAL_AND_BUTTON_BOX"] = GLUT_HAS_DIAL_AND_BUTTON_BOX;
      mEConstants["HAS_TABLET"] = GLUT_HAS_TABLET;
      mEConstants["NUM_MOUSE_BUTTONS"] = GLUT_NUM_MOUSE_BUTTONS;
      mEConstants["NUM_SPACEBALL_BUTTONS"] = GLUT_NUM_SPACEBALL_BUTTONS;
      mEConstants["NUM_BUTTON_BOX_BUTTONS"] = GLUT_NUM_BUTTON_BOX_BUTTONS;
      mEConstants["NUM_DIALS"] = GLUT_NUM_DIALS;
      mEConstants["NUM_TABLET_BUTTONS"] = GLUT_NUM_TABLET_BUTTONS;
      mEConstants["DEVICE_IGNORE_KEY_REPEAT"] = GLUT_DEVICE_IGNORE_KEY_REPEAT;
      mEConstants["DEVICE_KEY_REPEAT"] = GLUT_DEVICE_KEY_REPEAT;
      mEConstants["HAS_JOYSTICK"] = GLUT_HAS_JOYSTICK;
      mEConstants["OWNS_JOYSTICK"] = GLUT_OWNS_JOYSTICK;
      mEConstants["JOYSTICK_BUTTONS"] = GLUT_JOYSTICK_BUTTONS;
      mEConstants["JOYSTICK_AXES"] = GLUT_JOYSTICK_AXES;
      mEConstants["JOYSTICK_POLL_RATE"] = GLUT_JOYSTICK_POLL_RATE;
      mEConstants["OVERLAY_POSSIBLE"] = GLUT_OVERLAY_POSSIBLE;
      mEConstants["LAYER_IN_USE"] = GLUT_LAYER_IN_USE;
      mEConstants["HAS_OVERLAY"] = GLUT_HAS_OVERLAY;
      mEConstants["TRANSPARENT_INDEX"] = GLUT_TRANSPARENT_INDEX;
      mEConstants["NORMAL_DAMAGED"] = GLUT_NORMAL_DAMAGED;
      mEConstants["OVERLAY_DAMAGED"] = GLUT_OVERLAY_DAMAGED;
      mEConstants["VIDEO_RESIZE_POSSIBLE"] = GLUT_VIDEO_RESIZE_POSSIBLE;
      mEConstants["VIDEO_RESIZE_IN_USE"] = GLUT_VIDEO_RESIZE_IN_USE;
      mEConstants["VIDEO_RESIZE_X_DELTA"] = GLUT_VIDEO_RESIZE_X_DELTA;
      mEConstants["VIDEO_RESIZE_Y_DELTA"] = GLUT_VIDEO_RESIZE_Y_DELTA;
      mEConstants["VIDEO_RESIZE_WIDTH_DELTA"] = GLUT_VIDEO_RESIZE_WIDTH_DELTA;
      mEConstants["VIDEO_RESIZE_HEIGHT_DELTA"] = GLUT_VIDEO_RESIZE_HEIGHT_DELTA;
      mEConstants["VIDEO_RESIZE_X"] = GLUT_VIDEO_RESIZE_X;
      mEConstants["VIDEO_RESIZE_Y"] = GLUT_VIDEO_RESIZE_Y;
      mEConstants["VIDEO_RESIZE_WIDTH"] = GLUT_VIDEO_RESIZE_WIDTH;
      mEConstants["VIDEO_RESIZE_HEIGHT"] = GLUT_VIDEO_RESIZE_HEIGHT;
      mEConstants["NORMAL"] = GLUT_NORMAL;
      mEConstants["OVERLAY"] = GLUT_OVERLAY;

      mIConstants["ACTIVE_SHIFT"] = GLUT_ACTIVE_SHIFT;
      mIConstants["ACTIVE_CTRL"] = GLUT_ACTIVE_CTRL;
      mIConstants["ACTIVE_ALT"] = GLUT_ACTIVE_ALT;
      mIConstants["CURSOR_RIGHT_ARROW"] = GLUT_CURSOR_RIGHT_ARROW;
      mIConstants["CURSOR_LEFT_ARROW"] = GLUT_CURSOR_LEFT_ARROW;
      mIConstants["CURSOR_INFO"] = GLUT_CURSOR_INFO;
      mIConstants["CURSOR_DESTROY"] = GLUT_CURSOR_DESTROY;
      mIConstants["CURSOR_HELP"] = GLUT_CURSOR_HELP;
      mIConstants["CURSOR_CYCLE"] = GLUT_CURSOR_CYCLE;
      mIConstants["CURSOR_SPRAY"] = GLUT_CURSOR_SPRAY;
      mIConstants["CURSOR_WAIT"] = GLUT_CURSOR_WAIT;
      mIConstants["CURSOR_TEXT"] = GLUT_CURSOR_TEXT;
      mIConstants["CURSOR_CROSSHAIR"] = GLUT_CURSOR_CROSSHAIR;
      mIConstants["CURSOR_UP_DOWN"] = GLUT_CURSOR_UP_DOWN;
      mIConstants["CURSOR_LEFT_RIGHT"] = GLUT_CURSOR_LEFT_RIGHT;
      mIConstants["CURSOR_TOP_SIDE"] = GLUT_CURSOR_TOP_SIDE;
      mIConstants["CURSOR_BOTTOM_SIDE"] = GLUT_CURSOR_BOTTOM_SIDE;
      mIConstants["CURSOR_LEFT_SIDE"] = GLUT_CURSOR_LEFT_SIDE;
      mIConstants["CURSOR_RIGHT_SIDE"] = GLUT_CURSOR_RIGHT_SIDE;
      mIConstants["CURSOR_TOP_LEFT_CORNER"] = GLUT_CURSOR_TOP_LEFT_CORNER;
      mIConstants["CURSOR_TOP_RIGHT_CORNER"] = GLUT_CURSOR_TOP_RIGHT_CORNER;
      mIConstants["CURSOR_BOTTOM_RIGHT_CORNER"] = GLUT_CURSOR_BOTTOM_RIGHT_CORNER;
      mIConstants["CURSOR_BOTTOM_LEFT_CORNER"] = GLUT_CURSOR_BOTTOM_LEFT_CORNER;
      mIConstants["CURSOR_INHERIT"] = GLUT_CURSOR_INHERIT;
      mIConstants["CURSOR_NONE"] = GLUT_CURSOR_NONE;
      mIConstants["CURSOR_FULL_CROSSHAIR"] = GLUT_CURSOR_FULL_CROSSHAIR;
      mIConstants["KEY_REPEAT_OFF"] = GLUT_KEY_REPEAT_OFF;
      mIConstants["KEY_REPEAT_ON"] = GLUT_KEY_REPEAT_ON;
      mIConstants["KEY_REPEAT_DEFAULT"] = GLUT_KEY_REPEAT_DEFAULT;
      mIConstants["JOYSTICK_BUTTON_A"] = GLUT_JOYSTICK_BUTTON_A;
      mIConstants["JOYSTICK_BUTTON_B"] = GLUT_JOYSTICK_BUTTON_B;
      mIConstants["JOYSTICK_BUTTON_C"] = GLUT_JOYSTICK_BUTTON_C;
      mIConstants["JOYSTICK_BUTTON_D"] = GLUT_JOYSTICK_BUTTON_D;
      mEConstants["GAME_MODE_ACTIVE"] = GLUT_GAME_MODE_ACTIVE;
      mEConstants["GAME_MODE_POSSIBLE"] = GLUT_GAME_MODE_POSSIBLE;
      mEConstants["GAME_MODE_WIDTH"] = GLUT_GAME_MODE_WIDTH;
      mEConstants["GAME_MODE_HEIGHT"] = GLUT_GAME_MODE_HEIGHT;
      mEConstants["GAME_MODE_PIXEL_DEPTH"] = GLUT_GAME_MODE_PIXEL_DEPTH;
      mEConstants["GAME_MODE_REFRESH_RATE"] = GLUT_GAME_MODE_REFRESH_RATE;
      mEConstants["GAME_MODE_DISPLAY_CHANGED"] = GLUT_GAME_MODE_DISPLAY_CHANGED;
    }
    
  protected:
    
    std::map<int, std::string> mMenuCallbacks;
    std::map<int, std::string> mTimerCallbacks;
    std::map<int, WindowCallbacks> mWinCallbacks;
    lua_State *mState;
    
    std::map<std::string, unsigned int> mIConstants;
    std::map<std::string, void*> mPConstants;
    std::map<std::string, GLenum> mEConstants;
};


int LuaGLUT::REG_KEY = 0;
unsigned int LuaGLUT::INTEGER_ERROR = (unsigned int)-1;
GLenum LuaGLUT::ENUM_ERROR = (GLenum)-2;
void* LuaGLUT::PTR_ERROR = (void*)-1;
LuaGLUT* LuaGLUT::msInstance = 0;

// ---

EXPORT int luaopen_luagl_glut(lua_State *L) {
  
  // create a userdata named GL
  
  void *ud = lua_newuserdata(L, sizeof(LuaGLUT));  // +1 (1)
  new (ud) LuaGLUT(L);
  int module = lua_gettop(L);
  
  lua_newtable(L); // +1 (2)
  int metatable = lua_gettop(L);
  
  ((LuaGLUT*)ud)->fillFunctions(L, metatable);
  
  lua_pushvalue(L, metatable); // +1 (3)
  lua_setfield(L, metatable, "__index"); // -1 (2)
  
  lua_pushcfunction(L, &LuaGLUT::lua__newindex); // +1 (3)
  lua_setfield(L, metatable, "__newindex"); // -1 (2)
  
  lua_pushcfunction(L, &LuaGLUT::lua__gc); // +1 (3)
  lua_setfield(L, metatable, "__gc"); // -1 (2)
  
  lua_pushvalue(L, metatable); // +1 (3)
  lua_setfield(L, metatable, "__metatable"); // -1 (2)
  
  lua_newtable(L); // +1 (3)
  int metametatable = lua_gettop(L);
  lua_pushcfunction(L, &LuaGLUT::lua__index); // +1 (4)
  lua_setfield(L, metametatable, "__index"); // -1 (3)
  lua_setmetatable(L, metatable); // -1 (2)
  
  lua_pushvalue(L, metatable); // +1 (3)
  lua_setmetatable(L, module); // -1 (2)
  
  lua_pushvalue(L, module); // +1 (3)
  lua_setfield(L, LUA_GLOBALSINDEX, "glut"); // -1 (2)

  lua_pushlightuserdata(L, (void*)&LuaGLUT::REG_KEY); // +1 (3)
  lua_pushvalue(L, metatable); // +1 (4)
  lua_settable(L, LUA_REGISTRYINDEX); // -2 (2)

  lua_pushvalue(L, module); // set module on top
  
  return 1;
}

