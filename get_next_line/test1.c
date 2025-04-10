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

char *test(char *s);
void ft_bzero(void *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

int	main()
{
    char *a;
    char *b;

    a = "";
    b = "def";
    
    a = ft_strjoin(a, b);
    printf("a: %s", a);
	// printf("%s\n", test("test1"));
	// printf("%s\n", test("set15"));
	return (0);
}

char *test(char *s)
{
    static char *excess;
    int i;
    int j;

    i = 0;
    j = 0;
    while (s[j] != '\0')
        ++j;
    printf("1%s\n", excess);
    excess = malloc(j + 1);
    printf("2%s\n", excess);
    while (s[i] != '\0')
    {
        excess[i] = s[i];
        ++i;
    }
    excess[i] = s[i];
    printf("3%s\n", excess);
    // ft_bzero(excess + i, BUFFER_SIZE - i - 1);
    printf("4%s\n", excess);
    return (excess);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;

	temp = s;
	while (n > 0)
	{
		*temp = '\0';
		temp++;
		n--;
	}
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
