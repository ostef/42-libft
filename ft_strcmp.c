#include "libft.h"

t_int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1 += 1;
		s2 += 1;
	}
	return ((t_u8)(*s1) - (t_u8)(*s2));
}
