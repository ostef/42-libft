#include "libft.h"

const char	*ft_strrchr(const char *str, t_int c)
{
	t_ssize	i;

	i = 0;
	while (str[i])
		i += 1;
	while (i >= 0 && str[i] != (char)c)
		i -= 1;
	if (i == -1)
		return (NULL);
	return (str + i);
}
