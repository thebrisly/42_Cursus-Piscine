/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:50:50 by dferreir          #+#    #+#             */
/*   Updated: 2023/04/04 15:02:10 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	continues_heredoc(t_minishell *ms)
{
	int	i;

	i = -1;
	while (ms->args[ms->start + ms->i + 2 + ++i])
	{
		if (!ft_strncmp(ms->args[ms->start + ms->i + 2 + i], ">", 2))
			ms->output = open(ms->args[ms->start + ms->i + 3 + i],
					O_CREAT | O_RDWR | O_TRUNC, 0644);
		else if (!ft_strncmp(ms->args[ms->start + ms->i + 2 + i], "<", 2))
			ms->input = open(ms->args[ms->start + ms->i + 3 + i], O_RDONLY);
		else if (!ft_strncmp(ms->args[ms->start + ms->i + 2 + i], ">>", 3))
			ms->output = open(ms->args[ms->start + ms->i + 3 + i],
					O_WRONLY | O_APPEND | O_CREAT, 0644);
	}
	dup2(ms->output, 1);
	dup2(ms->input, 0);
}

void	exec_heredoc(t_minishell *ms)
{
	char	**tmp;

	ms->pid = fork();
	if (!ms->pid)
	{
		tmp = malloc((ms->i + 1) * sizeof(char *));
		tmp[ms->i] = 0;
		while (--ms->i >= 0)
			tmp[ms->i] = ft_strdup(ms->args[ms->start + ms->i]);
		ms->cmd = get_cmd(ms->paths, ms->args[ms->start]);
		dup2(ms->input, 0);
		execve(ms->cmd, tmp, ms->env);
		exit(1);
	}
	wait(0);
}

int	pipe_redir(t_minishell *ms)
{
	int	i;
	int	j;

	i = ms->start - 1;
	j = 0;
	if (!ms->args[ms->end])
		return (0);
	while (++i <= ms->end)
		if (!ft_strncmp(ms->args[i], ">", 2)
			|| !ft_strncmp(ms->args[i], ">>", 3))
			j = 1;
	if (!ft_strncmp(ms->args[ms->end], "|", 2))
	{
		if (j)
		{
			dup2(ms->input, 0);
			if (ms->pid)
				dup2(ms->ter_out, 1);
		}
		else
			return (1);
	}
	return (0);
}

void	heredoc_2(t_minishell *ms)
{
	if (ms->args[ms->end] && !ft_strncmp(ms->args[ms->end], "|", 2))
		ms->pip = 1;
	if (ms->args[ms->end] && !ft_strncmp(ms->args[ms->end], "||", 3)
		&& !ms->err)
		ms->or = 1;
	continues_heredoc(ms);
	pipe(ms->pipe);
	ms->pid = fork();
	if (!ms->pid)
	{
		if (pipe_redir(ms))
		{
			dup2(ms->pipe[1], 1);
			close(ms->pipe[0]);
		}
		exec_heredoc(ms);
		exit(1);
	}
	if (pipe_redir(ms))
	{
		dup2(ms->pipe[0], 0);
		close(ms->pipe[1]);
	}
	wait(0);
}

void	heredoc_mod(t_minishell *ms, char *str, int file)
{
	free(str);
	close(file);
	ms->input = open(".heredoc", O_RDONLY);
	dup2(ms->input, 0);
	if (ms->input < 0)
	{
		unlink(".heredoc");
		print_err("Error reading from heredoc file descriptor");
	}
	heredoc_2(ms);
}

int	is_hd(t_minishell *ms)
{
	if (ms->args[ms->start + ms->i + 1])
		return (1);
	printf("syntax error near unexpected token 'newline'\n");
	ms->i = 173;
	return (0);
}

int	heredoc_input(t_minishell *ms)
{
	int		file;
	char	*str;

	while (ms->args[ms->start + ++ms->i]
		&& ft_strncmp(ms->args[ms->start + ms->i], "<<", 3));
	if (ms->args[ms->start + ms->i]
		&& !ft_strncmp(ms->args[ms->start + ms->i], "<<", 3) && is_hd(ms))
	{
		file = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (file < 0)
			print_err("Error creating temporary heredoc file descriptor");
		while (1)
		{
			str = readline("\033[0;91m> \033[0m");
			if (!str || !ft_strncmp(ms->args[ms->start + ms->i + 1],
					str, ft_strlen(str) + 1))
				break ;
			print_heredoc(str, file);
			free(str);
		}
		heredoc_mod(ms, str, file);
		return (1);
	}
	return (0);
}
