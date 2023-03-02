/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:35:17 by lfabbian          #+#    #+#             */
/*   Updated: 2023/03/02 15:36:49 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

// When Ctrl+C is pressed, SIGINT signal is generated,
// we can catch this signal and run our defined signal handler.

// Ctrl-\ sends a QUIT signal (SIGQUIT); by default,
// this causes the process to terminate and dump core.

// If You press Ctrl-D then the terminal driver will send a
// SIGINT to the signal handler of the program.

void	signal_handler(int signum)
{
	if (signum == SIGINT) //ctrl+C
		ft_putstr_fd("\b\b  \n\033[0;91m₼ℹηℹ\033[1;91mℍ\033[0;91mΞ⅃L⫸ \033[0m", 2);
	if (signum == SIGQUIT)
		ft_putstr_fd("\b\b  \b\b", 2);
}

void	signal_init(void)
{
	signal(SIGQUIT, signal_handler);
	signal(SIGINT, signal_handler);
}
