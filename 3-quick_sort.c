#include "sort.h"

/**
 * swap_ints - swaps two ints in an array
 * @a: first int to swap
 * @b: second int to swap
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - sorts an array utilizing the Lomuto partition scheme
 * @array: array of ints to sort
 * @size: size of the array
 * @l: lefthand starting index
 * @r: righthand ending index
 *
 * Return: final partition index
 */

int lomuto_partition(int *array, size_t size, int l, int r)
{
	int *pivot, a, b;

	pivot = array + r;
	for (a = b = l; b < r; b++)
	{
		if (array[b] < *pivot)
		{
			if (a < b)
			{
				swap_ints(array + b, array + a);
				print_array(array, size);
			}
			a++;
		}
	}

	if (array[a] > *pivot)
	{
		swap_ints(array + a, pivot);
		print_array(array, size);
	}
	return (a);
}

/**
 * lomuto_sort - recursively implements the quicksort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 * @l: starting index of array parition
 * @r: ending index of array parition
 */

void lomuto_sort(int *array, size_t size, int l, int r)
{
	int p;

	if (r - l > 0)
	{
		p = lomuto_partition(array, size, l, r);
		lomuto_sort(array, size, l, p - 1);
		lomuto_sort(array, size, p + 1, r);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: array of ints to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
