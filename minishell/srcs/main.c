/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:40:00 by dferreir          #+#    #+#             */
/*   Updated: 2023/02/26 14:18:38 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	minishell(char **envp)
{
	t_minishell	ms;
	int			i;
	char		*tmp;
	char		**str;

	ms.env = envp;
	ms.paths = get_path(envp);
	while (1)
	{
		i = 0;
		ft_putstr_fd("\033[1mMiniHell> \033[0m", 2);
		tmp = get_next_line(0);
		str = ft_split(tmp, ' ');
		if (!str)
			return ;
		free(tmp);
		while (str[i])
			i++;
		i--;
		str[i][ft_strlen(str[i]) - 1] = '\0';
		if (!ft_strncmp("exit", str[0], 5))
		{
			i = -1;
			while (str[++i])
				free(str[i]);
			free(str);
			exit(0);
		}
		if(is_builtin(ms, str))
		{
			i = -1;
			while (str[++i])
				free(str[i]);
			free(str);
		}
		else
		{
			ms.pid = fork();
			if (!ms.pid) // 0 = child
			{
				ms.cmd = get_cmd(ms.paths, str[0]);
				execve(ms.cmd, str, envp);
			}
			waitpid(-1, 0, 0);
			i = -1;
			while (str[++i])
				free(str[i]);
			free(str);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	if (argc == 1)
		minishell(envp);
	else
		print_err("Incorrect number of arguments");
}
