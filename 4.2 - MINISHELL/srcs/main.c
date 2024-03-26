/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:40:00 by dferreir          #+#    #+#             */
/*   Updated: 2023/04/10 13:01:21 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	*cutter(t_minishell *ms, char *str, int i)
{
	char	**tmp_array;
	char	*tmp;
	char	*tmp2;

	if (!str[i + 1])
		return ("$");
	tmp_array = 0;
	tmp = 0;
	tmp2 = ft_substr(str, i + 1, ft_strlen(str));
	tmp2 = cutter_start(tmp_array, tmp, tmp2, i);
	i = -1;
	ms->dol = -1;
	return (cutter_middle(ms, tmp, tmp2));
}

void	expander(t_minishell *ms, int i)
{
	char	*res;
	char	*tmp;

	ms->i = i;
	ms->j = -1;
	ms->x = -1;
	res = ft_calloc(1000, sizeof(char));
	tmp = 0;
	ms->quote = 0;
	expander_start(ms, res, tmp);
	expander_end(ms, res, i);
}

int	end_check(t_minishell *ms)
{
	int	i;

	if (!ft_strncmp(ms->args[0], "||", 3)
		|| !ft_strncmp(ms->args[0], "&&", 3)
		|| !ft_strncmp(ms->args[0], "|", 2))
		return (0);
	if ((!ms->args[1] || !ms->args[2])
		&& (!ft_strncmp(ms->args[0], "<", 2)
			|| !ft_strncmp(ms->args[0], ">", 2)
			|| !ft_strncmp(ms->args[0], ">>", 3)))
		return (0);
	i = -1;
	while (ms->args[++i])
		;
	if (!ft_strncmp(ms->args[i - 1], "||", 3)
		|| !ft_strncmp(ms->args[i - 1], "&&", 3)
		|| !ft_strncmp(ms->args[i - 1], "|", 2)
		|| !ft_strncmp(ms->args[i - 1], "<", 2)
		|| !ft_strncmp(ms->args[i - 1], ">", 2)
		|| !ft_strncmp(ms->args[i - 1], ">>", 3))
		return (0);
	return (1);
}

void	minishell(t_minishell *ms)
{
	if (!end_check(ms))
	{
		printf("syntax error near unexpected token '%s'\n", ms->args[0]);
		ms->err_prev = 258;
	}
	else
		minishell_loop1(ms);
	minishell_end(ms);
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell		ms;
	struct termios	termios;

	if (tcgetattr(STDIN_FILENO, &termios) == -1)
		exit(EXIT_FAILURE);
	termios.c_lflag &= ~(ECHOCTL);
	if ((tcsetattr(STDIN_FILENO, TCSANOW, &termios)) == -1)
		exit(EXIT_FAILURE);
	if (argc == 1 && !ft_strncmp("./minishell", argv[0], 12))
	{
		init_vars(&ms, 0, envp);
		while (1)
			init_prompt(&ms, envp);
		rl_clear_history();
	}
	else
		print_err("\"./minishell\" must be the only argument");
}
