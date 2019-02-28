##
## EPITECH PROJECT, 2018
## ASM_minilibc_2018
## File description:
## Makefile
##

ASM 	=	nasm
DSRC	=	src/

SRC		=	$(DSRC)strlen.asm		\

ASFLAGS =	-felf64 -shared
OBJ 	=	$(SRC:.asm=.o)
NAME	=	libasm.so

all: $(OBJ)
	ld -o $(NAME) $(OBJ) -nostdlib

%.o:%.asm
	$(ASM) $(ASFLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

test_run: re
	make test_run -C $(DTESTS)

.PHONY: all clean fclean re test_run
