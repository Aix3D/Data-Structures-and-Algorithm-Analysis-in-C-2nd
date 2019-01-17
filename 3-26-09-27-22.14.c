/*  3-26-09-27-22.14.c -- 第三章第二十六题  */
#include <stdio.h>
#include "doubly_queue.h"

int main (void) ;
void print_item (const Item item) ;

int main (void)
{
	Queue queue ;
	Item item = 0 ;

	InitializeDoublyQueue (&queue) ;
	printf ("%c\n", Pop (&queue)) ;
	printf ("%c\n", Eject (&queue)) ;
	item++ ;
	Inject (&queue, &item) ;
	item++ ;
	Inject (&queue, &item) ;
	item++ ;
	Inject (&queue, &item) ;
	item++ ;
	Inject (&queue, &item) ;
	item++ ;
	Inject (&queue, &item) ;
	item = 1 ;
	Push (&queue, &item) ;
	item++ ;
	Push (&queue, &item) ;
	item++ ;
	Push (&queue, &item) ;
	item++ ;
	Push (&queue, &item) ;
	item++ ;
	Push (&queue, &item) ;
	Traverse (&queue, print_item) ;
	printf ("[%d]", Eject (&queue)) ;
	printf ("[%d]", Eject (&queue)) ;
	printf ("[%d]\n", Eject (&queue)) ;
	printf ("[%d]", Pop (&queue)) ;
	printf ("[%d]", Pop (&queue)) ;
	printf ("[%d]\n", Pop (&queue)) ;
	Traverse (&queue, print_item) ;
	printf ("front:%p\n", queue.front) ;
	printf ("rear:%p\n", queue.rear) ;
	printf ("items:%d\n", queue.items) ;
	EmptyTheDoublyQueue (&queue) ;
	printf ("front:%p\n", queue.front) ;
	printf ("rear:%p\n", queue.rear) ;
	printf ("items:%d\n", queue.items) ;
	return 0 ;
}

void print_item (const Item item)
{
	printf ("%d", item) ;
}