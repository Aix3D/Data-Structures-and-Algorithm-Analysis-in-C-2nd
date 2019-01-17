/*  4-35-10-06-14.11.c -- 第四章第三十五题	*/
#include <stdio.h>
#include "new_queue.h"

int main (void) ;
void print_item (const Item item) ;
void level_inorder_traversal (const Tree tree) ;

int main (void)
{
	Tree tree ;
	Item item ;

	InitializeTree (&tree) ;
	item = 10 ;
	Insert (&tree, &item) ;
	item = 5 ;
	Insert (&tree, &item) ;
	item = 20 ;
	Insert (&tree, &item) ;
	item = 8 ;
	Insert (&tree, &item) ;
	item = 15 ;
	Insert (&tree, &item) ;

	InorderTraversal (tree, print_item) ;
	putchar ('\n') ;
	level_inorder_traversal (tree) ;
	
	EmptyTheTree (tree) ;
	
	return 0 ;
}

void print_item (const Item item)
{
	printf ("%d", item) ;
}

void level_inorder_traversal (const Tree tree)
{
	Queue queue ;
	QueueItem temp ;
	
	InitializeQueue (&queue) ;

	EnQueue (&queue, &tree) ;
	while (!QueueIsEmpty (&queue))
	{
		temp = DeQueue (&queue) ;
		print_item (temp -> item) ;
		if (temp -> left != NULL)
			EnQueue (&queue, &temp -> left) ;
		if (temp -> right != NULL)
			EnQueue (&queue, &temp -> right) ;
	}
}
