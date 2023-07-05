SRCS	= $(wildcard */*.c *.c)

OBJS	= ${SRCS:.c=.o}

NAME 	= libft.a

CC 		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -g

.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
