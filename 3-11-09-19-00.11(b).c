/*  3-11-09-19-00.11(b).c -- 第三章第十一题  */
#include <stdio.h>
#include "unidirectional_linked_list.h"

int main (void) ;
void print_list (const Item * pitem) ;

int main (void)
{
	List list ;
	int i ;

	InitializeList (&list) ;
	for (i = 0; i < 5; i++)
		AddItem (&list, &i) ;
	Traverse (&list, print_list) ;
	DeleteItem (&list, &i) ;
	Traverse (&list, print_list) ;

	return 0 ;
}

void print_list (const Item * pitem)
{
	printf ("%d ", *pitem) ;
}
