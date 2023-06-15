/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:10:04 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/07 23:18:57 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_d *d)
{
	ft_lstiter(d->env, print_env);
	d->exit_status = 0;
}

void	ft_unset(char **args, t_d *d)
{
	t_list	*tmp;
	t_env	*env;
	int		i;

	i = 0;
	tmp = d->env;
	while (args[++i])
	{
		if (!check_valid(args[i]) || ft_isdigit(args[i][0]))
		{
			printf("bash: %s: `%s': not a valid identifier\n", args[0], args[1]);
			d->exit_status = 1;
			return ;
		}
		while (tmp)
		{
			env = tmp->content;
			if (!ft_strcmp(env->key, args[i])
				&& ft_strlen(env->key) == ft_strlen(args[i]))
				break ;
			tmp = tmp->next;
		}
		lst_delmid(d->env, tmp);
	}
	d->exit_status = 0;
}

void	is_good_digit(char **args, t_d *d)
{
	int	i;

	i = 0;
	if (args[1][i] == '-')
		i++;
	while (args[1][i])
	{
		if (!ft_isdigit(args[1][i]))
		{
			printf("bash: %s: %s: ", args[0], args[1]);
			printf("numeric argument required\n");
			free_for_all(d);
			exit(255);
		}
		i++;
	}
}

void	ft_exit(char **args, t_d *d)
{
	int				size;
	unsigned int	ret;
	int				i;

	i = 0;
	size = args_count(args);
	if (size > 1)
	{
		is_good_digit(args, d);
		if (size > 2)
		{
			printf("bash: %s: too many arguments\n", args[0]);
			d->exit_status = 1;
			return ;
		}
		ret = (unsigned int)ft_atoi(args[1]);
	}
	else
		ret = 0;
	free_for_all(d);
	printf("exit\n");
	exit((int)ret);
}

void	ft_cd(char **args, t_d *d)
{
	int	size;

	size = args_count(args);
	if (size == 1)
		chdir(ft_getenv(d->env, "HOME"));
	else if (size >= 2)
	{
		if (chdir(args[1]))
		{
			printf("bash: %s: %s: ", args[0], args[1]);
			printf("No such file or directory\n");
			d->exit_status = 1;
			return ;
		}
	}
	d->exit_status = 0;
}
