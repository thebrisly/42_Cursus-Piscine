#COLORS
GREEN		= \033[0;32m
RED 		= \033[0;31m
BOLD		= \033[1m
NORMAL		= \033[0m
UP 			= \033[A
CUT 		= \033[K

#OUTPUT
NAME		= ex01

HEADS_LIST	= 

SRCS		= 

OBJS	:= ${SRCS:.c=.o}

#COMMANDS
CC			= gcc
CFLAGS		= -std=c++98 -Wall -Wextra -Werror
AR			= ar rcs
MKDIR		= mkdir -p
RM			= rm -rf
LIBS		= -lft -L$(LIBFT_DIR)

all: ${NAME}

#Compile normal executable
${NAME}: ${OBJS}
	@${CC} -g ${CFLAGS} ${OBJS} -o ${NAME}
	@echo "$(GREEN)[$(BOLD)OK$(NORMAL)$(GREEN)]$(NORMAL) created and compiled object files"
	@echo "$(GREEN)[$(BOLD)OK$(NORMAL)$(GREEN)]$(NORMAL) $(BOLD)$(NAME)$(NORMAL) is ready"

#Clean obj files
clean:
	@${RM} ${OBJS}
	@echo "$(GREEN)[$(BOLD)OK$(NORMAL)$(GREEN)]$(NORMAL) object files deleted"

#Clean objs files and name
fclean:	clean
	@${RM} ${NAME}
	@echo "$(GREEN)[$(BOLD)OK$(NORMAL)$(GREEN)]$(NORMAL) $(BOLD)$(NAME)$(NORMAL) deleted"

re: fclean all

.PHONY: all clean fclean re