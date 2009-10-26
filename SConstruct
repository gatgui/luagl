import glob
import excons
import excons.tools
from excons.tools import lua
from excons.tools import glut

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
  { "name"  : "luagl",
    "type"  : "dynamicmodule",
    "defs"  : ["GLEW_STATIC", "GLEW_BUILD"],
    "srcs"  : glob.glob("src/gl/*.cpp") + glob.glob("src/gl/mem/*.cpp") + ["src/gl/glew.c"],
    "ext"   : ".so",
    "prefix": "lua",
    "deps"  : ["luabitop", "luaraw"],
    "custom": [lua.Require, glut.Require]
  }
]

env = excons.MakeBaseEnv()
excons.DeclareTargets(env, prjs)




