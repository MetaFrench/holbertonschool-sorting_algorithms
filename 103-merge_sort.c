#include "sort.h"

/**
 * merge_sort - merge sorts an array
 * @array: pointer to array to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp_arr = malloc(sizeof(array[0]) * size);

	copy_array(array, 0, size, tmp_arr);
	recur_split(tmp_arr, 0, size, array);
	free(tmp_arr);
}

/**
 * print_da_array - prints array
 * @array: pointer to array to print
 * @start: start index of array
 * @end: end index of array
 */
void print_da_array(int *array, int start, int end)
{
	int i;

	for (i = start; i < end; i++)
	{
		printf("%d", array[i]);
		if (i < end - 1)
			printf(", ");
		else
			printf("\n");
	}
}

/**
 * copy_array - copies array into temporary array
 * @array: pointer to array to copy
 * @start: start index of array
 * @tmp_arr: pointer to temporary array
 * @end: end index of array
 */
void copy_array(int *array, int start, int end, int *tmp_arr)
{
	int i;

	for (i = start; i < end; i++)
		tmp_arr[i] = array[i];
}

/**
 * recur_split - recursively splits array into subarrays
 * @array: pointer to array to sort
 * @tmp_arr: pointer to temporary array
 * @start: start index of array
 * @end: end index of array
 */
void recur_split(int *tmp_arr, int start, int end, int *array)
{
	int mid = (start + end) / 2;

	if (end - start <= 1)
		return;
	recur_split(array, start, mid, tmp_arr);
	recur_split(array, mid, end, tmp_arr);
	merge_it(tmp_arr, start, mid, end, array);
}

/**
 * merge_it - merges two subarrays
 * @array: pointer to array to sort
 * @tmp_arr: pointer to temporary array
 * @start: start index of array
 * @mid: middle index of array
 * @end: end index of array
 */
void merge_it(int *array, int start, int mid, int end, int *tmp_arr)
{
	int i = start, j = mid, k = start;

	for (k = start; k < end; k++)
	{
		if (i < mid && (j >= end || array[i] <= array[j]))
		{
			tmp_arr[k] = array[i];
			i++;
		}
		else
		{
			tmp_arr[k] = array[j];
			j++;
		}
	}
	printf("Merging...\n[left]: ");
	print_da_array(array, start, mid);
	printf("[right]: ");
	print_da_array(array, mid, end);
	printf("[Done]: ");
	print_da_array(tmp_arr, start, end);
}
