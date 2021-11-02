#include "libft.h"

t_int	ft_memcmp(const void *p1, const void *p2, t_usize n)
{
	t_usize	i;

	i = 0;
	while (i < n && ((t_u8 *)p1)[i] == ((t_u8 *)p2)[i])
		i += 1;
	if (i == n)
		return (0);
	return (((t_u8 *)p1)[i] - ((t_u8 *)p2)[i]);
}
