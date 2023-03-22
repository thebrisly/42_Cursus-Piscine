/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:05:47 by lfabbian          #+#    #+#             */
/*   Updated: 2023/03/22 12:49:23 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	set_dir(t_minishell *ms)
{
	char	*cwd;

	cwd = malloc(PATH_MAX);
	getcwd(cwd, PATH_MAX);
	replace_value(ms, "PWD")->value = cwd;
	replace_value(ms, "OLDPWD")->value = ms->oldpwd;
	ms->oldpwd = cwd;
	free (cwd);
}

void	new_dir(t_minishell	*ms, char *directory, char *argument)
{
	int	new_dir;

	new_dir = chdir(directory);
	if (new_dir == -1)
	{
		printf("cd: %s: No such file or directory\n", argument);
		return ;
	}
	set_dir(ms);
}

char	*go_home(t_minishell *ms)
{
	char	*directory;

	if (ms->args_tmp[1] && ms->args_tmp[1][0] == '/')
	{
		directory = ms->args_tmp[1];
		return (directory);
	}
	else
	{
		directory = get_value(ms, "HOME");
		if (!directory)
		{
			printf("cd: HOME not set\n");
			return (NULL);
		}
		return (directory);
	}
}

char	*change_directory(t_minishell *ms, char *dir, char *tmp, char *arg)
{
	char	*cwd;

	if (arg[0] == '~')
	{
		tmp = ft_substr(arg, 1, ft_strlen(ms->args_tmp[1]));
		dir = ft_strjoin(get_value(ms, "HOME"), tmp);
		free (tmp);
		return (dir);
	}
	else
	{
		cwd = malloc(PATH_MAX);
		tmp = ft_strjoin("/", ms->args_tmp[1]);
		getcwd(cwd, PATH_MAX);
		dir = ft_strjoin(cwd, tmp);
		free(cwd);
		free (tmp);
		return (dir);
	}
}

void	mini_cd(t_minishell *ms)
{
	char	*directory;
	char	*arg;
	char	*tmp;

	arg = ms->args_tmp[1];
	if (!arg || (arg[0] == '~' && !arg[1]) || arg[0] == '/')
	{
		directory = go_home(ms);
		new_dir(ms, directory, arg);
	}
	else
	{
		tmp = 0;
		directory = 0;
		directory = change_directory(ms, directory, tmp, arg);
		new_dir(ms, directory, arg);
	}
}
