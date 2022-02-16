/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:28:28 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/22 16:28:28 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_int	ft_strcmp(t_cstr s1, t_cstr s2)
{
	t_s64	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i += 1;
	return (s1[i] - s2[i]);
}

t_int	ft_strncmp(t_cstr s1, t_cstr s2, t_s64 n)
{
	t_s64	i;

	i = 0;
	while (i < n && s1[i] && s1[i] == s2[i])
		i += 1;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

t_bool	ft_strequ(t_cstr s1, t_cstr s2)
{
	return (ft_strcmp (s1, s2) == 0);
}

t_bool	ft_strnequ(t_cstr s1, t_cstr s2, t_s64 n)
{
	return (ft_strncmp (s1, s2, n) == 0);
}
