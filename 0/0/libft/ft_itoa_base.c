/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:55:38 by csantivi          #+#    #+#             */
/*   Updated: 2022/03/13 13:46:06 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	count(unsigned long long int n, int base)
{
	int	i;

	i = 0;
	while (n >= (unsigned long long int)base)
	{
		n = n / base;
		i++;
	}
	return (i);
}

static long long int	ft_convert_base(unsigned long long int n)
{
	if (n >= 10)
		return (n - 10 + 'a');
	else
		return (n + '0');
}

char	*ft_itoa_base(unsigned long long int value, int base)
{
	char				*str;
	long long int		size;

	size = count(value, base);
	if (base < 2 || base > 36)
		return (0);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size + 1] = '\0';
	while (size >= 0)
	{
		str[size] = ft_convert_base(value % base);
		value /= base;
		size--;
	}
	return (str);
}
