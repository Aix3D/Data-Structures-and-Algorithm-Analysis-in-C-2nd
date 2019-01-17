/*  3-10-09-18-00.32.c -- 第三章第十题  */
#include <stdio.h>
#include <stdlib.h>
#include "unidirectional_linked_list.h"

int main (void) ;
void eatline (void) ;
Item josephus (const int m, int n) ;
void print_list (const Item * pitem) ;

int main (void)
{
	Item item ;
	int m, n ;

	while (1)
	{
		printf ("请输入n(人数)的值(0退出程序):") ;
		while (scanf ("%d", &n) != 1)
		{
			eatline () ;
			printf ("输入有误,请重新输入n的值:") ;
		}
		if (n == 0)
			break ;
		printf ("请输入m(每次传递经过的人数):") ;
		while (scanf ("%d", &m) != 1)
		{
			eatline () ;
			printf ("输入有误,请重新输入m的值:") ;
		}
		if (1 == n)
		{
			printf ("土豆最终落入:1 号手中\n") ;
			continue ;
		}
		item = josephus (m, n) ;
		printf ("热土豆最终落入:%d 号手中\n", item) ;
	}

	return 0 ;
}

void eatline (void)
{
	while (getchar () != '\n')
		continue ;
}

Item josephus (const int m, int n)
{
	List list_josephus ;
	Position position, record ;
	Item item ;
	int count ;

	InitializeList (&list_josephus) ;
	position = list_josephus ;
	
	/*	根据n的大小创建循环链表	*/
	for (count = 1; count <= n; count++)
	{
		if (n == count)
			MakeACircularList (&list_josephus, &count) ;
		else
			AddItem (&list_josephus, &count) ;
	}
	position = list_josephus ;
	while (n > 1)
	{
		for (count = 0; count < m; count++)
			position = position -> next ;
		/*	记录被删除节点下一个节点的地址	*/
		record = position -> next ;
		DeleteItem (&list_josephus, &position -> item) ;
		/*	更新链表头节点	*/
		list_josephus = record ;
		position = record ;
		n-- ;
	}
	item = position -> item ;
	free (position) ;

	return item ;
}

void print_list (const Item * pitem)
{
	printf ("%d ", *pitem) ;
}

