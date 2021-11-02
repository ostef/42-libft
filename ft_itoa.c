#include "libft.h"
#include <stdlib.h>

static t_ssize	ft_itoa_len(t_int n)
{
	t_uint	un;
	t_ssize	len;

	if (n == 0)
		return (1);
	len = 0;
	un = n;
	if (n < 0)
	{
		len += 1;
		un = -n;
	}
	while (un > 0)
	{
		len += 1;
		un /= 10;
	}
	return (len);
}

char	*ft_itoa(t_int n)
{
	t_uint	un;
	t_ssize	i;
	t_ssize	len;
	char	*result;

	len = ft_itoa_len (n);
	result = (char *)malloc (len + 1);
	if (!result)
		return (NULL);
	un = n;
	if (n < 0)
	{
		result[0] = '-';
		un = -n;
	}
	i = len - 1;
	while (i >= (n < 0))
	{
		result[i] = (un % 10) + '0';
		un /= 10;
		i -= 1;
	}
	result[len] = 0;
	return (result);
}
