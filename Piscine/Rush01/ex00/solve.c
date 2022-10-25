/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:32:09 by pkondrac          #+#    #+#             */
/*   Updated: 2022/09/11 14:03:39 by pkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define DEBUG 0

int	*ft_allocateptr(int x);
int **ft_allocatepptr(int x, int y);

int	find(int n, int *a, int size)
{
	int i;

	i = 0;
	while (i < size)
		if (a[i++] == n)
			return (1);
	return (0);
}

int	count(int n, int *a, int size)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (i < size)
		if (a[i++] == n)
			count++;
	return (count);
}

int *get_remaining(int *line, int size)
{
	int *p;
	int i;
	int j;

	p = ft_allocateptr(size - count(0, line, size));
	i = 0;
	j = 0;
	while (i < size)
	{
		if (line[i] != 0)
			p[j++] = line[i];
		i++;
	}
	if (j == 0)
	{
		p = ft_allocateptr(1);
		p[0] = 0;
	}

	return (p);
}

int	check_conditions(int *line, int start, int end, int size)
{
	//get remaining
	
	//foreach fill possibilits check sight from start and end
	
	//check sight from start
	//'   ' end
	
	
	return (1);
}

int	*possibilities(int **tab, int **con, int x, int y)
{
	int	*p; //possibilities
	int	*h; //horizontal
	int	*v; //vertical
	int	u; //up
	int	d; //down
	int	l; //left
	int	r; //right
	int i;
	int j;
	int	t;
	int *p2; //possibilites without the zero

	t = 4; //len(tab[0]);
	u = con[0][x];
	d = con[1][x];
	l = con[2][y];
	r = con[3][y];
	h = tab[x];
	v = ft_allocateptr(t); //HERE
	i = 0;
	while (tab[i][y])
		v[i] = tab[i][y++];

	if (DEBUG)
	{
		printf("u:%d d:%d l:%d r:%d \n", u, d, l, r );
		printf("hor: %d %d %d %d \n", h[0], h[1], h[2], h[3]);
		printf("ver: %d %d %d %d \n", v[0], v[1], v[2], v[3]);
	}
	p = ft_allocateptr(t); //HERE
	//horizontal and vertical remove at same time as innitialization of p
	i = 1;
	while (i <= t)
	{
		if (find(i, h, t))
			p[i-1] = 0;
		else if (find(i, v, t))
			p[i-1] = 0;
		else
			p[i-1] = i;
		i++;
	}
	if(DEBUG)
		printf("%d %d %d %d\n", p[0], p[1], p[2], p[3]); //0,2,0,4
	//Condition check (sight and stuff) for each non-zero
	i = 0;
	while (i < t)
	{
		if (p[i] == 0)
		{
			i++;
			continue;
		}
		h[x] = p[i];
		v[y] = p[i];
		if (!(check_conditions(v, u, d, t) && check_conditions(h, l, r, t)))
			p[i] = 0;
		else if(DEBUG)
			printf("Sucessful check for value %d\n", p[i]);
		i++;
	}
	
	//Filter out the zeros from the p array into the p2
	p2 = ft_allocateptr(t - count(0, p, t));
	i = 0;
	j = 0;
	while (i < t)
	{
		if (p[i] != 0)
			p2[j++] = p[i];
		i++;
	}
	if (j == 0)
	{
		p2 = ft_allocateptr(1);
		p2[0] = 0;
	}
	return (p2);
}

int main(void)
{
	//int	tab[4][4] = {{0,4,0,0}, {1,0,3,4}, {0,4,0,0}, {0,4,0,0}};
	//int	con[4][4] = {{1,4,2,3}, {1,2,3,4}, {1,4,2,3}, {1,2,3,4}};
	int **tab = ft_allocatepptr(4, 4);
	int	**con = ft_allocatepptr(4, 4);
	con[0][2] = 3;
	con[1][2] = 2;
	con[2][2] = 2;
	con[3][2] = 3;
	tab[2][0] = 1;
	tab[2][3] = 3;
	possibilities((int**)tab, (int**)con, 2, 2);
}
