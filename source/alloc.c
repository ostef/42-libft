/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:27:54 by soumanso          #+#    #+#             */
/*   Updated: 2022/02/15 17:57:04 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_alloc(t_s64 size, t_alloc alloc)
{
	void	*result;

	if (size <= 0)
		return (NULL);
	return (alloc.proc (MODE_ALLOCATE, size, NULL, alloc.data));
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

void	ft_free(void *ptr, t_alloc alloc)
{
	if (ptr)
		alloc.proc (MODE_FREE, 0, ptr, alloc.data);
	if (allocator == ALLOC_HEAP)
	{
		if (ptr)
			g_heap_allocations -= 1;
		free (ptr);
	}
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
