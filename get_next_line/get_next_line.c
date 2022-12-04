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

char *get_next_line(int fd)
{
	static char	*stash;
	char 		*buffer;
	//char 		*line;
	
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	//stash = stash_filling(fd, stash, buffer); 
	line = extract_line(stash, line);
	stash = extract_new_stash(stash);
	return (stash);
}

char	*stash_filling(int fd, char *stash, char *buffer)
{
	int	i;
	ssize_t	nbytes;

	i = 0;
	nbytes = read(fd, buffer, BUFFER_SIZE);
	buffer[nbytes] = 0;
	if (!stash)
		stash = ft_strdup(buffer);
	else
		stash = ft_strjoin(stash, buffer);
	return (stash);
}

char	*extract_new_stash(char * stash)
{
	int	i;

	i = 0;
	printf("--- extract --- NEW STASH: %s\n", stash);
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			//free(stash);
			printf("-----------ICI--------- \n");
			printf("I: %d\n", i);
			stash = ft_substr(stash, i + 1, (ft_strlen(stash) - (i)));
			printf("STASH: %s\n", stash);
			break ;
		}
		i++;
	}
	return (stash);
}

char	*extract_line(char *stash, char *line)
{
	int	len;

	len = 0;
	while (stash[i] != 'n')
	{
		stash = stash_filling(fd, stash, buffer);
		i++;
	}
	while (stash[len] && stash[len] != '\n')
		len++;
}

int main()
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("stash 1: %s\n", get_next_line(fd));
	printf("stash 2: %s\n", get_next_line(fd));
	printf("stash 3: %s\n", get_next_line(fd));
	printf("stash 4: %s\n", get_next_line(fd));
	printf("stash 5: %s\n", get_next_line(fd));
	printf("stash 6: %s\n", get_next_line(fd));
	printf("stash 7: %s\n", get_next_line(fd));
	printf("stash 8: %s\n", get_next_line(fd));
	printf("stash 9: %s\n", get_next_line(fd));
	/*printf("stash 10: %s\n", get_next_line(fd));
	printf("stash 11: %s\n", get_next_line(fd));
	printf("stash 12: %s\n", get_next_line(fd));
	printf("stash 13: %s\n", get_next_line(fd));
	printf("stash 14: %s\n", get_next_line(fd));
	printf("stash 15: %s\n", get_next_line(fd));
	printf("stash 16: %s\n", get_next_line(fd));*/
}
