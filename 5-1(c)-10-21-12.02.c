/*	5-1(c)-10-21-12.02 -- 第五章第一题c	*/
#include <stdio.h>
#include "open_addressing_hash(2).h"

int main (void) ;
void print_cell (const Cell cell) ;

int main (void)
{
	HashTable h ;
	Item item ;
	int size = 11 ;

	InitializeTable (&h, size) ;
	item = 7 ;
	Insert (&h, item) ;
	item = 18 ;
	Insert (&h, item) ;
	item = 29 ;
	Insert (&h, item) ;
	item = 40 ;
	Insert (&h, item) ;
	item = 51 ;
	Insert (&h, item) ;
	item = 62 ;
	Insert (&h, item) ;
	item = 73 ;
	Insert (&h, item) ;
	item = 29 ;
	Delete (&h, item) ;
	Traversal (&h, print_cell) ;
	Release (&h) ;

	return 0 ;
}

void print_cell (const Cell cell)
{
	if (Legitimate == cell.entry)
		printf ("%d\n", cell.item) ;
}