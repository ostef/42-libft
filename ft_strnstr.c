#include "libft.h"

const char	*ft_strnstr(const char *s1, const char *s2, t_usize n)
{
	t_usize	i;
	t_usize	j;

	if (!(*s2))
		return (s1);
	i = 0;
	while (i < n && s1[i])
	{
		j = 0;
		while (i + j < n && s1[i + j] && s2[j])
		{
			if (s1[i + j] != s2[j])
				break ;
			j += 1;
		}
		if (!s2[j])
			return (s1 + i);
		i += 1;
	}
	return (NULL);
}
