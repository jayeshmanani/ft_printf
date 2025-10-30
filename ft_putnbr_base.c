/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:30:15 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/30 15:38:56 by jmanani          ###   ########.fr       */
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

int	convert_numbers_to_base(long nbr, int count, char *base)
{
	int ret;

	if (nbr >= count)
	{
		ret = convert_numbers_to_base(nbr / count, count, base);
		if (ret == -1)
			return (-1);
	}
	if (handle_char((int)base[nbr % count]) == -1)
		return (-1);
	return (0);
}

int	ft_putnbr_base(int nbr, char *base, char c)
{
	int		base_letters;
	long	num;
	int		count;
	int		ret;

	count = 0;
	if ((c == 'x') || (c == 'X') || (c == 'u'))
		num = (unsigned int)nbr;
	base_letters = count_base_letter(base);
	if (base_letters < 2)
		return (0);
	else
	{
		if (num < 0)
		{
			num = -num;
			count++;
		}
		ret = convert_numbers_to_base(num, base_letters, base);
		if (ret == -1)
			return (-1);
	}
	return (count + ft_count_digits(num, base_letters));
}

// int	main(void)
// {
// 	printf("Digits are: %c\n", ft_putnbr_base(-1, "0123456789abcdef", 'x'));
// }