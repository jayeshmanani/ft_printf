/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:26:53 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/28 12:28:05 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_digits(long nbr, int count)
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
