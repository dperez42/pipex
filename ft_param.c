/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 23:10:36 by daniel            #+#    #+#             */
/*   Updated: 2021/07/17 11:45:45 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Aux split funcion for parameters
static int	ft_contador_param(char const *str, char c)
{
	int		word_len;
	int		cont;
	int		flag;

	word_len = 0;
	cont = 0;
	flag = 0;
	while (*str)
	{
		if (!word_len && *str != c && flag == 0)
			cont++;
		if (*str == c)
			word_len = 0;
		else
			word_len = 1;
		if (*str == '\'' || *str == '\"')
		{
			if (flag == 0)
				flag = 1;
			else
				flag = 0;
		}
		str++;
	}
	return (cont);
}

//Aux split funcion for parameters
static int	ft_word_len_param(char const *str, char c)
{
	int	i;
	int	len;
	int	flag;

	i = 0;
	len = 0;
	flag = 0;
	while (str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			i++;
			if (flag == 0)
				flag = 1;
			else
				flag = 0;
		}
		if (str[i] == c && flag == 0)
			break ;
		i++;
		len++;
	}
	return (len);
}

int	ft_flag(int flag)
{
	if (flag == 0)
		g_pipex.flag = 1;
	else
		g_pipex.flag = 0;
	return (1);
}

int	ft_avant(const char *str, int ini, char c)
{
	while (str[ini] == c)
		ini++;
	return (ini);
}

// modified ft_split for " and '
char	**ft_split_param(const char *str, char c)
{
	int		i;
	int		j;
	int		k;
	char	**s;

	s = ft_malloc2(str, (ft_contador_param(str, c) + 1));
	i = -1;
	j = 0;
	while (++i < ft_contador_param(str, c))
	{
		k = 0;
		s[i] = ft_malloc1(ft_word_len_param(&str[j], c) + 1);
		j = ft_avant(str, j, c);
		while (str[j])
		{
			if (str[j] == '\'' || str[j] == '\"')
				j = j + ft_flag(g_pipex.flag);
			if (str[j] == c && g_pipex.flag == 0)
				break ;
			s[i][k++] = str[j++];
		}
		s[i][k] = '\0';
	}
	s[i] = 0;
	return (s);
}
