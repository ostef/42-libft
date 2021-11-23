/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:29:36 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/23 14:16:45 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s64	ft_abs(t_s64 x)
{
	if (x < 0)
		return (-x);
	return (x);
}

t_f32	ft_absf(t_f32 x)
{
	if (x < 0)
		return (-x);
	return (x);
}

t_s64	ft_sign(t_s64 x)
{
	if (x < 0)
		return (-1);
	if (x > 0)
		return (1);
	return (0);
}

t_f32	ft_signf(t_f32 x)
{
	if (x < 0)
		return (-1);
	if (x > 0)
		return (1);
	return (0);
}
