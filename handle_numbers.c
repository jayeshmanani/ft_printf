/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:41:40 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/28 13:48:09 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_numbers(int n, char c)
{
	if (c == 'x')
		return (ft_putnbr_base(n, "0123456789abcdef", c));
	else if (c == 'X')
		return (ft_putnbr_base(n, "0123456789ABCDEF", c));
	else if (c == 'd' | c == 'i')
	{
		ft_putnbr_fd(n, 1);
		return (ft_count_digits((long)n, 10));
	}
	ft_putnbr_base(n, "0123456789", 'u');
	return (ft_count_digits((unsigned int)n, 10));
}
