/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 02:18:23 by csantivi          #+#    #+#             */
/*   Updated: 2022/02/21 22:00:03 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	if (start > size)
		return (ft_strdup(""));
	if (len > (size - start))
		len = size - start;
	c = malloc((sizeof(char) * (len + 1)));
	if (!c)
		return (NULL);
	while (i < len)
	{
		c[i] = *(s + start + i);
		i++;
	}
	c[i] = '\0';
	return (c);
}
