/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:58:26 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/23 14:06:50 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_s64	ft_get_len(t_buff buff, t_fmt_arg arg, va_list va)
{
	va_list	va2;
	t_s64	len;

	buff.data = NULL;
	va_copy (va2, va);
	len = (*arg.func)(&buff, arg, va2);
	va_end (va2);
	return (len);
}

t_s64	ft_next_arg(t_cstr fmt, t_buff *buff, va_list va)
{
	t_fmt_arg	arg;
	t_s64		len;
	t_s64		i;

	i = ft_read_arg (fmt, &arg, va);
	if (arg.func)
	{
		len = ft_get_len (*buff, arg, va);
		if (!(arg.flags & FLAG_LJUSTIFY))
		{
			if ((arg.flags & FLAG_ZPAD) && arg.precision < 0)
				ft_putchars_buff (buff, '0', arg.width - len, FALSE);
			else
				ft_putchars_buff (buff, ' ', arg.width - len, FALSE);
		}
		(*arg.func)(buff, arg, va);
		if ((arg.flags & FLAG_LJUSTIFY))
			ft_putchars_buff (buff, ' ', arg.width - len, FALSE);
	}
	else
	{
		ft_putchar_buff (buff, '%', FALSE);
		ft_putstrn_buff (buff, fmt, i, FALSE);
	}
	return (i);
}
