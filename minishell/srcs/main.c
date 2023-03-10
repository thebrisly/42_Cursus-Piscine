/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:40:00 by dferreir          #+#    #+#             */
/*   Updated: 2023/03/10 12:24:39 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	expander(t_minishell *ms, int i)
{
	int		j;
	int		x;
	char 	*res;
	char 	*str;
	char 	*tmp_str;

	j = -1;
	x = -1;
	res = ft_calloc(1000, sizeof(char));
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
			tmp_str = get_value(ms, ft_strtrim(ft_split(ft_split(ft_substr(ms->args[i], j + 1, ft_strlen(ms->args[i])), ' ')[0], '\"')[0], "\""));
			if (tmp_str)
				str = ft_strdup(tmp_str);
			if (str)
			{
				ft_strlcat(res, str, ft_strlen(str) + j + 1);
				x += ft_strlen(str) + j + 1;
				j += ft_strlen(str) + 1;
			}
		}
		else
			res[++x] = ms->args[i][j];
	}
	ms->args_tmp[i - ms->start] = ft_strdup(res);
	free(str);
	free(res);
}

void	minishell(t_minishell *ms)
{
	int	i;

	while (1)
	{
		ms->err = 0;
		ms->start = ms->end + 1;
		i = ms->start - 1;
		while (ms->args[++i])
		{
			if (!ft_strncmp(ms->args[i], "&&", 3))
				break ;
			else if (!ft_strncmp(ms->args[i], "||", 3))
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
		if (!ms->args_tmp[1])
			str = ft_strdup(ms->args_tmp[0]);
/*		if (!ft_strncmp(ms->args[ms->end], "|", 2))
		{
			if (!ms->pip)
			{
				dup2(ms->pipe[1], 1);
				ms->pip = 1;
			}
			else
			{
				dup2(ms->pipe[0], 0);
				ms->pip = 2;
			}
		}
		else
*/			ms->pip = 0;
		if (!ms->or)
		{
			if(is_builtin(ms))
				ms->err_prev = 0;
			else
			{
				ms->cmd = get_cmd(ms->paths, ms->args_tmp[0]);
				if (ms->cmd)
				{
					ms->pid = fork();
					if (!ms->pid)
					{
						execve(ms->cmd, ms->args_tmp, ms->env);
						ms->err = 1;
						exit(1);
					}
					ms->err_prev = 0;
					wait(0);
				}
				else
					ms->err = 127;
				free(ms->cmd);
			}
			if ((!ms->args[ms->end] || ft_strncmp(ms->args[ms->end], "||", 3)) && ms->err)
				printf("%s does not exist\n", ms->args_tmp[0]);
			if (ms->args[ms->end] && !ft_strncmp(ms->args[ms->end], "||", 3) && !ms->err)
				ms->or = 1;
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
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell ms;

	if (argc == 1 && !ft_strncmp("./minishell", argv[0], 12))
	{
		ms.env = envp;
		ms.env_dup = 0;
		ms.env_dup2 = 0;
		ms.err_prev = 0;
		env_init(&ms);
		ms.paths = get_path(ms.env);
		while (1)
		{
			ft_putstr_fd("\033[0;91m₼ℹηℹ\033[1;91mℍ\033[0;91mΞ⅃L⫸ \033[0m", 2);
			signal_init();
			ms.prompt = get_next_line(0);
			ms.dol = 0;
			ms.or = 0;
			ms.quote = 0;
			ms.end = -1;
			if (str_to_array(&ms))
				minishell(&ms);
		}
	}
	else
		print_err("\"./minishell\" must be the only argument");
}

