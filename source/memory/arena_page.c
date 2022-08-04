/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_page.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:38:04 by soumanso          #+#    #+#             */
/*   Updated: 2022/08/04 15:38:04 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_arena_add_page(t_arena *arena, t_s64 min_size)
{
	t_arena_page	*page;

	page = (t_arena_page *)ft_alloc (((sizeof (t_arena_page) + 7) & ~7)
			+ ft_max (min_size, MEMORY_ARENA_PAGE_SIZE), arena->page_allocator);
	if (!page)
		return (FALSE);
	page->prev = arena->current_page;
	page->size = ft_max (min_size, MEMORY_ARENA_PAGE_SIZE);
	page->top = 0;
	arena->current_page = page;
	return (TRUE);
}

void	ft_arena_free_pages(t_arena *arena, t_arena_page *page)
{
	t_arena_page	*prev;

	while (arena->current_page && arena->current_page != page)
	{
		prev = arena->current_page->prev;
		ft_free (arena->current_page, arena->page_allocator);
		arena->current_page = prev;
	}
}

t_arena_mk	ft_arena_get_marker(t_arena *arena)
{
	t_arena_mk	marker;

	marker.page = arena->current_page;
	marker.top = arena->current_page->top;
	return (marker);
}

void	ft_arena_set_marker(t_arena *arena, t_arena_mk marker)
{
	ft_arena_free_pages (arena, marker.page);
	arena->current_page->top = marker.top;
}
