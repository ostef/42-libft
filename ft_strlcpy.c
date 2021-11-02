#include "libft.h"

t_usize	ft_strlcpy(char *dst, const char *src, t_usize size)
{
	t_usize	i;
	t_usize	copied;

	i = 0;
	copied = 0;
	while (src[i])
	{
		if (size > 0 && i < size - 1)
		{
			dst[i] = src[i];
			copied += 1;
		}
		i += 1;
	}
	if (copied < size)
		dst[copied] = 0;
	return (i);
}
