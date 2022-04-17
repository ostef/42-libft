/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:54:27 by soumanso          #+#    #+#             */
/*   Updated: 2022/04/17 16:06:49 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_builder_init(t_builder *builder, t_s64 cap, t_alloc allocator)
{
	builder->data = (t_str)ft_alloc (cap, allocator);
	builder->len = 0;
	builder->cap = cap;
	builder->allocator = allocator;
}

void	ft_builder_reset(t_builder *builder)
{
	ft_free (builder->data, builder->allocator);
	builder->data = NULL;
	builder->len = 0;
	builder->cap = 0;
}

void	ft_builder_grow(t_builder *builder, t_s64 add_cap)
{
	if (add_cap <= 0)
		return ;
	builder->data = (t_str)ft_realloc (builder->data, builder->cap,
			builder->cap + add_cap, builder->allocator);
	builder->cap += add_cap;
}

t_str	ft_builder_build(t_builder *builder)
{
	ft_builder_append_char (builder, 0);
	return (builder->data);
}
