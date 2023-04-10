/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:40:22 by dferreir          #+#    #+#             */
/*   Updated: 2023/04/09 15:04:29 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 && *s2) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	print_heredoc(char *str, int file)
{
	write(file, str, ft_strlen(str));
	write(file, "\n", 1);
}

void	check_dir_file(t_minishell *ms)
{
	int		i;
	char	*tmp;

	if (ft_strncmp(ms->args_tmp[0], "cd", 3))
	{
		i = 0;
		while (ms->args_tmp[++i] && ms->args_tmp[i][0] == '-')
			;
		i--;
		while (ms->args_tmp[++i] && ms->args_tmp[i])
		{
			tmp = ft_strdup(ms->args_tmp[i]);
			if (chdir(tmp) == -1)
				ms->err_prev = 1;
			else
				chdir("..");
			free (tmp);
		}
	}
}

char	**ft_split2(t_minishell *ms, char const *s, char c)
{
	char	**new_strs;
	int		start;

	ms->x = 0;
	ms->i = 0;
	ms->j = 0;
	start = -42;
	new_strs = malloc((word_counter(s, c) + 1) * sizeof(char *));
	if (!s || !new_strs)
		return (0);
	while ((size_t)ms->i <= ft_strlen(s))
	{
		if (s[ms->i] != c && start < 0)
			start = ms->i;
		else if ((s[ms->i] == c || !s[ms->i]) && start >= 0
			&& (!ms->x || !s[ms->i]))
		{
			ms->x++;
			new_strs[ms->j++] = str_maker(s, start, ms->i);
			start = -42;
		}
		ms->i++;
	}
	new_strs[ms->j] = 0;
	return (new_strs);
}

int	inside_cat(t_minishell *ms)
{
	int	i;

	i = ms->start;
	while (++i < ms->end)
		if (ms->args[i][0] != '-')
			break ;
	if (i == ms->end)
		return (1);
	return (0);
}
