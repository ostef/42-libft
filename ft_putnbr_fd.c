#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(t_int n, t_int fd)
{
	t_uint	un;
	t_usize	i;
	char	buffer[11];

	un = n;
	if (n < 0)
	{
		write (fd, "-", 1);
		un = -n;
	}
	i = 0;
	while (un > 0)
	{
		buffer[11 - i - 1] = (un % 10) + '0';
		un /= 10;
		i += 1;
	}
	write (fd, &buffer[11 - i], i);
}
