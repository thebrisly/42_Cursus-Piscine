/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:39:13 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/21 17:50:37 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

/*char *ft_strrev(char *str)
{
	int debut;
	int fin;
	char swap;
	int longueur;

	debut = 0;
	longueur = 0;
	fin = 0;
	while(str[longueur] != '\0')
		longueur++;
	fin = longueur - 1;
	while (debut < fin)
	{
		swap = str[debut];
		str[debut] = str[fin];
		str[fin] = swap;
		debut ++;
		fin --;
	}
	return (str);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrev2(char *str)
{
	int i;

	int len;
	char tmp;

	i = 0;
	len = ft_strlen(str) - 1;
		while (len > i)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}

char	*ft_strrev3(char *str)
{
	int i;
	int len;
	char tmp;

	len = ft_strlen(str) - 1;
	//printf("%d\n", len);
 	i = 0;
	while (i < len / 2)
	{
		tmp = str[len - i];
		str[len - i] = str[i];
		str[i] = tmp;
		i++;
	}
	return (str);
}/

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int i;
	int len;
	char tmp;

	i = 0;
	len = ft_strlen(str) - 1;
	while (len > i)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}
 */
char *ft_strrev(char *str)
{
	int i;
	int j;
	char save;

	i = 0;
	j = 0;
	while(str[i])
	{
		i++;
	}
	i -= 1;
	while(i > j)
	{
		save = str[i];
		str[i] = str[j];
		str[j] = save;
		i--;
		j++;
	}
	return(str);
}
 /*
int argc, char **argv)int argc, char **argv)?
*/
int main(int argc, char **argv)
{	

	if (argc == 2)
		printf("%s", ft_strrev(argv[1]));
	return(0);
}
