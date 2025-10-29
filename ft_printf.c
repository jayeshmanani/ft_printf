/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:16:43 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/29 14:30:18 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_ulong(unsigned long nbr, size_t count)
{
	int	digs;

	digs = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		digs++;
	}
	if (nbr < count)
		return (digs);
	return (digs + ft_count_digits(nbr / count, count));
}

void	convert_ulong_to_base(unsigned long nbr, size_t count, char *base)
{
	if (nbr >= count)
		convert_ulong_to_base(nbr / count, count, base);
	write(1, &(base[nbr % count]), 1);
}

int	handle_pointer(void *num)
{
	unsigned long	nbr;
	int				count;

	count = 0;
	if (!num)
		return (write(1, "(nil)", 5));
	nbr = (unsigned long)num;
	count += write(1, "0x", 2);
	convert_ulong_to_base(nbr, 16, "0123456789abcdef");
	return (count + ft_count_ulong(nbr, 16));
}

int	print_arg(va_list args, const char c)
{
	int	count;

	count = 0;
	if (c == 's')
		count += handle_string(va_arg(args, char *));
	else if ((c == 'd') || (c == 'i'))
		count += handle_numbers(va_arg(args, int), c);
	else if (c == 'u')
		count += handle_numbers(va_arg(args, int), c);
	else if (c == '%')
		count += write(1, &c, 1);
	else if (c == 'x' | c == 'X')
		count += handle_numbers(va_arg(args, int), c);
	else if (c == 'p')
		count += handle_pointer(va_arg(args, void *));
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
// 	int	myAge;
// 	int	i;
// 	int	j;

// 	// string
// 	// int i = printf(" heheh  NULL %s NULL \n", NULL);
// 	// int j = ft_printf(" NULL %s NULL \n", NULL);
// 	// digit
// 	// int i = printf(" %d ", -1);
// 	// int j = ft_printf(" %d ", -1);
// 	// uint
// 	// int i = printf(" %u \n", -1);
// 	// int j = ft_printf(" %u \n", -1);
// 	// X and x (hex)
// 	// int i = printf(" %x \n", -1);
// 	// int j = ft_printf(" %x \n", -1);
// 	// %p
// 	myAge = 0;
// 	i = printf(" %p %p \n", NULL, NULL);
// 	j = ft_printf(" %p %p \n", NULL, NULL);
// 	printf("\nI, J : %d, %d \n", i, j);
// }
