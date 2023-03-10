/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:34:38 by dferreir          #+#    #+#             */
/*   Updated: 2023/03/09 09:58:28 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	add_env_var(t_minishell *ms, char *key, char *value)
{
	t_env	*new_var;

	new_var = env_new(key ,value);
	if (!new_var)
		return ;
	env_add_end(&ms->env_dup, new_var);
	// ft_printf("%s\n", ms->env_dup->key);
}

void	env_init(t_minishell *ms)
{
	int		i;
	char	**tmp;

	i = 0;
	while (ms->env[i])
	{
		tmp = ft_split(ms->env[i], '=');
		if (!tmp)
			return ;
		add_env_var(ms, ft_strdup(tmp[0]), ft_strdup(tmp[1])); //ne pas oublier de free cle valeur
		free(tmp[0]);
		free(tmp[1]);
		free(tmp);
		i++;
	}
}

/*void	env_pointer(t_minishell	*ms)
{
	int counter;
	t_env	*tmp;

	counter = 1;
	tmp = ms->env_dup;
	while (tmp)
	{
		if (counter == 1)
		{
			ms->env_ptr->head = tmp;
			counter++;
		}
		else
			tmp = tmp->next;
	}
	ms->env_ptr->tail = tmp;
}*/

void	mini_env(t_minishell *ms)
{
	t_env *tmp;

	tmp = ms->env_dup;
	while (tmp)
	{
		if (tmp->value)
			printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}
