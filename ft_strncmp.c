#include "libft.h"

t_int	ft_strncmp(const char *s1, const char *s2, t_usize n)
{
	t_usize	i;

	i = 0;
	while (i < n && s1[i] && s1[i] == s2[i])
		i += 1;
	if (i == n)
		return (0);
	return ((t_u8)s1[i] - (t_u8)s2[i]);
}
