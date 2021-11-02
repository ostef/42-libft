#include "libft.h"

t_bool	ft_strequ(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1 += 1;
		s2 += 1;
	}
	return (*s1 == *s2);
}
