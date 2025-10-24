/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:07:01 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/18 19:18:52 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	int		temp;
	char	*bs;
	char	*ls;

	index = 0;
	bs = (char *)big;
	ls = (char *)little;
	if ('\0' == ls[0])
		return (bs);
	while (bs[index] != 0 && index < len)
	{
		temp = 0;
		if (bs[index] == ls[temp])
		{
			while (ls[temp] != 0 && (bs[index + temp] == ls[temp]) && index
				+ temp < len)
				temp++;
			if ('\0' == ls[temp])
				return (&bs[index]);
		}
		index++;
	}
	return (0);
}
