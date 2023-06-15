/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:47:14 by csantivi          #+#    #+#             */
/*   Updated: 2023/05/27 12:24:03 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	token_analyze(char *token)
{
	int	d;

	d = ft_strcmp(token, "test");
	printf("%s - test = %d\n", token, d);
}

void	create_llst_from2d(char **str)
{
	
	t_token	new;
	int		i;

	i = 0;
	while (str[i])
	{
		token_analyze(str[i]);
		// ft_lstnew((void *)new.token)
		i++;
	}
}

int	check_special(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\' || str[i] == ';')
			return (1);
		i++;
	}
	return (0);
}

char	**lexer(char *input)
{
	char	**data;
	t_list	head;

	if (check_special(input))
		return (NULL);
	data = smart_split(input, ' ');
	if (!data)
		return (NULL);
	// create_llst_from2d(data);
	// show_2d(data);
	return (data);
	// free_2d(data);
}
