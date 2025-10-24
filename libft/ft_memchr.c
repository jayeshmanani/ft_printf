/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:06:37 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/23 16:16:34 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*temp_s;
	size_t	i;

	i = 0;
	temp_s = (char *)s;
	while (i < n)
	{
		if (*temp_s == (char)c)
			return ((void *)(temp_s));
		temp_s++;
		i++;
	}
	return (NULL);
}
