/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:53:54 by lfabbian          #+#    #+#             */
/*   Updated: 2022/12/23 15:00:17 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main()
{
	int	pid;

	pid = getpid();
	printf("Server's PID: %d\n", pid); //PID always changes
}
