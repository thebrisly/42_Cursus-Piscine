/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:37:44 by lfabbian          #+#    #+#             */
/*   Updated: 2023/04/13 15:15:20 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	first_init(int argc, char **argv, t_data *data, t_philo *ph)
{
	(void) ph;
	// int i = 0;

	data->nbr_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->loop = ft_atoi(argv[5]);
	data->not_dead = 1;
	// while (i < data->nbr_philo)
	// {
	// 	printf("FORKS: %d\n", data->forks[i]);
	// 	i++;
	// }
}

int	philo_init(t_philo *ph, t_data *dt)
{
	int	i;

	// i = 0;
	// while (i < dt->nbr_philo)
	// {
	// 	printf("FORKS: %d\n", dt->forks[i]);
	// 	i++;
	// }
	i = 0;
	while (i < dt->nbr_philo)
	{
		// t_args *args = malloc(sizeof(t_args));
		ph[i].id = i;
		ph[i].fork = 0; //if fork taken it will be 1
		dt->forks[i] = ph[i].fork;
		// printf("FORKS: %d\n", dt->forks[i]);
		ph[i].data = dt;

		// args->ph1 = &ph[i];
		// pthread_mutex_init(ph->mutex, NULL);
		if (pthread_create(&dt->threads[i], NULL, routine, (void *) dt) != 0)
			return (1);
		i++;
	}

	return (0);
}
