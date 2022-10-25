/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:48:49 by lvon-war          #+#    #+#             */
/*   Updated: 2022/09/11 12:17:48 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

void caseofone(int **board, int i, int j)
{
	if (j == UP)
		board[0][i] = 4;
	else if (j == DOWN)
		board[3][i] = 4;
	else if (j == LEFT)
		board[i][0] = 4;
	else if (j == RIGHT)
		board[i][3] = 4;
}

void caseoffour(int **board, int i, int j)
{
	if (j == UP)
	{
		board[0][i] = 1;
		board[1][i] = 2;
		board[2][i] = 3;
		board[3][i] = 4;
	}
	else if (j == DOWN)
	{
		board[3][i] = 1;
		board[2][i] = 2;
		board[1][i] = 3;
		board[0][i] = 4;
	}
	else if (j == LEFT)
	{
		board[i][0] = 1;
		board[i][1] = 2;
		board[i][2] = 3;
		board[i][3] = 4;
	}
	else if (j == RIGHT)
	{
		board[i][3] = 4;
		board[i][2] = 3;
		board[i][1] = 2;
		board[i][0] = 1;
	}
}

void	ft_easyfill(int **board, int **crittab, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			if (crittab[j][i] == 1)
				caseofone(board, i, j);
			else if (crittab[j][i] == 4)
				caseoffour(board, i, j);
			i++;
		}
		j++;
	}
}
