/*  3-8-09-17-18.17.c -- 第三章第八题  */
#include <stdio.h>
#include "unidirectional_linked_list.h"

int main (void) ;
List list_pow (List * plist, int power) ;
void print_list (const Item * pitem) ;

int main (void)
{
	List input, reasult ;
	int i ;

	InitializeList (&input) ;
	/*	设置输入数据,链表实现	*/
//	for (i = 0; i < 5; i++)
	i = 1 ;
	AddItem (&input, &i) ;
	i = 2 ;
	AddItem (&input, &i) ;
	reasult = list_pow (&input, 4) ;
	DeleteList (&input) ;
	Traverse (&reasult, print_list) ;
	DeleteList (&reasult) ;

	return 0 ;
}

List list_pow (List * input, int power)
{
	List reasult, occasional_list ;
	Position scan_r ;
	Position scan_i ;
	Item occasional_value ;
	int initialization_power = power ;
	
	InitializeList (&reasult) ;
	if (0 == power)
	{
		occasional_value = 1 ;
		AddItem (&reasult, &occasional_value) ;
		return reasult ;
	}
	scan_i = *input ;
	while (scan_i != NULL)
	{
		AddItem (&reasult, &scan_i -> item) ;
		AddItem (&occasional_list, &scan_i -> item) ;
		scan_i = scan_i -> next ;
	}
	while (power != 1 && power != -1)
	{
		scan_r = occasional_list ;
		while (scan_r != NULL)
		{
			scan_i = *input ;
			while (scan_i != NULL)
			{
				occasional_value = scan_r -> item * scan_i -> item ;
				AddItem (&reasult, &occasional_value) ;
				AddItem (&occasional_list, &occasional_value) ;
				scan_i = scan_i -> next ;
			}
			scan_r = scan_r -> next ;
		}
		if (power > 0)
			power-- ;
		else if (power < 0)
			power++ ;
	}
	/*	幂数是负数,取倒数	*/
	if (initialization_power < 0)
	{
		while (reasult != NULL)
			reasult -> item = 1 / reasult -> item ;
	}
	return reasult ;
}

void print_list (const Item * pitem)
{
	printf ("%d ", *pitem) ;
}