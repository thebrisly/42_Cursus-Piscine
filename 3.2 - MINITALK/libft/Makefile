# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 13:23:30 by lfabbian          #+#    #+#              #
#    Updated: 2022/12/16 13:28:15 by lfabbian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_isalpha.c \
	ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
	ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c  ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c

BONUS	= ft_lstadd_front_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c

OBJS	= ${SRCS:.c=.o}
OBJS_BONUS	= ${BONUS:.c=.o}

NAME	= libft.a

CC		= gcc
RM		= rm -f

CFLAGS 	= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

bonus:		${OBJS} ${OBJS_BONUS}
			ar rcs ${NAME} ${OBJS} ${OBJS_BONUS}
