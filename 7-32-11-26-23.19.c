/*	7-32-11-26-23.19.c -- 第七章第三十二题	*/
#include <stdio.h>

#define SIZE 22
#define FALSE 1
#define MAYBE 2
#define TRUE 3
#define PROBABLYFALSE 4
#define PROBABLYTRUE 5

int main (void) ;
void print_array (const int * const array, const int size) ;
void swap (int * const vala, int * const valb) ;

int main (void)
{
	int array[SIZE] = {TRUE, FALSE, FALSE, FALSE, TRUE, TRUE, TRUE, TRUE, TRUE, MAYBE, MAYBE, MAYBE, MAYBE, FALSE, FALSE, FALSE, FALSE, FALSE, MAYBE, MAYBE, MAYBE, FALSE} ;
	int i, j, size, index, probablyfalse, probablytrue ;

	probablyfalse = PROBABLYFALSE ;
	probablytrue = PROBABLYTRUE ;
	size = SIZE ;
	index = (size - 1) / 2 ;
	i = 0 ;
	j = size - 1 ;

	print_array (array, size) ;
	/*	First step	*/
	swap (array + index, &probablytrue) ;
	while (1)
	{
		while (FALSE == array[i] || MAYBE == array[i])
			i++ ;
		while (TRUE == array[j])
			j-- ;
		if (i < j)
			swap (array + i, array + j) ;
		else
			break ;
	}
	swap (array + i, &probablytrue) ;
	/*	Second step	*/
	if (TRUE == array[i])
		i -= 1 ;
	index = i / 2 ;
	j = i ;
	i = 0 ;
	swap (array + index, &probablyfalse) ;
	while (1)
	{
		while (FALSE == array[i])
			i++ ;
		while (MAYBE == array[j])
			j-- ;
		if (i < j)
			swap (array + i, array + j) ;
		else
			break ;
	}
	swap (array + i, &probablyfalse) ;

	print_array (array, size) ;

	return 0 ;
}


void print_array (const int * const array, const int size)
{
	int i ;

	for (i = 0; i < size; i++)
		printf ("%s\n", FALSE == array[i] ? "FALSE" : (MAYBE == array[i] ? "MAYBE" : "TRUE")) ;
	putchar ('\n') ;
}

void swap (int * const vala, int * const valb)
{
	int temp ;

	temp = *vala ;
	*vala = *valb ;
	*valb = temp ;
}