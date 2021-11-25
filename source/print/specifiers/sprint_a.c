/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprint_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:04:19 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/25 19:40:10 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_s64	ft_putsign_buff(t_buff *buff, t_u32 s, t_fmt_flags flags)
{
	if (s)
		return (ft_putchar_buff (buff, '-', FALSE));
	else if ((flags & FLAG_SIGN))
		return (ft_putchar_buff (buff, '+', FALSE));
	else if ((flags & FLAG_SPACE))
		return (ft_putchar_buff (buff, ' ', FALSE));
	return (0);
}

static t_s64	ft_putint_buff(t_buff *buff, t_s32 n, t_cstr base)
{
	t_s64	i;
	t_u64	un;

	i = 0;
	i += ft_putsign_buff (buff, n < 0, FLAG_SIGN);
	if (n < 0)
		un = -n;
	else
		un = n;
	i += ft_putuint_buff (buff, un, -1, base);
	return (i);
}

t_s64	ft_sprint_a(t_buff *buff, t_fmt_arg arg, va_list va)
{
	t_s64	i;
	t_f32	x;
	t_u32	exponent;
	t_u32	mantissa;

	x = (t_f32)va_arg (va, t_f64);
	ft_decompose_f32 (x, NULL, &exponent, &mantissa);
	i = 0;
	if (ft_is_nan (x))
		return (ft_putstr_buff (buff, "NaN", FALSE));
	i += ft_putsign_buff (buff, x < 0, arg.flags);
	if (ft_is_inf (x))
		return (i + ft_putstr_buff (buff, "Inf", FALSE));
	if (exponent == 0)
		i += ft_putstr_buff (buff, "0x0.", FALSE);
	else
		i += ft_putstr_buff (buff, "0x1.", FALSE);
	i += ft_putuint_buff (buff, mantissa, -1, HEX);
	i += ft_putchar_buff (buff, 'p', FALSE);
	if (exponent == 0)
		i += ft_putchar_buff (buff, '1', FALSE);
	else
		i += ft_putint_buff (buff, (t_s32)exponent - F32_EXP_BIAS, HEX);
	return (i);
}
