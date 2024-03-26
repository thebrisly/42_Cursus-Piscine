/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:20:09 by brisly            #+#    #+#             */
/*   Updated: 2023/02/20 09:32:55 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "list.h"

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
}



t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int swap;
	t_list tmp;

	tmp = lst;
	while (lst->next != NULL)
	{
		if ((*cmp)(lst->data, lst->next) == 0)
		{
			swap = lst->data;
			lst->data = lst->next;
			lst->next = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}