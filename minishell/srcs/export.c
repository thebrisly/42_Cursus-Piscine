/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:00:55 by lfabbian          #+#    #+#             */
/*   Updated: 2023/03/12 14:11:39 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	sort_export(t_minishell *ms)
{
	ms->export = NULL;
	t_env *current = ms->env_dup2;
	t_env *temp;

	while (current != NULL)
	{
		t_env *next = current->next;
		if (ms->export == NULL || ft_strcmp(current->key, ms->export->key) < 0)
		{
			current->next = ms->export;
			if (ms->export != NULL)
				ms->export->previous = current;
			ms->export = current;
		}
		else
		{
			temp = ms->export;
			while (temp->next != NULL && ft_strcmp(current->key, temp->next->key) >= 0)
				temp = temp->next;
			current->next = temp->next;
			if (temp->next != NULL)
				temp->next->previous = current;
			temp->next = current;
			current->previous = temp;
		}
		current = next;
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

void	mini_export(t_minishell *ms)
{
	char		**kvtmp;
	int			i;
	size_t		j;

	i = 0;
	duplicate(ms);
	sort_export(ms);			//chercher d'ou viennent les leaks
	if  (!ms->args_tmp[1])
		print_export(ms);
    else
    {
		while (ms->args_tmp[++i])
		{
			kvtmp = ft_split(ms->args_tmp[i], '=');
			if (!kvtmp)
				return ;
			if (get_value(ms, kvtmp[0]))
				replace_value(ms, kvtmp[0])->value = ft_strdup(kvtmp[1]);
			else if (ft_strchr(ms->args_tmp[i], '=') && ms->args_tmp[i][0] != '=')
				add_env_var(ms, ft_strdup(kvtmp[0]), ft_strdup(kvtmp[1]));
			else
			{
				j = -1;
				if (ft_isalpha(ms->args_tmp[i][j+1]))
					while (ft_isalpha(ms->args_tmp[i][++j]) || ft_isdigit(ms->args_tmp[i][j]));
				if (j == ft_strlen(ms->args_tmp[i]))
					add_env_var(ms, ft_strdup(ms->args_tmp[i]), 0);
				else
					ft_printf("export: %s not a valid identifier\n", ms->args_tmp[i]);
			}
			free(kvtmp[0]);
			free(kvtmp[1]);
			free(kvtmp);
		}
	}
	free_export(ms);
	ms->env_dup2 = 0;
}
