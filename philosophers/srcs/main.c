/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:54:07 by lfabbian          #+#    #+#             */
/*   Updated: 2023/04/13 17:40:44 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//some code
int  main(int argc, char **argv)
{
	int		i;
	t_data	data;
	t_philo	*philo;

	i = 0;
	// philo = NULL;
	if (!args_check(argc, argv)) //check args
	{
		philo = malloc(sizeof(t_philo) * data.nbr_philo);
		if (!philo)
			return (1);
		data.threads = malloc((sizeof (pthread_t)) * data.nbr_philo);
		data.forks = ft_calloc (data.nbr_philo, sizeof (int));
		first_init(argc, argv, &data, philo); //data init
		// if (!philo)
		// // 	return 1;
		// while (i < data.nbr_philo)
		// {
		// 	printf("FORKS: %d\n", data.forks[i]);
		// 	i++;
		// }
		if (philo_init(philo, &data) == 1)
		{
			//thread_join && free tout ce qui a ete malloc
			return (1);
		}
		i = 0;
		while (i < data.nbr_philo)
		{
			pthread_join(data.threads[i], NULL); //
			i++;
		}
		// while (philos.not_dead == 1) // si egal a 0 ca veut dire qu'un philo est dead
		// {
		// 	instructions(&philos);
		// }
		// on peut pas mettre ca ici pcq quand on fait phread_create ca va directement appeler la fonction routine
		//program for philosophers
	}
	else
		printf("Incorrect args\n");
}
