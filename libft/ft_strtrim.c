/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:40:48 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/18 19:13:50 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*create_new_str(int i, int j, char const *s1)
{
	int		len;
	char	*new_str;

	len = j - i + 1;
	if (len <= 0)
		return (ft_strdup(""));
	new_str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!new_str)
		return (0);
	return (ft_memcpy(new_str, &s1[i], len));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	str_len;

	i = 0;
	str_len = ft_strlen(s1);
	j = str_len - 1;
	if (!str_len)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[i]) != 0)
		i++;
	while (ft_strchr(set, s1[j]) != 0)
		j--;
	return (create_new_str(i, j, s1));
}

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;
// 	char	*ret;

// 	s1 = "  \t \t \n   \n\n\n\t";
// 	s2 = "";
// 	ret = ft_strtrim(s1, " \n\t");
// 	printf("Op: %s\n", ret);
// 	printf("Op: %s\n", s2);
// }
