#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 6
#endif

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

char	*get_next_line(int fd);

// https://stackoverflow.com/questions/68144753/using-read-for-reading-a-file-in-c

int	main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	printf("fd: %i\n", fd);
	printf("11111111111111111111\n");
	printf("gnl1: %s\n",get_next_line(fd));
	printf("22222222222222222222\n");
	printf("gnl2: %s\n",get_next_line(fd));
	close(fd);
	return (0);
}

char	*get_next_line(int fd)
{
	// int         i;
    char        *ptr;
    char        *line;
	char        buffer[BUFFER_SIZE + 1];
	ssize_t     bytes_read;
	static char *excess;
    
	// int i;
	// int j;
	// char	*line;
	// char		*temp;
	// int			j;

    if (fd == -1 || BUFFER_SIZE <= 1)
	{
		// printf("2\n");
		// write(1, "ERROR!\n", 7);
		return (NULL);
	}
    line = "";
    printf("excess: %p\n", excess);
    printf("excess: %s\n", excess);
    if (excess != NULL)
    {
        ptr = ft_strchr(buffer, '\n');
        if (ptr != NULL)
        {
            excess = ft_strdup(ptr + 1);
            printf("excess: %s\n", excess);
            printf("buffer: %s\n", buffer);
            *(ptr + 1) = '\0';
            printf("line: %s\n", line);
            printf("buffer: %s\n", buffer);
            line = ft_strjoin(line, buffer);
            printf("line: %s\n", line);
            return (line);
        }
        else
        {
            printf("line: %s\n", line);
            printf("buffer: %s\n", excess);
            line = ft_strjoin(line, excess);
            printf("line: %s\n", line);
        }
    }
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    buffer[bytes_read] = '\0';
    printf("excess: %s\n", excess);
    printf("buffer: %s\n", buffer);
    while (bytes_read)
    {
        printf("Buffer: %s\n", buffer);
        printf("excess: %s\n", excess);
        printf("ptr: %p\n", ptr);
        if (bytes_read == -1)
            return (NULL);
        ptr = ft_strchr(buffer, '\n');
        printf("ptr: %p\n", ptr);
        printf("line: %p\n", line);
        printf("line: %s\n", line);
        if (ptr != NULL)
        {
            excess = ft_strdup(ptr + 1);
            printf("1excess: %s\n", excess);
            printf("2buffer: %s\n", buffer);
            *(ptr + 1) = '\0';
            printf("line: %s\n", line);
            printf("buffer: %s\n", buffer);
            line = ft_strjoin(line, buffer);
            printf("line: %s\n", line);
            return (line);
        }
        else
        {
            printf("line: %s\n", line);
            printf("buffer: %s\n", buffer);
            line = ft_strjoin(line, buffer);
            printf("line: %s\n", line);
        }
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        buffer[bytes_read] = '\0';
    }
    return (line);
}

//##########

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c % 256)
		{
			return ((char *)s);
		}
		++s;
	}
	if (*s == c % 256)
		return ((char *)s);
	else
		return (0);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ptr;

	len = 0;
	while (s[len] != '\0')
		len++;
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
	{
		ptr[len] = s[len];
		++len;
	}
	ptr[len] = s[len];
	return (ptr);
}

static void	len(char const *s, size_t *len);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len1;
	size_t	len2;

	len(s1, &len1);
	len(s2, &len2);
	ptr = malloc(len1 + len2 + 1);
	if (ptr == NULL)
		return (NULL);
	len2 = 0;
	while (s1[len2] != '\0')
	{
		ptr[len2] = s1[len2];
        printf("c: %c\n", ptr[len2]);
		++len2;
	}
	while (s2[len2 - len1] != '\0')
	{
        ptr[len2] = s2[len2 - len1];
        printf("c: %c\n", ptr[len2]);
		++len2;
	}
	ptr[len2] = '\0';
    printf("s: %s\n", ptr);
	return (ptr);
}

static void	len(char const *s, size_t *len)
{
	*len = 0;
	while (s[*len] != '\0')
		++*len;
}
