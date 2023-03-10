/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:42:47 by lfabbian          #+#    #+#             */
/*   Updated: 2023/03/08 14:14:44 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

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

//char *is
// if "is" != 0 alors ca veut dire qu'il est dedans
