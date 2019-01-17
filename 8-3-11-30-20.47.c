/*	8-3-11-30-20.47.c -- 第八章第三题	*/
#include <stdio.h>
#include <stdlib.h>
#include "DisjiontADT.h"

#define SIZE (17)

int main (void) ;
void print_s (const DisjiontSet gather, const int size) ;

int main (void)
{
	SetType s[SIZE + 1] ;
	DisjiontSet gather = s ;
	int size = SIZE ;

/*	puts ("As Height.") ;
	InitializeAsHeight (s, size) ;
	print_s (gather, size) ;
	SetUnionAsHeight (gather, 1, 2) ;
	SetUnionAsHeight (gather, 3, 4) ;
	SetUnionAsHeight (gather, 3, 5) ;
	SetUnionAsHeight (gather, 1, 7) ;
	SetUnionAsHeight (gather, 3, 6) ;
	SetUnionAsHeight (gather, 8, 9) ;
	SetUnionAsHeight (gather, 1, 8) ;
	SetUnionAsHeight (gather, 3, 10) ;
	SetUnionAsHeight (gather, 3, 11) ;
	SetUnionAsHeight (gather, 3, 12) ;
	SetUnionAsHeight (gather, 3, 13) ;
	SetUnionAsHeight (gather, 14, 15) ;
	SetUnionAsHeight (gather, 16, 17) ;
	SetUnionAsHeight (gather, 14, 16) ;
	SetUnionAsHeight (gather, 1, 3) ;
	SetUnionAsHeight (gather, 1, 14) ;
	print_s (gather, size) ;
	printf ("%d\n", Find (gather, 4)) ;
	print_s (gather, size) ;
*/

	puts ("As Size.") ;
	InitializeAsSize (gather, size) ;
	print_s (gather, size) ;
	SetUnionAsSize (gather, 1, 2) ;
	SetUnionAsSize (gather, 3, 4) ;
	SetUnionAsSize (gather, 3, 5) ;
	SetUnionAsSize (gather, 1, 7) ;
	SetUnionAsSize (gather, 3, 6) ;
	SetUnionAsSize (gather, 8, 9) ;
	SetUnionAsSize (gather, 1, 8) ;
	SetUnionAsSize (gather, 3, 10) ;
	SetUnionAsSize (gather, 3, 11) ;
	SetUnionAsSize (gather, 3, 12) ;
	SetUnionAsSize (gather, 3, 13) ;
	SetUnionAsSize (gather, 14, 15) ;
	SetUnionAsSize (gather, 16, 17) ;
	SetUnionAsSize (gather, 14, 16) ;
	SetUnionAsSize (gather, 1, 3) ;
	SetUnionAsSize (gather, 1, 14) ;
	print_s (gather, size) ;
	printf ("%d\n", Find (gather, 4)) ;
	print_s (gather, size) ;

	return 0 ;
}

void print_s (const DisjiontSet gather, const int size)
{
	int i ;

	for (i = 1; i <= size; i++)
		printf ("%-3d ", gather[i]) ;
	putchar ('\n') ;
}