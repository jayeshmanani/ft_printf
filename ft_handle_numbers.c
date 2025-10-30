/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:41:40 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/30 17:12:17 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_unsigned_rec(unsigned long long n, int base,
		const char *digits)
{
	int	cnt;
	int	r;

	cnt = 0;
	if (n == 0)
		return (ft_handle_char('0'));
	if (n >= (unsigned)base)
	{
		cnt = print_unsigned_rec(n / base, base, digits);
		if (cnt == -1)
			return (-1);
	}
	r = ft_handle_char((int)digits[n % base]);
	if (r == -1)
		return (-1);
	return (cnt + r);
}

static int	print_signed(long num)
{
	unsigned long long	un;
	int					cnt;
	int					r;

	cnt = 0;
	if (num < 0)
	{
		r = ft_handle_char('-');
		if (r == -1)
			return (-1);
		cnt += r;
		un = (unsigned long long)(-num);
	}
	else
		un = (unsigned long long)num;
	r = print_unsigned_rec(un, 10, "0123456789");
	if (r == -1)
		return (-1);
	return (cnt + r);
}

int	ft_handle_numbers(int n, char c)
{
	if (c == 'd' || c == 'i')
		return (print_signed((long)n));
	if (c == 'u')
		return (print_unsigned_rec((unsigned int)n, 10, "0123456789"));
	if (c == 'x')
		return (print_unsigned_rec((unsigned int)n, 16, "0123456789abcdef"));
	if (c == 'X')
		return (print_unsigned_rec((unsigned int)n, 16, "0123456789ABCDEF"));
	return (0);
}

int	ft_handle_pointer(void *p)
{
	unsigned long long	addr;
	int					r;

	if (!p)
		return (ft_handle_string(NULL_PTR_STR));
	if (write(1, "0x", 2) == -1)
		return (-1);
	addr = (unsigned long long)p;
	r = print_unsigned_rec(addr, 16, "0123456789abcdef");
	if (r == -1)
		return (-1);
	return (2 + r);
}
