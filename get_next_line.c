/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:23:38 by josfelip          #+#    #+#             */
/*   Updated: 2023/08/16 11:17:33 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		if (left_str)
			left_str = ft_strjoin(left_str, buff);
		else
			left_str = ft_strdup(buff);
	}
	free(buff);
	return (left_str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	if (dstsize == 0)
		return (i);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	c;
	size_t	d;

	c = ft_strlen(dst);
	d = ft_strlen(src);
	if (size <= c)
		return (size + d);
	d = 0;
	while (src[d] && c + 1 < size)
	{
		dst[c] = src[d];
		c++;
		d++;
	}
	dst[c] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[d]));
}

char    *ft_strdup(const char *s1)
{
        char    *result;
        size_t  len;

        len = ft_strlen(s1);
        result = malloc(len + 1);
        if (result == NULL)
                return (NULL);
		ft_strlcpy(result, s1, len + 1);
        return (result);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;
	size_t		len;
	size_t		i;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	len = 0;
	while (left_str[len] && left_str[len] != '\n')
		len++;
	if (left_str[len] == '\0' && len == 0)
	{
		free(left_str);
		return (NULL);
	}
	line = (char *)malloc((len + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (++i < len)
		line[i] = left_str[i];
	line[len] = '\n';
	line[len + 1] = '\0';
	left_str += len + 1;
	return (line);
}

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;

	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	fd4 = open("tests/test4.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd4);
		printf("line [%02d]: %s", i, line);
		free(line);
		// line = get_next_line(fd2);
		// printf("line [%02d]: %s", i, line);
		// free(line);
		// line = get_next_line(fd3);
		// printf("line [%02d]: %s", i, line);
		// free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return (0);
}
