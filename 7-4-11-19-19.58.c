/*	7-4-11-19-19.58.c -- 第七章第四题	*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

int main (void) ;
void print_array (const int * array, const int size) ;
void shell_sort (int * array, const int size) ;

int main (void)
{
	int array[SIZE] = {9, 8, 7, 6, 5, 4, 3, 2, 1} ;
	int size = SIZE ;

	print_array (array, size) ;
	shell_sort (array, size) ;
	print_array (array, size) ;

	return 0 ;
}

void print_array (const int * array, const int size)
{
	int ct ;

	for (ct = 0; ct < size; ct++)
		printf ("%d ", array[ct]) ;
	putchar ('\n') ;
}

void shell_sort (int * array, const int size)
{
	int ct_out, ct_lin, increment ;
	int temp ;

	for (increment = size / 2; increment > 0; increment /= 2)
	{
		for (ct_out = increment; ct_out < size; ct_out++)
		{
			temp = array[ct_out] ;
			for (ct_lin = ct_out; ct_lin >= increment; ct_lin -= increment)
			{
				if (temp < array[ct_lin - increment])
					array[ct_lin] = array[ct_lin - increment] ;
				else
					break ;
			}
			array[ct_lin] = temp ;
		}
	}
}