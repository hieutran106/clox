#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

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

int growCapacity(int oldCapacity);
uint8_t *growArray_uint8_t(uint8_t *pointer, int oldCount, int newCount);
void *freeArray(uint8_t *pointer, int oldCount);

#endif
