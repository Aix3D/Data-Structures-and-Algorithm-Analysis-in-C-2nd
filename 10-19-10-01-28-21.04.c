/*	10-19-10-01-28-21.35.c -- 第十章第十九题	*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FALSE (0)
#define CUTOFF (5)
#define SIZE (70)

typedef int Item ;

int main (void) ;
void initializeInput (Item * const pi, const int size) ;
Item medianOfMedianOfFive (Item * const pi, const int left, const int right) ;
void quickSelect (Item * const pi, const int left, const int right, const int k) ;
void insertSort (Item * const pi, const int left, const int right) ;
void swap (Item * const left, Item * const right) ;
void printResult (const Item * const pi, const int size) ;

int main (void)
{
	Item * input ;
	int size = SIZE, k ;

	input = (Item *) malloc (sizeof (Item) * size) ;
	if (NULL == input)
		return 0 ;
	initializeInput (input, size) ;
	/*	Test	*/
	for (k = 0; k < size; k++)
	{
		quickSelect (input, 0, size - 1, k) ;
		if (k != input[k])
			printf ("k is %d and input[k] is %d.\n", k, input[k]) ;
		else
			puts ("OK.") ;
	}
	free (input) ;

	return 0 ;
}

void initializeInput (Item * const pi, const int size)
{
	int i, j ;

	for (i = 0; i < size; i++)
		pi[i] = i ;
	srand ((unsigned int) time (NULL)) ;
	j = rand () % (size / 2) + 1 ;
	for (i = 0; i < j; i++)
		swap (pi + rand () % size, pi + rand () % size) ;
}
	
Item medianOfMedianOfFive (Item * const pi, const int left, const int right)
{
	Item * temp, result ;
	int i, size ;

	size = (right - left + 1) / 5 ;
	if (size <= 0)
		return FALSE ;
	temp = (Item *) malloc (sizeof (Item) * size) ;
	if (NULL == temp)
		return FALSE ;
	for (i = 0; i < size; i++)
	{
		insertSort (pi, left + 5 * i, left + 5 * i + 4) ;
		temp[i] = pi[left + 5 * i + 3] ;
	}
	insertSort (pi, 0, size - 1) ;
	result = temp[size / 2] ;
	free (temp) ;

	return result ;
}

void quickSelect (Item * const pi, const int left, const int right, const int k)
{
	Item pivot ;
	int i, j ;

	if (right - left + 1 <= CUTOFF)
		insertSort (pi, left, right) ;
	else
	{
		pivot = medianOfMedianOfFive (pi, left, right) ;
		i = left ;
		j = right ;
		while (1)
		{
			while (pi[i++] < pivot)
				NULL ;
			i-- ;
			while (pi[j--] > pivot)
				NULL ;
			j++ ;
			if (i < j)
				swap (pi + i, pi + j) ;
			else
				break ;
		}
		if (k < i)
			quickSelect (pi, left, i - 1, k) ;
		else if (k > i)
			quickSelect (pi, i + 1, right, k) ;
	}
}

void insertSort (Item * const pi, const int left, const int right)
{
	Item temp ;
	int i, j ;

	for (i = left + 1; i <= right; i++)
	{
		temp = pi[i] ;
		for (j = i; j > left && pi[j - 1] > temp; j--)
			pi[j] = pi[j - 1] ;
		pi[j] = temp ;
	}
}

void swap (Item * const left, Item * const right)
{
	Item temp ;

	temp = *left ;
	*left = *right ;
	*right = temp ;
}

void printResult (const Item * const pi, const int size)
{
	int i ;

	for (i = 0; i < size; i++)
		printf ("%d ", pi[i]) ;
	putchar ('\n') ;
}