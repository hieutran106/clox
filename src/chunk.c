#include <stdlib.h>

#include "../include/chunk.h"
#include "../include/memory.h"

void initChunk(Chunk *chunk) {
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL;
}

void freeChunk(Chunk *chunk) {
    freeArray(chunk->code, chunk->capacity);
    initChunk(chunk);
}

void writeChunk(Chunk *chunk, uint8_t byte) {
    if (chunk->capacity < chunk->count + 1) {
        int oldCapacity = chunk->capacity;
        chunk->capacity = growCapacity(oldCapacity);
        chunk->code =
            growArray_uint8_t(chunk->code, oldCapacity, chunk->capacity);
    }
    chunk->code[chunk->count] = byte;
    chunk->count++;
}
