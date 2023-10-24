#include "sort.h"

/**
 * swaps_ints - To swap two integers in an array
 * @g: first integer to swap
 * @h: second integer to swap
 */

void swaps_ints(int *g, int *h)
{
	int temp;

	temp = *g;
	*g = *h;
	*h = temp;
}

/**
 * selection_sort - it sorts an array of ints in ascending order
 * @array: array of ints
 * @size: size of the array
 *
 * Description: After each swap, an array is printed
 */

void selection_sort(int *array, size_t size)
{
	int *mini;
	size_t k, L;

	if (array == NULL || size < 2)
		return;

	for (k = 0; k < size - 1; k++)
	{
		mini = array + k;
		for (L = k + 1; size > L; L++)
		{
			mini = (array[L] < *mini) ? (array + L) : mini;
		}
		if ((array + k) != mini)
		{
			swaps_ints(array + k, mini);
			print_array(array, size);
		}
	}
}

