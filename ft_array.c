#include "libft.h"
#include <stdlib.h>

void	*ft_arraynew(t_usize cap, t_usize size)
{
	void	*result;

	result = malloc (sizeof (t_usize) * 2 + size * cap);
	if (!result)
		return (NULL);
	result = (void *)((t_usize *)result + 2);
	COUNT (result) = 0;
	CAP (result) = cap;
	return (result);
}

void	ft_arraydel(void **array)
{
	free (ARRAY_BASE (*array));
	*array = NULL;
}

void	ft_grow(void **array, t_usize add_cap, t_usize size)
{
	t_usize	new_cap;
	void	*new_array;

	if (add_cap == 0)
		return ;
	new_cap = CCAP (*array) + add_cap;
	new_array = ft_alloc (
		sizeof (t_usize) * 2 + size * new_cap, ARRAY_ALLOC (array));
	if (!new_array)
	{
		PANIC ("Allocation failure when growing array.");
		return ;
	}
	new_array = (void *)((t_usize *)new_array + 2);
	ft_memcpy (new_array, *array, CCOUNT (*array) * size);
	COUNT (new_array) = CCOUNT (*array);
	CAP (new_array) = new_cap;
	free (*array);
	*array = new_array;
}

void	*ft_push(void **array, t_usize size)
{
	void	*result;

	if (CCOUNT (*array) == CCAP (*array))
		ft_grow(array, CCAP (*array) + 8, size);
	result = *array + size * CCOUNT (*array);
	COUNT (*array) += 1;
	return (result);
}

void	*ft_pop(void **array, t_usize size)
{
	ASSERT (CCOUNT (*array) > 0, "Attempting to pop from empty array.");
	COUNT (*array) -= 1;
	return (*array + size * CCOUNT (*array));
}
