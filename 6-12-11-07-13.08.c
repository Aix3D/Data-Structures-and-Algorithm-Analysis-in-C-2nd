/*	6-12-11-07-13.08.c -- 第六章第十二题	*/
#include <stdio.h>
#include "d-heap.h"

#define SIZE 15

int main (void) ;
void print_item (const Item item) ;

int main (void)
{
	Heap h ;
	Item array[SIZE] = {10, 12, 1, 14, 6, 5, 8, 15, 3, 9, 7, 4, 11, 13, 2} ;
	int capacity, d, position, triangle, ct, size ;

	capacity = 20 ;
	d = 2 ;
	position = 1 ;
	triangle = 15 ;
	size = SIZE ;

	if (!InitializeHeap (&h, capacity, d))
		return 0 ;
//	BuildHeap (&h, array, size) ;
	for (ct = 0; ct < size; ct++)
		Insert (&h, array[ct]) ;
	Traversal (&h, print_item) ;
	putchar ('\n') ;
	DeleteMin (&h) ;
	DeleteMin (&h) ;
	DeleteMin (&h) ;
//	IncreaseKey (&h, position, triangle) ;
	Traversal (&h, print_item) ;
//	putchar ('\n') ;

	Release (&h) ;

	return 0 ;
}

void print_item (const Item item)
{
	printf ("%d\n", item) ;
}
