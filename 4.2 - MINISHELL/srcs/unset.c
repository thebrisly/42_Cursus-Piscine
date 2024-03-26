/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:38:20 by lfabbian          #+#    #+#             */
/*   Updated: 2023/03/31 14:18:26 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	delete_np(int number, t_env *current)
{
	if (number == 1)
		current->next->previous = NULL;
	else if (number == 2)
	{
		current->previous->next = current->next;
		current->next->previous = current->previous;
	}
}

void	free_unset(t_env *current, int number, t_minishell *ms)
{
	if (number == 0)
	{
		if (!current->previous)
		{
			free (current->key);
			free (current->value);
			current->value = 0;
			free (current);
			current = 0;
			ms->env_dup = 0;
			return ;
		}
		current->previous->next = NULL;
	}
	if (number == 1 || number == 2)
		delete_np(number, current);
	free (current->key);
	free (current->value);
	current->value = 0;
	free (current);
	if (number == 1)
		ms->env_dup = ms->env_dup->next;
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
					free_unset(current, 0, ms);
				else if (!current->previous)
					free_unset(current, 1, ms);
				else
					free_unset(current, 2, ms);
				break ;
			}
			current = current->next;
		}
	}
}
