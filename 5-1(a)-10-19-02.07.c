/*	5-1(a)-10-19-02.07.c -- 第五章第一题a	*/
#include <stdio.h>
#include "Separate_Chaining_Hash.h"

int main (void) ;
void print_list_node (const ListNode * const pnode) ;

int main (void)
{
	HashTable h ;
	int size = 10 ;
	Item item ;

	h = InitializeTable (size) ;
	item = 4371 ;
	Insert (item, &h) ;
	item = 1323 ;
	Insert (item, &h) ;
	item = 6173 ;
	Insert (item, &h) ;
	item = 4199 ;
	Insert (item, &h) ;
	item = 4344 ;
	Insert (item, &h) ;
	item = 9679 ;
	Insert (item, &h) ;
	item = 1989 ;
	Insert (item, &h) ;
	Traversal (&h, print_list_node) ;
	putchar ('\n') ;
	item = 102 ;
	Delete (item, &h) ;
	Traversal (&h, print_list_node) ;
	printf ("%p\n", h) ;
	Release (&h) ;

	return 0 ;
}


void print_list_node (const ListNode * const pnode)
{
	printf ("%d\n", pnode -> item) ;
}