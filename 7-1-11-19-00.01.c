/*	7-1-11-19-00.01.c -- 第七章第一题	*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

typedef int Item ;

int main (void) ;
void insert_sort (Item * array, const int size) ;
void print_array (const Item * const array, const int size) ;

int main (void)
{
	Item array[SIZE] = {3, 1, 4, 1, 5, 9, 2, 6, 5} ;
	int size = SIZE ;
	
	print_array (array, size) ;
	insert_sort (array, size) ;
	print_array (array, size) ;

	return 0 ;
}

void insert_sort (Item * array, const int size)
{
	Item temp ;
	int ct_lin, position ;

	for (position = 1; position < size; position++)
	{
		temp = array[position] ;
		for (ct_lin = position; ct_lin > 0 && array[ct_lin - 1] > temp; ct_lin--)
			array[ct_lin] = array[ct_lin - 1] ;
		array[ct_lin] = temp ;
	}
}

void print_array (const Item * const array, const int size)
{
	int ct ;

	for (ct = 0; ct < size; ct++)
		printf ("%d ", array[ct]) ;
	putchar ('\n') ;
}