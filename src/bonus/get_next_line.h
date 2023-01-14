/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 00:24:48 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/14 00:41:16 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

size_t	ft_gnl_strlen(char *s);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_gnl_strlcat(char *dst, char *src, size_t dstsize);
ssize_t	ft_strchr_index(char *s, int c);
char	*get_next_line(int fd);

#endif