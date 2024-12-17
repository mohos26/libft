/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 08:47:43 by mhoussas          #+#    #+#             */
/*   Updated: 2024/11/08 08:45:29 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_log10(int n)
{
	int	res;

	res = 0;
	while (n > 9)
	{
		res += 1;
		n /= 10;
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

void	ft_putnbr_fd(int n, int fd)
{
	int	loop;
	int	pow;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			ft_putchar_fd('2', fd);
			n = -147483648;
		}
		n *= -1;
	}
	loop = ft_log10(n);
	while (loop + 1)
	{
		pow = ft_pow10(loop);
		ft_putchar_fd(n / pow + 48, fd);
		n %= pow;
		loop--;
	}
}
