/*	7-40-11-27-23.10.c -- 第七章第四十题	*/
#include <stdio.h>
#define SIZE 20

int main (void) ;
void print_array (const int * const array, const int size) ;
void swap (int * const vala, int * const valb) ;
void percolate_up (int * const array, const int index, const int size) ;
void percolate_down (int * const array, const int index, const int size) ;
void build_heap (int * const array, const int size) ;
void heap_sort (int * const array, const int size) ;

int main (void)
{
	int array[SIZE] = {0, 3, 1, 4, 2, 6, 9, 5, 7, 8, 13, 12, 11, 14, 10, 19, 15, 17, 18, 16} ;
	int size = SIZE ;

	print_array (array, size) ;
	heap_sort (array, size) ;
	print_array (array, size) ;

	return 0 ;
}

void print_array (const int * const array, const int size)
{
	int i ;

	for (i = 0; i < size; i++)
		printf ("%-2d ", array[i]) ;
	putchar ('\n') ;
}

void swap (int * const vala, int * const valb)
{
	int temp ;

	temp = *vala ;
	*vala = *valb ;
	*valb = temp ;
}

void build_heap (int * const array, const int size)
{
	int i ;

	for (i = size / 2; i >= 0; i--)
		percolate_down (array, i, size) ;
}

void percolate_up (int * const array, const int index, const int size)
{
	int i, value ;

	value = array[index] ;
	for (i = index; i >= 1; i = (i - 1) / 2)
	{
		if (array[(i - 1) / 2] < value)
			array[i] = array[(i - 1) / 2] ;
		else
			break ;
	}
	array[i] = value ;
}

void percolate_down (int * const array, const int index, const int size)
{
	int child, i, value ;

	value = array[index] ;
	for (i = index; i * 2 + 1 < size; i = child)
	{
		child = i * 2 + 1 ;
		if (child != size - 1 && array[child + 1] > array[child])
			child++ ;
		array[i] = array[child] ;
	}
	array[i] = value ;
	percolate_up (array, i, size) ;
}

void heap_sort (int * const array, const int size)
{
	int i ;

	build_heap (array, size) ;

	for (i = size - 1; i > 0; i--)
	{
		swap (array, array + i) ;
		percolate_down (array, 0, i) ;
	}
}