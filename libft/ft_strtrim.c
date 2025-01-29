/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:13:24 by mmajka            #+#    #+#             */
/*   Updated: 2025/01/24 20:10:59 by mmajka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	s1_len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	s1_len = ft_strlen(s1);
	if (ft_strlen(set) == 0)
		return (ft_strdup(s1));
	while (check_set(s1[start], set) && start < s1_len)
		++start;
	while (check_set(s1[s1_len - 1], set) && s1_len > start)
		--s1_len;
	if (start > s1_len)
		return (ft_strdup(""));
	ptr = malloc(s1_len - start + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s1[start], s1_len - start + 1);
	return (ptr);
}

static int	check_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		++i;
	}
	return (0);
}
