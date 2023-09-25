#include "sort.h"

/**
 * swap - Swaps the positions of two elements in an array.
 * @array: The array.
 * @item1: The first array element.
 * @item2: The second array element.
 */
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
 * lomuto_partition - Lomuto partition sorting scheme implementation.
 * @array: The array to be sorted.
 * @first: The first array element.
 * @last: The last array element.
 * @size: The size of the array.
 *
 * Return: The position of the last element sorted.
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}
	return (current);
}

/**
 * qs - Quick sort algorithm implementation.
 * @array: The array to be sorted.
 * @first: The first array element.
 * @last: The last array element.
 * @size: The size of the array.
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);

		qs(array, first, position - 1, size);
		qs(array, position + 1, last, size);
	}
}

/**
 * quick_sort - Prepares the terrain for the quicksort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}

