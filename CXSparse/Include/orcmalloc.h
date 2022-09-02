#ifndef _ORCMALLOC_H
#define _ORCMALLOC_H
#include <stdlib.h>

typedef void* (*malloc_func)(size_t size);
typedef void* (*calloc_func)(size_t num, size_t size);
typedef void* (*realloc_func)(void *ptr, size_t new_size);
typedef void (*free_func)(void *ptr);

typedef struct
{
    malloc_func malloc;
    calloc_func calloc;
    realloc_func realloc;
    free_func free;
} allocator_t;


void *_malloc(size_t size);
void *_calloc(size_t num, size_t size);
void *_realloc(void *ptr, size_t new_size);
void _free(void *ptr);
void cs_register_allocator(const allocator_t *allocator);

#endif
