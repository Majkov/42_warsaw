/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:52:05 by mmajka            #+#    #+#             */
/*   Updated: 2025/03/07 19:00:05 by mmajka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
RETURN VALUES OF "READ":
0 EOF
-1 ERROR
else works fine, returns the number of bytes successfully read

Because you will have to read files in get_next_line(),
add this option to your compiler call: -D BUFFER_SIZE=n
*/

char	*get_next_line(int fd)
{
	char	*line;
	char	buffer[BUFFER_SIZE];
	static char *excess;

	if (excess[0] == '\n')
	{
		...
	}
	if (fd == -1)
	Error;
	if (BUFFER_SIZE <= 1)
	Error;
	read(fd, buffer, sizeof(buffer)-1);

	static char *variable to store excess characters (after \n)
	
	return (str);
}

READ MALLOC FREE

REKURENCJA

char	*recursive(char *line, int index, static char *excess, int fd)
{
	int i;
	int j;

	i = 0;
	read(fd, buffer, sizeof(buffer)-1);
	czy 0 lub EOF
	while (buffer[i] != '\0' && buffer[i] != '\n')
		++i;
	if (buffer[i] == '\n')
	{
		j = 0;
		while (buffer[i + j - 1] != '\0')
		{
			excess[j] = buffer[i + j];
			++j;
		}
		line = mallock(index + 1);
		line[index] = '\0';
	}
	else
	{
		recursive(*line, index, *excess, fd);
	}
	while (i >= 0)
		{
			line[index] = buffer[i];
		}
		return (index);
}
