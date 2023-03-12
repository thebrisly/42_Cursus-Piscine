/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:39:49 by lfabbian          #+#    #+#             */
/*   Updated: 2023/03/12 11:26:38 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

t_env	*env_new(char *key, char *value)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = key;
	new->value = value;
	new->next = 0;
	new->previous = 0;
	return (new);
}

t_env	*env_last(t_env	*lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;

	return(lst);
}

void	env_add_end(t_env **lst, t_env *new)
{
	t_env	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = env_last(*lst);
	last->next = new;
	new->previous = last;
}

int	env_size(t_env *lst)
{
	int len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

void	free_env(t_minishell *ms)
{
	t_env *tmp;

	while (ms->env_dup)
	{
		tmp = ms->env_dup->next;
		free(ms->env_dup->key);
		free(ms->env_dup->value);
		free(ms->env_dup);
		ms->env_dup = tmp;
	}
}
