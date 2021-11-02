#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, t_usize n)
{
	t_usize	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((t_u8 *)dst)[i] = ((t_u8 *)src)[i];
		i += 1;
	}
	return (dst);
}
