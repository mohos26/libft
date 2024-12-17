/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:16:07 by mhoussas          #+#    #+#             */
/*   Updated: 2024/11/08 17:30:55 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*aid;
	unsigned char	*aid2;

	aid = (unsigned char *) s1;
	aid2 = (unsigned char *) s2;
	while (n && *aid == *aid2)
	{
		n--;
		aid++;
		aid2++;
	}
	if (!n)
		return (0);
	return (*aid - *aid2);
}
