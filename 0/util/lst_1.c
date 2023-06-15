/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:01:20 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/05 21:03:14 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*lst_new(char *str, enum e_token type)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->str = str;
	new->type = type;
	new->token = NULL;
	new->next = NULL;
	return (new);
}

t_token	*lst_last(t_token *tkn)
{
	if (!tkn)
		return (NULL);
	while (tkn->next)
		tkn = tkn->next;
	return (tkn);
}

void	lst_addfront(t_token **tkn, t_token *new)
{
	if (!tkn || !new)
		return ;
	new->next = *tkn;
	*tkn = new;
}

void	lst_addback(t_token **tkn, t_token *new)
{
	t_token	*last;

	if (!tkn || !new)
		return ;
	if (*tkn)
	{
		last = lst_last(*tkn);
		last->next = new;
	}
	else
		*tkn = new;
}

int	lst_size(t_token *tkn)
{
	int	i;

	i = 0;
	while (tkn)
	{
		tkn = tkn->next;
		i++;
	}
	return (i);
}
