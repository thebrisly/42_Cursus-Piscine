/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:01:16 by dferreir          #+#    #+#             */
/*   Updated: 2023/02/28 14:54:05 by dferreir         ###   ########.fr       */
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
	int		env_len;
	int		*size_args;
	char	*prompt;
	char	*cmd;
    char    *str_var;
    char    *key;
    char    *value;
	char	**args;
	char	**env;
	char	**paths;
	char    **env_variables;
}	t_minishell;

//functions

int	print_err(char *msg);

char	**get_path(char **envp);

char	*get_cmd(char **paths, char *cmd);

int		str_to_args(t_minishell *ms);

void	mini_env(t_minishell ms);

int		env_count(t_minishell ms);

void	add_var_env(t_minishell ms);

void	mini_echo(t_minishell ms);

void	mini_pwd(t_minishell ms);

void	mini_exit(t_minishell *ms);

int		is_builtin(t_minishell ms);

#endif
