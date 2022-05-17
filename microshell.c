/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:10:54 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/17 12:40:49 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
