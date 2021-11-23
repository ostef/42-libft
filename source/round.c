/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:55:57 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/22 16:59:10 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_f32	ft_floor(t_f32 x)
{
	t_s64	i;
	t_s64	diff;

	i = (t_s64)ft_round (x);
	diff = x - i;
	return ((t_f32)(i - (diff < 0)));
}

t_f32	ft_round(t_f32 x)
{
	return ((t_f32)(t_s64)(x + ft_signf (x) * 0.5f));
}

t_f32	ft_ceil(t_f32 x)
{
	t_s64	i;
	t_s64	diff;

	i = (t_s64)ft_round (x);
	diff = i - x;
	return ((t_f32)(i + (diff < 0)));
}
