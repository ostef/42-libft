#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	t_usize	len;
	t_usize	i;
	char	*result;

	len = 0;
	while (str[len])
		len += 1;
	result = (char *)malloc (len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = str[i];
		i += 1;
	}
	result[i] = 0;
	return (result);
}
