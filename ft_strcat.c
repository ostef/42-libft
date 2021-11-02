#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	t_usize	len;
	t_usize	i;

	len = 0;
	while (dst[len])
		len += 1;
	i = 0;
	while (src[i])
	{
		dst[len + i] = src[i];
		i += 1;
	}
	dst[len + i] = 0;
	return (dst);
}
