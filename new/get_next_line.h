/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 08:24:02 by ybadaoui          #+#    #+#             */
/*   Updated: 2022/01/09 09:40:25 by ybadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

char	*get_next_line(int fd);
int		the_end(char *str);
char	*get_intel(int fd, int size, char *buffer);
int		ft_strlen(char *str);
char	*get_line(char *buffer);
char	*get_rest(char *buffer);
char	*ft_strjoin(char *s1, char *s2);
#endif
