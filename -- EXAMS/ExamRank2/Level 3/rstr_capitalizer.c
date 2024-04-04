/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:51:26 by brisly            #+#    #+#             */
/*   Updated: 2023/02/20 10:10:31 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*char ft_majuscule(char letter)
{
	if (letter >= 65 & letter <= 90)
		return (letter);
	else if (letter >= 97 & letter <= 122)
		return (letter - 32);
}

char ft_minuscule(char letter)
{
	if (letter >= 65 & letter <= 90)
		return (letter + 32);
	else if (letter >= 97 & letter <= 122)
		return (letter);
}

int main(int argc, char **argv)
{
	int i = 1;
	int words = argc - 1;

	if (argc > 1)
	{
		while (i <= words)
		{
			int j = 0;
			while (argv[i][j])
			{
				if (argv[i][j + 1] == 0)
					argv[i][j] = ft_majuscule(argv[i][j]);
				else
					argv[i][j] = ft_minuscule(argv[i][j]);
				write (1, &argv[i][j], 1);
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}*/

void    rstr_capitalizer(char *str)
{
    int i = 0;

    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        if ((str[i] >= 'a' && str[i] <= 'z') && (str[i + 1] == ' ' \
                    || str[i + 1] == '\t' || str[i + 1] == '\0'))
            str[i] -= 32;
        write(1, &str[i++], 1);
    }
}

int main(int argc, char **argv)
{
    int i;

    if (argc == 1)
        write(1, "\n", 1);
    else
    {
        i = 1;
        while (i < argc)
        {
            rstr_capitalizer(argv[i]);
            write(1, "\n", 1);
            i += 1;
        }
    }
    return (0);
}