/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:47:39 by soumanso          #+#    #+#             */
/*   Updated: 2022/07/29 21:30:34 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef COUNT_HEAP_ALLOCATIONS

static t_int	g_heap_allocations;

#endif

t_alloc	ft_heap(void)
{
	t_alloc	result;

	result.proc = ft_heap_alloc;
	result.data = NULL;
	return (result);
}

#ifdef COUNT_HEAP_ALLOCATIONS

t_int	ft_get_heap_allocations(void)
{
	return (g_heap_allocations);
}

#else

t_int	ft_get_heap_allocations(void)
{
	return (0);
}

#endif

#ifdef COUNT_HEAP_ALLOCATIONS

void	*ft_heap_alloc(t_alloc_op op, t_s64 size, void *ptr, void *data)
{
	void	*result;

	(void)data;
	if (op == OP_ALLOCATE)
	{
		result = malloc (size);
		if (result)
			g_heap_allocations += 1;
		return (result);
	}
	else if (op == OP_FREE)
	{
		if (ptr)
			g_heap_allocations -= 1;
		free (ptr);
	}
	return (NULL);
}

#else

void	*ft_heap_alloc(t_alloc_op op, t_s64 size, void *ptr, void *data)
{
	void	*result;

	(void)data;
	if (op == OP_ALLOCATE)
	{
		result = malloc (size);
		return (result);
	}
	else if (op == OP_FREE)
	{
		free (ptr);
	}
	return (NULL);
}

#endif
