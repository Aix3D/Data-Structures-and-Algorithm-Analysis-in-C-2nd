/*	5-15-10-31-20.52.c -- 第五章第十一题	*/
#include <stdio.h>
#include "extendible_hashing.h"

int main (void) ;
void print_subdirectories (const Subdirectories subdirectories) ;

int main (void)
{
	Table t ;
	Item item ;

	InitializeTable (&t) ;
	item = 32 ;
	Insert (&t, &item) ;
	item = 33 ;
	Insert (&t, &item) ;
	item = 34 ;
	Insert (&t, &item) ;
	item = 35 ;
	Insert (&t, &item) ;
	putchar ('\n') ;
	item = 64 ;
	Insert (&t, &item) ;
	item = 65 ;
	Insert (&t, &item) ;
	item = 66 ;
	Insert (&t, &item) ;
	item = 80 ;
	Insert (&t, &item) ;
	putchar ('\n') ;
	item = 68 ;
	Insert (&t, &item) ;
	printf ("【【%d】】\n", Insert (&t, &item)) ;
	item = 32 ;
	Delete (&t, &item) ;
	item = 99 ;
	Insert (&t, &item) ;
	item = 107 ;
	Insert (&t, &item) ;
	item = 96 ;
	Insert (&t, &item) ;
	item = 126 ;
	Insert (&t, &item) ;
	item = 127 ;
	if (Delete (&t, &item))
	{
		printf ("%d\n", t -> directory[0].point -> array[0]) ;
		printf ("%d\n", t -> directory[0].point -> array[1]) ;
		printf ("%d\n", t -> directory[0].point -> array[2]) ;
		printf ("%d\n", t -> directory[0].point -> array[3]) ;
		printf ("%d\n", t -> directory[1].point -> array[0]) ;
		printf ("%d\n", t -> directory[1].point -> array[1]) ;
		printf ("%d\n", t -> directory[1].point -> array[2]) ;
		printf ("%d\n", t -> directory[1].point -> array[3]) ;
		printf ("%d\n", t -> directory[2].point -> array[0]) ;
		printf ("%d\n", t -> directory[2].point -> array[1]) ;
		printf ("%d\n", t -> directory[2].point -> array[2]) ;
		printf ("%d\n", t -> directory[2].point -> array[3]) ;
		printf ("%d\n", t -> directory[3].point -> array[0]) ;
		printf ("%d\n", t -> directory[3].point -> array[1]) ;
		printf ("%d\n", t -> directory[3].point -> array[2]) ;
		printf ("%d\n", t -> directory[3].point -> array[3]) ;
		printf ("%d\n", t -> directory[4].point -> array[0]) ;
		printf ("%d\n", t -> directory[4].point -> array[1]) ;
		printf ("%d\n", t -> directory[4].point -> array[2]) ;
		printf ("%d\n", t -> directory[4].point -> array[3]) ;
		printf ("%d\n", t -> directory[5].point -> array[0]) ;
		printf ("%d\n", t -> directory[5].point -> array[1]) ;
		printf ("%d\n", t -> directory[5].point -> array[2]) ;
		printf ("%d\n", t -> directory[5].point -> sub) ;
	}
	printf ("%d\n", Find (&t, &item)) ;
	putchar ('\n') ;
	Traversal (&t, print_subdirectories) ;
	Release (&t) ;

	return 0 ;
}

void print_subdirectories (const Subdirectories subdirectories)
{
	int count ;

	count = subdirectories.point -> sub - 1 ;
	while (count >= 0)
	{
		printf ("%d\n", subdirectories.point -> array[count]) ;
		count-- ;
	}
}