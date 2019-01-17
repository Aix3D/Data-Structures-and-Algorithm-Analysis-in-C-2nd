/*  2-7-09-14-00.15.c -- 第二章第七题(Third Kind Of Algotithm)  */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5

int main (void) ;
int get_random_figure (const int) ;
void swap (int *, int *) ;
void show_arr (const int *, const int) ;

int main (void)
{
	int arr[SIZE] ;
	int i, size = SIZE ;

	srand ((unsigned int) time (NULL)) ;
	for (i = 0; i < size; i++)
		*(arr + i) = i + 1;
	for (i = 1; i < size; i++)
		swap (arr + i, arr + get_random_figure (i)) ;
	show_arr (arr, size) ;

	return 0 ;
}

int get_random_figure (const int supe_size)
{
	return (int) rand () % supe_size ;
}

void swap (int * x, int * y)
{
	int temp ;

	temp = *x ;
	*x = *y ;
	*y = temp ;
}

void show_arr (const int * supe_arr, const int supe_size)
{
	int i ;

	for (i = 0; i < supe_size; i++)
		printf ("%d ", *(supe_arr + i)) ;
	putchar ('\n') ;
}