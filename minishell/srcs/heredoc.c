/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:50:50 by dferreir          #+#    #+#             */
/*   Updated: 2023/04/10 12:54:36 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	continues_heredoc(t_minishell *ms)
{
	int	i;

	i = -1;
	while (ms->args[ms->i + 2 + ++i])
	{
		if (ms->args[ms->i + 2 + i][0] == '|')
			break ;
		if (!ft_strncmp(ms->args[ms->i + 2 + i], ">", 2))
			ms->output = open(ms->args[ms->i + 3 + i],
					O_CREAT | O_RDWR | O_TRUNC, 0644);
		else if (!ft_strncmp(ms->args[ms->i + 2 + i], "<", 2))
			ms->input = open(ms->args[ms->i + 3 + i], O_RDONLY);
		else if (!ft_strncmp(ms->args[ms->i + 2 + i], ">>", 3))
			ms->output = open(ms->args[ms->i + 3 + i],
					O_WRONLY | O_APPEND | O_CREAT, 0644);
		if (!ft_strncmp(ms->args[ms->i + 2 + i], ">", 2)
			|| !ft_strncmp(ms->args[ms->i + 2 + i], "<", 2)
			|| !ft_strncmp(ms->args[ms->i + 2 + i], ">>", 3))
			ms->in_out_acc = 17;
	}
	if (ms->in_out_acc != 17)
		ms->in_out_acc = 0;
	dup2(ms->output, 1);
	dup2(ms->input, 0);
}

void	exec_heredoc(t_minishell *ms)
{
	int		i;
	char	**tmp;

	ms->pid = fork();
	if (!ms->pid)
	{
		if (ft_strncmp(ms->args[ms->start], "<<", 3))
			tmp = else_exec_hd(ms);
		else
		{
			i = ms->i + 2;
			tmp = malloc((ms->end - i + 1) * sizeof(char *));
			ms->i++;
			while (++ms->i < ms->end && ft_strncmp(ms->args[ms->i], "<", 2)
				&& ft_strncmp(ms->args[ms->i], ">", 2)
				&& ft_strncmp(ms->args[ms->i], ">>", 3))
				tmp[ms->i - i] = ft_strdup(ms->args[ms->i]);
			tmp[ms->i - i] = 0;
			ms->cmd = get_cmd(ms->paths, ms->args[i]);
		}
		dup2(ms->input, 0);
		execve(ms->cmd, tmp, ms->env);
		exit(1);
	}
	wait(0);
}

void	heredoc_2(t_minishell *ms)
{
	if (ms->args[ms->end] && !ft_strncmp(ms->args[ms->end], "|", 2))
		ms->pip = 1;
	if (ms->args[ms->end] && !ft_strncmp(ms->args[ms->end], "||", 3)
		&& !ms->err)
		ms->or = 1;
	continues_heredoc(ms);
	prepare_heredoc(ms);
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

int	heredoc_input(t_minishell *ms)
{
	int		file;
	char	*str;

	while (++ms->i < ms->end && ms->args[ms->i]
		&& ft_strncmp(ms->args[ms->i], "<<", 3));
	if (ms->args[ms->i]
		&& !ft_strncmp(ms->args[ms->i], "<<", 3) && is_hd(ms))
	{
		file = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (file < 0)
			print_err("Error creating temporary heredoc file descriptor");
		while (1)
		{
			str = readline("\033[0;91m> \033[0m");
			if (!str || !ft_strncmp(ms->args[ms->i + 1],
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
