/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:46:02 by csantivi          #+#    #+#             */
/*   Updated: 2023/05/27 12:29:32 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count(char const *s, char c)
{
	int	n;
	int	q;

	n = 0;
	q = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
			n++;
		if (*s == 34 || *s == 39)
		{
			q = *s;
			s++;
			while (*s != q && *s)
				s++;
			if (!*s)
				return (0);
		}
		while (*s != c && *s)
			s++;
	}
	return (n);
}

static char	*putstr(char const *s, char c)
{
	int		i;
	int		q;
	char	*txt;

	i = 0;
	q = 0;
	if ((s[i] == 34 || s[i] == 39) && s[i])
	{
		q = s[i];
		i++;
		while (s[i] != q)
			i++;
	}
	while (s[i] != c && s[i])
		i++;
	txt = (char *)malloc(sizeof(char) * (i + 1));
	if (!txt)
		return (NULL);
	ft_strlcpy(txt, s, i + 1);
	return (txt);
}

static char	**ft_split2(char const *s, char c, int n, char **str)
{
	int	i;

	i = 0;
	while (i < n)
	{
		while (*s == c)
			s++;
		str[i] = putstr(s, c);
		if (!str[i])
		{
			while (i)
				free(str[i--]);
			free(str);
			return (NULL);
		}
		s = s + ft_strlen(str[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**smart_split(char const *s, char c)
{
	int		n;
	char	**str;

	if (!s)
		return (NULL);
	n = count(s, c);
	if (n == 0)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (n + 1));
	if (!str)
		return (NULL);
	return (ft_split2(s, c, n, str));
}
