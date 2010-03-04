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

class LuaGLU {
  public:
    
    static int REG_KEY;
    static GLenum ENUM_ERROR;

  public:
    
    LuaGLU(lua_State *L)
      :mQuadric(0), mTess(0), mNURBS(0), mState(L) {
      assert(msInstance == 0);
      msInstance = this;
      initConstants();
    }
    
    ~LuaGLU() {
      msInstance = 0;
    }
    
    inline lua_State* State() {
      return mState;
    }
    
    inline GLenum getConstant(const std::string &str) {
      std::map<std::string, GLenum>::iterator it = mConstants.find(str);
      if (it != mConstants.end()) {
        return it->second;
      } else {
        return ENUM_ERROR;
      }
    }

  public:
    
    inline static LuaGLU& Instance() {
      assert(msInstance != 0);
      return *msInstance;
    }

  public: // GLU callbacks
    
    // Quadrics
    static void CALLBACK lua_gluQuadricErrorProc(GLenum e) {
      const char *fn = Instance().getCurrentQuadricCallback();
      if (fn) {
        lua_State *L = Instance().State();
        lua_getfield(L, LUA_GLOBALSINDEX, "glu");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fn);
        lua_pushinteger(L, e);
        lua_call(L, 1, 0);
        lua_pop(L, 2);
      }
    }
    // Nurbs
#ifdef GLU_VERSION_1_3
    static void CALLBACK lua_gluNurbsBeginProc(GLenum e, void *ud) {
      const char *fn = Instance().getCurrentNurbsBeginCallback();
      if (fn) {
        lua_State *L = Instance().State();
        lua_getfield(L, LUA_GLOBALSINDEX, "glu");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fn);
        lua_pushinteger(L, e);
        Instance().getNurbsData(L, ud);
        lua_call(L, 2, 0);
        lua_pop(L, 2);
      }
    }
    static void CALLBACK lua_gluNurbsVertexProc(GLfloat *v, void *ud) {
      const char *fn = Instance().getCurrentNurbsVertexCallback();
      if (fn) {
        lua_State *L = Instance().State();
        lua_getfield(L, LUA_GLOBALSINDEX, "glu");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fn);
        Array1D<Float>(v, 3).toLUA(L);
        Instance().getNurbsData(L, ud);
        lua_call(L, 2, 0);
        lua_pop(L, 2);
      }
    }
    static void CALLBACK lua_gluNurbsNormalProc(GLfloat *n, void *ud) {
      const char *fn = Instance().getCurrentNurbsNormalCallback();
      if (fn) {
        lua_State *L = Instance().State();
        lua_getfield(L, LUA_GLOBALSINDEX, "glu");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fn);
        Array1D<Float>(n, 3).toLUA(L);
        Instance().getNurbsData(L, ud);
        lua_call(L, 2, 0);
        lua_pop(L, 2);
      }
    }
    static void CALLBACK lua_gluNurbsColorProc(GLfloat *c, void *ud) {
      const char *fn = Instance().getCurrentNurbsColorCallback();
      if (fn) {
        lua_State *L = Instance().State();
        lua_getfield(L, LUA_GLOBALSINDEX, "glu");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fn);
        Array1D<Float>(c, 4).toLUA(L);
        Instance().getNurbsData(L, ud);
        lua_call(L, 2, 0);
        lua_pop(L, 2);
      }
    }
    static void CALLBACK lua_gluNurbsTexCoordProc(GLfloat *t, void *ud) {
      const char *fn = Instance().getCurrentNurbsTexCoordCallback();
      if (fn) {
        lua_State *L = Instance().State();
        lua_getfield(L, LUA_GLOBALSINDEX, "glu");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fn);
        int n = Instance().getNurbsTexCoordDim(ud);
        Array1D<Float>(t, n).toLUA(L);
        Instance().getNurbsData(L, ud);
        lua_call(L, 2, 0);
        lua_pop(L, 2);
      }
    }
    static void CALLBACK lua_gluNurbsEndProc(void *ud) {
      const char *fn = Instance().getCurrentNurbsEndCallback();
      if (fn) {
        lua_State *L = Instance().State();
        lua_getfield(L, LUA_GLOBALSINDEX, "glu");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fn);
        Instance().getNurbsData(L, ud);
        lua_call(L, 1, 0);
        lua_pop(L, 2);
      }
    }
#endif
    static void CALLBACK lua_gluNurbsErrorProc(GLenum e) { // no user data
      const char *fn = Instance().getCurrentNurbsErrorCallback();
      if (fn) {
        lua_State *L = Instance().State();
        lua_getfield(L, LUA_GLOBALSINDEX, "glu");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fn);
        lua_pushinteger(L, e);
        lua_call(L, 1, 0);
        lua_pop(L, 2);
      }
    }
    // Tess
    static void CALLBACK lua_gluTessBeginProc(GLenum e, void *ud) {
      lua_State *L = Instance().State();
      const char *fname = Instance().getCurrentTesselatorBeginCallback();
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glu");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushinteger(L, e);
        Instance().getTesselatorPolygonData(L, ud);
        lua_call(L, 2, 0);
        lua_pop(L, 2);
      }
    }
    static void CALLBACK lua_gluTessEndProc(void *ud) {
      lua_State *L = Instance().State();
      const char *fname = Instance().getCurrentTesselatorEndCallback();
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glu");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        Instance().getTesselatorPolygonData(L, ud);
        lua_call(L, 1, 0);
        lua_pop(L, 2);
      }
    }
    static void CALLBACK lua_gluTessEdgeFlagProc(GLboolean b, void *ud) {
      lua_State *L = Instance().State();
      const char *fname = Instance().getCurrentTesselatorEdgeFlagCallback();
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glu");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushboolean(L, b);
        Instance().getTesselatorPolygonData(L, ud);
        lua_call(L, 2, 0);
        lua_pop(L, 2);
      }
    }
    static void CALLBACK lua_gluTessVertexProc(void *vd, void *ud) {
      lua_State *L = Instance().State();
      const char *fname = Instance().getCurrentTesselatorVertexCallback();
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glu");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        Instance().getTessContourVertex(L, vd);
        Instance().getTesselatorPolygonData(L, ud);
        lua_call(L, 2, 0);
        lua_pop(L, 2);
      }
    }
    static void CALLBACK lua_gluTessCombineProc(GLdouble coords[3], void *verts[4],
                                                GLfloat weights[4], void **out, void *ud) {
      lua_State *L = Instance().State();
      const char *fname = Instance().getCurrentTesselatorCombineCallback();
      if (fname) {
        int i;
        // function
        lua_getfield(L, LUA_GLOBALSINDEX, "glu");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        // coords
        Array1D<Double>(coords, 3).toLUA(L);
        // verts
        lua_newtable(L);
        for (i=0; i<4; ++i) {
          lua_pushinteger(L, i+1);
          Instance().getTessContourVertex(L, verts[i]);
          lua_settable(L, -2);
        }
        // weights
        Array1D<Float>(weights, 4).toLUA(L);
        // ud
        Instance().getTesselatorPolygonData(L, ud);
        // call
        lua_call(L, 4, 1);
        // result (it a lua data, just store it in out contour vertex table)
        // it will be passed again to the GLU_TESS_VERTEX callback
        size_t id = Instance().addTessContourVertex(L, -1);
        *out = (void*)id;
        // restore stack to original state
        lua_pop(L, 3);
      }                                   
    }
    static void CALLBACK lua_gluTessErrorProc(GLenum e, void *ud) {
      lua_State *L = Instance().State();
      const char *fname = Instance().getCurrentTesselatorErrorCallback();
      if (fname) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glu");
        lua_getmetatable(L, -1);
        lua_getfield(L, -1, fname);
        lua_pushinteger(L, e);
        Instance().getTesselatorPolygonData(L, ud);
        lua_call(L, 2, 0);
        lua_pop(L, 2);
      }
    }
    
  protected: // Callback data
  
    // Quadric
  
    typedef std::map<void*, std::string> QuadricCallbackMap;
    
    QuadricCallbackMap mQuadricCallbacks;
    void *mQuadric;
    
    // Tess
    
    struct TessCallbacks {
      std::string Begin;
      std::string End;
      std::string EdgeFlag;
      std::string Vertex;
      std::string Combine;
      std::string Error;
      std::string pdata; // for user data passed to gluTessBeginPolygon
    };
    
    typedef std::map<void*, TessCallbacks> TessCallbacksMap;
    
    TessCallbacksMap mTessCallbacks;
    size_t mNumContourVertices;
    void *mTess;
    
    // Nurbs
    
    struct NurbsCallbacks {
      std::string Begin;
      std::string Vertex;
      std::string Normal;
      std::string Color;
      std::string TexCoord;
      std::string End;
      std::string Error;
      std::string data; // for user data passed to gluNurbsCallbackData
      int tdim; // texture coord dimension (check for GL_MAP[1|2]_TEXTURE_COORD_[1|2|3|4])
    };
    
    typedef std::map<void*, NurbsCallbacks> NurbsCallbacksMap;
    
    NurbsCallbacksMap mNurbsCallbacks;
    void *mNURBS;
    
  public: // Callbacks management
    
