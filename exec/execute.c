/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:30:08 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/11 05:26:40 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

 void	execute_from_path(t_token *cmd, t_d *d)
{
	int		pid;
	char	**path;
	int		i;
	int		status;

	if (!cmd)
		return ;
	path = ft_split(ft_getenv(d->env, "PATH"), ':');
	pid = fork();
	i = -1;
	if (pid == 0)
	{
		// if (is_inside('/', cmd->token[0]))
		// 	execve(cmd->token[0], cmd->token, d->envp);
		if (access(cmd->token[0], X_OK | F_OK) == 0)
			execve(cmd->token[0], cmd->token, d->envp);
		while (path && path[++i])
		{
			path[i] = ft_strjoin(path[i], "/");
			path[i] = ft_strjoin(path[i], cmd->token[0]);
			execve(path[i], cmd->token, d->envp);
		}
		printf("bash : %s: command not found\n", cmd->token[0]);
		exit(127);
	}
	waitpid(pid, &status, 0);
	d->exit_status = WEXITSTATUS(status);
	free_2d(path);
}

void	main_execute(t_d *d)
{
	t_token	*cmd;
	int		size;
	int		i;
	// int		fd[2];

	i = 0;
	cmd = d->tkn;
	size = lst_size(cmd);
	
	printf("It's %d command, Good luck\n", size);
	cmd->exe.infd = 0;
	cmd->exe.outfd = 1;

	// int	status;
	while (cmd)
	{
		if (i < size)
		{
			if (pipe(cmd->exe.pfd) == -1)
			{
				perror("Error from pipe");
				exit(EXIT_FAILURE);
			}
		}
		cmd->exe.pid = fork();
		if (cmd->exe.pid == -1)
		{
				perror("Error from fork");
				exit(EXIT_FAILURE);
		}
		else if (cmd->exe.pid == 0) //child process
		{
			kids_process(cmd, d, i, size);
		}
		parent_process(cmd);
		cmd = cmd->next;
		i++;
	}
}