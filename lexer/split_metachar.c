/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_metachar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:39:54 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/05 22:29:00 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_meta(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

int	case_cut_list(t_token **h, t_token *p, int i, int pos)
{
	int				size;
	int				redi;
	t_token			*last;

	size = ft_strlen(p->str);
	if (i != 0)
		redi = i;
	else
	{
		if (p->str[0] == p->str[1])
			redi = 2;
		else
			redi = 1;
	}
	lst_insert(h, lst_new(ft_substr(p->str, 0, redi), UNKNOW), pos);
	last = lst_new(ft_substr(p->str, redi, size - redi), UNKNOW);
	lst_insert(h, last, pos + 1);
	last->next = p->next;
	lst_delone(p);
	return (0);
}

void	define_type(t_token *ptr)
{
	t_token	*tmp;

	tmp = ptr;
	while (tmp)
	{
		tmp->type = check_type(tmp->str);
		tmp = tmp->next;
	}
}

void	split_metachar(t_d *d, int pos, int size, int i)
{
	t_token	*ptr;

	ptr = d->tkn;
	while (ptr)
	{
		i = 0;
		size = ft_strlen(ptr->str);
		while (ptr->str[i])
		{
			if (ptr->str[i] == '\'' || ptr->str[i] == '\"')
				i += skip_quote(ptr->str, i);
			else if (is_meta(ptr->str[i]) && !(size == 1
					|| ((size == 2) && ptr->str[0] == ptr->str[1])))
			{
				pos = case_cut_list(&d->tkn, ptr, i, pos);
				ptr = d->tkn;
				break ;
			}
			else
				i++;
		}
		ptr = ptr->next;
		pos++;
	}
	define_type(d->tkn);
}
