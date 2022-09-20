/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:20:14 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/15 10:37:39 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_final_len(int size, char **strs, char *sep)
{
	char	*final;
	int		final_len;
	int		j;

	j = 0;
	while (j < size)
	{
		final_len = final_len + ft_strlen(strs[j]);
		j++;
	}
	final_len = final_len + (ft_strlen(sep) * size - 1);
	final = malloc(sizeof(char) * final_len);
	if (size <= 0)
	{
		final = malloc(0);
		return (final);
	}
	return (final);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*final;
	int		i_final;
	int		i_tab;
	int		i;
	int		i_sep;

	i_tab = 0;
	i_final = 0;
	final = ft_final_len(size, strs, sep);
	while (i_tab < size)
	{
		i = 0;
		while (strs[i_tab][i] != '\0')
		{
			final[i_final] = strs[i_tab][i];
			i_final++;
			i++;
		}
		i_sep = -1;
		while ((i_tab < (size - 1)) && (sep[++i_sep] != '\0'))
			final[i_final++] = sep[i_sep];
		i_tab++;
	}
	final[i_final] = '\0';
	return (final);
}
/*#include <stdio.h>
int	main()
{
	char *strs[4] = {"test0", "test1", "test2", "test3"};
	char	*sep = "	";
	char	*res;

	res = ft_strjoin(4, strs, sep);
	printf("%s", res);
}*/
