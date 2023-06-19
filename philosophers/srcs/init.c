/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:37:44 by lfabbian          #+#    #+#             */
/*   Updated: 2023/06/19 21:53:43 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	first_init(int argc, char **argv, t_data *data)
{
	data->nbr_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->loop = -2;
	data->check_meal = 0;
	data->start_time = 0;
	data->ready = 0;
	if (argc == 6)
	{
		data->check_meal = 1;
		data->loop = ft_atoi(argv[5]);
	}
	data->over = 0;
}

void	second_init(t_data *dt)
{
	int i;

	i = -1;
	//dt->death = 0;
	//dt->forks = 0;
	dt->death = malloc(sizeof(pthread_mutex_t));
	if (!dt->death)
		error_msg("Mutex death: malloc failed", dt, 0, 1);
	dt->forks = malloc(sizeof(pthread_mutex_t) * dt->nbr_philo);
	if (!dt->forks)
		error_msg("Error\nMutex fork: malloc failed\n", dt, 0, 1);
	if (pthread_mutex_init(dt->death, NULL) == -1)
		error_msg("Mutex init failed", dt, 0, 1);
	while (++i < dt->nbr_philo)
		if (pthread_mutex_init(&dt->forks[i], NULL) == -1)
			error_msg("Mutex init failed", dt, 0, 1);
}

void third_init(t_data *dt, t_philo *ph)
{
	int	i;

	i = -1;
	while (++i < dt->nbr_philo)
	{
		ph[i].id = i;
		ph[i].dead = 0;
		ph[i].ph_loop = 0;
		ph[i].thread_start = 0;
		ph[i].last_meal = 0;
		ph[i].data = dt;
		ph[i].left_fork = &dt->forks[i];
		ph[i].right_fork = 0;
	}
}

int	thread_init(t_data *dt, t_philo *ph)
{
	int	i;

	i = -1;
	while (++i < dt->nbr_philo)
	{
		ph[i].right_fork = ph[(i + 1) % dt->nbr_philo].left_fork;
		if (pthread_create(&ph[i].life_tid, NULL,
				&routine, &ph[i]) == -1)
			error_msg("Failed to create thread", dt, ph, 1);
	}
	i = -1;
	dt->start_time = get_time();
	while (++i < dt->nbr_philo)
	{
		ph[i].thread_start = dt->start_time;
		ph[i].last_meal = dt->start_time;
	}
	dt->ready = 1;
	return (0);
}

int	philo_init(t_data *dt)
{
	t_philo *ph;

	ph = malloc(sizeof(t_philo) * dt->nbr_philo);
	if (!ph)
	{
		error_msg("Mutex death: malloc failed", dt, ph, 1);
		return (1);
	}
	third_init(dt, ph);
	thread_init(dt, ph);
	check_thread(dt, ph);
	end_thread(dt, ph);
	return (0);
}

