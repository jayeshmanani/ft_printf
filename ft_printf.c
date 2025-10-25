/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:16:43 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/25 18:04:29 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(va_list args, const char c)
{
	int		count;
	char	*temp;
	int		inp;

	count = 0;
	if (c == 'c')
	{
		// ft_putchar_fd(va_arg(args, int), 1);
		// count++;
		inp = va_arg(args, int);
		if (inp)
			count += handle_char(inp);
	}
	else if (c == 's')
	{
		temp = va_arg(args, char *);
		if (!temp)
			return (count);
		count += ft_strlen(temp);
		ft_putstr_fd(temp, 1);
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int	count;

	// char	c;
	count = 0;
	va_list(args);
	va_start(args, s);
	while (*s)
	{
		if (*s != '%')
			ft_putchar_fd(*s, 1);
		else
		{
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
// 	ft_printf("String: %s\n", "HELLO");
// }

