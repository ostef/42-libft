/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:20:38 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/22 17:21:59 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_to_lower(char c)
{
	if (ft_is_upper (c))
		return ('a' + c - 'A');
	return (c);
}

char	ft_to_upper(char c)
{
	if (ft_is_lower (c))
		return ('a' + c - 'A');
	return (c);
}

t_bool	ft_is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

t_bool	ft_is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}
