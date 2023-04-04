/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:00:12 by dferreir          #+#    #+#             */
/*   Updated: 2023/04/03 14:02:54 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	exec_builtin(t_minishell *ms)
{
	if (!ft_strncmp("exit", ms->args_tmp[0], 5))
		mini_exit(ms);
	else if (!ft_strncmp("echo", ms->args_tmp[0], 5))
		mini_echo(ms);
	else if (!ft_strncmp("env", ms->args_tmp[0], 4))
		mini_env(ms);
	else if (!ft_strncmp("pwd", ms->args_tmp[0], 4))
		mini_pwd(ms);
	else if (!ft_strncmp("export", ms->args_tmp[0], 7))
		mini_export(ms);
	else if (!ft_strncmp("unset", ms->args_tmp[0], 6))
		mini_unset(ms);
	else if (!ft_strncmp("cd", ms->args_tmp[0], 3))
		mini_cd(ms);
}

int	is_builtin(t_minishell *ms)
{
	int	trigger;

	trigger = 0;
	if (!ft_strncmp("exit", ms->args_tmp[0], 5))
		trigger = 2;
	else if (!ft_strncmp("echo", ms->args_tmp[0], 5))
		trigger = 1;
	else if (!ft_strncmp("env", ms->args_tmp[0], 4))
		trigger = 1;
	else if (!ft_strncmp("pwd", ms->args_tmp[0], 4))
		trigger = 1;
	else if (!ft_strncmp("export", ms->args_tmp[0], 7))
		trigger = 1;
	else if (!ft_strncmp("unset", ms->args_tmp[0], 6))
		trigger = 1;
	else if (!ft_strncmp("cd", ms->args_tmp[0], 3))
		trigger = 2;
	return (trigger);
}
