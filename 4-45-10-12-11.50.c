/*	4-45-10-12-11.50.c -- �����µ���ʮ����	*/
#include <stdio.h>
#include "threaded_tree.h"

int main (void) ;
void print_item (const Item item) ;
int main (void)
{
	Tree tree ;
	Item item ;

	InitializeTree (&tree) ;
	item = 20 ;
	Insert (&tree, &item) ;
	item = 10 ;
	Insert (&tree, &item) ;
	item = 5 ;
	Insert (&tree, &item) ;
	item = 15 ;
	Insert (&tree, &item) ;
	item = 30 ;
	Insert (&tree, &item) ;
	item = 25 ;
	Insert (&tree, &item) ;
	item = 35 ;
	item = 10 ;
//	tree = Delete (tree, item) ;
	InorderThreading (&tree) ;
	InorderThreadedTraversal (tree, print_item) ;

	return 0 ;
}

void print_item (const Item item)
{
	printf ("%d ", item) ;
}