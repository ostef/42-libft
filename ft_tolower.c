#include "libft.h"

t_int	ft_tolower(t_int c)
{
	if (c >= 'A' && c <= 'Z')
		c = 'a' + c - 'A';
	return (c);
}
