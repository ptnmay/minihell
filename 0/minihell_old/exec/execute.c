/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:30:08 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/13 19:17:50 by psaeyang         ###   ########.fr       */
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

void	fork_exec(char **args, t_d *d, int type, t_token *cmd)
{
	int	tmp;
	int	pid;
	int	status;

	tmp = dup(STDIN_FILENO);
	pid = fork();
	if (pid == 0)
	{
		dupdup(cmd);
		if (type == 0)
			execute_from_path(args, d);
		else if (type == 1)
			do_builtin(args, d, 1);
	}
	dup2(tmp, STDIN_FILENO);
	waitpid(pid, &status, 0);
	close(cmd->fd.pipe[1]);
	if (cmd->fd.i > 0)
	{
		close(cmd->fd.pipe[0]);
	}
	d->exit_status = WEXITSTATUS(status);
}

void	main_execute(t_d *d)
{
	t_token	*cmd;
	int		do_fork;
	int		i;

	i = 0;
	cmd = d->tkn;
	cmd->fd.size = lst_size(cmd);
	do_fork = 1;
	if (lst_size(cmd) == 1)
		do_fork = 0;
	pipe_all(cmd, i);
	cmd->fd.i = 0;
	fork_fork(d, cmd, do_fork);
}
