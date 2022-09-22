# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 10:37:26 by lfabbian          #+#    #+#              #
#    Updated: 2022/09/22 10:51:18 by lfabbian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
rm -f libft.a
gcc -c -Wall -Wextra -Werror ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
ar -rcs libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
rm ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
