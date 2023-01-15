SRCS	= fdf.c hooks.c start.c points.c draw.c limits.c

OBJS	:= $(SRCS:%.c=%.o)

NAME	= fdf

CC		= gcc
RM		= rm -f

CFLAGS 	= -Wall -Wextra -Werror

all:		${NAME}

%.o:	%.c
		${CC} ${CFLAGS} -Ilibft -Iprintf -I./minilibx -c $? -o $@

${NAME}:		${OBJS}
		@make -C libft
		@make -C printf
		@make -C minilibx
		${CC} ${CFLAGS} $^ -Llibft -lft -Lprintf -lftprintf -L./minilibx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

libft:
		make -C libft

printf:
		make -C printf

minilibx:
		make -C minilibx

clean:
			make clean -C libft
			make clean -C printf
			make clean -C minilibx
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		libft printf
