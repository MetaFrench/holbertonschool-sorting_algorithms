#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order using the
 * LSD Radix sort algorithm
 * @array: array to sort
 * @size: size of array
 */

void radix_sort(int *array, size_t size)
{
	int i, max, place = 1;
	int *output = NULL;

	if (array == NULL || size < 2)
		return;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	max = array[0];
	for (i = 1; i < (int) size; i++)
		if (array[i] > max)
			max = array[i];
	while (max / place > 0)
	{
		counting_sort(array, size, output, place);
		print_array(array, size);
		place *= 10;
	}
	free(output);
}

/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: array to sort
 * @size: size of array
 * @output: output array
 * @place: digit place
 */

void counting_sort(int *array, size_t size, int *output, int place)
{
	int i, count[10] = {0};

	for (i = 0; i < (int) size; i++)
		count[(array[i] / place) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = (int) size - 1; i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}
	for (i = 0; i < (int) size; i++)
		array[i] = output[i];
}
