/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:49:44 by josfelip          #+#    #+#             */
/*   Updated: 2023/08/22 10:50:42 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#define FILE_TO_READ ".tests/evangelion.txt"
#define LINES_TO_READ 10

int	main(void)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(FILE_TO_READ, O_RDONLY);
	while (i++ <= LINES_TO_READ)
	{
		line = get_next_line(fd);
		printf("line %i - %s", i, line);
		free(line);
	}
	close(fd);
	return (0);
}
