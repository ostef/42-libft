/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:31:01 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/23 14:19:39 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s64	ft_str_to_s64(t_cstr s, t_s64 *out)
{
	t_u64	un;
	t_s64	i;
	t_s64	sign;

	i = 0;
	un = 0;
	sign = 1;
	if (*s == '-' || *s == '+')
	{
		i += 1;
		sign = (*s == '+') * 2 - 1;
	}
	i += ft_str_to_u64 (s + i, &un);
	if (out)
		*out = sign * un;
	return (i);
}

t_s64	ft_str_to_int(t_cstr s, t_int *out)
{
	t_s64	n;
	t_s64	len;

	len = ft_str_to_s64 (s, &n);
	if (out)
		*out = (t_int)n;
	return (len);
}

t_s64	ft_str_to_u64(t_cstr s, t_u64 *out)
{
	t_u64	n;
	t_s64	i;

	i = 0;
	n = 0;
	while (s[i] && ft_is_digit (s[i]))
	{
		n *= 10;
		n += s[i] - '0';
		i += 1;
	}
	if (out)
		*out = n;
	return (i);
}

t_s64	ft_str_to_uint(t_cstr s, t_uint *out)
{
	t_u64	un;
	t_s64	len;

	len = ft_str_to_u64 (s, &un);
	if (out)
		*out = (t_uint)un;
	return (len);
}

t_s64	ft_str_to_bool(t_cstr s, t_bool *out)
{
	t_bool	b;
	t_s64	len;

	len = 0;
	b = FALSE;
	if (ft_strequ (s, "true"))
	{
		len = sizeof ("true") - 1;
		b = TRUE;
	}
	else if (ft_strequ (s, "false"))
	{
		len = sizeof ("false") - 1;
		b = FALSE;
	}
	if (out)
		*out = b;
	return (len);
}
