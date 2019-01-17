/*	2-7-09-13-22.43.c -- 第二章第七题(First Kind Of Algorithm)  */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 2000

int main (void) ;
int get_rand_figure (const int) ;
void show_arr (const int *, const int) ;

int main (void)
{
	int arr[N] ;
	int i, j, rand_figure, index = 0 ;

	srand ((unsigned int) time (NULL)) ;

	for (i = 0; i < N; i++)
	{
		/*	Get the random figure	*/
		rand_figure = get_rand_figure (N) ;
		if (i != 0)
			for (j = 0; j < i; j++)
				if (*(arr + j) == rand_figure)
				{
					index = 1 ;
					break ;
				}
		if (1 == index)
		{
			i-- ;
			index = 0 ;
			continue ;
		}
		*(arr + i) = rand_figure ;
	}
	show_arr (arr, N) ;

	return 0 ;
}

int get_rand_figure (const int supe_size)
{
	return rand () % supe_size ;
}

void show_arr (const int * supe_arr, const int supe_size)
{
	int i ;

	for (i = 0; i < supe_size; i++)
		printf ("%d ", *(supe_arr + i)) ;
	putchar ('\n') ;
}