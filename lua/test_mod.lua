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
--package.cpath = package.cpath..";./lua/?.dll;./?.so;./lua/?.so;"

require "class"

LifeForm = Class.new()
function LifeForm.initialize(self, age)
  self.age = age
end
function LifeForm.live(self)
  print(string.format("I'm a living entity of %d years old", self.age))
end

Human = Class.sub(LifeForm)
function Human.initialize(self, age, gender, name)
  self.super:initialize(age)
  self.gender = gender
  self.name = name
end
function Human.live(self)
  print(string.format("My name is %s. I'm a %s of %d years old",
                      self.name, self.gender, self.age))
end

-- create class instances

l = LifeForm.new(4)
l:live()

h = Human.new(18, "male", "Henry")
h:live()
