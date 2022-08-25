/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:47:02 by soumanso          #+#    #+#             */
/*   Updated: 2022/08/24 16:47:02 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef FT_WIN32

t_file	ft_open_file(t_cstr filename, t_open_mode mode)
{
	DWORD	access;
	DWORD	open_mode;

	access = 0;
	if (mode & OPEN_READ)
		access |= FILE_GENERIC_READ;
	if (mode & OPEN_WRITE)
		access |= FILE_GENERIC_WRITE;
	if (mode & OPEN_APPEND)
		access &= ~FILE_GENERIC_WRITE & ~FILE_APPEND_DATA;
	if (mode & OPEN_CREATE)
		access |= FILE_GENERIC_WRITE;
	open_mode = OPEN_EXISTING;
	if ((mode & OPEN_CREATE) && (mode & OPEN_TRUNCATE))
		open_mode = CREATE_ALWAYS;
	else if (mode & OPEN_CREATE)
		open_mode = OPEN_ALWAYS;
	else if (mode & OPEN_TRUNCATE)
		open_mode = TRUNCATE_EXISTING;
	return ((t_file)CreateFileA (filename, access,
			FILE_SHARE_READ | FILE_SHARE_WRITE, 0, open_mode,
			FILE_ATTRIBUTE_NORMAL | FILE_FLAG_BACKUP_SEMANTICS, 0));
}

void	ft_close_file(t_file file)
{
	if (file != INVALID_FILE)
		CloseHandle ((HANDLE)file);
}

#else

t_file	ft_open_file(t_cstr filename, t_open_mode mode)
{
	int	flags;

	flags = 0;
	if ((mode & OPEN_RDWR) == OPEN_RDWR)
		flags |= O_RDWR;
	else if (mode & OPEN_READ)
		flags |= O_RDONLY;
	else if (mode & OPEN_WRITE)
		flags |= O_WRONLY;
	if (mode & OPEN_CREATE)
		flags |= O_CREAT;
	if (mode & OPEN_APPEND)
		flags |= O_APPEND;
	if (mode & OPEN_TRUNCATE)
		flags |= O_TRUNC;
	return (open (filename, flags));
}

void	ft_close_file(t_file file)
{
	close (file);
}

#endif
