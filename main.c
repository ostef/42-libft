#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*s = "split  ||this|for|me|||||!|";
	char	**result = ft_split (s, '|');
	int		i;

	i = 0;
	while (result[i])
	{
		printf ("result[%d] is %p.\n", i, result[i]);
		free (result[i]);
		i += 1;
	}
	free (result);
}

/*
int main()
{
	t_int	*array = ARRAY_NEW (t_int, 10);
	*(t_int *)PPUSH (&array) = 10;
	*(t_int *)PPUSH (&array) = 42;
	PUSH (&array, 43);
	PUSH (&array, 44);
	PUSH (&array, 45);
	for (t_usize i = 0; i < CCOUNT (array); i += 1)
		printf ("%d ", array[i]);
	printf ("\n");
	POP (&array);
	for (t_usize i = 0; i < CCOUNT (array); i += 1)
		printf ("%d ", array[i]);
	printf ("\n");
	array[0] = 69105;
	for (t_usize i = 0; i < CCOUNT (array); i += 1)
		printf ("%d ", array[i]);
	printf ("\n");
	*(t_int *)PSORT_INSERT (&array, 2) = 28;
	for (t_usize i = 0; i < CCOUNT (array); i += 1)
		printf ("%d ", array[i]);
	printf ("\n");
	SORT_INSERT (&array, 0, 2002);
	for (t_usize i = 0; i < CCOUNT (array); i += 1)
		printf ("%d ", array[i]);
	printf ("\n");
	SORT_REMOVE (&array, 2);
	for (t_usize i = 0; i < CCOUNT (array); i += 1)
		printf ("%d ", array[i]);
	printf ("\n");
	REMOVE (&array, 2);
	for (t_usize i = 0; i < CCOUNT (array); i += 1)
		printf ("%d ", array[i]);
	printf ("\n");
	printf ("count is %lu, capacity is %lu.\n", CCOUNT (array), CCAP (array));
	CLEAR (&array);
	ARRAY_DEL (&array);
}
*/
