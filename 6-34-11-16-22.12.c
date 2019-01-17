/*	6-34-11-16-22.12.c -- �����µ���ʮ����	*/
#include <stdio.h>
#include "box.h"

int main (void) ;
void print_box (const Box * const box) ;

int main (void)
{
	BoxTree bt ;
	Weight w ;
	int capacity = GENERIC ;
	
	InitializeBoxTree (&bt, capacity) ;
	w = 7 ;
	DealWithTheBiggest (&bt, w) ;
	w = 1 ;
	DealWithTheBiggest (&bt, w) ;
	w = 15 ;
	DealWithTheBiggest (&bt, w) ;
	w = 7 ;
	DealWithTheBiggest (&bt, w) ;
	w = 1 ;
	DealWithTheBiggest (&bt, w) ;
	w = 4 ;
	DealWithTheBiggest (&bt, w) ;
	w = 25 ;
	DealWithTheBiggest (&bt, w) ;

	w = 3 ;
	DealWithTheSmallest (&bt, w) ;
	w = 2 ;
	DealWithTheSmallest (&bt, w) ;
	w = 6 ;
	DealWithTheSmallest (&bt, w) ;
	w = 30 ;
	DealWithTheSmallest (&bt, w) ;
	w = 1 ;
	DealWithTheSmallest (&bt, w) ;
	w = 2 ;
	DealWithTheSmallest (&bt, w) ;
	w = 5 ;
	DealWithTheSmallest (&bt, w) ;
	w = 7 ;
	DealWithTheSmallest (&bt, w) ;
	w = 1 ;
	DealWithTheSmallest (&bt, w) ;
	w = 3 ;
	DealWithTheSmallest (&bt, w) ;
	w = 1 ;
	DealWithTheSmallest (&bt, w) ;
	InorderTraversal (bt -> root, print_box) ;
	Release (&bt) ;

	return 0 ;
}

void print_box (const Box * const box)
{
	printf ("ʣ������:%-5d ȫ������:%-5d ��ָ��:%p ��ָ��:%p ��ָ��:%p �����ַ:%p\n",
			box -> unoccupied, box -> capacity, box -> parent, box -> left, box -> right, box) ;
}