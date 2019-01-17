/*  3-4-09-16-19.14.c -- 第三章第五题  */
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
	/*	以list_1为基础扫描list_2.如果相同则添加;不同同样添加	*/
	while (position_1 != NULL)
	{
		index = 0 ;
		position_2 = list_2 ;
		while (position_2 != NULL)
		{
			/*	重复的情况下	*/
			if (position_1 -> item == position_2 -> item)
			{
				/*	标记变量置为1,添加元素,并退出本层循环	*/
				index = 1 ;
				AddItem (&list_new, &position_1 -> item) ;
				break ;
			}
			position_2 = position_2 -> next ;
		}
		/*	如果未重复,同样需要添加	*/
		if (!IsIterant (index))
			AddItem (&list_new, &position_1 -> item) ;
		position_1 = position_1 -> next ;
	}
	/*  以list_2为基础扫描list_1,如果重复不再添加;不重复则添加  */
	position_2 = list_2 ;
	while (position_2 != NULL)
	{
		index = 0 ;
		position_1 = list_1 ;
		while (position_1 != NULL)
		{
			/*	重复的情况下	*/
			if (position_2 -> item == position_1 -> item)
			{
				/*	标记变量置为1,不重复添加元素,因为已经添加过了.退出本层循环	*/
				index = 1 ;
				break ;
			}
			position_1 = position_1 -> next ;
		}
		/*	如果未重复,需要添加	*/
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