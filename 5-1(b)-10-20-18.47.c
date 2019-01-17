/*	5-1(b)-10-20-18.4.c -- 第五章第一题	*/
#include <stdio.h>
#include "open_addressing_hash.h"

int main (void) ;
void print_cell (const Cell cell) ;

int main (void)
{
	HashTable h ;
	Item item ;
	int size = 3 ;

	InitializeTable (&h, size) ;
	item = 0 ;
	Insert (&h, item) ;
	item = 1 ;
	Insert (&h, item) ;
	item = 2 ;
	Insert (&h, item) ;
	Delete (&h, item) ;
	Insert (&h, item) ;
	Traversal (&h, print_cell) ;
//	printf ("%d\n", Find (&h, item) -> item) ;
	Release (&h) ;
//	printf ("%p\n", h -> lists) ;

	return 0 ;
}

void print_cell (const Cell cell)
{
	if (cell.info == Legitimate)
		printf ("%d\n", cell.item) ;
}