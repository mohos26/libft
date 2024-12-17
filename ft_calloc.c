/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:05:41 by mhoussas          #+#    #+#             */
/*   Updated: 2024/11/06 12:24:54 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	size_alloc;

	if (count != 0 && size > ((size_t)-1) / count)
		return (NULL);
	size_alloc = count * size;
	ptr = malloc(size_alloc);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size_alloc);
	return (ptr);
}
