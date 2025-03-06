/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:38:16 by mmajka            #+#    #+#             */
/*   Updated: 2025/03/06 18:43:13 by mmajka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
// # include <stdlib.h>
// # include <unistd.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *str, ...);
int	int_write(unsigned int number, char type);
int	pointer_write(uintptr_t number);
int	int_conversion(long int number);

#endif