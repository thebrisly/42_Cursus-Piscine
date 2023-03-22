/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:00:55 by lfabbian          #+#    #+#             */
/*   Updated: 2023/03/22 12:59:48 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

/* si on veut ajouter une valeur de maniere normale ou en remplacer une normalement comme suit: export message=hello */
void	normal_case(t_minishell *ms, int i)
{
	size_t	j;

	j = -1;
	if (ft_isalpha(ms->args_tmp[i][j + 1]))
		while (ft_isalpha(ms->args_tmp[i][++j]) || ft_isdigit(ms->args_tmp[i][j]))
			;
	if (j == ft_strlen(ms->args_tmp[i]))
		add_env_var(ms, ft_strdup(ms->args_tmp[i]), 0);
	else
		ft_printf("export: %s not a valid identifier\n", ms->args_tmp[i]);
}

/* quand export message ou export message=
utiliser replace_value au lieu de get_value ! */
void	special_cases(t_minishell *ms, int i);


void	mini_export(t_minishell *ms)
{
	char		**kvtmp;
	int			i;

	i = 0;
	duplicate(ms);
	ms->export = NULL;
	sort_export(ms);
	if (!ms->args_tmp[1])
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
				normal_case(ms, i);
			free(kvtmp[0]);
			free(kvtmp[1]);
			free(kvtmp);
		}
	}
	free_export(ms);
	ms->env_dup2 = 0;
}
