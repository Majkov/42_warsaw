/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:18:52 by mmajka            #+#    #+#             */
/*   Updated: 2025/01/24 16:32:21 by mmajka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	if (len == 0)
		return (0);
	while (big[i] != '\0' && len > 0)
	{
		j = 0;
		while (big[i + j] != '\0' && big[i + j] == little[j] && len - j > 0)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
		len--;
	}
	return (0);
}
