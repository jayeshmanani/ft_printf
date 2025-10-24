/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:06:59 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/15 18:05:09 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	index;

	index = 0;
	while (((s1[index] != 0) || s2[index] != 0) && (index < n))
	{
		if (s1[index] != s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return (0);
}

// int	main(void)
// {
//     printf("this is : %d\n", strncmp("abcdef", "abc\375xx", 5));
//     printf("this is : %d\n", ft_strncmp("abcdef", "abc\375xx", 5));
// }