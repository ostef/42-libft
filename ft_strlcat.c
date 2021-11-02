#include "libft.h"

t_usize	ft_strlcat(char *dst, const char *src, t_usize size)
{
	t_usize	src_len;
	t_usize	dst_len;
	t_usize	i;

	src_len = 0;
	while (src[src_len])
		src_len += 1;
	dst_len = 0;
	while (dst[dst_len])
		dst_len += 1;
	if (dst_len >= size)
		return (size + src_len);
	if (src_len == 0)
		return (dst_len);
	i = 0;
	while (i < size - dst_len - 1 && src[i])
	{
		dst[dst_len + i] = src[i];
		i += 1;
	}
	dst[dst_len + i] = 0;
	return (dst_len + src_len);
}
