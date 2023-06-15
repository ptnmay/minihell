/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 01:17:09 by csantivi          #+#    #+#             */
/*   Updated: 2022/03/02 23:38:44 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*txt;

	if (nitems == 0 || size == 0)
	{
		nitems = 1;
		size = 1;
	}
	txt = malloc(nitems * size);
	if (!txt)
		return (NULL);
	ft_bzero(txt, nitems * size);
	return (txt);
}
