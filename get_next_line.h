/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:09:39 by josfelip          #+#    #+#             */
/*   Updated: 2023/08/21 11:48:19 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_get_line(char *left_str);
char	*ft_new_left_str(char *left_str);
char	*ft_read_to_left_str(int fd, char *left_str);
char	*ft_strnwl(const char *s);
char	*ft_strjoin(char *left_str, char *buff);
size_t	ft_strlen(const char *s);

#endif
