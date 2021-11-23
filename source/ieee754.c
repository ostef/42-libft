/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ieee754.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:41:34 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/22 16:50:26 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_is_nan(t_f32 x)
{
	t_u32	uf;
	t_s64	uexp;
	t_s64	mantissa;

	uf = *((t_u32 *)&x);
	uexp = (uf >> 23) & 0xff;
	if (uexp == 0xff)
	{
		mantissa = uf & 0x7fffff;
		if (mantissa == 0)
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	ft_is_inf(t_f32 x)
{
	t_u32	uf;
	t_s64	uexp;
	t_s64	mantissa;

	uf = *((t_u32 *)&x);
	uexp = (uf >> 23) & 0xff;
	if (uexp == 0xff)
	{
		mantissa = uf & 0x7fffff;
		if (mantissa == 0)
			return (TRUE);
		return (FALSE);
	}
	return (FALSE);
}

t_bool	ft_is_pos_inf(t_f32 x)
{
	return (x > 0 && ft_is_inf (x));
}

t_bool	ft_is_neg_inf(t_f32 x)
{
	return (x < 0 && ft_is_inf (x));
}
