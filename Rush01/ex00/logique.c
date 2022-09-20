/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logique.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:55:34 by lvon-war          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/11 11:57:26 by lfabbian         ###   ########.fr       */
=======
/*   Updated: 2022/09/11 15:02:34 by lvon-war         ###   ########.fr       */
>>>>>>> a27553ef2cb540dec8466b68bd2fd445c244716a
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int		*ft_allocateptr(int x);
int		**ft_allocatepptr(int x, int y);
void	ft_print(int **board, int x, int y);
int		ft_test_tab(int **board, int nbx, int nby);
int		*possibilities(int **tab, int **con, int x, int y);
int		ft_logique(int **board, int **crtab, int nbx, int nby);
void	ft_easyfill(int **board, int **crittab, int x, int y);

int	ft_calledloop(int **board, int **crtab, int i, int j, int nbx, int nby)
{
	int	*soluce;
	int soln;

	soln = 0;
	soluce = possibilities(board, crtab, i, j);
	if (soluce[0] == 0)
		return (0);
	else if (i == nbx - 1 && j == nby - 1 && soluce[1] == '\0')
	{
		board[j][i] = soluce[0];
		return (1);
	}
	while (soluce[soln])
	{
		board[j][i] = soluce[soln];
		if (ft_logique(board, crtab, nbx, nby))
		{
			return (1);
		}
		soln++;
	}
	board[j][i] = 0;
	return (0);
}

int	ft_logique(int **board, int **crtab, int nbx, int nby)
{
	ft_print(board, nbx, nby);
	int	i;
	int	j;

	j = 0;
	while (j < nbx)
	{
		i = 0;
		while (i < nby)
		{
			printf("i = %i | j = %i\n", i, j);
			if (board[j][i] == 0)
			{
				if (ft_calledloop(board, crtab, i, j, nbx, nby))
					return (1);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	main(void)
{
	int	**board;
	int	**crittab;
	int	x;
	int	y;

	x = 4;
	y = 4;
	board = ft_allocatepptr(x, y);
	crittab = ft_allocatepptr(x, y);
	crittab[UP][0] = 1;
	crittab[UP][1] = 2;
	crittab[UP][2] = 2;
	crittab[UP][3] = 4;
	crittab[DOWN][0] = 3;
	crittab[DOWN][1] = 2;
	crittab[DOWN][2] = 3;
	crittab[DOWN][3] = 1;
	crittab[LEFT][0] = 1;
	crittab[LEFT][1] = 2;
	crittab[LEFT][2] = 2;
	crittab[LEFT][3] = 3;
	crittab[RIGHT][0] = 3;
	crittab[RIGHT][1] = 2;
	crittab[RIGHT][2] = 2;
	crittab[RIGHT][3] = 1;
	ft_easyfill(board, crittab, x, y);
	if (ft_logique(board, crittab, x, y))
	{
		printf("\nsucces");
	}
	else
		printf("\nfail");
	ft_print(board, x, y);
	free(board);
	free(crittab);
	return (0);
}
