/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:06:45 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/23 16:37:21 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp_src;
	char	*temp_dest;
	size_t	i;

	i = 0;
	temp_dest = (char *)dest;
	temp_src = (char *)src;
	if (dest == 0 && src == 0)
		return (NULL);
	if (dest <= src)
	{
		while (i++ < n)
			*temp_dest++ = *temp_src++;
	}
	else if (dest > src)
	{
		temp_dest += n - 1;
		temp_src += n - 1;
		while (i++ < n)
			*temp_dest-- = *temp_src--;
	}
	return (dest);
}
