/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:53:54 by lfabbian          #+#    #+#             */
/*   Updated: 2022/12/26 09:51:09 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char message[1024]; // Tableau de caractères pour stocker le message reçu
unsigned int messageIndex = 0; // Indice du prochain caractère à recevoir dans le message

// Fonction de gestion des signaux
void signal_handler(int signum)
{
	// Si le signal reçu est SIGUSR1, cela signifie qu'un message est en cours de transmission
	if (signum == SIGUSR1)
	{
		messageIndex = 0;
	}
	// Si le signal reçu est un entier non signé (unsigned int), cela signifie qu'il s'agit d'un caractère du message
	else if (signum >= 0)
	{
		message[messageIndex] = (char)signum;
		messageIndex++;
	}
}

	// Structure de gestion des signaux
	struct sigaction action;
	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;

	// Enregistrement de la fonction signal_handler pour les signaux SIGUSR1 et tous les entiers non signés (unsigned int)
	sigaction(SIGUSR1, &action, NULL);
	for (unsigned int i = 0; i < 32; i++)
		{
		sigaction(i, &action, NULL);
		}

	// Boucle infinie pour attendre les messages des clients
	while (1)
	{
		// Si le message est complet, on l'affiche et on remet l'indice du prochain caractère à 0
		if (message[messageIndex] == '\0')
		{
			printf("Message reçu : %s\n", message);
			messageIndex = 0;
		}
		usleep(100);
	}
	return 0;
}

int	main()
{
	static char	message;
	int	pid;

	pid = getpid();
	printf("Server's PID: %d\n", pid); //PID always changes
	while (1) // Boucle infinie pour attendre le message des clients
		usleep();
}
