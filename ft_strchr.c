#include "libft.h"

const char	*ft_strchr(const char *str, t_int c)
{
	while (*str && *str != (char)c)
		str += 1;
	if (*str == (char)c)
		return (str);
	return (NULL);
}
