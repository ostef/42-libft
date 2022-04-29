/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:29:02 by soumanso          #+#    #+#             */
/*   Updated: 2022/04/29 17:24:07 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s64	count_splits(t_cstr str, char c)
{
	t_s64	start;
	t_s64	end;
	t_s64	i;

	i = 0;
	start = 0;
	end = 0;
	while (str[end])
	{
		if (str[end] == c)
		{
			if (start > end)
				i += 1;
			start = end + 1;
		}
		end += 1;
	}
	return (i + 1);
}

t_pcstr	*ft_split(t_cstr str, char c, t_alloc alloc)
{
	t_pcstr	*res;
	t_s64	i;
	t_s64	start;
	t_s64	end;

	start = 0;
	end = 0;
	i = 0;
	res = (t_pcstr *)ft_alloc (sizeof (t_pcstr) * count_splits (str, c), alloc);
	if (!res)
		return (NULL);
	while (str[end])
	{
		if (str[end] == c)
		{
			if (start > end)
				res[i++] = ft_pcstr (str + start, end - start);
			start = end + 1;
		}
		end += 1;
	}
	if (start > end)
		res[i++] = ft_pcstr (str + start, end - start);
	res[i] = ft_pcstr (NULL, 0);
	return (res);
}
