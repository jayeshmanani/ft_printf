/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:41:40 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/30 15:38:49 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		rep;

	(void)fd;
	num = n;
	if (num < 0)
	{
		if (handle_char('-') == -1)
			return (-1);
		num = -num;
	}
	if (num >= 10)
	{
		rep = ft_putnbr_fd((int)(num / 10), fd);
		if (rep == -1)
			return (-1);
	}
	if (handle_char((int)((num % 10) + 48)) == -1)
		return (-1);
	return (0);
}

int	handle_numbers(int n, char c)
{
	int	ret;

	if (c == 'x')
		return (ft_putnbr_base(n, "0123456789abcdef", c));
	else if (c == 'X')
		return (ft_putnbr_base(n, "0123456789ABCDEF", c));
	else if (c == 'd' || c == 'i')
	{
		ret = ft_putnbr_fd(n, 1);
		if (ret == -1)
			return (-1);
		return (ft_count_digits((long)n, 10));
	}
	ret = ft_putnbr_base(n, "0123456789", 'u');
	if (ret == -1)
		return (-1);
	return (ft_count_digits((unsigned int)n, 10));
}
