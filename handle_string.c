/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:07:23 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/27 13:13:59 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_string(char *temp)
{
	int	count;

	count = 0;
	if (!temp)
		temp = "(null)";
	count += ft_strlen(temp);
	ft_putstr_fd(temp, 1);
	return (count);
}
