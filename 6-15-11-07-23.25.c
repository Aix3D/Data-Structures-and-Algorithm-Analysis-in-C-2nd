/*	6-15-11-07-23.25.c -- 第六章第十五题	*/
#include <stdio.h>
#include "min-max_heap.h"

int main (void) ;
void print_item (const Item item) ;

int main (void)
{
	Heap h ;
	int array[15] = {10, 77, 2, 14, 6, 5, 8, 15, 55, 9, 7, 9, 11, 13, 4} ;
	int capacity = 20, size = 15, ct = 0 ;

	InitializeHeap (&h, capacity) ;
	for (ct = 0; ct < size; ct++)
		Insert (&h, array[ct]) ;
	Traversal (&h, print_item) ;
	printf ("\n%d\n\n", DeleteMin (&h)) ;
	Traversal (&h, print_item) ;

	return 0 ;
}

void print_item (const Item item)
{
	printf ("%d\n", item) ;
}