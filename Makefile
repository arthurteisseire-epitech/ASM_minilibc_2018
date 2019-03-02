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
			$(DSRC)strchr.asm		\

SRC_UT	=	$(DTESTS)load_sym.c		\
			$(DTESTS)strlen_test.c	\
			$(DTESTS)strchr_test.c	\

ASFLAGS =	-felf64 -shared
LDFLAGS =   --shared -nostdlib
OBJ 	=	$(SRC:.asm=.o)
NAME	=	libasm.so

all: $(OBJ)
	ld -o $(NAME) $(OBJ) $(LDFLAGS)

%.o:%.asm
	$(ASM) $(ASFLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

tests_run: all
	gcc -o units $(SRC_UT) -lcriterion -ldl
	./units

.PHONY: all clean fclean re test_run
