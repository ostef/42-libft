#include "libft.h"

t_bool	ft_strnequ(const char *s1, const char *s2, t_usize n)
{
	t_usize	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < n)
		i += 1;
	return (i == n || s1[i] == s2[i]);
}
