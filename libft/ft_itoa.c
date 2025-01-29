/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:03:20 by mmajka            #+#    #+#             */
/*   Updated: 2025/01/23 18:11:28 by mmajka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_length(int n);

char	*ft_itoa(int n)
{
	char	*ptr;
	int		length;

	length = ft_length(n);
	ptr = malloc(length + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[length] = '\0';
	if (!n)
	{
		ptr[0] = '0';
		return (ptr);
	}
	else if (n > 0)
		n *= -1;
	--length;
	while (n)
	{
		ptr[length] = (n % 10) * -1 + '0';
		--length;
		n /= 10;
	}
	if (!length)
		ptr[0] = '-';
	return (ptr);
}

static int	ft_length(int n)
{
	int	length;

	length = 0;
	if (n <= 0)
		++length;
	while (n)
	{
		n /= 10;
		++length;
	}
	return (length);
}
