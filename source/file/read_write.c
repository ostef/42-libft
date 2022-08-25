/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:46:54 by soumanso          #+#    #+#             */
/*   Updated: 2022/08/24 16:46:54 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef FT_WIN32

t_s64	ft_read_file(t_file file, void *buff, t_s64 buff_size)
{
	DWORD	nread;

	if (file == STDIN || file == STDOUT || file == STDERR)
		file = (t_file)GetStdHandle ((DWORD)(STD_INPUT_HANDLE - file));
	if (file == INVALID_FILE)
		return (-1);
	if (!ReadFile ((HANDLE)file, buff, (DWORD)buff_size, &nread, NULL))
		return (-1);
	return ((t_s64)nread);
}

t_s64	ft_write_file(t_file file, const void *buff, t_s64 buff_size)
{
	DWORD	written;

	if (file == STDIN || file == STDOUT || file == STDERR)
		file = (t_file)GetStdHandle ((DWORD)(STD_INPUT_HANDLE - file));
	if (file == INVALID_FILE)
		return (-1);
	if (!WriteFile ((HANDLE)file, buff, (DWORD)buff_size, &written, NULL))
		return (-1);
	return ((t_s64)written);
}

#else

t_s64	ft_read_file(t_file file, void *buff, t_s64 buff_size)
{
	return (read (file, buff, (t_u64)buff_size));
}

t_s64	ft_write_file(t_file file, const void *buff, t_s64 buff_size)
{
	return (write (file, buff, (t_u64)buff_size));
}

#endif
