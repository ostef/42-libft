/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:28:33 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/22 16:28:33 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str	ft_strdup(t_cstr s, t_alloc allocator)
{
	t_s64	len;
	t_str	result;

	len = ft_strlen (s);
	result = (t_str)ft_alloc (len + 1, allocator);
	ft_strcpy (result, s);
	return (result);
}

t_str	ft_strndup(t_cstr s, t_s64 n, t_alloc allocator)
{
	t_s64	len;
	t_str	result;

	len = ft_min (n, ft_strlen (s));
	result = (t_str)ft_alloc (len + 1, allocator);
	ft_strncpy (result, s, len);
	return (result);
}
