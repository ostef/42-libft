#include "libft.h"
#include <unistd.h>

void	ft_putendl(const char *s)
{
	while (*s)
	{
		write (1, s, 1);
		s += 1;
	}
	write (1, "\n", 1);
}
