/*  4-32-10-05-13.41.c -- 第四章第三十二题	*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BinarySearchTree.h"

int main (void) ;
static Tree make_random_tree (const int lower, const int upper) ;
static int rand_int (const int lower, const int upper) ;
static void seek_and_print (const Tree tree, const Item k1, const Item k2) ;

int main (void)
{
	Tree tree ;
	int lower = 3, upper = 10 ;

	tree = make_random_tree (lower, upper) ;
	lower = 4 ;
	upper = 9 ;
	seek_and_print (tree, lower, upper) ;

	EmptyTheTree (tree) ;

	return 0 ;
}

static Tree make_random_tree (const int lower, const int upper)
{
	Tree tree ;
	int random_value ;

	InitializeTree (&tree) ;
	if (lower <= upper)
	{
		tree = (Node *) malloc (sizeof (Node)) ;
		if (tree != NULL)
		{
			tree -> item = random_value = rand_int (lower, upper) ;
			tree -> left = make_random_tree (lower, random_value - 1) ;
			tree -> right = make_random_tree (random_value + 1, upper) ;
		}
		else
			puts ("Out of space!") ;
	}

	return tree ;
}


static int rand_int (const int lower, const int upper)
{
	return rand () % (upper - lower + 1) + lower ;
}


static void seek_and_print (const Tree tree, const Item k1, const Item k2)
{
	if (tree != NULL)
	{
		if (tree -> item >= k1)
			seek_and_print (tree -> left, k1, k2) ;
		if (tree -> item >= k1 && tree -> item <= k2)
			printf ("%d", tree -> item) ;
		if (tree -> item <= k2)
			seek_and_print (tree -> right, k1, k2) ;
	}
}