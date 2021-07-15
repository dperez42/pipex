/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:37:07 by daniel            #+#    #+#             */
/*   Updated: 2021/07/06 08:09:47 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <signal.h>

typedef struct s_commands
{
	char	**paths;
	char	*filein;
	char	*fileout;
	char	*command_in;
	char	**param_in;
	char	*command_out;
	char	**param_out;
}	t_commands;

t_commands	g_pipex;
int		ft_strlen(char *str);
char	**ft_split(const char *str, char c);
char	**ft_split_param(const char *str, char c);
void	ft_free_array(char **str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_path(char *s1, char *s2);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_exit(int ex, char *str);
int		ft_pip(char **env);
void	ft_parse(char **argv, char **env);
void	*ft_calloc(size_t nitems, size_t size);
#endif
