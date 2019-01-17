/*	5-2-10-22-12.56.c -- 第五章第二题	*/
#include <stdio.h>
#include "open_addressing_hash_with_hashing_again.h"

int main (void) ;
void print_cell (const Cell cell) ;

int main (void)
{
	HashTable h ;
	Item item ;
	int size = 5 ;

	InitializeTable (&h, size) ;
	item = 7 ;
	Insert (&h, item) ;
	item = 12 ;
	Insert (&h, item) ;
	item = 17 ;
	Insert (&h, item) ;
	Traversal (&h, print_cell) ;
	putchar ('\n') ;
	item = 22 ;
	Insert (&h, item) ;
	Insert (&h, item) ;
	Delete (&h, item) ;
//	Delete (&h, item) ;
	Traversal (&h, print_cell) ;

	return 0 ;
}

void print_cell (const Cell cell)
{
	if (Legitimate == cell.info)
		printf ("%d\n", cell.item) ;
}