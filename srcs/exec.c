/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:12:58 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/17 20:29:51 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

static void	child(char **cmd, char **envp, int in, int fd[2])
{
	int	i;

	i = -1;
	if (dup2(in, STDIN_FILENO) < 0)
		errors(3, NULL);
	if (next_pipe(cmd) != 0 && dup2(fd[1], STDOUT_FILENO) < 0)
		errors(3, NULL);
	close(in);
	close(fd[0]);
	close(fd[1]);
	while (cmd[++i] != 0)
		if (strcmp(cmd[i], "|") == 0)
			break ;
	cmd[i] = 0;
	exec_cmd(cmd, envp);
	exit(0);
}

static void	parent(char ***cmd, int in, int fd[2], int *nb_wait)
{
	if (dup2(fd[0], in) < 0)
		errors(3, NULL);
	close(fd[0]);
	close(fd[1]);
	*cmd = next_pipe(*cmd);
	(*nb_wait)++;
}

static void	exec_pipes(char **cmd, char **envp)
{
	pid_t	pid;
	int		in;
	int		fd[2];
	int		nb_wait;

	nb_wait = 0;
	in = dup(STDIN_FILENO);
	if (in < 0)
		errors(3, NULL);
	while (cmd)
	{
		if (pipe(fd) < 0)
			errors(3, NULL);
		pid = fork();
		if (pid < 0)
			errors(3, NULL);
		if (pid == 0)
			child(cmd, envp, in, fd);
		else
			parent(&cmd, in, fd, &nb_wait);
	}
	close(in);
	while (nb_wait-- > 0)
		waitpid(0, NULL, 0);
}

void	exec(char **cmd, char **envp)
{
	if (strcmp(cmd[0], "cd") == 0)
		exec_cd(cmd);
	else if (next_pipe(cmd) == 0)
		exec_cmd(cmd, envp);
	else
		exec_pipes(cmd, envp);
}
