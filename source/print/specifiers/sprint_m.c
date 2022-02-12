/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprint_m.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:39:27 by soumanso          #+#    #+#             */
/*   Updated: 2022/02/12 16:09:16 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s64	ft_sprint_m(t_buff *buff, t_fmt_arg arg, va_list va)
{
	t_cstr	s;

	(void)va;
	s = strerror (errno);
	if (arg.precision < 0)
	{
		if (!s)
			return (ft_putstr_buff (buff, "(null)", FALSE));
		return (ft_putstr_buff (buff, s, FALSE));
	}
	if (!s)
		return (ft_putstrn_buff (buff, "(null)", arg.precision, FALSE));
	return (ft_putstrn_buff (buff, s, arg.precision, FALSE));
}
