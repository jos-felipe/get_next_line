/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:23:54 by josfelip          #+#    #+#             */
/*   Updated: 2023/08/21 12:51:57 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

/// @brief find the first new line char
/// @param s - the string to look inside
/// @return the point to new line char
char	*ft_strnwl(const char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			return (&s[i]);
	return (NULL);
}

/// @brief join the str in buff after left_str
/// @param left_str
/// @param buff 
/// @return a new string formed by buff joined to left_str
char	*ft_strjoin(char *left_str, char *buff)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!left_str)
	{
		left_str = maloc(1);
		if (!left_str)
			return (NULL);
		left_str[0] = '\0';
	}
	str = malloc(str_len(left_str) + str_len(buff) + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (left_str[++i])
		str[i] = left_str[i];
	free(left_str);
	j = 0;
	while (buff[j])
		str[i++] = buff[j++];
	str[i] = '\0';
	return (str);
}

/// @brief create a new str 
/// @param left_str 
/// @return a line
char	*ft_get_line(char *left_str)
{
	char	*line;
	size_t	i;

	i = 0;
	while (left_str[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		line[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		line[i] = left_str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

/// @brief stores a new string result from subtratected line from left_str
/// @param left_str 
/// @return the new left_str
char	*ft_new_left_str(char *left_str)
{
	char	*str;
	size_t	i;

	i = 0;
	while (left_str[i] != '\n')
		i++;
	str = malloc(ft_strlen(left_str) - i + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	return (str);
}
