/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:46:09 by dferreir          #+#    #+#             */
/*   Updated: 2023/03/31 15:21:47 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	str_count_norm(t_minishell *ms)
{
	while (ms->prompt[ms->i] == ' ' || ms->prompt[ms->i] == '\t')
		ms->i++;
	ms->i--;
	ms->j++;
}

void	str_count(t_minishell *ms)
{
	ms->i = 0;
	ms->j = 0;
	ms->args_size = ft_calloc(100, sizeof(int));
	while (ms->prompt[ms->i] == ' ' || ms->prompt[ms->i] == '\t')
		ms->i++;
	while (ms->prompt[ms->i] && ms->prompt[ms->i] != '\n')
	{
		if (ms->prompt[ms->i] == '\"' || ms->prompt[ms->i] == '\'')
		{
			if (!ms->quote)
				ms->quote = ms->prompt[ms->i];
			else
				if (ms->prompt[ms->i] == ms->quote)
					ms->quote = 0;
			ms->args_size[ms->j]++;
		}
		else if (ms->prompt[ms->i] != ' ' && ms->prompt[ms->i] != '\t')
			ms->args_size[ms->j]++;
		else if ((ms->prompt[ms->i] == ' ' || ms->prompt[ms->i] == '\t')
			&& ms->quote)
			ms->args_size[ms->j]++;
		else
			str_count_norm(ms);
		ms->i++;
	}
}

void	parse_quotes(t_minishell *ms)
{
	if (!ms->quote)
		ms->quote = ms->prompt[ms->x];
	else
		if (ms->prompt[ms->x] == ms->quote)
			ms->quote = 0;
	ms->args[ms->i][++ms->j] = ms->prompt[ms->x];
}

void	parsing(t_minishell *ms)
{
	if (ms->prompt[ms->x] == '\"' || ms->prompt[ms->x] == '\'')
		parse_quotes(ms);
	else if (ms->prompt[ms->x] != ' ' && ms->prompt[ms->x] != '\t')
		ms->args[ms->i][++ms->j] = ms->prompt[ms->x];
	else if ((ms->prompt[ms->x] == ' ' || ms->prompt[ms->x] == '\t')
		&& ms->quote)
		ms->args[ms->i][++ms->j] = ms->prompt[ms->x];
	else
	{
		while (ms->prompt[ms->x] == ' ' || ms->prompt[ms->x] == '\t')
			ms->x++;
		ms->x--;
		if (ms->prompt[ms->x + 1] && ms->prompt[ms->x + 1] != '\n')
		{
			ms->args[ms->i][++ms->j] = '\0';
			ms->i++;
			ms->j = -1;
		}
	}
	ms->x++;
}

int	str_to_array(t_minishell *ms)
{
	str_count(ms);
	ms->x = 0;
	ms->i = 0;
	ms->j = -1;
	if (!ms->args_size[0] || ms->prompt[0] == '\n' || !ms->prompt[0])
	{
		free(ms->prompt);
		return (0);
	}
	ms->quote = 0;
	while (ms->args_size[++ms->j])
		;
	ms->args = ft_calloc(ms->j + 1, sizeof(char *));
	if (!ms->args)
		return (0);
	while (--ms->j >= 0)
		ms->args[ms->j] = ft_calloc(ms->args_size[ms->j] + 1, sizeof(char));
	while (ms->prompt[ms->x] == ' ' || ms->prompt[ms->x] == '\t')
		ms->x++;
	while (ms->prompt[ms->x] && ms->prompt[ms->x] != '\n')
		parsing(ms);
	ms->args[ms->i][++ms->j] = '\0';
	ms->args[ms->i + 1] = 0;
	free(ms->prompt);
	return (1);
}
