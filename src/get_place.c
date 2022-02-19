/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** get_place
*/

#include "../include/my_malloc.h"

void *get_next_pointer(void *ptr)
{
    block_t *block = (block_t *)ptr;
    void *next_pointer = (void *)block + block->size + sizeof(block_t);

    return (next_pointer);
}

size_t get_space_used(void)
{
    void **my_zone = get_mem();
    int *nb_alloc = get_alloc();
    void *temp = *my_zone;
    size_t memory_used = 0;
    block_t *block = (block_t *)temp;

    if (nb_alloc == 0)
        return (0);
    for (int i = 0; i < *nb_alloc; i++) {
        block = (block_t *)temp;
        memory_used += block->size + sizeof(block_t);
        temp = get_next_pointer(temp);
    }
    return (memory_used);
}
