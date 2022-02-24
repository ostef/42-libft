/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:17:36 by soumanso          #+#    #+#             */
/*   Updated: 2022/02/24 18:29:21 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s64	ft_skip_spaces(t_cstr str)
{
	t_s64	i;

	i = 0;
	while (ft_is_space (str[i]))
		i += 1;
	return (i);
}

t_s64	ft_skip_until_space(t_cstr str)
{
	t_s64	i;

	i = 0;
	while (str[i] && !ft_is_space (str[i]))
		i += 1;
	return (i);
}

t_s64	ft_skip_quoted_string(t_cstr str, char quote)
{
	t_s64	i;

	i = 0;
	while (str[i] && str[i] != quote)
		i += 1;
	return (i);
}
