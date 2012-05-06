-- Copyright (C) 2009  Gaetan Guidet
-- 
-- This file is part of luagl.
-- 
-- luagl is free software; you can redistribute it and/or modify it
-- under the terms of the GNU Lesser General Public License as published by
-- the Free Software Foundation; either version 2.1 of the License, or (at
-- your option) any later version.
-- 
-- luagl is distributed in the hope that it will be useful, but
-- WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
-- Lesser General Public License for more details.
-- 
-- You should have received a copy of the GNU Lesser General Public
-- License along with this library; if not, write to the Free Software
-- Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
-- USA.

--package.path = package.path..";./lua/?.lua;./lua/?/init.lua"
--package.cpath = package.cpath..";./?.so;./lua/?.so;"

require "luagl.gl"
require "luagl.glu"
require "luagl.glut"
require "luabitop"
require "luaraw"

mesh_fmt = nil
mesh = nil
mesh_idx = nil
use_arrays = false

function check_vertex(element)
  if element[1] ~= element.position.x then
    error("position.x mismatch")
  end
  if element[2] ~= element.position.y then
    error("position.y mismatch")
  end
  if element[3] ~= element.position.z then
    error("position.z mismatch")
  end
  if element[4] ~= element.texcoord.s then
    error("texcoord.s mismatch")
  end
  if element[5] ~= element.texcoord.t then
    error("texcoord.t mismatch")
  end
end

function initMesh()

  mesh_fmt = raw.MakeStructure({"position", {"x", "y", "z"}}, {"texcoord", {"s", "t"}})

  mesh = raw.StructuredBuffer.new(raw.Float, mesh_fmt, 4)

  -- StructuredBuffer sucks ...
  
  mesh_idx = raw.Buffer.new(raw.Ushort, 4)
  mesh_idx[1] = 0
  mesh_idx[2] = 1
  mesh_idx[3] = 2
  mesh_idx[4] = 3
  
  v = mesh:element(1)
  v[1] = 0
  v[2] = 0
  v[3] = 0
  v[4] = 0
  v[5] = 0
  print("check v0")
  check_vertex(v)

  v = mesh:element(2)
  v.position.x = 1
  v.position.y = 0
  v.position.z = 0
  v.texcoord.s = 1
  v.texcoord.t = 0
  print("check v1")
  check_vertex(v)

  v = mesh:element(3)
  v[1] = 1
  v[2] = 1
  v[3] = 0
  v[4] = 1
  v[5] = 1
  print("check v2")
  check_vertex(v)

  v = mesh:element(4)
  v[1] = 0
  v[2] = 1
  v[3] = 0
  v[4] = 0
  v[5] = 1
  print("check v3")
  check_vertex(v)

end

function drawMesh()
  if use_arrays == true then
    positions = mesh:field_buffer("position")
    texcoords = mesh:field_buffer("texcoord")
    stride = mesh:element_size()
    gl.EnableClientState(gl.VERTEX_ARRAY)
    gl.ClientActiveTexture(gl.TEXTURE0)
    gl.EnableClientState(gl.TEXTURE_COORD_ARRAY)
    gl.TexCoordPointer(2, gl.FLOAT, stride, texcoords:raw_ptr())
    gl.VertexPointer(3, gl.FLOAT, stride, positions:raw_ptr())
    --gl.DrawArrays(gl.QUADS, 0, 4)
    gl.DrawElements(gl.QUADS, 4, gl.UNSIGNED_SHORT, mesh_idx:raw_ptr())
    gl.DisableClientState(gl.TEXTURE_COORD_ARRAY)
    gl.DisableClientState(gl.VERTEX_ARRAY)
  else
    gl.Begin(gl.QUADS)
    for e in mesh:elements() do
      gl.MultiTexCoord2f(gl.TEXTURE0, e.texcoord.s, e.texcoord.t)
      gl.Vertex3fv(e.position)
      --gl.Vertex3f(e.position.x, e.position.y, e.position.z)
    end
    gl.End()
  end
end

vprog_src = {
  "void main() {\n",
  "  gl_TexCoord[0] = gl_MultiTexCoord0;\n",
  "  gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;\n",
  "}\n"
}
fprog_src = {
  "void main() {\n",
  "  gl_FragColor = vec4(gl_TexCoord[0].s, gl_TexCoord[0].t, 1.0, 0.0);\n",
  "}\n"
}

