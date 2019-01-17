/*  4-29-10-04-15.28.c --  第四章第二十九题  */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "binarysearchtree.h"

int main (void) ;
static void random_generate (Tree * const ptree, const int size) ;
static int generate_random_value (const int max_value) ;
static void print_item (const Item item) ;
static Tree make_random_tree (const int lower, const int upper) ;
static int rand_int (const int lower, const int upper) ;

int main (void)
{
	Tree tree ;
	int size = 1000000 ;

	InitializeTree (&tree) ;
	random_generate (&tree, size) ;
//	tree = make_random_tree (1, 1000000) ;
	InorderTraversal (tree, print_item) ;
	EmptyTheTree (tree) ;

	return 0 ;
}

static void random_generate (Tree * const ptree, const int size)
{
	int * array, count, index ;

	srand ((unsigned int) time (NULL)) ;
	array = (int *) malloc (sizeof (int) * size) ;
	if (NULL == array)
	{
		puts ("Out of memory.") ;
		return ;
	}
	for (count = 0; count < size; count++)
		*(array + count) = count + 1 ;
	count = size - 1 ;
	while (count > -1)
	{
		index = generate_random_value (count) ;
		(*ptree) = Insert (*ptree, *(array + index)) ;
		if (index != count)
			*(array + index) = *(array + count) ;
		count-- ;
	}
	free (array) ;
}

static int generate_random_value (const int max_index)
{
	return 0 == max_index ? 0 : rand () % max_index + 1 ;
}

static void print_item (const Item item)
{
	printf ("%d ", item) ;
}

static Tree make_random_tree (const int lower, const int upper)
{
	Tree tree;
	int random_value ;

	InitializeTree (&tree) ;
	if (lower <= upper)
	{
		tree = (Node *) malloc(sizeof (Node)) ;
		if(tree != NULL)
		{
			tree -> item = random_value = rand_int (lower, upper) ;
			tree -> left = make_random_tree (lower, random_value - 1) ;
			tree -> right = make_random_tree (random_value + 1, upper);
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