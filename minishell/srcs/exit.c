/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:25:03 by dferreir          #+#    #+#             */
/*   Updated: 2023/02/28 14:34:00 by dferreir         ###   ########.fr       */
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
	write(1, msg, ft_strlen(msg));
	exit(0);
}
