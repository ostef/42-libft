#include "libft.h"
#include <stdlib.h>

static t_temp_storage	s_temp_storage;

t_bool	ft_init_temp_storage(t_usize cap)
{
	s_temp_storage.mem = malloc (cap);
	if (!s_temp_storage.mem)
		return (FALSE);
	s_temp_storage.cap = cap;
	s_temp_storage.top = 0;
}

void	ft_free_temp_storage(void)
{
	free (s_temp_storage.mem);
	s_temp_storage.mem = NULL;
	s_temp_storage.top = 0;
	s_temp_storage.cap = 0;
}

void	ft_reset_temp_storage(void)
{
	s_temp_storage.top = 0;
}

void	*ft_alloc(t_usize size, t_alloc type)
{
	void	*result;

	if (type == ALLOC_TEMP)
	{
		if (s_temp_storage.top + n > cap)
		{
			PANIC ("Memory failure in temporary storage.");
			return (NULL);
		}
		result = s_temp_storage.mem + s_temp_storage.top;
		s_temp_storage.top += n;
		return (result);
	}
	else if (type == ALLOC_HEAP)
	{
		return (malloc (size));
	}
	return (NULL);
}

void	ft_free(void *ptr, t_alloc type)
{
	if (type == ALLOC_HEAP)
		free (ptr);
}
