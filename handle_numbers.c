/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:41:40 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/30 16:53:46 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* recursive printing avoids an explicit buffer and writes digits
 * from most-significant to least-significant using handle_char
 */
static int	print_unsigned_rec(unsigned long long n, int base,
		const char *digits)
{
	int	cnt;
	int	r;

	cnt = 0;
	if (n >= (unsigned)base)
	{
		cnt = print_unsigned_rec(n / base, base, digits);
		if (cnt == -1)
			return (-1);
	}
	r = handle_char((int)digits[n % base]);
	if (r == -1)
		return (-1);
	return (cnt + r);
}

static int	print_unsigned(unsigned long long n, int base, const char *digits)
{
	if (n == 0)
	{
		if (handle_char('0') == -1)
			return (-1);
		return (1);
	}
	return (print_unsigned_rec(n, base, digits));
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
		return (handle_string("(nil)"));
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	addr = (unsigned long long)p;
	r = print_unsigned(addr, 16, "0123456789abcdef");
	if (r == -1)
		return (-1);
	return (2 + r);
}
