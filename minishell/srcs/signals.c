/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:35:17 by lfabbian          #+#    #+#             */
/*   Updated: 2023/03/22 13:01:23 by lfabbian         ###   ########.fr       */
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
	if (signum == SIGINT && cat == 1)
		ft_putstr_fd("\n", 2);
	else if (signum == SIGINT) //ctrl+C
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	//	ft_putstr_fd("\n\033[0;91m₼ℹηℹ\033[1;91mℍ\033[0;91mΞ⅃L⫸ \033[0m", 2);
	}
	if (signum == SIGQUIT && cat == 1)
		ft_putstr_fd("Quit: 3\n", 2);
	else if (signum == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		write(2, "  \b\b", 4);
	}
	cat = 0;
}

void	signal_init(void)
{
	// struct sigaction	signal_received;

	// signal_received.sa_handler = signal_handler;
	// signal_received.sa_flags = 0;
	//sigaction(SIGINT, &signal_received, NULL);

	signal(SIGQUIT, signal_handler);
	signal(SIGINT, signal_handler);
}
