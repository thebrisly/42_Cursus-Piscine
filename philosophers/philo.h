/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:50:28 by lfabbian          #+#    #+#             */
/*   Updated: 2023/04/04 20:55:19 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>


/* -------------------- Structures -------------------- */

typedef struct s_philo
{
	// mettre des trucs pour les philos ??
} t_philo;

typedef struct s_data {
	int			nbr_philo;
	int			time_to_die;
	int			time_to_eat;
	int 		time_to_sleep;
	int			eat_max;
	int			not_dead;
	pthread_t	philos_id;
} t_data;

/* -------------------- functions -------------------- */

/* checkers */
int	args_check(int argc, char **argv);
int	check_eat_time();

/* utils */
int	ft_atoi(const char *str);

/* init */
void	philo_init(int argc, char **argv, t_data *philo);

#endif
