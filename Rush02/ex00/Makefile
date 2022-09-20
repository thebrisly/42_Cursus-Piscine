NAME = rush-02

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = *.c

OBJ = $(SRC:.c=.o)

INC = Includes

all:
	@$(CC) -I $(INC) $(CFLAGS) $? $(SRC) -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
