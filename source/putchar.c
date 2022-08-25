/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:28:15 by soumanso          #+#    #+#             */
/*   Updated: 2022/08/24 20:47:53 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s64	ft_fputchar(t_file f, char c)
{
	ft_write_file (f, &c, 1);
	return (1);
}

t_s64	ft_putchar(char c)
{
	return (ft_fputchar (STDOUT, c));
}
