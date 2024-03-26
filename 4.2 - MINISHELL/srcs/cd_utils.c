/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:38:17 by lfabbian          #+#    #+#             */
/*   Updated: 2023/04/04 10:35:43 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	new_dir(t_minishell	*ms, char *directory, char *argument)
{
	int	new_dir;

	new_dir = chdir(directory);
	if (new_dir == -1)
	{
		printf("cd: %s: No such file or directory\n", argument);
		ms->err = 1;
		return ;
	}
	set_dir(ms);
	free(ms->oldpwd);
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
			ms->err = 1;
			return (NULL);
		}
		return (directory);
	}
}

char	*change_tilde(t_minishell *ms, char *dir, char *tmp, char *arg)
{
	if (arg[0] == '~')
	{
		tmp = ft_substr(arg, 1, ft_strlen(ms->args_tmp[1]));
		dir = ft_strjoin(get_value(ms, "HOME"), tmp);
		if (!dir)
			return (NULL);
		free (tmp);
		return (dir);
	}
	return (NULL);
}

char	*change_directory(t_minishell *ms, char *dir, char *tmp, char *arg)
{
	char	*cwd;

	if (arg[0] == '~')
	{
		dir = change_tilde(ms, dir, tmp, arg);
		return (dir);
	}
	else
	{
		cwd = malloc(PATH_MAX);
		if (!cwd)
			return (NULL);
		tmp = ft_strjoin("/", ms->args_tmp[1]);
		if (!tmp)
			return (NULL);
		getcwd(cwd, PATH_MAX);
		dir = ft_strjoin(cwd, tmp);
		if (!dir)
			return (NULL);
		free(cwd);
		free (tmp);
		return (dir);
	}
}
