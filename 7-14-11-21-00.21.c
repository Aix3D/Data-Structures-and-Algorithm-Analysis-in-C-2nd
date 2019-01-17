/*	7-14-11-21-00.21.c -- 第七章第十四题	*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) ;
void initialize_array (int * const array, const int size, const int max_value) ;
void print_array (const int * const array, const int size) ;
int test (const int * const array, const int size) ;
void merge_sort (int * const array, const int size) ;
void merge (int * const array, int * const temp, int left_position, int right_position, int right_end) ;
int get_power (const int size) ;
int pow_base_two (const int power) ;

int main (void)
{
	int * array ;
	int size, max_value ;

	size = 15, max_value = 120 ;
	array = (int *) malloc (sizeof (int) * size) ;
	if (NULL == array)
	{
		printf ("Out of space occurred in \"main\"\n") ;
		return 0 ;
	}
	initialize_array (array, size, max_value) ;
	print_array (array, size) ;
	merge_sort (array, size) ;
	print_array (array, size) ;
	printf ("%s\n", 1 == test (array, size) ? "OK" : "Wrong") ;
	free (array) ;

	return 0 ;
}

void initialize_array (int * const array, const int size, const int max_value)
{
	int i ;

	srand ((unsigned int) time (NULL)) ;
	for (i = 0; i < size; i++)
		array[i] = rand () % max_value + 1 ;
}

void print_array (const int * const array, const int size)
{
	int i ;

	for (i = 0; i < size; i++)
		printf ("%d\n", array[i]) ;
	putchar ('\n') ;
}

int test (const int * const array, const int size)
{
	int i ;

	for (i = 1; i < size; i++)
	{
		if (array[i] < array[i - 1])
			return 0 ;
	}

	return 1 ;
}

void merge_sort (int * const array, const int size)
{
	int * temp ;
	int left_position, right_end, center, i, j, value, power ;

	temp = (int *) malloc (sizeof (int) * size) ;
	if (NULL == temp)
	{
		printf ("Out of space occurred in \"merge_sort\"\n") ;
		return ;
	}
	power = get_power (size) ;
	for (i = 1, value = pow_base_two (i); i <= power; i++, value = pow_base_two (i))
	{
		for (j = 0; j < size; j += value)
		{
			left_position = j ;
			right_end = j + value - 1 ;
			if (right_end > size - 1)
			{
				right_end = size - 1 ;
				center = left_position + value / 2 - 1 ;
			}
			else
				center = (left_position + right_end) / 2 ;
			merge (array, temp, left_position, center + 1, right_end) ;
		}
	}
	free (temp) ;
}

void merge (int * const array, int * const temp, int left_position, int right_position, int right_end)
{
	int left_end, temp_position, count, i ;

	left_end = right_position - 1 ;
	temp_position = left_position ;
	count = right_end - left_position + 1 ;

	while (left_position <= left_end && right_position <= right_end)
	{
		if (array[left_position] < array[right_position])
			temp[temp_position++] = array[left_position++] ;
		else
			temp[temp_position++] = array[right_position++] ;
	}
	while (left_position <= left_end)
		temp[temp_position++] = array[left_position++] ;
	while (right_position <= right_end)
		temp[temp_position++] = array[right_position++] ;
	for (i = 0; i < count; i++, right_end--)
		array[right_end] = temp[right_end] ;
}

int get_power (const int size)
{
	int power, value ;

	for (power = 1, value = 1; value <= size; power++)
	{
		value *= 2 ;
		if (value >= size)
			break ;
	}

	return power ;
}

int pow_base_two (const int power)
{
	int i, value ;

	if (power <= 0)
	{
		puts ("Can't work.") ;
		return 0 ;
	}
	for (i = 1, value = 1; i <= power; i++)
		value *= 2 ;

	return value ;
}