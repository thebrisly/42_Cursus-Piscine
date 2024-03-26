/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:42:47 by lfabbian          #+#    #+#             */
/*   Updated: 2023/03/31 13:37:14 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	duplicate(t_minishell	*ms)
{
	t_env	*tmp;
	t_env	*new;
	char	*key;

	tmp = ms->env_dup;
	while (tmp)
	{
		key = ft_strdup(tmp->key);
		if (!tmp->value)
			new = env_new(key, 0);
		else
			new = env_new(key, ft_strdup(tmp->value));
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
	t_env	*tmp;

	while (ms->export)
	{
		tmp = ms->export->next;
		free(ms->export->key);
		free(ms->export->value);
		free(ms->export);
		ms->export = tmp;
	}
}

void	print_export(t_minishell *ms)
{
	t_env	*tmp;

	tmp = ms->export;
	while (tmp)
	{
		if (!tmp->value)
			printf("declare -x %s\n", tmp->key);
		else
			printf("declare -x %s=\"%s\"\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}
