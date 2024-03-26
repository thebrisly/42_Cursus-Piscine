# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 10:02:37 by lfabbian          #+#    #+#              #
#    Updated: 2022/11/12 14:48:34 by lfabbian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_check_type.c ft_put_c.c ft_put_d_i.c ft_put_s.c ft_put_u.c ft_put_x.c ft_put_p.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= gcc
RM		= rm -f

CFLAGS 	= -Wall -Wextra -Werror

all:		${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $?

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:  
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
