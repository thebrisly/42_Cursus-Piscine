/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:40:00 by dferreir          #+#    #+#             */
/*   Updated: 2023/03/02 15:20:01 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	minishell(t_minishell *ms)
{
	int	i;

/*	if (find_1st(&ms))
		minishell(&ms);
	if (find_2nd(&ms))
		minishell(&ms);
	rep_quotes(&ms);
	rep_vars(&ms);
*/	if(is_builtin(ms));
	else
	{
		ms->pid = fork();
		if (!ms->pid)
		{
			ms->cmd = get_cmd(ms->paths, ms->args[0]);
			execve(ms->cmd, ms->args, ms->env);
		}
		waitpid(-1, 0, 0);
	}
	i = -1;
	while (ms->args[++i])
		free(ms->args[i]);
	free(ms->args);
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell ms;

	if (argc == 1 && !ft_strncmp("./minishell", argv[0], 12))
	{
		ms.dol = 0;
		ms.quote = 0;
		ms.start = 0;
		ms.env = envp;
		ms.env_dup = 0;
		env_init(&ms);
		ms.paths = get_path(ms.env);
		while (1)
		{
			ft_putstr_fd("\033[0;91m₼ℹηℹ\033[1;91mℍ\033[0;91mΞ⅃L⫸ \033[0m", 2);
			signal_init();
			ms.prompt = get_next_line(0);
			if (str_to_array(&ms))
				minishell(&ms);
		}
	}
	else
		print_err("Incorrect number of arguments");
}

