/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:23:38 by josfelip          #+#    #+#             */
/*   Updated: 2023/08/22 12:21:18 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/// @brief reads chars from a input until '\n' or EOF is found
/// @param fd - the input file descriptor
/// @param left_str - the string to where the chars read are joined
/// @return left_str
char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	buff[BUFFER_SIZE + 1];
	int		r_bytes;

	r_bytes = 1;
	while (!ft_strnwl(left_str) && r_bytes)
	{
		r_bytes = read(fd, buff, BUFFER_SIZE);
		if (r_bytes == -1)
			return (NULL);
		buff[r_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	if (!left_str[0])
		return (NULL);
	return (left_str);
}

/// @brief get the next line from a input
/// @param fd - the input file descriptor
/// @return the next line
char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}

// Para testes, veja:
// https://github.com/jos-felipe/get_next_line