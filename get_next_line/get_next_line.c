/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:52:05 by mmajka            #+#    #+#             */
/*   Updated: 2025/03/13 20:06:20 by mmajka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
RETURN VALUES OF "READ":
0 EOF
-1 ERROR
else works fine, returns the number of bytes successfully read

Because you will have to read files in get_next_line(),
add this option to your compiler call: -D BUFFER_SIZE=n
*/

#ifndef BUFFER_SIZE

BUFFER_SIZE 42;

#endif
/* int	BUFFER_SIZE = 42; 

int main() {
    int fd = open("example.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);  // Don't forget to free memory if you use dynamic allocation
    }
    close(fd);
    return 0;
}
*/

char	*get_next_line(int fd)
{
	char		*line;
	char		buffer[BUFFER_SIZE];
	static char	*excess;
	int			i;

	i = 0;
	if (fd == -1 || BUFFER_SIZE <= 1)
		write(1, "ERROR!\n", 7);
	// if (BUFFER_SIZE <= 1)
	// 	write(1, "ERROR!\n", 7);
	if (excess[0] == '\n')
	{
		++i;
		while(excess[i] != '\0' && excess[i] != '\n')
			++i;
		if (excess[i] == '\n')
		line = malloc(i);
		while (i >= 0)
		{
			line[i] = excess[i];
		}
		
	}
	else
		read(fd, buffer, BUFFER_SIZE - 1);

	// static char *variable to store excess characters (after \n)
	
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
