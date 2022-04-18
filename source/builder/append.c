/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:58:09 by soumanso          #+#    #+#             */
/*   Updated: 2022/04/18 15:51:19 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s64	ft_builder_append_char(t_builder *builder, char c)
{
	if (builder->len >= builder->cap)
		ft_builder_grow (builder, builder->cap + 8);
	builder->data[builder->len] = c;
	builder->len += 1;
	return (1);
}

t_s64	ft_builder_append_len(t_builder *builder, t_cstr str, t_s64 len)
{
	t_s64	i;

	i = 0;
	while (i < len)
	{
		ft_builder_append_char (builder, str[i]);
		i += 1;
	}
	return (i);
}

t_s64	ft_builder_append(t_builder *builder, t_cstr str)
{
	t_s64	i;

	i = 0;
	while (str[i])
	{
		ft_builder_append_char (builder, str[i]);
		i += 1;
	}
	return (i);
}

t_s64	ft_builder_append_fmt(t_builder *builder, t_cstr fmt_str, ...)
{
	va_list	va;
	va_list	va2;
	t_s64	len;

	va_start (va, fmt_str);
	va_copy (va2, va);
	len = ft_vsprint (NULL, fmt_str, va2);
	va_end (va2);
	if (builder->len + len > builder->cap)
		ft_builder_grow (builder, builder->cap + len);
	ft_vsprint (builder->data + builder->len, fmt_str, va);
	builder->len += len;
	va_end (va);
	return (len);
}
