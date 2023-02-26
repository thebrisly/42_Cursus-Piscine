/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:01:16 by dferreir          #+#    #+#             */
/*   Updated: 2023/02/26 14:15:22 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <fcntl.h>
# include "../libft/incs/libft.h"

//structs

typedef struct s_minishell
{
	int		pid;
	char	*cmd;
	char	**env;
	char	**paths;
}	t_minishell;

//functions

int	print_err(char *msg);

char	**get_path(char **envp);

char	*get_cmd(char **paths, char *cmd);

void	mini_env(char **envp);

void	mini_echo(char **args);

void	mini_pwd(t_minishell *ms);

int		is_builtin(t_minishell ms, char **args);

#endif
