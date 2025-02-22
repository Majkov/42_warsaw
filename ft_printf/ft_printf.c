/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:26:51 by mmajka            #+#    #+#             */
/*   Updated: 2025/02/22 18:42:56 by mmajka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *str, ...);
static int	check(char type, va_list args);
static int assignment(char type, va_list args);
static int	int_write(unsigned int number, char type);
static int	string_write();
static int	char_write();
static int	pointer_write();
static int	unsignedint_write();
static int	hex_write();

int	main()
{
	int number;

	number = 11;
	ft_printf("abc %u\n", 17);
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

// String of characters
static int string_write()
{}

// Character
static int	char_write()
{}

// Pointer address
static int	pointer_write()
{}

// Unsigned decimal integer
static int	unsignedint_write()
{}

// Unsigned hexadecimal integer
static int	hex_write()
{}
