/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_realloc
*/

#include "../include/my_malloc.h"

void *realloc(void *ptr, size_t size)
{
    void *new_ptr = NULL;
    block_t *block = NULL;

    if (ptr == NULL)
        return (malloc(size));
    if (size == 0) {
        free(ptr);
        return (NULL);
    }
    block = ptr - sizeof(block_t);
    if (ALIGN_ADDRESSES(sizeof(block_t) + size, 8) -
    sizeof(block_t) <= block->size)
        return (ptr);
    new_ptr = malloc(size);
    if (new_ptr == NULL)
        return (NULL);
    memcpy(new_ptr, ptr, block->size);
    free(ptr);
    return (new_ptr);
}
