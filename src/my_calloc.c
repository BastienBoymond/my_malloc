/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_calloc
*/

#include "../include/my_malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void *ptr = NULL;

    if (nmemb == 0 || size == 0)
        return NULL;
    if (2147483647 < nmemb * size)
        return NULL;
    ptr = malloc(nmemb * size);
    if (ptr == NULL)
        return NULL;
    memset(ptr, 0, nmemb * size);
    return ptr;
}
