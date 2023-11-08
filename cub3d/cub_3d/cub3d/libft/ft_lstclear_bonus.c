/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:19:30 by oelboukh          #+#    #+#             */
/*   Updated: 2022/11/03 13:00:57 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*n;

	if (!lst || !del)
		return ;
	n = *lst;
	while (n != NULL)
	{
		n = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = n;
	}
	*lst = NULL;
}
