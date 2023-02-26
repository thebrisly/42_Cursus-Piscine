/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:40:22 by dferreir          #+#    #+#             */
/*   Updated: 2023/02/26 12:45:01 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	print_err(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

char	**get_path(char **envp)
{
	int		i;
	char	*env;
	char	**res;

	i = 0;
	while (envp[i]) //chercher la variable d'environnement "PATH"
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			env = ft_substr(envp[i], 6, ft_strlen(envp[i]));
			if (!env)
				return (0);
			res = ft_split(env, ':');
			free (env);
			if (!res)
				return (0);
			return (res);
		}
		i++;
	}
	return (0);
}

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0) //si = 0 il y a la commande ici
			return (command);
		free(command);
		paths++;
	}
	write(2, cmd, ft_strlen(cmd));
	print_err(" doesn't exits");
	return (0);
}
