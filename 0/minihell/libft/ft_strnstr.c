/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:28:43 by csantivi          #+#    #+#             */
/*   Updated: 2022/03/02 23:21:54 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	if (!s2 || !(*s2))
		return (str1);
	while (str1[i] && i < n)
	{
		j = 0;
		while (i + j < n && str1[i + j] == str2[j] && str1[i + j] && str2[j])
				j++;
		if (!str2[j])
			return (str1 + i);
		i++;
	}
	return (0);
}
