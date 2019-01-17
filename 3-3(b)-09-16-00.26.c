/*  3-3(b)-09-16-00.26.c -- 第三章第三题b  */
#include <stdio.h>
#include "bidirectional_linked_list.h"
#define SIZE 5

int main (void) ;
void print_list (const Item * pitem) ;

int main (void)
{
	List list ;
	int i ;

	InitializeList (&list) ;

	for (i = 0; i < SIZE; i++)
		AddItem (&list, &i) ;
	Traverse (&list, print_list) ;
	if (1 == SwapPosition (list -> next -> next))
		Traverse (&list, print_list) ;
	else
		printf ("交换失败\n") ;

	return 0 ;
}

void print_list (const Item * pitem)
{
	printf ("%d ", *pitem) ;
}