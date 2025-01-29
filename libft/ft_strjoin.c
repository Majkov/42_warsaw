/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:54:49 by mmajka            #+#    #+#             */
/*   Updated: 2025/01/23 18:08:27 by mmajka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
