/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:02:16 by dferreir          #+#    #+#             */
/*   Updated: 2023/04/04 14:39:17 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	minishell_loop2(t_minishell *ms)
{
	int	i;

	i = -1;
	while (++i < ms->end - ms->start)
		expander(ms, i + ms->start);
	ms->args_tmp[i - ms->in_out_acc] = 0;
	phase_enter(ms);
	if (ms->f_touched)
	{
		dup2(ms->ter_in, 0);
		dup2(ms->ter_out, 1);
	}
}

void	minishell_loop1(t_minishell *ms)
{
	int	i;

	while (1)
	{
		i = -1;
		init_vars_inloop(ms, i);
		i = init_heredoc(ms);
		if (i == 1)
			continue ;
		else if (i == 2 || (!i && ms->i == 173))
			break ;
		ms->i = -1;
		i = -1;
		while (++i < ms->end)
			;
		if (init_cat(ms))
			continue ;
		ms->args_tmp = malloc((i + 1) * sizeof(char *));
		if (!ms->args_tmp)
			return ;
		minishell_loop2(ms);
		if (!ms->args[ms->end])
			break ;
	}
}

char	*cutter_start(char **tmp_array, char *tmp, char *tmp2, int i)
{
	i = -1;
	tmp_array = ft_split(tmp2, '\"');
	tmp = ft_strdup(tmp_array[0]);
	while (tmp_array[++i])
		free(tmp_array[i]);
	free(tmp_array);
	free(tmp2);
	i = -1;
	tmp_array = ft_split(tmp, '\'');
	tmp2 = ft_strdup(tmp_array[0]);
	while (tmp_array[++i])
		free(tmp_array[i]);
	free(tmp_array);
	free(tmp);
	tmp = ft_strdup(tmp2);
	free(tmp2);
	tmp_array = ft_split(tmp, ' ');
	tmp2 = ft_strdup(tmp_array[0]);
	i = -1;
	while (tmp_array[++i])
		free(tmp_array[i]);
	free(tmp_array);
	free(tmp);
	return (tmp2);
}

char	*cutter_middle(t_minishell *ms, char *tmp, char *tmp2)
{
	if (!ft_strncmp(tmp2, "?", 2))
	{
		tmp = ft_itoa(ms->err_prev);
		free(tmp2);
		return (tmp);
	}
	else if (!ft_strncmp(tmp2, "$$$$$$$$$$$$$$$$$$$$$$", ft_strlen(tmp2)))
	{
		tmp = ft_strjoin("$", tmp2);
		free(tmp2);
		return (tmp);
	}
	else
		return (cutter_end(ms, tmp, tmp2));
	return (0);
}

char	*cutter_end(t_minishell *ms, char *tmp, char *tmp2)
{
	int	i;

	i = -1;
	while (tmp2[++ms->dol] && tmp2[ms->dol] != '$')
		;
	if (ms->dol > 0 && tmp2[ms->dol])
	{
		tmp = malloc((ms->dol + 1) * sizeof(char));
		if (!tmp)
			return (0);
		while (++i < ms->dol)
			tmp[i] = tmp2[i];
		tmp[ms->dol] = 0;
	}
	else
		tmp = ft_strdup(tmp2);
	free(tmp2);
	tmp2 = get_value(ms, tmp);
	free(tmp);
	if (tmp2)
	{
		tmp = ft_strdup(tmp2);
		return (tmp);
	}
	return (tmp2);
}
