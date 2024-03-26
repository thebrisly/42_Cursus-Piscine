/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:54:07 by lfabbian          #+#    #+#             */
/*   Updated: 2023/06/19 21:48:16 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int  main(int argc, char **argv)
{
	t_data		data;
	
	if (!args_check(argc, argv))
	{
		first_init(argc, argv, &data);
		second_init(&data);
		if (philo_init(&data) == 1)
			return (1);
	}
	return (0);
}

void	error_msg(char *str, t_data *dt, t_philo *p, int malloc)
{
	if (malloc)
	{
		if (dt->death)
			free(dt->death);
		if (dt->forks)
			free(dt->forks);
		if (p)
			free(p);
	}
	printf("%s\n", str);
	exit(1);
}

void	end_thread(t_data *dt, t_philo *ph)
{
	int	i;

	i = -1;
	while (++i < dt->nbr_philo)
		pthread_join(ph[i].life_tid, (void *)&ph[i]);
	pthread_mutex_destroy(dt->death);
	pthread_mutex_destroy(dt->forks);
	free(dt->death);
	free(dt->forks);
	free(ph);
}
