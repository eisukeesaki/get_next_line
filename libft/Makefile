NAME = libft.a

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -c

all: $(NAME)

$(NAME): $(SRC) libft.h
	$(CC) $(CFLAGS) $(SRC)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
