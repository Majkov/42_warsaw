/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:16:18 by mmajka            #+#    #+#             */
/*   Updated: 2025/01/24 19:23:08 by mmajka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int					i;
	unsigned char		*d;
	unsigned const char	*s;

	if (dest == src)
		return (dest);
	d = dest;
	s = src;
	i = 1;
	if (d > s)
	{
		d += n - 1;
		s += n - 1;
		i = -1;
	}
	while (n > 0)
	{
		*d = *s;
		d += i;
		s += i;
		--n;
	}
	return (dest);
}
