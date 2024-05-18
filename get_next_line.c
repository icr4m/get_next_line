/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:24:54 by ijaber            #+#    #+#             */
/*   Updated: 2024/05/18 11:17:36 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_line(int fd, char *buffer, char *left);
static char	*set_line(char *line);

char	*get_next_line(int fd)
{
	static char	*left;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd == -1 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(left);
		free(buffer);
		left = NULL;
		buffer = NULL;
		return (NULL);
	}
	line = fill_line(fd, buffer, left);
	left = set_line(line);
	return (line);
}

char	*fill_line(int fd, char *buffer, char *left)
{
	ssize_t	bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(left);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!left)
		{
			left = (char *)malloc(1 * sizeof(char));
			left = NULL;
		}
		tmp = left;
		left = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left);
}

char	*set_line(char *line)
{
	char	*left;

	while (*line != '\n' || *line != '\0')
		line++;
	left = ft_strdup(line);
	*line = '\0';
	return (left);
}
