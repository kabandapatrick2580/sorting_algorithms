#include "sort.h"

/**
 * swap - Function to swap two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sorts integers using selection sort
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t custom_i, custom_j, custom_min_idx;

	if (array == NULL || size < 2)
		return;

	for (custom_i = 0; custom_i < size - 1; custom_i++)
	{
		custom_min_idx = custom_i;

		for (custom_j = custom_i + 1; custom_j < size; custom_j++)
		{
			if (array[custom_j] < array[custom_min_idx])
				custom_min_idx = custom_j;
		}

		if (custom_min_idx != custom_i)
		{
			swap(&array[custom_i], &array[custom_min_idx]);
			print_array(array, size);
		}
	}
}

