/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:24:32 by lfabbian          #+#    #+#             */
/*   Updated: 2023/05/29 13:47:21 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct	s_data
{
    int         nbr_philo;
    pthread_mutex_t *forks;
}               t_data;

typedef struct  s_philo
{
    int         id;
    t_data      *data;
}               t_philo;

void    *routine(void *arg)
{
    t_philo *ph = (t_philo *)arg;

    while (1)
    {
        // Philosopher is thinking
        printf("Philosopher %d is thinking\n", ph->id);

        // Philosopher is hungry and tries to pick up two forks
        pthread_mutex_lock(&ph->data->forks[ph->id]);
        printf("Philosopher %d has picked up fork %d\n", ph->id, ph->id);
        pthread_mutex_lock(&ph->data->forks[(ph->id + 1) % ph->data->nbr_philo]);
        printf("Philosopher %d has picked up fork %d\n", ph->id, (ph->id + 1) % ph->data->nbr_philo);

        // Philosopher is eating
        printf("Philosopher %d is eating\n", ph->id);
        usleep(100000);

        // Philosopher puts down the forks and goes back to thinking
        pthread_mutex_unlock(&ph->data->forks[ph->id]);
        printf("Philosopher %d has put down fork %d\n", ph->id, ph->id);
        pthread_mutex_unlock(&ph->data->forks[(ph->id + 1) % ph->data->nbr_philo]);
        printf("Philosopher %d has put down fork %d\n", ph->id, (ph->id + 1) % ph->data->nbr_philo);
    }

    return (NULL);
}

int     main(int argc, char **argv)
{

    if (argc != 2)
    {
        printf("Usage: %s number_of_philosophers\n", argv[0]);
        return (1);
    }

    int nbr_philo = atoi(argv[1]);

    pthread_t   *th;
    t_philo     *ph;
    t_data      data;

    th = malloc(sizeof(pthread_t) * nbr_philo);
    ph = malloc(sizeof(t_philo) * nbr_philo);
    data.forks = malloc(sizeof(pthread_mutex_t) * nbr_philo);
    if (!th || !ph || !data.forks)
        return (1);
    data.nbr_philo = nbr_philo;
    for (int i = 0; i < nbr_philo; i++)
        pthread_mutex_init(&data.forks[i], NULL);

    // Initialize philosophers and start their routines
    for (int i = 0; i < nbr_philo; i++)
    {
        ph[i].id = i;
        ph[i].data = &data;

        if (pthread_create(&th[i], NULL, routine, &ph[i]) != 0)
            return (1);
    }

    // Wait for philosophers to finish
    for (int i = 0; i < nbr_philo; i++)
        pthread_join(th[i], NULL);

    // Destroy mutex locks for forks
    for (int i = 0; i < nbr_philo; i++)
        pthread_mutex_destroy(&data.forks[i]);

    free(th);
    free(ph);
    free(data.forks);

    return (0);
}
