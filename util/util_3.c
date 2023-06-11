/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:20:12 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/12 00:37:29 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_print_format_1(char *s1)
{
	ft_putstr_fd("bash: syntax error near unexpected token `", 2);
	write(2, s1, ft_strlen(s1));
	write(2, "'\n", 2);
}

void	error_print_format_2(char *s1, int option)
{
	ft_putstr_fd("bash: ", 2);
	write(2, s1, ft_strlen(s1));
	if (option == 1)
		ft_putstr_fd(": command not found\n", 2);
	if (option == 2)
		ft_putstr_fd(": too many arguments\n", 2);
}

void	error_print_format_3(char *s1, char *s2, int option)
{
	ft_putstr_fd("bash: ", 1);
	write(2, s1, ft_strlen(s1));
	write(2, ": `", 2);
	write(2, s2, ft_strlen(s2));
	if (option == 1)
		ft_putstr_fd("': not a valid identifier\n", 2);
	else if (option == 2)
		ft_putstr_fd("': numeric argument required\n", 2);
	else if (option == 3)
		ft_putstr_fd("': No such file or directory\n", 2);
}

int	check_error_arrange(t_d *d)
{
	t_token	*ptr;

	ptr = d->tkn;
	if (ptr->type == PIPE)
	{
		error_print_format_1(ptr->str);
		d->exit_status = 258;
		return (1);
	}
	while (ptr)
	{
		if (ptr->type != CMD && ptr->next && ptr->next->type != CMD)
		{
			error_print_format_1(ptr->next->str);
			d->exit_status = 258;
			return (1);
		}
		ptr = ptr->next;
	}
	return (0);
}
