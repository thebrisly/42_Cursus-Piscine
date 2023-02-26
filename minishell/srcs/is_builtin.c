/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:00:12 by dferreir          #+#    #+#             */
/*   Updated: 2023/02/26 14:16:57 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	is_builtin(t_minishell ms, char **args)
{
	int	trigger;

	trigger = 0;
	if (!ft_strncmp("echo", args[0], 5))
	{
		trigger = 1;
		mini_echo(args);
	}
	else if (!ft_strncmp("env", args[0], 4))
	{
		trigger = 1;
		mini_env(ms.env);
	}
	else if (!ft_strncmp("pwd", args[0], 4))
	{
		trigger = 1;
		mini_pwd(&ms);
	}
	return (trigger);
}
