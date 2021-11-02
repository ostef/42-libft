#include "libft.h"

t_usize	ft_strlen(const char *s)
{
	t_usize	len;

	len = 0;
	while (s[len])
		len += 1;
	return (len);
}
