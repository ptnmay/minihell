/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 00:08:10 by psaeyang          #+#    #+#             */
/*   Updated: 2023/06/13 19:17:48 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipe(t_token *tmp)
{
	int	j;

	j = 1;
	while (j < tmp->fd.size)
	{
		close(tmp->fd.pipe[0]);
		close(tmp->fd.pipe[1]);
		j++;
	}
}

void	dupdup(t_token *tmp)
{
	if (tmp->fd.i == 0)
	{
		printf(KMAG"this is first cmd%s\n", NONE);
		dup2(tmp->fd.pipe[1], STDOUT_FILENO);
		close_pipe(tmp);
	}
	else if (tmp->fd.i == tmp->fd.size - 1)
	{
		printf(KMAG"this is last cmd%s\n", NONE);
		dup2(tmp->fd.pipe[0], STDIN_FILENO);
		close_pipe(tmp);
	}
	else
	{
		printf(KMAG"this is middle cmd%s\n", NONE);
		dup2(tmp->fd.pipe[0], STDIN_FILENO);
		dup2(tmp->fd.pipe[1], STDOUT_FILENO);
		close_pipe(tmp);
	}
}

//main exec
void	pipe_all(t_token *cmd, int i)
{
	// fd->pipe = malloc(sizeof(int *) * (fd->size - 1));
	// while (fd->i + 1 < fd->size)
	// {
	// 	pipe(fd->pipe[fd->i]);
	// 	fd->i++;
	// }
	// fd->i = 0;
	t_token	*tmp;
	
	tmp = cmd;
	while (i + 1 < tmp->fd.size)
	{
		printf("pipe here[%d]\n", i);
		pipe(tmp->fd.pipe);
		tmp = tmp->next;
		i++;
	}
}

void	fork_fork(t_d *d, t_token *cmd, int do_fork)
{
	while (cmd)
	{
		if (do_fork)
			fork_exec(cmd->token, d, check_builtin(*cmd->token), cmd);
		else if (!do_fork && check_builtin(*cmd->token))
			do_builtin(cmd->token, d, 0);
		else
			fork_exec(cmd->token, d, 0, cmd);
		cmd->fd.i++;
		cmd = cmd->next;
	}
}
