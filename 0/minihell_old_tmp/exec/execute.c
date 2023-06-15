/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:30:08 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/13 19:14:47 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_from_path(char **token, t_d *d)
{
	char	**path;
	int		i;

	if (!token)
		return ;
	path = ft_split(ft_getenv(d->env, "PATH"), ':');
	i = -1;
	if (is_inside('/', token[0]))
		execve(token[0], token, d->envp);
	while (path && path[++i])
	{
		path[i] = ft_strjoin_premium(path[i], "/", 1);
		path[i] = ft_strjoin_premium(path[i], token[0], 1);
		if (!access(path[i], F_OK))
			execve(path[i], token, d->envp);
	}
	error_print_format_2(token[0], 1);
	free_2d(path);
	free_for_all(d);
	exit(127);
}

void	free_pipe(t_fd *fd)
{
	int	size;
	int	i;

	i = 1;
	size = fd->size - 1;
	while (i < size)
	{
		if (fd->pipe[i])
			free(fd->pipe[i]);
		i++;
	}
}

void	fork_exec(char **args, t_d *d, int type, t_fd *fd)
{
	int	pid;
	int	status;
	int	tmp;
	
	pid = 0;
	tmp = 0;
	pid = fork();
	tmp = dup(STDIN_FILENO);
	if (pid == 0)
	{
		dupdup(fd);
		if (type == 0)
			execute_from_path(args, d);
		else if (type == 1)
			do_builtin(args, d, 1);
	}
	waitpid(pid, &status, 0);
	dup2(tmp, STDIN_FILENO);
	if (fd->i > 0)
	{
		close(fd->pipe[fd->i - 1][0]);
	}
	close(fd->pipe[fd->i][1]);
	d->exit_status = WEXITSTATUS(status);
}

void	init_fd(t_fd *fd)
{
	fd->i = 0;
	fd->pipe = 0;
	fd->size = 0;
}

void	main_execute(t_d *d)
{
	t_token	*cmd;
	t_fd	fd;
	int		do_fork;

	// init_fd(&fd);
	cmd = d->tkn;
	fd.size = lst_size(cmd);
	do_fork = 1;
	fd.i = 0;
	if (lst_size(cmd) == 1)
		do_fork = 0;
	pipe_all(&fd);
	fork_fork(d, cmd, &fd, do_fork);
	// if (fd.size != 1)
	// 	free_pipe(&fd);
}
