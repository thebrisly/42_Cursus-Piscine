/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:05:47 by lfabbian          #+#    #+#             */
/*   Updated: 2023/03/14 15:30:14 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"



void	set_dir(t_minishell *ms, char *dir)
{
	// char *tmp;

	// tmp = ft_strdup(dir);
	replace_value(ms, "PWD")->value = ft_strdup(dir);
	replace_value(ms, "OLDPWD")->value = ms->oldpwd;
	ms->oldpwd = dir;
	// free (tmp);
}

void	mini_cd(t_minishell *ms)
{
	char	*directory;
	char	*cwd;
	char	*argument;
	char	*tmp;
	int		new_dir;

	argument = ms->args_tmp[1];
	if (!argument)
	{
		directory = get_value(ms, "HOME");
		if (!directory)
			printf("cd: HOME not set\n");
	}
	else
	{
		directory = 0;
		if (ms->args_tmp[1][0] == '/')
			directory = ms->args_tmp[1];
		else if (ms->args_tmp[1][0] == '~')
		{
			tmp = ft_substr(argument, 1, ft_strlen(ms->args_tmp[1]));
			directory = ft_strjoin(get_value(ms, "HOME"), tmp);
			if (!directory)
				printf("cd: No such file or directory\n");
			free (directory);
			free (tmp);
		}
		else if (ft_strcmp("..", ms->args_tmp[1]) == 0)
			directory = "..";
		else
		{
			cwd = malloc(PATH_MAX);
			tmp = ft_strjoin("/", ms->args_tmp[1]);
			getcwd(cwd, PATH_MAX);
			directory = ft_strjoin(cwd, tmp);
			free(cwd);
			free (tmp);
			free (directory);
		}
	}
	new_dir = chdir(directory);
	if (new_dir == -1)
	{
		printf("cd: No such file or directory\n"); //code d'erreur sur bash: 1
		return ;
	}
	set_dir(ms, directory);
}
