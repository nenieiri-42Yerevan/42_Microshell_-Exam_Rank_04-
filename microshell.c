/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:10:54 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/17 14:04:08 by vismaily         ###   ########.fr       */
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

static void	exec(char **cmd, char **envp)
{
	if (strcmp(cmd, "cd") == 0)
		exec_cd(cmd);
	exec_cmd(cmd, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	start;

	i = 1;
	start = 1;
	if (argc < 2)
		return (0);
	while (argv[i] != 0)
	{
		if (strcmp(argv[i], ";") == 0)
		{
			argv[i] = '\0';
			exec(argv + start, envp);
			i++;
			while (argv[i] != 0 && strcmp(argv[i], ";") == 0)
				i++;
			start = i;
		}
		else
			i++;
	}
	exec(argv + start, envp);
	return (0);
}
