/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpongrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:05:17 by tpongrit          #+#    #+#             */
/*   Updated: 2022/10/21 19:57:31 by tpongrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char *get_next_line(int fd)
{
    char *str = malloc(10000), *copy = str;
    while (read(fd, copy, 1) > 0 && *copy++ != '\n');
    return (copy > str) ? (*copy = 0, str) : (free(str), NULL);
}
int	main(void) {
	char	*line;
	int		i;
	int		fd1;
	fd1 = open("testme1.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}
