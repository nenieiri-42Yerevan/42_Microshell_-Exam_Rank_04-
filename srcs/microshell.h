/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:41:21 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/17 16:25:56 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>

void	exec(char **cmd, char **envp);
void	exec_cd(char **cmd);
void	exec_cmd(char **cmd, char **envp);
void	errors(int err_num, char *msg);
char	**next_pipe(char **cmd);

#endif
