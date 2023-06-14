/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:32:59 by lfabbian          #+#    #+#             */
/*   Updated: 2023/06/14 14:02:33 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *) arg;

	(void) p;
	/*while (1)
	{
		if (check_death(p) == 1)
			break ;
		routine_think(p);
		check_forks(p);
		routine_eat(p);
		routine_sleep(p);
	}*/
	//if right & left fork are available
		//take left fork
		//take right fork
		//eat
		//let left fork
		//let right fork
		//sleep
	//if not: then continue as long as your time < time to die
		// think
		// always check if forks are available
	//repeat
	//we always need to check that the current time < time_to_die otherwise the similuation ends !
	// printf("Thread created :-)\n");
	return 0;
}

void	routine_eat(t_philo	*ph)
{
	int left_fork;
    int right_fork;
	//int start_eat;

	left_fork = ph->id;
	right_fork = (ph->id + 1) % ph->data->nbr_philo;
	ph->data->current_time = get_time() - ph->data->start_time;

	print_message(ph->id, ph->data->current_time, EAT, ph);
	usleep(ph->data->time_to_eat * 1000); //here the philo eats
	pthread_mutex_unlock(&ph->data->forks[left_fork]);
	ph[left_fork].fork = 0;
	ph->data->current_time = get_time() - ph->data->start_time;
	print_message(ph->id, ph->data->current_time, PUTDOWN, ph);
	pthread_mutex_unlock(&ph->data->forks[right_fork]);
	ph[right_fork].fork = 0;
	ph->data->current_time = get_time() - ph->data->start_time;
	print_message(ph->id, ph->data->current_time, PUTDOWN, ph);
}

void	routine_think(t_philo *p)
{
	p->data->current_time = get_time() - p->data->start_time;
	print_message(p->id, p->data->current_time, THINK, p);
	//thinks until two forks are available
	//should not die
}

void	routine_sleep(t_philo *p)
{
	p->data->current_time = get_time() - p->data->start_time;
	print_message(p->id, p->data->current_time, SLEEP, p);
	usleep(p->data->time_to_sleep);
}

// void	routine_die(t_philo *p)
// {

// }
