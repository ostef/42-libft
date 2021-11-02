#include "libft.h"

void	*ft_insert(void **array, t_usize index, t_usize size)
{
	ASSERT (index <= CCOUNT (*array), "Index out of range.");
	if (CCOUNT (*array) == CCAP (*array))
		ft_grow (array, CCAP (*array) + 8, size);
	ft_memcpy (*array + size * CCOUNT (*array), *array + size * index, size);
	COUNT (*array) += 1;
	return (*array + size * index);
}

void	ft_remove(void **array, t_usize index, t_usize size)
{
	ASSERT (index < CCOUNT (*array), "Index out of range.");
	COUNT (*array) -= 1;
	ft_memcpy (*array + size * index, *array + size * CCOUNT (*array), size);
}

void	*ft_sort_insert(void **array, t_usize index, t_usize size)
{
	t_usize	tomove;

	ASSERT (index <= CCOUNT (*array), "Index out of range.");
	if (CCOUNT (*array) == CCAP (*array))
		ft_grow (array, CCAP (*array) + 8, size);
	tomove = CCOUNT (*array) - index;
	ft_memmove (*array + size * (index + 1),
		*array + size * index, tomove * size);
	COUNT (*array) += 1;
	return (*array + size * index);
}

void	ft_sort_remove(void **array, t_usize index, t_usize size)
{
	t_usize	tomove;

	ASSERT (index < CCOUNT (*array), "Index out of range.");
	COUNT (*array) -= 1;
	tomove = CCOUNT (*array) - index;
	ft_memmove (*array + size * index,
		*array + size * (index + 1), tomove * size);
}
