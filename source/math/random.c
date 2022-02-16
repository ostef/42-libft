/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:50:18 by soumanso          #+#    #+#             */
/*   Updated: 2022/02/03 12:10:48 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define RAND_RANGE 0x10000000
#define M 0x7fffffff
#define A 16807

static t_int	g_rand_state = 0x0173965;

void	ft_rand_seed(t_int seed)
{
	g_rand_state = seed & M;
	if (g_rand_state == 0 || g_rand_state == 1)
		g_rand_state += 2;
}

t_int	ft_rand(void)
{
	t_int	hi;
	t_int	lo;

	hi = g_rand_state / 127773;
	lo = g_rand_state % 127773;
	g_rand_state = A * lo - 2836 * hi;
	if (g_rand_state <= 0)
		g_rand_state += M;
	return (g_rand_state);
}

t_f32	ft_rand_rangef(t_f32 low, t_f32 high)
{
	t_int	rand;
	t_f32	t;

	rand = ft_rand () & (RAND_RANGE - 1);
	t = (rand / (t_f32)RAND_RANGE) * (high - low);
	return (low + t);
}

t_int	ft_rand_rangei(t_int low, t_int high)
{
	return ((t_int)ft_rand_rangef ((t_f32)low, (t_f32)high));
}
