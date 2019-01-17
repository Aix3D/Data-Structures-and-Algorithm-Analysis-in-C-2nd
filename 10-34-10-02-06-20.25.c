/*	10-34-10-02-06-20.25.c -- 第十章第三十四题	*/
#include <stdio.h>
#include <stdlib.h>

#define NOT_A_VERTEX (-1)
#define THE_NUMBER_OF_VERTICES (7)
#define MAX (20)

typedef int Item ;

int main (void) ;
void allPairs (const Item * const * const graph, Item * const * const value, int * const * const path, const int the_number_of_vertices) ;
void PrintPath (const int * const * const path, const int start, const int end) ;
void printPath (const int * const * const path, const int start, const int end) ;
void test (int * const * const array, const int size) ;

int main (void)
{
	Item * * graph, * * value ;
	int * * path ;
	int i, j ;

	for (i = 0; i < THE_NUMBER_OF_VERTICES; i++)
	{
		for (j = 0; j < THE_NUMBER_OF_VERTICES; j++)
			graph[i][j] = rand () % MAX + 1 ;
	}
	allPairs (graph, value, path, THE_NUMBER_OF_VERTICES) ;
	PrintPath (path, 0, THE_NUMBER_OF_VERTICES - 1) ;

	return 0 ;
}

void allPairs (const Item * const * const graph, Item * const * const value, int * const * const path, const int the_number_of_vertices)
{
	Item temp ;
	int i, j, k ;

	//	Initialize D and Path
	for (i = 0; i < the_number_of_vertices; i++)
	{
		for (j = 0; j < the_number_of_vertices; j++)
		{
			value[i][j] = graph[i][j] ;
			path[i][j] = NOT_A_VERTEX ;
		}
	}
	//	Cure
	for (k = 0; k < the_number_of_vertices; k++)
	{
		//	Consider each vertes as an intermediate
		for (i = 0; i < the_number_of_vertices; i++)
		{
			for (j = 0; j < the_number_of_vertices; j++)
			{
				temp = value[i][k] + value[k][j] ;
				if (temp < value[i][j])
				{
					//	Update shorest path	
					value[i][j] = temp ;
					path[i][k] = k ;
				}
			}
		}
	}
}

void PrintPath (const int * const * const path, const int start, const int end)
{
	printf ("%d to ", start) ;
	printPath (path, start, end) ;
	printf ("%d", end) ;
	putchar ('\n') ;
}

void printPath (const int * const * const path, const int start, const int end)
{
	int stop = path[start][end] ;

	if (start != end && stop != NOT_A_VERTEX)
	{
		printPath (path, start, stop) ;
		printf ("%d to", stop) ;
		printPath (path, stop, end) ;
	}
}

void test (int * const * const array, const int size)
{
	int i, j ;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			printf ("weight : %d ", array[i][j]) ;
		putchar ('\n') ;
	}
}