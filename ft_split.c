#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static t_bool	ft_dup(char **split, t_ssize i, const char *s, t_usize len)
{
	t_usize	j;

	void	*ptr = malloc (len + 1);
	split[i] = (char *)ptr;
	printf ("Allocated %lu bytes, ptr is %p, split[%ld] = %p.\n", len + 1, ptr, i, split[i]);
	if (!split[i])
	{
		while (i >= 0)
		{
			free (split[i]);
			i -= 1;
		}
		free (split);
		return (FALSE);
	}
	j = 0;
	while (j < len)
	{
		split[i][j] = s[j];
		j += 1;
	}
	split[i][j] = 0;
	return (TRUE);
}

char	**ft_split(const char *s, char c)
{
	t_usize	start;
	t_usize	end;
	t_ssize	i;
	char	**result;

	result = (char **)malloc (ft_strlen (s) + 1);
	if (!result)
		return (NULL);
	i = 0;
	start = 0;
	end = 0;
	while (s[end])
	{
		if (s[end] == c)
		{
			if (end > start && !ft_dup (result, i++, s + start, end - start))
				return (NULL);
			start = end + 1;
		}
		end += 1;
	}
	if (end > start && !ft_dup (result, i++, s + start, end - start))
		return (NULL);
	result[i] = NULL;
	return (result);
}
