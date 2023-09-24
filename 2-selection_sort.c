#include "sort.h"

/**
 * selection_sort - sorts an array
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, temp, j, id = 0;

	if (array != NULL || size > 1)
	{
		for (i = 0; i < size - 1; i++)
		{
			id = i;
			for (j = i + 1; j < size; j++)
			{
				if (array[j] < array[id])
				{
					id = j;
				}
			}
			if (id != i)
			{
				temp = array[id];
				array[id] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
	}
}
