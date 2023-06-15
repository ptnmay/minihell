/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:28:25 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/05 01:23:56 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*clear_quote_expand(char *str, t_d *d)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_calloc(1, sizeof(char));
	while (str[i])
	{
		if (str[i] == '\'')
			i += fill_squote(&new, str, i);
		else if (str[i] == '\"')
			i += fill_dquote(&new, str, i, d);
		else
			i += fill_string(&new, str, i, d);
	}
	return (new);
}

void	parser(t_d *d)
{
	t_token	*ptr;
	char	*new;
	char	*tmp;

	ptr = d->tkn;
	while (ptr)
	{
		new = clear_quote_expand(ptr->str, d);
		tmp = ptr->str;
		ptr->str = new;
		free(tmp);
		ptr = ptr->next;
	}
}
