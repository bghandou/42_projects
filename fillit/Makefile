NAME = fillit

INCLUDES = libft

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I $(INCLUDES)

CFLAGSLINK = -Wall -Werror -Wextra

SRCS = backtracking.c check_error.c tools.c main.c stock_and_validate.c \
	   main_aux.c 

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(CFLAGSLINK) -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean all re clean
