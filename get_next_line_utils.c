/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:23:54 by josfelip          #+#    #+#             */
/*   Updated: 2023/08/22 12:29:48 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

/// @brief finds the first new line char
/// @param s - the string to look inside
/// @return the pointer to new line char
char	*ft_strnwl(char *s)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			return (&s[i]);
	return (NULL);
}

/// @brief join the buff string to left_str
/// @param left_str - first part of the new str
/// @param buff - second part of the new str
/// @return a new string = left_str + buff
char	*ft_strjoin(char *left_str, char *buff)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!left_str)
	{
		left_str = malloc(1);
		if (!left_str)
			return (NULL);
		left_str[0] = '\0';
	}
	str = malloc(ft_strlen(left_str) + ft_strlen(buff) + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (left_str[++i])
		str[i] = left_str[i];
	j = 0;
	while (buff[j])
		str[i++] = buff[j++];
	str[i] = '\0';
	free(left_str);
	return (str);
}

/// @brief copy the chars of left_str until reach '\n' or EOF 
/// @param left_str 
/// @return a line with or without '\n'
char	*ft_get_line(char *left_str)
{
	char	*line;
	size_t	i;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
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

/// @brief copy the chars after the line returned
/// @param left_str 
/// @return left_str updated
char	*ft_new_left_str(char *left_str)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = malloc(ft_strlen(left_str) - i + 1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}
