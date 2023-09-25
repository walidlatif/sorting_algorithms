#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection sort algorithm.
 *
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int temp, swaps_occurred;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		swaps_occurred = 0;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
				swaps_occurred = 1;
			}
		}

		if (swaps_occurred)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}

