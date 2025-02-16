/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:26:51 by mmajka            #+#    #+#             */
/*   Updated: 2025/02/16 14:13:39 by mmajka           ###   ########.fr       */
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
	while(arguments[j] != '\0')
	{
		if(placeholder == '%')
		{
			..;
		}
		else if(placeholder == arguments[j])
		{
			assignment();
			break;
		}
		else
		{
			..;
		}
		++j;
	}
	return ();
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