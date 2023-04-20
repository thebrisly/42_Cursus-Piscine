/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:32:59 by lfabbian          #+#    #+#             */
/*   Updated: 2023/04/20 14:35:28 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *) arg; //c'est ici que j'accederai a toutes mes variables	// i = 0;
	printf(": %d\n", p->id);
	// pthread_mutex_destroy()
	pthread_mutex_lock(&p->data->forks[p->id]);
	//if right & left fork are available
		//yes: then eat
			//when done: replace the forks
	//if not: then continue as long as your time < time to die
		// sleep
		// think
	//repeat
	// printf("seg2?\n");
	//we always need to check that the current time < time_to_die otherwise the similuation ends !
	// printf("Thread created :-)\n");
	return 0;
}
