#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(const char *s, char (*f)(t_uint, char))
{
	t_usize	i;
	t_usize	len;
	char	*result;

	len = 0;
	while (s[len])
		len += 1;
	result = (char *)malloc (len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = (*f)((t_uint)i, s[i]);
		i += 1;
	}
	result[i] = 0;
	return (result);
}
