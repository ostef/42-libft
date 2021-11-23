/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:22:15 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/22 17:28:58 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

t_bool	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

t_bool	ft_is_digit_of_base(char c, t_cstr base)
{
	return (c != 0 && ft_strchr (base, c) != NULL);
}

t_bool	ft_is_alnum(char c)
{
	return (ft_is_alpha (c) || ft_is_digit (c) || c == '_');
}

t_bool	ft_is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}
