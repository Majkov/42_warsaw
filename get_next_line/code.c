#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

char	*get_next_line(int fd);

int	main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	// printf("fd: %i\n", fd);
	// printf("11111111111111111111\n");
	printf("gnl1: %s\n",get_next_line(fd));
	// printf("22222222222222222222\n");
	printf("gnl2: %s\n",get_next_line(fd));
	printf("gnl2: %s\n",get_next_line(fd));
	printf("gnl2: %s\n",get_next_line(fd));
	printf("gnl2: %s\n",get_next_line(fd));
	printf("gnl2: %s\n",get_next_line(fd));
	printf("gnl2: %s\n",get_next_line(fd));
	close(fd);
	return (0);
}

char	*get_next_line(int fd)
{
    char        *ptr;
    char        *line;
	char        buffer[BUFFER_SIZE + 1];
	ssize_t     bytes_read;
	static char *excess;
    
    if (fd == -1 || BUFFER_SIZE < 1)
	{
		return (NULL);
	}
    line = ""; //??
    if (excess != NULL)
    {
		line = ft_strdup(excess);
        ptr = ft_strchr(line, '\n');
        if (ptr != NULL)
        {
			
            excess = ft_strdup(ptr + 1);
            *(ptr + 1) = '\0';
            line = ft_strdup(line);
            return (line);
        }
        else
        {
            line = ft_strdup(line);
        }
    }
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    buffer[bytes_read] = '\0';
    while (bytes_read != 0)
    {
        if (bytes_read == -1)
            return (NULL);
        ptr = ft_strchr(buffer, '\n');
        if (ptr != NULL)
        {
            excess = ft_strdup(ptr + 1);
            *(ptr + 1) = '\0';
            line = ft_strjoin(line, buffer);
            return (line);
        }
        else
        {
            line = ft_strjoin(line, buffer);
        }
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        buffer[bytes_read] = '\0';
    }
    return (line);
}

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
	{
		return (NULL);
	}
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
	{
		return (NULL);
	}
	len2 = 0;
	while (s1[len2] != '\0')
	{
		ptr[len2] = s1[len2];
		++len2;
	}
	while (s2[len2 - len1] != '\0')
	{
        ptr[len2] = s2[len2 - len1];
		++len2;
	}
	ptr[len2] = '\0';
	return (ptr);
}

static void	len(char const *s, size_t *len)
{
	*len = 0;
	while (s[*len] != '\0')
		++*len;
}
