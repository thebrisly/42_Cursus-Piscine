/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:42:47 by lfabbian          #+#    #+#             */
/*   Updated: 2023/03/14 10:28:53 by lfabbian         ###   ########.fr       */
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
		if (!tmp->value)
			new = env_new(ft_strdup(tmp->key), 0);
		else
			new = env_new(ft_strdup(tmp->key), ft_strdup(tmp->value));
		if (!new)
			return ;
		env_add_end(&ms->env_dup2, new);
		tmp = tmp->next;
	}
}

char	*get_value(t_minishell *ms, char *str)
{
	t_env	*tmp;

	tmp = ms->env_dup;
	while (tmp)
	{
		if (ft_strcmp(str, tmp->key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

t_env	*replace_value(t_minishell *ms, char *str)
{
	t_env	*tmp;

	tmp = ms->env_dup;
	while (tmp)
	{
		if (ft_strcmp(str, tmp->key) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	free_export(t_minishell *ms)
{
	t_env *tmp;

	while (ms->env_dup2)
	{
		tmp = ms->env_dup2->next;
		free(ms->env_dup2->key);
		free(ms->env_dup2->value);
		free(ms->env_dup2);
		ms->env_dup2 = tmp;
	}
}
