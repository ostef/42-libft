/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_storage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:47:24 by soumanso          #+#    #+#             */
/*   Updated: 2022/02/15 17:53:53 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_arena	g_temp_storage;

void	ft_init_temp_storage(void)
{
	static t_u8	memory[TEMP_STORAGE_SIZE];

	g_temp_storage.mem = memory;
	g_temp_storage.size = TEMP_STORAGE_SIZE;
	g_temp_storage.top = 0;
}

void	ft_reset_temp_storage(void)
{
	g_temp_storage.top = 0;
}

t_s64	ft_get_temp_storage_state(void)
{
	return (g_temp_storage.top);
}

void	ft_set_temp_storage_state(t_s64 state)
{
	ft_assert (state >= 0 && state < g_temp_storage.size,
		"Invalid temp storage marker.");
	g_temp_storage.top = state;
}
