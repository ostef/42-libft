#include "libft.h"
#include <stdlib.h>

char	*ft_substr(const char *str, t_uint start, t_usize len)
{
	char	*result;
	t_usize	srclen;
	t_usize	i;

	srclen = ft_strlen (str);
	if (start > srclen)
		start = srclen;
	if (start + len > srclen)
		len = srclen - start;
	result = (char *)malloc (len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (str[start + i] && i < len)
	{
		result[i] = str[start + i];
		i += 1;
	}
	result[i] = 0;
	return (result);
}
