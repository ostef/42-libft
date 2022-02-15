/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:47:39 by soumanso          #+#    #+#             */
/*   Updated: 2022/02/15 17:58:21 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_int	g_heap_allocations;

t_int	ft_get_heap_allocations(void)
{
	return (g_heap_allocations);
}

void	*heap_alloc(t_alloc_mode mode, t_s64 size, void *ptr, void *data)
{
	void	*result;

	(void)data;
	if (mode == MODE_ALLOCATE)
	{
		result = malloc (size);
		if (result)
			g_heap_allocations += 1;
		return (result);
	}
	else if (mode == MODE_FREE)
	{
		if (ptr)
			g_heap_allocations -= 1;
		free (ptr);
	}
	return (NULL);
}
