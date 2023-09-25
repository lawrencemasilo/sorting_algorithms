#include "sort.h"

/**
 * quick_sort - sorts array using quick sort
 * @array: array to be sorted
 * @size: the size of array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	int low = 0, high = size - 1;

	if (array == NULL || size < 1)
		return;
	quick_sort_recursion(array, size, low, high);
}

/**
 * quick_sort_recursion - recursive function
 * @array: array to be sorted
 * @size: the size of array
 * @low: index of first element
 * @high: index of last element
 * Return: Nothing
 */
void quick_sort_recursion(int *array, size_t size, int low, int high)
{
	int index;

	if (low < high)
	{
		index = lomuto_partition(array, low, high);
		print_array(array, size);
		quick_sort_recursion(array, size, low, index - 1);
		quick_sort_recursion(array, size, index + 1, high);
	}
}

/**
 * lomuto_partition - lomuto for sorting
 * @array: array to be sorted
 * @low: index of first element
 * @high: index of last element
 * Return: the index
 */
int lomuto_partition(int *array, int low, int high)
{
	int index = low, j = low, temp;

	while (j < high)
	{
		if (array[j] < array[high])
		{
			temp = array[index];
			array[index] = array[j];
			array[j] = temp;
			index++;
		}
		j++;
	}
	temp = array[index];
	array[index] = array[high];
	array[high] = temp;
	return (index);
}
