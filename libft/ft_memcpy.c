/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:06:43 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/23 16:19:12 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*temp_dest;
	char	*temp_src;
	size_t	i;

	i = 0;
	if (dest == 0 && src == 0)
		return (NULL);
	temp_dest = (char *)dest;
	temp_src = (char *)src;
	while (i < n)
	{
		*temp_dest++ = *temp_src++;
		i++;
	}
	return (dest);
}
