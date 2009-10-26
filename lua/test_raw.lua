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

require "luaraw"

--[[
d = raw.BufferStructure.new()
p = d:add_field("position")
p:add_field("x")
p:add_field("y")
p:add_field("z")
n = d:add_field("normal")
n:add_field("x")
n:add_field("y")
n:add_field("z")
d:finalize()
]]

print("Create structure")
d = raw.MakeStructure({"position", {"x","y","z"}}, {"normal", {"x","y","z"}})

print("  "..tostring(d))
print("  has field \"position\": "..tostring(d:has_field("position")))
print("  has field \"x\": "..tostring(d:has_field("x")))
print("  is finalized: "..tostring(d:is_finalized()))
print("  is terminal: "..tostring(d:is_terminal()))
print("  field \"normal\" index: "..tostring(d:field_index("normal")))
print("  field \"x\" index: "..tostring(d:field_index("x")))
print("  offset: "..tostring(d:offset()))
print("  \"normal\": "..tostring(d:field("normal")))
print("  \"normal\" field count: "..tostring(d:field("normal"):field_count()))
print("  \"normal.y\" index: "..tostring(d:field("normal"):field_index("y")))
print("  \"position\" offset: "..tostring(d:field("position"):offset()))
print("  \"position.z\" offset: "..tostring(d:field("position"):field("z"):offset()))
print("  \"normal\" offset: "..tostring(d:field("normal"):offset()))
print("  \"normal.z\" offset: "..tostring(d:field("normal"):field("z"):offset()))
--d:add("texcoord0")

print("Allocate new buffer")
b = raw.StructuredBuffer.new(raw.Float, d, 20)
print("  structure: "..tostring(b:structure()))
print("  type: "..tostring(b:type()))
print("  element count: "..tostring(b:element_count()))
print("  element byte size: "..tostring(b:element_size()))
print("  field count: "..tostring(b:field_count()))
print("  \"position\" field offset: "..tostring(b:field_offset("position")))
print("  \"normal\" field offset: "..tostring(b:field_offset("normal")))

print("Get sub buffer \"normal\"")
n = b:field_buffer("normal")
print("  structure: "..tostring(n:structure()))
print("  element count: "..tostring(n:element_count()))
print("  element size: "..tostring(n:element_size()))
print("  field count: "..tostring(n:field_count()))
print("  \"z\"field offset: "..tostring(n:field_offset("z")))

-- rename field_stride -> element_stride
print("Set values in buffer")
for i=1, b:element_count() do
  --off = (i-1) * b:element_stride()
  off = b:element_offset(i)
  for j=1, b:field_count() do
    print("@"..(off+j).." (i: "..i..", j: "..j..") = "..(i+j))
    b[off+j] = i + j
  end
end

print("Get values in buffer")
print("  b[2].position.x = "..(b:element(2).position.x))
print("  b[2].position.z = "..(b:element(2).position.z))
print("  b[2].normal.z = "..(b:element(2).normal.z))
print("  b[7] = "..b[7])
print("  b[9] = "..b[9])
print("  b[12] = "..b[12])
b:element(2).position.x = -20
print("  b[2].position.x = "..(b:element(2).position.x))

print("Set normals")
normals = b.normal
foff = b:field_offset("normal")
print("  field count: "..normals:field_count())
for i=1, normals:element_count() do
  --off = (i-1) * normals:element_stride()
  off = normals:element_offset(i)
  print("@"..(off+foff+1).."~"..(off+foff+3).." (i: "..i..", j: [1~3]) = ["..(off-1).."~"..(off-3).."]")
  normal = normals:element(i)
  normal.x = off-1
  normal.y = off-2
  normal.z = off-3
end

print("Get normals")
print("b[118] = "..b[118])
print("b[119] = "..b[119])
print("b[120] = "..b[120])


print("Buffer print")
print(b)
print("Positions")
print(b.position)
print("Normals")
print(b.normal)


print("Test iterator")
for e in b:elements() do
  px = e.position.x
  py = e.position.y
  pz = e.position.z
  nx = e.normal.x
  ny = e.normal.y
  nz = e.normal.z
  print("[("..px..", "..py..", "..pz.."), ("..nx..", "..ny..", "..nz..")]")
end


print("Test simple buffer")
sb = raw.ByteBuffer.new(20)
sb[16] = 320 -- 255
sb[11] = 157.987 -- 158
for i=1, sb:element_count() do
  print("@"..i..": "..sb[i])
end
print("  raw ptr: "..tostring(sb:raw_ptr()))

print("Constant")
print("  raw.Byte = "..tostring(raw.Byte))
print("  raw.Short = "..tostring(raw.Short))
print("  raw.Int = "..tostring(raw.Int))
print("  raw.Float = "..tostring(raw.Float))
print("  raw.Double = "..tostring(raw.Double))
--print(raw.Long)






