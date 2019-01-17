/*	count_sort-11-03-21-19.01.c -- ¼ÆÊýÅÅÐò	*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE (10)

int main (void) ;
int countSort (int * const array, const int size) ;
void printResult (const int * const array, const int size) ;

int main (void)
{
	int array[SIZE] = {7, 22, 4, 3, 0, 0, 9, 11, 8, 15} ;
	int size = SIZE ;

	printResult (array, size) ;
	countSort (array, size) ;
	printResult (array, size) ;

	return 0 ;
}

int countSort (int * const array, const int size)
{
	int * count ;
	int min, max ;
	int range, i, j, k ;

	min = max = array[0] ;
	for (i = 0; i < size; i++)
	{
		if (array[i] < min)
			min = array[i] ;
		else if (array[i] > max)
			max = array[i] ;
	}
	range = max - min + 1 ;
	count = (int *) malloc (sizeof (int) * range) ;
	if (NULL == count)
		return 0 ;
	for (i = 0; i < range; i++)
		count[i] = 0 ;
	for (i = 0; i < size; i++)
		count[array[i] - min]++ ;
	k = 0 ;
	for (i = min; i <= max; i++)
	{
		for (j = 0; j < count[i - min]; j++)
			array[k++] = i ;
	}
	free (count) ;

	return 1 ;
}

void printResult (const int * const array, const int size)
{
	int i ;

	for (i = 0; i < size; i++)
		printf ("%-4d", array[i]) ;
	putchar ('\n') ;
}