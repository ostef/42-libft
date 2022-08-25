/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_entire_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:13:04 by soumanso          #+#    #+#             */
/*   Updated: 2022/08/25 09:54:46 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_grow_buff(t_buff *buff, t_s64 min, t_alloc alloc)
{
	t_str	new_data;
	t_s64	new_count;

	new_count = ft_max (min, buff->count * 2 + 100);
	new_data = (t_str)ft_alloc (new_count, alloc);
	if (!new_data)
	{
		ft_free (buff->data, alloc);
		buff->data = NULL;
		buff->count = 0;
	}
	ft_memcpy (new_data, buff->data, buff->count);
	ft_free (buff->data, alloc);
	buff->data = new_data;
	buff->count = new_count;
}

static t_s64	ft_do_one_read(t_file f, t_buff *buff, t_s64 len, t_alloc a)
{
	t_s64	read_len;

	ft_grow_buff (buff, len, a);
	if (!buff->data)
	{
		ft_close_file (f);
		return (-1);
	}
	read_len = ft_read_file (f, buff->data + len, buff->count - len - 1);
	if (read_len < 0)
	{
		ft_free (buff->data, a);
		ft_close_file (f);
	}
	return (read_len);
}

t_str	ft_read_entire_file(t_cstr filename, t_alloc alloc)
{
	t_buff	buff;
	t_file	file;
	t_s64	read_len;
	t_s64	len;

	buff.data = NULL;
	buff.count = 0;
	len = 0;
	file = ft_open_file (filename, OPEN_READ);
	if (file == INVALID_FILE)
		return (NULL);
	read_len = 1;
	while (read_len)
	{
		read_len = ft_do_one_read (file, &buff, len, alloc);
		len += read_len;
		if (read_len < 0)
			return (NULL);
		else if (read_len < buff.count - len - 1)
			break ;
	}
	ft_close_file (file);
	if (buff.data)
		buff.data[len] = 0;
	return (buff.data);
}
