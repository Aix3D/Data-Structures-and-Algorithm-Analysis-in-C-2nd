/*	3-25(a)-09-27-13.21.c -- 第三章第二十五题	*/
#include <stdio.h>
#include "queue_achievied_by_linked_list.h"

int main (void) ;
void print_int (const Item item) ;

int main (void)
{
	Queue queue ;
	Item item = 1 ;

	InitializeQueue (&queue) ;
	EnQueue (&queue, &item) ;
	DeQueue (&queue, &item) ;
	Traverse (&queue, print_int) ;
	EmptyTheQueue (&queue) ;

	return 0 ;
}

void print_int (const Item item)
{
	printf ("%d", item) ;
}