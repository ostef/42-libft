/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:27:54 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/22 16:27:56 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_temp_storage	g_temp_storage;

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
			size);
		result = g_temp_storage.mem + g_temp_storage.top;
		g_temp_storage.top += size;
		return (result);
	}
	else if (allocator == ALLOC_HEAP)
	{
		return (malloc (size));
	}
	return (NULL);
}

void	*ft_zalloc(t_s64 size, t_alloc allocator)
{
	void	*result;

	result = ft_alloc (size, allocator);
	if (result)
		ft_memset (result, 0, size);
	return (result);
}

void	ft_free(void *ptr, t_alloc allocator)
{
	if (allocator == ALLOC_HEAP)
		free (ptr);
}
