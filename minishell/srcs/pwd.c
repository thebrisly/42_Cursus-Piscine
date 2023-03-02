/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:33:50 by dferreir          #+#    #+#             */
/*   Updated: 2023/03/01 15:30:47 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	mini_pwd(t_minishell *ms)
{
	int		i;
	char	*directory;

	i = 0;
	while (ms->env[i])
	{
		if (!ft_strncmp(ms->env[i], "PWD=", 4))
		{
			directory = ft_substr(ms->env[i], 5, ft_strlen(ms->env[i]));
			if (!directory)
				return ;
			ft_printf(directory);
		}
		i++;
	}
	free(directory);
	ft_printf("\n");
}
