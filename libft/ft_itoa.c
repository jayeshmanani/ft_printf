/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:45:00 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/23 20:33:39 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_digits(long int n)
{
	size_t	count;

	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	get_digit(long int n, size_t multiple)
{
	while (multiple-- && n > 0)
		n /= 10;
	return ((n % 10) + '0');
}

char	*write_array(long int num, int is_neg, size_t digits)
{
	size_t	i;
	char	*arr;

	i = 0;
	arr = (char *)ft_calloc(digits + 1, sizeof(char));
	if (!arr)
		return (NULL);
	if (is_neg)
	{
		arr[0] = '-';
		i++;
	}
	while (i < digits)
	{
		arr[i] = get_digit(num, (digits - i - 1));
		i++;
	}
	return (arr);
}

char	*ft_itoa(int n)
{
	size_t		digits;
	int			is_neg;
	long int	num;

	is_neg = 0;
	if (n == 0)
		return (ft_strdup("0"));
	num = n;
	if (n < 0)
	{
		is_neg = 1;
		num = -num;
	}
	digits = count_digits(num);
	if (is_neg)
		digits++;
	return (write_array(num, is_neg, digits));
}

// int main(){
//     printf("FT itoa return (value is : %s\n", ft_itoa(1000034)));
// }