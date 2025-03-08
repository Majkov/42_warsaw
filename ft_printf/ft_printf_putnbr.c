/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:26:51 by mmajka            #+#    #+#             */
/*   Updated: 2025/03/08 16:14:30 by mmajka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>

int					int_write(unsigned int number, char type);
static uintptr_t	reverse(uintptr_t input, int divisor);
int					pointer_write(uintptr_t number);
int					int_conversion(long int number);

/* Used for d, i, u, x, X */
int	int_write(unsigned int number, char type)
{
	int		divisor;
	int		count;
	char	digit;

	count = 0;
	if (number == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	divisor = 16;
	if (type == 'd' || type == 'i' || type == 'u')
		divisor = 10;
	number = (unsigned int)reverse((uintptr_t)number, divisor);
	while (number)
	{
		digit = number % divisor;
		digit += '0' + (digit / 10 * (type - '0' - 10));
		write(1, &digit, 1);
		number /= divisor;
		++count;
	}
	return (count);
}
/* Is used to reverse a number in order to
output it one digit at a time more easily */

static uintptr_t	reverse(uintptr_t input, int divisor)
{
	uintptr_t	output;

	output = 0;
	while (input)
	{
		output = output * divisor + (input % divisor);
		input /= divisor;
	}
	return (output);
}

/* Pointer address */
int	pointer_write(uintptr_t number)
{
	int		count;
	char	digit;

	count = 0;
	if (number == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	number = reverse(number, 16);
	write(1, "0x", 2);
	count += 2;
	while (number)
	{
		digit = number % 16;
		if (digit < 10)
			digit += '0';
		else
			digit += 'a' - 10;
		write(1, &digit, 1);
		number /= 16;
		++count;
	}
	return (count);
}

int	int_conversion(long int number)
{
	int	count;

	count = 0;
	if (number < 0)
	{
		write(1, "-", 1);
		++count;
		number *= -1;
	}
	count += int_write((unsigned int)number, 'u');
	return (count);
}
