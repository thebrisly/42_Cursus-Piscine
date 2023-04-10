/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:35:17 by lfabbian          #+#    #+#             */
/*   Updated: 2023/04/05 13:24:22 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	signal_handler(int signum)
{
	if (signum == SIGINT && g_cat == 1)
	{
		ft_putstr_fd("^C \n", 2);
		g_cat = 130;
	}
	else if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_cat = 0;
	}
	if (signum == SIGQUIT && g_cat == 1)
	{
		ft_putstr_fd("^\\Quit: 3\n", 2);
		g_cat = 131;
	}
	else if (signum == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		g_cat = 0;
	}
}

void	signal_init(void)
{
	signal(SIGQUIT, signal_handler);
	signal(SIGINT, signal_handler);
}
