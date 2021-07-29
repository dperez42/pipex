/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:37:07 by daniel            #+#    #+#             */
/*   Updated: 2021/07/29 09:07:59 by dperez-z         ###   ########.fr       */
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
	int		flag;
}	t_commands;

int		ft_strlen(char *str);
char	**ft_split(const char *str, char c);
char	**ft_split_param(const char *str, char c, t_commands *pipex);
void	ft_free_array(char **str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_path(char *s1, char *s2);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_exit(int ex, char *str, t_commands *pipex);
int		ft_pip(char **env, t_commands *pipex);
void	ft_parse(char **argv, char **env, t_commands *pipex);
void	*ft_calloc(size_t nitems, size_t size);
void	ft_bzero(void *str, size_t n);
char	**ft_malloc2(const char *str, int cont);
char	*ft_malloc1(int cont);
#endif
