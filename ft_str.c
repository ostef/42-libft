#include "libft.h"

t_str	ft_str(char *cstr)
{
	t_str	result;
	
	result.count = ft_strlen (cstr);
	result.data = cstr;
	return (result);
}
