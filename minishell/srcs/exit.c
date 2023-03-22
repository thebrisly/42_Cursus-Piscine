/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:25:03 by dferreir          #+#    #+#             */
/*   Updated: 2023/03/22 11:38:15 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

// void	mini_error(t_minishell *ms, char *str, int error_type)
// {
// 	if (error_type == 0)
// 		ft_printf
// }

void	mini_exit(t_minishell *ms)
{
	int		i;
	char	*msg;

	msg = "exit\nThank you for using ₼ℹηℹℍΞ⅃L⁅℣.⁶⁶⁶⁆, by:\n	₦€₵℞ø₥ and ₿ℼℹ$₤¥\n";
	i = -1;
	while (ms->args_tmp[++i])
		free(ms->args_tmp[i]);
	free(ms->args_tmp);
	i = -1;
	while (ms->args[++i])
		free(ms->args[i]);
	free(ms->args);
	free(ms->args_size);
	write(1, msg, ft_strlen(msg));
	exit(0);
}
