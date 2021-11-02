#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(const char *str, const char *set)
{
	t_ssize	start;
	t_ssize	end;
	t_ssize	i;
	char	*result;

	start = 0;
	while (str[start] && ft_strchr (set, str[start]))
		start += 1;
	end = (t_ssize)ft_strlen (str);
	if (end > 0)
		end -= 1;
	while (end > start && ft_strchr (set, str[end]))
		end -= 1;
	result = (char *)malloc (end - start + 2);
	if (!result)
		return (NULL);
	i = 0;
	while (i <= end - start)
	{
		result[i] = str[start + i];
		i += 1;
	}
	result[i] = 0;
	return (result);
}
