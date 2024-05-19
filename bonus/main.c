/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:11:30 by ijaber            #+#    #+#             */
/*   Updated: 2024/05/19 11:22:21 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		close(fd);
	}
	return (0);
}
