/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:32:59 by lfabbian          #+#    #+#             */
/*   Updated: 2023/05/30 13:15:26 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *) arg; //c'est ici que j'accederai a toutes mes variables	// i = 0;
	// while (p->data->not_dead || p->ph_loop != 0)
	while (1)
	{
		usleep(1000);
		check_forks(p);
	// if (check_forks == 1)
	// {
	// 	take_forks(p);
	// 	eat(p);
	// 	let_forks(p);
	// }
	}
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

// void	routine_eat(t_philo	*p)
// {

// }

// void	routine_think(t_philo *p)
// {
	//thinks until two forks are available
	//should not die
// }

// void	routine_sleep(t_philo *p)
// {

// }

// void	routine_die(t_philo *p)
// {

// }
