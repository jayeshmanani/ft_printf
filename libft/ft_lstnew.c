/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:57:21 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/23 16:09:45 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_mem;

	new_mem = (t_list *)malloc(sizeof(t_list));
	if (!new_mem)
		return (NULL);
	new_mem->content = content;
	new_mem->next = NULL;
	return (new_mem);
}
