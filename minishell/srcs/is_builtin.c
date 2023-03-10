/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:00:12 by dferreir          #+#    #+#             */
/*   Updated: 2023/03/09 10:02:15 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	is_builtin(t_minishell *ms)
{
	int	trigger;

	trigger = 0;
	if (!ft_strncmp("exit", ms->args_tmp[0], 5))
		mini_exit(ms);
	else if (!ft_strncmp("echo", ms->args_tmp[0], 5))
	{
		trigger = 1;
		mini_echo(ms);
	}
	else if (!ft_strncmp("env", ms->args_tmp[0], 3))
	{
		trigger = 1;
		mini_env(ms);
	}
	else if (!ft_strncmp("pwd", ms->args_tmp[0], 3))
	{
		trigger = 1;
		mini_pwd(ms);
	}
	else if (!ft_strncmp("export", ms->args_tmp[0], 6))
	{
		trigger = 1;
		mini_export(ms);
	}
/*	else if (!ft_strncmp("unset", ms->args_tmp[0], 5))
	{
		trigger = 1;
		mini_unset(ms);
	}*/
	return (trigger);
}
