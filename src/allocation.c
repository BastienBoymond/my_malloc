/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** allocation
*/

#include "../include/my_malloc.h"

int have_enough_space(size_t size, size_t size_memory)
{
    int *nb_page = get_nb_page();
    size_t page_size = getpagesize();
    size_t memory_allowed = page_size * (*nb_page);
    int i = 0;

    while (size + size_memory + sizeof(block_t) >
            memory_allowed + (page_size * i)) {
        i++;
    }
    return i;
}

void give_space(int nbr_alloc)
{
    void **my_zone = get_mem();
    int *nb_page = get_nb_page();
    int page_size = getpagesize();

    if (*nb_page == 0) {
        *my_zone = sbrk(page_size * (nbr_alloc * 2));
    } else {
        sbrk(page_size * (nbr_alloc * 2));
    }
    *nb_page += nbr_alloc * 2;
}

void *best_fit_func(size_t size)
{
    void **my_zone = get_mem();
    int *nb_alloc = get_alloc();
    void *temp = *my_zone;
    block_t *block = (block_t *)temp;
    void *best_fit = NULL;

    for (int i = 0; i < *nb_alloc; i++) {
        block = (block_t *)temp;
        if (block->free == 1 && block->size == size) {
            block->free = 0;
            best_fit = temp + sizeof(block_t);
            return best_fit;
        }
        temp = get_next_pointer(temp);
    }
    return NULL;
}

void *create_meta_data(size_t size, size_t size_memory)
{
    block_t block;
    void **my_zone = get_mem();
    void *best_fit = NULL;
    int *nb_alloc = get_alloc();

    best_fit = best_fit_func(ALIGN_ADDRESSES(sizeof(block_t) + size, 8)
    - sizeof(block_t));
    if (best_fit != NULL)
        return best_fit;
    block.size = ALIGN_ADDRESSES(sizeof(block_t) + size, 8) - sizeof(block_t);
    block.free = 0;
    memcpy(((*my_zone) + size_memory), &block, sizeof(block_t));
    *nb_alloc += 1;
    return ((*my_zone) + size_memory + sizeof(block_t));
}
