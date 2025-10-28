/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:16:43 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/28 11:31:45 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(va_list args, const char c)
{
	int	count;

	count = 0;
	if (c == 's')
		count += handle_string(va_arg(args, char *));
	else if ((c == 'd') || (c == 'i'))
		count += handle_decimal(va_arg(args, int));
	else if (c == 'u')
		count += handle_uint(va_arg(args, int));
	else if (c == '%')
		count += write(1, &c, 1);
	else if (c == 'x' | c == 'X')
		count += handle_hex(va_arg(args, int), c);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int	count;

	count = 0;
	va_list(args);
	va_start(args, s);
	while (*s != '\0')
	{
		if (*s != '%')
			count += handle_char(*s);
		else
		{
			if (*(s + 1) == 'c')
				count += handle_char(va_arg(args, int));
			else
				count += print_arg(args, *(s + 1));
			s++;
		}
		s++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	//string
// 	// int i = printf(" NULL %s NULL \n", NULL);
// 	// int j = ft_printf(" NULL %s NULL \n", NULL);

// 	//digit
// 	// int i = printf(" %d ", -1);
// 	// int j = ft_printf(" %d ", -1);

// 	//uint
// 	// int i = printf(" %u \n", -1);
// 	// int j = ft_printf(" %u \n", -1);
	
// 	int i = printf(" %x \n", -1);
// 	int j = ft_printf(" %x \n", -1);
// 	printf("\nI, J : %d, %d \n", i, j);
// }
