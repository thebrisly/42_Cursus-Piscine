/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:38:06 by dferreir          #+#    #+#             */
/*   Updated: 2023/04/10 13:07:25 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	phase_check(t_minishell *ms)
{
	if (is_builtin(ms) == 1)
	{
		dup2(ms->dev_null, 1);
		exec_builtin(ms);
		if (!ms->in_out_acc)
			dup2(ms->ter_out, 1);
		else
			dup2(ms->output, 1);
	}
	else if (is_builtin(ms) == 2)
		exec_builtin(ms);
	if (ms->paths || !access(ms->args_tmp[0], 0))
		ms->cmd = get_cmd(ms->paths, ms->args_tmp[0]);
	if (!ms->cmd && !is_builtin(ms))
		printf("command not found: %s\n", ms->args_tmp[0]);
	if (ms->args[ms->end] && !ft_strncmp(ms->args[ms->end], "|", 2))
		pipe_check(ms);
	else
		ms->f_touched = 1;
}

void	phase_child(t_minishell *ms)
{
	if (!ms->pid)
	{
		if (ms->pip == 1)
		{
			if (!ms->in_out_acc)
				piper(ms, 1);
		}
		else if (ms->pip == 2)
		{
			dup2(1, ms->pipe[1]);
			close(ms->pipe[0]);
		}
		if (is_builtin(ms) == 1)
			exec_builtin(ms);
		else if (ms->cmd && is_builtin(ms) != 2)
			execve(ms->cmd, ms->args_tmp, ms->env);
		exit(ms->err);
	}
	else if (ms->pip && ms->pip != 2)
		piper(ms, 0);
}

void	phase_end(t_minishell *ms)
{
	if (ms->pip == 2)
	{
		dup2(0, ms->pipe[0]);
		ms->pip = 0;
	}
	waitpid(-1, &ms->err, 0);
	if (ms->err)
		ms->err /= 256;
	if (!ms->cmd && !is_builtin(ms))
		ms->err = 127;
	if (ms->cmd)
	{
		free(ms->cmd);
		ms->cmd = 0;
	}
	ms->err_prev = 0;
	check_dir_file(ms);
	if (ms->args[ms->end] && !ft_strncmp(ms->args[ms->end], "||", 3)
		&& !ms->err)
		ms->or = 1;
	write(1, "\b\b\b\b", 4);
}

void	phase_enter(t_minishell *ms)
{
	int	i;

	if (!ms->or)
	{
		phase_check(ms);
		ms->pid = fork();
		phase_child(ms);
		phase_end(ms);
	}
	else
		ms->or = 0;
	ms->err_prev = ms->err;
	i = -1;
	while (ms->args_tmp[++i])
		free(ms->args_tmp[i]);
	free(ms->args_tmp);
	i = -1;
	if (ms->paths)
	{
		while (ms->paths[++i])
			free(ms->paths[i]);
		free(ms->paths);
	}
}

void	minishell_end(t_minishell *ms)
{
	int	i;

	i = -1;
	while (++i < ms->cat_nb)
	{
		write(1, "  \b\b", 4);
		ms->prompt = get_next_line(0);
		free(ms->prompt);
	}
	i = -1;
	while (ms->args[++i])
		free(ms->args[i]);
	free(ms->args);
	if (g_cat > 2)
		ms->err_prev = g_cat;
	else
		g_cat = 2;
	dup2(ms->ter_in, 0);
	dup2(ms->ter_out, 1);
}
