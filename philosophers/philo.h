/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:50:28 by lfabbian          #+#    #+#             */
/*   Updated: 2023/04/11 14:58:25 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>


/* -------------------- Structures -------------------- */

typedef struct s_data {
	int			nbr_philo;
	int			time_to_die;
	int			time_to_eat;
	int 		time_to_sleep;
	int			eat_max;
	int			not_dead;
	pthread_t	threads;
} t_data;

typedef struct s_philo
{
	int			left_fork;
	int			right_fork;
	t_data		data;
	// mettre des trucs pour les philos ??
} t_philo;

/* -------------------- functions -------------------- */

/* checkers */
int	args_check(int argc, char **argv);
int	check_eat_time();

/* utils */
int	ft_atoi(const char *str);

/* init */
void	philo_init(int argc, char **argv, t_data *philo);
void	thread_init(t_data *philo);

/* instructions.c */
void	*routine();

#endif
