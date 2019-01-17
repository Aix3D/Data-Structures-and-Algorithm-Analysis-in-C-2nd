/* 3-2-09-15-19.33.c -- 第三章第二题  */
#include <stdio.h>
#include "linked_list.h"

int main (void) ;
void print_linked_list (const Position posi_p, const Position posi_l) ;

int main (void)
{
	List P, L ;
	int i ;
	
	InitializeList (&P) ;
	InitializeList (&L) ;

	for (i = 0; i < 5; i++)
		if (1 == i || 3 == i || 4 == i)
			AddItem (&P, &i) ;
	for (i = 0; i < 5; i++)
		AddItem (&L, &i) ;

	print_linked_list (P, L) ;
	DeleteList (&P) ;

	return 0 ;
}

void print_linked_list (const Position posi_p, const Position posi_l)
{
	Position temp = posi_l ;
	Item index ;
	int i = 0 ;

	if (posi_p == NULL)
		return ;
	/*	依次读入链表posi_p -> item到索引	*/
	index = posi_p -> item ;
	/*	前进到第index个节点	*/
	while (temp != NULL && i < index)
	{
		temp = temp -> next ;
		i++ ;
	}
	if (temp != NULL)
	{
		printf ("%d ", temp -> item) ;
		print_linked_list (posi_p -> next, posi_l) ;
	}
	else
	{
		printf ("链表中无相应数据\n") ;
		return ;
	}
}