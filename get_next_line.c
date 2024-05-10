/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 00:44:01 by ijaber            #+#    #+#             */
/*   Updated: 2024/05/10 09:17:00 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_line(int fd, char *buffer, char *left);
static char	*set_left_line(char *line);

char	*get_next_line(int fd)
{
	static char	*left;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(left_c);
		free(buffer);
		left_c = NULL;
		buffer = NULL;
		return (NULL);
	}
	line = fill_line(fd, buffer, left);
	left = set_left_line(line);
	return (line);
}

char	*fill_line(int fd, char *buffer, char *left)
{
	ssize_t	r_read;
	char	*tmp;

	r_read = 1;
	while (r_read > 0)
	{
		r_read = read(fd, buffer, BUFFER_SIZE);
		if (r_read == -1)
		{
			free(left);
			return (NULL);
		}
		else if (r_read == 0)
			break ;
		buffer[r_read] = "\0";
		if (!left)
		{
			left = (char *)malloc(1 * sizeof(char));
			left = 0;
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

static char	*_fill_line_buffer(int fd, char *left_c, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		/ if (b_read == -1)
		{
			free(left_c);
			return (NULL);
		}
		else if (b_read == 0) break ;
		buffer[b_read] = 0;
		if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}
