#include "sort.h"

/**
 * gets_max - finds the max value in array of ints
 * @array: array of ints
 * @size: size of array
 *
 * Return: max int in the array
 */

int gets_max(int *array, int size)
{
	int k, max;

	for (max = array[0], k = 1; k < size; k++)
	{
		if (array[k] > max)
			max = array[k];
	}
	return (max);
}

/**
 * counting_sort - sorts array of ints in ascending order
 * By Counting Sort Algorithm
 * @array: array of ints
 * @size: size of the array
 *
 * Description: After set up, counting array is printed
 */

void counting_sort(int *array, size_t size)
{
	int *counter, *sorted, k, max;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;

	max = gets_max(array, size);
	counter = malloc(sizeof(int) * (max + 1));
	if (counter == NULL)
	{
		free(sorted);
		return;
	}

	for (k = 0; k < (max + 1); k++)
		counter[k] = 0;
	for (k = 0; k < (int)size; k++)
		counter[array[k]] += 1;
	for (k = 0; k < (max + 1); k++)
		counter[k] += counter[k - 1];
	print_array(count, max + 1);

	for (k = 0; k < (int)size; k++)
	{
		sorted[counter[array[k]] - 1] = array[k];
		counter[array[k]] -= 1;
	}
	for (k = 0; k < (int)size; k++)
		array[k] = sorted[k];

	free(sorted);
	free(counter);
}
