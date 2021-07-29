/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_pid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:41:44 by daniel            #+#    #+#             */
/*   Updated: 2021/07/29 09:20:47 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Execve funcion
int	ft_exe(char *command, char **param, char **env, t_commands *pipex)
{
	int		i;
	char	*tmp;
	char	*error;

	i = 0;
	while (pipex->paths[i])
	{
		tmp = ft_strjoin_path(pipex->paths[i], command);
		execve(tmp, param, env);
		free(tmp);
		i++;
	}
	error = ft_strjoin(command, ", \033[1;31mcommand not found\n\033[0m");
	ft_exit(-1, error, pipex);
	return (0);
}

//Pip child
int	ft_pip_child(int pipefd, char **env, t_commands *pipex)
{
	int	file;

	file = open(pipex->fileout, O_WRONLY | O_TRUNC | O_CREAT,
			S_IRWXU | S_IRGRP | S_IROTH);
	if (pipex->fileout && file == -1)
	{
		ft_exit(access(pipex->fileout, R_OK),
			ft_strjoin(pipex->fileout, "\", \033[1;31mpermission denied\033[0m"),
			pipex);
		ft_exit(-1, ft_strjoin(pipex->fileout,
				"\",\033[1;31mno such file\033[0m"), pipex);
	}
	dup2(pipefd, STDIN_FILENO);
	close(pipefd);
	if (pipex->fileout)
	{
		dup2(file, STDOUT_FILENO);
		close(file);
	}
	ft_exe(pipex->command_out, pipex->param_out, env, pipex);
	return (0);
}

//Pip father
int	ft_pip_father(int pipefd, char **env, t_commands *pipex)
{
	int			file;
	char		**cmd;

	file = open(pipex->filein, O_RDONLY);
	if (file == -1)
	{
		ft_exit(access(pipex->filein, F_OK), ft_strjoin(pipex->filein, \
							", \033[1;31mno such file\n\033[0m"), pipex);
		ft_exit(access(pipex->filein, R_OK), ft_strjoin(pipex->filein, \
							", \033[1;31mpermission denied\n\033[0m"), pipex);
	}
	dup2(file, STDIN_FILENO);
	close(file);
	dup2(pipefd, STDOUT_FILENO);
	close(pipefd);
	if (!pipex->command_in)
		ft_exit(-1, ": \033[1;31mEmpty command\033[0m", pipex);
	ft_exe(pipex->command_in, pipex->param_in, env, pipex);
	return (0);
}

//Create pips
int	ft_pip(char **env, t_commands *pipex)
{
	pid_t		pid;
	int			fd[2];

	ft_exit(pipe(fd), "\033[1;31m pipe error \n \033[0m", pipex);
	pid = fork();
	if (pid == 0)
	{
		close(fd[1]);
		ft_pip_child(fd[0], env, pipex);
	}
	else if (pid > 0)
	{
		close(fd[0]);
		ft_pip_father(fd[1], env, pipex);
	}
	else if (pid < 0)
		ft_exit(pipe(fd), "\033[1;31m fork error \n \033[0m", pipex);
	return (0);
}
