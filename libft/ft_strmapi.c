/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:32:57 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/18 15:39:00 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*arr;

	i = 0;
	len = ft_strlen(s);
	if (len)
	{
		arr = (char *)ft_calloc(len + 1, sizeof(char));
		if (!arr)
			return (NULL);
	}
	else
		return (ft_strdup(""));
	while (s[i])
	{
		arr[i] = f(i, s[i]);
		i++;
	}
	return (arr);
}
