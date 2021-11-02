#include "libft.h"

t_bool	ft_isalpha(t_int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
