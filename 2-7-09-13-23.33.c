/*  2-7-09-13-23.33.c -- 第二章第七题(Second Kind Of Algortthm)  */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 80000

int main (void) ;
int get_random_figure (const int) ;
void show_arr (const int *, const int) ;

int main (void)
{
	int arr[SIZE], used_arr[SIZE] ;
	int i, random_figure, size = SIZE ;

	srand ((unsigned int) time (NULL)) ;
	for (i = 0; i < size; i++)
	{
		random_figure = get_random_figure (size) ;
		if (i != 0)
			if (*(used_arr + random_figure) == 1)
			{
				i-- ;
				continue ;
			}
		*(arr + i) = random_figure ;
		*(used_arr + random_figure) = 1 ;
	}
	show_arr (arr, size) ;

	return 0 ;
}

int get_random_figure (const int supe_size)
{
	return (int) rand () % supe_size ;
}

void show_arr (const int * supe_arr, const supe_size)
{
	int i ;

	for (i = 0; i < supe_size; i++)
		printf ("%-*d ", 4, *(supe_arr + i)) ;
	putchar ('\n') ;
}