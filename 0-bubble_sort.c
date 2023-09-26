#include "sort.h"

/**
 * swap - Function to swap two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temporary;

	temporary = *a;
	*a = *b;
	*b = temporary;
}

/**
 * bubble_sort - Bubble sort algorithm
 * @array: Pointer to an array of integers
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int changed;
	size_t index_i, length_l = size;

	if (array == NULL || size < 2)
		return;

	while (1)
	{
		changed = 0;
		for (index_i = 0; index_i < length_l - 1; index_i++)
		{
			if (array[index_i] > array[index_i + 1])
			{
				swap(&array[index_i], &array[index_i + 1]);
				changed = 1;
				print_array(array, size);
			}
		}
		length_l--;

		if (changed == 0)
			break;
	}
}
