/*  3-17-09-22-22.46.c -- 第三章第十七题  */
#include <stdio.h>
#include "lazy_deletion_linked_list.h"

int main (void) ;
void show_menu (void) ;
void eatline (void) ;
void get_input_to_add (List * plist, int * pexistent) ;
void get_input_to_delete (List * plist, int * pexistent, int * pbeingless) ;
void print_list (const Item item) ;

int main (void)
{
	List list ;
	int choice, num_of_existent = 0, num_of_beingless = 0 ;

	InitializeList (&list) ;
	show_menu () ;
	while (1 == scanf ("%d", &choice))
	{
		eatline () ;
		switch (choice)
		{
		case 1:	get_input_to_add (&list, &num_of_existent) ;
				break ;
		case 2:	get_input_to_delete (&list, &num_of_existent, &num_of_beingless) ;
				break ;
		case 3:	Traverse (&list, print_list) ;
				break ;
		default:puts ("无效的选项,请重新输入") ;
		}
		show_menu () ;
	}
	DeleteList (&list) ;

	puts ("Bye") ;

	return 0 ;
}

void show_menu (void)
{
	puts ("1).添加数据") ;
	puts ("2).删除数据") ;
	puts ("3).显示数据") ;
	puts ("q).退出") ;
	printf ("( )\b\b") ;
}

void eatline (void)
{
	while (getchar () != '\n')
		continue ;
}

void get_input_to_add (List * plist, int * pexistent)
{
	Item input ;

	fputs ("请输入要添加的数据,q结束输入过程:", stdout) ;
	while (1 == scanf ("%d", &input.num))
	{
		eatline () ;
		if (1 == AddItem (plist, &input))
		{
			puts ("添加成功") ;
			(*pexistent)++ ;
			fputs ("请输入下一个添加的数值:", stdout) ;
		}
		else
		{
			puts ("添加失败,提前结束添加过程") ;
			break ;
		}
	}
	eatline () ;
}

void get_input_to_delete (List * plist, int * pexistent, int * pbeingless)
{
	Item input ;
	Position scan, temp ;

	scan = *plist ;

	fputs ("请输入要删除的数据,q结束输入过程", stdout) ;
	while (1 == scanf ("%d", &input.num))
	{
		eatline () ;
		if (1 == LazyDeleteItem (plist, &input))
		{
			(*pexistent)-- ;
			(*pbeingless)++ ;
			puts ("删除成功") ;
		}
		else
			puts ("删除失败") ;
		if (!(*pexistent ^ *pbeingless))
			while (scan != NULL)
			{
				temp = scan -> next ;
				if (1 == scan -> item.index)
				{
					DeleteItem (plist, &scan -> item) ;
					(*pbeingless)-- ;
				}
				scan = temp ;
			}
	fputs ("请输入下一个删除的数值:", stdout) ;
	}
	eatline () ;
}

void print_list (const Item item)
{
	printf ("数据:%-2d %-8s\n", item.num, 1 == item.index ? "标记删除" : " ") ;
}