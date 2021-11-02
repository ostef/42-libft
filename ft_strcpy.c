#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	t_usize	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i += 1;
	}
	dst[i] = 0;
	return (dst);
}
