/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:40:58 by lfabbian          #+#    #+#             */
/*   Updated: 2023/06/19 21:44:55 by brisly           ###   ########.fr       */
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

/* The gettimeofday function takes a parameter of type timeval, which is a structure with the following members:
	struct timeval {
    time_t      tv_sec;     // Number of seconds since January 1, 1970
    suseconds_t tv_usec;    // Number of microseconds (fractional part of seconds)

	In the subject it is asked to use milliseconds, so we need to convert everything from seconds to ms before returning a value
*/
long int	get_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_usleep(long int time)
{
	long int	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time)
		usleep(150);
	return (1);
}
