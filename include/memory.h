#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(type, pointer, oldCount, newCount)                          \
  (type *)reallocate(pointer, sizeof(type) * (oldCount),                       \
                     sizeof(type) * (newCount))

#define FREE_ARRAY(type, pointer, oldCount)                                    \
  reallocate(pointer, sizeof(type) * (oldCount), 0)

/*
 * Dynamic memory management in clox - allocating, freeing, changing the size of
 * an existing allocation
 *  - {oldSize: 0, newSize: non-zero} - Allocate new block
 *  - {oldSize: Non-zero, newSize: 0 } - Free allocation
 *  - {oldSize: Non-zero, newSize: smaller than oldSize } - Shrink existing
 * allocation
 *  - {oldSize: Non-zero, newSize: larger than oldSize }  - Grow existing
 * allocation
 */
void *reallocate(void *pointer, size_t oldSize, size_t newSize);

#endif
