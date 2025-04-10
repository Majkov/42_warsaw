/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:52:05 by mmajka            #+#    #+#             */
/*   Updated: 2025/04/01 18:10:17 by mmajka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char	*recursive(int index, char *excess, int fd);
char	*get_next_line(int fd);

int	main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	printf("fd: %i\n", fd);
	printf("gnl1\n");
	printf("%s",get_next_line(fd));
	printf("gnl2\n");
	printf("%s",get_next_line(fd));
	close(fd);
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*temp;
	static char	excess[BUFFER_SIZE];
	int			i;
	int			j;
	
	printf("2\n");
	printf("fd: %i, BUFFER_SIZE: %i\n", fd, BUFFER_SIZE);
	i = 0;
	if (fd == -1 || BUFFER_SIZE <= 1)
	{
		printf("2\n");
		// write(1, "ERROR!\n", 7);
		return (NULL);
	}
	printf("222\n");
	printf("c %c, p %p\n", 'a', excess);
	while (/*excess[i] != '\0' &&*/ excess != NULL)
	{
		printf("3\n");
		if (excess[i] == '\n' /*|| excess[i] == EOF*/)
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
				++j;
			}
			temp[j] = '\0';
			// free(excess);
			// excess = temp;
			return (line);
		}
		//keep reading
		++i;
	}
	printf("4\n");
	if (/*line[0] != '\0' ||*/ line != NULL)
	{
		printf("5\n");
		line = recursive(i, excess, fd);
	}
	
	printf("6\n");
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
	
	printf("7\n");
	i = 0;
	j = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	printf("bytes %li\n", bytes_read);
	if (bytes_read < 0)
	{
		write(1, "ERROR!\n", 7);
		return (NULL);
	}
	while (buffer[i] != '\0' && buffer[i] != '\n' && buffer[i] != EOF)
	{
		printf("8.1\n");
		printf("i %i\n", buffer[i]);
		printf("c %c\n", buffer[i]);
		++i;
		++index;
	}
	printf("i %i\n", buffer[i]);
	if (buffer[i] == '\n' || bytes_read == 0)
	{
		printf("8.2\n");
		line = malloc(index + 2);
		if (line == NULL)
		{
			free(line);
			return (NULL);
		}
		printf("9\n");
		// ecxess -> line copy
		if (excess != NULL)
		{
			while (excess[j] != '\0')
			{
				line[j] = excess[j];
				++j;
			}
		}
		printf("10\n");
		free(excess);
		excess = malloc(bytes_read - i);
		if (excess == NULL)
		{
			free(excess);
			return (NULL);
		}
		printf("11\n");
		j = 0;
		while (buffer[i + j + 1] != '\0')
		{
			printf("%c\n", buffer[i + j + 1]);
			excess[j] = buffer[i + j + 1];
			++j;
		}
		printf("12\n");
		printf("12\n");
		printf("%s\n", excess);
		// excess = excess;
		// excess[j] = '\0';
		j = 0;
		// line = mallock(index + 1);
		line[index + 1] = '\0';
	}
	else
	{
		--i;
		// line = recursive(index, excess, fd);
	}
	while (i >= 0)
	{
		line[index] = buffer[i];
		--i;
		--index;
	}
	printf("13\n");
	return (line);
}