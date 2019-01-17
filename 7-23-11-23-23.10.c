/*	7-23-11-23-23.10.c -- 第七章第二十三题	*/
#include <stdio.h>
#include <stdlib.h>

#define CUTOFF (3)
#define SIZE (40)
#define WRONG (-36768)

int main (void) ;
void print_array (const int * const array, const int size) ;
void swap (int * const p1, int * const p2) ;
int median3 (int * const array, const int left, const int right) ;
void insert_sort (int * const array, const int size) ;
void quick_select (int * const array, const int left, const int right, const int k) ;
int nozzle (const int * const array, const int size, const int k) ;

int main (void)
{
	int array[SIZE] = { 5, 4, 3, 2, 1, 0, 10, 21, 33, 34, 35, 36, 37, 38, 11, 22, 23, 25, 24, 26, 27, 28, 29, 30, 31, 32, 12, 13, 14, 15, 16, 17, 18, 9, 8, 7, 6, 19, 20,  39} ;
	int size = SIZE, value, k ;

	for (k = 1; k <= size; k++)
	{
		value = nozzle (array, size, k) ;
		printf ("The %2d%s smallest number is %d\n", k, k < 3 ? (1 == k ? "st" : "nd") : "th", value) ;
	}
	
	return 0 ;
}

void print_array (const int * const array, const int size)
{
	int i ;

	for (i = 0; i < size; i++)
		printf ("[%-2d] ", i) ;
	putchar ('\n') ;
	for (i = 0; i < size; i++)
		printf ("% -4d ", array[i]) ;
	putchar ('\n') ;
}

void swap (int * const p1, int * const p2)
{
	int temp ;

	temp = *p1 ;
	*p1 = *p2 ;
	*p2 = temp ;
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

void insert_sort (int * const array, const int size)
{
	int position, j ;
	int temp ;

	for (position = 1; position < size; position++)
	{
		temp = array[position] ;
		for (j = position; j > 0 && array[j - 1] > temp; j--)
			array[j] = array[j - 1] ;
		array[j] = temp ;
	}
}

void quick_select (int * const array, const int left, const int right, const int k)
{
	int i, j ;
	int pivot ;

	if (left + CUTOFF <= right)
	{
		pivot = median3 (array, left, right) ;
		i = left ;
		j = right - 1 ;
		while (1)
		{
			while (array[++i] < pivot)
				;
			while (array[--j] > pivot)
				;
			if (i < j)
				swap (array + i, array + j) ;
			else
				break ;
		}
		/*	如果自史自终不调用其他排序函数. 当当前数组中元素 == 3个时, 需要添加下面的条件检测.	*/
		/*	避免了一种特殊情况.即枢纽元在 i - 1 位置上	*/
		//	if (i != right)	/*	or "array[i - 1] != pivot)"	*/
		swap (array + i, array + right - 1) ;
		/*	i 是索引	*/
		if (k < i)
			quick_select (array, left, i - 1, k) ;
		else if (k > i)
			quick_select (array, i + 1, right, k) ;
		else
			;	/*	I'm here!	^ ^	*/
	}
	else
		insert_sort (array + left, right - left + 1) ;
}

int nozzle (const int * const array, const int size, const int k)
{
	int * duplicate ;
	int i, value, lenth = sizeof (int) ;

	if (k >= size + 1)
	{
		puts ("k is too large.") ;
		return WRONG ;
	}
	duplicate = (int *) malloc (lenth * size) ;
	if (NULL == duplicate)
	{
		puts ("Out of space.") ;
		return WRONG ;
	}
	for (i = 0; i < size; i++)
		duplicate[i] = array[i] ;
	quick_select (duplicate, 0, size - 1, k - 1) ;
	value = duplicate[k - 1] ;
	free (duplicate) ;

	return value ;
}