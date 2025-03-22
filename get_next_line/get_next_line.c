/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:52:05 by mmajka            #+#    #+#             */
/*   Updated: 2025/03/22 16:21:46 by mmajka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	char		*line;
	char		*temp;
	static char	*excess;
	int			i;

	i = 0;
	if (fd == -1 || BUFFER_SIZE <= 1)
	{
		write(1, "ERROR!\n", 7);
		return('ERROR!');
	}
	while (excess[i] != '\0' && excess != NULL)
	{
		if (excess[i] == '\n' || excess[i] == EOF)
		{
			//return line and shorten excess
			line = malloc(i + 2);
			temp = malloc(sizeof(excess) - i);
			//copy or split or memcpy or ft_substr
		}
		//keep reading
	}
	if (line[0] != '\0' && line != NULL)
	{
		read(fd, i);
	}

	return (line);
}

// READ MALLOC FREE

// REKURENCJA

int	recursive(int index, char *excess, int fd)
{
	int i;
	int j;
	ssize_t bytes_read;
	char buffer[BUFFER_SIZE];
	char	*line;

	i = 0;
	j = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	if (bytes_read < 0)
		write(1, "ERROR!\n", 7);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		{
			++i;
			++index;
		}
		
	if (buffer[i] == '\n' || bytes_read < BUFFER_SIZE - 1)
	{
		while (buffer[i + j] != '\0')
		{
			excess[j] = buffer[i + j];
			++j;
		}
		excess[j] = '\0';
		line = malloc(index);
		// line = mallock(index + 1);
		// line[index - 1] = '\0';
	}
	else
	{
		recursive(index, excess, fd);
	}
	while (i >= 0)
		{
			line[index] = buffer[i];
			--i;
			--index;
		}
	return (index);
}
