#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 *                  order using the Selection sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	unsigned int a, b, min;

	register int tmp; /*faster access in memory*/

	if (size < 2)
		return;

	for (a = 0; a < size; a++)
	{
		min = a;
		for (b = a + 1; b < size; b++)
		{
			if (array[a] < array[min])
				min = b;
		}
		tmp = array[a];
		array[a] = array[min];
		array[min] = tmp;
		if (a != min)
			print_array(array, size);
	}
}
