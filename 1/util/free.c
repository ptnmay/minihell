/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:23:11 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/07 20:10:59 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_2d(char **input)
{
	int	i;

	i = 0;
	if (!input || !*input)
		return ;
	while (input[i])
		free(input[i++]);
	free(input);
}

void	free_env(void *content)
{
	t_env	*env;

	env = (t_env *) content;
	free(env->key);
	free(env->value);
	free(env);
}

void	free_for_all(t_d *d)
{
	lst_clear(&d->tkn);
	ft_lstclear(&d->env, free_env);
	rl_clear_history();
	free(d->buf);
}
