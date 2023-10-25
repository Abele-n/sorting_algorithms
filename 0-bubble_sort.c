#include "sort.h"

/**
 * swaps_ints - it swaps two integers in an array
 * @k: first integer to swap
 * @l: second integer to swap
 */

void swaps_ints(int *k, int *l)
{
	int temp;

	temp = *k;
	*k = *l;
	*l = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array of int to sort
 * @size: size of array
 *
 * Description: After each swap, an array is printed
 */

void bubble_sort(int *array, size_t size)
{
	size_t m, len = size;
	bool is_bubbly = false;
	
	if (array == NULL || size < 2)
		return;
	while (is_bubbly == false)
	{
		is_bubbly = true;
		for (m = 0; m < len - 1; m++)
		{
			if (array[m] > array[m + 1])
			{
				swaps_ints(array + m, array + m + 1);
				print_array(array, size);
				is_bubbly = false;
			}
		}
		len--;
	}
}
