SRCS	= $(wildcard *.c)

OBJS	= ${SRCS: .c=.o}

NAME	= libft.a

CC		= gcc
RM

CFLAGS 	= -Wall -Wextra -Werror

${NAME}:	${OBJS}
		${CC} -o ${NAME} ${OBJS} 

all:	${NAME}

clean:
		rm ${OBJS}

fclean:	clean
		rm ${NAME}