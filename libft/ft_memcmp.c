/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:06:40 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/18 19:15:23 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	ind;
	char	*temp_s1;
	char	*temp_s2;

	temp_s1 = (char *)s1;
	temp_s2 = (char *)s2;
	ind = 0;
	if (n == 0)
		return (0);
	while (ind < n)
	{
		if (temp_s1[ind] != temp_s2[ind])
			return ((unsigned char)temp_s1[ind] - (unsigned char)temp_s2[ind]);
		ind++;
	}
	return (0);
}

// int main(){
// 	char *s1 = "\xff\0\0\xaa\0\xde\xffMACOSX\xff";
// 	char *s2 = "\xff\0\0\xaa\0\xde\x00MBS";
// 	size_t size = 9;
// 	printf("Result : %d\n", ft_memcmp(s1, s2, size));
// 	printf("Result Prog: %d\n", memcmp(s1, s2, size));
// }
