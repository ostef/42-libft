#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(t_usize count, t_usize size)
{
	void	*result;
	t_usize	i;

	result = malloc (count * size);
	if (!result)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((t_u8 *)result)[i] = 0;
		i += 1;
	}
	return (result);
}
