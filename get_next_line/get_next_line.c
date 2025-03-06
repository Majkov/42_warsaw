/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajka <mmajka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:52:05 by mmajka            #+#    #+#             */
/*   Updated: 2025/03/06 20:40:12 by mmajka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
RETURN VALUES OF "READ":
0 EOF
-1 ERROR
else works fine, returns the number of bytes successfully read

Because you will have to read files in get_next_line(),
add this option to your compiler call: -D BUFFER_SIZE=n
*/

char	*get_next_line(int fd)
{
	char	*str;

	
	return (str);
}
