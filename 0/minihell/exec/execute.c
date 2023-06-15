/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:30:08 by csantivi          #+#    #+#             */
/*   Updated: 2023/05/27 12:17:17 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_from_path(char **args)
{
	int		pid;
	int		i;
	char	**path;

	if (!args)
		return ;
	path = ft_split(getenv("PATH"), ':');
	pid = fork();
	i = 0;
	if (pid == 0)
	{
		execve(args[0], args, environ);
		while (path[i])
		{
			path[i] = ft_strjoin(path[i], "/");
			path[i] = ft_strjoin(path[i], args[0]);
			execve(path[i], args, environ);
			i++;
		}
		printf("bash : %s: comand not found\n", args[0]);
		exit(127);
	}
	else
		waitpid(pid, NULL, 0);
	free_2d(path);
}