//#ifdef __APPLE__
//    typedef GLvoid (CALLBACK *GLUcallback)(...);
//#else
    typedef void (CALLBACK *GLUcallback)();
//#endif

    // Quadrics
  
    void addQuadricCallback(lua_State *L, GLUquadric *q, int fn) {
      
      void *key = (void*)q;
      
      QuadricCallbackMap::iterator it = mQuadricCallbacks.find(key);
      
      if (it == mQuadricCallbacks.end()) {
        char fname[64];
        sprintf(fname, "__glu_qerr_%p", key);
        mQuadricCallbacks[key] = std::string(fname);
      }
      
      lua_getfield(L, LUA_GLOBALSINDEX, "glu");
      lua_getmetatable(L, -1);
      lua_pushvalue(L, fn);
      lua_setfield(L, -2, mQuadricCallbacks[key].c_str());
      lua_pop(L, 2);
      
      gluQuadricCallback(q, GLU_ERROR, (GLUcallback)lua_gluQuadricErrorProc);
    }
    
    void delQuadricCallback(lua_State *L, GLUquadric *q) {
      
      void *key = (void*)q;
      
      QuadricCallbackMap::iterator it = mQuadricCallbacks.find(key);
      
      if (it != mQuadricCallbacks.end()) {
        lua_getfield(L, LUA_GLOBALSINDEX, "glu");
        lua_getmetatable(L, -1);
        lua_pushnil(L);
        lua_setfield(L, -2, it->second.c_str());
        lua_pop(L, 2);
        
        mQuadricCallbacks.erase(it);
      }
      
      gluQuadricCallback(q, GLU_ERROR, (GLUcallback)0);
    }
    
    const char* getCurrentQuadricCallback() {
      QuadricCallbackMap::iterator it = mQuadricCallbacks.find(mQuadric);
      if (it != mQuadricCallbacks.end()) {
        if (it->second.length() > 0) {
          return it->second.c_str();
        }
      }
      return 0;
    }
    
    inline void setCurrentQuadric(GLUquadric *q) {
      mQuadric = (void*) q;
    }
    
    // Tess

#define ADD_TESS_CALLBACK(which, cbe)\
    void addTesselator##which##Callback(lua_State *L, GLUtesselator *t, int fn) {\
      void *key = (void*)t;\
      TessCallbacksMap::iterator it = mTessCallbacks.find(key);\
      if (it == mTessCallbacks.end()) {\
        char fname[64];\
        sprintf(fname, "__glu_t%s_%p", #which, key);\
        mTessCallbacks[key].which = std::string(fname);\
      }\
      lua_getfield(L, LUA_GLOBALSINDEX, "glu");\
      lua_getmetatable(L, -1);\
      lua_pushvalue(L, fn);\
      lua_setfield(L, -2, mTessCallbacks[key].which.c_str());\
      lua_pop(L, 2);\
      gluTessCallback(t, cbe, (GLUcallback)lua_gluTess##which##Proc);\
    }

#define DEL_TESS_CALLBACK(which, cbe)\
    void delTesselator##which##Callback(lua_State *L, GLUtesselator *t) {\
      void *key = (void*)t;\
      TessCallbacksMap::iterator it = mTessCallbacks.find(key);\
      if (it != mTessCallbacks.end()) {\
        lua_getfield(L, LUA_GLOBALSINDEX, "glu");\
        lua_getmetatable(L, -1);\
        lua_pushnil(L);\
        lua_setfield(L, -2, it->second.which.c_str());\
        lua_pop(L, 2);\
        it->second.which = "";\
      }\
      gluTessCallback(t, cbe, (GLUcallback)0);\
    }

#define GET_TESS_CALLBACK(which)\
    const char* getCurrentTesselator##which##Callback() {\
      TessCallbacksMap::iterator it = mTessCallbacks.find(mTess);\
      if (it != mTessCallbacks.end()) {\
        if (it->second.which.length() > 0) {\
          return it->second.which.c_str();\
        }\
      }\
      return 0;\
    }
    
    ADD_TESS_CALLBACK(Begin, GLU_TESS_BEGIN_DATA);
    ADD_TESS_CALLBACK(EdgeFlag, GLU_TESS_EDGE_FLAG_DATA);
    ADD_TESS_CALLBACK(Vertex, GLU_TESS_VERTEX_DATA);
    ADD_TESS_CALLBACK(Combine, GLU_TESS_COMBINE_DATA);
    ADD_TESS_CALLBACK(End, GLU_TESS_END_DATA);
    ADD_TESS_CALLBACK(Error, GLU_TESS_ERROR_DATA);
    
    DEL_TESS_CALLBACK(Begin, GLU_TESS_BEGIN_DATA);
    DEL_TESS_CALLBACK(EdgeFlag, GLU_TESS_EDGE_FLAG_DATA);
    DEL_TESS_CALLBACK(Vertex, GLU_TESS_VERTEX_DATA);
    DEL_TESS_CALLBACK(Combine, GLU_TESS_COMBINE_DATA);
    DEL_TESS_CALLBACK(End, GLU_TESS_END_DATA);
    DEL_TESS_CALLBACK(Error, GLU_TESS_ERROR_DATA);
    
    GET_TESS_CALLBACK(Begin);
    GET_TESS_CALLBACK(EdgeFlag);
    GET_TESS_CALLBACK(Vertex);
    GET_TESS_CALLBACK(Combine);
    GET_TESS_CALLBACK(End);
    GET_TESS_CALLBACK(Error);
    
    void setTesselatorPolygonData(lua_State *L, GLUtesselator *t, int arg) {
      char pname[64];
      void *key = (void*)t;
      sprintf(pname, "__glu_pdata_%p", key);
      lua_getfield(L, LUA_GLOBALSINDEX, "glu");
      lua_getmetatable(L, -1);
      lua_pushvalue(L, arg);
      lua_setfield(L, -2, pname);
      TessCallbacksMap::iterator it = mTessCallbacks.find(key);
      if (it == mTessCallbacks.end()) {
        mTessCallbacks[key].pdata = std::string(pname);
      } else {
        it->second.pdata = std::string(pname);
      }
    }
    
    void getTesselatorPolygonData(lua_State *L, void *ud) {
      TessCallbacksMap::iterator it = mTessCallbacks.find(ud);
      if (it != mTessCallbacks.end()) {
        if (it->second.pdata.length() > 0) {
          const char *pname = it->second.pdata.c_str();
          int n = lua_gettop(L);
          lua_getfield(L, LUA_GLOBALSINDEX, "glu");
          lua_getmetatable(L, -1);
          lua_getfield(L, -1, pname);
          lua_remove(L, n); // glu
          lua_remove(L, n); // glu metatable
          return;
        }
      }
      lua_pushnil(L);
      // the polygon data is now on top
    }
    
    void delAllTesselatorCallbacks(lua_State *L, GLUtesselator *t) {
      delTesselatorBeginCallback(L, t);
      delTesselatorEndCallback(L, t);
      delTesselatorVertexCallback(L, t);
      delTesselatorCombineCallback(L, t);
      delTesselatorEdgeFlagCallback(L, t);
      delTesselatorErrorCallback(L, t);
      void *key = (void*)t;
      TessCallbacksMap::iterator it = mTessCallbacks.find(key);
      if (it != mTessCallbacks.end()) {
        mTessCallbacks.erase(it);
      }
    }
    
    inline void setCurrentTesselator(GLUtesselator *t) {
      mTess = (void*)t;
    }
    
    size_t addTessContourVertex(lua_State *L, int arg) {
      // pre incr because lua starts at one
      size_t id = ++mNumContourVertices;
      lua_getfield(L, LUA_GLOBALSINDEX, "glu");
      lua_getmetatable(L, -1);
      lua_pushstring(L, "__glu_cverts");
      lua_rawget(L, -2);
      if (lua_isnil(L, -1)) {
        lua_pop(L, 1);
        lua_newtable(L);
        lua_pushstring(L, "__glu_cverts");
         // duplicate table on top, so that after rawset, __glu_cverts is on top
        lua_pushvalue(L, -2);
        lua_rawset(L, -4); 
      }
      size_t tlen = lua_objlen(L, -1);
      while (tlen < id) {
        lua_pushinteger(L, ++tlen);
        lua_pushnil(L);
        lua_settable(L, -3);
      }
      lua_pushinteger(L, id);
      lua_pushvalue(L, arg);
      lua_settable(L, -3);
      lua_pop(L, 3);
      return id;
    }
    
    void clearTessContourVertices(lua_State *L) {
      lua_getfield(L, LUA_GLOBALSINDEX, "glu");
      lua_getmetatable(L, -1);
      lua_getfield(L, -1, "__glu_cverts");
      for (size_t i=0; i<mNumContourVertices; ++i) {
        lua_pushinteger(L, i+1);
        lua_pushnil(L);
        lua_settable(L, -3);
      }
      lua_pop(L, 3);
      mNumContourVertices = 0;
    }
    
    void getTessContourVertex(lua_State *L, void *ud) {
      int n = lua_gettop(L);
      lua_getfield(L, LUA_GLOBALSINDEX, "glu"); // +1 (1)
      lua_getmetatable(L, -1); // +1 (2)
      lua_getfield(L, -1, "__glu_cverts"); // +1 (3)
      lua_pushinteger(L, (size_t)ud); // +1 (4)
      lua_gettable(L, -2); // +-0 (4)
      lua_remove(L, n); // glu
      lua_remove(L, n); // glu metatable
      lua_remove(L, n); // glu metatable __glu_cverts
      // the vertex data now is on top
    }
    
