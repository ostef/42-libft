/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprint_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:39:50 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/23 14:06:37 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s64	ft_sprint_p(t_buff *buff, t_fmt_arg arg, va_list va)
{
	t_int	min_width;
	t_u64	un;
	t_s64	i;

	un = va_arg (va, t_u64);
	i = ft_putstr_buff (buff, "0x", FALSE);
	min_width = -1;
	if (arg.precision >= 0)
		min_width = arg.precision;
	else if (!(arg.flags & FLAG_LJUSTIFY) && (arg.flags & FLAG_ZPAD))
		min_width = arg.width - i;
	i += ft_putuint_buff (buff, un, min_width, HEX);
	return (i);
}
