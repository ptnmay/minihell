/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_trypipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 04:05:10 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/23 05:20:40 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	int	id;
	int	i;

	id = fork();
	if (id != 0)
		fork();
	printf("how to fork 3\n");
	// id = fork();
	// if (id == 0)
	// 	printf("id = [child process]\n");
	// else
	// 	printf("id = [parent process]\n");
	
	// i = 0;
	// while (i < 2)
	// {
	// 	id = fork();
	// 	printf("%d\n", id);
	// 	i++;
	// }

	// fork();
	// fork();
	// fork();
	// printf("hello world\n");
	return (0);
}