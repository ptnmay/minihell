/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testpipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:38:14 by psaeyang          #+#    #+#             */
/*   Updated: 2023/06/09 01:07:50 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int pipefd[2];

	pipe(pipefd);

	/* child process, executes echo */
	int childPid = fork();
	if (childPid == 0) {
		 char *av[] = {
			"/bin/echo",
			"h_e_l_l_o_ _w_o_r_l_d",
			NULL,
		};
		close(pipefd[0]); // closing unused read end
		dup2(pipefd[1], 1);
		close(pipefd[1]); // closing original write end, because it has been duplicated

		if (execv(av[0], av) == -1) {
			perror("execv: ");
		}
		exit(0);
	}

	/* parent process, wires up echo's output to tr's input */

	char *av[] = {
		"/usr/bin/tr",
		"-d",
		"_",
		NULL,
	};

	close(pipefd[1]); // closing unused write end
	dup2(pipefd[0], 0);
	close(pipefd[0]); // closing original read end, because it has been duplicated
	if (execv(av[0], av) == -1) {
		perror("execv: ");
	}

	return (0);
}