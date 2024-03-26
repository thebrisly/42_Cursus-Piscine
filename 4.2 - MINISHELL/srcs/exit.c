/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:25:03 by dferreir          #+#    #+#             */
/*   Updated: 2023/03/31 13:37:03 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	print_err(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	normal_exit(t_minishell *ms)
{
	if (ms->args_tmp[1] && !ft_isdigit((ms->args_tmp[1][0])))
	{
		printf("minihell: exit: numeric argument required\n");
		ms->err = 255;
	}
	else if (ms->args_tmp[1] && !ms->args_tmp[2])
		exit(ft_atoi(ms->args_tmp[1]) % 256);
	exit(ms->err);
}

void	mini_exit(t_minishell *ms)
{
	int		i;
	char	*msg;

	msg = "exit\nThank you for using ₼ℹηℹℍΞ⅃L⁅℣.⁶⁶⁶⁆, by:\n	₦€₵℞ø₥ and ₿ℼℹ$₤¥\n";
	if (ms->prompt && !ms->args_tmp[2])
	{
		i = -1;
		while (ms->args[++i])
			free(ms->args[i]);
		free(ms->args);
		free(ms->args_size);
	}
	write(1, msg, ft_strlen(msg));
	if (!ms->prompt)
		exit(ms->err);
	else if (ms->args_tmp[1] && ms->args_tmp[2] \
			&& ft_isdigit(ms->args_tmp[1][0]))
	{
		printf("minhell: exit: too many arguments\n");
		ms->err = 1;
	}
	else
		normal_exit(ms);
}
