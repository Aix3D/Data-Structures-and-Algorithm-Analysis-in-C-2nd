/*  3-17-09-22-22.46.c -- �����µ�ʮ����  */
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
		default:puts ("��Ч��ѡ��,����������") ;
		}
		show_menu () ;
	}
	DeleteList (&list) ;

	puts ("Bye") ;

	return 0 ;
}

void show_menu (void)
{
	puts ("1).�������") ;
	puts ("2).ɾ������") ;
	puts ("3).��ʾ����") ;
	puts ("q).�˳�") ;
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

	fputs ("������Ҫ��ӵ�����,q�����������:", stdout) ;
	while (1 == scanf ("%d", &input.num))
	{
		eatline () ;
		if (1 == AddItem (plist, &input))
		{
			puts ("��ӳɹ�") ;
			(*pexistent)++ ;
			fputs ("��������һ����ӵ���ֵ:", stdout) ;
		}
		else
		{
			puts ("���ʧ��,��ǰ������ӹ���") ;
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

	fputs ("������Ҫɾ��������,q�����������", stdout) ;
	while (1 == scanf ("%d", &input.num))
	{
		eatline () ;
		if (1 == LazyDeleteItem (plist, &input))
		{
			(*pexistent)-- ;
			(*pbeingless)++ ;
			puts ("ɾ���ɹ�") ;
		}
		else
			puts ("ɾ��ʧ��") ;
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
	fputs ("��������һ��ɾ������ֵ:", stdout) ;
	}
	eatline () ;
}

void print_list (const Item item)
{
	printf ("����:%-2d %-8s\n", item.num, 1 == item.index ? "���ɾ��" : " ") ;
}