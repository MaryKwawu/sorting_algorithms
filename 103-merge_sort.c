#include "sort.h"
#include <stdio.h>

/**
 * print_data - Function that prints data
 * @msg: Message
 * @a: Array
 * @from: Beginning
 * @to: End
 * Return: Void
 */

void print_data(char *msg, int *a, int from, int to)
{
	char *sep;
	int i;

	printf("[%s]: ", msg);
	sep = "";

	for (i = from; i <= to; i++)
	{
		printf("%s%d", sep, a[i]);
		sep = ", ";
	}
	printf("\n");
}

/**
 * merge - Function that serves as auxiliar function for merge sort algorithm
 * @a: Array
 * @low: Low index
 * @middle: Middle index
 * @high: High index
 * @buff: Buffer
 * Return: Void
 */

void merge(int *a, int low, int middle, int high, int *buff)
{
	int lo, lm, i;

	lo = i = low;
	lm = middle + 1;

	printf("Merging...\n");
	print_data("left", a, low, middle);
	print_data("right", a, middle + 1, high);

	while (lo <= middle && lm <= high)
	{
		if (a[lo] < a[lm])
			buff[i++] = a[lo++];
		else
			buff[i++] = a[lm++];
	}

	while (lo <= middle)
		buff[i++] = a[lo++];

	while (lm <= high)
		buff[i++] = a[lm++];

	for (i = low; i <= high; i++)
		a[i] = buff[i];

	print_data("Done", a, low, high);
}
/**
 * msort - Function that serves as auxiliar function for merge sort algorithm
 * @array: Array
 * @low: Low index
 * @high: High index
 * @buffer: Buffer
 * Return: Void
 */

void msort(int *array, int low, int high, int *buffer)
{
	int midle;

	if (low < high)
	{
		midle = (low + high - 1) / 2;
		msort(array, low, midle, buffer);
		msort(array, midle + 1, high, buffer);
		merge(array, low, midle, high, buffer);
	}
}

/**
 * merge_sort - Function that sorts an array of integers in ascending order 
 * using the merge sort algorithm
 * @array: Array
 * @size: Size
 * Return: Void
 */

void merge_sort(int *array, size_t size)
{
	int *buffer;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;
	msort(array, 0, size - 1, buffer);
	free(buffer);
}
