/*  3-4-09-16-19.14.c -- �����µ�����  */
#include <stdio.h>
#include "unidirectional_linked_list.h"
#define IsIterant(index) index == 1 ? 1 : 0

int main (void) ;
void print_list (const Item * pitem) ;

int main (void)
{
	List list_1, list_2, list_new ;
	Position position_1, position_2 ;
	Item item_1, item_2 ;
	int i, index ;

	InitializeList (&list_1) ;
	InitializeList (&list_2) ;
	InitializeList (&list_new) ;

	for (i = 0; i < 10; i++)
	{
		item_1 = i ;
		AddItem (&list_1, &item_1) ;
		printf ("%-2d ", item_1) ;
	}
	putchar ('\n') ;
	for (i = 0; i < 20; i++)
	{
		item_2 =2 * i ;
		AddItem (&list_2, &item_2) ;
		printf ("%-2d ", item_2) ;
	}
	putchar ('\n') ;
	position_1 = list_1 ;
	/*	��list_1Ϊ����ɨ��list_2.�����ͬ�����;��ͬͬ�����	*/
	while (position_1 != NULL)
	{
		index = 0 ;
		position_2 = list_2 ;
		while (position_2 != NULL)
		{
			/*	�ظ��������	*/
			if (position_1 -> item == position_2 -> item)
			{
				/*	��Ǳ�����Ϊ1,���Ԫ��,���˳�����ѭ��	*/
				index = 1 ;
				AddItem (&list_new, &position_1 -> item) ;
				break ;
			}
			position_2 = position_2 -> next ;
		}
		/*	���δ�ظ�,ͬ����Ҫ���	*/
		if (!IsIterant (index))
			AddItem (&list_new, &position_1 -> item) ;
		position_1 = position_1 -> next ;
	}
	/*  ��list_2Ϊ����ɨ��list_1,����ظ��������;���ظ������  */
	position_2 = list_2 ;
	while (position_2 != NULL)
	{
		index = 0 ;
		position_1 = list_1 ;
		while (position_1 != NULL)
		{
			/*	�ظ��������	*/
			if (position_2 -> item == position_1 -> item)
			{
				/*	��Ǳ�����Ϊ1,���ظ����Ԫ��,��Ϊ�Ѿ���ӹ���.�˳�����ѭ��	*/
				index = 1 ;
				break ;
			}
			position_1 = position_1 -> next ;
		}
		/*	���δ�ظ�,��Ҫ���	*/
		if (!IsIterant (index))
			AddItem (&list_new, &position_2 -> item) ;
		position_2 = position_2 -> next ;
	}
	Traverse (&list_new, print_list) ;

	return 0 ;
}

void print_list (const Item * pitem)
{
	printf ("%-2d ", *pitem) ;
}