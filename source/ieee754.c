/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ieee754.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:41:34 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/25 19:06:17 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_decompose_f32(t_f32 x, t_u32 *s, t_u32 *e, t_u32 *m)
{
	t_u32	as_u32;

	as_u32 = *(t_u32 *)&x;
	if (s)
		*s = (as_u32 >> 31) & 0x1;
	if (e)
		*e = (as_u32 >> 23) & 0xff;
	if (m)
		*m = as_u32 & 0x7fffff;
}

t_bool	ft_is_nan(t_f32 x)
{
	t_u32	exponent;
	t_u32	mantissa;

	ft_decompose_f32 (x, NULL, &exponent, &mantissa);
	return (exponent == 0xff && mantissa != 0);
}

t_bool	ft_is_inf(t_f32 x)
{
	t_u32	exponent;
	t_u32	mantissa;

	ft_decompose_f32 (x, NULL, &exponent, &mantissa);
	return (exponent == 0xff && mantissa == 0);
}

t_f32	ft_nan32(void)
{
	t_u32	as_u32;

	as_u32 = 0x7fffffff;
	return (*(t_f32 *)&as_u32);
}

t_f32	ft_inf32(void)
{
	t_u32	as_u32;

	as_u32 = 0x7f800000;
	return (*(t_f32 *)&as_u32);
}
