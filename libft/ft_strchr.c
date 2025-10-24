/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:06:49 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/23 21:29:44 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	ind;

	ind = 0;
	while (s[ind] != 0)
	{
		if (s[ind] == (char)c)
			return ((char *)(s + ind));
		ind++;
	}
	if (s[ind] == 0 && (char)c != 0)
		return (NULL);
	return ((char *)(s + ind));
}
