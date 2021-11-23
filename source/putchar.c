/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:28:15 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/22 18:13:18 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

t_s64	ft_fputchar(t_file f, char c)
{
	write (f, &c, 1);
	return (1);
}

t_s64	ft_putchar(char c)
{
	return (ft_fputchar (STDOUT, c));
}
