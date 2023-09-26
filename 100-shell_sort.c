#include "sort.h"

/**
 * shell_sort - This function sorts an array of integers in ascending order
 * using the Shell sort algorithm with the Knuth sequence
 * @array: The array of integers
 * @size: The size of @array
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t custom_gap, custom_a, custom_b;

	if (array == NULL || size < 2)
		return;

	for (custom_gap = 1; custom_gap < (size / 3);)
		custom_gap = custom_gap * 3 + 1;

	for (; custom_gap >= 1; custom_gap /= 3)
	{
		for (custom_a = custom_gap; custom_a < size; custom_a++)
		{
			custom_b = custom_a;
			while (custom_b >= custom_gap &&
					array[custom_b - custom_gap] > array[custom_b])
			{
				int custom_swap = array[custom_b];

				array[custom_b] = array[custom_b - custom_gap];
				array[custom_b - custom_gap] = custom_swap;
				custom_b -= custom_gap;
			}
		}
		print_array(array, size);
	}
}
