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

Class = {}

function Class.new()

  local class = {}
  
  class.__index = class
  
  class.new = function (...)
    obj = {}
    setmetatable(obj, class)
    obj:initialize(...)
    return obj
  end
  
  return class
end

function Class.sub(baseclass)

  local class = Class.new()

  local metaclass = {}
  
  metaclass.__index = baseclass
  
  class.super = baseclass
  
  setmetatable(class, metaclass)
  
  return class
end


