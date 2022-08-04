/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:45:37 by soumanso          #+#    #+#             */
/*   Updated: 2022/08/04 16:04:43 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_alloc	ft_arena(t_arena *arena)
{
	t_alloc	result;

	result.proc = ft_arena_alloc;
	result.data = arena;
	return (result);
}

t_bool	ft_init_arena(t_arena *arena, t_s64 size, t_alloc allocator)
{
	arena->current_page = NULL;
	arena->page_allocator = allocator;
	return (ft_arena_add_page (arena, size));
}

void	ft_free_arena(t_arena *arena)
{
	ft_arena_free_pages (arena, NULL);
}

void	ft_reset_arena(t_arena *arena)
{
	t_arena_page	*prev;

	while (arena->current_page && arena->current_page->prev)
	{
		prev = arena->current_page->prev;
		ft_free (arena->current_page, arena->page_allocator);
		arena->current_page = prev;
	}
	arena->current_page->top = 0;
}

void	*ft_arena_alloc(t_alloc_op op, t_s64 size, void *ptr, void *data)
{
	t_arena	*arena;
	void	*result;

	(void)ptr;
	arena = (t_arena *)data;
	if (op == OP_ALLOCATE)
	{
		size = (size + 7) & ~7;
		if (arena->current_page->top + size > arena->current_page->size)
		{
			if (!ft_arena_add_page (arena, size))
				return (NULL);
		}
		result = (t_u8 *)(arena->current_page)
			+ ((sizeof (t_arena_page) + 7) & ~7) + arena->current_page->top;
		arena->current_page->top += size;
		return (result);
	}
	return (NULL);
}
