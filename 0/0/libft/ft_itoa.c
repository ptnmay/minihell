/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:40:12 by csantivi          #+#    #+#             */
/*   Updated: 2022/03/13 22:04:20 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(long int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(long int nbr)
{
	int		c;
	int		neg;
	char	*str;

	c = count(nbr);
	neg = 1;
	if (nbr != 0)
		str = (char *)malloc(sizeof(char) * (c + 1));
	else
		return (str = ft_strdup("0"));
	if (!str)
		return (NULL);
	str[c--] = 0;
	if (nbr < 0)
	{
		neg *= -1;
		str[0] = '-';
	}
	while (c >= 0 && str[c] != '-')
	{
		str[c--] = '0' + (neg * (nbr % 10));
		nbr /= 10;
	}
	return (str);
}
