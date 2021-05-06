/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:43:34 by msadaoui          #+#    #+#             */
/*   Updated: 2021/05/06 15:48:57 by msadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strnew(size_t size)
{
	char	*new;

	new = malloc(sizeof(*new) * size + 1);
	if (!new)
		return (NULL);
	new[size] = '\0';
	while (size--)
		new[size] = '\0';
	return (new);
}

static void	get_line(char **save, int *bytes_read, \
	char buffer[BUFFER_SIZE], int fd)
{
	char	*temp;

	*bytes_read = 1;
	if (!*save)
		*save = ft_strnew(1);
	while (*bytes_read > 0 && (ft_strchr(*save, '\n') == 0))
	{
		*bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[*bytes_read] = '\0';
		temp = ft_strjoin(*save, buffer);
		ft_strdel(&*save);
		*save = temp;
	}
}

static void	still_reading(char **line, int bytes_read, char **save)
{
	char	*temp;
	char	*new_line;

	if (bytes_read > 0)
	{
		new_line = ft_strchr(*save, '\n');
		if (!new_line)
		{
			*line = ft_strdup(*save);
			ft_strdel(&*save);
		}
		*new_line++ = '\0';
		*line = ft_strdup(*save);
		temp = ft_strdup(new_line);
		ft_strdel(&*save);
		*save = temp;
	}
}

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*save[255];
	int			bytes_read;

	if (read(fd, buffer, 0) < 0)
		return (-1);
	get_line(&save[fd], &bytes_read, buffer, fd);
	if (bytes_read < 0 || fd < 0)
	{
		ft_strdel(&save[fd]);
		return (-1);
	}
	if (bytes_read == 0)
	{
		*line = ft_strdup(save[fd]);
		ft_strdel(&save[fd]);
		return (0);
	}
	still_reading(line, bytes_read, &save[fd]);
	return (1);
}
