#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(const char *s, t_int fd)
{
	while (*s)
	{
		write (fd, s, 1);
		s += 1;
	}
}
