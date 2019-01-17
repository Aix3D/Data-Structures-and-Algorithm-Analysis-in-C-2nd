/*	5-1(d)-10-21-19.10.c -- 第五章第一题(d)	*/
#include <stdio.h>
#include "open_addressing_double_hash.h"

int main (void) ;
void print_cell (const Cell cell) ;

int main (void)
{
	HashTable h ;
	Item item ;
	int size = 11 ;

	InitializeTable (&h, size) ;
	item = 1 ;
	Insert (&h, item) ;
	item = 12 ;
	Insert (&h, item) ;
	item = 23 ;
	Insert (&h, item) ;
	item = 34 ;
	Insert (&h, item) ;
	item = 45 ;
	Insert (&h, item) ;
	item = 56 ;
	Insert (&h, item) ;
	item = 67 ;
	Insert (&h, item) ;
	item = 78 ;
	Insert (&h, item) ;
	item = 89 ;
	Insert (&h, item) ;
	item = 100 ;
	Insert (&h, item) ;
	item = 111 ;
	Insert (&h, item) ;
	item = 100 ;
	Delete (&h, item) ;
	Insert (&h, item) ;
	Traversal (&h, print_cell) ;
	Release (&h) ;
	
	return 0 ;
}

void print_cell (const Cell cell)
{
	if (Legitimate == cell.info)
		printf ("%d\n", cell.item) ;
}