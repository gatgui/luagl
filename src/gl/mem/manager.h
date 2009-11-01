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

#ifndef __mem_manager_h_
#define __mem_manager_h_

#include "chunkallocator.h"
#include <vector>

class MemoryManager {
  
  public:
  
    static MemoryManager& Instance(size_t chunkSize=8192, size_t smallSize=256);
    static MemoryManager* InstancePtr();
    
    ~MemoryManager();
    
    void* allocate(size_t numBytes);
    void deallocate(void *ptr, size_t numBytes);
    
  private:
    
    MemoryManager(size_t chunkSize, size_t smallSize);
    
  private:
    
    static MemoryManager *msInstance;
    
    typedef std::vector<ChunkAllocator> AllocatorVector;
    typedef AllocatorVector::iterator AllocatorIterator;
    typedef AllocatorVector::const_iterator AllocatorConstIterator;
    
    size_t mSmallSize;
    size_t mChunkSize;
    AllocatorVector mAllocators;
    ChunkAllocator *mLastAlloc;
    ChunkAllocator *mLastDealloc;
};

#endif
