/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 23:35:51 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/07 23:35:00 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(t_list *my_env, char *str)
{
	t_env	*env;

	while (my_env)
	{
		env = my_env->content;
		if (!ft_strcmp(env->key, str)
			&& ft_strlen(env->key) == ft_strlen(str))
			return (env->value);
		my_env = my_env->next;
	}
	return (NULL);
}

void	print_env(void *content)
{
	t_env	*env;

	env = (t_env *)content;
	printf("%s=%s\n", env->key, env->value);
}

void	create_new_env(char *key, char *value, t_d *d)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	env->key = key;
	env->value = value;
	ft_lstadd_back(&d->env, ft_lstnew((void *) env));
}

void	init_env(t_d *d, char **envp)
{
	char	**key_n_value;
	int		i;

	i = 0;
	d->envp = envp;
	d->env = NULL;
	d->exit_status = 0;
	while (envp[i])
	{
		key_n_value = ft_split(envp[i], '=');
		create_new_env(key_n_value[0], key_n_value[1], d);
		free(key_n_value);
		i++;
	}
}
