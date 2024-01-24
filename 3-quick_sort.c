#include "sort.h"

void swp_int(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swp_int - Swap two integers in an array
 * @a: first int to swap
 * @b: second int to swap
 */
void swp_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - order a subset of an array or integer.
 * @array: the array of ints
 * @size: the size of the array
 * @left: the starting index of the subset
 * @right: the ending index of tge subset
 * Return: final partition
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *driver, up, down;

	driver = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *driver)
		{
			if (up < down)
			{
				swp_int(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *driver)
	{
		swp_int(array + up, driver);
		print_array(array, size);
	}
	return (up);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion
 * @array: an array of int for sorting
 * @size: size of the array
 * @left: starting index of the array partition
 * @right: ending index of the array partition
 * Description: uses lomuto partition scheme
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part_of;

	if (right - left > 0)
	{
		part_of = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part_of - 1);
		lomuto_sort(array, size, part_of + 1, right);
	}
}

/**
 * quick_sort - sort an array of int as quick as possible
 * @array: array of int to be sorted
 * @size: size of the array
 *
 * Description: uses the lomuto partition scheme
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
