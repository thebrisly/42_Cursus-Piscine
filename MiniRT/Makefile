
#COLORS
GREEN		= \033[0;32m
RED 		= \033[0;31m
BOLD		= \033[1m
NORMAL		= \033[0m
UP 			= \033[A
CUT 		= \033[K

SRCS = srcs/free.c srcs/colors.c srcs/cylinder_intersections.c srcs/errors.c srcs/intersections.c \
srcs/lightray.c srcs/miniRT.c srcs/mlbx.c srcs/ray.c srcs/sphere_plane_intersections.c \
srcs/math/math.c srcs/math/vec3d_others.c srcs/math/vec3d.c \
srcs/parsing/conversions.c srcs/parsing/linked_list.c srcs/parsing/objects_parsing.c \
srcs/parsing/parsing_utils.c srcs/parsing/parsing_utils2.c srcs/parsing/parsing.c srcs/parsing/scene_parsing.c \
srcs/utils/print_utils.c srcs/utils/malloc.c

OBJDIR	:= objs
OBJS	:= $(addprefix $(OBJDIR)/, ${SRCS:.c=.o})

NAME	= miniRT

CC		= gcc -g
RM		= rm -f

CFLAGS 	= -Wall -Wextra -Werror

all:		${NAME}

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -Ilibft -I./mlx -c $< -o $@

${NAME}:	${OBJS}
		@$(MAKE) -C libft
		@$(MAKE) -C mlx
		${CC} ${CFLAGS} $^ -Llibft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}
		@echo "$(GREEN)[$(BOLD)OK$(NORMAL)$(GREEN)]$(NORMAL) $(BOLD)$(NAME)$(NORMAL) is ready"

libft:
		make -C libft

mlx:
		make -C mlx

clean:
			make clean -C libft
			make clean -C mlx
			@${RM} -r ${OBJDIR}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY:		libft all bonus clean fclean re
