/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:39:38 by vismaily          #+#    #+#             */
/*   Updated: 2022/06/07 17:32:22 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

static void	print_error(char *msg)
{
	int	i;

	i = 0;
	if (msg != NULL)
	{
		while (msg[i] != 0)
			i++;
		write(STDERR_FILENO, msg, i);
	}
}

int	errors(int err_num, char *msg)
{
	if (err_num == 1)
		print_error("error: cd: bad arguments");
	else if (err_num == 2)
		print_error("error: cd: cannot change directory to ");
	else if (err_num == 3)
		print_error("error: fatal");
	else if (err_num == 4)
		print_error("error: cannot execute ");
	print_error(msg);
	print_error("\n");
	if (err_num == 1 || err_num == 2)
		return (0);
	exit(EXIT_FAILURE);
}
