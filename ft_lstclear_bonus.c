/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:57:22 by mhoussas          #+#    #+#             */
/*   Updated: 2024/11/06 12:21:28 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aid;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		aid = (*lst)->next;
		ft_lstdelone(*lst, *del);
		*lst = aid;
	}
}
