#include "libft.h"

void	ft_striteri(char *s, void (*f)(t_uint, char *))
{
	t_usize	i;

	i = 0;
	while (s[i])
	{
		(*f)((t_uint)i, s + i);
		i += 1;
	}
}
