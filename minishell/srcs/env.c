/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:34:38 by dferreir          #+#    #+#             */
/*   Updated: 2023/02/28 14:48:01 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	env_count(t_minishell ms)
{
	ms.env_len = 0;

	while(ms.env[ms.env_len])
		ms.env_len++;
	return (ms.env_len);
}

void	env_sep_variable(t_minishell *ms)
{
	int sep;
	int i;
	int	j;

	sep = 0;
	i = -1;
	j = 0;
	ms->str_var = "message=hello";	//a effacer ensuite, c'est juste pour tester en attendant
	while (ms->str_var[sep] != '=')
		sep++;
	ms->key = ft_calloc(sep + 1, sizeof(char));
	if (!ms->key)
		return ;
	ms->value = ft_calloc(ft_strlen(ms->str_var) - sep + 1, sizeof(char));
	if (!ms->value)
		return ;
	while (ms->str_var[++i] != '=')
		ms->key[i] = ms->str_var[i];
	while (ms->str_var[++i])
	{
		ms->value[j] = ms->str_var[i];
		j++;
	}
}

/* A FAIRE*/
// void	env_add_var(t_minishell ms)
// {
// 	int		i;

// 	i = 0;
// 	while (i)

// }

// void	env_modify(t_minishell ms)
// {
// 	int i;

// 	i = 0;
// 	env_sep_variable(ms);
// 	if (ms.env_variables[i])
// 	{

// 	}
// 	else
// 		env_add_var(&ms);
// }

void	mini_env(t_minishell ms)
{
	int i;

	i = -1;
	env_sep_variable(&ms);
}
