/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_to_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:46:02 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/05 12:03:14 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_word(char *str)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && str[i] != ' ')
			n++;
		while (str[i] && str[i] != ' ')
		{
			if (str[i] && (str[i] == '\'' || str[i] == '\"'))
				i += skip_quote(str, i);
			if (!str[i] || str[i] == ' ')
				break ;
			i++;
		}
	}
	return (n);
}

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*ret;

	i = 0;
	ret = malloc(n + 1);
	while (*str && n)
	{
		ret[i] = *str;
		str++;
		i++;
		--n;
	}
	ret[i] = 0;
	return (ret);
}

char	*makestr(char *str, int *k)
{
	int		i;
	char	*tmp;

	tmp = str;
	i = 0;
	while (str[i] && str[i] != ' ')
	{
		if (str[i] && (str[i] == '\'' || str[i] == '\"'))
			i += skip_quote(str, i);
		if (!str[i] || str[i] == ' ')
			break ;
		i++;
	}
	*k = i;
	return (ft_strndup(tmp, i));
}

char	**fill_word(char *s, int n, char **str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < n)
	{
		while (*s && *s == ' ')
			s++;
		str[i] = makestr(s, &k);
		s = s + k;
		i++;
	}
	str[i] = 0;
	return (str);
}

void	split_to_list(t_d *d, int i, int n)
{
	t_token	*new_tkn;
	char	**str;

	if (!d->buf)
		return ;
	n = count_word(d->buf);
	if (n == 0)
		return ;
	str = (char **)malloc(sizeof(char *) * (n + 1));
	if (!str)
		return ;
	str = fill_word(d->buf, n, str);
	d->tkn = NULL;
	while (str[i])
	{
		new_tkn = lst_new(ft_strndup(str[i], ft_strlen(str[i])), UNKNOW);
		lst_addback(&d->tkn, new_tkn);
		i++;
	}
	free_2d(str);
}
