/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:40:00 by dferreir          #+#    #+#             */
/*   Updated: 2023/03/07 14:04:42 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

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
	//	while (--i >= 0)
	//		ms->args_tmp[i] = malloc((ms->args_size[i] + 1) * sizeof(char));
		i = -1;
		while (++i < ms->end - ms->start)
			ms->args_tmp[i] = ft_strdup(ms->args[i + ms->start]);
		ms->args_tmp[i] = 0;
//		if (!ft_strncmp(ms->args[ms->end], "|", 2))
//			ms->pip = 1;
		if (!ms->or)
		{
			if(is_builtin(ms));
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
						//launch what is after ||, if not, continue without executing
					}
					waitpid(-1, 0, 0);
				}
				else
					ms->err = 1;
				free(ms->cmd);
			}
			if ((!ms->args[ms->end] || ft_strncmp(ms->args[ms->end], "||", 3)) && ms->err)
				printf("%s does not exit\n", ms->args_tmp[0]);
			if (ms->args[ms->end] && !ft_strncmp(ms->args[ms->end], "||", 3) && !ms->err)
				ms->or = 1;
		}
		else
			ms->or = 0;
		i = -1;
		while (ms->args_tmp[++i])
			free(ms->args_tmp[i]);
		free(ms->args_tmp);
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
		ms.env_dup = env_init(&ms);
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
		print_err("Incorrect number of arguments");
}

