/*  3-25(b)-09-27-16.08.c -- �����µڶ�ʮ����	*/
#include <stdio.h>
#include <stdlib.h>
#include "queue_achievied_by_array.h"
#include "shadow.h"

int main (void) ;
void ptint_int (const Item item) ;

int main (void)
{
	Queue queue ;
	Item item = 0 ;

	if (NULL == (queue = CreateQueue (5)))
	{
		puts ("��������ʧ��") ;
		exit (EXIT_FAILURE) ;
	}
	EnQueue (queue, item++) ;
	DeQueue (queue, &item) ;
	Traverse (queue, print_int) ;

	return 0 ;
}