/*	11-6-11-02-27-20.15.c -- 第十一章第六题	*/
#include "FibonacciHeap.h"

int main (void) ;

int main (void)
{
	FibonacciHeap fh ;
	Item item ;

	Initialize_F (&fh) ;

	item = 10 ;
	Insert_F (&fh, &item) ;
	item = 9 ;
	Insert_F (&fh, &item) ;
	item = 8 ;
	Insert_F (&fh, &item) ;
	item = 7 ;
	Insert_F (&fh, &item) ;
	item = 6 ;
	Insert_F (&fh, &item) ;
	item = 11 ;
	Insert_F (&fh, &item) ;
	item = 12 ;
	Insert_F (&fh, &item) ;
	item = 13 ;
	Insert_F (&fh, &item) ;
	item = 14 ;
	Insert_F (&fh, &item) ;
	item = 0 ;
	Insert_F (&fh, &item) ;

	DeleteMin_F (&fh) ;

	printf ("min is : %d\n", item) ;
	DecreaseKey_F (&fh, fh -> min -> child -> right -> child, 9) ;

	item = 15 ;
	Insert_F (&fh, &item) ;

	DecreaseKey_F (&fh, fh -> min -> right -> right -> right -> child -> right, 9) ;
	DeleteMin_F (&fh) ;


	item = 10 ;
	Insert_F (&fh, &item) ;
	item = 9 ;
	Insert_F (&fh, &item) ;
	DeleteMin_F (&fh) ;
	item = 8 ;
	Insert_F (&fh, &item) ;
	item = 7 ;
	Insert_F (&fh, &item) ;
	item = 6 ;
	Insert_F (&fh, &item) ;
	item = 11 ;
	Insert_F (&fh, &item) ;
	item = 12 ;
	Insert_F (&fh, &item) ;
	DeleteMin_F (&fh) ;
	item = 13 ;
	Insert_F (&fh, &item) ;
	item = 14 ;
	Insert_F (&fh, &item) ;
	Delete_F (&fh, fh -> min) ;
	item = 3 ;
	Insert_F (&fh, &item) ;
	DeleteMin_F (&fh) ;
	Insert_F (&fh, &item) ;
	item = 12 ;
	Insert_F (&fh, &item) ;
	DeleteMin_F (&fh) ;
	item = 9 ;
	Insert_F (&fh, &item) ;
	item = 88 ;
	Insert_F (&fh, &item) ;
	DeleteMin_F (&fh) ;
	item = 8 ;
	Insert_F (&fh, &item) ;
	DeleteMin_F (&fh) ;
	Insert_F (&fh, &item) ;
	item = 31 ;
	Insert_F (&fh, &item) ;
	DeleteMin_F (&fh) ;
	item = 22 ;
	Insert_F (&fh, &item) ;
	item = 11 ;
	Insert_F (&fh, &item) ;
	DeleteMin_F (&fh) ;
	DecreaseKey_F (&fh, fh -> min, 10) ;
	item = 11 ;
	Insert_F (&fh, &item) ;
	DeleteMin_F (&fh) ;
	item = 99 ;
	Insert_F (&fh, &item) ;
	item = 0 ;
	Insert_F (&fh, &item) ;

	Delete_F (&fh, fh -> min) ;
	printf ("%p\n", fh) ;

	Release_F (&fh) ;

	return 0 ;
}