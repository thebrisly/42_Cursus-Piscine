/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:05:47 by lfabbian          #+#    #+#             */
/*   Updated: 2023/04/04 10:33:29 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	set_dir(t_minishell *ms)
{
	char	*cwd;

	cwd = malloc(PATH_MAX);
	getcwd(cwd, PATH_MAX);
	if (get_value(ms, "PWD"))
	{
		free(replace_value(ms, "PWD")->value);
		replace_value(ms, "PWD")->value = ft_strdup(cwd);
	}
	if (get_value(ms, "OLDPWD"))
	{
		free(replace_value(ms, "OLDPWD")->value);
		replace_value(ms, "OLDPWD")->value = ft_strdup(ms->oldpwd);
	}
	ms->oldpwd = ft_strdup(cwd);
	free(cwd);
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
		if (! directory)
			return ;
		new_dir(ms, directory, arg);
	}
	else
	{
		tmp = 0;
		directory = 0;
		directory = change_directory(ms, directory, tmp, arg);
		new_dir(ms, directory, arg);
		free(directory);
	}
}
