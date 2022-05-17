/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:39:38 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/17 13:44:18 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

static void	print_error(char *msg)
{
	int	i;

	i = 0;
	while (msg[i] != 0)
		i++;
	write(STDERR_FILENO, msg, i);
}

void	errors(int err_num, char *msg)
{
	if (err_num == 1)
		print_error("error: cd: bad arguments");
	else if (err_num = 2)
	{
		print_error("error: cd: cannot change directory to ");
		print_error(msg);
	}
	print_error("\n");
}
