/*  4-33-10-05-19.45.c -- 第四章第三十二题	*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "binary_search_tree.h"

int main (void) ;
static void calculate_depth (Tree * const ptree, const int incipient_depth) ;
static Node * search_the_deepmost_node (const Tree tree) ;
static void calculate_the_coordinate_of_x (Tree * const ptree, int * const incipient_coordinate_value) ;
static void calculate_the_coordinate_of_y (Tree * const ptree, const int deepmost_depth) ;
static void print_item (const Item item) ;
static void random_generate (Tree * const ptree, const int size) ;
static int generate_random_value (const int max_index) ;

int main (void)
{
	Tree tree ;
	Node * the_deepmost_node ;
	Item item = 5 ;
	int incipient_coordinate_value = 0 ;
	int size = 10 ;
	int maximal_depth ;
	const int incipient_depth = 0 ;

	InitializeTree (&tree) ;
	random_generate (&tree, size) ;											/*	随机生成size个结点的二叉搜索树	*/
	item = 6 ;
	tree = Delete (tree, item) ;
	calculate_depth (&tree, incipient_depth) ;								/*	为结点赋予深度值	*/
	the_deepmost_node = search_the_deepmost_node (tree) ;					/*	获得最深结点	*/
	maximal_depth = the_deepmost_node -> depth ;							/*	获得最大深度值	*/
	calculate_the_coordinate_of_x (&tree, &incipient_coordinate_value) ;	/*	设置X轴坐标	*/	
	calculate_the_coordinate_of_y (&tree, maximal_depth) ;					/*	设置y轴坐标	*/
	InorderTraversal (tree, print_item) ;
	putchar ('\n') ;
	EmptyTheTree (tree) ;

	return 0 ;
}

static void calculate_depth (Tree * const ptree, const int incipient_depth)
{
	if (*ptree != NULL)
	{
		(*ptree) -> depth = incipient_depth ;
		calculate_depth (&(*ptree) -> left, incipient_depth + 1) ;
		calculate_depth (&(*ptree) -> right, incipient_depth + 1) ;
	}
}

static Node * search_the_deepmost_node (const Tree tree)
{
	Node * left_node, * right_node ;

	if (tree != NULL)
	{
		left_node = search_the_deepmost_node (tree -> left) ;
		right_node = search_the_deepmost_node (tree -> right) ;
		if (NULL == left_node && NULL == right_node)
			return tree ;
		else if (NULL == left_node)
			return right_node ;
		else if (NULL == right_node)
			return left_node ;
		else
			return left_node -> depth >= right_node -> depth ? left_node : right_node ;
	}
	else
		return NULL ;
}

static void calculate_the_coordinate_of_x (Tree * const ptree, int * const incipient_coordinate_value)
{
	if ((*ptree) != NULL)
	{
		calculate_the_coordinate_of_x (&(*ptree) -> left, incipient_coordinate_value) ;
		(*ptree) -> x_coordinate = (*incipient_coordinate_value)++ ;
		calculate_the_coordinate_of_x (&(*ptree) -> right, incipient_coordinate_value) ;
	}
}

static void calculate_the_coordinate_of_y (Tree * const ptree, const int deepmost_depth)
{
	if ((*ptree) != NULL)
	{
		(*ptree) -> y_coordinate = deepmost_depth - (*ptree) -> depth ;
		calculate_the_coordinate_of_y (&(*ptree) -> left, deepmost_depth) ;
		calculate_the_coordinate_of_y (&(*ptree) -> right, deepmost_depth) ;
	}
}

static void print_item (const Item item)
{
	printf ("%d ", item) ;
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
		Insert (ptree, array + index) ;
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