#include "sort.h"

/**
 * bubble_sort - Function that sorts an array  of integers in 
 * ascending order using the Bubble sort algorithm
 * @array: Array of input 
 * @size: Size of  array
 * Return: Void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n;
	int tmp, swap;

	for (n = size, swap = 1; n > 0 && swap; n--)
	{
		swap = 0;
		for (i = 0; (i + 1) < n; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				print_array(array, size);
				swap = 1;
			}
		}
	}
}
