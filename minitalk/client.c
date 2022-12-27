/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:53:56 by lfabbian          #+#    #+#             */
/*   Updated: 2022/12/27 20:34:02 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(int pid, char *message)
{
	int				letter;
	int				i;
	unsigned char	bit;

	letter = 0;
	while (message[letter])
	{
		i = 0;
		while (i < 8)
		{
			bit = (message[letter] >> (7 - i)) & 1;
			if (bit == 0)
				kill(pid, SIGUSR1);
			else if (bit == 1)
				kill(pid, SIGUSR2);
		i++;
		}
	letter++;
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
		printf("Wrong args. Must be like that: ./<PROGRAM> <PID> <MESSAGE>");
	return (0);
}
