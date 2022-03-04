/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:27:54 by soumanso          #+#    #+#             */
/*   Updated: 2022/03/04 17:52:35 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_alloc(t_s64 size, t_alloc alloc)
{
	if (size <= 0)
		return (NULL);
	return (alloc.proc (OP_ALLOCATE, size, NULL, alloc.data));
}

void	*ft_zalloc(t_s64 size, t_alloc alloc)
{
	void	*result;

	result = ft_alloc (size, alloc);
	if (result)
		ft_memset (result, 0, size);
	return (result);
}

void	ft_free(void *ptr, t_alloc alloc)
{
	if (ptr)
		alloc.proc (OP_FREE, 0, ptr, alloc.data);
}

void	*ft_realloc(void *ptr, t_s64 old_size, t_s64 size, t_alloc alloc)
{
	void	*new_ptr;

	new_ptr = ft_alloc (size, alloc);
	if (new_ptr)
		ft_memcpy (new_ptr, ptr, ft_min (size, old_size));
	ft_free (ptr, alloc);
	return (new_ptr);
}
