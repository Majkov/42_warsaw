/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:26:51 by mmajka            #+#    #+#             */
/*   Updated: 2025/02/27 20:32:36 by mmajka           ###   ########.fr       */
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
static int	reverse(uintptr_t input);

int	main()
{
	int number;

	number = 11;
	ft_printf("abc %p\n", &number);
	printf("abc %p\n", &number);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int i;
	
	// write(1, "1\n", 2);
	va_list args;
	va_start(args, str);
	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] == '%')
		{
			++i;
			if (str[i] != '\0')
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

int	check(char type, va_list args)
{
	int	j;
	char *arguments;

	// write(1, "2\n", 2);
	arguments = "cspdiuxX";
	j = 0;
	if(type == '%')
	{
		write(1, "%", 1);
	}
	else
	{
		while(arguments[j] != '\0')
		{
			if(type == arguments[j])
			{
				assignment(arguments[j], args);
				break;
			}
			++j;
		}
	}
	if(arguments[j] == '\0')
	{
		write(1, "ERROR!\n", 7);
		return (1);
	}
	return (0);
}

int assignment(char type, va_list args)
{
	long int	temp;

	// write(1, "3\n", 2);
	if (type == 'd' || type == 'i')
	{
		// write(1, "3.1\n", 4);
		temp = (long int)va_arg(args, int);
		// write(1, "3.1.1\n", 6);
		if (temp < 0)
		{
			// write(1, "3.1.2\n", 6);
			write(1, "-", 1);
			temp *= -1;
		}
		// write(1, "3.1.3\n", 6);
		int_write((unsigned int)temp, type);
	}
	if (type == 'u' || type == 'x' || type == 'X')
	{
		// write(1, "3.2\n", 4);
		int_write(va_arg(args, unsigned int), type);
	}
	if (type == 'c')
	{
		char_write(va_arg(args, int));
	}
	if (type == 's')
	{
		string_write(va_arg(args, char*));
	}
	if (type == 'p')
	{
		// write(1, "1\n", 2);
		pointer_write((uintptr_t)va_arg(args, void*));
	}
	// if(type == 'd') // int
	// if(type == 'i') // int
	// if(type == 'x') // unsigned int
	// if(type == 'X') // unsigned int
	// if(type == 's') // char*
	// if(type == 'c') // int \/ char
	// if(type == 'p') // void*
	// if(type == 'u') // unsigned int
	return(0);
}

//Signed decimal integer
static int	int_write(unsigned int number, char type)
{
	int divisor;
	char digit;

	// write(1, "4\n", 2);
	if (number == 0)
	{
		write(1, "0", 1);
		return (0);
	}
	number = (unsigned int)reverse((uintptr_t)number);
	if (type == 'd' || type == 'i' || type == 'u')
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
		else if (type == 'x')
		{
			digit += 'a' - 10;
		}
		else if (type == 'X')
		{
			digit += 'A' - 10;
		}
		write(1, &digit, 1);
		number /= divisor;
	}
	return (0);
}

static int	reverse(uintptr_t input)
{
	// write(1, "3\n", 2);
	long int output;

	output = 0;

	while (input)
	{
		output = output * 10 + (input % 10);
		input /= 10;
	}
	return (output);
}

// String of characters
static int string_write(char *pointer)
{
	int	i;

	i = 0;
	while (pointer[i] != '\0')
	{
		write(1, &pointer[i], 1);
		++i;
	}
	return (0);
}

// Character
static int	char_write(int input)
{
	char	output;

	output = (char)input;
	write(1, &output, 1);
	return (0);
}

// Pointer address
static int	pointer_write(uintptr_t number)
{
	// write(1, "2\n", 2);
	int divisor;
	char digit;

	// write(1, "4\n", 2);
	if (number == 0)
	{
		write(1, "0", 1);
		return (0);
	}
	printf("%ld\n", number);
	number = reverse(number);
	printf("%ld\n", number);
	// write(1, "4\n", 2);
	// divisor = 16;
	while (number)
	{
		// write(1, "5\n", 2);
		digit = number % 16;
		if (digit < 10)
		{
			digit += '0';
			// write(1, "6\n", 2);
		}
		else
		{
			digit += 'a' - 10;
			// write(1, "7\n", 2);
		}
		write(1, &digit, 1);
		// write(1, "8\n", 2);
		number /= 16;
		// write(1, "9\n", 2);
	}
	return (0);
}

// Unsigned decimal integer
static int	unsignedint_write()
{}

// Unsigned hexadecimal integer
static int	hex_write()
{}
