/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:38:48 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/22 16:39:34 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s64	ft_min(t_s64 a, t_s64 b)
{
	if (a < b)
		return (a);
	return (b);
}

t_f32	ft_minf(t_f32 a, t_f32 b)
{
	if (a < b)
		return (a);
	return (b);
}

t_s64	ft_max(t_s64 a, t_s64 b)
{
	if (a > b)
		return (a);
	return (b);
}

t_f32	ft_maxf(t_f32 a, t_f32 b)
{
	if (a > b)
		return (a);
	return (b);
}
