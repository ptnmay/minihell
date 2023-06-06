/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:23:11 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/04 17:39:52 by csantivi         ###   ########.fr       */
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
