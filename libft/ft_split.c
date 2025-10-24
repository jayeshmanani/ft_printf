/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:28:29 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/23 20:48:58 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	word_count(const char *str, char c)
{
	size_t	count;
	int		is_word;

	is_word = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && !is_word)
		{
			is_word = 1;
			count++;
		}
		else if (*str == c)
			is_word = 0;
		str++;
	}
	return (count);
}

void	*free_memory(char **arr, size_t i)
{
	while (i)
		free(arr[--i]);
	free(arr);
	return (NULL);
}

int	fill_data(char **arr, const char *s, size_t words, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s && i <= words)
	{
		len = 0;
		while (*s == c && *s)
			++s;
		while (*(s + len) != c && *(s + len))
			++len;
		if (len)
		{
			arr[i] = ft_substr((char *)(s), 0, len);
			if (!arr[i++])
			{
				free_memory(arr, i);
				return (0);
			}
			s += len;
		}
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	size_t	words;
	char	**arr;

	words = word_count(s, c);
	arr = (char **)ft_calloc((words + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	if (!fill_data(arr, s, words, c))
		return (NULL);
	return (arr);
}

// int	main(void)
// {
// 	char **tab = ft_split("chinimala", ' ');
// }