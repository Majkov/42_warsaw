/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:26:51 by mmajka            #+#    #+#             */
/*   Updated: 2025/03/03 20:25:51 by mmajka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

int	ft_printf(const char *str, ...);
static int	check(char type, va_list args);
static int assignment(char type, va_list args);
static int	int_write(unsigned int number, char type);
static int	string_write(char *pointer);
static int	char_write(int input);
static int	pointer_write(uintptr_t number);
static int	unsignedint_write();
static int	hex_write();
static uintptr_t reverse(uintptr_t input, int divisor);

int	main()
{
	int number;
	// cspdiuxX
	number = -156719;
	ft_printf("abc %p\n", &number);
	printf("%p\n", &number);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	va_start(args, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			++i;
			if (str[i] != '\0')
				check(str[i], args);
		}
		else
		{
			write(1, &str[i], 1);
			++count;
		}
		++i;
	}
	return (count);
}

int	check(char type, va_list args)
{
	int	j;
	char *arguments;
	int		count;

	count = 0;
	arguments = "cspdiuxX";
	j = 0;
	if (type == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else
	{
		while (arguments[j] != '\0')
		{
			if (type == arguments[j])
			{
				count = assignment(arguments[j], args);
				return (count);
			}
			++j;
		}
	}
	write(1, "ERROR!\n", 7);
	return (-1);
}

/* if(type == 'd') int
if(type == 'i') int
if(type == 'x') unsigned int
if(type == 'X') unsigned int
if(type == 's') char*
if(type == 'c') int \/ char
if(type == 'p') void*
if(type == 'u') unsigned int */
int assignment(char type, va_list args)
{
	long int	temp;
	int			count;

	count = 0;
	if (type == 'd' || type == 'i')
	{
		temp = (long int)va_arg(args, int);
		if (temp < 0)
		{
			write(1, "-", 1);
			temp *= -1;
		}
		int_write((unsigned int)temp, type);
	}
	else if (type == 'x' || type == 'X')
		type -= 23;
	if (type == 'u' || type == 'a' || type == 'A')
		count += int_write(va_arg(args, unsigned int), type);
	if (type == 'c')
		count += char_write(va_arg(args, int));
	if (type == 's')
		count += string_write(va_arg(args, char*));
	if (type == 'p')
		count += pointer_write((uintptr_t)va_arg(args, void*));
	return(count);
}

/* Used for d, i, u, x, X */
static int	int_write(unsigned int number, char type)
{
	int		divisor;
	char	digit;
	int		count;

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
		if (digit < 10)
			digit += '0';
		else
			digit += type - 10;
		write(1, &digit, 1);
		number /= divisor;
		++count;
	}
	return (count - 1);
}
/* Is used to reverse a number in order to output it one digit at a time more easily */
static uintptr_t	reverse(uintptr_t input, int divisor)
{
	long int output;

	output = 0;
	while (input)
	{
		output = output * divisor + (input % divisor);
		input /= divisor;
	}
	return (output);
}

/* String of characters */
static int string_write(char *pointer)
{
	int	count;

	count = 0;
	while (pointer[count] != '\0')
	{
		write(1, &pointer[count], 1);
		++count;
	}
	return (count - 1);
}

/* Character */
static int	char_write(int input)
{
	char	output;

	output = (char)input;
	write(1, &output, 1);
	return (1);
}

/* Pointer address */
static int	pointer_write(uintptr_t number)
{
	int divisor;
	char digit;
	int	count;

	count = 0;
	if (number == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	number = reverse(number, 16);
	write(1, "0x", 2);
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
	return (count + 1);
}
