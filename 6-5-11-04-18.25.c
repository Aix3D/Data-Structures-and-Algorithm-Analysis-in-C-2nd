/*	6-5-11-04-18.25.c -- 第六章第一题	*/
#include <stdio.h>
#include "binary_heap.h"

int main (void) ;
void print_item (const Item item) ;

int main (void)
{
	Heap h ;
	Item array[15] = {10, 12, 1, 14, 6, 5, 8, 15, 3, 9, 7, 4, 11, 13, 2} ;
	int capacity = 20, array_size = 15, i, position = 15, triangle = 8 ;

	InitializeHeap (&h, capacity) ;
	for (i = 0; i < array_size; i++)
		Insert (&h, array[i]) ;
//	DeleteMin (&h) ;
//	DeleteMin (&h) ;
//	DeleteMin (&h) ;
//	BuildHeap (&h, array, array_size) ;
	Traversal (&h, print_item) ;
	putchar ('\n') ;
//	Delete (&h, position) ;
//	Delete (&h, position) ;
//	Delete (&h, position) ;
	DecreaseKey (&h, position, triangle) ;
//	DecreaseKey (&h, position, triangle) ;
//	Traversal (&h, print_item) ;
//	Traversal (&h, print_item) ;
//	putchar ('\n') ;
//	i = 15 ;

	Traversal (&h, print_item) ;
	Release (&h) ;

	return 0 ;
}

void print_item (const Item item)
{
	printf ("%d\n", item) ;
}
