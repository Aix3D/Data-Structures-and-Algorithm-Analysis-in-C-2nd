/*  4-28-10-04-13.25.c -- 第四张第二十八题	*/
#include <stdio.h>
#include "BinarySearchTree.h"

int main (void) ;
static int node_count (const Tree tree) ;
static int leaf_count (const Tree tree) ;
static int full_count (const Tree tree) ;
static int new_node_count (const Tree tree) ;
static int new_leaf_count (const Tree tree) ;
static int new_full_count (const Tree tree) ;

int main (void)
{
	Tree tree ;
	Item item ;

	InitializeTree (&tree) ;
	item = 10 ;
	tree = Insert (tree, item) ;
	item = 5 ;
	tree = Insert (tree, item) ;
	item = 32 ;
	tree = Insert (tree, item) ;
	item = 2 ;
	tree = Insert (tree, item) ;
	item = 8 ;
	tree = Insert (tree, item) ;
	item = 40 ;
	tree = Insert (tree, item) ;
	item = 20 ;
	tree = Insert (tree, item) ;
	item = 15 ;
	tree = Insert (tree, item) ;
	item = 2 ;
	tree = Insert (tree, item) ;
	item = 7 ;
	tree = Insert (tree, item) ;

	printf ("结点数:[%d], 叶结点数:[%d], 满结点数:[%d]\n", node_count (tree), leaf_count (tree), full_count (tree)) ;
	printf ("结点数:[%d], 叶结点数:[%d], 满结点数:[%d]\n", new_node_count (tree), new_leaf_count (tree), new_full_count (tree)) ;
	EmptyTheTree (tree) ;

	return 0 ;
}

static int node_count (const Tree tree)
{
	int the_number_of_left_subtree = 0, the_number_of_right_subtree = 0, the_number_of_node = 0 ;

	if (tree != NULL)
	{
		the_number_of_left_subtree = node_count (tree -> left) ;
		the_number_of_right_subtree = node_count (tree -> right) ;
		the_number_of_node = the_number_of_left_subtree + the_number_of_right_subtree + 1 ;
	}

	return the_number_of_node ;
}

static int leaf_count (const Tree tree)
{
	int the_number_of_left_subtree = 0, the_number_of_right_subtree = 0, the_number_of_leaf = 0 ;

	if (tree != NULL)
	{
		the_number_of_left_subtree = leaf_count (tree -> left) ;
		the_number_of_right_subtree = leaf_count (tree -> right) ;
		the_number_of_leaf = the_number_of_left_subtree + the_number_of_right_subtree ;
		if (0 == the_number_of_left_subtree && 0 == the_number_of_right_subtree)
			the_number_of_leaf++ ;
	}

	return the_number_of_leaf ;
}

static int full_count (const Tree tree)
{
	int the_number_of_left_subtree = 0, the_number_of_right_subtree = 0, the_number_of_full_node = 0 ;

	if (tree != NULL)
	{
		the_number_of_left_subtree = full_count (tree -> left) ;
		the_number_of_right_subtree = full_count (tree -> right) ;
		if (the_number_of_left_subtree != 0 && the_number_of_right_subtree != 0)
			the_number_of_full_node += the_number_of_left_subtree + the_number_of_right_subtree + 1 ;
		else if (tree -> left != NULL && tree -> right != NULL)
			the_number_of_full_node++ ;
	}

	return the_number_of_full_node ;
}

static int new_node_count (const Tree tree)
{
	if (NULL == tree)
		return 0;
	return 1 + new_node_count (tree -> left) + new_node_count (tree -> right) ;
}

static int new_leaf_count (const Tree tree)
{
	if (NULL == tree)
		return 0;
	else if (NULL == tree -> left && NULL == tree -> right)
		return 1;
	return new_leaf_count (tree -> left) + new_leaf_count (tree -> right) ;
}

static int new_full_count (const Tree tree)
{
	if (NULL == tree)
		return 0;
	return (tree -> left != NULL && tree -> right != NULL) + new_full_count (tree -> left) + new_full_count (tree -> right) ;
}