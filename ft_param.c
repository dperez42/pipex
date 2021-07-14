/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 23:10:36 by daniel            #+#    #+#             */
/*   Updated: 2021/07/14 10:24:25 by dperez-z         ###   ########.fr       */
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

// Flag to diseable split when found ' y "
int	ft_flag(const char *str, int j)
{
	int	flag;

	if (str[j] == '\'' || str[j] == '\"')
	{
		j++;
		if (g_pipex.flag == 0)
			g_pipex.flag = 1;
		else
			g_pipex.flag = 0;
	}
	return (j);
}

// Malloc 2 dim
char	**ft_malloc2(const char *str, char c)
{
	char	**s;

	s = (char **)malloc(sizeof(*s) * (ft_contador_param(str, c) + 1));
	if (!str || !s)
		return (NULL);
	return (s);
}

// modified ft_split for " and '
char	**ft_split_param(const char *str, char c)
{
	int		i;
	int		j;
	int		k;
	char	**s;

	s = ft_malloc2(str, c);
	i = -1;
	j = 0;
	while (++i < ft_contador_param(str, c))
	{
		k = 0;
		s[i] = ft_malloc1(ft_word_len_param(&str[j], c));
		while (str[j] == c)
			j++;
		while (str[j])
		{
			j = ft_flag(str, j);
			if (str[j] == c && g_pipex.flag == 0)
				break ;
			s[i][k++] = str[j++];
		}
		s[i][k] = '\0';
	}
	s[i] = 0;
	return (s);
}
