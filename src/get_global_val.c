/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** get_global_val
*/

#include "../include/my_malloc.h"

void **get_mem(void)
{
    static void *my_zone = NULL;

    return (&my_zone);
}

int *get_nb_page(void)
{
    static int nb_page = 0;

    return (&nb_page);
}

int *get_alloc(void)
{
    static int nb_alloc = 0;

    return (&nb_alloc);
}
