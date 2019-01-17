/*	7-11-11-19-22.12.c -- 第七章第十一题	*/
#include <stdio.h>
#include <stdlib.h>

#define LEFTCHILD(position) ((position) * 2 + 1)				/*	Notice the space	*/
#define SIZE 12

int main (void) ;
void print_array (const int * const array, const int size) ;
void heap_sort (int * const array, const int size) ;
void build_heap (int * const array, const int size) ;
void precolate_down (int * array, int index, const int size) ;
void swap (int * const val_1, int * const val_2) ;

int main (void)
{
	int array[SIZE] = {142, 543, 123, 65, 453, 879, 572, 434, 111, 242, 811, 102} ;
	int size = SIZE ;

	print_array (array, size) ;
	heap_sort (array, size) ;
	print_array (array, size) ;

	return 0 ;
}

void print_array (const int * const array, const int size)
{
	int ct ;

	for (ct = 0; ct < size; ct++)
		printf ("%-3d ", array[ct]) ;
	putchar ('\n') ;
}

void heap_sort (int * const array, const int size)
{
	int ct ;

	build_heap (array, size) ;			/*	Build the heap	*/

	for (ct = size - 1; ct > 0; ct--)
	{
		swap (array, array + ct) ;		/*	Delete the maximum value	*/
		precolate_down (array, 0, ct) ;
	}
}

void build_heap (int * const array, const int size)
{
	int position ;

	for (position = size / 2; position >= 0; position--)
		precolate_down (array, position, size) ;
}

void precolate_down (int * array, int index, const int size)
{
	int child, value ;

	for (value = array[index]; LEFTCHILD (index) < size; index = child)
	{
		child = LEFTCHILD (index) ;
		if (child != size - 1 && array[child + 1] > array[child])
			child++ ;
		if (value < array[child])
			array[index] = array[child] ;
		else
			break ;
	}
	array[index] = value ;
}

void swap (int * const val_1, int * const val_2)
{
	int temp ;

	temp = *val_1 ;
	*val_1 = *val_2 ;
	*val_2 = temp ;
}