/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:39:27 by brisly            #+#    #+#             */
/*   Updated: 2022/10/28 14:18:26 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*final_len(int size, char **s1, char *s2)
{
	char	*final;
	int		final_len;
	int		j;

	j = 0;
	while (j < size)
	{
		final_len = final_len + ft_strlen(s1[j]);
		j++;
	}
	final_len = final_len + (ft_strlen(s2) * size - 1);
	final = malloc(sizeof(char) * final_len);
	if (size <= 0)
	{
		final = malloc(0);
		return (final);
	}
	return (final);
}

char	*ft_strjoin(int size, char **s1, char *s2)
{
	char	*final;
	int		i_final;
	int		i_tab;
	int		i;
	int		i_s2;

	i_tab = 0;
	i_final = 0;
	final = final_len(size, s1, s2);
	while (i_tab < size)
	{
		i = 0;
		while (s1[i_tab][i] != '\0')
		{
			final[i_final] = s1[i_tab][i];
			i_final++;
			i++;
		}
		i_s2 = -1;
		while ((i_tab < (size - 1)) && (s2[++i_s2] != '\0'))
			final[i_final++] = s2[i_s2];
		i_tab++;
	}
	final[i_final] = '\0';
	return (final);
}

/*int	main()
{
	char *s1[4] = {"test0", "test1", "test2", "test3"};
	char	*s2 = " blablabliblou ";
	char	*res;
	res = ft_strjoin(4, s1, s2);
	printf("%s", res);
}*/