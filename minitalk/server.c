/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:53:54 by lfabbian          #+#    #+#             */
/*   Updated: 2022/12/27 20:58:31 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_recursive_power(int nb, int power)
{
	int	res;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
	{
		res = nb * ft_recursive_power(nb, power - 1);
		return (res);
	}
}

void	signal_handler(int signum)
{
	static int	bits;
	int	*char_received[8];

	bits = 0;
	while (bits < 8)
	{
		if (signum == SIGUSR1)
			char_received[bits] = 0;
		else if (signum == SIGUSR2)
			char_received[bits] = 1;
		bits++;
	}
	while ()
	if (bits == 8)
		bits = 0;
}

int	main(void)
{
	static char			message;
	struct sigaction	signal_received;

	ft_printf("Server's PID: %d\n", getpid());
	signal_received.sa_handler = signal_handler;
	sigemptyset(&signal_received.sa_mask);
	signal_received.sa_flags = 0;
	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);
	while (1)
		usleep(50);
}
