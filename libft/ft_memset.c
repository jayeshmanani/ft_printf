/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:06:47 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/23 16:38:38 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ss;
	size_t	i;

	ss = (char *)s;
	i = 0;
	while (i < n)
		ss[i++] = c;
	return (s);
}

// int	main(void)
// {
//     printf("Here");
// 	const int size = 18;

// 	char b1[0xF00];
// 	memset(b1, 'B', 0xF00);
//     int i  = 0;
//     while(i < 18){
//         printf("%d, %c\n", i, b1[i]);
//         i++;
//     }
// 	char *r1 = memset(b1, 'A', size);
//     // char *r2 = memset(b1, 'C', size);
//     // i = 0;
//     // while(i < 18){
//     //     printf("%d, %c, %c\n", i, r1[i], r2[i]);
//     //     i++;
//     // }
//     // memset(b1, 'B', 0xF00);
// 	char *r2 = ft_memset(b1, 'C', size);
//     i = 0;
//     while(i < 18){
//         i++;
//         printf("%d, %c, %c\n", i, r1[i], r2[i]);
//     }
// }
