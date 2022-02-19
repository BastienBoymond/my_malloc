/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_malloc
*/

#include "../include/my_malloc.h"

void *malloc(size_t size)
{
    int i = 0;
    size_t size_memory = get_space_used();

    if (size == 0)
        return (malloc(4));
    i = have_enough_space(size, size_memory);
    give_space(i);
    return create_meta_data(size, size_memory);
}
