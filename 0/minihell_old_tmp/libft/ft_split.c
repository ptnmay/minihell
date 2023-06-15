/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:46:02 by csantivi          #+#    #+#             */
/*   Updated: 2022/03/02 23:13:33 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *s, char c)
{
	int	n;

	n = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
			n++;
		while (*s != c && *s)
			s++;
	}
	return (n);
}

char	*putstr(char const *s, char c)
{
	int		i;
	char	*txt;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	txt = (char *)malloc(sizeof(char) * (i + 1));
	if (!txt)
		return (NULL);
	ft_strlcpy(txt, s, i + 1);
	return (txt);
}

char	**ft_split2(char const *s, char c, int n, char **str)
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

char	**ft_split(char const *s, char c)
{
	int		n;
	char	**str;

	if (!s)
		return (NULL);
	n = count(s, c);
	str = (char **)malloc(sizeof(char *) * (n + 1));
	if (!str)
		return (NULL);
	return (ft_split2(s, c, n, str));
}
