/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:46:02 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/03 00:58:06 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**smart_split(char *s)
{
	int		n;
	char	**str;

	if (!s)
		return (NULL);
	n = count_word(s);
	if (n == 0)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (n + 1));
	if (!str)
		return (NULL);
	return (fill_word(s, n, str));
}
