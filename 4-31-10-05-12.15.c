/*  4-31-10-05-12.15.c -- 第四章第三十一题	*/
#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

int main (void) ;
Tree generate_ideal_binary_search_tree (const int height, int * const assigned_min) ;
void print_item (const Item item) ;

int main (void)
{
	Tree tree ;
	int height = 9, assigned_min = 1 ;
	
	tree = generate_ideal_binary_search_tree (height, &assigned_min) ;
	InorderTraversal (tree, print_item) ;
	EmptyTheTree (tree) ;

	return 0 ;
}

Tree generate_ideal_binary_search_tree (const int height, int * const assigned_min)
{
	Tree tree ;

	if (height >= 0)
	{
		tree = (Node *) malloc (sizeof (Node)) ;
		tree -> left = generate_ideal_binary_search_tree (height - 1, assigned_min) ;
		tree -> item = (*assigned_min)++ ;
		tree -> right = generate_ideal_binary_search_tree (height - 1, assigned_min) ;
		return tree ;
	}
	else
		return NULL ;
}

void print_item (const Item item)
{
	printf ("%d", item) ;
}