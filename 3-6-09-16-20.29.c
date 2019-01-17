/*  3-6-09-16-20.29.c -- 第三章第六题  */
#include <stdio.h>
#include "unidirectional_linked_list.h"
#define SIZE 5

int main (void) ;
List plus (const int *, const int *, const int, const int) ;
void print_list (const Item * pitem) ;

int main (void)
{
	List list_new ;
	int arr_1[SIZE] = {1, 2, 7, 9, -1} ;
	int arr_2[SIZE] = {0, -5, 9, 22, 10} ;

	list_new = plus (arr_1, arr_2, 5, 5) ;
	Traverse (&list_new, print_list) ;

	return 0 ;
}

List plus (const int * supe_arr_1, const int * supe_arr_2, const int supe_size_1, const int supe_size_2)
{
	List new_list ;
	Item item ;
	int count = 0 ;

	InitializeList (&new_list) ;
	/*	循环条件是只要存在一个未越界的数组	*/
	while (count < supe_size_1 || count < supe_size_2)
	{
		item = 0 ;
		if (count < supe_size_1)
			item += *(supe_arr_1 + count) ;
		if (count < supe_size_2)
			item += *(supe_arr_2 + count) ;
		AddItem (&new_list, &item) ;
		count ++ ;
	}
	
	return new_list ;
}

void print_list (const Item * pitem)
{
	printf ("%d ", *pitem) ;
}