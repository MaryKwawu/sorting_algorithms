#include "sort.h"

/**
 * shell_sort - Function that sorts an array of integers in
 * ascending order using the shell sort algorithm
 * @array: Array of input
 * @size: Size of array
 * Return: Void
 */

void shell_sort(int *array, size_t size)
{
	size_t n = 1;

	while (n < size)
		n = (n * 3) + 1;

	while ((n = (n - 1) / 3) > 0)
		_ssort(array, size, n);
}

/**
 * _ssort - Function that serves as auxiliar for shell_sort function
 * @a: Array of input
 * @size: Size of array
 * @n: Intervale
 * Return: Void
 */

void _ssort(int *a, int size, int n)
{
	int tmp, i, j;

	for (i = 0; (i + n) < size; i++)
	{
		for (j = i + n; (j - n) >= 0; j = j - n)
		{
			if (a[j] < a[j - n])
			{
				tmp = a[j];
				a[j] = a[j - n];
				a[j - n] = tmp;
			}
		}
	}
	print_array(a, size);
}
