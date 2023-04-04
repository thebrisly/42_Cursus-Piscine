/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:54:07 by lfabbian          #+#    #+#             */
/*   Updated: 2023/04/04 21:00:52 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//some code
int  main(int argc, char **argv)
{
	t_data	philos; // were the main data will be
	// int 	i;
	if (!args_check(argc, argv)) //check args
	{
		philo_init(argc, argv, &philos); //data init
		printf("good instructions\n");
		while (philos.not_dead) // si egal a 0 ca veut dire qu'un philo est dead
		{

		}
		// while (1);
		// pthread_create() //pour creer un thread on ecrit ca comme ca -> il faudra stocker leur id dans philos_id :-)
		//program for philosophers
	}
	else
		printf("Incorrect args\n");
}
