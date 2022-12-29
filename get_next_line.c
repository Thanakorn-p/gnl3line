/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpongrit <tpongrit <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:05:17 by tpongrit          #+#    #+#             */
/*   Updated: 2022/12/29 15:30:50 by tpongrit         ###   ########.fr       */
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
#include <string.h>
int	main(int argc, char *argv[])
{
	char	*line;
	int		i;
	int		j;
	int		fd;
	int		k;
	fd = open("testme1.txt", O_RDONLY);
	i = 0;
	j = 1;
	k = atoi(argv[1]);
	while (i < k){
		line = get_next_line(fd);
		printf("line [%02d]: %s", j, line);
		free(line);
		i++;
		j++;
	}
	close(fd);
	return (0);
}
*/
