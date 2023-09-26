#include "sort.h"

/**
 * shell_sort - sorting elements by exchange
 * @array: array to be sorted
 * @size: the size of  array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1, i, j, end = 0;
	int temp;

	if (size > 1)
	{
		for (interval *= (3 + 1); interval > 0; interval /= 3)
		{
			for (i = interval; i < size; i++)
			{
				temp = array[i];
				for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
				{
					end = j - interval;
					array[j] = array[end];
				}
				array[j] = temp;
			}
			interval -= 1;
			print_array(array, size);
		}
	}
}
