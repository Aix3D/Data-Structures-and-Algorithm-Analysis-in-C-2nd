/*  4-30-10-05-10.29.c -- 第四章第三十题	*/
#include <stdio.h>
#include <stdlib.h>
#include "binarysearchtree.h"

int main (void) ;
Tree gen_tree(const int height, int * const lastnode) ;
Tree min_AVL_tree(const int height) ;
void print_item (const Item item) ;
Tree new_min_AVL_tree (const int height) ;
Tree new_print_item (const int height, int * const last_node_assinged) ;

int main (void)
{
	Tree tree ;
	int height = 3 ;

	tree = new_min_AVL_tree (height) ;
	InorderTraversal (tree, print_item) ;

	EmptyTheTree (tree) ;

	return 0 ;
}

/* LastNode is the address containing last value that was assigned to a node */
Tree gen_tree (const int height, int * const lastnode)
{
	Tree tree ;

	if (height >= 0)
	{
		tree = (Node *) malloc (sizeof (Node)) ;
		tree -> left = gen_tree (height - 1, lastnode) ;
		tree -> item = ++*lastnode ;
		tree -> right = gen_tree (height - 2, lastnode) ;
		return tree ;
	}
	else
		return NULL;
}

Tree min_AVL_tree(const int height)
{
	int last_node_assigned = 0 ;

	return gen_tree (height, &last_node_assigned) ;
}

void print_item (const Item item)
{
	printf ("%d", item) ;
}

Tree new_min_AVL_tree (const int height) 
{
	int last_node_assinged = 0 ;

	return new_print_item (height, &last_node_assinged) ;
}

Tree new_print_item (const int height, int * const last_node_assinged)
{
	Tree tree ;

	if (height >= 0)
	{
		tree = (Node *) malloc (sizeof (Node)) ;
		tree -> left = new_print_item (height - 2, last_node_assinged) ;
		tree -> item = ++*last_node_assinged ;
		tree -> right = new_print_item (height - 1, last_node_assinged) ;
		return tree ;
	}
	else
		return NULL ;
}