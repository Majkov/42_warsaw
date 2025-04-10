/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:26:51 by mmajka            #+#    #+#             */
/*   Updated: 2025/04/10 16:34:37 by mmajka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include "libftprintf.h"

int					ft_printf(const char *str, ...);
static int			check(char type, va_list args);
static int			assignment(char type, va_list args);
static int			string_write(char *pointer);
static int			char_write(int input);

// int main()
// {
// 	// void *p = 16;
// 	ft_printf(" %u ", -1);
// 	// printf(" %i ", INT_MAX);
// 	return (0);
// }

/* 1 */
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
				count += check(str[i], args);
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

/* 2 */
int	check(char type, va_list args)
{
	int		j;
	int		count;
	char	*arguments;

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
				return (assignment(arguments[j], args));
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
/* 3 */
int	assignment(char type, va_list args)
{
	int			count;

	count = 0;
	if (type == 'd' || type == 'i')
		count += int_conversion((long int)va_arg(args, int));
	else if (type == 'x' || type == 'X')
		type -= 23;
	if (type == 'u' || type == 'a' || type == 'A')
		count += int_write(va_arg(args, unsigned int), type);
	if (type == 'c')
		count += char_write(va_arg(args, int));
	if (type == 's')
		count += string_write(va_arg(args, char *));
	if (type == 'p')
		count += pointer_write((uintptr_t)va_arg(args, void *));
	return (count);
}

/* Is used to reverse a number in order to
output it one digit at a time more easily */

/* String of characters */
static int	string_write(char *pointer)
{
	int	count;

	count = 0;
	while (pointer[count] != '\0')
	{
		write(1, &pointer[count], 1);
		++count;
	}
	return (count);
}

/* Character */
static int	char_write(int input)
{
	char	output;

	output = (char)input;
	write(1, &output, 1);
	return (1);
}
