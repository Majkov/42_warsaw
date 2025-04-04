/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:16:49 by mmajka            #+#    #+#             */
/*   Updated: 2025/01/24 19:24:30 by mmajka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_dst = 0;
	len_src = 0;
	i = 0;
	while (dst[len_dst] != '\0' && len_dst < size)
		++len_dst;
	while (src[len_src] != '\0')
		++len_src;
	if (len_dst == size)
		return (size + len_src);
	while (src[i] != '\0' && len_dst + i < size - 1)
	{
		dst[len_dst + i] = src[i];
		++i;
	}
	if (len_dst + i < size)
		dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
