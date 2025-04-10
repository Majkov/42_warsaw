/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:26:51 by mmajka            #+#    #+#             */
/*   Updated: 2025/04/10 16:06:05 by mmajka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>

int					int_write(unsigned int number, char type);
static uintptr_t	reverse(uintptr_t input, int divisor, int *leading_zeros);
int					pointer_write(uintptr_t number);
int					int_conversion(long int number);
int					value_zero(char type);

// int					edge_case(int digit, int divisor);

/* Used for d, i, u, x, X */

int	int_write(unsigned int number, char type)
{
	int		divisor;
	int		count;
	char	digit;
	int		leading_zeros;

	count = 0;
	if (number == 0)
		return (value_zero('n'));
	divisor = 16;
	if (type == 'd' || type == 'i' || type == 'u')
		divisor = 10;
	number = (unsigned int)reverse((uintptr_t)number, divisor, &leading_zeros);
	count += leading_zeros;
	while (number)
	{
		digit = number % divisor;
		digit += '0' + (digit / 10 * (type - '0' - 10));
		write(1, &digit, 1);
		number /= divisor;
		++count;
	}
	while (leading_zeros-- > 0)
		write(1, "0", 1);
	return (count);
}
/* Is used to reverse a number in order to
output it one digit at a time more easily */

static uintptr_t	reverse(uintptr_t input, int divisor, int *leading_zeros)
{
	uintptr_t	output;

	output = 0;
	*leading_zeros = 0;
	while (input % divisor == 0)
	{
		input /= divisor;
		++*leading_zeros;
	}
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
	int		leading_zeros;

	count = 0;
	if (number == 0)
		return (value_zero('p'));
	write(1, "0x", 2);
	number = reverse(number, 16, &leading_zeros);
	count += leading_zeros + 2;
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
	while (leading_zeros-- > 0)
		write(1, "0", 1);
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

// int	edge_case(int number, int divisor, *count)
// {
// 	if (number == divisor)
// 	{
// 		write(1, "0", 1);
// 		return (1);
// 	}
// 	return (0);
// }


int	value_zero(char type)
{
	if (type == 'p')
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0", 1);
		return (1);
	}
}
