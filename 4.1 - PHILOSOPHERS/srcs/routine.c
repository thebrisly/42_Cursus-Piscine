/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:32:59 by lfabbian          #+#    #+#             */
/*   Updated: 2023/06/19 21:42:20 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *) arg;
	while (!p->data->ready)
		continue ;
	if (p->id & 1)
		ft_usleep(p->data->time_to_eat * 0.9 + 1);
	while (!p->data->over)
	{
		routine_eat(p);
		routine_sleep_think(p);
	}
	return (NULL);
}

void	routine_eat(t_philo	*ph)
{
	pthread_mutex_lock(ph->left_fork);
	print_routine(ph, FORK);
	pthread_mutex_lock(ph->right_fork);
	print_routine(ph, FORK);
	ph->last_meal = get_time();
	ft_usleep(ph->data->time_to_eat);
	print_routine(ph, EAT);
	ph->ph_loop++;
	pthread_mutex_unlock(ph->left_fork);
	pthread_mutex_unlock(ph->right_fork);
}

void routine_sleep_think(t_philo *ph)
{
	ft_usleep(ph->data->time_to_sleep);
	print_routine(ph, SLEEP);
	print_routine(ph, THINK);
}

void	print_routine(t_philo *p, char *action)
{
	pthread_mutex_lock(p->data->death);
	if (p->data->over)
	{
		pthread_mutex_unlock(p->data->death);
		return ;
	}
	printf("%ldms %d %s\n", get_time() - p->thread_start,
		p->id, action);
	pthread_mutex_unlock(p->data->death);
}