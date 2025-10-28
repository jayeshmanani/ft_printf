/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 13:43:14 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/28 11:30:49 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		handle_char(int c);
int		handle_string(char *temp);
int		handle_decimal(int temp);
int		handle_uint(int n);
int		handle_hex(int n, char c);
int		count_digits(long num);
void	ft_putnbr_base(int nbr, char *base, char c);

#endif
