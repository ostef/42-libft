/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:50:18 by soumanso          #+#    #+#             */
/*   Updated: 2022/07/29 18:03:34 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define RAND_RANGE 0x10000000
#define M 0x7fffffff
#define A 16807

void	ft_rand_seed(t_rng *rng, t_int seed)
{
	*rng = seed & M;
	if (*rng == 0 || *rng == 1)
		*rng += 2;
}

t_int	ft_rand(t_rng *rng)
{
	t_int	hi;
	t_int	lo;

	hi = *rng / 127773;
	lo = *rng % 127773;
	*rng = A * lo - 2836 * hi;
	if (*rng <= 0)
		*rng += M;
	return (*rng);
}

t_f32	ft_rand_rangef(t_rng *rng, t_f32 low, t_f32 high)
{
	t_int	rand;
	t_f32	t;

	rand = ft_rand (rng) & (RAND_RANGE - 1);
	t = (rand / (t_f32)RAND_RANGE) * (high - low);
	return (low + t);
}

t_int	ft_rand_rangei(t_rng *rng, t_int low, t_int high)
{
	return ((t_int)ft_rand_rangef (rng, (t_f32)low, (t_f32)high));
}
