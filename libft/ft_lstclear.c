/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:47:12 by acetin            #+#    #+#             */
/*   Updated: 2022/02/11 12:50:44 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list;

	if (!lst)
		return ;
	while (*lst)
	{
		list = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = list;
	}
}
