/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:11:30 by ijaber            #+#    #+#             */
/*   Updated: 2024/05/19 15:00:18 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(int ac, char **av)
{
	int		fd;
	int		fd_2;
	int		fd_3;
	char	*line;
	char	*line_2;
	char	*line_3;
	size_t	count_line;

	(void)ac;
	count_line = 1;
	fd = open(av[1], O_RDONLY);
	fd_2 = open(av[2], O_RDONLY);
	fd_3 = open(av[3], O_RDONLY);
	while (line || line_2 || line_3)
	{
		line = get_next_line(fd);
		line_2 = get_next_line(fd_2);
		line_3 = get_next_line(fd_3);
		if (line)
			printf("La ligne %ld du fichier 1: %s\n", count_line, line);
		if (line_2)
			printf("La ligne %ld du fichier 2: %s\n", count_line, line_2);
		if (line_3)
			printf("La ligne %ld du fichier 3: %s\n", count_line, line_3);
		count_line++;
		free(line);
		free(line_2);
		free(line_3);
	}
	close(fd);
	close(fd_2);
	close(fd_3);
	return (0);
}
