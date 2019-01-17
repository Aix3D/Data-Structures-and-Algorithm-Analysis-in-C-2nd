/*  3-11-09-18-15.38(a).c -- 第三章第十一题  */
#include <stdio.h>
#include "unidirectional_linked_list.h"

int main (void) ;
void eatline (void) ;
void print_list (const Item * pitem) ;

int main (void)
{
	List list ;
	Item item ;

	InitializeList (&list) ;
	printf ("请输入数值,n前往下一步:") ;
	while (1 == scanf ("%d", &item))
	{
		eatline () ;
		AddItem (&list, &item) ;
		printf ("请输入下一个数值:") ;
	}
	eatline () ;
	Traverse (&list, print_list) ;
	printf ("请输入要删除的数值,q退出程序:") ;
	while (1 == scanf ("%d", &item))
	{
		eatline () ;
		if(0 == RecursiveDeleteItem (&list, &item))
			printf ("删除失败\n") ;
		else
			printf ("删除成功\n") ;
		printf ("请输入下一个数值:") ;
	}
	Traverse (&list, print_list) ;

	return 0 ;
}

void eatline (void)
{
	while (getchar () != '\n')
		continue ;
}

void print_list (const Item * pitem)
{
	printf ("%d ", *pitem) ;
}