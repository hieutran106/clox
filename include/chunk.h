#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "memory.h"

typedef enum { OP_RETURN } OpCode;

// Dynamic array
typedef struct Chunk {
  // count: how many of those allocated entries are actually in use
  int count;
  // capacity: the number of elements in the array we have allocated
  int capacity;
  uint8_t *code;
} Chunk;

void initChunk(Chunk *chunk);
void freeChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte);

#endif
