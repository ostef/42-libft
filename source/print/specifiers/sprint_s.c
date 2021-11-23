/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprint_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:39:27 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/23 14:06:39 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s64	ft_sprint_s(t_buff *buff, t_fmt_arg arg, va_list va)
{
	t_bool	escape;
	t_cstr	s;

	s = va_arg (va, t_cstr);
	escape = arg.flags & FLAG_ESCAPED;
	if (arg.precision < 0)
	{
		if (!s)
			return (ft_putstr_buff (buff, "(null)", FALSE));
		return (ft_putstr_buff (buff, s, escape));
	}
	if (!s)
		return (ft_putstrn_buff (buff, "(null)", arg.precision, FALSE));
	return (ft_putstrn_buff (buff, s, arg.precision, escape));
}
