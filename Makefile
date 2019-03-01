##
## EPITECH PROJECT, 2018
## ASM_minilibc_2018
## File description:
## Makefile
##

ASM 	=	nasm
DTESTS	=	tests/
DSRC	=	src/

SRC		=	$(DSRC)strlen.asm		\

SRC_UT	=	$(DTESTS)strlen_test.c	\

ASFLAGS =	-felf64 -shared
OBJ 	=	$(SRC:.asm=.o)
NAME	=	libasm.so

all: $(OBJ)
	ld --shared -o $(NAME) $(OBJ) -nostdlib

%.o:%.asm
	$(ASM) $(ASFLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

tests_run: all
	gcc -o units $(SRC_UT) $(OBJ) -lcriterion
	./units

.PHONY: all clean fclean re test_run
