/*	7-31-11-26-22.22.c -- 第七章第三十一题	*/
#include <stdio.h>

#define SIZE 21
#define FALSE 0
#define TRUE 2

int main (void) ;
void print_array (const int * const array, const int size) ;
void swap (int * const vala, int * const valb) ;

int main (void)
{
	const int MAYBE = 1 ;
	int array[SIZE] = {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE} ;
	int size = SIZE, i = 0, j = size - 1, index, dummy ;
	
	print_array (array, size) ;
	index = (size - 1) / 2 ;
	dummy = MAYBE ;
	swap (array + index, &dummy) ;
	while (1)
	{
		while (FALSE == array[i])
			i++ ;
		while (TRUE == array[j])
			j-- ;
		if (i < j)
			swap (array + i, array + j) ;
		else
			break ;
	}
	swap (array + i, &dummy) ;
	print_array (array, size) ;

	return 0 ;
}

void print_array (const int * const array, const int size)
{
	int i ; 

	for (i = 0; i < size; i++)
		printf ("%s\n", FALSE == array[i] ? "FALSE" : "TRUE") ;
	putchar ('\n') ;
}

void swap (int * const vala, int * const valb)
{
	int temp ;

	temp = *vala ;
	*vala = *valb ;
	*valb = temp ;
}