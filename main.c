/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:49:44 by josfelip          #+#    #+#             */
/*   Updated: 2023/08/29 12:40:15 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("tests/evangelion.txt", O_RDONLY);
	i = 1;
	line = get_next_line(fd1);
	while (line)
	{
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
		line = get_next_line(fd1);
	}
	close(fd1);
	return (0);
}
