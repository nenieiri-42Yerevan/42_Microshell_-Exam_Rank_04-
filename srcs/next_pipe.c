/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:54:51 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/17 19:50:18 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

char	**next_pipe(char **cmd)
{
	int	i;

	i = 0;
	if (cmd == 0)
		return (0);
	while (cmd[i] != 0)
	{
		if (strcmp(cmd[i], "|") == 0)
			return (cmd + i + 1);
		i++;
	}
	return (0);
}
