/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:28:18 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/22 17:12:55 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s64	ft_fputnbr(t_file f, t_s64 n)
{
	char	buff[64];
	t_u64	un;
	t_s64	i;
	t_s64	negative;

	un = n;
	negative = 0;
	if (n < 0)
	{
		ft_fputchar (f, '-');
		negative = 1;
		un = -n;
	}
	i = 0;
	while (un > 0 || i == 0)
	{
		buff[64 - i - 1] = '0' + (un % 10);
		un /= 10;
		i += 1;
	}
	return (negative + ft_fputstrn (f, buff + 64 - i, i));
}

t_s64	ft_putnbr(t_s64 n)
{
	return (ft_fputnbr (STDOUT, n));
}