prog = nil
vprog = nil
fprog = nil

function initShaders()
  prog = gl.CreateProgram()
  vprog = gl.CreateShader(gl.VERTEX_SHADER)
  gl.ShaderSource(vprog, vprog_src)
  gl.CompileShader(vprog)
  print("Compile vertex shader: " .. gl.GetShaderInfoLog(vprog))
  fprog = gl.CreateShader(gl.FRAGMENT_SHADER)
  gl.ShaderSource(fprog, fprog_src)
  gl.CompileShader(fprog)
  print("Compile fragment shader: " .. gl.GetShaderInfoLog(fprog))
  gl.AttachShader(prog, vprog)
  gl.AttachShader(prog, fprog)
  gl.LinkProgram(prog)
  print("Link: " .. gl.GetProgramInfoLog(prog))
  print("Vertex shader source: " .. gl.GetShaderSource(vprog))
  print("Fragment shader source: " .. gl.GetShaderSource(fprog))
end

-- callbacks

function display()
  gl.Clear(bitop.Or(gl.COLOR_BUFFER_BIT, gl.DEPTH_BUFFER_BIT))
  gl.PushMatrix()
  gl.UseProgram(prog)
  drawMesh()
  gl.UseProgram(0)
  gl.PopMatrix()
  glut.SwapBuffers()
end

function reshape(w, h)
  print("Reshape: "..tostring(w).."x"..tostring(h))
  gl.Viewport(0, 0, w, h)
  gl.MatrixMode(gl.PROJECTION)
  gl.LoadIdentity()
  gl.Ortho(0, 1, 0, 1, -1, 1)
  gl.MatrixMode(gl.MODELVIEW)
  gl.LoadIdentity()
  glut.PostRedisplay()
end

function keyboard(key, x, y)
  if (key == 27) then
    print("Quit")
    gl.Cleanup()
    os.exit()
  elseif key == 97 then -- 'A'
    use_arrays = not use_arrays
    glut.PostRedisplay()
  else
    print("Key: "..tostring(key))
  end
end

function menu(val)
  print("MenuEntry "..tostring(val).." selected")
  if (val == 1) then
    print("Quit")
    gl.Cleanup()
    os.exit()
  end
end

function submenu(val)
  print("SubMenuEntry "..tostring(val).." selected")
end

-- in millisecons
elapsed_time = 0
function timer(val)
  if val == 0 then
    gl.UseProgram(prog)
    loc = gl.GetUniformLocation(prog, "time")
    t = elapsed_time * 0.01
    gl.Uniform1f(loc, t)
    elapsed_time = elapsed_time + 1
    glut.PostRedisplay()
    glut.TimerFunc(1, timer, 0)
  end
end

function printMatrix(m)
  s = ""
  -- line
  for i=0, 3 do
    s = s .. "{ ";
    -- col
    for j=0, 3 do
      s = s .. tostring(m[1 + (i+j*4)]) .. " "
    end
    s = s .. "}\n"
  end
  print(s)
end

function initGL()
  gl.Init()
  print("OpenGL version: " .. tostring(gl.version))
  gl.ClearColor(0, 0, 0, 1)
  gl.ClearDepth(1)
  gl.DepthFunc(gl.LESS)
  gl.ShadeModel(gl.SMOOTH)
  gl.Enable(gl.LIGHTING)
  gl.Enable(gl.LIGHT0)
  gl.Enable(gl.DEPTH_TEST)
  gl.Enable(gl.CULL_FACE)
  gl.FrontFace(gl.CCW)
  initMesh()
  initShaders()
end

glut.Init()
glut.InitWindowPosition(50, 50)
glut.InitWindowSize(640, 480)
dm = bitop.Or(glut.RGBA, glut.DEPTH, glut.DOUBLE)
glut.InitDisplayMode(dm)
glut.CreateWindow("Lua GLUT")
initGL()
glut.DisplayFunc(display)
glut.ReshapeFunc(reshape)
glut.KeyboardFunc(keyboard)
--glut.TimerFunc(1, timer, 0)

smid = glut.CreateMenu(submenu)
glut.AddMenuEntry("Hello", 0)
glut.AddMenuEntry("Goodbye", 1)
mid = glut.CreateMenu(menu)
glut.AddSubMenu("Greetings", smid)
glut.AddMenuEntry("Quit", 1)
glut.AttachMenu(glut.RIGHT_BUTTON)

glut.MainLoop()

