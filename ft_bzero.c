#include "libft.h"

void	ft_bzero(void *ptr, t_usize n)
{
	t_usize	i;

	i = 0;
	while (i < n)
	{
		((char *)ptr)[i] = 0;
		i += 1;
	}
}
