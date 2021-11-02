#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(t_usize size)
{
	char	*result;
	t_usize	i;

	result = (char *)malloc (size + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < size + 1)
	{
		result[i] = 0;
		i += 1;
	}
	return (result);
}
