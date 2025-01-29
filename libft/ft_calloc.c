/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:55:44 by mmajka            #+#    #+#             */
/*   Updated: 2025/01/24 20:15:45 by mmajka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t		i;
	size_t		memory_size;
	char		*ptr;

	memory_size = nmemb * size;
	if (nmemb != 0 && memory_size / nmemb != size)
		return (NULL);
	ptr = malloc(memory_size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < memory_size)
	{
		ptr[i] = 0;
		++i;
	}
	return (ptr);
}
