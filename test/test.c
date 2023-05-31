/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 08:01:44 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/31 18:04:33 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/errno.h>
#include<stdlib.h>
#include<errno.h>

int	main()
{
	pid_t	pid[2];
	int		pipefd[2];

	pipe(pipefd);
	pid[0] = fork();
	if (pid[0] == 0)
	{
		dup2(pipefd[1], 1);
		execve("/bin/ls", (char *[]){"ls", "-l", NULL}, NULL);
	}
	else
	{
		pid[1] = fork();
		if (pid[1] == 0)
		{
			close(pipefd[1]);
			dup2(pipefd[0], 0);
			execve("/usr/bin/wc", (char *[]){"wc", "-l", NULL}, NULL);
		}
		else
		{
			close(pipefd[1]);
			close(pipefd[0]);
			printf("waiting 1\n");
			waitpid(pid[0], NULL, 0);
			printf("waiting 2\n");
			waitpid(pid[1], NULL, 0);
			printf("done\n");
		}
	}
}
