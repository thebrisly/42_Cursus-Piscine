/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:53:56 by lfabbian          #+#    #+#             */
/*   Updated: 2022/12/28 15:09:53 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(int pid, char *message)
{
	int				letter;
	int				i;

	letter = 0;
	while (message[letter])
	{
		i = -1;
		while (++i < 8)
		{
			if (((unsigned char)(message[letter] >> (7 - i)) & 1) == 0)
				kill(pid, SIGUSR1);
			else if (((unsigned char)(message[letter] >> (7 - i)) & 1) == 1)
				kill(pid, SIGUSR2);
			usleep(50);
		}
	letter++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR1);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	int		server_id;

	if (argc == 3)
	{
		server_id = ft_atoi(argv[1]);
		message = argv[2];
		send_signals(server_id, message);
	}
	else
	{
		ft_printf("[ERROR]. Too much or too few arguments.\n Make sure ");
		ft_printf("you enter arguments as follow: ./client <PID> <MESSAGE>");
	}
	return (0);
}
