/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:02:41 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/17 16:19:51 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

void	exec_cmd(char **cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		errors(3, NULL);
	if (pid == 0)
		if (execve(cmd[0], cmd, envp) == -1)
			errors(4, cmd[0]);
	waitpid(0, NULL, 0);
}
