/*	12-3-11-03-17-21.33.c -- 第十二章第三题	*/
#include <time.h>
#include "SplayTree.h"

int main (void) ;
void printNode (const Node * const pn) ;

int main (void)
{
	SplayTree st ;
	Item item ;
	int i ;

	Create_S (&st) ;

	srand ((unsigned int) time (NULL)) ;
	for (i = 0; i < 100; i++)
	{
		item = rand () % 99999 + 1 ;
		Insert_S (&st, &item) ;
	}

	Traversal_S (st -> root, printNode) ;
	printf ("It is:%-5d\n", FindKthMin_S (&st, 1) -> item) ;
	printf ("It is:%-5d\n", FindKthMin_S (&st, 2) -> item) ;
	printf ("It is:%-5d\n", FindKthMax_S (&st, 100) -> item) ;
	printf ("It is:%-5d\n", FindKthMax_S (&st, 99) -> item) ;
	printf ("It is:%-5d\n", FindKthMin_S (&st, 4) -> item) ;

	printf ("%p\n", st) ;
	Release_S (&st) ;

	return 0 ;
}

void printNode (const Node * const pn)
{
	printf ("%-5d", pn -> item) ;
}