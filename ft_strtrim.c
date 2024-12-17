/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:39:25 by mhoussas          #+#    #+#             */
/*   Updated: 2024/11/01 10:22:49 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	search(char c, const char *s)
{
	while (*s)
	{
		if (*s++ == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*aid;
	char	*res;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	aid = (char *)s1;
	start = 0;
	while (search(aid[start], set))
		start++;
	end = ft_strlen(aid) - 1;
	while (end > start && search(aid[end], set))
		end--;
	if (start > end)
		return (ft_strdup(""));
	res = (char *)malloc((end - start + 2) * sizeof(char));
	if (!res)
		return (NULL);
	ft_memcpy(res, aid + start, end - start + 1);
	res[end - start + 1] = '\0';
	return (res);
}
