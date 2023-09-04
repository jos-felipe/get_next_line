/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:49:44 by josfelip          #+#    #+#             */
/*   Updated: 2023/09/04 12:24:29 by josfelip         ###   ########.fr       */
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
	int		fd2;

	fd1 = open("tests/evangelion.txt", O_RDONLY);
	fd2 = open("tests/mlines.txt", O_RDONLY);
	// fd1 = 0;
	i = 1;
	while (i < 10)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}
