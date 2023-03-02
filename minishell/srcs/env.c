/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:34:38 by dferreir          #+#    #+#             */
/*   Updated: 2023/03/02 13:57:07 by lfabbian         ###   ########.fr       */
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

void	mini_env(t_minishell *ms)
{
	t_env *tmp;

	tmp = ms->env_dup;
	while (tmp)
	{
		ft_printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

// void	mini_env(t_minishell *ms)
// {
// 	t_env *tmp;

// 	// tmp = ms->env_dup;
// 	while (ms->env_dup)
// 	{
// 		tmp = ms->env_dup->next;
// 		free(ms->env_dup->key);
// 		free(ms->env_dup->value);
// 		free(ms->env_dup);
// 		ms->env_dup = tmp;
// 		// ft_printf("%s=%s\n", tmp->key, tmp->value);
// 		// tmp = tmp->next;
// 	}
// }
