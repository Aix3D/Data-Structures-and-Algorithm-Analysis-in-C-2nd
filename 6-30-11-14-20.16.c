/*	6-30-11-14-20.16.c -- 第六章第三十题	*/
#include <stdio.h>
#include "binomial-queue.h"

int main (void) ;
void print_item (const Item item) ;

int main (void)
{
	BinQueue bq1, bq2 ;
	Item item ;
	int size = 50 ;

	InitializeBinQueue (&bq1, size) ;
	InitializeBinQueue (&bq2, size) ;
	item = 1 ;
	bq1 = Insert (bq1, item) ;
	item = 1 ;
	bq1 = Insert (bq1, item) ;
//	item = 2 ;
//	bq2 = Insert (bq2, item) ;
	bq1 = Merge (bq1, bq2) ;
	Traversal (bq1, print_item) ;
	printf ("\n%p\n", bq1 -> size) ;
//	putchar ('\n') ;
/*	printf ("%d\n", DeleteMin (bq1)) ;
	putchar ('\n') ;
	Traversal (bq1, print_item) ;*/
	Release (bq1) ;
	Release (bq2) ;

	return 0 ;
}

void print_item (const Item item)
{
	printf ("%d\n", item) ;
}