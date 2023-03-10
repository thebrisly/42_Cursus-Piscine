/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:38:20 by lfabbian          #+#    #+#             */
/*   Updated: 2023/03/09 10:00:44 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	duplicate(t_minishell	*ms)
{
	t_env	*tmp;
	t_env	*new;

	tmp = ms->env_dup;
	while(tmp)
	{
		new = env_new(ft_strdup(tmp->key), ft_strdup(tmp->value));
		if (!new)
			return ;
		env_add_end(&ms->env_dup2, new);
		tmp = tmp->next;
	}
}

/*void	mini_unset(t_minishell *ms)
{
	t_env	*current;

	current = ms->env_dup;
	while (current)
	{
		if (ms->args_tmp[1] && ft_strcmp(current->key, ms->args_tmp[1]) == 0)
		{

			// condition si a la fin
			if (!current->next)

			// condition si au debut
			else if (!current->previous)

			// au milieu:
			else
			{
				printf("%s\n", current->key);
				current->previous->next = current->next;
				current->next->previous = current->previous;
				free (current->key);
				free (current->value);
				free (current);
				return ;
			}
		}
		current = current->next;
	}
}*/
