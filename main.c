/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 04:29:33 by ijaber            #+#    #+#             */
/*   Updated: 2024/05/18 18:04:32 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	size_t	i;
	char	*line;

	i = 4;
	fd = open("aaaa.txt", O_RDONLY);
	line = get_next_line(fd);
	while (i)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		i--;
	}
	return (0);
}
