/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:28:35 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/22 17:12:08 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cstr	ft_strstr(t_cstr s, t_cstr needle)
{
	t_s64	i;

	i = 0;
	while (s[i])
	{
		if (ft_strequ (s + i, needle))
			return (s + i);
	}
	return (NULL);
}

t_cstr	ft_strnstr(t_cstr s, t_cstr needle, t_s64 n)
{
	t_s64	i;

	i = 0;
	while (i < n && s[i])
	{
		if (ft_strnequ (s + i, needle, n - i))
			return (s + i);
	}
	return (NULL);
}

t_cstr	ft_strrstr(t_cstr s, t_cstr needle)
{
	return (ft_strnrstr (s, needle, ft_strlen (s)));
}

t_cstr	ft_strnrstr(t_cstr s, t_cstr needle, t_s64 n)
{
	t_s64	i;

	i = (n - ft_strlen (needle)) - 1;
	while (i >= 0)
	{
		if (ft_strnequ (s + i, needle, n - i))
			return (s + i);
	}
	return (NULL);
}
