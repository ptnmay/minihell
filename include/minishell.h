/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:15:02 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/07 04:58:27 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include <errno.h>
# include "../libft/libft.h"
# include <termios.h>
# include <curses.h>
# include <term.h>

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"
# define NONE  "\033[0m"

# define MAX_HISTORY 100

enum e_token
{
	CMD,
	PIPE,
	REIN,
	HDOC,
	REOUT,
	REAPP,
	UNKNOW
};

typedef struct s_exe
{
	pid_t	pid;
	int		pfd[2];
	int		infd;
	int		outfd;
}		t_exe;

typedef struct s_token
{
	char			**token;
	char			*str;
	t_exe			exe;
	enum e_token	type;
	struct s_token	*next;
}			t_token;

typedef struct s_env
{
	char	*key;
	char	*value;
}			t_env;

typedef struct s_d
{
	int		exit_status;
	char	*buf;
	char	**data;
	char	**envp;
	t_list	*env;
	t_token	*tkn;
}			t_d;

// LEXER

// lexer.c
void			lexer(t_d *d);
int				expand_var(char **new, char *s, int i, t_d *d);
int				varlen(char *s, int i);
int				check_special(char *str);
// smart_split.c
char			**smart_split(char *s);
// split_metachar.c
int				is_meta(char c);
int				case_cut_list(t_token **h, t_token *p, int i, int pos);
void			split_metachar(t_d *d, int pos, int size, int i);
// split_to_list.c
int				count_word(char *str);
char			*ft_strndup(char *str, int n);
char			*makestr(char *str, int *k);
char			**fill_word(char *s, int n, char **str);
void			split_to_list(t_d *d, int i, int n);
// parser.c
void			parser(t_d *d);
char			*clear_quote_expand(char *str, t_d *d);
// fill_in.c
int				fill_squote(char **new, char *s, int i);
int				fill_string(char **new, char *s, int i, t_d *d);
int				fill_dquote(char **new, char *s, int i, t_d *d);
int				fill_in_str(char **new, char *s, int i);
int				fill_in_dq(char **new, char *s, int i);
// join_cmd.c
void			join_cmd(t_d *d);

// EXECUTE
// execute.c
void			execute_from_path(t_token *cmd, t_d *d);
void			main_execute(t_d *d);

// UTIL
// free.c
void			free_2d(char **input);
void			free_env(void *content);
enum e_token	check_type(char *c);
void			show_2d(char **input);
// lst_1.c
t_token			*lst_new(char *str, enum e_token type);
t_token			*lst_last(t_token *tkn);
void			lst_addfront(t_token **tkn, t_token *new);
void			lst_addback(t_token **tkn, t_token *new);//
int				lst_size(t_token *tkn);
// lst_2.c
void			lst_delone(t_token *tkn);
void			lst_clear(t_token **tkn);
void			lst_iter(t_token *tkn, void (*f)(char *));
void			lst_insert(t_token **lst, t_token *new, int pos);
void			show_cmd(t_token *cmd);
// util_1.c
int				skip_quote(char *s, int i);
char			*ft_strjoin_premium(char *s1, char *s2, int option);
// util_2.c
int				check_builtin(char *str);

// SRC/ENV
// env.c
void			init_env(t_d *d, char **envp);
void			print_env(void *content);
void			print_tkn(char *str);
char			*ft_getenv(t_list *my_env, char *str);

#endif

/*
	(LV.1) linked-list : str -> str -> str
	
	for show: 	lst_iter(d->tkn, print_tkn);
	for free: 	lst_clear(&d.tkn);

	(LV.2) linked-list : cmd -> cmd -> cmd

	fot show:	show_cmd(head);
	for free:	lst_clear(&head);
*/

/*
	t_token	*tmp;
	
	printf("from split : ");	//  --|
	lst_iter(d->tkn, print_tkn); //   |
	printf("\n");				 // --|
	printf("type       : ");		// ----
	tmp = d->tkn;							//
	while (tmp)								//
	{										//
		printf(" %d ->", tmp->type);		//
		tmp = tmp->next;					//
	}										//
	printf("\n");					// ----

	printf("from join  : ");	 //  --|
	show_cmd(d->tkn); //   |
	printf("type       : ");		// ----
	tmp = d->tkn;							//
	while (tmp)								//
	{										//
		printf(" %d ->", tmp->type);		//
		tmp = tmp->next;					//
	}										//
	printf("\n\n");					// ----
*/