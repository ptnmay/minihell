/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:30:08 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/09 03:58:31 by psaeyang         ###   ########.fr       */
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

	i = 0;
	cmd = d->tkn;
	size = lst_size(cmd);
	
	//init infd, outfd
	// d->tkn->exe.infd = 0;
	// d->tkn->exe.outfd = 1;
	
	// while(cmd && i < size)
	// {
	// 	pipe(cmd->exe.pfd);
	// 	cmd->exe.pid = fork();
	// 	if (cmd->exe.pid == 0) //child process
	// 	{
	// 		close(cmd->exe.pfd[0]);
	// 		if (i == 0)
	// 		{
	// 			dup2(cmd->exe.pfd[1], STDOUT_FILENO);
				
	// 		}
	// 		printf("----child----\n");
	// 		exit(0);
	// 	}
	// 	else
	// 	{
	// 		printf("-----parent------\n");
	// 		exit(0);
	// 	}
	// 	cmd = cmd->next;
	// 	i++;
	// }
	
	printf("It's %d command, Good luck\n", size);

	while (cmd)
	{
		if (i < size)
		{
			pipe(cmd->exe.pfd);
			cmd->exe.pid = fork();
			if (cmd->exe.pid == 0)
			{
				printf("child process\n");
				if (i == 0) //first child
				{
					//first child
					if (check_type(cmd->token[i]) == REIN)
					{
						cmd->exe.infd = open(cmd->token[i], O_RDONLY);
					}
					dup2(cmd->exe.infd, STDIN_FILENO);
					dup2(cmd->exe.pfd[1], STDOUT_FILENO);
					close(cmd->exe.infd);
					
				}
				else if (i > 0 && i < size) //middle process
				{
					
				}
				
			}
			else
			{
				printf("parent process\n");
			}
		}
		


		//9 did
		if (check_builtin(cmd->token[0]))
		{
			printf(KBLU"Builtin func.\n"NONE);
			do_builtin(cmd->token, d);
		}
		else if (cmd->type == CMD)
		{
			execute_from_path(cmd, d);
		}
		cmd = cmd->next;
		i++;
	}
}










//9 did
// #include "minishell.h"

// void	execute_from_path(t_token *cmd, t_d *d)
// {
// 	int		pid;
// 	char	**path;
// 	int		i;
// 	int		status;

// 	if (!cmd)
// 		return ;
// 	path = ft_split(ft_getenv(d->env, "PATH"), ':');
// 	pid = fork();
// 	i = -1;
// 	if (pid == 0)
// 	{
// 		if (is_inside('/', cmd->token[0]))
// 			execve(cmd->token[0], cmd->token, d->envp);
// 		while (path && path[++i])
// 		{
// 			path[i] = ft_strjoin(path[i], "/");
// 			path[i] = ft_strjoin(path[i], cmd->token[0]);
// 			if (!access(path[i], F_OK))
// 				execve(path[i], cmd->token, d->envp);
// 		}
// 		printf("bash : %s: command not found\n", cmd->token[0]);
// 		exit(127);
// 	}
// 	waitpid(pid, &status, 0);
// 	d->exit_status = WEXITSTATUS(status);
// 	free_2d(path);
// }

// void	main_execute(t_d *d)
// {
// 	t_token	*cmd;
// 	int		size;

// 	cmd = d->tkn;
// 	size = lst_size(cmd);
// 	while (cmd)
// 	{
// 		if (check_builtin(cmd->token[0]))
// 		{
// 			printf(KBLU"Builtin func.\n"NONE);
// 			do_builtin(cmd->token, d);
// 		}
// 		else if (cmd->type == CMD)
// 		{
// 			execute_from_path(cmd, d);
// 		}
// 		cmd = cmd->next;
// 	}
// }
