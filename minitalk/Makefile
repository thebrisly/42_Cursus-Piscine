SRCS	= client.c server.c

#OBJS	:= $(SRCS:%.c=%.o)
SRV_OBJ = server.o
CLT_OBJ = client.o

NAME	= minitalk

CC		= gcc
RM		= rm -f

CFLAGS 	= -Wall -Wextra -Werror -Ilibft -Iprintf

all:		${NAME}

%.o:	%.c
		${CC} ${CFLAGS} -c $< -o $@

${NAME}:	 server client

server:		${SRV_OBJ}
		@make -C libft
		@make -C printf
		${CC} ${CFLAGS} -Llibft -lft -Lprintf -lftprintf $? -o server

client:		${CLT_OBJ}
		@make -C libft
		@make -C printf
		${CC} ${CFLAGS} -Llibft -lft -Lprintf -lftprintf $? -o client

libft:
		make -C libft

printf:
		make -C printf

clean:
			make clean -C libft
			make clean -C printf
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		server client libft printf
