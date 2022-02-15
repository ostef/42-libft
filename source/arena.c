/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:45:37 by soumanso          #+#    #+#             */
/*   Updated: 2022/02/15 18:02:05 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_init_arena(t_arena *arena, t_s64 size)
{
	arena->mem = ft_alloc (size, ALLOC_HEAP);
	if (!arena->mem)
		return (FALSE);
	arena->size = size;
	arena->top = 0;
	return (TRUE);
}

void	ft_free_arena(t_arena *arena)
{
	ft_free (arena->mem, ALLOC_HEAP);
	ft_memset (arena, 0, sizeof (t_arena));
}

void	*ft_arena_alloc(t_alloc_mode mode, t_s64 size, void *ptr, void *data)
{
	t_arena	*arena;

	arena = (t_arena *)data;
	if (mode == MODE_ALLOCATE)
	{
	}
	return (NULL);
}
