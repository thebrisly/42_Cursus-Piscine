/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:25:03 by dferreir          #+#    #+#             */
/*   Updated: 2023/03/02 14:48:27 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	mini_exit(t_minishell *ms)
{
	int		i;
	char	*msg;

	i = -1;
	msg = "Thank you for using ₼ℹηℹℍΞ⅃L⁅℣.⁶⁶⁶⁆, by:\n	₦€₵℞ø₥ and ₿ℼℹ$₤¥\n";
	while (ms->args[++i])
		free(ms->args[i]);
	free(ms->args);
	free_env(ms);
	write(1, msg, ft_strlen(msg));
	exit(0);
}
