/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:46:38 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/08 22:09:59 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_d *d)
{
	char	*current_path;
	char	*ret;

	current_path = malloc(sizeof(char) * 128);
	ret = getcwd(current_path, 128);
	if (ret)
		printf("%s\n", current_path);
	free(current_path);
	d->exit_status = 0;
}

void	ft_echo(char **args, t_d *d)
{
	int	i;
	int	n;
	int	size;

	i = 0;
	n = 0;
	size = args_count(args);
	i++;
	if (size != 1 && ft_strcmp(args[i], "-n") == 0)
	{
		n++;
		i++;
	}
	while (args[i])
	{
		printf("%s", args[i]);
		i++;
		if (args[i])
			printf(" ");
		else if (!args[i] && !n)
			printf("\n");
	}
	d->exit_status = 0;
}

int	check_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	add_new_env(char **var, t_d *d)
{
	t_env	*env;
	t_list	*list;
	char	*value_from_env;

	value_from_env = ft_getenv(d->env, var[0]);
	if (value_from_env)
	{
		list = d->env;
		while (list)
		{
			env = list->content;
			if (!ft_strncmp(env->key, var[0], ft_strlen(var[0])))
			{
				free(env->value);
				env->value = ft_strdup(var[1]);
			}
			list = list->next;
		}		
	}
	else
		create_new_env(ft_strdup(var[0]), ft_strdup(var[1]), d);
	free_2d(var);
}

void	ft_export(char **args, t_d *d)
{
	char	**var;
	int		size;
	int		i;

	size = args_count(args);
	i = 0;
	if (size == 1)
		ft_lstiter(d->env, print_env);
	while (++i != size)
	{
		var = ft_split(args[i], '=');
		if (check_valid(var[0]) && !ft_isdigit(var[0][0]))
		{
			if (!var[1])
				break ;
			add_new_env(var, d);
		}
		else
		{
			printf("bash: %s: `%s': not a valid identifier\n", args[0], var[0]);
			d->exit_status = 1;
			return ;
		}
	}
	d->exit_status = 0;
}
