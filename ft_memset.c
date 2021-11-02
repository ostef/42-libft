#include "libft.h"

void	*ft_memset(void *ptr, t_int val, t_usize len)
{
	t_usize	i;

	i = 0;
	while (i < len)
	{
		((t_u8 *)ptr)[i] = (t_u8)val;
		i += 1;
	}
	return (ptr);
}
