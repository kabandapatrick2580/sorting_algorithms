#include "sort.h"

/**
 * swap - Swap two integers
 * @a: The first integer
 * @b: The second integer
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * quicksort_recursive - Implement the quicksort algorithm using
 * the Lomuto partition scheme
 * @array: The array of integers to sort
 * @size: The size of @array
 * @left_s: The starting index of @array
 * @right_s: The ending index of @array
 *
 * Return: void
 */
void quicksort_recursive(int *array, size_t size, int left_s, int right_s)
{
	int *t_pivot = array + right_s;
	int above_t = left_s, below_t;

	if (right_s <= left_s)
		return;

	for (below_t = left_s; below_t < right_s; below_t++)
	{
		if (array[below_t] < *t_pivot)
		{
			if (above_t < below_t)
			{
				swap(array + below_t, array + above_t);
				print_array(array, size);
			}
			above_t++;
		}
	}

	if (array[above_t] > *t_pivot)
	{
		swap(array + above_t, t_pivot);
		print_array(array, size);
	}

	quicksort_recursive(array, size, left_s, above_t - 1);
	quicksort_recursive(array, size, above_t + 1, right_s);
}

/**
 * quick_sort - This function sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array of integers to sort
 * @size: The size of @array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, size, 0, size - 1);
}
