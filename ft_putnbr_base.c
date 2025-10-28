/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:30:15 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/28 11:32:52 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_base_letter(char *base)
{
	int	count;
	int	j;

	count = 0;
	while ((base[count] != 0) && (((base[count] <= 'Z') && (base[count] >= 'A'))
			|| ((base[count] <= 'z') && (base[count] >= 'a'))
			|| ((base[count] <= '9') && (base[count] >= '0'))))
	{
		j = count + 1;
		while (base[j])
		{
			if (base[count] == base[j])
				return (0);
			j++;
		}
		count++;
	}
	return (count);
}

void	convert_numbers_to_base(long nbr, int count, char *base)
{
	char	display;

	if (nbr >= count)
	{
		convert_numbers_to_base(nbr / count, count, base);
	}
	display = base[nbr % count];
	write(1, &display, 1);
}

void	ft_putnbr_base(int nbr, char *base, char c)
{
	int		base_letters;
	long	num;

	if ((c == 'x') || (c == 'X'))
		num = (unsigned int)nbr;
	if (c == 'u')
		num = (unsigned int)nbr;
	base_letters = count_base_letter(base);
	if (base_letters < 2)
		write(1, "", 1);
	else
	{
		if (num < 0)
		{
			num = -num;
		}
		convert_numbers_to_base(num, base_letters, base);
	}
}