/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:16:43 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/27 11:10:05 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(va_list args, const char c)
{
	int		count;
	char	*temp;

	count = 0;
	if (c == 's')
	{
		temp = va_arg(args, char *);
		if (!temp)
			return (count);
		count += ft_strlen(temp);
		ft_putstr_fd(temp, 1);
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int	count;

	count = 0;
	va_list(args);
	va_start(args, s);
	while (*s != '\0')
	{
		if (*s != '%')
			count += handle_char(*s);
		else
		{
			if (*(s + 1) == 'c')
				count += handle_char(va_arg(args, int));
			else
				count += print_arg(args, *(s + 1));
			s++;
		}
		s++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	// ft_printf("String: %s\n", "HELLO");
// 	int i = printf("%c", '0');
// 	int j = ft_printf("%c", '0');
// 	printf("\nI, J : %d, %d \n", i, j);
	
// }
