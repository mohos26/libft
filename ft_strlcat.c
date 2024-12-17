/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:57:10 by mhoussas          #+#    #+#             */
/*   Updated: 2024/11/06 10:37:48 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	len2;
	size_t	aid;
	size_t	i;

	if (!dest && !dstsize)
		return (ft_strlen(src));
	len = 0;
	len2 = ft_strlen(src);
	while (dest[len] && len < dstsize)
		len++;
	if (len == dstsize)
		return (dstsize + len2);
	aid = dstsize - len -1;
	if (aid > len2)
		aid = len2;
	i = 0;
	while (i < aid)
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + aid] = '\0';
	return (len + len2);
}
