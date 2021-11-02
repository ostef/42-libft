#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, t_int fd)
{
	write (fd, &c, 1);
}
