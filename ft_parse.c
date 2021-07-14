/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 22:58:31 by daniel            #+#    #+#             */
/*   Updated: 2021/07/14 10:13:02 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*ps1;
	char	*res;

	ps1 = (char *)s1;
	i = 0;
	while (ps1[i] != '\0')
		i++;
	res = (char *)malloc(i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (ps1[i] != '\0')
	{
		res[i] = ps1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	i = 0;
	while ((ps1[i] != '\0' || ps2[i] != '\0'))
	{
		if (ps1[i] != ps2[i])
			return (ps1[i] - ps2[i]);
		i++;
	}
	return (0);
}

//Load enviroment paths in g_pipex.paths
void	ft_load_paths(char **env)
{
	int		i;
	char	**tmp;

	i = 0;
	while (env[i])
	{
		tmp = ft_split(env[i], '=');
		if (!ft_strcmp(tmp[0], "PATH"))
		{
			g_pipex.paths = ft_split(tmp[1], ':');
			ft_free_array(tmp);
			return ;
		}
		ft_free_array(tmp);
		i++;
	}
	return ;
}

//Parsing data to g_pipex
void	ft_parse(char **argv, char **env)
{
	char	**tmp;
	int		i;

	i = 0;
	while (argv[i])
		if (!ft_strcmp(argv[i++], ""))
			ft_exit(-1, ": \033[1;31mEmpty command \n\033[0m");
	g_pipex.filein = ft_strdup(argv[1]);
	g_pipex.fileout = ft_strdup(argv[4]);
	g_pipex.flag = 0;
	g_pipex.param_in = ft_split_param(argv[2], ' ');
	g_pipex.flag = 0;
	g_pipex.param_out = ft_split_param(argv[3], ' ');
	tmp = ft_split(argv[2], ' ');
	g_pipex.command_in = ft_strdup(tmp[0]);
	ft_free_array(tmp);
	tmp = ft_split(argv[3], ' ');
	g_pipex.command_out = ft_strdup(tmp[0]);
	ft_free_array(tmp);
	ft_load_paths(env);
	return ;
}
