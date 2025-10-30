/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:16:43 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/30 17:07:09 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_char(int arg)
{
	char	c;
	int		wr;

	c = (char)arg;
	wr = write(1, &c, 1);
	if (wr == -1)
		return (-1);
	return (wr);
}

int	handle_string(char *temp)
{
	int	i;

	i = 0;
	if (!temp)
		temp = "(null)";
	while (temp[i])
	{
		if (handle_char((int)temp[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

static int	print_arg(va_list args, char c)
{
	if (c == 'c')
		return (handle_char(va_arg(args, int)));
	if (c == 's')
		return (handle_string(va_arg(args, char *)));
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (handle_numbers(va_arg(args, int), c));
	if (c == 'p')
		return (handle_pointer(va_arg(args, void *)));
	if (c == '%')
		return (handle_char('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	int		r;
	va_list	args;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (!*s)
				break ;
			r = print_arg(args, *s++);
		}
		else
			r = handle_char((int)*s++);
		if (r == -1)
			break ;
		count += r;
	}
	va_end(args);
	if (r == -1)
		return (-1);
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	// int	myAge;
// 	// int	i;
// 	// int	j;

// 	// string
// 	// printf("ndfhasbfhlsabhl d alsdnas dnbASDNAL  %s %d  %u ", "Hello", 10, 1)
// 	// int i = printf(" heheh  NULL %s NULL \n", NULL);
// 	// int j = ft_printf(" NULL %s NULL \n", NULL);
// 	// digit
// 	// int i = printf(" %d ", -1);
// 	// int j = ft_printf(" %d ", -1);
// 	// uint
// 	// int i = printf(" %u \n", -1);
// 	// int j = ft_printf(" %u \n", -1);
// 	// X and x (hex)
// 	int i = printf(" %X \n", -1);
// 	int j = ft_printf(" %X \n", -1);
// 	// %p
// 	// myAge = 0;
// 	// i = printf(" %p %p \n", NULL, NULL);
// 	// j = ft_printf(" %p %p \n", NULL, NULL);
// 	printf("\nI, J : %d, %d \n", i, j);
// }
