/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:14:52 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/27 18:24:38 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putuint(unsigned int n)
{
	char	print_char;

	if (n >= 10)
		putuint((n / 10));
	print_char = (n % 10) + 48;
	write(1, &print_char, 1);
}

int	handle_uint(int n)
{
	int				count;
	unsigned int	num;

	count = 0;
	num = (unsigned int)n;
	putuint(num);
	if (num == 0)
		count++;
	while (num > 0)
	{
		count++;
		num /= 10;
	}
	return (count);
}
