#include <stdlib.h>
#include "orcmalloc.h"

static allocator_t _allocator;

void *_malloc(size_t size)
{
    return _allocator.malloc(size);
}

void *_calloc(size_t num, size_t size)
{
    return _allocator.calloc(num, size);
}

void *_realloc(void *ptr, size_t new_size)
{
    return _allocator.realloc(ptr, new_size);
}

void _free(void *ptr)
{
    return _allocator.free(ptr);
}

void cs_register_allocator(const allocator_t *allocator)
{
    _allocator = *allocator;
}
