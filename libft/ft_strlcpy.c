/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:06:56 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/16 17:08:57 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	len;
	int				count;

	count = 0;
	len = 0;
	while (src[count] != '\0')
		count++;
	if (size <= 0)
		return (count);
	while ((src[len] != '\0') && (len < size - 1))
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (count);
}
