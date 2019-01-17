/*	10-36-11-02-12-00.05.c -- 第十章第三十六题	*/
/*	06.14 完成了, 大概4.5小时	*/
#include "SkipList.h"

int main (void) ;
void printNode (const Node * const pn) ;

int main (void)
{
	SkipList sl ;
	Item item ;
	int capacity = 20 ;

	InitializSeed_S (73L) ;
	Initialize_S (&sl, capacity) ;
	item = 2 ;
	Insert_S (&sl, &item) ;
	item = 8 ;
	Insert_S (&sl, &item) ;
	item = 10 ;
	Insert_S (&sl, &item) ;
	item = 11 ;
	Insert_S (&sl, &item) ;
	item = 13 ;
	Insert_S (&sl, &item) ;
	item = 19 ;
	Insert_S (&sl, &item) ;
	item = 20 ;
	Insert_S (&sl, &item) ;
	item = 23 ;
	Insert_S (&sl, &item) ;
	item = 29 ;
	Insert_S (&sl, &item) ;
	item = 29 ;
	Insert_S (&sl, &item) ;
	item = 22 ;
	Insert_S (&sl, &item) ;
	Traversal_S (&sl, printNode) ;
	item = 19 ;
	printf ("%d\n", Find_S (&sl, &item)) ;
	putchar ('\n') ;
	item = 19 ;
	Delete_S (&sl, &item) ;
	Traversal_S (&sl, printNode) ;
	printf ("%d\n", Find_S (&sl, &item)) ;

	Release_S (&sl) ;

	return 0 ;
}

void printNode (const Node * const pn)
{
	int i, height ;

	printf ("Item is : %-5d times is : %d height is : %d address is : %p ", pn -> item, pn -> times, pn -> height, pn) ;
	for (i = 0, height = pn -> height; i < height; i++)
		printf ("next[%d] is %p ", i, pn -> next[i]) ;
	putchar ('\n') ;
}