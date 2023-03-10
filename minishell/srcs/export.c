/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:00:55 by lfabbian          #+#    #+#             */
/*   Updated: 2023/03/08 16:07:38 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 && *s2) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	sort_env(t_minishell *ms)
{
	t_env *current;
	t_env	**sorted;
	int size;
	int i;
	t_env *min;

	i = 1;
	size = env_size(ms->env_dup2);
	sorted = malloc(size * sizeof(t_env *));

	// find min (pour premier element)
	while (i < size) //itere dans tab trie
	{
		min = sorted[i - 1];
		current = ms->env_dup2;
		while (current) // itere dans env dup
		{
			if (!min)
				min = current;
			else if (min->key > current->key)
				min = current;
			// comparer la cle de min avec cle de current
			current = current->next;
		}
		sorted[i] = min;
		i++;
	}

	// imprimer sorted


	// sorted[0] = ms->env_dup2;
	// sorted[1] = ms->env_dup2->next->next;
	// sorted[2] = ms->env_dup2->next;

	// printf("%s & %s\n", sorted[0]->key, sorted[0]->value);
	// printf("%s & %s\n", sorted[1]->key, sorted[1]->value);
	// printf("%s & %s\n", sorted[2]->key, sorted[2]->value);
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

void	mini_export(t_minishell *ms)
{
	t_env	*tmp;
	char	**kvtmp;
	int		i = 0;

	duplicate(ms);
	tmp = ms->env_dup2;
	if  (!ms->args_tmp[1])
	{
		sort_env(ms);
		print_export(ms);
	}
	else
	{
		while (ms->args_tmp[++i])
		{
			if (ft_strchr(ms->args_tmp[i], '='))
			{
				kvtmp = ft_split(ms->args_tmp[i], '=');
				if (!kvtmp)
					return ;
				add_env_var(ms, ft_strdup(kvtmp[0]), ft_strdup(kvtmp[1]));
				free(kvtmp[0]);
				free(kvtmp[1]);
				free(kvtmp);
			}
		}
	}
	while (tmp)
	{
		printf("%s & %s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
	free_export(ms);
	ms->env_dup2 = 0;
}

// void	mini_export(t_minishell *ms)
// {
// 	char		**kvtmp;
// 	int			i;
// 	size_t		j;

// 	j = 0;
// 	i = 0;
// 	// if (!ms->env_dup2)
// 	// 	ms->env_dup2 = env_init(ms);
// 	if  (!ms->args_tmp[1])
// 	{
// 		sort_env(ms);
// 		print_export(ms);
// 	}
//     else
//     {
// 		while (ms->args_tmp[++i])
// 		{
// 			if (ft_strchr(ms->args_tmp[i], '='))
// 			{
// 				kvtmp = ft_split(ms->args_tmp[i], '=');
// 				if (!kvtmp)
// 					return ;
// 				// add_env_var(ms, ft_strdup(kvtmp[0]), ft_strdup(kvtmp[1]), ms->env_dup);
// 				// add_env_var(ms, ft_strdup(kvtmp[0]), ft_strdup(kvtmp[1]), ms->env_dup2);
// 				free(kvtmp[0]);
// 				free(kvtmp[1]);
// 				free(kvtmp);
// 			}
// 			else
// 			{
// 				if (ft_isalpha(ms->args_tmp[i][j]))
// 				{
// 					while (ft_isalpha(ms->args_tmp[i][j]) || ft_isdigit(ms->args_tmp[i][j]))
// 						j++;
// 				}
// 				if (j == ft_strlen(ms->args_tmp[i]))
// 				{
// 					// add_env_var(ms, ft_strdup(ms->args_tmp[i]), 0, ms->env_dup);
// 					// add_env_var(ms, ft_strdup(ms->args_tmp[i]), 0, ms->env_dup2);
// 				}
// 				else
// 				{
// 					ft_printf("export: %s not a valid identifier\n", ms->args_tmp[i]);
// 				}
// 			}
// 		}
// 	}
// 	//ne pas oublier de free ma duplication et de set a NULL
// }
