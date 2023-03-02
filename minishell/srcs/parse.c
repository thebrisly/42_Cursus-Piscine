/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:46:09 by dferreir          #+#    #+#             */
/*   Updated: 2023/03/02 14:46:38 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	str_count(t_minishell *ms)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	ms->args_size = malloc (100 * sizeof(int));
	while (ms->prompt[i] == ' ' || ms->prompt[i] == '\t')
		i++;
	while (ms->prompt[i] && ms->prompt[i] != '\n')
	{
		if (ms->prompt[i] == '\"' || ms->prompt[i] == '\'')
		{
			ms->args_size[j]++;
			if (ms->quote)
				ms->quote = 0;
			else
				ms->quote = 1;
		}
		else if ((ms->prompt[i] == '(' || ms->prompt[i] == ')') && !ms->quote)
		{
			if (ms->prompt[i - 1] != ' ' && ms->prompt[i - 1] != '\t')
				j++;
			ms->args_size[j]++;
			j++;
		}
		else if (ms->prompt[i] != ' ' && ms->prompt[i] != '\t')
			ms->args_size[j]++;
		else if ((ms->prompt[i] == ' ' || ms->prompt[i] == '\t') && ms->quote)
			ms->args_size[j]++;
		else
		{
			while (ms->prompt[i] == ' ' || ms->prompt[i] == '\t')
				i++;
			i--;
			j++;
		}
		i++;
	}
}

int	str_to_array(t_minishell *ms)
{
	int		x;
	int		i;
	int		j;

	x = 0;
	i = 0;
	j = -1;
	str_count(ms);
	if (!ms->args_size[0] || ms->prompt[0] == '\n')
		return (0);
	while (ms->args_size[++j]);
	ms->args = malloc((j + 1) * sizeof(char *));
	ms->end = j - 1;
	while (--j >= 0)
		ms->args[j] = malloc((ms->args_size[j] + 1) * sizeof(char));
	free(ms->args_size);
	while (ms->prompt[x] == ' ' || ms->prompt[x] == '\t')
		x++;
	while (ms->prompt[x] && ms->prompt[x] != '\n')
	{
		if (ms->prompt[x] == '\"' || ms->prompt[x] == '\'')
		{
			ms->args[i][++j] = ms->prompt[x];
			if (ms->quote)
				ms->quote = 0;
			else
				ms->quote = 1;
		}
		else if ((ms->prompt[x] == '(' || ms->prompt[x] == ')') && !ms->quote)
		{
			if (ms->prompt[x - 1] != ' ' && ms->prompt[x - 1] != '\t')
				i++;
			ms->args[i][0] = ms->prompt[x];
			ms->args[i][1] = '\0';
			i++;
			j = -1;
		}
		else if (ms->prompt[x] != ' ' && ms->prompt[x] != '\t')
			ms->args[i][++j] = ms->prompt[x];
		else if ((ms->prompt[x] == ' ' || ms->prompt[x] == '\t') && ms->quote)
			ms->args[i][++j] = ms->prompt[x];
		else
		{
			ms->args[i][++j] = '\0';
			while (ms->prompt[x] == ' ' || ms->prompt[x] == '\t')
				x++;
			x--;
			i++;
			j = -1;
		}
		x++;
	}
	if (ms->prompt[x - 1] == ')')
	{
		i--;
		j++;
	}
	if (ms->prompt[x - 1] == ' ' || ms->prompt[x - 1] == '\t')
		ms->args[i] = 0;
	else
	{
		ms->args[i][++j] = '\0';
		ms->args[i + 1] = 0;
	}
	free(ms->prompt);
	if (ms->quote)
		return (0);
	return (1);
}
