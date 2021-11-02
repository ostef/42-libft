#include "libft.h"
#include <unistd.h>

void	ft_putnbr(t_int n)
{
	t_uint	un;
	t_usize	i;
	char	buffer[11];

	un = n;
	if (n < 0)
	{
		write (1, "-", 1);
		un = -n;
	}
	i = 0;
	while (un > 0)
	{
		buffer[11 - i - 1] = (un % 10) + '0';
		un /= 10;
		i += 1;
	}
	write (1, &buffer[11 - i], i);
}
