/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_free
*/

#include "../include/my_malloc.h"

void free(void *ptr)
{
    if (ptr == NULL)
        return;
    block_t *block = ptr - sizeof(block_t);
    block->free = 1;
}
