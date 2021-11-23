/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:28:00 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/22 17:11:49 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_debug_break(void)
{
	asm ("int3");
}

void	ft_assert(t_bool assert, t_cstr fmt, ...)
{
	va_list	va;

	if (!assert)
	{
		ft_print ("Assertion failed: ");
		va_start (va, fmt);
		ft_vprintln (fmt, va);
		va_end (va);
		ft_debug_break ();
	}
}

void	ft_panic(t_cstr fmt, ...)
{
	va_list	va;

	ft_print ("PANIC: ");
	va_start (va, fmt);
	ft_vprintln (fmt, va);
	va_end (va);
	ft_debug_break ();
}
