/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:26:53 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/28 11:29:09 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits(long num)
{
	int	count;

	count = 0;
	if (num <= 0)
	{
		count++;
		num = -num;
	}
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}
