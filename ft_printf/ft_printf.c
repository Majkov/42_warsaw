/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:26:51 by mmajka            #+#    #+#             */
/*   Updated: 2025/02/21 21:50:38 by mmajka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	int i;
	
	va_list args;
	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] == '%')
		{
			++i;
			check(str[i], args);
		}
		else
		{
			write(1, &str[i], 1);
		}
		++i;
	}
	return (0);
}

int	check(char placeholder, va_list args)
{
	int	j;
	char *arguments;

	arguments = "cspdiuxX";
	j = 0;
	if(placeholder == '%')
	{
		write(1, "%", 1);
	}
	else
	{
		while(arguments[j] != '\0')
		{
			if(placeholder == arguments[j])
			{
				assignment();
				break;
			}
			++j;
		}
	}
	if(arguments[j] == '\0')
	{
		printf("ERROR!\n");
		return (1);
	}
	return (0);
}

int assignment(char placeholder, va_list args)
{
	if(placeholder == 'd') // int
	if(placeholder == 'i') // int
	if(placeholder == 's') // char*
	if(placeholder == 'c') // int \/ char
	if(placeholder == 'p') // void*
	if(placeholder == 'u') // unsigned int
	if(placeholder == 'x') // unsigned int
	if(placeholder == 'X') // unsigned int
	return();
}

//Signed decimal integer
static int	int_write(unsigned int number, char placeholder)
{
	int divisor;
	char digit;

	if (number == 0)
	{
		write(1, "0", 1);
		return (0);
	}
	if (placeholder == 'd' || placeholder == 'i' || placeholder == 'u')
		divisor = 10;
	else
		divisor = 16;
	while (number)
	{
		digit = number % divisor;
		if (digit < 10)
		{
			digit += '0';
		}
		else if (placeholder == 'x')
		{
			digit += 'a';
		}
		else if (placeholder == 'X')
		{
			digit += 'A';
		}
	}
	
}

// String of characters
static int string_write();

// Character
static int	char_write();

// Pointer address
static int	pointer_write();

// Unsigned decimal integer
static int	unsignedint_write();

// Unsigned hexadecimal integer
static int	hex_write();
