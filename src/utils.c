/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** utils
*/

#include "../include/my_malloc.h"

size_t get_next_pow(size_t nbr)
{
    size_t pow = 1;

    for (; pow < nbr; pow *= 2);
    return (pow);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void print_memory(size_t size)
{
    size_t i = 0;
    void **my_zone = get_mem();
    void *temp = *my_zone;

    write(1, "Actual memory :\n", 17);
    for (; i < size; i++) {
        my_putchar((*(char *)*my_zone + '0'));
        (*my_zone)++;
    }

    my_putchar('\n');
    *my_zone = temp;
}
