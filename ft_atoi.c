#include "libft.h"

t_int	ft_atoi(const char *str)
{
	t_uint	un;
	t_int	sign;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str += 1;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '+') * 2 - 1;
		str += 1;
	}
	un = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		un *= 10;
		un += *str - '0';
		str += 1;
	}
	return ((t_int)(sign * un));
}
