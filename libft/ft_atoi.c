/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:50:22 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/24 13:49:22 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	calc_num(const char *str, int index)
{
	int	num;

	num = 0;
	while (str[index] != 0 && str[index] >= '0' && str[index] <= '9')
	{
		num *= 10;
		num += str[index] - '0';
		index++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int		num;
	int		is_neg;
	size_t	index;

	is_neg = 0;
	num = 0;
	index = 0;
	while ((str[index] != 0) && ((str[index] < 14 && str[index] > 8)
			|| (str[index] == 32)))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			is_neg = 1;
		index++;
	}
	num = calc_num(str, index);
	if (is_neg)
		return (-num);
	return (num);
}
