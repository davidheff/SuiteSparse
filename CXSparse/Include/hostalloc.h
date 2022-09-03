#ifndef HOSTMALLOC_H
#define HOSTMALLOC_H

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

void *host_malloc(size_t size);
void *host_calloc(size_t num, size_t size);
void *host_realloc(void *ptr, size_t new_size);
void host_free(void *ptr);
void host_alloc_register(const allocator_t *allocator);

#endif /* HOSTMALLOC_H */
