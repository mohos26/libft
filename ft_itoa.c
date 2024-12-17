/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:39:54 by mhoussas          #+#    #+#             */
/*   Updated: 2024/11/06 14:22:38 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_log10(int n)
{
	int	res;

	res = 0;
	while (n > 9)
	{
		n /= 10;
		res++;
	}
	return (res);
}

static int	ft_pow10(int n)
{
	int	res;

	res = 1;
	while (n--)
		res *= 10;
	return (res);
}

static int	ft_sing(int n, int aid)
{
	if (aid)
	{
		if (n < 0)
		{
			if (n == -2147483648)
				return (147483648);
			return (-n);
		}
		return (n);
	}
	else
	{
		if (n < 0)
		{
			if (n == -2147483648)
				return (2);
			return (1);
		}
		return (0);
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	char	*head;
	int		sing;
	int		loop;

	sing = ft_sing(n, 0);
	n = ft_sing(n, 1);
	loop = ft_log10(n) + 1;
	res = (char *) malloc((loop + 1 + sing) * sizeof(char));
	if (!res)
		return (NULL);
	head = res;
	if (sing)
		*res++ = '-';
	if (sing == 2)
		*res++ = '2';
	while (loop)
	{
		*res++ = n / ft_pow10(loop -1) + 48;
		n %= ft_pow10(loop -1);
		loop--;
	}
	*res = '\0';
	return (head);
}
