#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"

typedef enum { OP_RETURN } OpCode;

typedef struct {
  // Dynamic array
  // Store 2 numbers 
  //  - capacity: the number of elements in the array we have allocated
  //  - count: how many of those allocated entries are actually in use
  int count;
  int capacity;
  uint8_t *code;
} Chunk;

void initChunk(Chunk* chunk);

#endif