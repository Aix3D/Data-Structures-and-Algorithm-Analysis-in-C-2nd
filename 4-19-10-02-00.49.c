/*  4-19-10-02-00.49.c -- 第四章第十九题	*/
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
	item = 5 ;
	tree = AddItem (tree, item) ;
	item = 15 ;
	tree = AddItem (tree, item) ;
	item = 40 ;
	tree = AddItem (tree, item) ;
	item = 50 ;
	tree = Insert (tree, item) ;
	item = 4 ;
	tree = Insert (tree, item) ;
	item = 3 ;
	tree = Insert (tree, item) ;
	item = 25 ;
	tree = Insert (tree, item) ;
	item = 28 ;
	tree = Insert (tree, item) ;
	item = 6 ;
	tree = Insert (tree, item) ;
	item = 29 ;
	tree = Insert (tree, item) ;
/*	item = 65 ;
	tree = Insert (tree, item) ;
	item = 100 ;
	tree = Insert (tree, item) ;
	item = 10 ;
	tree = Insert (tree, item) ;
	item = 25 ;
	tree = Insert (tree, item) ;
	item = 40 ;
	tree = Insert (tree, item) ;
	item = 47 ;
	tree = Insert (tree, item) ;
	item = 60 ;
	tree = Insert (tree, item) ;
	item = 110 ;
	tree = Insert (tree, item) ;
	item = 70 ;
	tree = Insert (tree, item) ;
	item = 8 ;
	tree = Insert (tree, item) ;
	item = 27 ;
	tree = Insert (tree, item) ;*/
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