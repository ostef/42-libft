/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:13:04 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/24 18:31:18 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <fnctl.h>

static void	ft_grow_buff(t_buff *buff, t_alloc allocator)
{
	t_str	new_data;
	t_s64	new_count;

	new_count = buff->count * 2 + 100;
	new_data = (char *)ft_alloc (new_count, allocator);
	if (!new_data)
	{
		ft_free (buff->data, allocator);
		buff->data = NULL;
		buff->count = 0;
	}
	ft_memcpy (new_data, buff->data, buff->count);
	ft_free (buff->data, allocator);
	buff->data = new_data;
	buff->count = new_count;
}

t_str	ft_read_entire_file(t_cstr filename, t_alloc allocator)
{
	t_buff	buff;
	t_file	file;
	t_s64	read_len;
	t_s64	len;

	ft_memset (&buff, 0, (t_s64)(&len + sizeof (len) - &buff));
	file = open (filename, O_RDONLY);
	if (file < 0)
		return (NULL);
	read_len = 1;
	while (read_len)
	{
		ft_grow_buff (&buff, allocator);
		if (!buff.data)
			break ;
		read_len = read (file, buff.data, buff.count - 1);
		len += read_len;
		if (read_len < 0)
		{
			ft_free (buff.data, allocator);
			close (file);
			return (NULL);
		}
		else if (read_len < buff.count - 1)
			break ;
	}
	close (file);
	if (buff)
		buff.data[len] = 0;
	return (buff.data);
}
