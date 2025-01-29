/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:56:05 by mmajka            #+#    #+#             */
/*   Updated: 2025/01/12 18:55:07 by mmajka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