#undef ADD_TESS_CALLBACK
#undef DEL_TESS_CALLBACK
#undef GET_TESS_CALLBACK
    
    // Nurbs
    
#define ADD_NURBS_CALLBACK(which, cbe)\
    void addNurbs##which##Callback(lua_State *L, GLUnurbs *n, int fn) {\
      void *key = (void*)n;\
      NurbsCallbacksMap::iterator it = mNurbsCallbacks.find(key);\
      if (it == mNurbsCallbacks.end()) {\
        char fname[64];\
        sprintf(fname, "__glu_n%s_%p", #which, key);\
        mNurbsCallbacks[key].which = std::string(fname);\
      }\
      lua_getfield(L, LUA_GLOBALSINDEX, "glu");\
      lua_getmetatable(L, -1);\
      lua_pushvalue(L, fn);\
      lua_setfield(L, -2, mNurbsCallbacks[key].which.c_str());\
      lua_pop(L, 2);\
      gluNurbsCallback(n, cbe, (GLUcallback)lua_gluNurbs##which##Proc);\
    }

#define DEL_NURBS_CALLBACK(which, cbe)\
    void delNurbs##which##Callback(lua_State *L, GLUnurbs *n) {\
      void *key = (void*)n;\
      NurbsCallbacksMap::iterator it = mNurbsCallbacks.find(key);\
      if (it != mNurbsCallbacks.end()) {\
        lua_getfield(L, LUA_GLOBALSINDEX, "glu");\
        lua_getmetatable(L, -1);\
        lua_pushnil(L);\
        lua_setfield(L, -2, it->second.which.c_str());\
        lua_pop(L, 2);\
        it->second.which = "";\
      }\
      gluNurbsCallback(n, cbe, (GLUcallback)0);\
    }

#define GET_NURBS_CALLBACK(which)\
    const char* getCurrentNurbs##which##Callback() {\
      NurbsCallbacksMap::iterator it = mNurbsCallbacks.find(mNURBS);\
      if (it != mNurbsCallbacks.end()) {\
        if (it->second.which.length() > 0) {\
          return it->second.which.c_str();\
        }\
      }\
      return 0;\
    }
    
#ifdef GLU_VERSION_1_3
    ADD_NURBS_CALLBACK(Begin, GLU_NURBS_BEGIN_DATA);
    ADD_NURBS_CALLBACK(Vertex, GLU_NURBS_VERTEX_DATA);
    ADD_NURBS_CALLBACK(Normal, GLU_NURBS_NORMAL_DATA);
    ADD_NURBS_CALLBACK(TexCoord, GLU_NURBS_TEXTURE_COORD_DATA);
    ADD_NURBS_CALLBACK(Color, GLU_NURBS_COLOR_DATA);
    ADD_NURBS_CALLBACK(End, GLU_NURBS_END_DATA);
    ADD_NURBS_CALLBACK(Error, GLU_NURBS_ERROR);
    
    DEL_NURBS_CALLBACK(Begin, GLU_NURBS_BEGIN_DATA);
    DEL_NURBS_CALLBACK(Vertex, GLU_NURBS_VERTEX_DATA);
    DEL_NURBS_CALLBACK(Normal, GLU_NURBS_NORMAL_DATA);
    DEL_NURBS_CALLBACK(TexCoord, GLU_NURBS_TEXTURE_COORD_DATA);
    DEL_NURBS_CALLBACK(Color, GLU_NURBS_COLOR_DATA);
    DEL_NURBS_CALLBACK(End, GLU_NURBS_END_DATA);
    DEL_NURBS_CALLBACK(Error, GLU_NURBS_ERROR);
    
    GET_NURBS_CALLBACK(Begin);
    GET_NURBS_CALLBACK(Vertex);
    GET_NURBS_CALLBACK(Normal);
    GET_NURBS_CALLBACK(TexCoord);
    GET_NURBS_CALLBACK(Color);
    GET_NURBS_CALLBACK(End);
    GET_NURBS_CALLBACK(Error);
#else
    ADD_NURBS_CALLBACK(Error, GLU_ERROR);
    
    DEL_NURBS_CALLBACK(Error, GLU_ERROR);
    
    GET_NURBS_CALLBACK(Error);
#endif
    
    inline void setCurrentNurbs(GLUnurbs *n) {
      mNURBS = (void*)n;
    }
    
    void delAllNurbsCallbacks(lua_State *L, GLUnurbs *n) {
#ifdef GLU_VERSION_1_3
      delNurbsBeginCallback(L, n);
      delNurbsEndCallback(L, n);
      delNurbsVertexCallback(L, n);
      delNurbsNormalCallback(L, n);
      delNurbsColorCallback(L, n);
      delNurbsTexCoordCallback(L, n);
#endif
      delNurbsErrorCallback(L, n);
      
      void *key = (void*)n;
      NurbsCallbacksMap::iterator it = mNurbsCallbacks.find(key);
      if (it != mNurbsCallbacks.end()) {
        mNurbsCallbacks.erase(it);
      }
    }
    
    void setNurbsData(lua_State *L, GLUnurbs *n, int arg) {
      char pname[64];
      void *key = (void*)n;
      sprintf(pname, "__glu_ndata_%p", key);
      lua_getfield(L, LUA_GLOBALSINDEX, "glu");
      lua_getmetatable(L, -1);
      lua_pushvalue(L, arg);
      lua_setfield(L, -2, pname);
      NurbsCallbacksMap::iterator it = mNurbsCallbacks.find(key);
      if (it == mNurbsCallbacks.end()) {
        mNurbsCallbacks[key].data = std::string(pname);
      } else {
        it->second.data = std::string(pname);
      }
    }
    
    void getNurbsData(lua_State *L, void *ud) {
      NurbsCallbacksMap::iterator it = mNurbsCallbacks.find(ud);
      if (it != mNurbsCallbacks.end()) {
        if (it->second.data.length() > 0) {
          const char *pname = it->second.data.c_str();
          int n = lua_gettop(L);
          lua_getfield(L, LUA_GLOBALSINDEX, "glu");
          lua_getmetatable(L, -1);
          lua_getfield(L, -1, pname);
          lua_remove(L, n); // glu
          lua_remove(L, n); // glu metatable
          return;
        }
      }
      lua_pushnil(L);
      // the nurbs data is on top
    }
    
    void setNurbsTexCoordDim(GLUnurbs *n, int dim) {
      void *key = (void*)n;
      NurbsCallbacksMap::iterator it = mNurbsCallbacks.find(key);
      if (it == mNurbsCallbacks.end()) {
        mNurbsCallbacks[key].tdim = dim;
      } else {
        it->second.tdim = dim;
      }
    }
    
    int getNurbsTexCoordDim(void *key) {
      NurbsCallbacksMap::iterator it = mNurbsCallbacks.find(key);
      if (it != mNurbsCallbacks.end()) {
        return it->second.tdim;
      } else {
        return 0;
      }
    }
    
