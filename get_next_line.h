/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpongrit <tpongrit <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:55:05 by tpongrit          #+#    #+#             */
/*   Updated: 2022/12/29 21:03:28 by tpongrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*ft_read(int fd, char *str);
char	*get_next_line(int fd);
char	*ft_strchr_nl(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_return_line(char *str);
char	*ft_move_line(char *str);
size_t	ft_strlen(const char *s);

#endif
