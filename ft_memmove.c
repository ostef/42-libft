#include "libft.h"

void	*ft_memmove(void *dst, const void *src, t_usize n)
{
	t_int	dir;
	t_ssize	i;
	t_ssize	end;

	if ((!dst && !src) || n == 0)
		return (dst);
	dir = (dst < src) * 2 - 1;
	i = (dst >= src) * (n - 1);
	end = (dst < src) * n - (dst >= src);
	while (i != end)
	{
		((t_u8 *)dst)[i] = ((t_u8 *)src)[i];
		i += dir;
	}
	return (dst);
}
