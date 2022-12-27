/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:53:56 by lfabbian          #+#    #+#             */
/*   Updated: 2022/12/26 09:51:19 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_message(int pid, char *message)
{
	int	i;

	i = 0;
	kill(pid, SIGUSR1); // Envoi du signal SIGUSR1 au serveur pour signaler qu'un message va être envoyé
	while (message[i++])
	{
		kill(pid, message[i]); // Envoi du caractère c au serveur
		usleep(100); // Pause pour laisser le temps au serveur de traiter le caractère reçu
	}
	kill(pid, 0); // Envoi d'un caractere null pour signaler la fin du message
}

int	main(int argc, char **argv)
{
	char	*message;
	int		*server_id;

	server_id = atoi(argv[1]);
	message = argv[2];
	if (argc == 3)
		send_message(server_id, message);
}