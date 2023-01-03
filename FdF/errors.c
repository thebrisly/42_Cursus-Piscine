/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:03:25 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/03 16:04:36 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_read_fd(fd)
{
	int	fd;

	fd = open(fd, O_RDONLY)
	if (fd == -1)
        printf("Error with file descriptor n");
    return 0;
}
