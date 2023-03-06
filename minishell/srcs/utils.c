/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:40:22 by dferreir          #+#    #+#             */
/*   Updated: 2023/03/05 13:45:58 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	print_err(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

char	**get_path(char **envp)
{
	int		i;
	char	*env;
	char	**res;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5)) //chercher "PATH=" dans la cmd env
		{
			env = ft_substr(envp[i], 6, ft_strlen(envp[i])); //mettre reste dans var
			if (!env)
				return (0);
			res = ft_split(env, ':'); //separer par ':'
			free (env);
			if (!res)
				return (0);
			return (res);
		}
		i++;
	}
	return (0);
}

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	if (access(cmd, 0) == 0) //si arg en lui meme est deja path entiere
		return(cmd);
	while (*paths) //sinon, joindre path a arg et tester si correct
	{
		tmp = ft_strjoin(*paths, "/"); //rajouter '/' a fin de path
		command = ft_strjoin(tmp, cmd); //rajouter arg a fin de path
		free(tmp);
		if (access(command, 0) == 0) //controler si cmd exite (0 = true)
			return (command);
		free(command);
		paths++; //recommencer avec nouvelle path
	}
//	write(2, cmd, ft_strlen(cmd));
//	print_err(" doesn't exits");
	return (0);
}

int	word_counter2(const char *s)
{
	int	nb_words;
	int	swtch;

	nb_words = 0;
	swtch = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\t' && swtch == 0)
		{
			nb_words++;
			swtch = 1;
		}
		if ((*s == '\t' || *s == ' ') && swtch == 1)
			swtch = 0;
		s++;
	}
	return (nb_words);
}

char	*str_maker2(const char *s, int start, int end)
{
	char	*new_s;
	size_t	i;

	i = 0;
	new_s = malloc((end - start + 1) * sizeof(char));
	while (start < end)
		new_s[i++] = s[start++];
	new_s[i] = 0;
	return (new_s);
}

int	str_to_args(t_minishell *ms)
{
	char	**new_strs;
	size_t	i;
	size_t	j;
	int		start;

	i = 0;
	j = 0;
	start = -42;
	new_strs = malloc((word_counter2(ms->prompt) + 1) * sizeof(char *));
	if (!ms->prompt || !new_strs || ft_strlen(ms->prompt) == 1)
		return (0);
	while (i <= ft_strlen(ms->prompt))
	{
		if (ms->prompt[i] != ' ' && ms->prompt[i] != '\t' && ms->prompt[i] != '\n' && start < 0)
			start = i;
		else if ((ms->prompt[i] == ' ' || ms->prompt[i] == '\t' || ms->prompt[i] == '\n' || !ms->prompt[i]) && start >= 0)
		{
			new_strs[j++] = str_maker2(ms->prompt, start, i);
			start = -42;
		}
		i++;
	}
	new_strs[j] = 0;
	ms->args = new_strs;
	return (1);
}
