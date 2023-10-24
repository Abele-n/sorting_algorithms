#include "sort.h"

void swaps_ints(int *g, int *h);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);
int lomuto_partition(int *array, size_t size, int left, int right);

/**
 * swaps_ints - to swap two integers in an array
 * @g: first int to swap
 * @h: second int to swap
 */

void swaps_ints(int *g, int *h)
{
	int temp;

	temp = *g;
	*g = *h;
	*h = temp;
}

/**
 * lomuto_sort - Quicksort implementation through recursion
 * @array: array of integers to sort
 * @size: size of the array
 * @left: starting index to order of the array partition
 * @right: ending index to order of the array partition
 *
 * Description: The Lomuto partition scheme
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int my_part;

	if (right - left > 0)
	{
		my_part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, my_part - 1);
		lomuto_sort(array, size, my_part + 1, right);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * By the Quicksort algorithm
 * @array: array of integers
 * @size: size of the array
 *
 * Description: The Lemuto partition scheme
 * The scheme prints the array after each two element swap
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

/**
 * lomuto_partition - a subset of an integer array is ordered
 * According to lomuto scheme
 * @array: array of integers
 * @size: size of array
 * @left: starting index to order of the subset
 * @right: ending index to order of the subset
 *
 * Return: index of the final partition
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, up, down;

	pivot = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
				swaps_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}
	if (array[up] > *pivot)
	{
		swaps_ints(array + up, pivot);
		print_array(array, size);
	}
	return (up);
}
