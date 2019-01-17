/*  4-10-09-29-13.03.c -- 第四章第十题  */
#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

int main (void) ;
void print_item (const Item item) ;

int main (void)
{
	Tree tree ;
	Item item ;

	InitializeTree (&tree) ;
	InorderTraversal (tree, print_item) ;
	item = 7 ;
	tree = Insert (tree, item) ;
	item = 6 ;
	tree = Insert (tree, item) ;
	item = 4 ;
	tree = Insert (tree, item) ;
	item = 2 ;
	tree = Insert (tree, item) ;
	item = 5 ;
	tree = Insert (tree, item) ;
	item = 15 ;
	tree = Insert (tree, item) ;
	item = 8 ;
	tree = Insert (tree, item) ;
	item = 12 ;
	tree = Insert (tree, item) ;
	item = 16 ;
	tree = Insert (tree, item) ;
	item = 17 ;
	tree = Insert (tree, item) ;
	item = 21 ;
	tree = Insert (tree, item) ;
	InorderTraversal (tree, print_item) ;
	putchar ('\n') ;
	item = 15 ;
	tree = Delete (tree, item) ;
	InorderTraversal (tree, print_item) ;
	EmptyTheTree (tree) ;

	return 0 ;
}

void print_item (const Item item)
{
	printf ("%d", item) ;
}