#include "libft.h"

void	*ft_memchr(const void *ptr, t_int val, t_usize n)
{
	t_usize	i;

	i = 0;
	while (i < n)
	{
		if (((t_u8 *)ptr)[i] == (t_u8)val)
			return ((void *)&((t_u8 *)ptr)[i]);
		i += 1;
	}
	return (NULL);
}
