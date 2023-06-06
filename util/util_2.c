/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:29:49 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/05 22:03:22 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_builtin(char *str)
{
	if (!ft_strcmp("echo", str) || !ft_strcmp("cd", str)
		|| !ft_strcmp("pwd", str) || !ft_strcmp("export", str)
		|| !ft_strcmp("unset", str) || !ft_strcmp("env", str)
		|| !ft_strcmp("exit", str))
		return (1);
	return (0);
}
