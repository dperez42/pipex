/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:19:23 by daniel            #+#    #+#             */
/*   Updated: 2021/07/14 10:24:01 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_free_array(char **str)
{
	int	cnt;

	cnt = 0;
	if (!str)
		return ;
	while (str[cnt])
	{
		free(str[cnt]);
		str[cnt++] = NULL;
	}
	free(str);
	str = NULL;
}

char	*ft_strjoin_path(char *s1, char *s2)
{
	char	*dest;
	size_t	lens1;
	size_t	lens2;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (lens1 + lens2) + 2);
	if (!dest)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < lens1)
		*(dest + i) = *(s1 + i);
	*(dest + i++) = '/';
	while (++j < lens2)
		*(dest + i++) = *(s2 + j);
	dest[i++] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	lens1;
	size_t	lens2;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (lens1 + lens2) + 1);
	if (!dest)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < lens1)
		*(dest + i) = *(s1 + i);
	while (++j < lens2)
		*(dest + i++) = *(s2 + j);
	dest[i++] = '\0';
	return (dest);
}

// Malloc 1 dim
char	*ft_malloc1(int i)
{
	char	*s;

	s = ft_calloc(i + 1, 1);
	if (!s)
		s = NULL;
	return (s);
}
