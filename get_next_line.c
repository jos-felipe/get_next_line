/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:23:38 by josfelip          #+#    #+#             */
/*   Updated: 2023/08/21 15:59:09 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/// @brief read chars from the text file pointed by fd until a '\n' is found
/// @param fd - file descriptor of the text file
/// @param left_str - the string where chars are stored
/// @return left_str
char	*ft_read_to_left(int fd, char *left_str)
{
	char	*buff;
	int		r_bytes;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	r_bytes = 1;
	while (!ft_strnwl(left_str) && r_bytes)
	{
		r_bytes = read(fd, buff, BUFFER_SIZE);
		if (r_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[r_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

/// @brief get the next line from the text file pointed by fd
/// @param fd - file descriptor of the text file
/// @return the line readed
char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_str = ft_read_to_left(fd, left_str);
	if (*left_str == '\0')
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}

// Para testes, veja:
// https://github.com/jos-felipe/get_next_line