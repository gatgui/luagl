import glob
import excons
import excons.tools
from excons.tools import lua
from excons.tools import glut

defs = ["GLEW_STATIC", "GLEW_BUILD"]
if int(ARGUMENTS.get("gluVariadicCallbacks", "0")) == 1:
  defs.append("LUAGL_GLU_VARIADIC_CALLBACK")

prjs = [
  { "name"  : "luabitop",
    "type"  : "dynamicmodule",
    "srcs"  : glob.glob("src/bitop/*.cpp"),
    "ext"   : ".so",
    "prefix": "lua",
    "custom": [lua.Require]
  },
  { "name"  : "luaraw",
    "type"  : "dynamicmodule",
    "srcs"  : glob.glob("src/raw/*.cpp"),
    "ext"   : ".so",
    "prefix": "lua",
    "custom": [lua.Require]
  },
  { "name"    : "luagl",
    "type"    : "dynamicmodule",
    "defs"    : defs,
    "incdirs" : ["include"],
    "srcs"    : glob.glob("src/gl/*.cpp") + ["src/gl/glew.c"],
    "ext"     : ".so",
    "prefix"  : "lua",
    "deps"    : ["luabitop", "luaraw"],
    "custom"  : [lua.Require, glut.Require]
  }
]

env = excons.MakeBaseEnv()
excons.DeclareTargets(env, prjs)




