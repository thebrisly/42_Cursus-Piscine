/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:03:17 by saeby             #+#    #+#             */
/*   Updated: 2022/09/18 21:57:39 by rjuriens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H
# define DEFAULT_DICT "numbers.dict"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

struct s_number
{
	char	*int_num;
	char	*letter_num;
};

typedef struct s_number	t_number;

void					ft_putchar(char c);
void					ft_putstr(char *str);
int						ft_strlen(char *str);
int						find_index(char *int_num, t_number *nums, int size);
int						ft_strcmp(char *s1, char *s2);
int						count_lines(char *file);
int						file_size(char *file);
unsigned long long int	ft_atoi(char *str);
unsigned long long int	ft_pow(unsigned long long int nb, int power);
char					*ft_strcat(char *dest, char *str);
int						ft_is_numeric(char *str);
int						ft_c_is_num(char c);
int						ft_char_is_alpha(char c);
int						ft_c_is_print(char c);
char					*ft_split_number(char *c_nb, t_number *tab, char *f);
char					*ft_split_hundreds(int nb, t_number *tab, char *file);
int						whitespaces(char *str, int *ptr_i);
char					*ft_strcat(char *dest, char *src);
char					*ft_strdup(char *src, int offset);
int						int_len(unsigned long long int nbr);
char					*ft_itoa(unsigned long long int nbr);
int						dict_error(void);
int						error(void);
int						parse_helper(int c[5], char *buf, t_number *nums);
int						check_nb_size(char *str);
int						fill_buffer(char *buffer, char *file);
void					num_index(int c[5], char *buffer, int f_size);
int						space_index(int c[5], char *buffer, int line_count);
int						after_colon_index(int c[5], char *buf, int fs, int lc);
void					letter_num_index(int c[5], char *buffer, int f_size);
char					*alloc_buffer(int size);
t_number				*alloc_nums_tab(int size);
t_number				*parse(char *file);

#endif
