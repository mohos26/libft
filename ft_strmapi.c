/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:15:52 by mhoussas          #+#    #+#             */
/*   Updated: 2024/11/06 14:29:16 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*head;
	char	*res;
	int		i;

	if (!s || !f)
		return (NULL);
	res = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	head = res;
	i = 0;
	while (s[i])
	{
		*res++ = f(i, s[i]);
		i++;
	}
	*res = '\0';
	return (head);
}
