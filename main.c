/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 04:29:33 by ijaber            #+#    #+#             */
/*   Updated: 2024/05/10 04:47:47 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

int	main(void)
{
	int fd = open("aaaa.txt", O_RDONLY);
	char *line;
	
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}