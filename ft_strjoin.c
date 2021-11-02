#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	t_usize	len1;
	t_usize	len2;
	t_usize	i;
	char	*result;

	len1 = ft_strlen (s1);
	len2 = ft_strlen (s2);
	result = (char *)malloc (len1 + len2 + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		result[i] = s1[i];
		i += 1;
	}
	i = 0;
	while (i < len2)
	{
		result[len1 + i] = s2[i];
		i += 1;
	}
	result[len1 + len2] = 0;
	return (result);
}
