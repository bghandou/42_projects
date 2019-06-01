CC = gcc

INCLUDE = ./include

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE)

SDL = -F/Library/Frameworks -framework SDL2

SRC1 = ./push/back_home.c \
	   ./push/check_bucks.c \
	   ./push/dig_check_free.c \
	   ./push/fill_bucket.c \
	   ./push/ismax.c \
	   ./push/push_swap.c \
	   ./push/reverse.c \
	   ./push/rotate.c \
	   ./push/small_arg.c \
	   ./push/swap.c \
	   ./push/take_args.c \
	   ./check/doubloons.c \
	   ./check/err.c

SRC2 = ./check/c_reverse.c \
	   ./check/c_rotate.c \
	   ./check/c_swap.c \
	   ./check/check_args.c \
	   ./check/checker.c \
	   ./check/checker_act.c \
	   ./check/vis_reverse.c \
	   ./check/vis_rotate.c \
	   ./check/vis_swap.c \
	   ./check/visu_check1.c \
	   ./check/visu_check2.c \
	   ./check/err.c \
	   ./check/doubloons.c \
	   ./push/ismax.c \
	   ./push/take_args.c

NAME1 = push_swap

NAME2 = checker

OBJ1 = $(SRC1:.c=.o)

OBJ2 = $(SRC2:.c=.o)

all : $(NAME1) $(NAME2)

$(NAME1) : $(OBJ1)
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1) -L libft/ -lft
$(NAME2) : $(OBJ2)
	$(CC) $(CFLAGS) $(SDL) -o $(NAME2) $(OBJ2) -L libft/ -lft

clean :
	make -C libft/ clean
	rm -f $(OBJ1) $(OBJ2)

fclean : clean
	make -C libft/ fclean
	rm -f $(NAME1) $(NAME2)

re : fclean all

.PHONY : clean fclean all re
