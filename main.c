/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:06:41 by daniel            #+#    #+#             */
/*   Updated: 2021/07/29 09:26:16 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(int ex, char *str, t_commands *pipex)
{
	if (ex < 0)
	{
		write(2, str, ft_strlen(str));
		ft_free_array(pipex->paths);
		ft_free_array(pipex->param_in);
		ft_free_array(pipex->param_out);
		free(pipex->filein);
		free(pipex->fileout);
		free(pipex->command_in);
		free(pipex->command_out);
		free(pipex);
		exit(ex);
	}
	return ;
}

void	ft_exit_p(int ex, char *str)
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
	t_commands	*pipex;

	if (arg != 5)
		ft_exit_p(-1, "\033[1;31muse: ./pipex file1 cmd1 cmd2 file2\n \033[0m");
	pipex = malloc(sizeof(t_commands));
	if (pipex == 0)
		ft_exit(-1, "\033[1;31mUnanable to allor memorty.\n \033[0m", pipex);
	ft_parse(argv, env, pipex);
	signal(SIGPIPE, SIG_IGN);
	ft_pip(env, pipex);
	return (EXIT_SUCCESS);
}
