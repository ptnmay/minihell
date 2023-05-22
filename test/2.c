/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 05:50:44 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/23 05:58:38 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int	main(void)
{
	int	id;
	int	i;
	int	n;

	id = fork();
	if (id == 0)
		n = 1;
	else
		n = 6;
	// i = 0;
	// while (i < n + 5)
	// {
	// 	i = n;
	// 	printf("%d ", i);
	// 	fflush(stderr);
	// 	i++;
	// }
	if (id != 0)
		wait(1);
	for (i = n; i < n + 5; i++)
	{
		printf("%d ", i);
		fflush(stderr);
		i++;
		
	}
	
	if (id != 0)
		printf("\n");
}