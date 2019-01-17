/*  04-27-10-03-18.41.c -- 第四章第二十七题	*/
#include <stdio.h>
#include "splay_tree.h"

int main (void) ;
void print_item (const Item item) ;

int main (void)
{
	SplayTree tree ;
	Item item ;

	IintializeSplayTree (&tree) ;
	item = 10 ;
	tree = AddItem (tree, item) ;
	item = 11 ;
	tree = AddItem (tree, item) ;
	item = 12 ;
	tree = Insert (tree, item) ;
	item = 13 ;
	tree = AddItem (tree, item) ;
	item = 4 ;
	tree = AddItem (tree, item) ;
	item = 6 ;
	tree = AddItem (tree, item) ;
	item = 2 ;
	tree = Insert (tree, item) ;
	item = 1 ;
	tree = AddItem (tree, item) ;
	item = 3 ;
	tree = Insert (tree, item) ;
	item = 5 ;
	tree = AddItem (tree, item) ;
	item = 8 ;
	tree = AddItem (tree, item) ;
	item = 7 ;
	tree = AddItem (tree, item) ;
	item = 9 ;
	tree = AddItem (tree, item) ;
	InorderTraversal (tree, print_item) ;
	putchar ('\n') ;
	printf ("[%d]\n", tree -> item) ;
	item = 3 ;
	tree = Find_By_Use_Stack (tree, item) ;
	InorderTraversal (tree, print_item) ;
	printf ("[%d]\n", tree -> item) ;
	item = 9 ;
	tree = Find_By_Use_Stack (tree, item) ;
	InorderTraversal (tree, print_item) ;
	printf ("[%d]\n", tree -> item) ;
	item = 1 ;
	tree = Find_By_Use_Stack (tree, item) ;
	InorderTraversal (tree, print_item) ;
	printf ("[%d]\n", tree -> item) ;
	item = 5 ;
	tree = Find_By_Use_Stack (tree, item) ;
	InorderTraversal (tree, print_item) ;
	printf ("[%d]\n", tree -> item) ;
	item = 6 ;
	tree = Delete (tree, item) ;
	InorderTraversal (tree, print_item) ;
	printf ("[%d]\n", tree -> item) ;

	return 0 ;
}

void print_item (const Item item)
{
	printf ("%d", item) ;
}