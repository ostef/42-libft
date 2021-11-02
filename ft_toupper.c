#include "libft.h"

t_int	ft_toupper(t_int c)
{
	if (c >= 'a' && c <= 'z')
		c = 'A' + c - 'a';
	return (c);
}
