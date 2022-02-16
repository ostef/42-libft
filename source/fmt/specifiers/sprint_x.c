/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprint_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:40:22 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/23 14:06:43 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s64	ft_sprint_x(t_buff *buff, t_fmt_arg arg, va_list va)
{
	t_cstr	base;
	t_int	min_width;
	t_s64	i;
	t_uint	un;

	i = 0;
	un = va_arg (va, t_uint);
	if (arg.flags & FLAG_HASH && un != 0)
	{
		if (arg.specifier == 'X')
			i += ft_putstr_buff (buff, "0X", FALSE);
		else
			i += ft_putstr_buff (buff, "0x", FALSE);
	}
	min_width = -1;
	if (arg.precision >= 0)
		min_width = arg.precision;
	else if (!(arg.flags & FLAG_LJUSTIFY) && (arg.flags & FLAG_ZPAD))
		min_width = arg.width - i;
	base = HEX;
	if (arg.specifier == 'X')
		base = HEX_UPPER;
	i += ft_putuint_buff (buff, un, min_width, base);
	return (i);
}
