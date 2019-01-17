/*	12-5-11-03-10-23.08.c -- 第十二章第五题	*/
#include "RedBlackTree.h"

int main (void) ;
void printNode (const Node * const pn) ;

int main (void)
{
	RedBlackTree rbt ;
	Item item ;

	Create_R (&rbt) ;

	item = 10 ;
	Insert_R (&rbt, item) ;
	item = 85 ;
	Insert_R (&rbt, item) ;
	item = 15 ;
	Insert_R (&rbt, item) ;
	item = 70 ;
	Insert_R (&rbt, item) ;
	item = 20 ;
	Insert_R (&rbt, item) ;
	item = 60 ;
	Insert_R (&rbt, item) ;
	item = 30 ;
	Insert_R (&rbt, item) ;
	item = 50 ;
	Insert_R (&rbt, item) ;
	item = 65 ;
	Insert_R (&rbt, item) ;
	item = 80 ;
	Insert_R (&rbt, item) ;
	item = 90 ;
	Insert_R (&rbt, item) ;
	item = 40 ;
	Insert_R (&rbt, item) ;
	item = 5 ;
	Insert_R (&rbt, item) ;
	item = 55 ;
	Insert_R (&rbt, item) ;
	item = 45 ;
	Insert_R (&rbt, item) ;

	Traversal_R (&rbt, printNode) ;

	item = 70 ;
	Delete_R (&rbt, item) ;
	item = 121 ;
	Insert_R (&rbt, item) ;
	item = 18 ;
	Insert_R (&rbt, item) ;
	item = 0 ;
	Delete_R (&rbt, item) ;
	item = 5 ;
	Delete_R (&rbt, item) ;
	item = 14 ;
	Insert_R (&rbt, item) ;
	item = 66 ;
	Insert_R (&rbt, item) ;
	Delete_R (&rbt, item) ;
	item = 44 ;
	Insert_R (&rbt, item) ;
	item = 56 ;
	Insert_R (&rbt, item) ;
	item = 87 ;
	Insert_R (&rbt, item) ;
	item = 98 ;
	Insert_R (&rbt, item) ;
	item = 22 ;
	Insert_R (&rbt, item) ;
	item = 13 ;
	Insert_R (&rbt, item) ;
	item = 17 ;
	Insert_R (&rbt, item) ;
	item = 18 ;
	Delete_R (&rbt, item) ;
	item = 63 ;
	Insert_R (&rbt, item) ;
	item = 34 ;
	Insert_R (&rbt, item) ;
	item = 64 ;
	Insert_R (&rbt, item) ;
	item = 99 ;
	Insert_R (&rbt, item) ;
	item = 53 ;
	Insert_R (&rbt, item) ;
	item = 11 ;
	Insert_R (&rbt, item) ;
	item = 4 ;
	Insert_R (&rbt, item) ;
	item = 90 ;
	Delete_R (&rbt, item) ;
	item = 80 ;
	Delete_R (&rbt, item) ;

	Traversal_R (&rbt, printNode) ;
	Release_R (&rbt) ;

	return 0 ;
}

void printNode (const Node * const pn)
{
	printf ("%-5d", pn -> item) ;
}