/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:28:06 by soumanso          #+#    #+#             */
/*   Updated: 2022/08/25 10:12:04 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_int	ft_memcmp(const void *p1, const void *p2, t_s64 n)
{
	t_s64	i;

	i = 0;
	while (i < n && ((const t_u8 *)p1)[i] == ((const t_u8 *)p2)[i])
		i += 1;
	if (i == n)
		return (0);
	return (((const t_u8 *)p1)[i] - ((const t_u8 *)p2)[i]);
}

t_bool	ft_memequ(const void *p1, const void *p2, t_s64 n)
{
	return (ft_memcmp (p1, p2, n) == 0);
}
