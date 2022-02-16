/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprint_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:39:14 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/23 14:06:29 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s64	ft_sprint_i(t_buff *buff, t_fmt_arg arg, va_list va)
{
	t_s64	i;
	t_int	n;
	t_uint	un;
	t_int	min_width;

	i = 0;
	n = va_arg (va, t_int);
	un = n;
	if (n < 0)
	{
		i += ft_putchar_buff (buff, '-', FALSE);
		un = -n;
	}
	else if ((arg.flags & FLAG_SIGN))
		i += ft_putchar_buff (buff, '+', FALSE);
	else if ((arg.flags & FLAG_SPACE))
		i += ft_putchar_buff (buff, ' ', FALSE);
	min_width = -1;
	if (arg.precision >= 0)
		min_width = arg.precision;
	else if (!(arg.flags & FLAG_LJUSTIFY) && (arg.flags & FLAG_ZPAD))
		min_width = arg.width - i;
	i += ft_putuint_buff (buff, un, min_width, DECIMAL);
	return (i);
}
