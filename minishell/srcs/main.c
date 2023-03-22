/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:40:00 by dferreir          #+#    #+#             */
/*   Updated: 2023/03/22 13:01:47 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	*cutter(t_minishell *ms, char *str, int i)
{
	char 	**tmp_array;
	char 	*tmp;
	char	*tmp2;

	if (!str[i + 1])
		return ("$");
	tmp2 = ft_substr(str, i + 1, ft_strlen(str));
	i = -1;
	tmp_array = ft_split(tmp2, '\"');
	tmp = ft_strdup(tmp_array[0]);
	while (tmp_array[++i])
		free(tmp_array[i]);
	free(tmp_array);
	free(tmp2);
	tmp_array = ft_split(tmp, ' ');
	tmp2 = ft_strdup(tmp_array[0]);
	i = -1;
	while (tmp_array[++i])
		free(tmp_array[i]);
	free(tmp_array);
	free(tmp);
	i = -1;
	ms->dol = -1;
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
	{
		while (tmp2[++ms->dol] && tmp2[ms->dol] != '$');
		if (ms->dol > 0 && tmp2[ms->dol])
		{
			tmp = malloc((ms->dol + 1) * sizeof(char));
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
	return (0);
}

void	expander(t_minishell *ms, int i)
{
	int		j;
	int		x;
	char 	*res;
	char 	*tmp;

	j = -1;
	x = -1;
	res = ft_calloc(100, sizeof(char));
	ms->quote = 0;
	while (ms->args[i][++j])
	{
		if (ms->args[i][j] == '\'' || ms->args[i][j] == '\"')
		{
			if (!ms->quote)
				ms->quote = ms->args[i][j];
			else
			{
				if (ms->args[i][j] != ms->quote)
					res[++x] = ms->args[i][j];
				else
					ms->quote = 0;
			}
		}
		else if (ms->args[i][j] == '$' && (!ms->quote || ms->quote == '\"'))
		{
			tmp = cutter(ms, ms->args[i], j);
			if (tmp)
			{
				ft_strlcat(res, tmp, ft_strlen(tmp) + ft_strlen(res) + 1);
				x += ft_strlen(tmp);
				if (ms->dol == -1)
					x += 2;
			}
			if (ft_strlen(ms->args[i]) != 1)
			{
				if (ms->dol == -1)
				{
					j += ft_strlen(tmp);
					if (tmp[1] == '$')
						j--;
				}
				else if ((size_t)ms->dol > ft_strlen(ms->args[i]))
					j += ft_strlen(ft_strtrim(ft_split(ft_split(ft_substr(ms->args[i], j + 1, ft_strlen(ms->args[i])), ' ')[0], '\"')[0], "\""));
				else
					j += ms->dol;
				free(tmp);
			}
		}
		else
			res[++x] = ms->args[i][j];
	}
	ms->args_tmp[i - ms->start] = ft_strdup(res);
	free(res);
}

void	minishell(t_minishell *ms)
{
	int	i;

	while (1)
	{
		if (!cat)
			break ;
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
		while (++i < ms->end);
		ms->args_tmp = malloc((i + 1) * sizeof(char *));
		i = -1;
		while (++i < ms->end - ms->start)
			expander(ms, i + ms->start);
		ms->args_tmp[i] = 0;
		if (!ft_strncmp(ms->args[ms->start], "cat", 4) && (ms->args[ms->end - 1][0] == '-' || !ft_strncmp(ms->args[ms->end - 1], "cat", 4))/* && (!ms->start || ms->args[ms->start - 1][0] != '|')*/)
			cat = 1;
		if (!ms->or)
		{
			if (is_builtin(ms) == 2)
				exec_builtin(ms);
			ms->cmd = get_cmd(ms->paths, ms->args_tmp[0]);
			if ((ms->args[ms->end] && !ft_strncmp(ms->args[ms->end], "|", 2)) || ms->args)
			{
				pipe(ms->pipe);
				if (!ms->pip && ms->args[ms->end] && !ft_strncmp(ms->args[ms->end], "|", 2))
					ms->pip = 1;
				else if (ms->pip && (!ms->args[ms->end] || ms->args[ms->end][0] != '|'))
					ms->pip = 2;
			}
			ms->pid = fork();
			if (!ms->pid)
			{
				if (ms->pip == 1)
				{
					dup2(ms->pipe[1], 1);
					close(ms->pipe[0]);
				}
				else if (ms->pip == 2)
				{
					dup2(1, ms->pipe[1]);
					close(ms->pipe[0]);
				}
				if(is_builtin(ms) == 1)
					exec_builtin(ms);
				else if (ms->cmd && is_builtin(ms) != 2)
				{
					execve(ms->cmd, ms->args_tmp, ms->env);
					ms->err = 1;
				}
				exit(1);
			}
			else if (ms->pip && ms->pip != 2)
			{
				dup2(ms->pipe[0], 0);
				close(ms->pipe[1]);
			}
			if (ms->pip == 2)
			{
				dup2(0, ms->pipe[0]);
				ms->pip = 0;
			}
			wait(0);
			if (!ms->cmd && !is_builtin(ms))
				ms->err = 127;
			free(ms->cmd);
			ms->err_prev = 0;
			if ((!ms->args[ms->end] || ft_strncmp(ms->args[ms->end], "||", 3)) && ms->err)
				printf("command not found: %s\n", ms->args_tmp[0]);
			if (ms->args[ms->end] && !ft_strncmp(ms->args[ms->end], "||", 3) && !ms->err)
				ms->or = 1;
			write(1, "\b\b\b\b", 4);
		}
		else
			ms->or = 0;
		if (ms->err)
			ms->err_prev = ms->err;
		if (ft_strncmp(ms->args_tmp[0], "./minishell", 12))
		{
			i = -1;
			while (ms->args_tmp[++i])
				free(ms->args_tmp[i]);
			free(ms->args_tmp);
		}
		if (!ms->args[ms->end])
			break ;
	}
	i = -1;
	while (ms->args[++i])
		free(ms->args[i]);
	free(ms->args);
	free(ms->args_size);
	cat = 2;
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell ms;

	if (argc == 1 && !ft_strncmp("./minishell", argv[0], 12))
	{
		ms.input = dup(0);
		ms.env = envp;
		ms.env_dup = 0;
		ms.err_prev = 0;
		env_init(&ms);
		ms.paths = get_path(ms.env);
		while (1)
		{
		//	ft_putstr_fd("\033[0;91m₼ℹηℹ\033[1;91mℍ\033[0;91mΞ⅃L⫸ \033[0m", 2);
			signal_init();
		//	ms.prompt = get_next_line(ms.input);
			dup2(ms.input, 0);
			ms.prompt = readline("\033[0;91m₼ℹηℹ\033[1;91mℍ\033[0;91mΞ⅃L⫸ \033[0m");
			if (!ms.prompt)
				mini_exit(&ms);
			add_history(ms.prompt);
			ms.dol = 0;
			ms.or = 0;
			ms.quote = 0;
			ms.end = -1;
			ms.pip = 0;
			cat = 2;
			if (str_to_array(&ms))
				minishell(&ms);
		}
		rl_clear_history();
	}
	else
		print_err("\"./minishell\" must be the only argument");
}
