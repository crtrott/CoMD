/// \file
/// Wrappers for memory allocation.

#ifndef _MEMUTILS_H_
#define _MEMUTILS_H_

#include <stdlib.h>
#include <Kokkos_Core.hpp>

#define freeMe(s,element) {if(s->element) comdFree<int>((int*)s->element);  s->element = NULL;}

template<class T>
T* comdMalloc(size_t n)
{
   return (T*) Kokkos::kokkos_malloc(n*sizeof(T));
}

template<class T>
T* comdCalloc(size_t num)
{
   return (T*) Kokkos::kokkos_malloc(num*sizeof(T));
}

template<class T>
T* comdRealloc(const T* ptr, size_t n)
{
   return (T*) Kokkos::kokkos_realloc<>(ptr, n*sizeof(T));
}

template<class T>
void comdFree(T *ptr)
{
   Kokkos::kokkos_free<>(ptr);
}
#endif
