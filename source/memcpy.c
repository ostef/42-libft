/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:28:10 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/22 16:28:10 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, t_s64 n)
{
	t_s64	i;

	i = 0;
	while (i < n)
	{
		((t_u8 *)dst)[i] = ((t_u8 *)src)[i];
		i += 1;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, t_s64 n)
{
	t_s64	i;

	if (dst > src)
	{
		i = n - 1;
		while (i >= 0)
		{
			((t_u8 *)dst)[i] = ((t_u8 *)src)[i];
			i -= 1;
		}
	}
	else if (dst < src)
	{
		i = 0;
		while (i < n)
		{
			((t_u8 *)dst)[i] = ((t_u8 *)src)[i];
			i += 1;
		}
	}
	return (dst);
}
