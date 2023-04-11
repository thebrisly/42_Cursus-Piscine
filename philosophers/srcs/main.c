/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:54:07 by lfabbian          #+#    #+#             */
/*   Updated: 2023/04/11 14:58:18 by lfabbian         ###   ########.fr       */
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
		// while (philos.not_dead == 1) // si egal a 0 ca veut dire qu'un philo est dead
		// {
		// 	instructions(&philos);
		// }
		//program for philosophers
	}
	else
		printf("Incorrect args\n");
}
