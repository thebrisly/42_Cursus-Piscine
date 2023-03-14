/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:01:16 by dferreir          #+#    #+#             */
/*   Updated: 2023/03/14 11:37:54 by lfabbian         ###   ########.fr       */
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

//STRUCTS

char	*str;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*previous;
}	t_env;

typedef struct s_minishell
{
	int		err;
	int		err_prev;
	int		dol;
	int		or;
	int		pip;
	int		pid;
	int		start;
	int		end;
	int		pipe[2];
	int		*args_size;
	char	quote;
	char	*prompt;
	char	*cmd;
	char	*oldpwd;
	char	**args;
	char	**args_tmp;
	char	**env;
	char	**paths;
	t_env	*env_dup;
	t_env	*env_dup2;
	t_env	*export;
}	t_minishell;

//FUNCTIONS

int	print_err(char *msg);

int		ft_strcmp(const char *s1, const char *s2);

/* builtin-cmds */
int		is_builtin(t_minishell *ms);

void	mini_echo(t_minishell *ms);

void	mini_pwd(t_minishell *ms);

void	mini_exit(t_minishell *ms);

void    mini_export(t_minishell *ms);

void	mini_env(t_minishell *ms);

void	mini_unset(t_minishell *ms);

void	mini_cd(t_minishell *ms);

/* parsing */
char	**get_path(char **envp);

char	*get_cmd(char **paths, char *cmd);

int		str_to_array(t_minishell *ms);

/* env */
void	add_env_var(t_minishell *ms, char *key, char *value);

void	env_init(t_minishell *ms);

t_env	*env_new(char *key, char *value);

t_env	*env_last(t_env	*lst);

void	env_add_end(t_env **lst, t_env *new);

int		env_size(t_env *lst);

void	add_var_env(t_minishell *ms);

void    free_env(t_minishell *ms);


/* export */

void    print_export(t_minishell *ms);

void    sort_export(t_minishell *ms);

char	*get_value(t_minishell *ms, char *str);

void	duplicate(t_minishell	*ms);

void	free_export(t_minishell *ms);

t_env	*replace_value(t_minishell *ms, char *str);


/* signals */
void    signal_init(void);

void    signal_handler(int signum);

#endif
