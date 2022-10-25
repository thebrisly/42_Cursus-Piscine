/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:39:27 by brisly            #+#    #+#             */
/*   Updated: 2022/10/23 22:01:47 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strlen1(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

char	*final_lenn(int size, char **strs, char *sep)
{
	char	*final;
	int		final_len;
	int		j;

	j = 0;
	while (j < size)
	{
		final_len = final_len + strlen1(strs[j]);
		j++;
	}
	final_len = final_len + (strlen1(sep) * size - 1);
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
	final = final_lenn(size, strs, sep);
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

/*int	main()
{
	char *strs[4] = {"test0", "test1", "test2", "test3"};
	char	*sep = " blablabliblou ";
	char	*res;
	res = ft_strjoin(4, strs, sep);
	printf("%s", res);
}*/