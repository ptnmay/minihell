/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 04:57:09 by psaeyang          #+#    #+#             */
/*   Updated: 2023/06/11 05:35:49 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parent_process(t_token *cmd)
{
	cmd->exe.tmp_fd = dup(cmd->exe.pfd[0]);
	close(cmd->exe.pfd[0]);
	close(cmd->exe.pfd[1]);
	// wait(NULL);
	wait(NULL);
}