#undef ADD_NURBS_CALLBACK
#undef DEL_NURBS_CALLBACK
#undef GET_NURBS_CALLBACK
    
  public: // lua functions
  
    static int lua__index(lua_State *L) {
      const char *key = lua_tostring(L, 2);
      LuaGLU &glu = Instance();
      GLenum e = glu.getConstant(key);
      if (e == ENUM_ERROR) {
        if (!strcmp(key, "GLU_TESS_MAX_COORD")) {
          lua_pushnumber(L, GLU_TESS_MAX_COORD);
          return 1;
        } else {
          lua_pushstring(L, "Invalid entry");
          lua_error(L);
        }
      }
      lua_pushinteger(L, lua_Integer(e));
      return 1;
    }
    
    static int lua__newindex(lua_State *L) {
      lua_pushstring(L, "No assignable values in GLU module");
      lua_error(L);
      return 0;
    }
    
    static int lua__gc(lua_State *L) {
      void *ud = lua_touserdata(L, 1);
      LuaGLU *glu = (LuaGLU*)ud;
      glu->~LuaGLU();
      return 0;
    }
    
    static int lua_gluErrorString(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      Enum code(L, 1);
      const GLubyte *str = gluErrorString(code);
      lua_pushstring(L, (const char*)str);
      return 1;
    }
    
    static int lua_gluGetString(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      Enum name(L, 1);
      const GLubyte *str = gluGetString(name);
      lua_pushstring(L, (const char*)str);
      return 1;
    }
    
    static int lua_gluOrtho2D(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc4<Double, Double, Double, Double, gluOrtho2D>::Call(L);
#else
      return WrapFunc4<Double, Double, Double, Double >::Call(L, gluOrtho2D);
#endif
    }
    
    static int lua_gluPerspective(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc4<Double, Double, Double, Double, gluPerspective>::Call(L);
#else
      return WrapFunc4<Double, Double, Double, Double >::Call(L, gluPerspective);
#endif
    }
    
    static int lua_gluPickMatrix(lua_State *L) {
      CHECK_ARG_COUNT(L, 5);
      Double x(L, 1);
      Double y(L, 2);
      Double w(L, 3);
      Double h(L, 4);
      Array1D<Int> viewport(L, 5);
      if (viewport.size() != 4) {
        luaL_error(L, "glu.PickMatrix: invalid viewport");
      }
      gluPickMatrix(x, y, w, h, viewport);
      return 0;
    }
    
    static int lua_gluLookAt(lua_State *L) {
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc9<Double, Double, Double, Double, Double, Double, Double, Double, Double, gluLookAt>::Call(L);
#else
      return WrapFunc9<Double, Double, Double, Double, Double, Double, Double, Double, Double >::Call(L, gluLookAt);
#endif
    }
    
    static int lua_gluProject(lua_State *L) {
      CHECK_ARG_COUNT(L, 6);
      Double ox(L, 1);
      Double oy(L, 2);
      Double oz(L, 3);
      FlatArray2D<Double> model(L, 4, ROW_MAJOR, COLUMN_MAJOR);
      if (model.numRows() != 4 || model.numColumns() != 4) {
        luaL_error(L, "glu.Project: invalid model matrix");
      }
      FlatArray2D<Double> proj(L, 5, ROW_MAJOR, COLUMN_MAJOR);
      if (proj.numRows() != 4 || proj.numColumns() != 4) {
        luaL_error(L, "glu.Project: invalid proj matrix");
      }
      Array1D<Int> viewport(L, 6);
      if (viewport.size() != 4) {
        luaL_error(L, "glu.Project: invalid viewport");
      }
      GLdouble w[3];
      int r = gluProject(ox, oy, oz, model, proj, viewport, &w[0], &w[1], &w[2]);
      if (r != GL_TRUE) {
        lua_pushnil(L);
      } else {
        Array1D<Double>(w, 3).toLUA(L);
      }
      return 1;
    }
    
    static int lua_gluUnProject(lua_State *L) {
      CHECK_ARG_COUNT(L, 6);
      Double wx(L, 1);
      Double wy(L, 2);
      Double wz(L, 3);
      FlatArray2D<Double> model(L, 4, ROW_MAJOR, COLUMN_MAJOR);
      if (model.numRows() != 4 || model.numColumns() != 4) {
        luaL_error(L, "glu.UnProject: invalid model matrix");
      }
      FlatArray2D<Double> proj(L, 5, ROW_MAJOR, COLUMN_MAJOR);
      if (proj.numRows() != 4 || proj.numColumns() != 4) {
        luaL_error(L, "glu.UnProject: invalid proj matrix");
      }
      Array1D<Int> viewport(L, 6);
      if (viewport.size() != 4) {
        luaL_error(L, "glu.UnProject: invalid viewport");
      }
      GLdouble o[3];
      int r = gluUnProject(wx, wy, wz, model, proj, viewport, &o[0], &o[1], &o[2]);
      if (r != GL_TRUE) {
        lua_pushnil(L);
      } else {
        Array1D<Double>(o, 3).toLUA(L);
      }
      return 1;
    }
    
    static int lua_gluScaleImage(lua_State *L) {
      CHECK_ARG_COUNT(L, 9);
      Enum fmt(L, 1);
      Int wi(L, 2);
      Int hi(L, 3);
      Enum ti(L, 4);
      ConstPtr dati(L, 5);
      Int wo(L, 6);
      Int ho(L, 7);
      Enum to(L, 8);
      Ptr dato(L, 9);
      lua_pushinteger(L, gluScaleImage(fmt, wi, hi, ti, dati, wo, ho, to, dato));
      return 1;
    }
    
    static int lua_gluBuild1DMipmaps(lua_State *L) {
      CHECK_ARG_COUNT(L, 6);
      Enum tgt(L, 1);
      Int comp(L, 2);
      Int w(L, 3);
      Enum fmt(L, 4);
      Enum typ(L, 5);
      ConstPtr data(L, 6);
      lua_pushinteger(L, gluBuild1DMipmaps(tgt, comp, w, fmt, typ, data));
      return 1;
    }
    
    static int lua_gluBuild2DMipmaps(lua_State *L) {
      CHECK_ARG_COUNT(L, 6);
      Enum tgt(L, 1);
      Int comp(L, 2);
      Int w(L, 3);
      Int h(L, 4);
      Enum fmt(L, 5);
      Enum typ(L, 6);
      ConstPtr data(L, 7);
      lua_pushinteger(L, gluBuild2DMipmaps(tgt, comp, w, h, fmt, typ, data));
      return 1;
    }
    
    // Quadrics

    struct QuadricT {
      typedef GLUquadric T;
    };
    typedef TypedPtr<QuadricT> Quadric;
    
    static int lua_gluNewQuadric(lua_State *L) {
      GLUquadric *q = gluNewQuadric();
      lua_pushlightuserdata(L, (void*)q);
      return 1;
    }
    
    static int lua_gluDeleteQuadric(lua_State *L) {
      Quadric q(L, 1);
      Instance().delQuadricCallback(L, q);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<Quadric, gluDeleteQuadric>::Call(L);
#else
      return WrapFunc1<Quadric >::Call(L, gluDeleteQuadric);
#endif
    }

    static int lua_gluQuadricNormals(lua_State *L) {
      Quadric q(L, 1);
      Instance().setCurrentQuadric(q);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc2<Quadric, Enum, gluQuadricNormals>::Call(L);
#else
      return WrapFunc2<Quadric, Enum >::Call(L, gluQuadricNormals);
#endif
    }
    
    static int lua_gluQuadricTexture(lua_State *L) {
      Quadric q(L, 1);
      Instance().setCurrentQuadric(q);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc2<Quadric, Boolean, gluQuadricTexture>::Call(L);
#else
      return WrapFunc2<Quadric, Boolean >::Call(L, gluQuadricTexture);
#endif
    }
    
    static int lua_gluQuadricOrientation(lua_State *L) {
      Quadric q(L, 1);
      Instance().setCurrentQuadric(q);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc2<Quadric, Enum, gluQuadricOrientation>::Call(L);
#else
      return WrapFunc2<Quadric, Enum >::Call(L, gluQuadricOrientation);
#endif
    }
    
    static int lua_gluQuadricDrawStyle(lua_State *L) {
      Quadric q(L, 1);
      Instance().setCurrentQuadric(q);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc2<Quadric, Enum, gluQuadricDrawStyle>::Call(L);
#else
      return WrapFunc2<Quadric, Enum >::Call(L, gluQuadricDrawStyle);
#endif
    }
    
    static int lua_gluCylinder(lua_State *L) {
      Quadric q(L, 1);
      Instance().setCurrentQuadric(q);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc6<Quadric, Double, Double, Double, Int, Int, gluCylinder>::Call(L);
#else
      return WrapFunc6<Quadric, Double, Double, Double, Int, Int >::Call(L, gluCylinder);
#endif
    }
    
    static int lua_gluDisk(lua_State *L) {
      Quadric q(L, 1);
      Instance().setCurrentQuadric(q);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc5<Quadric, Double, Double, Int, Int, gluDisk>::Call(L);
#else
      return WrapFunc5<Quadric, Double, Double, Int, Int >::Call(L, gluDisk);
#endif
    }
    
    static int lua_gluPartialDisk(lua_State *L) {
      Quadric q(L, 1);
      Instance().setCurrentQuadric(q);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc7<Quadric, Double, Double, Int, Int, Double, Double, gluPartialDisk>::Call(L);
#else
      return WrapFunc7<Quadric, Double, Double, Int, Int, Double, Double >::Call(L, gluPartialDisk);
#endif
    }
    
    static int lua_gluSphere(lua_State *L) {
      Quadric q(L, 1);
      Instance().setCurrentQuadric(q);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc4<Quadric, Double, Int, Int, gluSphere>::Call(L);
#else
      return WrapFunc4<Quadric, Double, Int, Int >::Call(L, gluSphere);
#endif
    }
    
    // Tesselator
    
    static int lua_gluNewTess(lua_State *L) {
      CHECK_ARG_COUNT(L, 0);
      GLUtesselator *t = gluNewTess();
      lua_pushlightuserdata(L, (void*)t);
      return 1;
    }

    struct TessT {
      typedef GLUtesselator T;
    };
    typedef TypedPtr<TessT> Tess;
    
    static int lua_gluDeleteTess(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      Tess t(L, 1);
      Instance().delAllTesselatorCallbacks(L, t);
      lua_pushnil(L);
      Instance().setTesselatorPolygonData(L, t, lua_gettop(L));
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<Tess, gluDeleteTess>::Call(L);
#else
      return WrapFunc1<Tess >::Call(L, gluDeleteTess);
#endif
    }
    
    static int lua_gluTessBeginPolygon(lua_State *L) {
      CHECK_ARG_COUNT(L, 2);
      Tess t(L, 1);
      Instance().setCurrentTesselator(t);
      Instance().setTesselatorPolygonData(L, t, 2);
      gluTessBeginPolygon(t, (void*)t);
      return 0;
    }
    
    static int lua_gluTessEndPolygon(lua_State *L) {
      Tess t(L, 1);
      Instance().setCurrentTesselator(t);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<Tess, gluTessEndPolygon>::Call(L);
#else
      return WrapFunc1<Tess >::Call(L, gluTessEndPolygon);
#endif
    }
  
    static int lua_gluTessBeginContour(lua_State *L) {
      Tess t(L, 1);
      Instance().setCurrentTesselator(t);
      Instance().clearTessContourVertices(L);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<Tess, gluTessBeginContour>::Call(L);
#else
      return WrapFunc1<Tess >::Call(L, gluTessBeginContour);
#endif
    }
    
    static int lua_gluTessEndContour(lua_State *L) {
      Tess t(L, 1);
      Instance().setCurrentTesselator(t);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<Tess, gluTessEndContour>::Call(L);
#else
      return WrapFunc1<Tess >::Call(L, gluTessEndContour);
#endif
    }
    
    static int lua_gluTessVertex(lua_State *L) {
      CHECK_ARG_COUNT(L, 3);
      Tess t(L, 1);
      Array1D<Double> coords(L, 2);
      if (coords.size() != 3) {
        luaL_error(L, "glu.TessVertex: invalid coords");
      }
      size_t id = Instance().addTessContourVertex(L, 3);
      Instance().setCurrentTesselator(t);
      gluTessVertex(t, coords, (void*)id);
      return 0;
    }
    
    static int lua_gluTessNormal(lua_State *L) {
      Tess t(L, 1);
      Instance().setCurrentTesselator(t);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc4<Tess, Double, Double, Double, gluTessNormal>::Call(L);
#else
      return WrapFunc4<Tess, Double, Double, Double >::Call(L, gluTessNormal);
#endif
    }
    
    static int lua_gluTessProperty(lua_State *L) {
      Tess t(L, 1);
      Instance().setCurrentTesselator(t);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc3<Tess, Enum, Double, gluTessProperty>::Call(L);
#else
      return WrapFunc3<Tess, Enum, Double >::Call(L, gluTessProperty);
#endif
    }
    
    static int lua_gluGetTessProperty(lua_State *L) {
      CHECK_ARG_COUNT(L, 2);
      Tess t(L, 1);
      Enum which(L, 2);
      GLdouble val;
      Instance().setCurrentTesselator(t);
      gluGetTessProperty(t, which, &val);
      lua_pushnumber(L, val);
      return 1;
    }
    
    // Nurbs

    struct NurbsT {
      typedef GLUnurbs T;
    };
    typedef TypedPtr<NurbsT> Nurbs;
    
    static int lua_gluNewNurbsRenderer(lua_State *L) {
      CHECK_ARG_COUNT(L, 0);
      GLUnurbs *n = gluNewNurbsRenderer();
      lua_pushlightuserdata(L, n);
      return 1;
    }
    
    static int lua_gluDeleteNurbsRenderer(lua_State *L) {
      CHECK_ARG_COUNT(L, 1);
      Nurbs n(L, 1);
      Instance().delAllNurbsCallbacks(L, n);
      lua_pushnil(L);
      Instance().setNurbsData(L, n, lua_gettop(L));
      gluDeleteNurbsRenderer(n);
      return 0;
    }
    
    static int lua_gluBeginSurface(lua_State *L) {
      Nurbs n(L, 1);
      Instance().setCurrentNurbs(n);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<Nurbs, gluBeginSurface>::Call(L);
#else
      return WrapFunc1<Nurbs >::Call(L, gluBeginSurface);
#endif
    }
    
    static int lua_gluEndSurface(lua_State *L) {
      Nurbs n(L, 1);
      Instance().setCurrentNurbs(n);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<Nurbs, gluEndSurface>::Call(L);
#else
      return WrapFunc1<Nurbs >::Call(L, gluEndSurface);
#endif
    }
    
    static int lua_gluBeginCurve(lua_State *L) {
      Nurbs n(L, 1);
      Instance().setCurrentNurbs(n);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<Nurbs, gluBeginCurve>::Call(L);
#else
      return WrapFunc1<Nurbs >::Call(L, gluBeginCurve);
#endif
    }
    
    static int lua_gluEndCurve(lua_State *L) {
      Nurbs n(L, 1);
      Instance().setCurrentNurbs(n);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<Nurbs, gluEndCurve>::Call(L);
#else
      return WrapFunc1<Nurbs >::Call(L, gluEndCurve);
#endif
    }
    
    static int lua_gluBeginTrim(lua_State *L) {
      Nurbs n(L, 1);
      Instance().setCurrentNurbs(n);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<Nurbs, gluBeginTrim>::Call(L);
#else
      return WrapFunc1<Nurbs >::Call(L, gluBeginTrim);
#endif
    }
    
    static int lua_gluEndTrim(lua_State *L) {
      Nurbs n(L, 1);
      Instance().setCurrentNurbs(n);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc1<Nurbs, gluEndTrim>::Call(L);
#else
      return WrapFunc1<Nurbs >::Call(L, gluEndTrim);
#endif
    }
    
    static int lua_gluPwlCurve(lua_State *L) {
      Nurbs n(L, 1);
      Instance().setCurrentNurbs(n);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc5<Nurbs, Int, TypedPtr<Float>, Int, Enum, gluPwlCurve>::Call(L);
#else
      return WrapFunc5<Nurbs, Int, TypedPtr<Float>, Int, Enum >::Call(L, gluPwlCurve);
#endif
    }
    
    static int lua_gluNurbsCurve(lua_State *L) {
      Nurbs n(L, 1);
      Instance().setCurrentNurbs(n);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc7<Nurbs, Int, TypedPtr<Float>, Int, TypedPtr<Float>, Int, Enum, gluNurbsCurve>::Call(L);
#else
      return WrapFunc7<Nurbs, Int, TypedPtr<Float>, Int, TypedPtr<Float>, Int, Enum >::Call(L, gluNurbsCurve);
#endif
    }
    
    static int lua_gluNurbsSurface(lua_State *L) {
      Nurbs n(L, 1);
      Instance().setCurrentNurbs(n);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc11<Nurbs, Int, TypedPtr<Float>, Int, TypedPtr<Float>, Int, Int, TypedPtr<Float>, Int, Int, Enum, gluNurbsSurface>::Call(L);
#else
      return WrapFunc11<Nurbs, Int, TypedPtr<Float>, Int, TypedPtr<Float>, Int, Int, TypedPtr<Float>, Int, Int, Enum >::Call(L, gluNurbsSurface);
#endif
    }
    
    static int lua_gluNurbsProperty(lua_State *L) {
      Nurbs n(L, 1);
      Instance().setCurrentNurbs(n);
#ifndef LUAGL_FUNC_AS_ARG
      return WrapFunc3<Nurbs, Enum, Float, gluNurbsProperty>::Call(L);
#else
      return WrapFunc3<Nurbs, Enum, Float >::Call(L, gluNurbsProperty);
#endif
    }
    
    static int lua_gluGetNurbsProperty(lua_State *L) {
      CHECK_ARG_COUNT(L, 2);
      Nurbs n(L, 1);
      Enum p(L, 2);
      Instance().setCurrentNurbs(n);
      GLfloat v;
      gluGetNurbsProperty(n, p, &v);
      lua_pushnumber(L, v);
      return 1;
    }
    
    static int lua_gluLoadSamplingMatrices(lua_State *L) {
      CHECK_ARG_COUNT(L, 4);
      Nurbs n(L, 1);
      FlatArray2D<Float> model(L, 2, ROW_MAJOR, COLUMN_MAJOR);
      if (model.numRows() != 4 || model.numColumns() != 4) {
        luaL_error(L, "glu.LoadSamplingMatrices: invalid modelview matrix");
      }
      FlatArray2D<Float> proj(L, 3, ROW_MAJOR, COLUMN_MAJOR);
      if (proj.numRows() != 4 || proj.numColumns() != 4) {
        luaL_error(L, "glu.LoadSamplingMatrices: invalid projection matrix");
      }
      Array1D<Int> viewport(L, 4);
      if (viewport.size() != 4) {
        luaL_error(L, "glu.LoadSamplingMatrices: invalid viewport");
      }
      gluLoadSamplingMatrices(n, model, proj, viewport);
      return 0;
    }

    static int lua_gluQuadricCallback(lua_State *L) {
      
      CHECK_ARG_COUNT(L, 3);

      Quadric q(L, 1);
      Enum which(L, 2);
      
      if (which != GLU_ERROR) {
        luaL_argerror(L, 2, "glu.GLU_ERROR is the only valid option");
      }
      
      if (lua_isnil(L, 3)) {
        Instance().delQuadricCallback(L, q);
        
      } else if (lua_isfunction(L, 3)) {
        Instance().addQuadricCallback(L, q, 3);
        
      } else {
        luaL_argerror(L, 3, "Expected function");
      }
      
      return 0;
    }
    
    static int lua_gluTessCallback(lua_State *L) {

      CHECK_ARG_COUNT(L, 3);

      Tess t(L, 1);
      Enum which(L, 2);

      bool isnil = lua_isnil(L, 3);
      
      if (!isnil && !lua_isfunction(L, 3)) {
        luaL_argerror(L, 3, "Expected function");
      }
      
      switch (which) {
      case GLU_TESS_BEGIN:
      case GLU_TESS_BEGIN_DATA:
        if (isnil) {
          Instance().delTesselatorBeginCallback(L, t);
        } else {
          Instance().addTesselatorBeginCallback(L, t, 3);
        }
        break;
      case GLU_TESS_EDGE_FLAG:
      case GLU_TESS_EDGE_FLAG_DATA:
        if (isnil) {
          Instance().delTesselatorEdgeFlagCallback(L, t);
        } else {
          Instance().addTesselatorEdgeFlagCallback(L, t, 3);
        }
        break;
      case GLU_TESS_VERTEX:
      case GLU_TESS_VERTEX_DATA:
        if (isnil) {
          Instance().delTesselatorVertexCallback(L, t);
        } else {
          Instance().addTesselatorVertexCallback(L, t, 3);
        }
        break;
      case GLU_TESS_COMBINE:
      case GLU_TESS_COMBINE_DATA:
        if (isnil) {
          Instance().delTesselatorCombineCallback(L, t);
        } else {
          Instance().addTesselatorCombineCallback(L, t, 3);
        }
        break;
      case GLU_TESS_END:
      case GLU_TESS_END_DATA:
        if (isnil) {
          Instance().delTesselatorEndCallback(L, t);
        } else {
          Instance().addTesselatorEndCallback(L, t, 3);
        }
        break;
      case GLU_TESS_ERROR:
      case GLU_TESS_ERROR_DATA:
        if (isnil) {
          Instance().delTesselatorErrorCallback(L, t);
        } else {
          Instance().addTesselatorErrorCallback(L, t, 3);
        }
        break;
      default:
        luaL_argerror(L, 2, "Invalid callback name");
      }
      
      return 0;
    }
  
    static int lua_gluNurbsCallback(lua_State *L) {

      CHECK_ARG_COUNT(L, 3);

      Nurbs n(L, 1);
      Enum which(L, 2);
      
      bool isnil = lua_isnil(L, 3);
      if (!isnil && !lua_isfunction(L, 3)) {
        luaL_argerror(L, 3, "Expected function");
      }
      
#ifdef GLU_VERSION_1_3
      switch (which) {
      case GLU_NURBS_BEGIN:
      case GLU_NURBS_BEGIN_DATA:
        if (isnil) {
          Instance().delNurbsBeginCallback(L, n);
        } else {
          Instance().addNurbsBeginCallback(L, n, 3);
        }
        break;
      case GLU_NURBS_VERTEX:
      case GLU_NURBS_VERTEX_DATA:
        if (isnil) {
          Instance().delNurbsVertexCallback(L, n);
        } else {
          Instance().addNurbsVertexCallback(L, n, 3);
        }
        break;
      case GLU_NURBS_NORMAL:
      case GLU_NURBS_NORMAL_DATA:
        if (isnil) {
          Instance().delNurbsNormalCallback(L, n);
        } else {
          Instance().addNurbsNormalCallback(L, n, 3);
        }
        break;
      case GLU_NURBS_COLOR:
      case GLU_NURBS_COLOR_DATA:
        if (isnil) {
          Instance().delNurbsColorCallback(L, n);
        } else {
          Instance().addNurbsColorCallback(L, n, 3);
        }
        break;
      case GLU_NURBS_TEXTURE_COORD:
      case GLU_NURBS_TEXTURE_COORD_DATA:
        if (isnil) {
          Instance().delNurbsTexCoordCallback(L, n);
        } else {
          Instance().addNurbsTexCoordCallback(L, n, 3);
        }
        break;
      case GLU_NURBS_END:
      case GLU_NURBS_END_DATA:
        if (isnil) {
          Instance().delNurbsEndCallback(L, n);
        } else {
          Instance().addNurbsEndCallback(L, n, 3);
        }
        break;
      case GLU_NURBS_ERROR:
        if (isnil) {
          Instance().delNurbsErrorCallback(L, n);
        } else {
          Instance().addNurbsErrorCallback(L, n, 3);
        }
        break;
      default:
        luaL_argerror(L, 2, "Invalid callback name");
      }
#else
      if (which != GLU_ERROR) {
        luaL_argerror(L, 2, "Invalid callback name");
      }
      if (isnil) {
        Instance().delNurbsErrorCallback(L, n);
      } else {
        Instance().addNurbsErrorCallback(L, n, 3);
      }
#endif
      return 0;
    }
    
