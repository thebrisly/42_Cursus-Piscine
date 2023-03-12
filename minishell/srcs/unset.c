/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:38:20 by lfabbian          #+#    #+#             */
/*   Updated: 2023/03/12 12:55:34 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	free_unset(t_env *current, int number)
{
	if (number == 0)
		current->previous->next = NULL;
	else if (number == 1)
		current->next->previous = NULL;
	else if (number == 2)
	{
		current->previous->next = current->next;
		current->next->previous = current->previous;
	}
	free (current->key);
	free (current->value);
	free (current);
}

void	mini_unset(t_minishell *ms)
{
	t_env	*current;
	int		i;

	i = 0;
	while (ms->args_tmp[++i])
	{
		current = ms->env_dup;
		while (current)
		{
			if (ft_strcmp(current->key, ms->args_tmp[i]) == 0)
			{
				if (!current->next)
					free_unset(current, 0);
				else if (!current->previous)
					free_unset(current, 1);
				else
					free_unset(current, 2);
				break;
			}
			current = current->next;
		}
	}
}
