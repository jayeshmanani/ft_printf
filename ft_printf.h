/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 13:43:14 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/30 17:12:19 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_handle_char(int c);
int	ft_handle_string(char *temp);
int	ft_handle_numbers(int n, char c);
int	ft_handle_pointer(void *p);

/* platform-specific NULL pointer string */
# ifdef __APPLE__
#  define NULL_PTR_STR "0x0"
# else
#  define NULL_PTR_STR "(nil)"
# endif

#endif
