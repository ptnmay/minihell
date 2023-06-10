/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kids_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 01:55:27 by psaeyang          #+#    #+#             */
/*   Updated: 2023/06/11 06:11:23 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	first_kid(t_token *cmd)
{
	printf("----in first kids----\n");
	dup2(cmd->exe.pfd[1], STDIN_FILENO);
	// close(cmd->exe.pfd[0]);
	// close(cmd->exe.pfd[1]);
}

// void	middle_kids(t_token *cmd)
// {
// }

void	last_kid(t_token *cmd)
{
	printf(KBLU"----last process----%s\n", NONE);
	// dup2(cmd->exe.pfd[0], STDOUT_FILENO);
	dup2(cmd->exe.tmp_fd, STDOUT_FILENO);
	close(cmd->exe.pfd[0]);
	close(cmd->exe.pfd[1]);
}

void	dupdup(t_token *cmd, int i, int size)
{
	printf(KYEL"------in dupdup--------%s\n", NONE);
	if (i == 0)
		first_kid(cmd);
	else if (i < size && i != 0)
		// middle_kids(cmd);
	{	
		printf(KBLU"----middle process----%s\n", NONE);

		dup2(cmd->exe.tmp_fd, STDIN_FILENO);
		dup2(cmd->exe.pfd[1], STDOUT_FILENO);
		close(cmd->exe.tmp_fd);
		close(cmd->exe.pfd[1]);
	}
	else if (i == size)
		last_kid(cmd);
}

void	kids_process(t_token *cmd, t_d *d, int i, int size)
{
	int	cnt;
	char **path;
	
	cnt = -1;
	printf(KBLU"----in kids process----%s\n", NONE);
	close(cmd->exe.pfd[0]);
	dupdup(cmd, i, size);
	close(cmd->exe.pfd[1]);

	printf("-----go get path----\n");
	
	path = ft_split(ft_getenv(d->env, "PATH"), ':');
	if (access(cmd->token[0], X_OK | F_OK) == 0)
		execve(cmd->token[0], cmd->token, d->envp);
	while (path && path[++cnt])
	{
		path[cnt] = ft_strjoin(path[cnt], "/");
		path[cnt] = ft_strjoin(path[cnt], cmd->token[0]);
		execve(path[cnt], cmd->token, d->envp);
	}
}