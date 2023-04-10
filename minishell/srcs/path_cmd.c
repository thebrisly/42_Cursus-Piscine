/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:08:19 by lfabbian          #+#    #+#             */
/*   Updated: 2023/04/09 15:13:15 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	**get_path(t_minishell *ms)
{
	int		i;
	char	*tmp_val;
	char	*tmp;
	char	**res;

	i = 0;
	tmp_val = get_value(ms, "PATH");
	if (tmp_val)
		tmp = ft_strdup(tmp_val);
	else
		return (0);
	res = ft_split(tmp, ':');
	if (!res)
		res[0] = ft_strdup(tmp);
	free(tmp);
	if (res)
		return (res);
	return (0);
}

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	if (access(cmd, 0) == 0)
		return (ft_strdup(cmd));
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (0);
}
