/*	6-19-11-10-03.21.c -- 第六章第十九题	*/
#define SIZE 15
#define CAONIMA(x) printf ("%d\n", x)

#include <stdio.h>
#include "lefttist_heap.h"

int main (void) ;

int main (void)
{
	Heap heap ;
	Item array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15} ;
	int ct, size = SIZE ;


	CreateANullHeap (&heap) ;
	heap = Bulid (heap, array, size) ;
//	for (ct = 0, size = SIZE; ct < size; ct++)
//		INSERT (heap, array[ct]) ;
	LevelOrderTraversal (heap) ;
	putchar ('\n') ;
//	DELETEMIN (heap) ;
//	printf ("%p\n", Find (heap, array[17])) ;
//	putchar ('\n') ;
//	LevelOrderTraversal (heap) ;

	return 0 ;
}