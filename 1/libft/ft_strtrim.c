/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:11:55 by csantivi          #+#    #+#             */
/*   Updated: 2022/02/23 21:40:57 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isinset(char const c, char const *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*txt;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(""));
	i = 0;
	while (isinset(s1[i], set))
		i++;
	j = ft_strlen(s1);
	while (j > i && isinset(s1[j - 1], set))
		j--;
	txt = ft_substr(s1, i, j - i);
	return (txt);
}
