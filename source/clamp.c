/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:39:40 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/22 16:40:35 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s64	ft_clamp(t_s64 x, t_s64 min, t_s64 max)
{
	if (x > max)
		x = max;
	if (x < min)
		x = min;
	return (x);
}

t_f32	ft_clampf(t_f32 x, t_f32 min, t_f32 max)
{
	if (x > max)
		x = max;
	if (x < min)
		x = min;
	return (x);
}
