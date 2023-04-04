/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:50:44 by dferreir          #+#    #+#             */
/*   Updated: 2023/04/04 14:58:18 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	init_vars(t_minishell *ms, int i, char **env)
{
	if (!i)
	{
		ms->ter_in = dup(0);
		ms->ter_out = dup(1);
		ms->env = env;
		ms->env_dup = 0;
		ms->err_prev = 0;
		env_init(ms);
	}
	if (i)
	{
		signal_init();
		dup2(ms->ter_in, 0);
		dup2(ms->ter_out, 1);
		dup2(ms->ter_in, ms->input);
		dup2(ms->ter_out, ms->output);
		ms->dol = 0;
		ms->or = 0;
		ms->quote = 0;
		ms->end = -1;
		ms->pip = 0;
		ms->cat = 0;
		ms->cat_nb = 0;
		g_cat = 2;
	}
}

void	init_vars_inloop(t_minishell *ms, int i)
{
	ms->paths = get_path(ms);
	ms->f_touched = 0;
	ms->outf = 0;
	ms->inf = 0;
	ms->appf = 0;
	ms->in_out_acc = 0;
	if (ft_strncmp(ms->args[0], "exit", 5))
		ms->err = 0;
	ms->start = ms->end + 1;
	i = ms->start - 1;
	while (ms->args[++i])
	{
		if (!ft_strncmp(ms->args[i], "&&", 3))
			break ;
		else if (!ft_strncmp(ms->args[i], "||", 3))
			break ;
		else if (!ft_strncmp(ms->args[i], "|", 2))
			break ;
	}
	ms->end = i;
	i = ms->start - 1;
	if (!ft_strncmp(ms->args[ms->start], "cat", 4)
		&& (ms->args[ms->end - 1][0] == '-'
		|| !ft_strncmp(ms->args[ms->end - 1], "cat", 4)))
		g_cat = 1;
}

int	init_heredoc(t_minishell *ms)
{
	int	i;

	i = -1;
	ms->i = -1;
	if (heredoc_input(ms))
	{
		if (ms->paths)
		{
			while (ms->paths[++i])
				free(ms->paths[i]);
			free(ms->paths);
		}
		if (ms->args[ms->end])
			return (1);
		else
			return (2);
	}
	return (0);
}

int	init_cat(t_minishell *ms)
{
	int	x;

	if (ms->cat != 1 && ms->start)
		return (0);
	if (ms->cat != 2 && !ft_strncmp(ms->args[ms->start], "cat", 4)
		&& ms->args[ms->end] && !ft_strncmp(ms->args[ms->end], "|", 2)
		&& inside_cat(ms))
	{
		if (!ms->start)
			ms->cat = 1;
		ms->cat_nb++;
		x = -1;
		if (ms->paths)
		{
			while (ms->paths[++x])
				free(ms->paths[x]);
			free(ms->paths);
		}
		return (1);
	}
	else
		ms->cat = 2;
	return (0);
}

void	init_prompt(t_minishell *ms, char **envp)
{
	init_vars(ms, 1, envp);
	ms->dev_null = open("/dev/null", O_WRONLY);
	ms->prompt = readline("\033[0;91m₼ℹηℹ\033[1;91mℍ\033[0;91mΞ⅃L⫸ \033[0m");
	if (!ms->prompt)
		mini_exit(ms);
	add_history(ms->prompt);
	if (str_to_array(ms))
		minishell(ms);
	free(ms->args_size);
}
