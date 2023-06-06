/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 00:39:45 by csantivi          #+#    #+#             */
/*   Updated: 2022/03/02 00:57:51 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*st;

	if (!del)
		return ;
	else
	{
		while (lst && *lst)
		{
			st = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = st;
		}
	}
}
