/*	7-17-11-21-23.53.c -- 第七章第十七题	*/
#include <stdio.h>
#include <stdlib.h>

#define CUTOFF (3)
#define SIZE (22)

int main (void) ;
void print_array (const int * const array, const int size) ;
void swap (int * const left, int * const right) ;
void insert_sort2 (int * const array, const int size) ;	/*	情不自禁地写出了这个东西.我都JB学啥了?	*/
void insert_sort (int * const array, const int left, const int right) ;
int median3 (int * const array, const int left, const int right) ;
void q_sort (int * const array, const int left, const int right) ;
void quick_sort (int * const array, const int size) ;

int main (void)
{
	int array[SIZE] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 55, 0, 77, 128, 66, 88, -1, 3, 45, 15, 77} ;
	int size = SIZE ;

	print_array (array, size) ;
	quick_sort (array, size) ;
	print_array (array, size) ;

	return 0 ;
}

void print_array (const int * const array, const int size)
{
	int i ;

	for (i = 0; i < size; i++)
		printf ("%d ", array[i]) ;
	putchar ('\n') ;
}

void swap (int * const left, int * const right)
{
	int temp ;

	temp = *left ;
	*left = *right ;
	*right = temp ;
}

/*	What am I thinking of?	*/
void insert_sort2 (int * const array, const int size)
{
	int i, j ;

	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			if (array[j] < array[i])
				swap (array + j, array + i) ;
		}
	}
}

void insert_sort (int * const array, const int left, const int right)
{
	int position, j ;
	int temp ;

	for (position = left + 1; position <= right; position++)
	{
		temp = array[position] ;
		for (j = position; j > left && array[j - 1] > temp; j--)
			array[j] = array[j - 1] ;
		array[j] = temp ;
	}
}

int median3 (int * const array, const int left, const int right)
{
	int center = (left + right) / 2 ;

	if (array[left] > array[center])
		swap (array + left, array + center) ;
	if (array[left] > array[right])
		swap (array + left, array + right) ;
	if (array[center] > array[right])
		swap (array + center, array + right) ;
	swap (array + center, array + right - 1) ;

	return array[right - 1] ;
}

void q_sort (int * const array, const int left, const int right)
{
	int i, j ;
	int pivot ;

	if (left + CUTOFF <= right)
/*	if (left < right)	if you don't want to use insert_sort	*/
	{
		pivot = median3 (array, left, right) ;
		i = left ;
		j = right - 1 ;
		while (1)
		{
			while (array[++i] < pivot)
				;
			while (array[--j] > pivot)		/*	- -	*/
				;
			if (i < j)
				swap (array + i, array + j) ;
			else
				break ;
		}
		swap (array + i, array + right - 1) ;
		q_sort (array, left, i - 1) ;
		q_sort (array, i + 1, right) ;
	}
	else
		insert_sort (array, left, right) ;
}

void quick_sort (int * const array, const int size)
{
	q_sort (array, 0, size - 1) ;
}