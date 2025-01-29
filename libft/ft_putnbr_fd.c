/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:04:00 by mmajka            #+#    #+#             */
/*   Updated: 2025/01/23 17:54:06 by mmajka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	func(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	else if (n > 0)
		func(n * (-1), fd);
	else
	{
		write(fd, "-", 1);
		func(n, fd);
	}
}

static void	func(int n, int fd)
{
	char	c;

	if (n != 0)
	{
		c = n % 10 * -1 + '0';
		func(n / 10, fd);
		write(fd, &c, 1);
	}
}
