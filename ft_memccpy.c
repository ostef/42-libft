#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, t_int end, t_usize n)
{
	t_usize	i;
	t_bool	found;

	i = 0;
	found = FALSE;
	while (i < n)
	{
		((t_u8 *)dst)[i] = ((t_u8 *)src)[i];
		if (((t_u8 *)src)[i] == (t_u8)end)
		{
			found = TRUE;
			i += 1;
			break ;
		}
		i += 1;
	}
	if (!found)
		return (NULL);
	return (dst + i);
}
