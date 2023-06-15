/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 01:45:28 by csantivi          #+#    #+#             */
/*   Updated: 2022/02/20 02:06:12 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*c;

	c = (char *)malloc(ft_strlen(s1) + 1);
	ft_memcpy(c, s1, ft_strlen(s1));
	c[ft_strlen(s1)] = 0;
	return (c);
}
