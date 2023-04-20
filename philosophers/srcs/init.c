/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:37:44 by lfabbian          #+#    #+#             */
/*   Updated: 2023/04/20 17:10:48 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	first_init(int argc, char **argv, t_data *data)
{
	data->nbr_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->loop = ft_atoi(argv[5]);
	data->not_dead = 1;
}

int	philo_init(t_data *dt, pthread_t *th, t_philo *ph)
{
	int	i;

	i = 0;
	while (i < dt->nbr_philo)
	{
		ph[i].id = i;
		ph[i].fork = 0;
		ph[i].data = dt;
		pthread_mutex_init(&dt->forks[i], NULL);
		if (pthread_create(&th[i], NULL, routine, (void *) &ph[i]) != 0)
			return (0);
		i++;
	}
	return (0);
}
