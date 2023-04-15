/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:37:44 by lfabbian          #+#    #+#             */
/*   Updated: 2023/04/15 11:19:47 by lfabbian         ###   ########.fr       */
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

int	philo_init(t_data *dt, pthread_t *th)
{
	int	i;
	t_philo	*ph;

	i = 0;
	ph = malloc(sizeof(t_philo) * dt->nbr_philo);
	if (!ph)
		return (1);
	while (i < dt->nbr_philo)
	{
		ph[i].id = i; //meme pas obligatoire en fait
		ph[i].fork = 0;
		ph[i].data = dt;
		// printf("ID: %d\n", ph[i].id);
		// pthread_mutex_init(ph->mutex, NULL);
		if (pthread_create(&th[i], NULL, routine, (void *) ph) != 0)
			return (0); //check la valeur de retour
		i++;
	}
	return (0); //check la valeur de retour
}
