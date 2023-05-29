/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:50:28 by lfabbian          #+#    #+#             */
/*   Updated: 2023/05/29 14:35:36 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/*---------------------- Messages ---------------------- */

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define RFORK "has taken right fork"
# define LFORK "has taken left fork"
# define DIED "unfortunately (or not) died ☠️"

/* -------------------- Structures -------------------- */

typedef struct s_data {
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int 			time_to_sleep;
	int				not_dead;
	int				loop;
	int				start_time;
	pthread_mutex_t	*forks;
} t_data;

typedef struct s_philo
{
	int				fork; //chaque philo possede une fourchette, quand elle est prise = 1 sinon 0
	int				id;
	int				last_meal;
	int				ph_loop;
	t_data			*data;
} t_philo;

/* -------------------- functions -------------------- */

/* checkers */
int	args_check(int argc, char **argv);
int	check_eat_time();

/* utils */
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	check_forks(t_philo *ph);

/* init */
void	first_init(int argc, char **argv, t_data *data);
int		philo_init(t_data *dt, pthread_t *th, t_philo *ph);
void	print_message(int id, int ms, char *message, t_philo *ph);
int		get_time(void);

/* instructions.c */
void	*routine(void *arg);

#endif
