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

#include "manager.h"
#include <cassert>
#include <algorithm>
#include <iostream>
using namespace std;

static inline size_t NextPowerOfTwo(size_t sz) {
  sz -= 1;
  sz = sz | (sz >> 1);
  sz = sz | (sz >> 2);
  sz = sz | (sz >> 4);
  sz = sz | (sz >> 8);
  sz = sz | (sz >> 16);
  return (sz + 1);
}

MemoryManager* MemoryManager::msInstance = 0;

MemoryManager& MemoryManager::Instance(size_t chunkSize, size_t smallSize) {
  //static MemoryManager mmgr = MemoryManager(chunkSize, smallSize);
  //return mmgr;
  if (!msInstance) {
    new MemoryManager(chunkSize, smallSize);
    assert(msInstance != 0);
  }
  return *msInstance;
}

MemoryManager* MemoryManager::InstancePtr() {
  return msInstance;
}

MemoryManager::MemoryManager(size_t chunkSize, size_t smallSize)
  : mSmallSize(smallSize), mChunkSize(chunkSize), mLastAlloc(0), mLastDealloc(0) {
  assert(msInstance == 0);
  msInstance = this;
}

MemoryManager::~MemoryManager() {
#ifdef _DEBUG
  cout << "Clear managed memory... " << endl;
#endif
  mAllocators.clear();
  msInstance = 0;
}
    
void* MemoryManager::allocate(size_t numBytes) {
  if (numBytes == 0) {
#ifdef _DEBUG
    cerr << "*** 0 bytes allocation detected !" << endl;
#endif
    return NULL;
  }
  if (numBytes > mSmallSize) {
#ifdef _DEBUG
    cout << "### Too big for memory manager (" << numBytes << ")" << endl;
#endif
    return ::operator new(numBytes);
  } else {
    numBytes = NextPowerOfTwo(numBytes);
    if (mLastAlloc && mLastAlloc->getBlockSize() == numBytes) {
      return mLastAlloc->allocate();
    } else {
      AllocatorIterator it = std::lower_bound(mAllocators.begin(), mAllocators.end(), numBytes);
      if (it == mAllocators.end() || it->getBlockSize() != numBytes) {
        it = mAllocators.insert(it, ChunkAllocator(mChunkSize, numBytes));
        mLastDealloc = &(mAllocators.front());
      }
      mLastAlloc = &*it;
      return mLastAlloc->allocate();
    }
  }
}

void MemoryManager::deallocate(void *ptr, size_t numBytes) {
  if (numBytes == 0) {
#ifdef _DEBUG
    cerr << "*** 0 bytes deallocation detected !" << endl;
#endif
    return;
  }
  if (numBytes > mSmallSize) {
#ifdef _DEBUG
    cout << "### Free big memory chunk (" << numBytes << ")" << endl;
#endif
    ::operator delete(ptr);
  } else {
    numBytes = NextPowerOfTwo(numBytes);
    if (mLastDealloc && mLastDealloc->getBlockSize() == numBytes) {
      mLastDealloc->deallocate(ptr);
    } else {
      AllocatorIterator it = std::lower_bound(mAllocators.begin(), mAllocators.end(), numBytes);
      assert(it != mAllocators.end());
      assert(it->getBlockSize() == numBytes);
      mLastDealloc = &*it;
      mLastDealloc->deallocate(ptr);
    }
  }
}

