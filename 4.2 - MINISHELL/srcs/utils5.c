/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:10:36 by dferreir          #+#    #+#             */
/*   Updated: 2023/04/10 13:14:28 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	is_hd(t_minishell *ms)
{
	if (ms->args[ms->i + 1])
		return (1);
	printf("syntax error near unexpected token 'newline'\n");
	ms->i = 173;
	return (0);
}

void	prepare_heredoc(t_minishell *ms)
{
	if (ms->pip == 1)
	{
		pipe(ms->pipe);
		ms->pid = fork();
		if (!ms->pid)
		{
			if (!ms->in_out_acc)
			{
				dup2(ms->pipe[1], 1);
				close(ms->pipe[0]);
			}
			exec_heredoc(ms);
			exit(1);
		}
		dup2(ms->pipe[0], 0);
		close(ms->pipe[1]);
		wait(0);
	}
	else
		exec_heredoc(ms);
	if (ms->in_out_acc && ms->pip == 1)
	{
		dup2(ms->input, 0);
		dup2(ms->ter_out, 1);
	}
}

char	**else_exec_hd(t_minishell *ms)
{
	char	**tmp;

	tmp = malloc((ms->i - ms->start + 1) * sizeof(char *));
	tmp[ms->i] = 0;
	while (--ms->i >= ms->start)
		tmp[ms->i - ms->start] = ft_strdup(ms->args[ms->i]);
	ms->cmd = get_cmd(ms->paths, ms->args[ms->start]);
	if (!ms->cmd)
		printf("command not found: %s\n", ms->args[ms->start]);
	return (tmp);
}

int	is_single_cat(t_minishell *ms)
{
	char	*tmp;
	char	*tmp2;

	tmp = ms->args[ms->start];
	while (*tmp)
	{
		tmp2 = ft_strtrim(tmp, "\"\'");
		if (!ft_strncmp(tmp2, "cat", 4))
		{
			free(tmp2);
			return (1);
		}
		tmp++;
		free(tmp2);
	}
	return (0);
}

void	pipe_check(t_minishell *ms)
{
	pipe(ms->pipe);
	if (!ms->pip && ms->args[ms->end]
		&& !ft_strncmp(ms->args[ms->end], "|", 2))
		ms->pip = 1;
	else if (ms->pip && (!ms->args[ms->end]
			|| ft_strncmp(ms->args[ms->end], "|", 2)))
	{
		ms->pip = 2;
		ms->f_touched = 1;
	}
}
