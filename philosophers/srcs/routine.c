/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:32:59 by lfabbian          #+#    #+#             */
/*   Updated: 2023/04/11 14:58:20 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine()
{
	//if right & left fork are available
		//yes: then eat
			//when done: replace the forks
	//if not: then continue as long as your time < time to die
		// sleep
		// think
	//repeat

	//we always need to check that the current time < time_to_die otherwise the similuation ends !
	printf("Thread created :-)\n");
	return 0;
}
