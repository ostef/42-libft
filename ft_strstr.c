#include "libft.h"

const char	*ft_strstr(const char *s1, const char *s2)
{
	t_usize	i;

	if (!(*s2))
		return (s1);
	while (*s1)
	{
		i = 0;
		while (s1[i] && s2[i])
		{
			if (s1[i] != s2[i])
				break ;
			i += 1;
		}
		if (!s2[i])
			return (s1);
		s1 += 1;
	}
	return (NULL);
}
