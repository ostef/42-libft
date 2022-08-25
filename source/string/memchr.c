/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:28:04 by soumanso          #+#    #+#             */
/*   Updated: 2022/08/25 10:11:42 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const void	*ft_memchr(const void *p, t_u8 c, t_s64 n)
{
	t_s64	i;

	i = 0;
	while (i < n && ((const t_u8 *)p)[i] != c)
		i += 1;
	if (i == n)
		return (NULL);
	return ((const t_u8 *)p + i);
}

const void	*ft_memrchr(const void *p, t_u8 c, t_s64 n)
{
	t_s64	i;

	i = n - 1;
	while (i >= 0 && ((const t_u8 *)p)[i] != c)
		i -= 1;
	if (i == -1)
		return (NULL);
	return ((const t_u8 *)p + i);
}
