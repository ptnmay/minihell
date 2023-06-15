/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:00:45 by csantivi          #+#    #+#             */
/*   Updated: 2022/02/23 11:07:45 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*txt;
	int		i;
	int		j;

	txt = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!txt)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		txt[j++] = s1[i++];
	i = 0;
	while (s2[i])
		txt[j++] = s2[i++];
	txt[j] = 0;
	return (txt);
}
