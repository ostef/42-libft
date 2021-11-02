#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, t_usize n)
{
	t_usize	i;

	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i += 1;
	}
	while (i < n)
	{
		dst[i] = 0;
		i += 1;
	}
	return (dst);
}
