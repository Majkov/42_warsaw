/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:40:03 by mmajka            #+#    #+#             */
/*   Updated: 2025/01/23 18:12:24 by mmajka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	segments_count(char const *s, char c);
static size_t	string_size(char const *s, char c, size_t *j, size_t *i);

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	segments;
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	array = ft_calloc(segments_count(s, c) + 1, sizeof(char *));
	if (!array)
		return (NULL);
	segments = 0;
	while (segments < segments_count(s, c))
	{
		array[segments] = malloc(string_size(s, c, &j, &i) + 1);
		k = i;
		while (i < j)
		{
			array[segments][i - k] = s[i];
			++i;
		}
		array[segments++][i - k] = '\0';
	}
	return (array);
}

static size_t	segments_count(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			++i;
		if (s[i] != c && s[i] != '\0')
			++counter;
		while (s[i] != c && s[i] != '\0')
			++i;
	}
	return (counter);
}

static size_t	string_size(char const *s, char c, size_t *j, size_t *i)
{
	*i = *j;
	while (s[*j] == c)
	{
		++*j;
		++*i;
	}
	while (s[*j] != c && s[*j] != '\0')
		++*j;
	return (*j - *i);
}
