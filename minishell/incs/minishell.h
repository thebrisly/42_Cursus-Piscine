/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:01:16 by dferreir          #+#    #+#             */
/*   Updated: 2023/04/03 13:57:55 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/syslimits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/incs/libft.h"

//STRUCTS

int	g_cat;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*previous;
}	t_env;

typedef struct s_minishell
{
	int		x;
	int		i;
	int		j;
	int		cat;
	int		cat_nb;
	int		f_touched;
	int		inf;
	int		outf;
	int		appf;
	int		in_out_acc;
	int		dev_null;
	int		ter_in;
	int		ter_out;
	int		input;
	int		output;
	int		out;
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

void	minishell(t_minishell *ms);

void	expander(t_minishell *ms, int i);

char	*cutter(t_minishell *ms, char *str, int i);

int		print_err(char *msg);

int		ft_strcmp(const char *s1, const char *s2);

char	**ft_split2(t_minishell *ms, char const *s, char c);

void	check_dir_file(t_minishell *ms);

int		inside_cat(t_minishell *ms);

/* builtin-cmds */
int		is_builtin(t_minishell *ms);

void	exec_builtin(t_minishell *ms);

void	mini_echo(t_minishell *ms);

void	mini_pwd(t_minishell *ms);

void	mini_exit(t_minishell *ms);

void	mini_export(t_minishell *ms);

void	mini_env(t_minishell *ms);

void	mini_unset(t_minishell *ms);

void	mini_cd(t_minishell *ms);

/* parsing */
char	**get_path(t_minishell *ms);

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

void	free_env(t_minishell *ms);

/* export */

void	print_export(t_minishell *ms);

void	sort_export(t_minishell *ms);

void	sort_utils(t_minishell *ms, t_env *current, t_env *temp, t_env *next);

char	*get_value(t_minishell *ms, char *str);

void	duplicate(t_minishell	*ms);

void	free_export(t_minishell *ms);

t_env	*replace_value(t_minishell *ms, char *str);

/* cd */

char	*change_directory(t_minishell *ms, char *dir, char *tmp, char *arg);

char	*change_tilde(t_minishell *ms, char *dir, char *tmp, char *arg);

char	*go_home(t_minishell *ms);

void	new_dir(t_minishell *ms, char *directory, char *argument);

void	set_dir(t_minishell *ms);

/* signals */
void	signal_init(void);

void	signal_handler(int signum);

/* hredoc */
int		heredoc_input(t_minishell *ms);

void	print_heredoc(char *str, int file);

/* init */
void	init_vars(t_minishell *ms, int i, char **env);

void	init_vars_inloop(t_minishell *ms, int i);

int		init_heredoc(t_minishell *ms);

int		init_cat(t_minishell *ms);

void	init_prompt(t_minishell *ms, char **envp);

/* norm */
void	phase_enter(t_minishell *ms);

void	minishell_end(t_minishell *ms);

void	minishell_loop1(t_minishell *ms);

char	*cutter_start(char **tmp_array, char *tmp, char *tmp2, int i);

char	*cutter_middle(t_minishell *ms, char *tmp, char *tmp2);

char	*cutter_end(t_minishell *ms, char *tmp, char *tmp2);

void	expander_start(t_minishell *ms, char *res, char *tmp);

void	expander_end(t_minishell *ms, char *res, int i);

#endif
