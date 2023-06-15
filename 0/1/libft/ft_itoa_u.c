/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:36:46 by csantivi          #+#    #+#             */
/*   Updated: 2022/03/11 12:23:13 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_u(unsigned int n)
{
	int		c;
	char	*str;

	c = count(n);
	str = (char *)malloc(sizeof(char) * (c + 1));
	if (!str)
		return (NULL);
	str[c] = 0;
	c--;
	while (c >= 0)
	{
		str[c] = '0' + (n % 10);
		n /= 10;
		c--;
	}
	return (str);
}
