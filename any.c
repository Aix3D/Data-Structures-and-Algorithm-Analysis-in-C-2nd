/*	any.c	*/
#include "SplayTree.h"

int main (void) ;
void printNode (const Node * const pn) ;

int main (void)
{
	SplayTree st ;
	Item item ;

	Create_S (&st) ;
	item = 10 ;
	Insert_S (&st, &item) ;
	item = 9 ;
	Insert_S (&st, &item) ;
	item = 8 ;
	Insert_S (&st, &item) ;
	item = 7 ;
	Insert_S (&st, &item) ;
	item = 6 ;
	Insert_S (&st, &item) ;
	item = 5 ;
	Insert_S (&st, &item) ;
	item = 4 ;
	Insert_S (&st, &item) ;
	item = 3 ;
	Insert_S (&st, &item) ;
	item = 2 ;
	Insert_S (&st, &item) ;
	item = 1 ;
	Insert_S (&st, &item) ;
	item = 55 ;
	Insert_S (&st, &item) ;
	item = 77 ;
	Insert_S (&st, &item) ;
	item = 2 ;
	Insert_S (&st, &item) ;
	item = 75 ;
	Insert_S (&st, &item) ;
	item = 14 ;
	Insert_S (&st, &item) ;
	item = 0 ;
	Insert_S (&st, &item) ;
	item = 1 ;
	Insert_S (&st, &item) ;
	item = 99 ;
	Insert_S (&st, &item) ;
	item = 122 ;
	Insert_S (&st, &item) ;
	item = 18 ;
	Insert_S (&st, &item) ;

	Traversal_S (st -> root, printNode) ;
	putchar ('\n') ;

	item = 5 ;
	Delete_S (&st, &item) ;
	Insert_S (&st, &item) ;
	item = 1 ;
	Delete_S (&st, &item) ;
	Insert_S (&st, &item) ;

	item = -5 ;
	Insert_S (&st, &item) ;
	item = 67 ;
	Insert_S (&st, &item) ;
	item = 654 ;
	Insert_S (&st, &item) ;
	item = 34 ;
	Insert_S (&st, &item) ;
	item = 66 ;
	Insert_S (&st, &item) ;
	item = 54 ;
	Insert_S (&st, &item) ;
	item = 22 ;
	Insert_S (&st, &item) ;
	item = 87 ;
	Insert_S (&st, &item) ;
	item = 65 ;
	Insert_S (&st, &item) ;
	item = 96 ;
	Insert_S (&st, &item) ;
	item = 67 ;
	Insert_S (&st, &item) ;
	item = 43 ;
	Insert_S (&st, &item) ;
	item = 43 ;
	Insert_S (&st, &item) ;
	item = 88 ;
	Insert_S (&st, &item) ;
	item = 887 ;
	Insert_S (&st, &item) ;
	item = 01 ;
	Insert_S (&st, &item) ;
	item = 35 ;
	Insert_S (&st, &item) ;
	item = 887 ;
	Insert_S (&st, &item) ;
	item = 986 ;
	Insert_S (&st, &item) ;
	item = 178 ;
	Insert_S (&st, &item) ;

	Traversal_S (st -> root, printNode) ;
	putchar ('\n') ;

	Release_S (&st) ;

	return 0 ;
}

void printNode (const Node * const pn)
{
	printf ("%-5d", pn -> item) ;
}