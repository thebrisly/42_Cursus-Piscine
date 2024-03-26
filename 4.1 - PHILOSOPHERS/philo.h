/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:50:28 by lfabbian          #+#    #+#             */
/*   Updated: 2023/06/19 21:53:55 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

/*---------------------- Messages ---------------------- */

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIE "unfortunately (or not) died ☠️"
# define PUTDOWN "has put down fork"
# define LEFT 0
# define RIGHT 1

/* -------------------- Structures -------------------- */

typedef struct s_data {
	int				nbr_philo;
	int				ready;
	int				time_to_die;
	int				time_to_eat;
	int 			time_to_sleep;
	int				loop;
	int				check_meal;
	int				over;
	long int		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death;
} t_data;

typedef struct s_philo
{
	int				id;
	int				dead;
	int				ph_loop;
	long int		last_meal;
	long int		thread_start;
	pthread_t		life_tid;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
} t_philo;

/* -------------------- functions -------------------- */

/* checkers */
int			args_check(int argc, char **argv);
void		check_thread(t_data *dt, t_philo *ph);
int 		check_death(t_philo *ph);
int			check_meals(t_philo p, int last);
int			someone_died(t_philo *ph);

/* utils */
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
long int	get_time(void);
int			ft_usleep(long int time);
void		error_msg(char *str, t_data *dt, t_philo *p, int malloc);

/* init && end */
void		first_init(int argc, char **argv, t_data *data);
void		second_init(t_data *dt);
void		third_init(t_data *dt, t_philo *ph);
int			philo_init(t_data *dt);
int			thread_init(t_data *dt, t_philo *ph);
void		end_thread(t_data *dt, t_philo *ph);

/* routine.c */
void		*routine(void *arg);
void		routine_eat(t_philo	*ph);
void		routine_sleep_think(t_philo *ph);
void		print_routine(t_philo *p, char *action);

/*int		philosophers(t_params *p);
int			init_philo(t_params *p, t_philo *philo);
int			check_death(t_philo *p);
int			ft_atoi(const char *str);
int			ft_usleep(long int time);
int			error_msg(char *s, t_params *par, t_philo *p, int malloc);
void		*thread_routine(void *job);
void		final_print(int alive);
void		print_routine(t_philo *p, char *action);
long int	time_now(void);*/

#endif
