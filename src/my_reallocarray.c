/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_reallocarray
*/

#include "../include/my_malloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0)
        return NULL;
    return realloc(ptr, nmemb * size);
}
