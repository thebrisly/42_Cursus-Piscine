/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:00:55 by lfabbian          #+#    #+#             */
/*   Updated: 2023/03/31 14:46:23 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

/* quand export message ou export message=
utiliser replace_value au lieu de get_value ! */
void	special_cases(t_minishell *ms, int i)
{
	size_t	j;

	j = -1;
	while (ft_isalpha(ms->args_tmp[i][++j]) || ft_isdigit(ms->args_tmp[i][j]))
		;
	if (j == ft_strlen(ms->args_tmp[i]))
		add_env_var(ms, ft_strdup(ms->args_tmp[i]), 0);
	else
	{
		ft_printf("minihell: export: %s not a valid identifier\n", \
			ms->args_tmp[i]);
		ms->err = 1;
	}
}

/* si on veut ajouter une valeur de maniere normale
ou en remplacer une normalement comme suit: export message=hello */
void	normal_case(t_minishell *ms, int i, char **kvtmp)
{
	if (replace_value(ms, kvtmp[0]))
	{
		if (kvtmp[1] == 0)
		{
			free(replace_value(ms, kvtmp[0])->value);
			replace_value(ms, kvtmp[0])->value = 0;
		}
		else
		{
			free(replace_value(ms, kvtmp[0])->value);
			replace_value(ms, kvtmp[0])->value = ft_strdup(kvtmp[1]);
		}
	}
	else if (ft_strchr(ms->args_tmp[i], '='))
	{
		if (kvtmp[1] == 0)
			add_env_var(ms, ft_strdup(kvtmp[0]), 0);
		else
			add_env_var(ms, ft_strdup(kvtmp[0]), ft_strdup(kvtmp[1]));
	}
}

void	export_init(t_minishell *ms)
{
	duplicate(ms);
	ms->export = NULL;
	sort_export(ms);
	if (!ms->args_tmp[1])
		print_export(ms);
}

void	valid_export(t_minishell *ms, int i)
{
	char		**kvtmp;

	kvtmp = ft_split2(ms, ms->args_tmp[i], '=');
	if (!kvtmp)
		return ;
	if (replace_value(ms, kvtmp[0]) \
		|| ft_strchr(ms->args_tmp[i], '='))
		normal_case(ms, i, kvtmp);
	else
		special_cases(ms, i);
	free(kvtmp[0]);
	free(kvtmp[1]);
	free(kvtmp);
}

void	mini_export(t_minishell *ms)
{
	int			i;

	i = 0;
	export_init(ms);
	if (ms->args_tmp[1])
	{
		while (ms->args_tmp[++i])
		{
			if (ft_isalpha(ms->args_tmp[i][0]))
				valid_export(ms, i);
			else
			{
				ms->err = 1;
				printf("minihell: export: %s: \
					not a valid identifier\n", ms->args_tmp[i]);
			}
		}
	}
	free_export(ms);
	ms->env_dup2 = 0;
}
