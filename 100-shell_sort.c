#include "sort.h"

/**
 * swaps_ints - it swaps two ints in an array
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
 * shell_sorts - an array of integers is sorted in an
 * Ascending order in shell sort algorithm
 * @array: array of ints
 * @size: size of the array
 *
 * Description: It applies Knuth interval sequence
 */

void shell_sorts(int *array, size_t size)
{
	size_t interval, k, L;

	if (array == NULL || size < 2)
		return;

	for (interval = 1; interval < (size / 3); )
		interval = interval * 3 + 1;

	for (; interval >= 1; interval /= 3)
	{
		for (k = interval; k < size; k++)
		{
			k = L;
			while (L >= interval && array[L - interval] > array[L])
			{
				swaps_ints(array + L, array + (L - interval));
				L -= interval;
			}
		}
		print_array(array, size);
	}
}
