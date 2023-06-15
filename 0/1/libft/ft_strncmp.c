/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:55:52 by csantivi          #+#    #+#             */
/*   Updated: 2022/03/05 00:58:07 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t				i;
	unsigned const char	*s1;
	unsigned const char	*s2;

	s1 = (unsigned const char *)str1;
	s2 = (unsigned const char *)str2;
	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || (s1[i] == 0 && s2[i] == 0))
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
