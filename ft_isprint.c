#include "libft.h"

t_bool	ft_isprint(t_int c)
{
	return (c >= ' ' && c <= '~');
}
