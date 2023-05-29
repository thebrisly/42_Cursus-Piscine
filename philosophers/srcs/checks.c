/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:30:23 by lfabbian          #+#    #+#             */
/*   Updated: 2023/05/29 14:05:53 by lfabbian         ###   ########.fr       */
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

int	check_eat_time()
{
	// regarder avec la fonction  gettimeofday qui permet de calculer en ms le temps passé dessus
	return (0);
}

//function that checks if actual time > time_to_die (if yes: dead)

//check if time to eat is respected
