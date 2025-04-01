/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:52:05 by mmajka            #+#    #+#             */
/*   Updated: 2025/04/01 16:54:28 by mmajka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char	*recursive(int index, char *excess, int fd);

char	*get_next_line(int fd)
{
	char		*line;
	char		*temp;
	static char	*excess;
	int			i;
	int			j;

	i = 0;
	if (fd == -1 || BUFFER_SIZE <= 1)
	{
		// write(1, "ERROR!\n", 7);
		return (NULL);
	}
	while (excess[i] != '\0' && excess != NULL)
	{
		if (excess[i] == '\n' || excess[i] == EOF)
		{
			//return line and shorten excess
			line = malloc(i + 2);
			if (line == NULL)
			{
				free(line);
				return (NULL);
			}
			temp = malloc(sizeof(excess) - i - 1);
			if (temp == NULL)
			{
				free(temp);
				return (NULL);
			}
			//copy or split or memcpy or ft_substr
			while (j <= i)
			{
				line[j] = excess[j];
				++j;
			}
			line[j] = '\0';
			j = 0;
			++i;
			while (temp[j] != '\0')
			{
				temp[j] = excess[i];
			}
			temp[j] = '\0';
			free(excess);
			excess = temp;
			return (line);
		}
		//keep reading
		++i;
	}
	if (line[0] != '\0' || line != NULL)
	{
		line = recursive(i, excess, fd);
	}

	return (line);
}

// READ MALLOC FREE

// REKURENCJA

char	*recursive(int index, char *excess, int fd)
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
	{
		write(1, "ERROR!\n", 7);
		return (NULL);
	}
	while (buffer[i] != '\0' && buffer[i] != '\n' && buffer[i] != EOF)
	{
		++i;
		++index;
	}
	if (buffer[i] == '\n' || buffer[i] == EOF)
	{
		line = malloc(index + 2);
		if (line == NULL)
		{
			free(line);
			return (NULL);
		}
		// ecxess -> line copy
		while (excess[j] != '\0')
		{
			line[j] = excess[j];
			++j;
		}
		free(excess);
		excess = malloc(BUFFER_SIZE - i);
		if (excess == NULL)
		{
			free(excess);
			return (NULL);
		}
		j = 0;
		while (buffer[i + j + 1] != '\0')
		{
			excess[j] = buffer[i + j + 1];
			++j;
		}
		excess[j] = '\0';
		j = 0;
		// line = mallock(index + 1);
		line[index + 1] = '\0';
	}
	else
	{
		--i;
		recursive(index, excess, fd);
	}
	while (i >= 0)
	{
		line[index] = buffer[i];
		--i;
		--index;
	}
	return (line);
}

