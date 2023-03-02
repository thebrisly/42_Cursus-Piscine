/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:01:16 by dferreir          #+#    #+#             */
/*   Updated: 2023/03/01 15:30:19 by lfabbian         ###   ########.fr       */
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

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*previous;
}	t_env;

typedef struct s_minishell
{
	int		pid;
	int		env_len;
	int		*size_args;
	char	*prompt;
	char	*cmd;
    char    *str_var;
	char	**args;
	char	**env;
	char	**paths;
	t_env	*env_dup;
}	t_minishell;

//functions

int	print_err(char *msg);

char	**get_path(char **envp);

char	*get_cmd(char **paths, char *cmd);

int		str_to_args(t_minishell *ms);


/* env */
void	add_env_var(t_minishell *ms, char *key, char *value);
void	env_init(t_minishell *ms);
void	mini_env(t_minishell *ms);
t_env	*env_new(char *key, char *value);
t_env	*env_last(t_env	*lst);
void	env_add_end(t_env **lst, t_env *new);
int		env_size(t_env *lst);

void	add_var_env(t_minishell *ms);

void	mini_echo(t_minishell *ms);

void	mini_pwd(t_minishell *ms);

void	mini_exit(t_minishell *ms);

int		is_builtin(t_minishell *ms);

#endif
