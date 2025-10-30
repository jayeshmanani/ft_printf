/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:07:23 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/30 15:37:37 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_string(char *temp)
{
	int	count;

	count = 0;
	if (!temp)
		temp = "(null)";
	while (temp[count] != '\0')
	{
		if (handle_char((int)temp[count]) == -1)
			return (-1);
		count++;
	}
	return (count);
}
