/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:12:58 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/17 14:14:21 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

static void	exec_cd(char **cmd)
{
	if (cmd[1] == 0 || cmd[2] != 0)
		errors(1, NULL);
	if (chdir(cmd[1]) == -1)
		errors(2, cmd[1]);
}

static void	exec_cmd(char **cmd, char **envp)
{
	pid_t	pid;

	if ((pid = fork()) < 0)
		errors(3, NULL);
	if (pid == 0)
		if (execve(cmd[0], cmd, envp) == -1)
			errors(4, cmd[0]);
	waitpid(0, NULL, 0);
}

void	exec(char **cmd, char **envp)
{
	if (strcmp(cmd, "cd") == 0)
		exec_cd(cmd);
	exec_cmd(cmd, envp);
}
