/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:30:23 by lfabbian          #+#    #+#             */
/*   Updated: 2023/06/14 13:52:20 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/* checking for the arguments */
int	args_check(int argc, char **argv)
{
	int	i;
	if (argc == 5 || argc == 6)
	{
		i = 0;
		while (argv[++i] && ft_atoi(argv[i]) >= 0)
			;
		if (i != argc)
		{
			printf("\033[0;31mWrong number of args ! Interger must be strictly greater than 0\033[0;30m\n");
			return (1);
		}
		else if (ft_atoi(argv[1]) <= 0)
		{
			printf("At least \033[0;31mone\033[0;30m philosopher must be created");
			return (1);
		}
		return (0);
	}
	printf("\033[0;31mToo many argument. 4 or 5 needed.\033[0;30m\n");
	return (1);
}

int check_death(t_philo *ph)
{
	return (ph->data->dead);
}


void check_forks(t_philo *ph)
{
    int left_fork = ph->id;
    int right_fork = (ph->id + 1) % ph->data->nbr_philo;

    if (ph[left_fork].fork == 0 && ph[right_fork].fork == 0 && (ph->id != ph->data->nbr_philo -1)) 
    {
       	pthread_mutex_lock(&ph->data->forks[left_fork]);
		ph[left_fork].fork = 1;
		ph->data->current_time = get_time() - ph->data->start_time;
		print_message(ph->id, ph->data->current_time, LTAKE, ph);
		pthread_mutex_lock(&ph->data->forks[right_fork]);
		ph[right_fork].fork = 1;
		ph->data->current_time = get_time() - ph->data->start_time;
		print_message(ph->id, ph->data->current_time, RTAKE, ph);
    }
	else
	{
		pthread_mutex_lock(&ph->data->forks[right_fork]);
		ph[right_fork].fork = 1;
		ph->data->current_time = get_time() - ph->data->start_time;
		print_message(ph->id, ph->data->current_time, RTAKE, ph);
		pthread_mutex_lock(&ph->data->forks[left_fork]);
		ph[left_fork].fork = 1;
		ph->data->current_time = get_time() - ph->data->start_time;
		print_message(ph->id, ph->data->current_time, LTAKE, ph);
	}
}