/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprint_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:40:10 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/23 14:06:41 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s64	ft_sprint_u(t_buff *buff, t_fmt_arg arg, va_list va)
{
	t_int	min_width;
	t_uint	un;

	un = va_arg (va, t_uint);
	min_width = -1;
	if (arg.precision >= 0)
		min_width = arg.precision;
	else if (!(arg.flags & FLAG_LJUSTIFY) && (arg.flags & FLAG_ZPAD))
		min_width = arg.width;
	return (ft_putuint_buff (buff, un, min_width, DECIMAL));
}
