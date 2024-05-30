#include "memory.h"
#include <stdint.h>
#include <stdlib.h>

void *reallocate(void *pointer, size_t oldSize, size_t newSize) {
    if (newSize == 0) {
        free(pointer);
        return NULL;
    }

    void *result = realloc(pointer, newSize);
    if (result == NULL)
        exit(1);
    return result;
}

int growCapacity(int oldCapacity) {
    return oldCapacity < 8 ? 8 : oldCapacity * 2;
}

uint8_t *growArray_uint8_t(uint8_t *pointer, int oldCount, int newCount) {
    return (uint8_t *)reallocate(pointer, sizeof(uint8_t) * oldCount,
                                 sizeof(uint8_t) * newCount);
}

void *freeArray(uint8_t *pointer, int oldCount) {
    reallocate(pointer, sizeof(uint8_t) * oldCount, 0);
}
