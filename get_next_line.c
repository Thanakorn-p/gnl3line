/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpongrit <tpongrit <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:05:17 by tpongrit          #+#    #+#             */
/*   Updated: 2022/12/24 20:51:28 by tpongrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char	*ft_read(int fd, char *str)
{
	char	*buf;
	int		bytes_count;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	bytes_count = 2004;
	while (!check4nl(str) && bytes_count != 0)
	{
		bytes_count = read(fd, buf, BUFFER_SIZE);
		if (bytes_count == -1)
		{
			free(buf);
			return (0);
		}
		buf[bytes_count] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (0);
	line = ft_return_line(str);
	str = ft_move_line(str);
	return (line);
}
/*
int	main(void) {
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("testme1.txt", O_RDONLY);
	fd2 = open("testme2.txt", O_RDONLY);
	fd3 = open("testme3.txt", O_RDONLY);
	i = 1;
	while (i < 5){
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
	//	line = get_next_line(fd2);
	//	printf("line [%02d]: %s", i, line);
	//	free(line);
	//	line = get_next_line(fd3);
	//	printf("line [%02d]: %s", i, line);
	//	free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
*/
