/*	4-46-10-16-09.35.c -- 第四章第二十六题	*/
#include <stdio.h>
#include "2-d_tree.h"

int main (void) ;
void print_node (const Item * const pkey1, const Item * const pkey2) ;

int main (void)
{
	Tree tree ;
	Item key1, key2 ;
	Item low1 = 0, low2 = 0, high1 = 100, high2 = 100 ;

	InitializeTree (&tree) ;
	key1 = 20, key2 = 40 ;
	Insert (&tree, &key1, &key2) ;
	key1 = 10, key2 = 30 ;
	Insert (&tree, &key1, &key2) ;
	key1 = 35, key2 = 20 ;
	Insert (&tree, &key1, &key2) ;
	key1 = 10, key2 = 60 ;
	Insert (&tree, &key1, &key2) ;
	key1 = 50, key2 = 25 ;
	Insert (&tree, &key1, &key2) ;
	key1 = 65, key2 = 11 ;
	Insert (&tree, &key1, &key2) ;
	InorderSeekTraversal (&tree, low1, low2, high1, high2, print_node) ;
	putchar ('\n') ;
	key1 = 20, key2 = 40 ;
	tree = Delete (&tree, &key1, &key2) ;
	InorderSeekTraversal (&tree, low1, low2, high1, high2, print_node) ;

	return 0 ;
}

void print_node (const Item * const pkey1, const Item * const pkey2)
{
	printf ("key1 : %d key2 : %d\n", *pkey1, *pkey2) ;
}