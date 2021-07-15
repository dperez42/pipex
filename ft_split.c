/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 23:10:36 by daniel            #+#    #+#             */
/*   Updated: 2021/07/15 10:27:48 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_bzero(void *str, size_t n)
{
	char	*c;
	size_t	i;

	c = (char *)str;
	i = 0;
	while (i < n)
	{
		*c = '\0';
		c++;
		i++;
	}
}

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*res;

	res = malloc(nitems * size);
	if (!res)
		return (NULL);
	ft_bzero(res, nitems * size);
	return ((void *)res);
}

//Aux Split funcion
static int	ft_contador(char const *str, char c)
{
	int		word_len;
	int		cont;

	word_len = 0;
	cont = 0;
	while (*str)
	{
		if (!word_len && *str != c)
			cont++;
		if (*str == c)
			word_len = 0;
		else
			word_len = 1;
		str++;
	}
	return (cont);
}

//Aux Split funcion
static int	ft_word_len(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

//Malloc funcion 2dimentions
char	**ft_malloc2(const char *str, int cont)
{
	char	**s;
	
	s = (char **)malloc(sizeof(*s) * cont);
	if (!str || !s)
		return (NULL);
	return (s);
}

//Malloc funcion 1dimentions
char	*ft_malloc1(int cont)
{
	char *s;
	s = ft_calloc(cont, 1);
	if (!s)
		s = NULL;
	return (s);
}
//Split funcion
char	**ft_split(const char *str, char c)
{
	int		i;
	int		j;
	int		k;
	char	**s;

	s = ft_malloc2(str, (ft_contador(str, c) + 1));
	i = -1;
	j = 0;
	while (++i < ft_contador(str, c))
	{
		k = 0;
		s[i] = ft_malloc1(ft_word_len(&str[j], c) + 1);
		while (str[j] == c)
			j++;
		while (str[j] != c && str[j])
			s[i][k++] = str[j++];
		s[i][k] = '\0';
	}
	s[i] = 0;
	return (s);
}
