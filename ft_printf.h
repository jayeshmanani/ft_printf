/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 13:43:14 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/30 15:38:55 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	handle_char(int c);
int	handle_string(char *temp);
int	ft_count_digits(long nbr, int count);
int	ft_putnbr_base(int nbr, char *base, char c);
int	handle_numbers(int n, char c);

#endif
