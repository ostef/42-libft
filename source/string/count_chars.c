/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:48:40 by aandric           #+#    #+#             */
/*   Updated: 2022/03/14 13:50:53 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_int	ft_count_chars(t_cstr str, char c, t_s64 n)
{
	t_int	i;
	t_int	nb_chars;

	i = 0;
	nb_chars = 0;
	while (i < n)
	{
		if (str[i] == c)
			nb_chars++;
		i++;
	}
	return (nb_chars);
}
