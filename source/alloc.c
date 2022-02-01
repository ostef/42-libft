/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:27:54 by soumanso          #+#    #+#             */
/*   Updated: 2022/02/01 18:00:16 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_int			g_heap_allocations;
static t_temp_storage	g_temp_storage;

t_int	ft_get_heap_allocations(void)
{
	return (g_heap_allocations);
}

void	ft_reset_temp_storage(void)
{
	g_temp_storage.top = 0;
}

void	*ft_alloc(t_s64 size, t_alloc allocator)
{
	void	*result;

	if (size <= 0)
		return (NULL);
	if (allocator == ALLOC_TEMP)
	{
		size = (size + 7) & -7;
		ft_assert (
			g_temp_storage.top + size <= TEMP_STORAGE_SIZE,
			"Memory shortage in temporay storage (requested size was %i).",
			(t_int)size);
		result = g_temp_storage.mem + g_temp_storage.top;
		g_temp_storage.top += size;
		return (result);
	}
	else if (allocator == ALLOC_HEAP)
	{
		result = malloc (size);
		if (result)
			g_heap_allocations += 1;
		return (result);
	}
	return (NULL);
}

void	*ft_realloc(void *ptr, t_s64 old_size, t_s64 size, t_alloc alloc)
{
	void	*new_ptr;

	new_ptr = ft_alloc (size, alloc);
	if (!new_ptr)
	{
		ft_free (ptr, alloc);
		return (NULL);
	}
	ft_memcpy (new_ptr, ptr, ft_min (size, old_size));
	ft_free (ptr, alloc);
	return (new_ptr);
}

void	ft_free(void *ptr, t_alloc allocator)
{
	if (allocator == ALLOC_HEAP)
	{
		if (ptr)
			g_heap_allocations -= 1;
		free (ptr);
	}
}
