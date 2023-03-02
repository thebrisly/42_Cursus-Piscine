/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:34:27 by dferreir          #+#    #+#             */
/*   Updated: 2023/03/01 15:31:29 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	mini_echo(t_minishell *ms)
{
	int	i;

	i = 0;
	if (ms->args[1] && !ft_strncmp(ms->args[1], "-n", 3)) //check si flag
		i = 1;
	if (ms->args[1]) //if more args than "echo", proceed
	{
		while (ms->args[++i + 1]) //continuer de 2eme a avant dernier arg
		{
			write(1, ms->args[i], ft_strlen(ms->args[i]));
			write(1, " ", 1);
		}
		if (ms->args[i]) //si dernier arg = existant, print
			write(1, ms->args[i], ft_strlen(ms->args[i]));
	}
	if (ms->args[1] && !ft_strncmp(ms->args[1], "-n", 3)); //si 2eme arg == -n, rien
	else //autre, print "\n"
		write(1, "\n", 2);
}
