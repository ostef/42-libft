/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:07:40 by soumanso          #+#    #+#             */
/*   Updated: 2022/04/17 16:06:28 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s64	ft_vsprint(t_str buff, t_cstr fmt, va_list va)
{
	t_buff		b;

	b.data = buff;
	b.count = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt += 1;
			if (!(*fmt))
				break ;
			if (*fmt != '%')
			{
				fmt += ft_next_arg (fmt, &b, va);
				continue ;
			}
		}
		fmt += ft_putchar_buff (&b, *fmt, FALSE);
	}
	ft_putchar_buff (&b, 0, FALSE);
	return (b.count - 1);
}

t_s64	ft_sprint(t_str buff, t_cstr fmt, ...)
{
	va_list	va;
	t_s64	len;

	va_start (va, fmt);
	len = ft_vsprint (buff, fmt, va);
	va_end (va);
	return (len);
}

t_s64	ft_vsprintln(t_str buff, t_cstr fmt, va_list va)
{
	t_s64	len;

	len = ft_vsprint (buff, fmt, va);
	if (buff)
		len += ft_sprint (buff + len, "\n");
	else
		len += ft_sprint (NULL, "\n");
	return (len);
}

t_s64	ft_sprintln(t_str buff, t_cstr fmt, ...)
{
	va_list	va;
	t_s64	len;

	va_start (va, fmt);
	len = ft_vsprintln (buff, fmt, va);
	va_end (va);
	return (len);
}

t_str	ft_fmt(t_alloc alloc, t_str fmt, ...)
{
	va_list	va;
	va_list	va2;
	t_s64	len;
	t_str	str;

	va_start (va, fmt);
	va_copy (va2, va);
	len = ft_vsprint (NULL, fmt, va2);
	va_end (va2);
	str = (t_str)ft_alloc (len + 1, alloc);
	if (!str)
	{
		va_end (va);
		return (NULL);
	}
	len = ft_vsprint (str, fmt, va);
	str[len] = 0;
	va_end (va);
	return (str);
}
