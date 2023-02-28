/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:00:12 by dferreir          #+#    #+#             */
/*   Updated: 2023/02/28 14:35:55 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	is_builtin(t_minishell ms)
{
	int	trigger;

	trigger = 0;
	if (!ft_strncmp("exit", ms.args[0], 5))
		mini_exit(&ms);
	else if (!ft_strncmp("echo", ms.args[0], 5))
	{
		trigger = 1;
		mini_echo(ms);
	}
	else if (!ft_strncmp("env", ms.args[0], 4))
	{
		trigger = 1;
		mini_env(ms);
	}
	else if (!ft_strncmp("pwd", ms.args[0], 4))
	{
		trigger = 1;
		mini_pwd(ms);
	}
	return (trigger);
}
