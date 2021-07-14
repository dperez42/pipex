/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:06:41 by daniel            #+#    #+#             */
/*   Updated: 2021/07/06 08:15:35 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(int ex, char *str)
{
	if (ex < 0)
	{
		write(2, str, ft_strlen(str));
		exit(ex);
	}
	return ;
}

int	main (int arg, char **argv, char **env)
{
	int	i;

	if (arg != 5)
		ft_exit(-1, "\033[1;31m : usage: ./pipex file1 cmd1 cmd2 file2\n \033[0m");
	ft_parse(argv, env);
	signal(SIGPIPE, SIG_IGN);
	ft_pip(env);
	return (EXIT_SUCCESS);
}
