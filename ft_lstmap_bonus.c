/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:34:32 by mhoussas          #+#    #+#             */
/*   Updated: 2024/11/08 10:57:16 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*aid;

	if (!f || !lst || !f || !del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		aid = ft_lstnew(f(lst->content));
		if (!aid)
		{
			ft_lstclear(&aid, del);
			return (NULL);
		}
		ft_lstadd_back(&res, aid);
		lst = lst->next;
	}
	return (res);
}
