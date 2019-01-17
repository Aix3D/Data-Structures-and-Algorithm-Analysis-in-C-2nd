/*  3-10-09-18-00.32.c -- �����µ�ʮ��  */
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
		printf ("������n(����)��ֵ(0�˳�����):") ;
		while (scanf ("%d", &n) != 1)
		{
			eatline () ;
			printf ("��������,����������n��ֵ:") ;
		}
		if (n == 0)
			break ;
		printf ("������m(ÿ�δ��ݾ���������):") ;
		while (scanf ("%d", &m) != 1)
		{
			eatline () ;
			printf ("��������,����������m��ֵ:") ;
		}
		if (1 == n)
		{
			printf ("������������:1 ������\n") ;
			continue ;
		}
		item = josephus (m, n) ;
		printf ("��������������:%d ������\n", item) ;
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
	
	/*	����n�Ĵ�С����ѭ������	*/
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
		/*	��¼��ɾ���ڵ���һ���ڵ�ĵ�ַ	*/
		record = position -> next ;
		DeleteItem (&list_josephus, &position -> item) ;
		/*	��������ͷ�ڵ�	*/
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

