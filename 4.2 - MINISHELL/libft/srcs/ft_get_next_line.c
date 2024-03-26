/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:31:55 by dferreir          #+#    #+#             */
/*   Updated: 2022/11/24 11:10:53 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_whole(int fd, char *res)
{
	char	*buffer;
	char	*tmp;
	int		len;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	len = 42;
	while (len > 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[len] = '\0';
		tmp = ft_strjoin(res, buffer);
		free(res);
		res = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*cut_line(char *buffer)
{
	char	*res;
	int		i;

	i = 0;
	if (!buffer[i])
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	res = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		res[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		res[i] = '\n';
	return (res);
}

char	*to_next(char *buffer)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	res = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		res[j++] = buffer[i++];
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	buffer[fd] = read_whole(fd, buffer[fd]);
	if (!buffer[fd])
		return (0);
	res = cut_line(buffer[fd]);
	buffer[fd] = to_next(buffer[fd]);
	return (res);
}
