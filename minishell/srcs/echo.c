/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:34:27 by dferreir          #+#    #+#             */
/*   Updated: 2023/03/22 11:03:11 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	mini_echo(t_minishell *ms)
{
	int	i;

	i = 0;
	if (ms->args_tmp[1] && !ft_strncmp(ms->args_tmp[1], "-n", 3))
		i = 1;
	if (ms->args_tmp[1])
	{
		while (ms->args_tmp[++i + 1])
		{
			write(1, ms->args_tmp[i], ft_strlen(ms->args_tmp[i]));
			write(1, " ", 1);
		}
		if (ms->args_tmp[i])
			write(1, ms->args_tmp[i], ft_strlen(ms->args_tmp[i]));
	}
	if (ms->args_tmp[1] && !ft_strncmp(ms->args_tmp[1], "-n", 3))
		;
	else
		write(1, "\n", 2);
}
