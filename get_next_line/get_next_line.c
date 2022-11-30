/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:43:10 by lfabbian          #+#    #+#             */
/*   Updated: 2022/11/30 14:54:21 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*stash;
	char 		*buffer;
	char 		*line;
	
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	stash = stash_filling(fd, stash, buffer);
	line = extract_line(stash);
	stash = extract_new_stash(stash);
	return(line);
}

char	*stash_filling(int fd, char *stash, char *buffer)
{
	int	i;
	ssize_t	nbytes;

	i = 0;
	nbytes = read(fd, buffer, BUFFER_SIZE);
	buffer[nbytes] = 0;
	stash = ft_strjoin(stash, buffer);
	while (stash[i])
	{
		if (stash[i] == ft_is_bsn(stash[i]))
			return (stash);
		i++;
	}
	return (NULL);
}

char	*extract_new_stash()
{
	return (NULL);
}

char	*extract_line()
{
	return(NULL);
}

int main()
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}
