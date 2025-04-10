#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char	*recursive(char *excess);
char	*get_next_line(int fd);

int	main()
{
	int fd = 3;
	fd = open("test.txt", O_RDONLY);
	printf("fd: %i\n", fd);
	printf("gnl1");
	printf("%s",get_next_line(fd));
	printf("gnl2");
	printf("%s",get_next_line(fd));
	close(fd);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*excess;
	printf("Before: %s", excess);
	recursive(excess);
	printf("After: %s", excess);
	return (0);
}

// READ MALLOC FREE

// REKURENCJA

char	*recursive(char *excess)
{
	int i;
	int j;
	ssize_t bytes_read;
	char buffer[BUFFER_SIZE];
	char	*line;
	
    free(excess);
    excess = malloc(BUFFER_SIZE - i);
    if (excess == NULL)
    {
        free(excess);
        return (NULL);
        printf("ERROR %s", excess);
    }
    printf("11\n");
    j = 0;
    excess = "lorem";
    printf("In: %s", excess);
	return (0);
}