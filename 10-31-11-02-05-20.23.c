/*	10-31-11-02-05-20.23.c -- 第十章第三十一题	*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFINITY (~(1 << 31))
#define LENTH (5)
#define SIZE (7)

typedef double Item ;
typedef struct cell
{
	char letter[LENTH] ;
	double probability ;
} Cell ;

int main (void) ;
void initialize (Cell * const input, const int size) ;
double best (const Cell * const input, const int size) ;
double summation (const Cell * const input, const int start, const int end) ;

int main (void)
{
	Cell input[SIZE] ;
	int size = SIZE ;
	
	initialize (input, size) ;

	printf ("The result is :%lf.\n", best (input, size)) ;

	return 0 ;
}

void initialize (Cell * const input, const int size)
{
	strcpy (input[0].letter, "a") ;
	input[0].probability = 0.22 ;
	strcpy (input[1].letter, "am") ;
	input[1].probability = 0.18 ;
	strcpy (input[2].letter, "and") ;
	input[2].probability = 0.20 ;
	strcpy (input[3].letter, "egg") ;
	input[3].probability = 0.05 ;
	strcpy (input[4].letter, "if") ;
	input[4].probability = 0.25 ;
	strcpy (input[5].letter, "the") ;
	input[5].probability = 0.02 ;
	strcpy (input[6].letter, "two") ;
	input[6].probability = 0.08 ;
}

double best (const Cell * const input, const int size)
{
	Item * * table ;
	Item value, sigma ;
	int left, right, step, k ;
	int i, j ;
	
	if (NULL == input || size <= 0)
		return INFINITY ;
	/*	Initialize table.	*/
	table = (Item * *) malloc (sizeof (Item *) * size) ;
	for (i = 0; i < size; i++)
	{
		table[i] = (Item *) malloc (sizeof (Item) * size) ;
		if (NULL == table[i])
		{
			if (0 == i)
				return INFINITY ;
			for (j = i - 1; j >= 0; j--)
				free (table[j]) ;
			return INFINITY ;
		}
		table[i][i] = input[i].probability ;
	}
	/*	Core.	*/
	for (step = 1; step < size; step++)
	{
		for (left = 0; left < size - step; left++)
		{
			right = left + step ;
			sigma = summation (input, left, right) ;
			table[left][right] = INFINITY ;
			for (k = left; k <= right; k++)
			{
				value = 0.0 ;
				if (left <= k - 1)
					value += table[left][k - 1] ;
				if (k + 1 <= right)
					value += table[k + 1][right] ;
				/*	Fucking precedence level!	*/
				if ((value += sigma) < table[left][right])
					table[left][right] = value ;
			}
		}
	}
	value = table[left - 1][right] ;
	free (table) ;

	return value ;
}

double summation (const Cell * const input, const int start, const int end)
{
	Item sum = 0.0 ;
	int i ;

	for (i = start; i <= end; i++)
		sum += input[i].probability ;

	return sum ;
}