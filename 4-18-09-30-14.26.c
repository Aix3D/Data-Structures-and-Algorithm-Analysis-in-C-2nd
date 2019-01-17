/*  4-18-09-30-14.26.c -- 第四章第十八题	*/
#include <stdio.h>
#include "AVLTree.h"

void print_item (const Position position) ;
int main (void) ;

int main (void)
{
	Tree tree ;
	Item item ;

	InitializeAVLTree (&tree) ;
	item = 20 ;
	tree = AddItem (tree, item) ;
	item = 10 ;
	tree = AddItem (tree, item) ;
	item = 30 ;
	tree = AddItem (tree, item) ;
	item = 8 ;
	tree = AddItem (tree, item) ;
	item = 15 ;
	tree = AddItem (tree, item) ;
	item = 6 ;
	tree = AddItem (tree, item) ;
	InorderTraversal (tree, print_item) ;
	putchar ('\n') ;
//	printf ("%d\n", tree -> right -> right -> item) ;
	EmptyTheAVLTree (tree) ;

	return 0 ;
}

void print_item (const Position position)
{
	printf (" %d ", position -> item) ;
}