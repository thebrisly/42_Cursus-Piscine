/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:03:59 by dferreir          #+#    #+#             */
/*   Updated: 2023/04/10 13:15:12 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	expander_dollar(t_minishell *ms, char *res, char *tmp)
{
	tmp = cutter(ms, ms->args[ms->i], ms->j);
	if (tmp)
	{
		ft_strlcat(res, tmp, ft_strlen(tmp) + ft_strlen(res) + 1);
		ms->x += ft_strlen(tmp);
		if (ms->dol == -1)
			ms->x += 2;
	}
	if (ft_strlen(ms->args[ms->i]) != 1)
	{
		if (ms->dol == -1)
		{
			ms->j += ft_strlen(tmp);
			if (tmp[1] == '$')
				ms->j--;
		}
		else if ((size_t)ms->dol > ft_strlen(ms->args[ms->i]))
			ms->j += ft_strlen(ft_strtrim(ft_split(ft_split(ft_substr(
									ms->args[ms->i], ms->j + 1,
									ft_strlen(ms->args[ms->i])), ' ')
						[0], '\"')[0], "\""));
		else
			ms->j += ms->dol;
		free(tmp);
	}
}

void	detect_redirections(t_minishell *ms)
{
	if (!ms->j && !ft_strncmp(ms->args[ms->i], ">", 2))
		ms->outf = 1;
	else if (!ms->j && !ft_strncmp(ms->args[ms->i], "<", 2))
		ms->inf = 1;
	else if (!ms->j && !ft_strncmp(ms->args[ms->i], ">>", 3))
		ms->appf = 1;
}

void	expander_start(t_minishell *ms, char *res, char *tmp)
{
	while (ms->args[ms->i][++ms->j])
	{
		if (ms->args[ms->i][ms->j] == '\'' || ms->args[ms->i][ms->j] == '\"')
			quote_expander(ms, res);
		else if (ms->args[ms->i][ms->j] == '$'
			&& (!ms->quote || ms->quote == '\"'))
			expander_dollar(ms, res, tmp);
		else if (!ms->j && (!ft_strncmp(ms->args[ms->i], ">", 2)
				|| !ft_strncmp(ms->args[ms->i], "<", 2)
				|| !ft_strncmp(ms->args[ms->i], ">>", 3)))
			detect_redirections(ms);
		else if (ft_strncmp(ms->args[ms->start], "cd", 3)
			&& (!ft_strncmp(ms->args[ms->i], ".", 2)
				|| !ft_strncmp(ms->args[ms->i], "..", 3)));
		else
			res[++ms->x] = ms->args[ms->i][ms->j];
	}
}

void	open_file(t_minishell *ms, char *res, int sig)
{
	if (!sig)
	{
		ms->in_out_acc += 2;
		ms->outf = 0;
		ms->output = open(res, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (ms->output < 0)
			ms->err = 1;
		dup2(ms->output, 1);
	}
	else
	{
		ms->in_out_acc += 2;
		ms->inf = 0;
		ms->input = open(res, O_RDONLY);
		if (ms->input < 0)
		{
			ms->err = 1;
			printf("%s: No such file or directory\n", res);
		}
		dup2(ms->input, 0);
	}
}

void	expander_end(t_minishell *ms, char *res, int i)
{
	if (ms->outf == 1)
		ms->outf = 2;
	else if (ms->inf == 1)
		ms->inf = 2;
	else if (ms->appf == 1)
		ms->appf = 2;
	else if (ms->outf == 2)
		open_file(ms, res, 0);
	else if (ms->inf == 2)
		open_file(ms, res, 1);
	else if (ms->appf == 2)
	{
		ms->in_out_acc += 2;
		ms->appf = 0;
		ms->output = open(res, O_WRONLY | O_APPEND | O_CREAT, 0644);
		if (ms->output < 0)
			ms->err = 1;
		dup2(ms->output, 1);
	}
	else
		ms->args_tmp[i - ms->start - ms->in_out_acc] = ft_strdup(res);
	free(res);
}
