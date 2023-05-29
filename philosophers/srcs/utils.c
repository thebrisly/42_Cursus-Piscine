/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:40:58 by lfabbian          #+#    #+#             */
/*   Updated: 2023/05/29 14:35:28 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	atoi;
	int	sign;

	i = 0;
	atoi = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		atoi *= 10;
		atoi += str[i] - 48;
		i++;
	}
	return (atoi * sign);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tab;
	unsigned long	i;

	i = 0;
	tab = malloc(count * size);
	if (!tab)
		return (NULL);
	while (count * size > i)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

void	check_forks(t_philo *ph)
{
	printf("SEG1\n");
	pthread_mutex_lock(&ph->data->forks[ph->id]);
	print_message(ph->id, get_time(), "has taken left fork", ph);
	pthread_mutex_lock(&ph->data->forks[(ph->id + 1) % ph->data->nbr_philo]);
	print_message(ph->id, get_time(), "has take right fork", ph);
	printf("SEG2\n");
}
