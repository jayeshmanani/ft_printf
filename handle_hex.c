/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:39:43 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/28 11:31:27 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_hex(int n, char c)
{
	if (c == 'x')
		ft_putnbr_base(n, "0123456789abcdef", c);
	else if (c == 'X')
		ft_putnbr_base(n, "0123456789ABCDEF", c);
	return (count_digits(n));
}
