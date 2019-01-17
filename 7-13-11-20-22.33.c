/*	7-13-11-20-22.33.c -- 第七章第十三题	*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

int main (void) ;
void print_array (const int * const array, const int size) ;
void merge_sort (int * const array, const int size) ;
void merge_sort_entity (int * const array, int * const temp, const int left_position, const int right_position) ;
void merge (int * const array, int * const temp, int left_position, int right_position, int right_end) ;

int main (void)
{
	int array[SIZE] = {3, 1, 4, 1, 5, 9, 2, 6} ;
	int size = SIZE ;

	print_array (array, size) ;
	merge_sort (array, size) ;
	print_array (array, size) ;

	return 0 ;
}

void print_array (const int * const array, const int size)
{
	int i ;

	for (i = 0; i < size; i++)
		printf ("%d ", array[i]) ;
	putchar ('\n') ;
}

void merge_sort (int * const array, const int size)
{
	int * temp ;

	temp = (int *) malloc (sizeof (int) * size) ;
	if (temp)
	{
		merge_sort_entity (array, temp, 0, size - 1) ;
		free (temp) ;
	}
	else
		puts ("Out of space.") ;
}

void merge_sort_entity (int * const array, int * const temp, const int left_position, const int right_position)
{
	int center ;

	if (left_position < right_position)
	{
		center = (left_position + right_position) / 2 ;
		merge_sort_entity (array, temp, left_position, center) ;
		merge_sort_entity (array, temp, center + 1, right_position) ;
		merge (array, temp, left_position, center + 1, right_position) ;
	}
}

/*	left_position = start of left half, right_position = start of right half	*/
void merge (int * const array, int * const temp, int left_position, int right_position, int right_end)
{
	int i, left_end, count, temp_position ;

	left_end = right_position - 1 ;
	temp_position = left_position ;
	count = right_end - left_position + 1 ;

	/*	main loop	*/
	while (left_position <= left_end && right_position <= right_end)
	{
		if (array[left_position] <= array[right_position])
			temp[temp_position++] = array[left_position++] ;
		else
			temp[temp_position++] = array[right_position++] ;
	}
	while (left_position <= left_end)
		temp[temp_position++] = array[left_position++] ;
	while (right_position <= right_end)
		temp[temp_position++] = array[right_position++] ;
	for (i = 0; i < count; i++, right_end--)
		array[right_end] = temp[right_end] ;
}