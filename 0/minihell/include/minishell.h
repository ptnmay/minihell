/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:15:02 by csantivi          #+#    #+#             */
/*   Updated: 2023/05/27 12:26:29 by csantivi         ###   ########.fr       */
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

extern char	**environ;

typedef enum
{
	UNTITLE,
	WORD,
	PIPE,
	REDI,
	SQOUTE,
	DQOUTE,
	BUILTIN
}		tokentype;

typedef struct s_dict
{
	char	*key;
	char	*value;	
}	t_dict;

typedef struct s_token
{
	char		*token;
	tokentype	type;
}	t_token;

/* LEXER */
char	**lexer(char *input);
char	**smart_split(char const *s, char c);

/* EXECUTE */
void	execute_from_path(char **args);

/* UNTIL */
void	free_2d(char **input);
void	show_2d(char **input);

#endif