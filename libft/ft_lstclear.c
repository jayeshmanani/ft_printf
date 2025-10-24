/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:09:26 by jmanani           #+#    #+#             */
/*   Updated: 2025/10/23 20:28:09 by jmanani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*lst_cur;

	if (lst && del)
	{
		lst_cur = *lst;
		while (lst_cur != NULL)
		{
			lst_new = lst_cur->next;
			ft_lstdelone(lst_cur, del);
			lst_cur = lst_new;
		}
		*lst = NULL;
	}
}
