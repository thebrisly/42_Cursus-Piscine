/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:30:23 by lfabbian          #+#    #+#             */
/*   Updated: 2023/06/19 21:44:32 by brisly           ###   ########.fr       */
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

void	check_thread(t_data *dt, t_philo *ph)
{
	int	i;

	while (!dt->ready)
		continue ;
	while (!dt->over)
	{
		i = -1;
		while (++i < dt->nbr_philo)
			if (check_death(&ph[i]) || check_meals(ph[i], i))
				dt->over = 1;
	}
	if (dt->check_meal && ph[dt->nbr_philo- 1].ph_loop == dt->loop)
	{
		ft_usleep(5 * dt->nbr_philo);
		printf("  All philosophers have eaten %d times\n", dt->loop);
		printf("No one died today");
	}
	printf("Oops.");
}

int	check_death(t_philo *ph)
{
	long int	now;

	pthread_mutex_lock(ph->data->death);
	now = get_time() - ph->last_meal;
	if (now >= ph->data->time_to_die)
	{
		pthread_mutex_unlock(ph->data->death);
		return (someone_died(ph));
	}
	pthread_mutex_unlock(ph->data->death);
	return (0);
}

int	check_meals(t_philo ph, int last)
{
	if (ph.data->check_meal
		&& last == ph.data->nbr_philo - 1
		&& ph.ph_loop == ph.data->loop)
		return (ft_usleep(300));
	return (0);
}

int	someone_died(t_philo *ph)
{
	print_routine(ph, DIE);
	ph->data->over = 1;
	ph->dead = 1;
	pthread_mutex_unlock(ph->left_fork);
	pthread_mutex_unlock(ph->right_fork);
	return (1);
}