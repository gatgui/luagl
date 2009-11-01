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

#ifndef __memory_stlallocator_h_
#define __memory_stlallocator_h_

#include "manager.h"

template <class T>
class BaseAlloc {
  public:
    typedef T value_type;
};

template <class T>
class BaseAlloc<const T> {
  public:
    typedef T value_type;
};

template <class T>
class STLAlloc : public BaseAlloc<T> {
  public:
    
    typedef typename BaseAlloc<T>::value_type value_type;
#ifdef WIN32
    typedef value_type _FARQ* pointer;
    typedef value_type _FARQ& reference;
    typedef const value_type _FARQ *const_pointer;
    typedef const value_type _FARQ& const_reference;
    typedef _SIZT size_type;
    typedef _PDFT difference_type;
#else
    typedef value_type* pointer;
    typedef value_type& reference;
    typedef const value_type *const_pointer;
    typedef const value_type& const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
#endif
    
    template<class Other>
    struct rebind {
      typedef STLAlloc<Other> other;
    };

    STLAlloc() {
    }

    STLAlloc(const STLAlloc<T>&) { 
    }

    template<class Other>
    STLAlloc(const STLAlloc<Other>&) {
    }

    template<class Other>
    STLAlloc<T>& operator=(const STLAlloc<Other>&) {
      return (*this);
    }
    
    pointer address(reference ref) const {
      return (&ref);
    }

    const_pointer address(const_reference ref) const {
      return (&ref);
    }

    void deallocate(pointer ptr, size_type count) {
      MemoryManager::Instance().deallocate(ptr, count * sizeof(T));
    }

    pointer allocate(size_type count) {
      return ((pointer) MemoryManager::Instance().allocate(count * sizeof(T)));
    }

#ifdef WIN32
    pointer allocate(size_type count, const void _FARQ *) {
      return (allocate(count));
    }

    void construct(pointer ptr, const T& val) {
      new ((void _FARQ *)ptr) T(val);
    }
#else
    pointer allocate(size_type count, const void*) {
      return (allocate(count));
    }

    void construct(pointer ptr, const T& val) {
      new ((void*)ptr) T(val);
    }
#endif

    void destroy(pointer ptr) {
      ptr->~T();
    }
    
    size_type max_size() const {
      size_type count = (size_type)(-1) / sizeof(T);
      return (0 < count ? count : 1);
    }
};

template<class T, class U>
inline bool operator==(const STLAlloc<T>&, const STLAlloc<U>&) {
  return true;
}

template<class T, class U>
inline bool operator!=(const STLAlloc<T>&, const STLAlloc<U>&) {
  return false;
}

#endif
