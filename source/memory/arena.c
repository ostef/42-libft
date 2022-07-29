/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:45:37 by soumanso          #+#    #+#             */
/*   Updated: 2022/07/29 21:37:00 by soumanso         ###   ########lyon.fr   */
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

t_bool	ft_init_arena(t_arena *arena, t_s64 size)
{
	arena->mem = ft_alloc (size, ft_heap ());
	if (!arena->mem)
		return (FALSE);
	arena->size = size;
	arena->top = 0;
	return (TRUE);
}

void	ft_free_arena(t_arena *arena)
{
	ft_free (arena->mem, ft_heap ());
	ft_memset (arena, 0, sizeof (t_arena));
}

void	ft_reset_arena(t_arena *arena)
{
	arena->top = 0;
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
		if (arena->top + size > arena->size)
			return (NULL);
		result = arena->mem + arena->top;
		arena->top += size;
		return (result);
	}
	return (NULL);
}
