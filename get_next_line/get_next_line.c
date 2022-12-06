/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:43:10 by lfabbian          #+#    #+#             */
/*   Updated: 2022/12/04 16:55:09 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));$
	if (!buffer)
		return (NULL);
	stash = stash_filling(fd, stash, buffer);
	line = extract_line(stash, line);
	stash = extract_new_stash(stash);
	return (line);
}

char	*stash_filling(int fd, char *stash, char *buffer)
{
	ssize_t	nbytes;

	if (!stash)
			stash = ft_strdup(buffer);
	while (!ft_strchr(stash, '\n') && nbytes != 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		buffer[nbytes] = 0;
		stash = ft_strjoin(stash, buffer);
	}
	free (buffer);
	return (stash);
}

char	*extract_new_stash(char	*stash)
{
	int	i;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			stash = ft_substr(stash, i + 1, (ft_strlen(stash) - (i)));
			break ;
		}
		i++;
	}
	return (stash);
}

char	*extract_line(char *stash, char *line)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (stash[i] != '\n')
		len++;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (i <= len)
	{
		line[i] = stash[i];
		i++;
	}
	free (line);
	return (line);
}

int main()
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("GNL 1: %s\n", get_next_line(fd));
	printf("GNL 2: %s\n", get_next_line(fd));
	printf("GNL 3: %s\n", get_next_line(fd));
	printf("GNL 4: %s\n", get_next_line(fd));
	printf("GNL 5: %s\n", get_next_line(fd));
	printf("GNL 6: %s\n", get_next_line(fd));
	printf("GNL 7: %s\n", get_next_line(fd));
	printf("GNL 8: %s\n", get_next_line(fd));
	printf("GNL 9: %s\n", get_next_line(fd));
}
