/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:40:00 by dferreir          #+#    #+#             */
/*   Updated: 2023/02/28 14:47:08 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	minishell(char **envp)
{
	t_minishell	ms;
	int			i;
	int			prompt_exists;

	ms.env = envp;
	ms.paths = get_path(ms.env);
	while (1)
	{
		ft_putstr_fd("\033[0;91m₼ℹηℹ\033[1;91mℍ\033[0;91mΞ⅃L⫸ \033[0m", 2); //print prompt every time
		ms.prompt = get_next_line(0); //store text written in prompt
		prompt_exists = str_to_args(&ms);
		free(ms.prompt);
		if (prompt_exists)
		{
			if(is_builtin(ms)); //check if builtin cmds, if yes, proceed
			else if (prompt_exists) //if prompt has cmds, use existing cmds || replace by prompt check
			{
				ms.pid = fork(); //duplicate process
				if (!ms.pid) //check if child(=0) or parent(=child ID)
				{
					ms.cmd = get_cmd(ms.paths, ms.args[0]); //join path to cmd and check if cmd exists, return
					execve(ms.cmd, ms.args, envp); //exec cmd
				}
				waitpid(-1, 0, 0); //wait for execution
			}
			i = -1;
			while (ms.args[++i])
				free(ms.args[i]);
			free(ms.args);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	if (argc == 1 && !ft_strncmp("./minishell", argv[0], 12))
		minishell(envp);
	else
		print_err("Incorrect number of arguments");
}
