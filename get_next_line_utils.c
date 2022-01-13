/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:22:49 by ybadaoui          #+#    #+#             */
/*   Updated: 2022/01/09 14:22:50 by ybadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*get_line(char	*buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (line);
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_rest(char	*buffer)
{
	int		i;
	int		j;
	char	*rest;

	if (!buffer)
		return (NULL);
	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	rest = malloc(ft_strlen(buffer) - i + 1);
	while (buffer[i])
	{
		rest[j] = buffer[i];
		i++;
		j++;
	}
	rest[j] = '\0';
	return (rest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	t_var	v;

	v.i = -1;
	if (s1 == NULL)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (s1);
	p = malloc(((v.size1 = ft_strlen((char *)s1
						)) + (v.size2 = ft_strlen((char *)s2))) + 1);
	if (!p)
		return (0);
	while (++v.i < (v.size1 + v.size2))
	{
		if (v.i < v.size1)
			p[v.i] = s1[v.i];
		if (v.i < v.size2)
			p[v.i + v.size1] = s2[v.i];
	}
	free(s1);
	p[v.i] = 0;
	return (p);
}
