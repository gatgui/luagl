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

#ifndef __mem_chunkallocator_h_
#define __mem_chunkallocator_h_

#include <vector>

class ChunkAllocator {
  public:
    
    ChunkAllocator(size_t chunkSize, size_t blockSize=0);
    ChunkAllocator(const ChunkAllocator &rhs);
    ~ChunkAllocator();
    
    ChunkAllocator& operator=(const ChunkAllocator &rhs);
    
    void* allocate();
    void deallocate(void *ptr);
    
    inline size_t getBlockSize() const {
      return mBlockSize;
    }
    
    inline bool operator<(size_t sz) {
      return (mBlockSize < sz);
    }
    
  private:
  
    struct Chunk {
      unsigned char *data;
      unsigned char firstFreeBlock;
      unsigned char numFreeBlocks;
      
      void initialize(size_t blockSize, unsigned char numBlocks);
      void* allocate(size_t blockSize);
      void deallocate(void *ptr, size_t blockSize);
      void release();
    };
    
    typedef std::vector<Chunk> ChunkVector;
    typedef ChunkVector::iterator ChunkIterator;
    typedef ChunkVector::const_iterator ChunkConstIterator;
    
    size_t mBlockSize;
    unsigned char mNumBlocks;
    ChunkVector mChunks;
    Chunk *mLastAlloc;
    Chunk *mLastDealloc;
    mutable bool mOwns;
};



#endif
