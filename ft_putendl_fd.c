#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(const char *s, t_int fd)
{
	while (*s)
	{
		write (fd, s, 1);
		s += 1;
	}
	write (fd, "\n", 1);
}