#ifdef GLU_VERSION_1_3

    static int lua_gluNurbsCallbackData(lua_State *L) {
      CHECK_ARG_COUNT(L, 2);
      Nurbs n(L, 1);
      Instance().setCurrentNurbs(n);
      Instance().setNurbsData(L, n, 2);
      gluNurbsCallbackData(n, (void*)(GLUnurbs*)n);
      return 0;
    }

#endif
  
    /*
Backward comp:
  
void APIENTRY gluBeginPolygon(GLUtesselator *tess);
void APIENTRY gluNextContour(GLUtesselator *tess, GLenum type);
void APIENTRY gluEndPolygon(GLUtesselator *tess);
  
1.3:
  
GLAPI GLint GLAPIENTRY gluBuild1DMipmapLevels (GLenum target, GLint internalFormat, GLsizei width, GLenum format, GLenum type, GLint level, GLint base, GLint max, const void *data);
GLAPI GLint GLAPIENTRY gluBuild2DMipmapLevels (GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLint level, GLint base, GLint max, const void *data);
GLAPI GLint GLAPIENTRY gluBuild3DMipmaps (GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
GLAPI GLint GLAPIENTRY gluBuild3DMipmapLevels (GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLint level, GLint base, GLint max, const void *data);
GLAPI GLboolean GLAPIENTRY gluCheckExtension (const GLubyte *extName, const GLubyte *extString);
    */
  
  public:
  
    void initFunctions(lua_State *L, int module) {

#define REGISTER_GLU_FUNC(Name)\
  lua_pushcfunction(L, &LuaGLU::lua_glu##Name);\
  lua_setfield(L, module, #Name)
    
      REGISTER_GLU_FUNC(ErrorString);
      REGISTER_GLU_FUNC(GetString);
      REGISTER_GLU_FUNC(Ortho2D);
      REGISTER_GLU_FUNC(Perspective);
      REGISTER_GLU_FUNC(PickMatrix);
      REGISTER_GLU_FUNC(LookAt);
      REGISTER_GLU_FUNC(Project);
      REGISTER_GLU_FUNC(UnProject);
      REGISTER_GLU_FUNC(ScaleImage);
      REGISTER_GLU_FUNC(Build1DMipmaps);
      REGISTER_GLU_FUNC(Build2DMipmaps);
      REGISTER_GLU_FUNC(NewQuadric);
      REGISTER_GLU_FUNC(DeleteQuadric);
      REGISTER_GLU_FUNC(QuadricNormals);
      REGISTER_GLU_FUNC(QuadricTexture);
      REGISTER_GLU_FUNC(QuadricOrientation);
      REGISTER_GLU_FUNC(QuadricDrawStyle);
      REGISTER_GLU_FUNC(Cylinder);
      REGISTER_GLU_FUNC(Disk);
      REGISTER_GLU_FUNC(PartialDisk);
      REGISTER_GLU_FUNC(Sphere);
      REGISTER_GLU_FUNC(NewTess);
      REGISTER_GLU_FUNC(DeleteTess);
      REGISTER_GLU_FUNC(TessBeginPolygon);
      REGISTER_GLU_FUNC(TessEndPolygon);
      REGISTER_GLU_FUNC(TessBeginContour);
      REGISTER_GLU_FUNC(TessEndContour);
      REGISTER_GLU_FUNC(TessVertex);
      REGISTER_GLU_FUNC(TessNormal);
      REGISTER_GLU_FUNC(TessProperty);
      REGISTER_GLU_FUNC(GetTessProperty);
      REGISTER_GLU_FUNC(NewNurbsRenderer);
      REGISTER_GLU_FUNC(DeleteNurbsRenderer);
      REGISTER_GLU_FUNC(BeginSurface);
      REGISTER_GLU_FUNC(EndSurface);
      REGISTER_GLU_FUNC(BeginCurve);
      REGISTER_GLU_FUNC(EndCurve);
      REGISTER_GLU_FUNC(BeginTrim);
      REGISTER_GLU_FUNC(EndTrim);
      REGISTER_GLU_FUNC(PwlCurve);
      REGISTER_GLU_FUNC(NurbsCurve);
      REGISTER_GLU_FUNC(NurbsSurface);
      REGISTER_GLU_FUNC(NurbsProperty);
      REGISTER_GLU_FUNC(GetNurbsProperty);
      REGISTER_GLU_FUNC(LoadSamplingMatrices);
      REGISTER_GLU_FUNC(QuadricCallback);
      REGISTER_GLU_FUNC(TessCallback);
      REGISTER_GLU_FUNC(NurbsCallback);
#ifdef GLU_VERSION_1_3
      REGISTER_GLU_FUNC(NurbsCallbackData);
#endif

#undef REGISTER_GLU_FUNC
    }

  protected:
    
    
    void initConstants() {
      //mConstants["TESS_MAX_COORD"] = GLU_TESS_MAX_COORD;
      mConstants["VERSION_1_1"] = GLU_VERSION_1_1;
      mConstants["VERSION_1_2"] = GLU_VERSION_1_2;
      mConstants["INVALID_ENUM"] = GLU_INVALID_ENUM;
      mConstants["INVALID_VALUE"] = GLU_INVALID_VALUE;
      mConstants["OUT_OF_MEMORY"] = GLU_OUT_OF_MEMORY;
      mConstants["INCOMPATIBLE_GL_VERSION"] = GLU_INCOMPATIBLE_GL_VERSION;
      mConstants["VERSION"] = GLU_VERSION;
      mConstants["EXTENSIONS"] = GLU_EXTENSIONS;
      mConstants["TRUE"] = GLU_TRUE;
      mConstants["FALSE"] = GLU_FALSE;
      mConstants["SMOOTH"] = GLU_SMOOTH;
      mConstants["FLAT"] = GLU_FLAT;
      mConstants["NONE"] = GLU_NONE;
      mConstants["POINT"] = GLU_POINT;
      mConstants["LINE"] = GLU_LINE;
      mConstants["FILL"] = GLU_FILL;
      mConstants["SILHOUETTE"] = GLU_SILHOUETTE;
      mConstants["OUTSIDE"] = GLU_OUTSIDE;
      mConstants["INSIDE"] = GLU_INSIDE;
      mConstants["TESS_WINDING_RULE"] = GLU_TESS_WINDING_RULE;
      mConstants["TESS_BOUNDARY_ONLY"] = GLU_TESS_BOUNDARY_ONLY;
      mConstants["TESS_TOLERANCE"] = GLU_TESS_TOLERANCE;
      mConstants["TESS_WINDING_ODD"] = GLU_TESS_WINDING_ODD;
      mConstants["TESS_WINDING_NONZERO"] = GLU_TESS_WINDING_NONZERO;
      mConstants["TESS_WINDING_POSITIVE"] = GLU_TESS_WINDING_POSITIVE;
      mConstants["TESS_WINDING_NEGATIVE"] = GLU_TESS_WINDING_NEGATIVE;
      mConstants["TESS_WINDING_ABS_GEQ_TWO"] = GLU_TESS_WINDING_ABS_GEQ_TWO;
      mConstants["TESS_BEGIN"] = GLU_TESS_BEGIN;
      mConstants["TESS_VERTEX"] = GLU_TESS_VERTEX;
      mConstants["TESS_END"] = GLU_TESS_END;
      mConstants["TESS_ERROR"] = GLU_TESS_ERROR;
      mConstants["TESS_EDGE_FLAG"] = GLU_TESS_EDGE_FLAG;
      mConstants["TESS_COMBINE"] = GLU_TESS_COMBINE;
      mConstants["TESS_BEGIN_DATA"] = GLU_TESS_BEGIN_DATA;
      mConstants["TESS_VERTEX_DATA"] = GLU_TESS_VERTEX_DATA;
      mConstants["TESS_END_DATA"] = GLU_TESS_END_DATA;
      mConstants["TESS_ERROR_DATA"] = GLU_TESS_ERROR_DATA;
      mConstants["TESS_EDGE_FLAG_DATA"] = GLU_TESS_EDGE_FLAG_DATA;
      mConstants["TESS_COMBINE_DATA"] = GLU_TESS_COMBINE_DATA;
      mConstants["TESS_ERROR1"] = GLU_TESS_ERROR1;
      mConstants["TESS_ERROR2"] = GLU_TESS_ERROR2;
      mConstants["TESS_ERROR3"] = GLU_TESS_ERROR3;
      mConstants["TESS_ERROR4"] = GLU_TESS_ERROR4;
      mConstants["TESS_ERROR5"] = GLU_TESS_ERROR5;
      mConstants["TESS_ERROR6"] = GLU_TESS_ERROR6;
      mConstants["TESS_ERROR7"] = GLU_TESS_ERROR7;
      mConstants["TESS_ERROR8"] = GLU_TESS_ERROR8;
      mConstants["TESS_MISSING_BEGIN_POLYGON"] = GLU_TESS_MISSING_BEGIN_POLYGON;
      mConstants["TESS_MISSING_BEGIN_CONTOUR"] = GLU_TESS_MISSING_BEGIN_CONTOUR;
      mConstants["TESS_MISSING_END_POLYGON"] = GLU_TESS_MISSING_END_POLYGON;
      mConstants["TESS_MISSING_END_CONTOUR"] = GLU_TESS_MISSING_END_CONTOUR;
      mConstants["TESS_COORD_TOO_LARGE"] = GLU_TESS_COORD_TOO_LARGE;
      mConstants["TESS_NEED_COMBINE_CALLBACK"] = GLU_TESS_NEED_COMBINE_CALLBACK;
      mConstants["AUTO_LOAD_MATRIX"] = GLU_AUTO_LOAD_MATRIX;
      mConstants["CULLING"] = GLU_CULLING;
      mConstants["SAMPLING_TOLERANCE"] = GLU_SAMPLING_TOLERANCE;
      mConstants["DISPLAY_MODE"] = GLU_DISPLAY_MODE;
      mConstants["PARAMETRIC_TOLERANCE"] = GLU_PARAMETRIC_TOLERANCE;
      mConstants["SAMPLING_METHOD"] = GLU_SAMPLING_METHOD;
      mConstants["U_STEP"] = GLU_U_STEP;
      mConstants["V_STEP"] = GLU_V_STEP;
      mConstants["PATH_LENGTH"] = GLU_PATH_LENGTH;
      mConstants["PARAMETRIC_ERROR"] = GLU_PARAMETRIC_ERROR;
      mConstants["DOMAIN_DISTANCE"] = GLU_DOMAIN_DISTANCE;
      mConstants["MAP1_TRIM_2"] = GLU_MAP1_TRIM_2;
      mConstants["MAP1_TRIM_3"] = GLU_MAP1_TRIM_3;
      mConstants["OUTLINE_POLYGON"] = GLU_OUTLINE_POLYGON;
      mConstants["OUTLINE_PATCH"] = GLU_OUTLINE_PATCH;
      mConstants["NURBS_ERROR1"] = GLU_NURBS_ERROR1;
      mConstants["NURBS_ERROR2"] = GLU_NURBS_ERROR2;
      mConstants["NURBS_ERROR3"] = GLU_NURBS_ERROR3;
      mConstants["NURBS_ERROR4"] = GLU_NURBS_ERROR4;
      mConstants["NURBS_ERROR5"] = GLU_NURBS_ERROR5;
      mConstants["NURBS_ERROR6"] = GLU_NURBS_ERROR6;
      mConstants["NURBS_ERROR7"] = GLU_NURBS_ERROR7;
      mConstants["NURBS_ERROR8"] = GLU_NURBS_ERROR8;
      mConstants["NURBS_ERROR9"] = GLU_NURBS_ERROR9;
      mConstants["NURBS_ERROR10"] = GLU_NURBS_ERROR10;
      mConstants["NURBS_ERROR11"] = GLU_NURBS_ERROR11;
      mConstants["NURBS_ERROR12"] = GLU_NURBS_ERROR12;
      mConstants["NURBS_ERROR13"] = GLU_NURBS_ERROR13;
      mConstants["NURBS_ERROR14"] = GLU_NURBS_ERROR14;
      mConstants["NURBS_ERROR15"] = GLU_NURBS_ERROR15;
      mConstants["NURBS_ERROR16"] = GLU_NURBS_ERROR16;
      mConstants["NURBS_ERROR17"] = GLU_NURBS_ERROR17;
      mConstants["NURBS_ERROR18"] = GLU_NURBS_ERROR18;
      mConstants["NURBS_ERROR19"] = GLU_NURBS_ERROR19;
      mConstants["NURBS_ERROR20"] = GLU_NURBS_ERROR20;
      mConstants["NURBS_ERROR21"] = GLU_NURBS_ERROR21;
      mConstants["NURBS_ERROR22"] = GLU_NURBS_ERROR22;
      mConstants["NURBS_ERROR23"] = GLU_NURBS_ERROR23;
      mConstants["NURBS_ERROR24"] = GLU_NURBS_ERROR24;
      mConstants["NURBS_ERROR25"] = GLU_NURBS_ERROR25;
      mConstants["NURBS_ERROR26"] = GLU_NURBS_ERROR26;
      mConstants["NURBS_ERROR27"] = GLU_NURBS_ERROR27;
      mConstants["NURBS_ERROR28"] = GLU_NURBS_ERROR28;
      mConstants["NURBS_ERROR29"] = GLU_NURBS_ERROR29;
      mConstants["NURBS_ERROR30"] = GLU_NURBS_ERROR30;
      mConstants["NURBS_ERROR31"] = GLU_NURBS_ERROR31;
      mConstants["NURBS_ERROR32"] = GLU_NURBS_ERROR32;
      mConstants["NURBS_ERROR33"] = GLU_NURBS_ERROR33;
      mConstants["NURBS_ERROR34"] = GLU_NURBS_ERROR34;
      mConstants["NURBS_ERROR35"] = GLU_NURBS_ERROR35;
      mConstants["NURBS_ERROR36"] = GLU_NURBS_ERROR36;
      mConstants["NURBS_ERROR37"] = GLU_NURBS_ERROR37;
      mConstants["CW"] = GLU_CW;
      mConstants["CCW"] = GLU_CCW;
      mConstants["INTERIOR"] = GLU_INTERIOR;
      mConstants["EXTERIOR"] = GLU_EXTERIOR;
      mConstants["UNKNOWN"] = GLU_UNKNOWN;
      mConstants["BEGIN"] = GLU_BEGIN;
      mConstants["VERTEX"] = GLU_VERTEX;
      mConstants["END"] = GLU_END;
      mConstants["ERROR"] = GLU_ERROR;
      mConstants["EDGE_FLAG"] = GLU_EDGE_FLAG;
#ifdef GLU_VERSION_1_3
      mConstants["VERSION_1_3"] = GLU_VERSION_1_3;
      mConstants["NURBS_ERROR"] = GLU_NURBS_ERROR;
      mConstants["NURBS_BEGIN"] = GLU_NURBS_BEGIN;
      mConstants["NURBS_VERTEX"] = GLU_NURBS_VERTEX;
      mConstants["NURBS_NORMAL"] = GLU_NURBS_NORMAL;
      mConstants["NURBS_COLOR"] = GLU_NURBS_COLOR;
      mConstants["NURBS_TEXTURE_COORD"] = GLU_NURBS_TEXTURE_COORD;
      mConstants["NURBS_END"] = GLU_NURBS_END;
      mConstants["NURBS_BEGIN_DATA"] = GLU_NURBS_BEGIN_DATA;
      mConstants["NURBS_VERTEX_DATA"] = GLU_NURBS_VERTEX_DATA;
      mConstants["NURBS_NORMAL_DATA"] = GLU_NURBS_NORMAL_DATA;
      mConstants["NURBS_COLOR_DATA"] = GLU_NURBS_COLOR_DATA;
      mConstants["NURBS_TEXTURE_COORD_DATA"] = GLU_NURBS_TEXTURE_COORD_DATA;
      mConstants["NURBS_END_DATA"] = GLU_NURBS_END_DATA;
      mConstants["NURBS_MODE"] = GLU_NURBS_MODE;
      mConstants["NURBS_TESSELLATOR"] = GLU_NURBS_TESSELLATOR;
      mConstants["NURBS_RENDERER"] = GLU_NURBS_RENDERER;
      mConstants["OBJECT_PARAMETRIC_ERROR"] = GLU_OBJECT_PARAMETRIC_ERROR;
      mConstants["OBJECT_PATH_LENGTH"] = GLU_OBJECT_PATH_LENGTH;
#else
      mConstants["VERSION_1_3"] = 0;
#endif
    }
  
  
  protected:
    
    static LuaGLU *msInstance;
    
  protected:
    
    lua_State *mState;
    std::map<std::string, GLenum> mConstants;
};

int LuaGLU::REG_KEY = 0;
GLenum LuaGLU::ENUM_ERROR = (GLenum)-2;
LuaGLU* LuaGLU::msInstance = 0;


EXPORT int luaopen_luagl_glu(lua_State *L) {
  
  // create a userdata named GL
  
  void *ud = lua_newuserdata(L, sizeof(LuaGLU));  // +1 (1)
  new (ud) LuaGLU(L);
  int module = lua_gettop(L);
  
  lua_newtable(L); // +1 (2)
  int metatable = lua_gettop(L);
  
  ((LuaGLU*)ud)->initFunctions(L, metatable);
  
  lua_pushvalue(L, metatable); // +1 (3)
  lua_setfield(L, metatable, "__index"); // -1 (2)
  
  lua_pushcfunction(L, &LuaGLU::lua__newindex); // +1 (3)
  lua_setfield(L, metatable, "__newindex"); // -1 (2)
  
  lua_pushcfunction(L, &LuaGLU::lua__gc); // +1 (3)
  lua_setfield(L, metatable, "__gc"); // -1 (2)
  
  lua_pushvalue(L, metatable); // +1 (3)
  lua_setfield(L, metatable, "__metatable"); // -1 (2)
  
  lua_newtable(L); // +1 (3)
  int metametatable = lua_gettop(L);
  lua_pushcfunction(L, &LuaGLU::lua__index); // +1 (4)
  lua_setfield(L, metametatable, "__index"); // -1 (3)
  lua_setmetatable(L, metatable); // -1 (2)
  
  lua_pushvalue(L, metatable); // +1 (3)
  lua_setmetatable(L, module); // -1 (2)
  
  lua_pushvalue(L, module); // +1 (3)
  lua_setfield(L, LUA_GLOBALSINDEX, "glu"); // -1 (2)

  lua_pushlightuserdata(L, (void*)&LuaGLU::REG_KEY); // +1 (3)
  lua_pushvalue(L, metatable); // +1 (4)
  lua_settable(L, LUA_REGISTRYINDEX); // -2 (2)

  lua_pop(L, 1); // -1 (1) : pop metatable

  return 1;
}


