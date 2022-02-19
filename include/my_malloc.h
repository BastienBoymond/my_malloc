/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_malloc
*/

#ifndef MY_MALLOC_H_
    #define MY_MALLOC_H_

    #include <unistd.h>
    #include <string.h>
    #include <stdio.h>

    #define ALIGN_ADDRESSES(x, s) (((x) + (s) - 1) &~ ((s) - 1))

typedef struct __attribute__((__packed__)) block_s {
    size_t size;
    int free;
} block_t;

//mandatory
void *malloc(size_t size);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);
void free(void *ptr);

//allocation
void *create_meta_data(size_t size, size_t size_memory);
void give_space(int nbr_alloc);
int have_enough_space(size_t size, size_t size_memory);

//utils
size_t get_next_pow(size_t nbr);
void print_memory(size_t size);

//getters
void **get_mem(void);
int *get_nb_page(void);
int *get_alloc(void);

//get_place
size_t get_space_used(void);
void *get_next_pointer(void *ptr);

#endif /* !MY_MALLOC_H_ */
