/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:41:40 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/30 16:42:42 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_unsigned(unsigned long long n, int base, const char *digits)
{
	char	buf[65];
	int		i;
	int		wr;
	int		r;

	i = 0;
	if (n == 0)
		return (handle_char('0'));
	while (n)
	{
		buf[i++] = digits[n % base];
		n /= base;
	}
	wr = 0;
	while (i--)
	{
		r = handle_char((int)buf[i]);
		if (r == -1)
			return (-1);
		wr += r;
	}
	return (wr);
}

static int	print_signed(long num)
{
	unsigned long long	un;
	int					cnt;
	int					r;

	cnt = 0;
	if (num < 0)
	{
		r = handle_char('-');
		if (r == -1)
			return (-1);
		cnt += r;
		un = (unsigned long long)(-num);
	}
	else
		un = (unsigned long long)num;
	r = print_unsigned(un, 10, "0123456789");
	if (r == -1)
		return (-1);
	return (cnt + r);
}

int	handle_numbers(int n, char c)
{
	if (c == 'd' || c == 'i')
		return (print_signed((long)n));
	if (c == 'u')
		return (print_unsigned((unsigned int)n, 10, "0123456789"));
	if (c == 'x')
		return (print_unsigned((unsigned int)n, 16, "0123456789abcdef"));
	if (c == 'X')
		return (print_unsigned((unsigned int)n, 16, "0123456789ABCDEF"));
	return (0);
}

int	handle_pointer(void *p)
{
	unsigned long long	addr;
	int					r;

	if (!p)
	{
		r = write(1, "(nil)", 5);
		if (r == -1)
			return (-1);
		return (r);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	addr = (unsigned long long)p;
	r = print_unsigned(addr, 16, "0123456789abcdef");
	if (r == -1)
		return (-1);
	return (2 + r);
}
