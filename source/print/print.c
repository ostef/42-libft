/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:07:40 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/23 14:06:55 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s64	ft_vprint(t_cstr fmt, va_list va)
{
	return (ft_vfprint (STDOUT, fmt, va));
}

t_s64	ft_print(t_cstr fmt, ...)
{
	va_list	va;
	t_s64	len;

	va_start (va, fmt);
	len = ft_vprint (fmt, va);
	va_end (va);
	return (len);
}

t_s64	ft_vprintln(t_cstr fmt, va_list va)
{
	return (ft_vfprintln (STDOUT, fmt, va));
}

t_s64	ft_println(t_cstr fmt, ...)
{
	va_list	va;
	t_s64	len;

	va_start (va, fmt);
	len = ft_vprintln (fmt, va);
	va_end (va);
	return (len);
}
