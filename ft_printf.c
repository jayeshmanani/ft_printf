/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:16:43 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/30 15:37:36 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_ulong(unsigned long nbr, size_t count)
{
	int	digs;

	digs = 1;
	if (nbr < count)
		return (digs);
	return (digs + ft_count_digits((long)(nbr / count), count));
}

int	convert_ulong_to_base(unsigned long nbr, size_t count, char *base)
{
	int ret;

	if (nbr >= count)
	{
		ret = convert_ulong_to_base(nbr / count, count, base);
		if (ret == -1)
			return (-1);
	}
	if (handle_char((int)base[nbr % count]) == -1)
		return (-1);
	return (0);
}

int	handle_pointer(void *num)
{
	unsigned long	nbr;
	int				count;
	int				wr;

	count = 0;
	if (!num)
	{
		wr = write(1, "(nil)", 5);
		if (wr == -1)
			return (-1);
		return (wr);
	}
	nbr = (unsigned long)num;
	wr = write(1, "0x", 2);
	if (wr == -1)
		return (-1);
	count += wr;
	if (convert_ulong_to_base(nbr, 16, "0123456789abcdef") == -1)
		return (-1);
	return (count + ft_count_ulong(nbr, 16));
}

int	print_arg(va_list args, const char c)
{
	int	count;
	count = 0;
	if (c == 's')
		return (handle_string(va_arg(args, char *)));
	else if ((c == 'd') || (c == 'i'))
		return (handle_numbers(va_arg(args, int), c));
	else if (c == 'u')
		return (handle_numbers(va_arg(args, unsigned int), c));
	else if (c == '%')
	{
		int wr = write(1, &c, 1);
		if (wr == -1)
			return (-1);
		return (wr);
	}
	else if (c == 'x' || c == 'X')
		return (handle_numbers(va_arg(args, int), c));
	else if (c == 'p')
		return (handle_pointer(va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, s);
	while (*s != '\0')
	{
		if (*s != '%')
		{
			int ret = handle_char((int)*s);
			if (ret == -1)
			{
				va_end(args);
				return (-1);
			}
			count += ret;
		}
		else
		{
			if (*(s + 1) == 'c')
			{
				int ret = handle_char(va_arg(args, int));
				if (ret == -1)
				{
					va_end(args);
					return (-1);
				}
				count += ret;
			}
			else
			{
				int ret = print_arg(args, *(s + 1));
				if (ret == -1)
				{
					va_end(args);
					return (-1);
				}
				count += ret;
			}
			s++;
		}
		s++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	// int	myAge;
// 	// int	i;
// 	// int	j;

// 	// string
// 	// printf("ndfhasbfhlsabhl d alsdnas dnbASDNAL  %s %d  %u ", "Hello", 10, 1)
// 	// int i = printf(" heheh  NULL %s NULL \n", NULL);
// 	// int j = ft_printf(" NULL %s NULL \n", NULL);
// 	// digit
// 	// int i = printf(" %d ", -1);
// 	// int j = ft_printf(" %d ", -1);
// 	// uint
// 	// int i = printf(" %u \n", -1);
// 	// int j = ft_printf(" %u \n", -1);
// 	// X and x (hex)
// 	int i = printf(" %X \n", -1);
// 	int j = ft_printf(" %X \n", -1);
// 	// %p
// 	// myAge = 0;
// 	// i = printf(" %p %p \n", NULL, NULL);
// 	// j = ft_printf(" %p %p \n", NULL, NULL);
// 	printf("\nI, J : %d, %d \n", i, j);
// }
