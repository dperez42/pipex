/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_pid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:41:44 by daniel            #+#    #+#             */
/*   Updated: 2021/07/06 08:22:13 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Execve funcion
int	ft_exe(char *command, char **param, char **env)
{
	int		i;
	char	*tmp;
	char	*error;

	i = 0;
	while (g_pipex.paths[i])
	{
		tmp = ft_strjoin_path(g_pipex.paths[i], command);
		execve(tmp, param, env);
		free(tmp);
		i++;
	}
	error = ft_strjoin(command, ", \033[1;31mcommand not found\n\033[0m");
	ft_exit(-1, error);
	return (0);
}

//Pip child
int	ft_pip_child(int pipefd, char **env)
{
	int	file;
	int	fd;

	file = open(g_pipex.fileout, O_WRONLY | O_TRUNC | O_CREAT,
			S_IRWXU | S_IRGRP | S_IROTH);
	if (g_pipex.fileout && file == -1)
	{
		ft_exit(access(g_pipex.fileout, R_OK),
			ft_strjoin(g_pipex.fileout, "\", \033[1;31mpermission denied\033[0m"));
		ft_exit(-1, ft_strjoin(g_pipex.fileout,
				"\",\033[1;31mno such file\033[0m"));
	}
	dup2(pipefd, STDIN_FILENO);
	close(pipefd);
	if (g_pipex.fileout)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	ft_exe(g_pipex.command_out, g_pipex.param_out, env);
	return (0);
}

//Pip father
int	ft_pip_father(int pipefd, char **env)
{
	int			file;
	char		**cmd;

	file = open(g_pipex.filein, O_RDONLY);
	if (file == -1)
	{
		ft_exit(access(g_pipex.filein, F_OK), ft_strjoin(g_pipex.filein, \
							", \033[1;31mno such file\n\033[0m"));
		ft_exit(access(g_pipex.filein, R_OK), ft_strjoin(g_pipex.filein, \
							", \033[1;31mpermission denied\n\033[0m"));
	}
	dup2(file, STDIN_FILENO);
	close(file);
	dup2(pipefd, STDOUT_FILENO);
	close(pipefd);
	if (!g_pipex.command_in)
		ft_exit(-1, ": \033[1;31mEmpty command\033[0m");
	ft_exe(g_pipex.command_in, g_pipex.param_in, env);
	return (0);
}

//Create pips
int	ft_pip(char **env)
{
	pid_t		pid;
	int			fd[2];

	ft_exit(pipe(fd), "\033[1;31m pipe error \n \033[0m");
	pid = fork();
	if (pid == 0)
	{
		close(fd[1]);
		ft_pip_child(fd[0], env);
	}
	else
	{
		close(fd[0]);
		ft_pip_father(fd[1], env);
	}
	return (0);
}
