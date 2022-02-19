##
## EPITECH PROJECT, 2022
## malloc_bootstrap
## File description:
## Makefile
##

RM		= rm -rf

CC        =    gcc

CFLAGS    =    -W -Wall -Wextra -fPIC

SRC_LIB    =    ./src/my_malloc.c \
				./src/my_free.c \
				./src/my_calloc.c \
				./src/my_realloc.c \
				./src/my_reallocarray.c \
				./src/allocation.c \
				./src/utils.c \
				./src/get_global_val.c \
				./src/get_place.c \

OBJ_LIB    =    $(SRC_LIB:.c=.o)

BINARY    =    libmy_malloc.so

all:    $(BINARY)

$(BINARY):   $(OBJ_LIB)
			gcc -shared -o libmy_malloc.so  $(OBJ_LIB)

clean:
	$(RM) *.o
	$(RM) *.so
	$(RM) ./src/*.o

fclean: clean
	$(RM) $(BINARY)
	$(RM) a.out

re:		fclean all
