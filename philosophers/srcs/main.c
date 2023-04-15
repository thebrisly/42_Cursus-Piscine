/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:54:07 by lfabbian          #+#    #+#             */
/*   Updated: 2023/04/15 11:16:37 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//some code
int  main(int argc, char **argv)
{
	int			i;
	t_data		data;
	// t_philo		*philo;
	pthread_t	*threads;

	i = 0;
	// philo = NULL;
	if (!args_check(argc, argv)) //check args
	{
		// philo = malloc(sizeof(t_philo) * data.nbr_philo);
		// if (!philo)
		// 	return (1);
		threads = malloc((sizeof (pthread_t)) * data.nbr_philo);
		first_init(argc, argv, &data); //data init
		if (philo_init(&data, threads) == 1)
		{
			return (1);
		}
		i = 0;
		while (i < data.nbr_philo)
		{
			pthread_join(data.threads[i], NULL); //
			//+ free tout ce qui a ete init
			i++;
		}
	}
	else
		printf("Incorrect args\n");
}
